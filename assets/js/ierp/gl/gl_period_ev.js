function beforePatch(inputData) {
  consoleLog("In GlPeriodEv beforePatch 1 ");
  let data = inputData["data"];
  let action = data["action"];
  let formData = data["formData"];

  return changePeriodStatus(formData, action);
}

function changePeriodStatus(data, action) {

  consoleLog("In GlPeriodEv changePeriodStatus 1 data is " + JSON.stringify(data));

  let glLedgerId = data["glLedgerId"];
  let glCalendarLineId = data["vvGlCalendarLineId"];
  
  consoleLog(
    "In changePeriodStatus glLedgerId " +
      glLedgerId +
      " glCalendarLineId " +
      glCalendarLineId
  );

  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let sql = "";

  if (action == "close") {
    sql =
      " select inoerp.glClosePeriod(" +
      glLedgerId +
      "," +
      glCalendarLineId +
      ")";
  } else if (action == "open") {
    sql =
      " select inoerp.glOpenPeriod(" +
      glLedgerId +
      "," +
      glCalendarLineId +
      ")";
  } else {
    retDataMap["rd_proceed_message"] = "Action is not supported";
    return retDataMap;
  }

  request = {
    sql: sql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  retDataMap["rd_proceed_message"] = JSON.stringify(response);
  return retDataMap;
}
