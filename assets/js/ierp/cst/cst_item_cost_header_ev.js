function beforePatch(inputData) {
  consoleLog("In cst_item_cost_header_ev beforePatch 1 ");
  var data = inputData["data"];
  var action = data["action"];
  //var cstItemCostHeaderId = data["cstItemCostHeaderId"];

  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Account is successfully completed",
  };
  if (action == "cost_update") {
    let retDataMap2 = changePeriodStatus(data);
    return retDataMap2;
  }else {
    return data;
  }

}
 
function changePeriodStatus(data) {
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

function xxcostUpdateForHeaderId(data) {
  var cstItemCostHeaderId = data["cstItemCostHeaderId"];
  consoleLog(
    "In prgCreateAccounting invItemMasterId " +
      data["invItemMasterId"] +
      " cstItemCostHeaderId " +
      cstItemCostHeaderId +
      " invOrgId " +
      data["invOrgId"]
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

  let lineData = response["data"];
  isArray = lineData.constructor === Array ? true : false;

  let changedCost = getChangedCostAmount(data);

  let insertSql =
    " INSERT INTO cst_frozen_cost (inv_org_id, inv_item_master_id, cst_item_cost_header_id, amount, cost_details) " +
    " SELECT inv_org_id, inv_item_master_id, cst_item_cost_header_id, vv_total_amount, '" +
    JSON.stringify(lineData) +
    "' " +
    " FROM  inoerp.cst_item_cost_header_ev " +
    " WHERE cst_item_cost_header_id = '" +
    cstItemCostHeaderId +
    "' ";

  let costInsertSql = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let retMessage = sqlInsert(costInsertSql);

  //Create the inventory transaction
  //TODO add WIP Quantities
  createInventoryTransaction(data, changedCost);

  retDataMap["rd_proceed_message"] = JSON.stringify(response);
  return retDataMap;
}

function getChangedCostAmount(data) {
  let changedCost = 0;
  //Find the OH Quantity and WIP Quantity
  let costChangeSql =
    " SELECT ifnull(ich.vv_total_amount, 0) - ifnull(cfc.amount, 0) as camount " +
    " from inoerp.cst_item_cost_header_ev ich " +
    " LEFT JOIN inoerp.cst_current_frozen_cost_v cfc ON cfc.inv_org_id = ich.inv_org_id " +
    " and cfc.inv_item_master_id = ich.inv_item_master_id " +
    " where ich.cst_item_cost_header_id = '" +
    data["cstItemCostHeaderId"] +
    "' ";

  let request = {
    sql: costChangeSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);
  let result = response["camount"];
  if (result.length > 0) {
    firstRow = result[0];
    changedCost = firstRow["onhand"];
  }

  return changedCost;
}

function createInventoryTransaction(data, changedCost) {
  let ohQuantity = 0;
  //Find the OH Quantity and WIP Quantity
  let onHandSql =
    " SELECT SUM(onhand) as onhand FROM inoerp.inv_onhand_summary_v " +
    " where inv_org_id = '" +
    data["invOrgId"] +
    "' and inv_item_master_id = '" +
    data["invItemMasterId"] +
    "' GROUP BY inv_org_id, inv_item_master_id";

  let ohRequest = {
    sql: onHandSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let ohResponse = sqlSelect(ohRequest);
  let ohData = ohResponse["data"];
  if (ohData.length > 0) {
    firstRow = ohData[0];
    ohQuantity = firstRow["onhand"];
  }

  let insertSql =
    " INSERT INTO inv_transaction " +
    " (inv_transaction_code,inv_org_code,inv_item_master_id,document_type,document_id, " +
    " oh_impact_type,uom_code,quantity,unit_cost) " +
    " SELECT 'CST_STANDARD_COST_UPDATE',vv_inv_org_code,inv_item_master_id,'CstItemCostHeader', cst_item_cost_header_id," +
    " 'NONE', vv_uom_code,'" +
    ohQuantity +
    "','" +
    changedCost +
    "' " +
    " FROM cst_item_cost_header_ev " +
    " WHERE cst_item_cost_header_id = '" +
    data["cstItemCostHeaderId"] +
    "' ";
  request = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  //  response = sqlInsert(request);
  consoleLog(
    "InsideJsTesting createInventoryTransaction insertSql " + insertSql
  );
}

function prgCreateAccounting(inputData) {
  var params = inputData["params"];
  let paramData = JSON.parse(params);
  let flatObject = {};
  getFlatObject(paramData, flatObject);
  //printNestedObject(flatObject);
  changePeriodStatus(flatObject);
}
