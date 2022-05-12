function beforePatch(inputData) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let request = inputData["request"];
  let data = inputData["data"];
  let action = data["action"];
  let faAssetId = data["faAssetId"];

  if (
    action == "fa_depreciation" ||
    action == "fa_depreciation_category" ||
    action == "fa_depreciation_legal_org"
  ) {
    return createAssignment(action, faAssetId);
  } else if (
    action == "fa_status_active" ||
    action == "fa_status_active_category" ||
    action == "fa_status_active_legal_org" ||
    action == "fa_status_retire" ||
    action == "fa_status_on_hold"
  ) {
    return changeStatus(action, faAssetId);
  } else if (
    action == "fa_create_account" ||
    action == "fa_create_account_category" ||
    action == "fa_create_account_legal_org"
  ) {
    return createAccountingFromParams(data, action);
  } else {
    return data;
  }

  return retDataMap;
}

function createAssignment(action, inputAssetId) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let insertSql =
    " INSERT INTO `inoerp`.`fa_asset_transaction` \
     (`fa_asset_id`, `fa_asset_book_id`, `transaction_type`, `amount`,`amount_10`,`amount_20`, `depreciation_period_no`) VALUES ";

  let selectSql =
    " SELECT (book.vv_depreciation_periods - book.vv_last_depreciation_period_no) as no_of_dep_period, \
     book.* \
   FROM inoerp.fa_asset_book_ev book \
   where vv_depreciation_periods <= life_months AND vv_asset_type ='capitalized' AND vv_asset_status ='active' \
   AND vv_depreciation_periods > vv_last_depreciation_period_no  ";

  const rateDetails = getDepreciationRates();

  if (action == "fa_depreciation") {
    selectSql += " AND fa_asset_id = '" + inputAssetId + "' ";
  } else if (action == "fa_depreciation_category") {
    selectSql +=
      " AND vv_fa_asset_category_id IN (SELECT fa_asset_category_id from inoerp.fa_asset \
       WHERE fa_asset_id = '" +
      inputAssetId +
      "' ) ";
  } else {
    selectSql +=
      " AND vv_legal_org_id IN (SELECT legal_org_id from inoerp.fa_asset \
       WHERE fa_asset_id = '" +
      inputAssetId +
      "' ) ";
  }

  let selectSqlRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let selectSqlResponse = sqlSelect(selectSqlRequest);
  let selectSqlResponseData = selectSqlResponse["data"];

  let createInsertRecord = false;

  if (selectSqlResponseData.length > 0) {
    for (let i = 0; i < selectSqlResponseData.length; i++) {
      const rowData = selectSqlResponseData[i];
      const faAssetId = rowData["faAssetId"];
      const faAssetBookId = rowData["faAssetBookId"];

      const noOfDepPeriod = parseInt(rowData["noOfDepPeriod"]);
      const lastDepreciationPeriodNo = parseInt(
        rowData["vvLastDepreciationPeriodNo"]
      );
      const vvNetBookValue = parseFloat(rowData["vvNetBookValue"]);
      const vvDepreciationLimitAmount = parseFloat(
        rowData["vvDepreciationLimitAmount"]
      );

      let depreciationAmount = getDepreciationAmount(rowData, rateDetails);
      if (depreciationAmount > vvNetBookValue) {
        depreciationAmount = vvNetBookValue;
      }
      consoleLog(
        "\n\n\n depreciationAmount 3  : " +
          depreciationAmount +
          " vvDepreciationLimitAmount:" +
          vvDepreciationLimitAmount
      );

      if (
        vvDepreciationLimitAmount > 0 &&
        depreciationAmount > vvDepreciationLimitAmount
      ) {
        depreciationAmount = vvDepreciationLimitAmount;
      }

      for (let j = 0; j < noOfDepPeriod; j++) {
        let depreciationPeriodNo = lastDepreciationPeriodNo + j + 1;
        insertSql +=
          " ('" +
          faAssetId +
          "', '" +
          faAssetBookId +
          "', 'depreciation', '" +
          depreciationAmount +
          "','" +
          depreciationAmount +
          "','" +
          depreciationAmount +
          "','" +
          depreciationPeriodNo +
          "')";

        if (i == selectSqlResponseData.length - 1 && j == noOfDepPeriod - 1) {
        } else {
          insertSql += ",";
        }
        if (createInsertRecord == false) {
          createInsertRecord = true;
        }
      }
    }
  }

  if (createInsertRecord == true) {
    let insertSqlRequest = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let insertSqlResponse = sqlInsert(insertSqlRequest);

    retDataMap["rd_proceed_message"] =
      getMessageFromSqlResponse(insertSqlResponse);
  } else {
    retDataMap["rd_proceed_message"] =
      "No records found to create depreciation";
  }

  return retDataMap;
}

