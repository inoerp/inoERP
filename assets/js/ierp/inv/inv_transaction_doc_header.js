function afterPatch(inputData) {
  consoleLog("In afterPatch 1 ");
  var data = inputData["data"];
  var firstRow = data[0];
  var invTransactionId = firstRow["invTransactionId"];
  var invTransactionCode = firstRow["invTransactionCode"];
  var serialControl = firstRow["serialControl"];
  var retDataMap;

  // consoleLog(
  //   "\n\n\nIn afterPatch 2 invTransactionId " +
  //     invTransactionId +
  //     "\n\n" +
  //     JSON.stringify(firstRow)
  // );
  if (invTransactionCode == "SUBINVENTORY_TRANSFER") {
    completeSubInvTransfer(invTransactionId, serialControl);

    serialControl = firstRow["serialControl"];
  retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Sub Inventory request is successfully submitted",
  };
  }

  return retDataMap;
}

function completeSubInvTransfer(invTransactionId, serialControl) {
  var retMessage = "";
  let insertRequest = {
    sql:
      " INSERT INTO inv_transaction (inv_transaction_code, src_entity_name, src_entity_id,  inv_org_code, item_number, revision_name, inv_item_master_id, uom_code, quantity, lot_number_id, " +
      " from_org_code, from_sub_inventory, from_locator_id, inv_transaction_doc_line_id, lot_control, serial_control) " +
      " SELECT 'SUBINVENTORY_TRANSFER_ISSUE', src_entity_name, src_entity_id,  inv_org_code, item_number, revision_name, inv_item_master_id, uom_code, quantity, lot_number_id, " +
      " from_org_code, from_sub_inventory, from_locator_id, inv_transaction_doc_line_id, lot_control, serial_control " +
      " FROM inv_transaction where inv_transaction_id = "+invTransactionId+"; ",
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlInsert(insertRequest);
  let responseData = response["data"];
  let firstRow = responseData[0];
  var newInvTransactionId = firstRow["lastInsertId"];
  
  if(serialControl == "PRE_DEFINED"){
    completeSerialTransaction(invTransactionId,newInvTransactionId);
  }

  insertRequest = {
    sql:
      " INSERT INTO inv_transaction (inv_transaction_code, src_entity_name, src_entity_id,  inv_org_code, item_number, revision_name, inv_item_master_id, uom_code, quantity, lot_number_id, " +
      " to_org_code, to_sub_inventory, to_locator_id, inv_transaction_doc_line_id, lot_control, serial_control) " +
      " SELECT 'SUBINVENTORY_TRANSFER_RECEIPT', src_entity_name, src_entity_id,  inv_org_code, item_number, revision_name, inv_item_master_id, uom_code, quantity, lot_number_id, " +
      " to_org_code, to_sub_inventory, to_locator_id, inv_transaction_doc_line_id, lot_control, serial_control " +
      " FROM inv_transaction where inv_transaction_id = "+invTransactionId+"; ",
    dbType: "MySQL",
    connName: "Inoerp",
  };

  response = sqlInsert(insertRequest);
  responseData = response["data"];
  firstRow = responseData[0];
  newInvTransactionId = firstRow["lastInsertId"];

  if(serialControl == "PRE_DEFINED"){
    completeSerialTransaction(invTransactionId,newInvTransactionId);
  }

}

function completeSerialTransaction(invTransactionId,newInvTransactionId ){
var retMessage = "";
  insertRequest = {
    sql:
      " INSERT INTO inv_serial_transaction (src_entity_name, src_entity_id , inv_serial_transaction_doc_id, " +
      " inv_transaction_id, inv_serial_number_id) " +
      " SELECT src_entity_name, src_entity_id , inv_serial_transaction_doc_id, " +
      " "+newInvTransactionId+", inv_serial_number_id " +
      " FROM inv_serial_transaction where inv_transaction_id = "+invTransactionId+"; ",
    dbType: "MySQL",
    connName: "Inoerp",
  };

  response = sqlInsert(insertRequest);
  
    if (response["data"][0]["message"]) {
    retMessage += "\n" + response["data"][0]["message"];
  } else {
    retMessage += "\n" + response["data"];
  }
}