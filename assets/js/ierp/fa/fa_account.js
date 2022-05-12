function beforePatch(inputData) {
  consoleLog("In beforePatch 1 ");
  var data = inputData["data"];
  var action = data["action"];
  var invTransactionId = data["invTransactionId"];

  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Account is successfully created",
  };
  if (action == "create_accounting") {
    let retDataMap2 = createAccountingFromParams(data);
    return retDataMap2;
  }

  return retDataMap;
}

/*
 * 1. Find all transactions pending for accounting - one SQL call
 * 1.1 Find all unique assets
 * 1.1.2 Find all asset accounting profile lines - one SQL call
 * 1.2 Find all unique asset categories
 * 1.2.1 Find all asset category accounting profile lines - one SQL call
 * 1.3 Group the transactions by transaction type
 * 1.4 For each transaction type, get the journal profile - one SQL call
 * 1.4.1 Create a journal header entry - one SQL call
 * 1.4.2 Create journal line entries for all pending transactions for that transaction type - one SQL call
 */
function createAccountingFromParams(dataObject) {
  consoleLog(
    "In prgCreateAccounting invOrgCode " +
      dataObject["invOrgCode"] +
      " invTransactionType " +
      dataObject["invTransactionType"] +
      " SysProgramHeaderId " +
      dataObject["sysProgramHeaderId"]
  );

  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };

  let pendingTransactionSql =
    " SELECT * " +
    " FROM     fa_asset_transaction trx " +
    " JOIN gl_journal_status js ON js.reference_key_value = trx.inv_transaction_id " +
    " AND js.accounting_status IN ('NEW', 'PENDING') " +
    " AND js.reference_key_name = 'fa_asset_transaction' ";

  if (dataObject["faAssetTransactionId"]) {
    pendingTransactionSql +=
      " AND fa_asset_transaction_id = '" +
      dataObject["faAssetTransactionId"] +
      "'";
  }

  if (dataObject["faAssetId"]) {
    pendingTransactionSql +=
      " AND fa_asset_id = '" + dataObject["faAssetId"] + "'";
  }

  if (dataObject["transactionType"]) {
    pendingTransactionSql +=
      " AND transaction_type = '" + transactionType + "'";
  }
  request = {
    sql: pendingTransactionSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  let lineData = response["data"];

  const groupedTransactions = groupTransactionByType(lineData);

  consoleLog("groupedTransactions " + JSON.stringify(groupedTransactions));

  // isArray = lineData.constructor === Array ? true : false;

  // if (isArray) {
  //   for (let i = 0; i < lineData.length; i++) {
  //     const line = lineData[i];
  //     let flatLineObject = {};
  //     getFlatObject(line, flatLineObject);
  //     let invTransactionId = flatLineObject["invTransactionId"];
  //     if (invTransactionId) {
  //       getJournalProfileAndCreateAccounting(flatLineObject, invTransactionId);
  //     }
  //   }
  // } else {
  //   let flatLineObject = {};
  //   getFlatObject(lineData, flatLineObject);
  //   let invTransactionId = flatLineObject["invTransactionId"];
  //   if (invTransactionId) {
  //     getJournalProfileAndCreateAccounting(flatLineObject, invTransactionId);
  //   }
  // }

  return retDataMap;
}

function groupTransactionByType (lineData) {
  let transactionTypeMap = {};
  for (let i = 0; i < lineData.length; i++) {
    const line = lineData[i];
    let transactionType = line["transactionType"];
    if (transactionTypeMap[transactionType]) {
      transactionTypeMap[transactionType].push(line);
    } else {
      transactionTypeMap[transactionType] = [];
      transactionTypeMap[transactionType].push(line);
    }
  }
  return transactionTypeMap;
};

