function beforePatch(inputData) {
  consoleLog("In cst_item_cost_header_ev beforePatch 1 ");
  var data = inputData["data"];
  var action = data["action"];
  //var cstItemCostHeaderId = data["cstItemCostHeaderId"];

  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Account is successfully created",
  };
  if (action == "cost_update") {
    let retDataMap2 = costUpdateForHeaderId(data);
    return retDataMap2;
  }

  return retDataMap;
}

function costUpdateForHeaderId(data) {
  var cstItemCostHeaderId = data["cstItemCostHeaderId"];
  consoleLog(
    "In prgCreateAccounting cstItemCostHeaderId " + cstItemCostHeaderId
  );

  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Cost update request is successfully submitted",
  };

  let sql = " select inoerp.cstStandardCostUpdate(" + cstItemCostHeaderId + ")";

  request = {
    sql: sql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  retDataMap["rd_proceed_message"] = JSON.stringify(response);
  return retDataMap;
}


function prgCreateAccounting(inputData) {
  var params = inputData["params"];
  let paramData = JSON.parse(params);
  let flatObject = {};
  getFlatObject(paramData, flatObject);
  //printNestedObject(flatObject);
  costUpdateForHeaderId(flatObject);
}
