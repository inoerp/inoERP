function beforePatch(inputData) {
  let data = inputData["data"];
  let action = data["action"];
  if (
    action == "make_primary_revision" ||
    action == "copy_to_primary_revision"
  ) {
    let retData = reviewAndUpdateRevision(data, action);
    return retData;
  } else if (action == "prj_generate_draft_revenue") {
    return generateDraftRevenue(data, action);
  } else {
    return data;
  }
}

function reviewAndUpdateRevision(dataObject, action) {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Update request is successfully submitted",
  };

  let prjBudgetHeaderIdStr = dataObject["prjBudgetHeaderId"];
  let prjBudgetHeaderId = 0;

  let prjBudgetHeaderIdNum = parseInt(prjBudgetHeaderIdStr);
  if (isNaN(prjBudgetHeaderIdNum)) {
    retDataMap["rd_proceed_message"] =
      "Fail to make budget primary as prjBudgetHeaderId is not a number";
    return retDataMap;
  } else {
    prjBudgetHeaderId = prjBudgetHeaderIdNum;
  }

  if (prjBudgetHeaderId <= 0) {
    retDataMap["rd_proceed_message"] =
      "Fail to  make budget primary as  prjBudgetHeaderId is 0";
    return retDataMap;
  }

  let retMessage = "No message from server";

  if (action == "make_primary_revision") {
    retMessage = makePrimaryRevision(prjBudgetHeaderId);
  } else if (action == "copy_to_primary_revision") {
    retMessage = copyToPrimaryRevision(prjBudgetHeaderId);
  }

  retDataMap["rd_proceed_message"] = JSON.stringify(retMessage);

  return retDataMap;
}

function makePrimaryRevision(prjBudgetHeaderId) {
  let updateSql =
    "UPDATE prj_budget_header SET version_number = 0 where prj_budget_header_id = '" +
    prjBudgetHeaderId +
    "'";
  return updateDataWithSql(updateSql);
}

function copyToPrimaryRevision(prjBudgetHeaderId) {
  let selectSql =
    "SELECT * FROM prj_budget_header where prj_budget_header_id = '" +
    prjBudgetHeaderId +
    "'";
  let selectData = getDataFromSql(selectSql);
  if (selectData.length < 1) {
    return {
      error:
        "Fail to copy to primary revision as no primary active revision found.\
       Make sure you have at least one active revision (revision with version_number = 0)",
    };
  }
  let selectDataMap = selectData[0];

  let materialCost = selectDataMap["materialCost"];
  let otherCost = selectDataMap["otherCost"];
  let resourceCost = selectDataMap["resourceCost"];
  let revenue = selectDataMap["revenue"];
  let prjProjectHeaderId = selectDataMap["prjProjectHeaderId"];

  let updateSql =
    "UPDATE prj_budget_header SET  material_cost = '" +
    materialCost +
    "', \
  other_cost = '" +
    otherCost +
    "', resource_cost = '" +
    resourceCost +
    "', revenue = '" +
    revenue +
    "' where version_number = '0' and prj_project_header_id = '" +
    prjProjectHeaderId +
    "'";

  return updateDataWithSql(updateSql);
}
