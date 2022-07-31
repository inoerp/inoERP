function beforePatch(inputData) {
  let data = inputData["data"];
  let action = data["action"];
  if (action == "prj_update_project_cost") {
    let retData = updateProjectCost(data);
    return retData;
  } else {
    return data;
  }
}

function getExpenditureCost1(selectSql) {
  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  return response["data"];
}

function getExpenditureCost2(selectSql) {
  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  return response["data"];
}

function getExpenditureCost3(selectSql) {
  consoleLog("\n\n getExpenditureCost3öp-p: " + selectSql);

  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  return response["data"];
}

function updateProjectCost(dataObject) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Update request is successfully submitted",
  };

  let prjProjectHeaderId = dataObject["prjProjectHeaderId"];
  let vvPrjProjectHeaderId = 0;

  let vvPrjProjectHeaderIdNum = parseInt(prjProjectHeaderId);
  if (isNaN(vvPrjProjectHeaderIdNum)) {
    retDataMap["rd_proceed_message"] =
      "Fail to update project cost as vvPrjProjectHeaderId is not a number";
    return retDataMap;
  } else {
    vvPrjProjectHeaderId = vvPrjProjectHeaderIdNum;
  }

  if (vvPrjProjectHeaderId <= 0) {
    retDataMap["rd_proceed_message"] =
      "Fail to update project cost as vvPrjProjectHeaderId is 0";
    return retDataMap;
  }

  let expenditureCost = 0;
  let materialCost = 0;
  let resourceCost = 0;

  let selectSql =
    "SELECT * from prj_cst_exp_trnx_sum_v WHERE prj_project_header_id = '" +
    vvPrjProjectHeaderId +
    "'";
  const expenditureValue = getExpenditureCost1(selectSql);

  if (expenditureValue.length > 0) {
    let expenditureCostNum = parseFloat(expenditureValue[0]["cost"]);
    if (isNaN(expenditureCostNum)) {
      retDataMap["rd_proceed_message"] =
        "Fail to update project cost as expenditureCost is not a number";
      return retDataMap;
    } else {
      expenditureCost = expenditureCostNum;
    }
  }

  selectSql =
    "SELECT * from prj_cst_mat_trnx_sum_v WHERE prj_project_header_id = '" +
    vvPrjProjectHeaderId +
    "'";
  const materialValue = getExpenditureCost2(selectSql);

  if (materialValue.length > 0) {
    let materialCostNum = parseFloat(materialValue[0]["cost"]);
    if (isNaN(materialCostNum)) {
      retDataMap["rd_proceed_message"] =
        "Fail to update project cost as materialCost is not a number";
      return retDataMap;
    } else {
      materialCost = materialCostNum;
    }
  }

  selectSql =
    "SELECT * from prj_cst_res_trnx_sum_v WHERE prj_project_header_id = '" +
    vvPrjProjectHeaderId +
    "'";
  const resourceValue = getExpenditureCost3(selectSql);
  if (resourceValue.length > 0) {
    let resourceCostNum = parseFloat(resourceValue[0]["cost"]);
    if (isNaN(resourceCostNum)) {
      retDataMap["rd_proceed_message"] =
        "Fail to update project cost as resourceCost is not a number";
      return retDataMap;
    } else {
      resourceCost = resourceCostNum;
    }
  }

  if (vvPrjProjectHeaderId > 0) {
    checkAndUpdateProjectCostXX(
      prjProjectHeaderId,
      expenditureCost,
      materialCost,
      resourceCost
    );
  }

  return retDataMap;
}

function checkAndUpdateProjectCostXX(
  prjProjectHeaderId,
  expenditureCost,
  materialCost,
  resourceCost
) {
  //Check if project cost exists
  //If not, create it
  //else update it

  if (prjProjectHeaderId > 0) {
  } else {
    return;
  }

  let selectSql =
    "SELECT * from prj_project_task_cost WHERE prj_project_header_id = '" +
    prjProjectHeaderId +
    "'";
  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  const responseData = response["data"];

  if (responseData.length > 0) {
    updateExistingProjectCost(
      prjProjectHeaderId,
      expenditureCost,
      materialCost,
      resourceCost
    );
  } else {
    insertProjectCost(
      prjProjectHeaderId,
      expenditureCost,
      materialCost,
      resourceCost
    );
  }
}

function insertProjectCost(
  prjProjectHeaderId,
  expenditureCost,
  materialCost,
  resourceCost
) {
  if (prjProjectHeaderId > 0) {
  } else {
    return;
  }

  let insertSql =
    "INSERT INTO prj_project_task_cost (prj_project_header_id, misc_expenditure, material_cost, resource_cost) VALUES ('" +
    prjProjectHeaderId +
    "', '" +
    expenditureCost +
    "', '" +
    materialCost +
    "', '" +
    resourceCost +
    "')";
  request = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlInsert(request);
}

function updateExistingProjectCost(
  prjProjectHeaderId,
  expenditureCost,
  materialCost,
  resourceCost
) {
  if (prjProjectHeaderId > 0) {
  } else {
    return;
  }

  let updateSql =
    "UPDATE prj_project_task_cost SET misc_expenditure = '" +
    expenditureCost +
    "', material_cost = '" +
    materialCost +
    "', resource_cost = '" +
    resourceCost +
    "' WHERE prj_project_header_id = '" +
    prjProjectHeaderId +
    "'";
  request = {
    sql: updateSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlUpdate(request);
}
