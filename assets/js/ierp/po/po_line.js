function afterGet(inputData) {
  return validationForAfterGet(inputData);
}

function afterPost(inputData) {
  var data = inputData["data"];
  var action = data["action"];
  var entityPath = data["entityPath"];
  let firstRow = data[0];
  let lastInsertId = firstRow["lastInsertId"];
  consoleLog("\n\afterPost in js printNestedObject lastInsertId \n\n", lastInsertId);
  createPoDetails(lastInsertId);
  printNestedObject(data)
}

function afterPatch(inputData) {
  var data = inputData["data"];
  var action = data["action"];
  var entityPath = data["entityPath"];
  consoleLog("\n\nafterPatch in js printNestedObject \n\n", data);
  printNestedObject(data)
}

function createPoDetails(lastInsertId) {
  request = {
    sql:
      " INSERT INTO  po_detail (po_detail_id, po_line_id, po_header_id, shipment_number,  uom_code,  quantity) " +
      " VALUES ( NULL, "+lastInsertId+", (SELECT po_header_id from po_line where po_line_id = '"+lastInsertId+"' LIMIT 1), 1, " +
      " (SELECT uom_code from po_line where po_line_id = '"+lastInsertId+"' LIMIT 1), " +
      " (SELECT line_quantity from po_line where po_line_id = '"+lastInsertId+"' LIMIT 1) " +
      "  )      ",
    dbType: "MySQL",
    connName: "Inoerp",
  };
  sqlInsert(request);
}


