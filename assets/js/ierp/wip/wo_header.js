function afterPost(inputData) {
  //return inputData["data"];
  if (inputData != null) {
  } else {
    return inputData;
  }

  var data = inputData["data"];
  var isArray = data.constructor === Array ? true : false;
  var firstRow = data[0];
  let wipWoHeaderId = firstRow["lastInsertId"];
  let wipWdHeaderId = firstRow["wipWdHeaderId"];
  let quantity = firstRow["quantity"];
  if (!quantity) {
    quantity = 1;
  }
  consoleLog("firstRow : " + JSON.stringify(firstRow));

  if (wipWoHeaderId) {
    completeWorkOrderCreation(wipWoHeaderId);
  }

  //  consoleLog("New wd header Id is  : " + firstRow["lastInsertId"]);
  // printNestedObject(data);
}

function completeWorkOrderCreation(wipWoHeaderId) {
  // let insertSql =
  //   " INSERT INTO wip_wo_line " +
  //   "    ( wip_wo_header_id, wip_wd_line_id, operation_sequence, standard_operation_id,  department_id, " +
  //   "      operation_description, count_point_cb,  auto_charge_cb, backflush_cb," +
  //   "      yield,  minimum_transfer_quantity" +
  //   "  ) " +
  //   "  SELECT '" +
  //   wipWoHeaderId +
  //   "' , wip_wd_line_id, operation_sequence, standard_operation_id,  department_id," +
  //   "  operation_description, count_point_cb,  auto_charge_cb, backflush_cb," +
  //   "  yield,  minimum_transfer_quantity " +
  //   "  from wip_wd_line where wip_wd_header_id   = '" +
  //   wipWdHeaderId +
  //   "'" +
  //   "  ";

  let insertSql =
    " INSERT INTO wip_wo_line " +
    "    ( wip_wo_header_id, wip_wd_line_id, operation_sequence, standard_operation_id,  department_id, " +
    "      operation_description, count_point_cb,  auto_charge_cb, backflush_cb," +
    "      yield,  minimum_transfer_quantity" +
    "  ) " +
    "  SELECT '" +
    wipWoHeaderId +
    "' , wip_wd_line_id, operation_sequence, standard_operation_id,  department_id," +
    "  operation_description, count_point_cb,  auto_charge_cb, backflush_cb," +
    "  yield,  minimum_transfer_quantity " +
    "  from wip_wd_line where wip_wd_header_id   IN (SELECT wip_wd_header_id from wip_wo_header where  wip_wo_header_id = '" +
    wipWoHeaderId +
    "' ) ";

  request = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  sqlInsert(request);

  let allLinesSql =
    "SELECT * from wip_wo_line where wip_wo_header_id = '" +
    wipWoHeaderId +
    "'";
  request = {
    sql: allLinesSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let response = sqlSelect(request);

  let lineData = response["data"];
  isArray = lineData.constructor === Array ? true : false;

  if (isArray) {
    for (let i = 0; i < lineData.length; i++) {
      const line = lineData[i];
      let wipWdLineId = line["wipWdLineId"];
      let wipWoLineId = line["wipWoLineId"];
      insertOperationResources(wipWoLineId, wipWdLineId, quantity);
      insertOperationMaterials(wipWoLineId, wipWdLineId, quantity);
    }
  }
}

function insertOperationResources(wipWoLineId, wipWdLineId, quantity) {
  let insertSql =
    " INSERT INTO wip_wo_line_res " +
    " (wip_wo_line_id, resource_sequence, charge_basis, resource_id, resource_usage, " +
    " resource_scheduled_cb, required_quantity, charge_type, standard_rate_cb) " +
    "  SELECT '" +
    wipWoLineId +
    "', resource_sequence, charge_basis, resource_id, resource_usage, resource_scheduled_cb, " +
    "  resource_usage *(" +
    quantity +
    "), charge_type, standard_rate_cb " +
    "   FROM wip_wd_line_res " +
    " WHERE wip_wd_line_id = '" +
    wipWdLineId +
    "'  ; ";
  request = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  sqlInsert(request);
}

function insertOperationMaterials(wipWoLineId, wipWdLineId, quantity) {
  let insertSql =
    " INSERT INTO wip_wo_line_mat " +
    " (wip_wo_line_id, item_sequence,component_item_id_m,component_revision,usage_basis,usage_quantity, required_quantity , " +
    " auto_request_material_cb,yield, wip_supply_type,supply_sub_inventory,supply_locator_id) " +
    "  SELECT '" +
    wipWoLineId +
    "', item_sequence,component_item_id_m,component_revision,usage_basis,usage_quantity, usage_quantity *(" +
    quantity +
    "), " +
    " auto_request_material_cb,yield, wip_supply_type,supply_sub_inventory,supply_locator_id " +
    "   FROM wip_wd_line_mat " +
    " WHERE wip_wd_line_id = '" +
    wipWdLineId +
    "'  ; ";
  request = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  sqlInsert(request);
}

function afterGet(inputData) {
  //return inputData["data"];
  if (inputData != null) {
  } else {
    return inputData;
  }
  var pathParamValues = inputData["pathParamValues"];
  if (pathParamValues != null) {
    //  consoleLog("pathParamValues keys : " + Object.keys(pathParamValues));
    // printNestedObject(pathParamValues);
  } else {
    return inputData["data"];
  }

  var data = inputData["data"];
  return data;
  var isArray = data.constructor === Array ? true : false;
  //consoleLog("data in afterGet isArray : " + isArray);
  if (isArray) {
    var retData = [];
    for (let index = 0; index < data.length; index++) {
      var element = data[index];
      updateAfterGetData(element);
      retData.push(element);
    }
    return retData;
  } else {
    updateAfterGetData(data);
    return data;
  }
}

function updateAfterGetData(data) {
  var docStatus = data["docStatus"];
  var readOnly = true;
  var entityObjectReadOnly = false;

  if (!docStatus) {
    return data;
  } else if (docStatus == "DRAFT") {
    readOnly = false;
  } else if (docStatus == "CANCELLED" || docStatus == "CLOSED") {
    entityObjectReadOnly = true;
  }
  var entityObject = { readonly: entityObjectReadOnly };
  var dataDefinition = { entityObject: entityObject };
  let allKeys = Object.keys(data);
  for (let i = 0; i < allKeys.length; i++) {
    const k = allKeys[i];
    if (k != null) {
      var dd = {};
      if (k == "description" || k == "orderSourceType") {
        dd["readonly"] = false;
      } else {
        dd["readonly"] = readOnly;
      }
      dataDefinition[k] = dd;
    }
  }
  data["dataDefinition"] = dataDefinition;
  return data;
}

function beforePatch(inputData) {
  var data = inputData["data"];
  var action = data["action"];
  var entityPath = data["entityPath"];
  var status = null;
  if (action == "cancel") {
    status = "CANCELLED";
  } else if (action == "confirm") {
    status = "CONFIRMED";
  } else if (action == "close") {
    status = "CLOSED";
  } else if (action == "reopen") {
    status = "DRAFT";
  }

  if (action == "update_quantities") {
    updateQuantities(data);
  } else {
    if (entityPath == "WipWoLineEv") {
      beforePatchLine(
        status,
        "wip_wo_line",
        "wip_wo_line_id",
        data["wipWoLineId"]
      );
    } else {
      beforePatchHeader(
        status,
        "wip_wo_header",
        "wip_wo_header_id",
        data["wipWoHeaderId"],
        "wip_wo_line"
      );
      if (action == "confirm") {
        confirmWorkOrder(data);
      }
    }
  }
}

function confirmWorkOrder(data) {
  var wipWoHeaderId = data["wipWoHeaderId"];

  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Confirmation request is successfully submitted",
  };

  let sql = " select inoerp.wipUpdateOpsQuantities(" + wipWoHeaderId + ")";

  request = {
    sql: sql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  retDataMap["rd_proceed_message"] = JSON.stringify(response);
  return retDataMap;
}

function updateQuantities(data) {
  var wipWoHeaderId = data["wipWoHeaderId"];
  consoleLog("In updateQuantities wipWoHeaderId " + wipWoHeaderId);

  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Quantity update request is successfully submitted",
  };

  let sql = " select inoerp.wipUpdateWoQuantities(" + wipWoHeaderId + ")";

  request = {
    sql: sql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  retDataMap["rd_proceed_message"] = JSON.stringify(response);
  return retDataMap;
}

function beforePatchHeader(
  status,
  tableName,
  primaryKeyName,
  primaryKeyValue,
  lineTableName
) {
  if (status !== null) {
    request = {
      sql:
        "UPDATE " +
        tableName +
        " SET doc_status = '" +
        status +
        "' WHERE " +
        primaryKeyName +
        " = '" +
        primaryKeyValue +
        "' ",
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let response = sqlUpdate(request);
    if (lineTableName) {
      request = {
        sql:
          "UPDATE " +
          lineTableName +
          " SET doc_status = '" +
          status +
          "' WHERE " +
          primaryKeyName +
          " = '" +
          primaryKeyValue +
          "' ",
        dbType: "MySQL",
        connName: "Inoerp",
      };
      response = sqlUpdate(request);
    }
  }
}

function beforePatchLine(status, tableName, primaryKeyName, primaryKeyValue) {
  if (status !== null) {
    request = {
      sql:
        "UPDATE " +
        tableName +
        " SET doc_status = '" +
        status +
        "' WHERE " +
        primaryKeyName +
        " = '" +
        primaryKeyValue +
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

function importWorkOrder(inputData) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let request = inputData["request"];
  let data = inputData["data"];
  let action = data["action"];

  if (action == "wip_import_wo" || action == "wip_import_wos") {
  } else {
    return data;
  }

  consoleLog("\n\nIn beforePatch importWorkOrder " + JSON.stringify(data));

  // Import Planned Work Orders
  let refreshResult = 0;
  if (action == "wip_import_wo") {
    return completeWorkOrderImport(data);
  } else if (action == "wip_import_wos") {
    ImportAllAvailableWorkOrders(data);
  }

  retDataMap["rd_proceed_message"] = "Release is successfully completed";

  return retDataMap;
}

function completeWorkOrderImport(data) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let invOrgId = data["formData"]["invOrgId"];
  let wipWoInterfaceId = data["wipWoInterfaceId"];
  if (wipWoInterfaceId != undefined && wipWoInterfaceId > 0) {
    wipWoInterfaceId = data["formData"]["wipWoInterfaceId"];
  }

  if (wipWoInterfaceId != undefined && wipWoInterfaceId > 0) {
    let insertSql =
      " INSERT INTO wip_wo_header ( src_entity_name, src_entity_id ,wip_wd_header_id,inv_item_master_id,wo_number,description,inv_org_id," +
      " wip_accounting_group_id,wo_type,doc_status,start_date,completion_date,quantity,nettable_quantity,wip_wo_interface_id,completion_sub_inventory,completion_locator, " +
      " schedule_group,build_sequence,line,scheduling_priority,gl_ac_profile_header_id,wo_cost_type) " +
      " SELECT src_entity_name, src_entity_id ,wip_wd_header_id,inv_item_master_id,wo_number,description,inv_org_id, " +
      " wip_accounting_group_id,wo_type,doc_status,start_date,completion_date,quantity,nettable_quantity,wip_wo_interface_id,completion_sub_inventory,completion_locator, " +
      " schedule_group,build_sequence,line,scheduling_priority,gl_ac_profile_header_id,wo_cost_type  " +
      " FROM wip_wo_interface WHERE  (doc_status IN ('DRAFT', 'CONFIRMED') OR doc_status is null ) AND wip_wo_interface_id = '" +
      wipWoInterfaceId +
      "' ";
    headerInsertRequest = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let headerResponse = sqlInsert(headerInsertRequest);
    let headerResponseData = headerResponse["data"];
    let headerId = headerResponseData[0]["lastInsertId"];
    if (headerId > 0) {
      completeWorkOrderCreation(headerId);
    }
  } else {
    retDataMap["rd_proceed_message"] =
      "Failed to import work orders as wipWoInterfaceId is not defined";
  }
}

//find all work orders that are not yet imported and store the wipWoInterfaceId in a list
//for each wipWoInterfaceId in the list, import the work order
function ImportAllAvailableWorkOrders(data) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let invOrgId = data["formData"]["invOrgId"];
  let wipWoInterfaceId = data["wipWoInterfaceId"];
  if (wipWoInterfaceId != undefined && wipWoInterfaceId > 0) {
    wipWoInterfaceId = data["formData"]["wipWoInterfaceId"];
  }

  let selectSql =
    "SELECT wip_wo_interface_id FROM wip_wo_interface WHERE (doc_status IN ('DRAFT', 'CONFIRMED') OR doc_status is null ) AND inv_org_id = '" +
    invOrgId +
    "' ";
  let selectRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let selectResponse = sqlSelect(selectRequest);
  let selectResponseData = selectResponse["data"];

  if (selectResponseData.length > 0) {
  } else {
    retDataMap["rd_proceed_message"] = "No work orders to import";
    return retDataMap;
  }
  for (let i = 0; i < selectResponseData.length; i++) {
    let wipWoInterfaceId = selectResponseData[i]["wipWoInterfaceId"];
    if (wipWoInterfaceId != undefined && wipWoInterfaceId > 0) {
      let insertSql =
        " INSERT INTO wip_wo_header ( src_entity_name, src_entity_id ,wip_wd_header_id,inv_item_master_id,wo_number,description,inv_org_id," +
        " wip_accounting_group_id,wo_type,doc_status,start_date,completion_date,quantity,nettable_quantity,wip_wo_interface_id,completion_sub_inventory,completion_locator, " +
        " schedule_group,build_sequence,line,scheduling_priority,gl_ac_profile_header_id,wo_cost_type) " +
        " SELECT src_entity_name, src_entity_id ,wip_wd_header_id,inv_item_master_id,wo_number,description,inv_org_id, " +
        " wip_accounting_group_id,wo_type,doc_status,start_date,completion_date,quantity,nettable_quantity,wip_wo_interface_id,completion_sub_inventory,completion_locator, " +
        " schedule_group,build_sequence,line,scheduling_priority,gl_ac_profile_header_id,wo_cost_type  " +
        " FROM wip_wo_interface WHERE  (doc_status IN ('DRAFT', 'CONFIRMED') OR doc_status is null ) AND wip_wo_interface_id = '" +
        wipWoInterfaceId +
        "' ";
      headerInsertRequest = {
        sql: insertSql,
        dbType: "MySQL",
        connName: "Inoerp",
      };
      let headerResponse = sqlInsert(headerInsertRequest);
      let headerResponseData = headerResponse["data"];
      let headerId = headerResponseData[0]["lastInsertId"];
      if (headerId > 0) {
        completeWorkOrderCreation(headerId);
      }
    }
  }
  retDataMap["rd_proceed_message"] =
    "No of work orders imported: " + selectResponseData.length;
  return retDataMap;
}
