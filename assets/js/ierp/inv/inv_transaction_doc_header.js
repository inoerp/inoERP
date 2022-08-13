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

function beforePatch(inputData) {
  consoleLog("In beforePatch 1 ");
  var data = inputData["data"];
  var action = data["action"];

  var retDataMap = {
    rd_proceed_status: true,
    rd_data_contains_item: true,
    rd_proceed_message: data,
  };

  if (action == "create_accounting") {
    return createAccounting(data, "final");
  } else if (action == "create_draft_accounting") {
    return createAccounting(data, "draft");
  } else if (
    action == "delete_draft_accounting" ||
    action == "confirm_draft_accounting"
  ) {
    return completeOtherAction(data, action);
  } else if (
    action == "line_create_inv_transaction_using_inv_transaction_doc_line_ev"
  ) {
    let validationStatus = allowTransaction(data);

    if (validationStatus["noOfInvalidRecords"] > 0) {
      retDataMap = {
        rd_proceed_status: false,
        rd_proceed_message:
          "You can create transactions only for validated documents. No of invalid records " +
          " " +
          validationStatus["noOfInvalidRecords"],
      };
    } else if (validationStatus["noOfValidRecords"] > 0) {
    } else {
      retDataMap = {
        rd_proceed_status: false,
        rd_proceed_message:
          "No valid records found. You can create transactions only for validated documents.",
      };
    }
    return retDataMap;
  } else if (action == "validate_transaction") {
    return validateTransaction(data);
  }else {
    return data;
  }

  return retDataMap;
}

/*Find all transaction lines - if all transaction lines have validated status then return true else return false
TODO trigger on transaction table to update the transaction doc line status to closed */
function allowTransaction(data) {
  let invTransactionDocHeaderId = data["invTransactionDocHeaderId"];
  let noOfValidRecords = 0;
  let noOfInvalidRecords = 0;
  let selectSql =
    " SELECT doc_status FROM inoerp.inv_transaction_doc_line where inv_transaction_doc_header_id = '" +
    invTransactionDocHeaderId +
    "'   ";
  let selectRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let selectResponse = sqlSelect(selectRequest);
  let selectData = selectResponse["data"];

  for (let index = 0; index < selectData.length; index++) {
    const element = selectData[index];
    if (element["docStatus"] == "validated") {
      noOfValidRecords++;
    } else {
      noOfInvalidRecords++;
    }
  }

  return {
    noOfValidRecords: noOfValidRecords,
    noOfInvalidRecords: noOfInvalidRecords,
  };
}

/*Find all transaction */
function validateTransaction(data) {
  retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "All transaction lines have been validated.",
  };

  let invTransactionDocHeaderId = data["invTransactionDocHeaderId"];
  let selectSql =
    " SELECT itt.allow_negative_balance_cb, line.* \
    FROM inoerp.inv_transaction_doc_line_ev line,  \
    inoerp.inv_transaction_type itt \
    WHERE itt.inv_transaction_code = line.vv_transaction_type \
    and inv_transaction_doc_header_id = '" +
    invTransactionDocHeaderId +
    "'   ";
  let selectRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let selectResponse = sqlSelect(selectRequest);
  let selectData = selectResponse["data"];

  let invalidMessages = {};

  for (let index = 0; index < selectData.length; index++) {
    const element = selectData[index];
    let transactionType = element["vvTransactionType"];
    let invTransactionDocLineId = element["invTransactionDocLineId"];
    let validationMessage1 = "";
    let validationMessage2 = "";
    let validationMessage3 = "";
    switch (transactionType) {
      case "PO_RECEIPT":
      case "MISCELLANEOUS_RECEIPT":
      case "PRJ_SHIPPING_RETURN":
      case "INTER_ORG_TRANSFER_RECEIPT":
      case "SO_REVERSE_PICKING":
      case "SO_REVERSE_SHIPPING":
      case "SO_RETURN":
      case "WIP_MATERIAL_RETURN":
      case "WIP_NEGATIVE_ISSUE":
      case "WIP_WOL_COMPLETION":
      case "WIP_ASSEMBLY_COMPLETION":
        validationMessage1 = checkToSubInv(element);
        break;

      case "PO_DELIVERY":
      case "INTER_ORG_TRANSFER_DIRECT":
      case "SUBINVENTORY_TRANSFER":
      case "PRJ_MATERIAL_ISSUE":
      case "PRJ_MATERIAL_RETURN":
        validationMessage1 = checkToSubInv(element);
        validationMessage2 = checkStockAtFromLocation(element);
        break;

      case "PO_REVERSE_RECEIPT":
      case "PO_RETURN":
      case "MISCELLANEOUS_ISSUE":
      case "INTER_ORG_TRANSFER_INTRANSIT":
      case "SO_PICKING":
      case "SO_SHIPPING":
      case "WIP_MATERIAL_ISSUE":
      case "WIP_NEGATIVE_RETURN":
      case "WIP_WOL_RETURN":
      case "WIP_ASSEMBLY_RETURN":
      case "PO_RETURN":
      case "PRJ_SHIPPING":
        validationMessage1 = checkStockAtFromLocation(element);
        break;

      default:
        break;
    }

    if (isNotNull(validationMessage1)) {
      invalidMessages[invTransactionDocLineId] = validationMessage1;
    }
    if (isNotNull(validationMessage2)) {
      invalidMessages[invTransactionDocLineId] = validationMessage2;
    }
    if (isNotNull(validationMessage3)) {
      invalidMessages[invTransactionDocLineId] = validationMessage3;
    }
  }

  if (Object.keys(invalidMessages).length > 0) {
    retDataMap = {
      rd_proceed_status: false,
      rd_proceed_message:
        "Some transaction lines failed validation. Please correct the errors and try again. \n" +
        JSON.stringify(invalidMessages),
    };
    return retDataMap;
  }

  //Update the transaction doc line status to validated
  let updateStatus = updateLineStatus(invTransactionDocHeaderId);
  retDataMap["rd_proceed_message"] =
    "Transaction lines have successfully validated." +
    JSON.stringify(updateStatus);

  return retDataMap;
}

