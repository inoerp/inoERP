function beforePost(inputData) {
  let data = inputData["data"];
  let fromWipWoLineId = data["fromWipWoLineId"];
  let toWipWoLineId = data["toWipWoLineId"];
  let fromOperationSequence = data["fromOperationSequence"];
  let toOperationSequence = data["toOperationSequence"];
  let fromOperationStep = data["fromOperationStep"];
  let toOperationStep = data["toOperationStep"];
  let moveQuantity = data["moveQuantity"];

  consoleLog("data in beforePost : " + JSON.stringify(data));
  consoleLog("fromWipWoLineId : " + fromWipWoLineId + " toWipWoLineId : " + toWipWoLineId + " fromOperationSequence : " + fromOperationSequence + " toOperationSequence : " + toOperationSequence + " fromOperationStep : " + fromOperationStep + " toOperationStep : " + toOperationStep + " moveQuantity : " + moveQuantity);

  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Move transaction request is successfully submitted",
  };

  let sql =
    " select inoerp.wipOperationPullTransactions(" +
    fromWipWoLineId +
    "," +
    toWipWoLineId +
    "," +
    fromOperationSequence +
    "," +
    toOperationSequence +
    ",'" +
    fromOperationStep +
    "','" +
    toOperationStep +
    "'," +
    moveQuantity +
    ")";

  request = {
    sql: sql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  retDataMap["rd_proceed_message"] = JSON.stringify(response);
  return retDataMap;
}
