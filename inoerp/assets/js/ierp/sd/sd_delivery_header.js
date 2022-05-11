function beforePatch(inputData) {
  var data = inputData["data"];
  var action = data["action"];
  var entityPath = data["entityPath"];

  var status = getStatusFromAction(action);

  consoleLog("InsideJsTesting beforePatch: status 1" + status);
  consoleLog("InsideJsTesting beforePatch: action 2" + action);

  if (action == "ship_confirm") {
    if(data){
      return completeShipment(data);
    }
  } else {
    consoleLog("InsideJsTesting beforePatch: entityPath 3" + entityPath);
    if (entityPath == "SdDeliveryHeader") {
      beforePatchDeliveryHeader(status, data);
    } else if (
      entityPath == "SdDeliveryLineEv" ||
      entityPath == "SdDeliveryLine"
    ) {
      consoleLog("InsideJsTesting beforePatch: entityPath 4" + entityPath);

      beforePatchLine(status, data);
    }
  }
}

function beforePatchDeliveryHeader(status, data) {
  if (status !== null) {
    request = {
      sql:
        "UPDATE sd_delivery_header SET doc_status = '" +
        status +
        "' WHERE sd_delivery_header_id = '" +
        data["sdDeliveryHeaderId"] +
        "' ",
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let response = sqlUpdate(request);
    request = {
      sql:
        "UPDATE sd_delivery_line SET doc_status = '" +
        status +
        "' WHERE sd_delivery_header_id = '" +
        data["sdDeliveryHeaderId"] +
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

function beforePatchLine(status, data) {
  if (status !== null) {
    request = {
      sql:
        "UPDATE sd_delivery_line SET doc_status = '" +
        status +
        "' WHERE sd_delivery_line_id = '" +
        data["sdDeliveryLineId"] +
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

function completeShipment(data) {
  let insertSql =
  " INSERT INTO inv_transaction " +
  " (inv_transaction_code,inv_org_code,ledger_id,inv_item_master_id,lot_number_id,document_type,document_id, sd_so_detail_id, "+
  " oh_impact_type,uom_code,quantity,unit_cost,from_org_code,from_sub_inventory,from_locator_id) "+
    " SELECT 'SO_SHIPPING',vv_org_code,null,vv_inv_item_master_id,null,'SdSoDetail', sd_so_detail_id, sd_so_detail_id," +
    " 'NEGATIVE', vv_uom_code,shipping_quantity,null,vv_org_code,shipping_sub_inventory,shipping_locator_id " +
    " FROM sd_delivery_line_ev " +
    " WHERE doc_status ='OPEN' AND  sd_delivery_header_id = '" +
    data["sdDeliveryHeaderId"] +
    "' ";
    request = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    response = sqlInsert(request);
    if (response != null) {
      responseData = response["data"];
      consoleLog(
        "InsideJsTesting completeShipment: responseData 1" + responseData
      );
      printNestedObject(responseData);
      beforePatchDeliveryHeader("CLOSED", data);
    }
  }