function updateLineStatus(invTransactionDocHeaderId) {
  let updateSql =
    " UPDATE inoerp.inv_transaction_doc_line SET doc_status = 'validated' \
  WHERE inv_transaction_doc_header_id = '" +
    invTransactionDocHeaderId +
    "' ";

  let updateSqlRequest = {
    sql: updateSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let updateSqlResponse = sqlUpdate(updateSqlRequest);
  return updateSqlResponse["data"];
}

function checkStockAtFromLocation(element) {
  if (isNotNull(element["fromSubInventory"])) {
  } else {
    return "Missing from sub inventory";
  }

  let quantity = element["quantity"];
  let invItemMasterId = element["invItemMasterId"];
  let fromSubInventory = element["fromSubInventory"];
  let fromLocatorId = element["fromLocatorId"];

  let selectSql =
    " SELECT onhand FROM inoerp.inv_onhand \
     where 1 = 1 \
     and sub_inventory = '" +
    fromSubInventory +
    "' \
     and inv_item_master_id = '" +
    invItemMasterId +
    "'   ";
  if (isNotNull(fromLocatorId)) {
    selectSql += " and locator_id = '" + fromLocatorId + "' ";
  }
  let selectRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let selectResponse = sqlSelect(selectRequest);
  let selectData = selectResponse["data"];

  if (selectData.length == 0) {
    return "Missing onhand for sub inventory " + fromSubInventory;
  }

  let onhand = parseInt(selectData[0]["onhand"]);
  if (onhand < quantity) {
    return "Stock " + onhand + " is less than required quantity " + quantity;
  }
  return "";
}

//toSubInventory should not be null
function checkToSubInv(element) {
  if (!isNotNull(element["toSubInventory"])) {
    return "Missing to sub inventory";
  } else {
    return "";
  }
}

function completeSubInvTransfer(invTransactionId, serialControl) {
  var retMessage = "";
  let insertRequest = {
    sql:
      " INSERT INTO inv_transaction (inv_transaction_code, src_entity_name, src_entity_id,  inv_org_code, item_number, revision_name, inv_item_master_id, uom_code, quantity, lot_number_id, " +
      " from_org_code, from_sub_inventory, from_locator_id, inv_transaction_doc_line_id, lot_control, serial_control) " +
      " SELECT 'SUBINVENTORY_TRANSFER_ISSUE', src_entity_name, src_entity_id,  inv_org_code, item_number, revision_name, inv_item_master_id, uom_code, quantity, lot_number_id, " +
      " from_org_code, from_sub_inventory, from_locator_id, inv_transaction_doc_line_id, lot_control, serial_control " +
      " FROM inv_transaction where inv_transaction_id = " +
      invTransactionId +
      "; ",
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlInsert(insertRequest);
  let responseData = response["data"];
  let firstRow = responseData[0];
  var newInvTransactionId = firstRow["lastInsertId"];

  if (serialControl == "PRE_DEFINED") {
    completeSerialTransaction(invTransactionId, newInvTransactionId);
  }

  insertRequest = {
    sql:
      " INSERT INTO inv_transaction (inv_transaction_code, src_entity_name, src_entity_id,  inv_org_code, item_number, revision_name, inv_item_master_id, uom_code, quantity, lot_number_id, " +
      " to_org_code, to_sub_inventory, to_locator_id, inv_transaction_doc_line_id, lot_control, serial_control) " +
      " SELECT 'SUBINVENTORY_TRANSFER_RECEIPT', src_entity_name, src_entity_id,  inv_org_code, item_number, revision_name, inv_item_master_id, uom_code, quantity, lot_number_id, " +
      " to_org_code, to_sub_inventory, to_locator_id, inv_transaction_doc_line_id, lot_control, serial_control " +
      " FROM inv_transaction where inv_transaction_id = " +
      invTransactionId +
      "; ",
    dbType: "MySQL",
    connName: "Inoerp",
  };

  response = sqlInsert(insertRequest);
  responseData = response["data"];
  firstRow = responseData[0];
  newInvTransactionId = firstRow["lastInsertId"];

  if (serialControl == "PRE_DEFINED") {
    completeSerialTransaction(invTransactionId, newInvTransactionId);
  }
}

function completeSerialTransaction(invTransactionId, newInvTransactionId) {
  var retMessage = "";
  insertRequest = {
    sql:
      " INSERT INTO inv_serial_transaction (src_entity_name, src_entity_id , inv_serial_transaction_doc_id, " +
      " inv_transaction_id, inv_serial_number_id) " +
      " SELECT src_entity_name, src_entity_id , inv_serial_transaction_doc_id, " +
      " " +
      newInvTransactionId +
      ", inv_serial_number_id " +
      " FROM inv_serial_transaction where inv_transaction_id = " +
      invTransactionId +
      "; ",
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