function getDepreciationAmount(rowData, rateDetails) {
  const depreciationType = rowData["vvDepreciationType"];
  let depreciationAmount = 0;

  if (depreciationType == "double_decline") {
    depreciationAmount = getDepreciationAmountForStraightLine(rowData);
    const vvFactorPercentage = parseInt(rowData["vvFactorPercentage"]);
    if (vvFactorPercentage > 0) {
      depreciationAmount = depreciationAmount * (vvFactorPercentage / 100);
    }
  } else if (depreciationType == "sum_of_years") {
    depreciationAmount = getDepreciationAmountForStraightLine(rowData);
    const vvFactor = getSumOfYearsFactor(rowData);
    if (vvFactor > 0) {
      depreciationAmount = depreciationAmount * vvFactor;
    }
  } else if (depreciationType == "rate_based") {
    depreciationAmount = getRateBaseDepreciationAmount(rowData, rateDetails);
  } else {
    depreciationAmount = getDepreciationAmountForStraightLine(rowData);
  }

  return depreciationAmount;
}

function getRateBaseDepreciationAmount(rowData, rateDetails) {
  const faDepreciationMethodId = rowData["faDepreciationMethodId"];
  const rateLines = rateDetails[faDepreciationMethodId];

  if (rateLines == undefined) {
    return 0;
  }
  const currDepreciationPeriodNo =
    parseInt(rowData["vvLastDepreciationPeriodNo"]) + 1;

  let depreciationRate = 0;

  for (let i = 0; i < rateLines.length; i++) {
    const rateLine = rateLines[i];
    const rateLinePeriodNo = parseInt(rateLine["vvMonthlyPeriodNo"]);
    const rate = parseFloat(rateLine["rate"]);

    if (rateLinePeriodNo == currDepreciationPeriodNo) {
      depreciationRate = rate;
    }
  }

  let depreciationAmount = 0;

  const calculationBasis = parseFloat(rowData["vvCalculationBasis"]);
  if (calculationBasis == "cost") {
    const vvCurrentCost = parseFloat(rowData["vvCurrentCost"]);
    depreciationAmount = vvCurrentCost * (depreciationRate / 100);
  } else {
    const recoverableAmount = parseFloat(rowData["vvRecoverableAmount"]);
    depreciationAmount = recoverableAmount * (depreciationRate / 100);
  }
  return depreciationAmount;
}

function getSumOfYearsFactor(rowData) {
  const lifeMonths = parseInt(rowData["lifeMonths"]);
  const lastDepreciationPeriodNo = parseInt(
    rowData["vvLastDepreciationPeriodNo"]
  );
  const lifeYears = Math.ceil(lifeMonths / 12);
  const currentYear = Math.ceil(lastDepreciationPeriodNo / 12);
  const sumOfYears = (lifeYears * (lifeYears + 1)) / 2;
  const factor = (lifeYears - currentYear) / sumOfYears;
  if (factor > 0) {
    return 1 / factor;
  } else {
    return 1;
  }
}