function getJournalProfileAndCreateAccounting(flatObject, invTransactionId) {
  let invTransactionCode = flatObject["invTransactionCode"];
  let invOrgCode = flatObject["invOrgCode"];
  //let invTransactionType = flatObject["invTransactionType"];
  let sql =
    " SELECT jpl.* FROM " +
    " inoerp.gl_journal_profile_l jpl, " +
    " inoerp.gl_journal_profile_h jph, " +
    " inoerp.gl_journal_pro_assg jpa, " +
    " inoerp.inv_transaction_type itt, " +
    " inoerp.inv_transaction it " +
    " WHERE 1 = 1 " +
    " AND jph.gl_journal_profile_h_id = jpl.gl_journal_profile_h_id " +
    " AND jpa.gl_journal_profile_h_id = jph.gl_journal_profile_h_id " +
    " AND itt.gl_document_type = jpa.gl_document_type " +
    " AND it.inv_org_code = jpa.inv_org_code " +
    " AND it.inv_transaction_id = '" +
    invTransactionId +
    "' " +
    " AND it.inv_org_code = '" +
    invOrgCode +
    "' " +
    " AND itt.inv_transaction_code='" +
    invTransactionCode +
    "'; ";

  request = {
    sql: sql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  consoleLog("\n\n journalProfileLines sql " + sql);

  let response = sqlSelect(request);

  let insertSql = [];

  let journalProfileLines = response["data"];
  consoleLog(
    "\n\n journalProfileLines sql " + JSON.stringify(journalProfileLines)
  );

  let accountProfiles = getAccountProfileLines(flatObject);
  let flatJournalAccounts = accountProfiles["data"];

  isArray = journalProfileLines.constructor === Array ? true : false;

  //Create Journal Header
  let headerSql =
    " INSERT INTO `inoerp`.`gl_journal_header` ( `src_entity_name`, `src_entity_id`, `gl_ledger_id`, " +
    " `journal_source`, `journal_category`, `journal_name`, `description`, `balance_type`, " +
    " `reference_type`, `reference_key_name`, `reference_key_value`) SELECT " +
    " 'inv_transaction', '" +
    invTransactionId +
    "', vv_gl_ledger_id, vv_transaction_type_class, vv_transaction_action, " +
    " concat(vv_transaction_type_description, ' - ', inv_transaction_id) , concat(document_type, ' - ', document_id), 'A', " +
    " 'inv_transaction', 'inv_transaction_id', '" +
    invTransactionId +
    "'" +
    " FROM inoerp.inv_transaction_ev WHERE inv_transaction_id = '" +
    invTransactionId +
    "'; ";

  headerInsertRequest = {
    sql: headerSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let headerResponse = sqlInsert(headerInsertRequest);
  let headerResponseData = headerResponse["data"];
  let headerFirstRow = headerResponseData[0];
  var glJournalHeaderId = headerFirstRow["lastInsertId"];

  consoleLog(
    "\n\n journalProfileLines , journalProfileLines 1 " +
      journalProfileLines.length +
      flatJournalAccounts.length
  );

  //Create Journal Lines
  if (
    isArray &&
    journalProfileLines.length > 0 &&
    flatJournalAccounts.length > 0 &&
    glJournalHeaderId > 0
  ) {
    for (let i = 0; i < journalProfileLines.length; i++) {
      const flatJournalProfileLine = journalProfileLines[i];
      let glAcLineType = flatJournalProfileLine["glAcLineType"];
      let drOrCr = flatJournalProfileLine["drOrCr"];
      let seq = flatJournalProfileLine["seq"];

      for (let index = 0; index < flatJournalAccounts.length; index++) {
        const flatJournalAccountLine = flatJournalAccounts[index];
        let lineNum;
        if (seq && seq > 0) {
          lineNum = seq;
        } else {
          lineNum = index + 1;
        }

        if (
          flatJournalAccountLine["glAcLineType"] == glAcLineType &&
          flatJournalAccountLine["drOrCr"] == drOrCr
        ) {
          let sql =
            "  INSERT INTO gl_journal_line (gl_journal_header_id, line_num, reference_entity_name, reference_key_name, reference_key_value, " +
            "  src_entity_name, src_entity_id, p_src_entity_name, p_src_entity_id_name, p_src_entity_id, " +
            "   status, gl_ac_id, amount,dr_cr,doc_currency) " +
            "   SELECT '" +
            glJournalHeaderId +
            "', '" +
            lineNum +
            "', 'inv_transaction', 'inv_transaction_id', '" +
            invTransactionId +
            "', src_entity_name,  src_entity_id, " +
            " 'inv_transaction', 'inv_transaction_id', '" +
            invTransactionId +
            "', 'U'," +
            "   '" +
            flatJournalAccountLine["glAcId"] +
            "' , unit_cost*quantity ,'" +
            drOrCr +
            "',ac_currency" +
            "  FROM inv_transaction_ev " +
            " WHERE inv_transaction_id = '" +
            invTransactionId +
            "'; ";
          insertSql.push(sql);
          consoleLog("\n\n glJournalHeaderId child sql " + sql);
        }
      }
    }
  }

  consoleLog(
    "\n\n insertSql , insertSql 1 " +
      insertSql.length +
      JSON.stringify(insertSql)
  );

  consoleLog(
    "\n\n journalProfileLines , journalProfileLines 1 " +
      journalProfileLines.length +
      JSON.stringify(journalProfileLines)
  );

  // printNestedObject(insertSql);
  let retMessages = [];
  if (insertSql.length == journalProfileLines.length) {
    //Insert Data
    for (let index = 0; index < insertSql.length; index++) {
      const sql = insertSql[index];
      crInsertSql = {
        sql: sql,
        dbType: "MySQL",
        connName: "Inoerp",
      };
      let retMessage = sqlInsert(crInsertSql);
      retMessages.push(retMessage);
      updateAccountingStatus(invTransactionId);
    }
  }
  return retMessages;
}

function getAccountProfileLines(flatObject) {
  let sql = "";
  if (
    flatObject["glAcProfileHeaderId"] &&
    flatObject["glAcProfileHeaderId"].length > 0
  ) {
    let glAcProfileHeaderId = flatObject["glAcProfileHeaderId"];
    sql =
      "SELECT * FROM inoerp.gl_ac_profile_line where gl_ac_profile_header_id = '" +
      glAcProfileHeaderId +
      "' ;";
  } else {
    //Use sql procedure to get glAcProfileHeaderId
    //get profileCodes from transaction
    let invTransactionCode = flatObject["invTransactionCode"];
    sql =
      "call GetAllAccounts('" +
      invTransactionCode +
      "','','','ITEM','','','','','SUBINVENTORY','INVENTORY','BUSINESS_UNIT','LEGAL_ORGANIZATION')";
  }

  request = {
    sql: sql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let response = sqlSelect(request);
  //return response["data"];
  return response;
}

function updateTransactionDetails() {
  let formData = data["formData"];
  let items = formData["items"];
  let menuPath = data["menuPath"];
  let pathCode = menuPath["path_code"];
  var dataMap;
  if (typeof items != "undefined" && items.constructor === Array) {
    for (var i = 0; i < items.length; i++) {
      items[i]["invTransactionCode"] = pathCode;
      if (!items[i]["vvInvTransactionType"]) {
        items[i]["vvInvTransactionType"] = pathCode;
      }
      if (pathCode == "WIP_MATERIAL_RETURN") {
        items[i]["toSubInventory"] = items[i]["fromSubInventory"];
        items[i]["toSubInventory"] = items[i]["fromLocatorId"];
      }
      items[i]["description"] = pathCode;
    }
    formData["items"] = items;
  } else {
    dataMap = items;
    dataMap["invTransactionCode"] = pathCode;
    if (!dataMap["invTransactionCode"]) {
      dataMap["invTransactionCode"] = pathCode;
    }
    dataMap["description"] = pathCode;
    formData["items"] = items;
  }
  data["formData"] = formData;
  return data;
}
updateTransactionDetails();
