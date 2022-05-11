function beforePost(inputData) {
  let returnData = {};
  var data = inputData["data"];
  var invTransactionCode = data["invTransactionCode"];
  var entityPath = data["entityPath"];
  var status = null;

  //TODO: Need to verify item is defined in both the organizations
  if (invTransactionCode == "MISCELLANEOUS_RECEIPT" || invTransactionCode == "PO_DELIVERY") {
    data["ohImpactType"] = "POSITIVE";
    returnData = data;
  } else if (invTransactionCode == "MISCELLANEOUS_ISSUE") {
    data["ohImpactType"] = "NEGATIVE";
    returnData = data;
  } else if (invTransactionCode == "SUBINVENTORY_TRANSFER" || invTransactionCode == "INTER_ORG_TRANSFER_DIRECT") {
    let positiveTransactionData = {};
    let negativeTransactionData = {};
    let keys = Object.keys(data);
    for(let i = 0; i < keys.length; i++) {
         let k = keys[i];
         negativeTransactionData[k] = data[k];
         positiveTransactionData[k] = data[k];
         
    }
    negativeTransactionData["invOrgCode"] = data["fromOrgCode"];
    positiveTransactionData["invOrgCode"] = data["toOrgCode"];
    positiveTransactionData["ohImpactType"] = "POSITIVE";
    negativeTransactionData["ohImpactType"] = "NEGATIVE";
    let items = [];
    items.push(positiveTransactionData);
    items.push(negativeTransactionData);
    returnData["items"] = items;
  }else{
    returnData = data;
  }

  return returnData;
  
}

function xxbeforePost(inputData) {
  let returnData = {};
  var data = inputData["data"];
  var invTransactionCode = data["invTransactionCode"];
  var entityPath = data["entityPath"];
  var status = null;

  if (invTransactionCode == "MISCELLANEOUS_RECEIPT") {
    data["ohImpactType"] = "POSITIVE";
    returnData = data;
  } else if (invTransactionCode == "MISCELLANEOUS_ISSUE") {
    data["ohImpactType"] = "NEGATIVE";
    returnData = data;
  } else if (invTransactionCode == "SUBINVENTORY_TRANSFER" || invTransactionCode == "INTER_ORG_TRANSFER_DIRECT") {
    let positiveTransactionData = {};
    let negativeTransactionData = {};
    let keys = Object.keys(data);
    for(let i = 0; i < keys.length; i++) {
         let k = keys[i];
         if(k.startsWith("fromSubInv") || k.startsWith("fromLoc") || k.startsWith("fromInv")|| k.startsWith("fromOrg")) {
          negativeTransactionData[k] = data[k];
          positiveTransactionData[k] = null;
         }else if(k.startsWith("toSubInv") || k.startsWith("toLoc") || k.startsWith("toInv")|| k.startsWith("toOrg")) {
          positiveTransactionData[k] = data[k];
          negativeTransactionData[k] = null;
         }else{
          negativeTransactionData[k] = data[k];
          positiveTransactionData[k] = data[k];
         }
    }
    positiveTransactionData["ohImpactType"] = "POSITIVE";
    negativeTransactionData["ohImpactType"] = "NEGATIVE";
    let items = [];
    items.push(positiveTransactionData);
    items.push(negativeTransactionData);
    returnData["items"] = items;
  } 

  return returnData;
  
}

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
    let retDataMap2 = createAccountingForInventoryTransaction(data);
    return retDataMap2;
  }

  return retDataMap;
}