function getDepreciationAmountForStraightLine(rowData) {
  const lastDepreciationPeriodNo = parseInt(
    rowData["vvLastDepreciationPeriodNo"]
  );
  const lifeMonths = parseInt(rowData["lifeMonths"]);
  const recoverableAmount = parseFloat(rowData["vvRecoverableAmount"]);
  const accumulatedDepreciation = parseFloat(
    rowData["vvAccumulatedDepreciation"]
  );
  let depreciationAmount = 0;
  const vvCurrentCost = parseFloat(rowData["vvCurrentCost"]);
  const calculationBasis = parseFloat(rowData["vvCalculationBasis"]);

  if (calculationBasis == "cost") {
    depreciationAmount = vvCurrentCost / lifeMonths;
  } else {
    depreciationAmount =
      (recoverableAmount - accumulatedDepreciation) /
      (lifeMonths - lastDepreciationPeriodNo);
  }

  consoleLog("\n\n\n depreciationAmount 1  : " + depreciationAmount);
  return depreciationAmount;
}

function changeStatus(action, faAssetId) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let statusValue = "";
  let transactionType = "";
  if (
    action == "fa_status_active" ||
    action == "fa_status_active_category" ||
    action == "fa_status_active_legal_org"
  ) {
    statusValue = "active";
    transactionType = "addition";
  } else if (action == "fa_status_retire") {
    statusValue = "retired";
    transactionType = "retirement";
  } else {
    statusValue = "on_hold";
  }

  if (
    action == "fa_status_active" ||
    action == "fa_status_retire" ||
    action == "fa_status_active_category" ||
    action == "fa_status_active_legal_org"
  ) {
    createStatusTransaction(transactionType, faAssetId, action);
  }
  retDataMap["rd_proceed_message"] = updateAssetStatus(
    statusValue,
    faAssetId,
    action
  );

  return retDataMap;
}

