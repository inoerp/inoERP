function beforePatch(inputData) {
  let data = inputData["data"];
  let action = data["action"];
  if (action == "create_accounting") {
    return createAccountingFromParams(data, action);
  } else if (action == "prj_generate_draft_revenue") {
    return generateDraftRevenue(data, action);
  } else {
    return data;
  }
}


//1. Find all document lines
//2. Find gl_document_type and corresponding journal lines (journal profile lines)from expenditure_header_id
//3. Find all accounts from business unit and expense_type
//4. Create a single gl_journal_header and gl_journal_lines for that gl_header_id

function createAccountingFromParams(data) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };

  const allLines = findAllLinesToBeAccounted(data);
  const journalTemplateLines = getAllJournalProfiles(data);
  const allAccountProfiles = getAllAccountProfiles(data);

  if (allLines.length < 1) {
    retDataMap["rd_proceed_message"] = "No lines to be accounted";
    return retDataMap;
  }

  const headerFirstRow = allLines[0];
  const vvGlLedgerId = headerFirstRow["vvGlLedgerId"];
  const vvGlDocumentType = headerFirstRow["glDocumentType"];

  //createJournalHeader
  const glJournalHeaderId = createJournalHeader(
    vvGlLedgerId,
    "project_expenditure",
    vvGlDocumentType
  );

  let message = createJournalLines(
    glJournalHeaderId,
    allLines,
    journalTemplateLines,
    allAccountProfiles
  );

  retDataMap["rd_proceed_message"] = message;

  return retDataMap;
}

