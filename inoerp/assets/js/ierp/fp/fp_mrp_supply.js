function beforePatch(inputData) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let request = inputData["request"];
  let data = inputData["data"];
  let action = data["action"];

  if (
    action == "mrp_release_planned_order" ||
    action == "mrp_release_planned_orders"
  ) {
  } else {
    return data;
  }

  consoleLog("\n\nIn beforePatch fp_mrp_supply " + JSON.stringify(data));

  // Release planned orders
  let refreshResult;
  if (action == "mrp_release_planned_order") {
    refreshResult = releasePlannedOrder(data);
  } else if (action == "mrp_release_planned_orders") {
    refreshResult = releaseAllPlannedOrders(data);
  }

  if (refreshResult != undefined) {
    retDataMap["rd_proceed_message"] = getMessageFromSqlResponse(refreshResult);
  } else {
    retDataMap["rd_proceed_message"] = "Release is successfully completed";
  }

  return retDataMap;
}

function releasePlannedOrder(data) {
  let supplyType = data["formData"]["supplyType"];
  let fpMrpSupplyId = data["fpMrpSupplyId"];
  if (fpMrpSupplyId == undefined) {
    fpMrpSupplyId = data["formData"]["fpMrpSupplyId"];
  }

  if (supplyType == "planned_order_pr") {
    return createPurchaseRequisition(fpMrpSupplyId);
  } else if (supplyType == "planned_order_wo") {
    return createWorkOrderInterface(fpMrpSupplyId);
  }

  return;
}

function releaseAllPlannedOrders(data) {
  let supplyType = data["formData"]["supplyType"];
  let fpMrpHeaderId = data["formData"]["fpMrpHeaderId"];
  if (fpMrpHeaderId == undefined) {
    fpMrpHeaderId = data["formData"]["fpMrpHeaderId"];
  }

  if (supplyType == "planned_order_pr") {
    createAllPurchaseRequisitions(fpMrpHeaderId);
  } else if (supplyType == "planned_order_wo") {
    return createAllWorkOrders(fpMrpHeaderId);
  }

  return;
}

function createWorkOrderInterface(fpMrpSupplyId) {
  let insertSql =
    "  INSERT INTO `inoerp`.`wip_wo_interface` (`inv_org_id`, `wip_wd_header_id`, `inv_item_master_id`, " +
    " `description`,  `quantity`, `nettable_quantity`,  `fp_mrp_supply_id`, `start_date` ) " +
    " SELECT inv_org_id, ifnull(wip_wd_header_id, 1), inv_item_master_id, 'Released from MRP',  " +
    "  quantity,  quantity, fp_mrp_supply_id, supply_date " +
    " FROM inoerp.fp_mrp_supply_ev WHERE supply_type = 'planned_order_wo' AND fp_mrp_supply_id = '" +
    fpMrpSupplyId +
    "' ";

  let insertSqlRequest = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  return sqlInsert(insertSqlRequest);
}

function createAllWorkOrders(fpMrpHeaderId) {
  let insertSql =
    "  INSERT INTO `inoerp`.`wip_wo_interface` (`inv_org_id`, `wip_wd_header_id`, `inv_item_master_id`, " +
    " `description`,  `quantity`, `nettable_quantity`,  `fp_mrp_supply_id`, `start_date` ) " +
    " SELECT inv_org_id, wip_wd_header_id, inv_item_master_id, 'Released from MRP',  " +
    "  quantity,  quantity, fp_mrp_supply_id, supply_date " +
    " FROM inoerp.fp_mrp_supply_ev WHERE supply_type = 'planned_order_wo' AND fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' ";

  let insertSqlRequest = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  return sqlInsert(insertSqlRequest);
}

function createAllPurchaseRequisitions(fpMrpHeaderId) {
  let insertSql =
    "  INSERT INTO `inoerp`.`po_requisition_interface` (`bu_org_id`, `line_number`, `doc_currency`, `receiving_org_id`, `inv_item_master_id`, " +
    " `product_description`, `line_type`, `uom_code`, `line_quantity`, `unit_price`, `supplier_id`, `supplier_site_id`, " +
    " `fp_mrp_supply_id`, `need_by_date` ) " +
    " SELECT bu_org_id, 1, doc_currency, inv_org_id, inv_item_master_id, item_description, 'ITEM', " +
    " uom_code, quantity, ifnull(list_price, 0), supplier_id, supplier_site_id, fp_mrp_supply_id, supply_date " +
    " FROM inoerp.fp_mrp_supply_ev WHERE supply_type = 'planned_order_pr' AND fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' ";

  let insertSqlRequest = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  return sqlInsert(insertSqlRequest);
}

function createPurchaseRequisition(fpMrpSupplyId) {
  let insertSql =
    "  INSERT INTO `inoerp`.`po_requisition_interface` (`bu_org_id`, `line_number`, `doc_currency`, `receiving_org_id`, `inv_item_master_id`, " +
    " `product_description`, `line_type`, `uom_code`, `line_quantity`, `unit_price`, `supplier_id`, `supplier_site_id`, " +
    " `fp_mrp_supply_id`, `need_by_date` ) " +
    " SELECT bu_org_id, 1, doc_currency, inv_org_id, inv_item_master_id, item_description, 'ITEM', " +
    " uom_code, quantity, ifnull(list_price, 0), supplier_id, supplier_site_id, fp_mrp_supply_id, supply_date " +
    " FROM inoerp.fp_mrp_supply_ev WHERE supply_type = 'planned_order_pr' AND fp_mrp_supply_id = '" +
    fpMrpSupplyId +
    "' ";

  let insertSqlRequest = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  return sqlInsert(insertSqlRequest);
}
