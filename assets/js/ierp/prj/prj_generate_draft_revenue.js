function generateDraftRevenue(data) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Request request is successfully submitted",
  };

  let prjProjectHeaderId = data["prjProjectHeaderId"];

  //get all project details
  let projectDetails = findProjectDetails(data);
  let glAcProfileHeaderId = 0;
  let revenueRecognitionMethod = "";
  let docStatus = "";

  if (projectDetails.length < 1) {
    retDataMap["rd_proceed_message"] = "Project details not found";
    return retDataMap;
  } else {
    glAcProfileHeaderId = projectDetails[0]["glAcProfileHeaderId"];
    revenueRecognitionMethod = projectDetails[0]["revenueRecognitionMethod"];
    prjProjectHeaderId = projectDetails[0]["prjProjectHeaderId"];
    docStatus = projectDetails[0]["docStatus"];
  }

  //for completed_contract project, project status must be completed
  if (
    revenueRecognitionMethod == "completed_contract" &&
    docStatus != "COMPLETE"
  ) {
    retDataMap["rd_proceed_message"] =
      "Fail to generate draft revenue as project status is not complete";
    return retDataMap;
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
    if (existingLineData["revenueAmount"]) {
      existingRevenueAmount = existingLineData["revenueAmount"];
    }
    if (existingLineData["lineNumber"]) {
      existingLineNumber = existingLineData["lineNumber"];
    }
  }
  let existingLineNumberNum = parseInt(existingLineNumber);
  let newLineNumber = existingLineNumberNum + 1;
  let existingRevenueAmountNum = parseFloat(existingRevenueAmount);

  let message = "Invalid revenue recognition method";
  if (
    revenueRecognitionMethod == "percentage_of_completion" ||
    revenueRecognitionMethod == "completed_contract" ||
    revenueRecognitionMethod == "milestone" ||
    revenueRecognitionMethod == "manual"
  ) {
    message = generateDraftRevenueForPOC(
      prjProjectHeaderId,
      prjRevenueDocHeaderId,
      newLineNumber,
      existingRevenueAmountNum,
      revenueRecognitionMethod
    );
  }
  retDataMap["rd_proceed_message"] = message;

  return retDataMap;
}

function findProjectDetails(data) {
  let selectSql = "SELECT * from prj_project_header where 1 = 1 ";
  if (data["prjProjectHeaderId"]) {
    selectSql +=
      " AND prj_project_header_id = '" + data["prjProjectHeaderId"] + "'";
  } else if (data["prjBudgetHeaderId"]) {
    selectSql +=
      " AND prj_project_header_id IN (SELECT prj_project_header_id FROM prj_budget_header \
        WHERE version_number = 0 AND prj_budget_header_id = '" +
      data["prjBudgetHeaderId"] +
      "')";
  } else if (data["prjRevenueDocHeaderId"]) {
    selectSql +=
      " AND prj_project_header_id IN (SELECT prj_project_header_id FROM prj_revenue_doc_header \
        WHERE prj_revenue_doc_header_id = '" +
      data["prjRevenueDocHeaderId"] +
      "')";
  } else {
    return [];
  }

  let selectData = getDataFromSql(selectSql);
  return selectData;
}

function findExistingRevenueAmount(prjRevenueDocHeaderId) {
  let selectSql =
    " SELECT prj_revenue_doc_header_id, ifnull(max(line_number),0) line_number, \
   ifnull(sum(revenue_amount), 0) revenue_amount  \
  from prj_revenue_doc_line \
  where prj_revenue_doc_header_id = '" +
    prjRevenueDocHeaderId +
    "' \
  GROUP BY prj_revenue_doc_header_id ";
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
    let headerDataMap = headerData[0];
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
  existingRevenueAmount,
  revenueRecognitionMethod
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

  let expectedRevenueAmount = getExpectedRevenueAmount(
    costBudgetNum,
    totalCostNum,
    revenueBudgetNum,
    revenueRecognitionMethod,
    prjProjectHeaderId
  );
  if (expectedRevenueAmount <= existingRevenueAmount) {
    return (
      "New expected revenue " +
      expectedRevenueAmount +
      " is less than equal to existing revenue " +
      existingRevenueAmount
    );
  }

  let newRevenueAmount = getNewRevenueAmount(
    expectedRevenueAmount,
    existingRevenueAmount,
    revenueRecognitionMethod
  );

  let revenueInsertSql =
    " INSERT INTO `inoerp`.`prj_revenue_doc_line` (`prj_revenue_doc_header_id`, `line_number`, \
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

function getNewRevenueAmount(
  expectedRevenueAmount,
  existingRevenueAmount,
  revenueRecognitionMethod
) {
  if (revenueRecognitionMethod == "manual") {
    return 0;
  } else {
    return expectedRevenueAmount - existingRevenueAmount;
  }
}

function getExpectedRevenueAmount(
  costBudgetNum,
  totalCostNum,
  revenueBudgetNum,
  revenueRecognitionMethod,
  prjProjectHeaderId
) {
  if (revenueRecognitionMethod == "percentage_of_completion") {
    let fractionOfCompletion = totalCostNum / costBudgetNum  ;
    if (fractionOfCompletion > 1) {
      fractionOfCompletion = 1;
    }
    let expectedRevenueAmount = revenueBudgetNum * fractionOfCompletion;
    return expectedRevenueAmount;
  } else if (revenueRecognitionMethod == "milestone") {
    return getExpectedRevenueForMilestone(prjProjectHeaderId);
  } else {
    return revenueBudgetNum;
  }
}

function getExpectedRevenueForMilestone(prjProjectHeaderId) {
  let milestoneSql =
    " SELECT vv_prj_project_header_id, sum(revenue_amount) as revenue_amount \
  from prj_milestone_budget_line_v \
  WHERE  1 = 1 \
  AND vv_task_doc_status IN ('COMPLETE', 'PENDING_CLOSE', 'CLOSED') \
  AND vv_milestone_cb = 1 \
  AND vv_prj_project_header_id = '" +
    prjProjectHeaderId +
    "' \
  GROUP BY vv_prj_project_header_id ";

  let milestoneData = getDataFromSql(milestoneSql);
  let revenueAmount = 0;
  if (milestoneData.length > 0) {
    let milestoneDataMap = milestoneData[0];
    revenueAmountStr = milestoneDataMap["revenueAmount"];
    if (revenueAmountStr != null) {
      revenueAmount = parseFloat(revenueAmountStr);
    }
  }
  return revenueAmount;
}