function createJournalLines(
  glJournalHeaderId,
  allLines,
  journalTemplateLines,
  allAccountProfiles
) {
  let lineSql =
    " INSERT INTO `inoerp`.`gl_journal_line` (`gl_journal_header_id`, `reference_entity_name`, `reference_key_name`, `reference_key_value`, `src_entity_name`, \
   `src_entity_id_name`, `src_entity_id`, `line_num`, `p_src_entity_name`, `p_src_entity_id_name`, `p_src_entity_id`, `gl_ac_id`, `amount`, `dr_cr`) VALUES ";

  let updateSql =
    " UPDATE `inoerp`.`prj_billing_doc_header` SET accounting_status = 'accounting_completed' \
    WHERE prj_billing_doc_header_id IN (";

  let prjBillingDocHeaderIds = [];
  isError = false;

  for (let i = 0; i < allLines.length; i++) {
    const transactionRow = allLines[i];
    const prjBillingDocHeaderId = transactionRow["prjBillingDocHeaderId"];
    const prjBillingDocLineId = transactionRow["prjBillingDocLineId"];

    for (let index = 0; index < journalTemplateLines.length; index++) {
      const journalLine = journalTemplateLines[index];
      let amount = parseFloat(transactionRow["lineAmount"]);
      if (amount == 0) {
        continue;
      }
      if (amount == "") {
        return (
          "Unable to complete accounting as no amount found for " +
          journalLine["glAcLineType"]
        );
      }

      const glAcId = getGlAcId(
        allAccountProfiles,
        journalLine["glAcLineType"],
        journalLine["drOrCr"]
      );

      if (glAcId == "") {
        return (
          "Unable to complete accounting as no gl account found for " +
          journalLine["glAcLineType"]
        );
      }

      lineSql +=
        " ('" +
        glJournalHeaderId +
        "', 'prj_billing_doc_line', 'prj_billing_doc_line_id', '" +
        prjBillingDocLineId +
        "', 'prj_billing_doc_line', 'prj_billing_doc_line_id', '" +
        prjBillingDocLineId +
        "', '" +
        journalLine["seq"] +
        "', 'prj_billing_doc_header', 'prj_billing_doc_header_id', '" +
        prjBillingDocHeaderId +
        "', '" +
        glAcId +
        "', '" +
        transactionRow["lineAmount"] +
        "', '" +
        journalLine["drOrCr"] +
        "' ) ";

      let addUpdateStmt = false;
      if (prjBillingDocHeaderIds.indexOf(prjBillingDocHeaderId) == -1) {
        prjBillingDocHeaderIds.push(prjBillingDocHeaderId);
        updateSql += "'" + prjBillingDocHeaderId + "'";
      } else if (prjBillingDocHeaderIds.indexOf(prjBillingDocHeaderId) == 0) {
        addUpdateStmt = true;
      }

      if (
        index == journalTemplateLines.length - 1 &&
        i == allLines.length - 1
      ) {
      } else {
        lineSql += " , ";
        if (prjBillingDocHeaderIds.length > 1 && addUpdateStmt) {
          updateSql += " , ";
        }
      }
    }
  }

  updateSql += ")";

  const insertResponse = insertDataWithSql(lineSql);
  consoleLog("\n\n insertResponse " + insertResponse);
  //TODO validate insertResponse before proceeding

  const updateResponse = updateDataWithSql(updateSql);
  return updateResponse;
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

function createJournalHeader(vvGlLedgerId, transactionType, vvGlDocumentType) {
  let headerSql =
    " INSERT INTO `inoerp`.`gl_journal_header` ( `gl_ledger_id`, `journal_source`, `journal_category`, `journal_name`,\
       `description`, `balance_type`) VALUES( '" +
    vvGlLedgerId +
    "', 'PRJ', '" +
    vvGlDocumentType +
    "' , 'Project Expenditure Accounting', 'Expenditure Accounting For " +
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

function findAllLinesToBeAccounted(dataObject) {
  let selectSql =
    "SELECT * FROM prj_billing_doc_line_unaccounted_v WHERE 1 = 1 ";

  if (dataObject["vvBuOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["vvBuOrgId"] + "'";
  } else if (dataObject["buOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["buOrgId"] + "'";
  }

  if (dataObject["prjBillingDocHeaderId"]) {
    selectSql +=
      " AND prj_billing_doc_header_id = '" +
      dataObject["prjBillingDocHeaderId"] +
      "'";
  }

  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  return response["data"];
}

function getAllJournalProfiles() {
  let selectSql =
    " SELECT gjpl.*       \
      FROM        inoerp.gl_journal_profile_l gjpl \
      join inoerp.gl_journal_profile_h gjph ON gjpl.gl_journal_profile_h_id =  gjph.gl_journal_profile_h_id \
      AND gjph.profile_code = 'prj_billing' ";

  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  return response["data"];
}

function getAllAccountProfiles(dataObject) {
  let selectSql = "SELECT * FROM prj_billing_ac_profile_v WHERE 1 = 1 ";

  if (dataObject["vvBuOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["vvBuOrgId"] + "'";
  } else if (dataObject["buOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["buOrgId"] + "'";
  }

  if (dataObject["prjBillingDocHeaderId"]) {
    selectSql +=
      " AND prj_billing_doc_header_id = '" +
      dataObject["prjBillingDocHeaderId"] +
      "'";
  }

  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  return response["data"];
}

//TODO: move to common file

function generateDraftRevenue(data) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Request request is successfully submitted",
  };

  let prjProjectHeaderId = data["prjProjectHeaderId"];

  //get all project details
  let projectDetails = findProjectDetails(prjProjectHeaderId);
  let glAcProfileHeaderId = 0;
  let revenueRecognitionMethod = "";

  if (projectDetails.length < 1) {
    retDataMap["rd_proceed_message"] = "Project details not found";
    return retDataMap;
  } else {
    glAcProfileHeaderId = projectDetails[0]["glAcProfileHeaderId"];
    revenueRecognitionMethod = projectDetails[0]["revenueRecognitionMethod"];
  }

  //get existing revenue header details or else create new header
  let prjRevenueDocHeaderId = getPrjRevenueDocHeaderId(
    prjProjectHeaderId,
    glAcProfileHeaderId
  );
  if (prjRevenueDocHeaderId > 0) {
  } else {
    retDataMap["rd_proceed_message"] = "No revenue header found";
    return retDataMap;
  }

  //get existing revenue amount
  const existingLines = findExistingRevenueAmount(prjRevenueDocHeaderId);

  let existingRevenueAmount = 0;
  let existingLineNumber = 0;

  if (existingLines.length > 0) {
    let existingLineData = existingLines[0];
    existingRevenueAmount = existingLineData["revenueAmount"];
    existingLineNumber = existingLineData["lineNumber"];
  }
  let newLineNumber = existingLineNumber + 1;

  let message = "Invalid revenue recognition method";
  if (revenueRecognitionMethod == "completed_contract") {
  } else if (revenueRecognitionMethod == "percentage_of_completion") {
    message = generateDraftRevenueForPOC(
      prjProjectHeaderId,
      prjRevenueDocHeaderId,
      newLineNumber,
      existingRevenueAmount
    );
  } else if (revenueRecognitionMethod == "milestone") {
  } else if (revenueRecognitionMethod == "manual") {
  }

  retDataMap["rd_proceed_message"] = message;

  return retDataMap;
}

function findProjectDetails(prjProjectHeaderId) {
  let selectSql =
    "SELECT * from prj_project_header where prj_revenue_doc_header_id = '" +
    prjProjectHeaderId +
    "'";
  let selectData = getDataFromSql(selectSql);
  return selectData;
}

function findExistingRevenueAmount(prjRevenueDocHeaderId) {
  let selectSql =
    " SELECT prj_revenue_header_id, ifnull(max(line_number),0) line_number, \
   ifnull(sum(revenue_amount), 0) revenue_amount  \
  from prj_revenue_doc_line \
  where prj_revenue_doc_header_id = '" +
    prjRevenueDocHeaderId +
    "' \
  GROUP BY prj_revenue_header_id ";
  let selectData = getDataFromSql(selectSql);
  return selectData;
}

function getPrjRevenueDocHeaderId(prjProjectHeaderId, glAcProfileHeaderId) {
  let headerSql =
    " SELECT * FROM `inoerp`.`prj_revenue_doc_header` WHERE `prj_project_header_id` = '" +
    prjProjectHeaderId +
    "' ";
  let headerData = getDataFromSql(headerSql);
  let prjRevenueDocHeaderId = 0;
  if (headerData.length > 0) {
    let headerDataMap = selectData[0];
    prjRevenueDocHeaderId = headerDataMap["prjRevenueDocHeaderId"];
  } else {
    //crate new revenue header
    let headerInsertSql =
      " INSERT INTO `inoerp`.`prj_revenue_doc_header`  \
    (`prj_project_header_id`, `gl_ac_profile_header_id`) VALUES ";
    if (glAcProfileHeaderId > 0) {
      headerInsertSql +=
        "('" + prjProjectHeaderId + "', '" + glAcProfileHeaderId + "')";
    } else {
      headerInsertSql += "('" + prjProjectHeaderId + "', NULL)";
    }
    let headerInsertResponse = insertDataWithSql(headerInsertSql);
    let headerFirstRow = headerInsertResponse[0];
    prjRevenueDocHeaderId = headerFirstRow["lastInsertId"];
  }

  return prjRevenueDocHeaderId;
}

//generate draft revenue for the given project using percentage of completion method
//Check if existing revenue exists for the given project. If yes, then update the existing revenue
// Existing revenue amount = Sum of all existing revenue lines for the given project
//Find all cost and revenue budget amounts
//Find all actual cost data
//Find expected revenue amount = (revenue budget amount)* percentage of completion
//                            = (revenue budget amount)* ((completed cost amount)/(budgeted cost amount))
// If expected revenue amount is greater than existing revenue amount, then create new revenue line
function generateDraftRevenueForPOC(
  prjProjectHeaderId,
  prjRevenueDocHeaderId,
  newLineNumber,
  existingRevenueAmount
) {
  let costSql =
    " SELECT prj_project_header_id, \
   ifnull(material_cost, 0) + ifnull(material_cost, 0) + ifnull(material_cost, 0) as total_cost \
  FROM inoerp.prj_project_cost_v WHERE prj_project_header_id = '" +
    prjProjectHeaderId +
    "' ";
  let costData = getDataFromSql(costSql);
  let totalCost = 0;
  if (costData.length > 0) {
    let costDataMap = costData[0];
    totalCost = costDataMap["totalCost"];
  } else {
    return "No cost data found";
  }
  if (totalCost == 0) {
    return "Total incurred cost is zero";
  }

  let budgetSql =
    " SELECT prj_project_header_id, vv_total_cost as cost_budget,  revenue as revenue_budget \
  FROM inoerp.prj_budget_header_ev \
  WHERE version_number = 0 AND prj_project_header_id = '" +
    prjProjectHeaderId +
    "' ";
  let budgetData = getDataFromSql(budgetSql);
  let costBudget = 0;
  let revenueBudget = 0;
  if (budgetData.length > 0) {
    let budgetDataMap = budgetData[0];
    costBudget = budgetDataMap["costBudget"];
    revenueBudget = budgetDataMap["revenueBudget"];
  } else {
    return "No budget data found";
  }

  let totalCostNum = parseFloat(totalCost);
  if (totalCostNum < 0) {
    return "Sum of total incurred cost is zero";
  }

  let costBudgetNum = parseFloat(costBudget);
  let revenueBudgetNum = parseFloat(revenueBudget);
  let fractionOfCompletion = costBudgetNum / totalCostNum;
  if(fractionOfCompletion > 1){
    fractionOfCompletion = 1;
  }
  let expectedRevenueAmount = revenueBudgetNum * fractionOfCompletion;
  if (expectedRevenueAmount <= existingRevenueAmount) {
    return (
      "New expected revenue " +
      expectedRevenueAmount +
      " is less than equal to existing revenue " +
      existingRevenueAmount
    );
  }
  let newRevenueAmount = expectedRevenueAmount - existingRevenueAmount;

  let revenueInsertSql =
    " INSERT INTO `inoerp`.`prj_revenue_doc_line` (`prj_revenue_header_id`, `line_number`, \
  `revenue_amount`, `suggested_amount`, `total_cost_amount`, `budget_cost_amount`, `budget_revenue_amount`) VALUES \
  ('" +
    prjRevenueDocHeaderId +
    "','" +
    newLineNumber +
    "','" +
    newRevenueAmount +
    "','" +
    newRevenueAmount +
    "','" +
    totalCostNum +
    "','" +
    costBudgetNum +
    "','" +
    revenueBudgetNum +
    "') ";
  let revenueInsertResponse = insertDataWithSql(revenueInsertSql);
  let revenueFirstRow = revenueInsertResponse[0];
  return JSON.stringify(revenueFirstRow);
}


