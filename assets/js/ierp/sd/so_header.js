// function afterGet(inputData) {
//   return validationForAfterGet(inputData);
// }



function beforePatch(inputData) {
  var data = inputData["data"];
  var action = data["action"];
  var entityPath = data["entityPath"];
  // var status = null;
  // if (action == "cancel") {
  //   status = "CANCELLED";
  // } else if (action == "confirm") {
  //   status = "CONFIRMED";
  // } else if (action == "close") {
  //   status = "CLOSED";
  // } else if (action == "reopen") {
  //   status = "DRAFT";
  // }

  var status = getStatusFromAction(action);
 if (entityPath == "SdSoLineEv") {
    beforePatchLine(status, data);
  } else {
    beforePatchHeader(status, data);
  }
}


function beforePatchHeader(status, data) {
  if (status !== null) {
    request = {
      sql:
        "UPDATE sd_so_header SET doc_status = '" +
        status +
        "' WHERE sd_so_header_id = '" +
        data["sdSoHeaderId"] +
        "' ",
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let response = sqlUpdate(request);
    request = {
      sql:
        "UPDATE sd_so_line SET doc_status = '" +
        status +
        "' WHERE sd_so_header_id = '" +
        data["sdSoHeaderId"] +
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
        "UPDATE sd_so_line SET doc_status = '" +
        status +
        "' WHERE sd_so_line_id = '" +
        data["sdSoLineId"] +
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

function cancel(inputData) {
  //  printNestedObject(inputData);
  var data = inputData["data"];
  request = {
    sql:
      "UPDATE sd_so_header SET description = 'CANCELLED' WHERE sd_so_header_id = '" +
      data["sdSoHeaderId"] +
      "' ",
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let response = sqlUpdate(request);
  request = {
    sql:
      "UPDATE sd_so_line SET doc_status = 'CANCELLED' WHERE sd_so_header_id = '" +
      data["sdSoHeaderId"] +
      "' ",
    dbType: "MySQL",
    connName: "Inoerp",
  };
  response = sqlUpdate(request);
  if (response != null) {
    //      printNestedObject(response);
  }
}

function updateTransactionDetails(){
  let formData = data["formData"];
  let items = formData["items"];
  let menuPath = data["menuPath"];
  let pathCode = menuPath["path_code"];
  var dataMap;
  if (typeof items != "undefined" && items.constructor === Array) {
    dataMap = items[0];
    dataMap["invTransactionCode"] = pathCode;
    dataMap["description"] = pathCode;
    formData["items"] = items;
  } else {
    dataMap = items;
    dataMap["invTransactionCode"] = pathCode;
    dataMap["description"] = pathCode;
    formData["items"] = items;
  }
   data["formData"] = formData;
   return data;
}
updateTransactionDetails();


function validateSerialNumbers() {
  let formData = data["formData"];
  let items = formData["items"];
  let childForms = formData["childForms"];
  var dataMap;
  if (typeof items != "undefined" && items.constructor === Array) {
    dataMap = items[0];
  } else {
    dataMap = items;
  }

  if(dataMap["lotControl"]){
  //check lot numbers
  let lotNumberForm = childForms["InvLotTransaction"];
  let changedData = lotNumberForm["changedData"];
  }


  return "Serial COntrol : " + dataMap["serialControl"] + " & Lost Control :" + dataMap["lotControl"];
}
validateSerialNumbers();

function simpleTest() {
  let i = 10;
  let j = 20;
  var k = i + j;
  if (k > 80) return true;
  else return false;
}
simpleTest();
console.log("simpleTest : " + simpleTest());