function updateAssetStatus(statusValue, faAssetId, action) {
  let updateSql =
    " UPDATE `inoerp`.`fa_asset` SET asset_status = '" +
    statusValue +
    "' " +
    " WHERE  1 = 1  ";

  let updateData = true;

  if (action == "fa_status_active") {
    updateSql +=
      " AND asset_status = 'pending_addition' AND fa_asset_id = '" +
      faAssetId +
      "' ";
  } else if (action == "fa_status_active_category") {
    const assetDetails = getAssetDetails(faAssetId);
    updateSql +=
      " AND asset_status = 'pending_addition' AND fa_asset_category_id ='" +
      assetDetails["faAssetCategoryId"] +
      "' ";
  } else if (action == "fa_status_active_legal_org") {
    const assetDetails = getAssetDetails(faAssetId);
    updateSql +=
      " AND asset_status = 'pending_addition' AND legal_org_id ='" +
      assetDetails["legalOrgId"] +
      "' ";
  } else if (action == "fa_status_retire") {
    updateSql +=
      " AND asset_status IN ('active', 'on_hold') AND fa_asset_id = '" +
      faAssetId +
      "' ";
  } else {
    updateData = false;
  }

  if (updateData == true) {
    let updateSqlRequest = {
      sql: updateSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let updateSqlResponse = sqlUpdate(updateSqlRequest);

    return getMessageFromSqlResponse(updateSqlResponse);
  } else {
    return "No data to update";
  }
}

function getAssetDetails(faAssetId) {
  let selectSql =
    "SELECT * FROM inoerp.fa_asset WHERE fa_asset_id = '" + faAssetId + "' ";

  let sqlRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let sqlResponse = sqlSelect(sqlRequest);
  let sqlResponseData = sqlResponse["data"];

  if (sqlResponseData.length > 0) {
    return sqlResponseData[0];
  } else {
    return {};
  }
}

function getDepreciationRates() {
  let selectSql = "SELECT * FROM inoerp.fa_depreciation_method_rate_ev ";

  let sqlRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let sqlResponse = sqlSelect(sqlRequest);
  let sqlResponseData = sqlResponse["data"];

  //convert to map
  let retDataMap = {};
  for (let i = 0; i < sqlResponseData.length; i++) {
    let rowData = sqlResponseData[i];
    if (rowData["faDepreciationMethodId"] in retDataMap) {
      retDataMap[rowData["faDepreciationMethodId"]].push(rowData);
    } else {
      retDataMap[rowData["faDepreciationMethodId"]] = [rowData];
    }
  }

  return retDataMap;
}

function createStatusTransaction(transactionType, faAssetId, action) {
  let insertSql =
    " INSERT INTO `inoerp`.`fa_asset_transaction` (`fa_asset_id`, `fa_asset_book_id`, `transaction_type`, `amount`, `amount_10`, `amount_20`) " +
    " SELECT fa_asset_id, fa_asset_book_id, '" +
    transactionType +
    "', original_cost, original_cost, original_cost " +
    " from fa_asset_book_ev WHERE  1 = 1 ";

  let insertData = true;

  if (action == "fa_status_active") {
    insertSql +=
      " AND vv_asset_status = 'pending_addition' AND fa_asset_id = '" +
      faAssetId +
      "' ";
  } else if (action == "fa_status_active_category") {
    insertSql +=
      " AND vv_asset_status = 'pending_addition' AND vv_fa_asset_category_id IN (SELECT fa_asset_category_id from inoerp.fa_asset \
       WHERE fa_asset_id = '" +
      faAssetId +
      "' ) ";
  } else if (action == "fa_status_active_legal_org") {
    insertSql +=
      " AND vv_asset_status = 'pending_addition' AND vv_legal_org_id IN (SELECT legal_org_id from inoerp.fa_asset \
     WHERE fa_asset_id = '" +
      faAssetId +
      "' ) ";
  } else if (action == "fa_status_retire") {
    return createRetirementTransaction(faAssetId, transactionType);
  } else {
    insertData = false;
  }

  if (insertData == true) {
    let insertSqlRequest = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let insertSqlResponse = sqlInsert(insertSqlRequest);
    return getMessageFromSqlResponse(insertSqlResponse);
  } else {
    return "No data to insert";
  }
}

function createRetirementTransaction(faAssetId, transactionType) {
  let insertSql =
    " INSERT INTO `inoerp`.`fa_asset_transaction` (`fa_asset_id`, `fa_asset_book_id`, `transaction_type`, `amount`, `amount_10`, `amount_20`, `amount_30`) " +
    " SELECT fa_asset_id, fa_asset_book_id, '" +
    transactionType +
    "',vv_current_cost, vv_accumulated_depreciation, vv_net_book_value, vv_current_cost " +
    " from fa_asset_book_ev WHERE  1 = 1 AND fa_asset_id = '" +
    faAssetId +
    "' ";
  let insertSqlRequest = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let insertSqlResponse = sqlInsert(insertSqlRequest);
  return getMessageFromSqlResponse(insertSqlResponse);
}

// fa_asset_cost
// fa_depreciation
// fa_cost_clearing
// fa_accumulated_depreciation
// fa_retired
// fa_cost_adjustment
// fa_depreciation_adjustment
// fa_depreciation_prior_period
// fa_cost_clearing_prior_period
// fa_cost_of_removal
// fa_revaluation_reserve
// fa_bonus_reserve

// Addition
// fa_asset_cost   dr
//              fa_cost_clearing cr

// Depreciation
// fa_depreciation   dr
//              fa_accumulated_depreciation cr

// Adjustment
// fa_asset_cost   dr
//              fa_cost_clearing cr

// Retirement
// fa_retired                   dr
// fa_accumulated_depreciation dr
//                        fa_asset_cost   cr

/*
 * 1. Find all transactions pending for accounting - one SQL call
 * 1.0 All 1.1* are merged into one SQL call - fa_asset_ac_profile_v
 * 1.1 Find all unique assets
 * 1.1.2 Find all asset accounting profile lines - one SQL call
 * 1.2 Find all unique asset categories
 * 1.2.1 Find all asset category accounting profile lines - one SQL call
 * 1.3 Group the transactions by transaction type
 * 1.4 For each transaction type, get the journal profile - one SQL call
 * 1.4.1 Create a journal header entry - one SQL call
 * 1.4.2 Create journal line entries for all pending transactions for that transaction type - one SQL call
 */
function createAccountingFromParams(dataObject, action) {
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
    " FROM     fa_asset_transaction_v trx " +
    " JOIN gl_journal_status js ON js.reference_key_value = trx.fa_asset_transaction_id " +
    " AND js.accounting_status IN ('NEW', 'PENDING') " +
    " AND js.reference_key_name = 'fa_asset_transaction' ";

  if (action == "fa_create_account_legal_org") {
    if (dataObject["vvLegalOrgId"]) {
      pendingTransactionSql +=
        " AND vv_legal_org_id = '" + dataObject["vvLegalOrgId"] + "'";
    } else if (dataObject["legalOrgId"]) {
      pendingTransactionSql +=
        " AND vv_legal_org_id = '" + dataObject["legalOrgId"] + "'";
    }
  } else {
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

    if (dataObject["faBookId"]) {
      pendingTransactionSql +=
        " AND fa_book_id = '" + dataObject["faBookId"] + "'";
    }

    if (dataObject["transactionType"]) {
      pendingTransactionSql +=
        " AND transaction_type = '" + transactionType + "'";
    }
  }

  request = {
    sql: pendingTransactionSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  let lineData = response["data"];

  if (lineData.length < 1) {
    retDataMap["rd_proceed_message"] = "No pending transactions found";
  }

  const groupedTransactions = groupTransactionByType(lineData);
  const allAccountProfiles = getAllAccountProfiles(dataObject);
  const faJournalProfiles = getFaJournalProfiles(dataObject);

  // consoleLog("groupedTransactions " + JSON.stringify(groupedTransactions));

  // consoleLog("allAccountProfiles " + JSON.stringify(allAccountProfiles));

  //consoleLog("faJournalProfiles " + JSON.stringify(faJournalProfiles));

  for (const transactionType in groupedTransactions) {
    const transactionRows = groupedTransactions[transactionType];
    if (transactionRows.length > 0) {
      const headerFirstRow = transactionRows[0];
      const vvGlLedgerId = headerFirstRow["vvGlLedgerId"];
      const vvGlDocumentType = headerFirstRow["vvGlDocumentType"];
      const vvDepreciationCb = headerFirstRow["vvDepreciationCb"];
      const vvBookType = headerFirstRow["vvBookType"];

           consoleLog("\n\n\n journalTemplateLines faJournalProfiles vvBookType "  + vvBookType + " vvGlLedgerId " + vvGlLedgerId + " vvGlDocumentType " + vvGlDocumentType + " depreciationCb " + vvDepreciationCb);


      if (
        vvBookType == "primary" &&
        (vvDepreciationCb == "1" || vvDepreciationCb == "true")
      ) {
        //create accounting for primary book
      } else {
        continue;
      }

      //createJournalHeader
      const glJournalHeaderId = createJournalHeader(
        vvGlLedgerId,
        transactionType,
        vvGlDocumentType
      );
      let journalTemplateLines = [];

      //consoleLog("\n\n\n journalTemplateLines faJournalProfiles "  + JSON.stringify(faJournalProfiles));

      for (const jlLine of faJournalProfiles) {
        if (jlLine["faTransactionCode"] == transactionType) {
          journalTemplateLines.push(jlLine);
        }
      }

      createJournalLines(
        glJournalHeaderId,
        transactionRows,
        journalTemplateLines,
        allAccountProfiles
      );

      consoleLog(
        "\n\n\n journalTemplateLines transactionType " +
          transactionType +
          " : " +
          JSON.stringify(journalTemplateLines)
      );
      //createJournalLines(dataObject, transactionType, faJournalProfiles, transactionRows);
      //updateJournalStatus(dataObject, transactionType, faJournalProfiles, transactionRows);
    }
  }

  return retDataMap;
}

function createJournalHeader(vvGlLedgerId, transactionType, vvGlDocumentType) {
  let headerSql =
    " INSERT INTO `inoerp`.`gl_journal_header` ( `gl_ledger_id`, `journal_source`, `journal_category`, `journal_name`,\
     `description`, `balance_type`) VALUES( '" +
    vvGlLedgerId +
    "', 'FA', '" +
    vvGlDocumentType +
    "' , 'Asset Accounting', 'Asset Accounting For " +
    transactionType +
    "', 'A' ) ";

  headerInsertRequest = {
    sql: headerSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const headerResponse = sqlInsert(headerInsertRequest);
  const headerResponseData = headerResponse["data"];
  const headerFirstRow = headerResponseData[0];
  const glJournalHeaderId = headerFirstRow["lastInsertId"];
  return glJournalHeaderId;
}

function createJournalLines(
  glJournalHeaderId,
  transactionRows,
  journalTemplateLines,
  allAccountProfiles
) {
  let lineSql =
    " INSERT INTO `inoerp`.`gl_journal_line` (`gl_journal_header_id`, `reference_entity_name`, `reference_key_name`, `reference_key_value`, `src_entity_name`, \
 `src_entity_id_name`, `src_entity_id`, `line_num`, `p_src_entity_name`, `p_src_entity_id_name`, `p_src_entity_id`, `gl_ac_id`, `amount`, `dr_cr`) VALUES ";

  let updateSql =
    " UPDATE `inoerp`.`gl_journal_status` SET accounting_status = 'COMPLETED' \
  WHERE reference_key_name = 'fa_asset_transaction' and accounting_status IN ('NEW', 'PENDING') AND reference_key_value IN (";

  for (let i = 0; i < transactionRows.length; i++) {
    const transactionRow = transactionRows[i];
    const faAssetBookId = transactionRow["faAssetBookId"];
    const faAssetTransactionId = transactionRow["faAssetTransactionId"];

    for (let index = 0; index < journalTemplateLines.length; index++) {
      const journalLine = journalTemplateLines[index];
      let amountKey = "amount_" + journalLine["seq"];
      let amount = parseFloat(transactionRow[amountKey]);
      if (amount == 0) {
        continue;
      }
      const glAcId = getGlAcId(
        allAccountProfiles,
        journalLine["glAcLineType"],
        journalLine["drOrCr"]
      );
      lineSql +=
        " ('" +
        glJournalHeaderId +
        "', 'fa_asset_transaction', 'fa_asset_transaction_id', '" +
        faAssetTransactionId +
        "', 'fa_asset_transaction', 'fa_asset_transaction_id', '" +
        faAssetTransactionId +
        "', '" +
        journalLine["seq"] +
        "', 'fa_asset_book', 'fa_asset_book_id', '" +
        faAssetBookId +
        "', '" +
        glAcId +
        "', '" +
        transactionRow[amountKey] +
        "', '" +
        journalLine["drOrCr"] +
        "' ) ";

      updateSql += "'" + faAssetTransactionId + "'";

      if (
        index == journalTemplateLines.length - 1 &&
        i == transactionRows.length - 1
      ) {
      } else {
        lineSql += " , ";
        updateSql += " , ";
      }
    }
  }

  updateSql += ")";

  let insertRequest = {
    sql: lineSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const insertResponse = sqlInsert(insertRequest);
  //TODO validate insertResponse before proceeding

  let updateRequest = {
    sql: updateSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const updateResponse = sqlUpdate(updateRequest);

  consoleLog("\n\n\n lineSql " + JSON.stringify(updateSql));
  consoleLog("\n\n\n insertResponse " + JSON.stringify(updateResponse));
}

function getGlAcId(allAccountProfiles, glAcLineType, drOrCr) {
  let glAcId = "";

  for (const profile of allAccountProfiles) {
    if (
      profile["glAcLineType"] == glAcLineType &&
      profile["drOrCr"] == drOrCr
    ) {
      glAcId = profile["glAcId"];
      break;
    }
  }

  return glAcId;
}

function getFaJournalProfiles() {
  let selectSql =
    " SELECT fat.*, gjpl.* \
  FROM \
  inoerp.fa_transaction_type fat \
  join inoerp.gl_journal_profile_h gjph ON gjph.profile_code = fat.gl_document_type \
  join  inoerp.gl_journal_profile_l gjpl ON gjpl.gl_journal_profile_h_id =  gjph.gl_journal_profile_h_id ";

  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  return response["data"];
}

function getAllAccountProfiles(dataObject) {
  let selectSql = "SELECT * FROM fa_asset_ac_profile_v WHERE 1 = 1 ";

  if (dataObject["vvLegalOrgId"]) {
    selectSql += " AND legal_org_id = '" + dataObject["vvLegalOrgId"] + "'";
  } else if (dataObject["legalOrgId"]) {
    selectSql += " AND legal_org_id = '" + dataObject["legalOrgId"] + "'";
  }

  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  return response["data"];
}

function groupTransactionByType(lineData) {
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
}