function validateBeforeIssueTransaction(status, data) {
  if (status !== null) {
    request = {
      sql:
        "UPDATE sd_so_header SET doc_status = '" +
        status +
        "' WHERE sd_so_header_id = '" +
        data["sdSoHeaderId"] +
        "' ",
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let response = sqlUpdate(request);
    request = {
      sql:
        "UPDATE sd_so_line SET doc_status = '" +
        status +
        "' WHERE sd_so_header_id = '" +
        data["sdSoHeaderId"] +
        "' ",
      dbType: "MySQL",
      connName: "Inoerp",
    };
    response = sqlUpdate(request);
    if (response != null) {
      //      printNestedObject(response);
    }
  }
}

function prgCreateAccounting(inputData) {
  var params = inputData["params"];
  let paramData = JSON.parse(params);
  let flatObject = {};
  getFlatObject(paramData, flatObject);
  //printNestedObject(flatObject);
  createAccountingForInventoryTransaction(flatObject);
}

function createAccountingForInventoryTransaction(flatObject) {
  consoleLog(
    "In prgCreateAccounting invOrgCode " +
      flatObject["invOrgCode"] +
      " invTransactionType " +
      flatObject["invTransactionType"] +
      " SysProgramHeaderId " +
      flatObject["sysProgramHeaderId"]
  );

  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };

  let pendingTransactionSql =
    " SELECT * " +
    " FROM     inv_transaction trx " +
    " JOIN gl_journal_status js ON js.reference_key_value = trx.inv_transaction_id " +
    " AND js.accounting_status IN ('NEW', 'PENDING') " +
    " AND js.reference_key_name = 'inv_transaction' ";

  if (flatObject["invTransactionId"]) {
    pendingTransactionSql +=
      " AND inv_transaction_id = '" + flatObject["invTransactionId"] + "'";
  }

  if (flatObject["invOrgCode"]) {
    pendingTransactionSql +=
      " AND inv_org_code = '" + flatObject["invOrgCode"] + "'";
  }

  if (flatObject["invTransactionType"]) {
    pendingTransactionSql +=
      " AND vv_inv_transaction_type = '" + invTransactionType + "'";
  }
  consoleLog("\n\npendingTransactionSql " + pendingTransactionSql);
  request = {
    sql: pendingTransactionSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  let lineData = response["data"];
  isArray = lineData.constructor === Array ? true : false;

  consoleLog(
    "In prgCreateAccounting lineData " +
      typeof lineData +
      " lineData " +
      lineData +
      " isArray " +
      isArray
  );

  printNestedObject(lineData);

  if (isArray) {
    for (let i = 0; i < lineData.length; i++) {
      const line = lineData[i];
      let flatLineObject = {};
      getFlatObject(line, flatLineObject);
      accounts = getAccountId(flatLineObject);
      let invTransactionId = flatLineObject["invTransactionId"];
      let accountingStatus = flatLineObject["accountingStatus"];
      if (invTransactionId) {
        createAccounting(invTransactionId, accounts);
      }
    }
  } else {
    let flatLineObject = {};
    getFlatObject(lineData, flatLineObject);
    accounts = getAccountId(flatLineObject);
    let invTransactionId = flatLineObject["invTransactionId"];
    let accountingStatus = flatLineObject["accountingStatus"];
    if (invTransactionId) {
      createAccounting(invTransactionId, accounts);
    }
  }

  return retDataMap;
}

function getAccountId(flatLineObject) {
  let sql =
    " SELECT * " +
    " FROM inoerp.gl_accounting_rule " +
    " WHERE 1 = 1 " +
    " AND rule_element_name = 'DEFAULT' ";
  if (flatLineObject["invOrgCode"]) {
    sql +=
      " OR (rule_element_name = 'INV_ORG_CODE' AND rule_element_value = '" +
      flatLineObject["invOrgCode"] +
      "') ";
  }
  consoleLog("\n\n getAccountId " + sql);
  request = {
    sql: sql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  let lineData = response["data"];
  isArray = lineData.constructor === Array ? true : false;

  let drAcSegments = {};
  let crAcSegments = {};

  if (isArray) {
    for (let i = 0; i < lineData.length; i++) {
      const line = lineData[i];
      let flatLineObject = {};
      getFlatObject(line, flatLineObject);
      let isDebit = flatLineObject["drCr"] === "D" ? true : false;
      let allKeys = Object.keys(flatLineObject);
      for (let i = 0; i < allKeys.length; i++) {
        let k = allKeys[i];
        let v = flatLineObject[k];
        if (k.startsWith("coaSegment")) {
          if (isDebit) {
            if (!drAcSegments[k]) {
              drAcSegments[k] = v;
            }
          } else {
            if (!crAcSegments[k]) {
              crAcSegments[k] = v;
            }
          }
        }
      }
    }
  } else {
    let flatLineObject = {};
    getFlatObject(lineData, flatLineObject);
    consoleLog("---------------------Accounting Rules ----------------");
    printNestedObject(flatLineObject);
  }


 // printNestedObject(drAcSegments);
  drAcId = getAccountIdFromSegmentValues(drAcSegments);

  crAcId = getAccountIdFromSegmentValues(crAcSegments);

  consoleLog("---------------Ac Ids ------------");
  consoleLog(" drAcId " + drAcId + " crAcId " + crAcId);
  let retDataMap = {
    "drAcId": drAcId,
    "crAcId": crAcId,
  }
 // printNestedObject(crAcSegments);
 return retDataMap
}

function getAccountIdFromSegmentValues(segmentValues) {
  let retId = 0;
  let sql =
    "SELECT  coa.coa_separator, coa.allow_dynamic_insert," +
    " gcc.* " +
    " FROM  " +
    " gl_coa_combination gcc, " +
    " gl_coa coa " +
    " WHERE 1 = 1 " +
    " AND coa.coa_id = gcc.coa_id ";
  if (segmentValues["coaSegment1"]) {
    sql += " AND gcc.coa_segment1 = '" + segmentValues["coaSegment1"] + "'";
  }
  if (segmentValues["coaSegment2"]) {
    sql += " AND  gcc.coa_segment2 = '" + segmentValues["coaSegment2"] + "'";
  }
  if (segmentValues["coaSegment3"]) {
    sql += " AND  gcc.coa_segment3 = '" + segmentValues["coaSegment3"] + "'";
  }
  if (segmentValues["coaSegment4"]) {
    sql += " AND  gcc.coa_segment4 = '" + segmentValues["coaSegment4"] + "'";
  }
  if (segmentValues["coaSegment5"]) {
    sql += " AND  gcc.coa_segment5 = '" + segmentValues["coaSegment5"] + "'";
  }
  if (segmentValues["coaSegment6"]) {
    sql += " AND  gcc.coa_segment6 = '" + segmentValues["coaSegment6"] + "'";
  }
  if (segmentValues["coaSegment7"]) {
    sql += " AND  gcc.coa_segment7 = '" + segmentValues["coaSegment7"] + "'";
  }
  if (segmentValues["coaSegment8"]) {
    sql += " AND  gcc.coa_segment8 = '" + segmentValues["coaSegment8"] + "'";
  }

  consoleLog("\n\n getAccountIdFromSegmentValues " + sql);
  request = {
    sql: sql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  let lineData = response["data"];
  isArray = lineData.constructor === Array ? true : false;

  if (isArray) {
    if(lineData.length > 0){
      const line = lineData[0];
      let flatLineObject = {};
      getFlatObject(line, flatLineObject);
      consoleLog("---------------------Accounting Rules Array ----------------");
      printNestedObject(flatLineObject);
      retId = flatLineObject["coaCombinationId"];
    }
  } else {
    let flatLineObject = {};
    getFlatObject(lineData, flatLineObject);
    consoleLog("---------------------Accounting Rules ----------------");
    printNestedObject(flatLineObject);
    retId = flatLineObject["coaCombinationId"];

  }

  return retId;
}

function createAccounting(invTransactionId, accounts) {
  var retMessage = "";
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is not allowed",
  };
  let drCodeCombinationId = accounts["drAcId"];
  let crCodeCombinationId = accounts["crAcId"];
  if (invTransactionId && drCodeCombinationId && crCodeCombinationId) {
    drInsertSql = {
      sql:
        "  INSERT INTO gl_journal_line (line_num, reference_entity_name, reference_key_name, reference_key_value, status, ledger_id," +
        "   code_combination_id, total_amount,total_ac_amount,dr_cr,ac_currency,doc_currency) " +
        "   SELECT '1', 'inv_transaction', 'inv_transaction_id', '" +
        invTransactionId +
        "', 'U', ledger_id," +
        "   '" +
        drCodeCombinationId +
        "' , costed_amount,costed_amount,'D',ac_currency,ac_currency" +
        "  FROM inv_transaction_ev " +
        " WHERE inv_transaction_id = '" +
        invTransactionId +
        "'; ",
      dbType: "MySQL",
      connName: "Inoerp",
    };

    let retMessage1 = sqlInsert(drInsertSql);
    consoleLog("retMessage1: " + retMessage1);
    printNestedObject(retMessage1["data"][0]);
    if (retMessage1["data"][0]["message"]) {
      retMessage += "\n" + retMessage1["data"][0]["message"];
    } else {
      retMessage += "\n" + retMessage1["data"];
    }

    crInsertSql = {
      sql:
        "  INSERT INTO gl_journal_line (line_num, reference_entity_name, reference_key_name, reference_key_value, status, ledger_id," +
        "   code_combination_id, total_amount,total_ac_amount,dr_cr,ac_currency,doc_currency) " +
        "   SELECT '2', 'inv_transaction', 'inv_transaction_id', '" +
        invTransactionId +
        "', 'U', ledger_id," +
        "   '" +
        crCodeCombinationId +
        "' , costed_amount,costed_amount,'C',ac_currency,ac_currency" +
        "  FROM inv_transaction_ev " +
        " WHERE inv_transaction_id = '" +
        invTransactionId +
        "'; ",
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let retMessage2 = sqlInsert(crInsertSql);

    if (retMessage2["data"][0]["message"]) {
      retMessage += "\n" + retMessage2["data"][0]["message"];
    } else {
      retMessage += "\n" + retMessage2["data"];
    }

    retDataMap["rd_proceed_message"] = retMessage;

    updateAccountingStatus(invTransactionId);
  }
  return retDataMap;
}

function updateAccountingStatus(invTransactionId) {
  request = {
    sql:
      "UPDATE gl_journal_status SET accounting_status = 'COMPLETED' " +
      " WHERE reference_key_name = 'inv_transaction' " +
      " AND reference_key_value = '" +
      invTransactionId +
      "' ",
    dbType: "MySQL",
    connName: "Inoerp",
  };
  sqlUpdate(request);
}

function updateTransactionDetails(){
  let formData = data["formData"];
  let items = formData["items"];
  let menuPath = data["menuPath"];
  let pathCode = menuPath["path_code"];
  var dataMap;
  if (typeof items != "undefined" && items.constructor === Array) {
    for (var i = 0; i < items.length; i++) {
      items[i]["invTransactionCode"] = pathCode;
      items[i]["description"] = pathCode;
    }
    formData["items"] = items;
  } else {
    dataMap = items;
    dataMap["invTransactionCode"] = pathCode;
    dataMap["description"] = pathCode;
    formData["items"] = items;
  }
   data["formData"] = formData;
   return data;
}
updateTransactionDetails();