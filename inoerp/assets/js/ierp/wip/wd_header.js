function afterPost(inputData) {
  //return inputData["data"];
  if (inputData != null) {
  } else {
    return inputData;
  }

  var data = inputData["data"];
  var isArray = data.constructor === Array ? true : false;
  var firstRow = data[0];
  let wipHeaderId = firstRow["lastInsertId"];
  let invItemMasterId = firstRow["invItemMasterId"];
  let invOrgId = firstRow["invOrgId"];


  if (wipHeaderId) {
    let insertSql =
      " INSERT INTO wip_wd_line " +
      "    ( wip_wd_header_id, operation_sequence, standard_operation_id,  department_id, " +
      "      operation_description, count_point_cb,  auto_charge_cb, backflush_cb," +
      "      yield,  minimum_transfer_quantity, bom_routing_line_id" +
      "  ) " +
      "  SELECT '" +
      wipHeaderId +
      "' , operation_sequence, standard_operation_id,  department_id," +
      "  operation_description, count_point_cb,  auto_charge_cb, backflush_cb," +
      "  yield,  minimum_transfer_quantity, bom_routing_line_id" +
      "  from bom_routing_line where bom_routing_header_id in (" +
      "  SELECT bom_routing_header_id from inoerp.wip_wd_header where wip_wd_header_id = '" +
      wipHeaderId +
      "'" +
      "  ) ";


    request = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    sqlInsert(request);

    let allLinesSql =
      "SELECT * from wip_wd_line where wip_wd_header_id = '" +
      wipHeaderId +
      "'";
    request = {
      sql: allLinesSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let response = sqlSelect(request);

    let lineData = response["data"];
    isArray = lineData.constructor === Array ? true : false;

    let itemCopySeq = 0;
    if (firstRow["copyBomItem"] == "LAST_OPERATION") {
      itemCopySeq = lineData.length - 1;
    } else if (firstRow["copyBomItem"] == "DONT_COPY") {
      itemCopySeq = -1;
    }

    consoleLog("wdHeaderAfterPost 0 firstRow : " + JSON.stringify(firstRow));

    consoleLog("wdHeaderAfterPost 1 lineData : " + JSON.stringify(lineData));

    if (isArray) {
      for (let i = 0; i < lineData.length; i++) {
        const line = lineData[i];
        consoleLog("wdHeaderAfterPost 2 i : " + i + "itemCopySeq: " + itemCopySeq + " invItemMasterId: " + invItemMasterId + " invOrgId: " + invOrgId);
        let wipWdLineId = line["wipWdLineId"];
        insertOperationResources(wipWdLineId);
        if (i == itemCopySeq && invItemMasterId && invOrgId) {
          insertOperationMaterials(wipWdLineId, invItemMasterId, invOrgId);
        }
      }
    }
  }

  //  consoleLog("New wd header Id is  : " + firstRow["lastInsertId"]);
  // printNestedObject(data);
}

function insertOperationResources(wipWdLineId) {
  consoleLog("wdHeaderAfterPost 3  insertOperationResources wipWdLineId: " + wipWdLineId);
  let insertSql =
    " INSERT INTO wip_wd_line_res " +
    " (wip_wd_line_id, resource_sequence, charge_basis, resource_id, resource_usage, " +
    " resource_scheduled_cb, charge_type, standard_rate_cb) " +
    "  SELECT '" +
    wipWdLineId +
    "', resource_sequence, charge_basis, resource_id, resource_usage, resource_scheduled_cb, " +
    "   charge_type, standard_rate_cb " +
    "   FROM bom_routing_detail " +
    " WHERE bom_routing_line_id IN (SELECT bom_routing_line_id" +
    " FROM inoerp.wip_wd_line WHERE wip_wd_line_id = '" +
    wipWdLineId +
    "'); ";
  request = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  sqlInsert(request);
}

function insertOperationMaterials(wipWdLineId, invItemMasterId, invOrgId) {
  consoleLog("wdHeaderAfterPost 4  insertOperationMaterials wipWdLineId: " + wipWdLineId + " : invItemMasterId: " + invItemMasterId + " : invOrgId: " + invOrgId);

  let insertSql =
    " INSERT INTO wip_wd_line_mat  (wip_wd_line_id,  item_sequence,component_item_id_m,component_revision,usage_basis,usage_quantity, " +
    " auto_request_material_cb,yield, wip_supply_type,supply_sub_inventory,supply_locator_id)  " +
    " SELECT '" +
    wipWdLineId +
    "', item_sequence,component_item_id_m,component_revision,usage_basis,usage_quantity,   " +
    " auto_request_material_cb,yield, wip_supply_type,supply_sub_inventory,supply_locator_id   " +
    " FROM bom_line  WHERE bom_header_id IN ( " +
    " SELECT bom_header_id FROM inoerp.bom_header WHERE inv_item_master_id = '" +
    invItemMasterId +
    "' and inv_org_id = '" +
    invOrgId +
    "') ;";

  request = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  sqlInsert(request);
}

