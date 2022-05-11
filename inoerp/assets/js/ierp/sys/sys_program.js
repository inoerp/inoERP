function beforePatch(inputData) {
  var data = inputData["data"];
  let flatObject = {};
  getFlatObject(data, flatObject);
  let sysProgramHeaderId = flatObject["sysProgramHeaderId"];

  consoleLog("beforePatch sysProgramHeaderId : " + sysProgramHeaderId);
  consoleLog("beforePatch invOrgCode : " + flatObject["invOrgCode"]);
  //printNestedObject(flatObject);

  let programHeaderSql =
    "SELECT * from sys_program_header where sys_program_header_id = '" +
    sysProgramHeaderId +
    "'";
  request = {
    sql: programHeaderSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  let lineData = response["data"];
  isArray = lineData.constructor === Array ? true : false;

  if (isArray) {
    for (let i = 0; i < lineData.length; i++) {
      const line = lineData[i];
      consoleLog("beforePatch lineData : ");
      printNestedObject(line);
      if (i == 0) {
        insertProgramRequestHeader(line, flatObject);
      }
    }
  }
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Request is successfully submitted.",
  };
  return retDataMap;
}

function insertProgramRequestHeader(lineData, params) {
  let scheduleStartTime =
    (scheduleEndTime =
    vvFrequencyUom =
    vvFrequencyValue =
      "");
  if (
    params["scheduleStartTime"] &&
    params["scheduleStartTime"].toLowerCase() != "null"
  ) {
    scheduleStartTime = params["scheduleStartTime"];
    if (
      params["scheduleEndTime"] &&
      params["scheduleEndTime"].toLowerCase() != "null"
    ) {
      scheduleEndTime = params["scheduleEndTime"];
    }
    if (
      params["vvFrequencyUom"] &&
      params["vvFrequencyUom"].toLowerCase() != "null"
    ) {
      vvFrequencyUom = params["vvFrequencyUom"];
    }
    if (
      params["vvFrequencyValue"] &&
      params["vvFrequencyValue"].toLowerCase() != "null"
    ) {
      vvFrequencyValue = params["vvFrequencyValue"];
    }
  }
  let insertSql =
    " INSERT INTO sys_program_request " +
    " ( sys_program_header_id, application_code, js_file_path, js_function_name, request_parameters, request_status, " +
    " schedule_start_time, schedule_end_time, frequency_uom, frequency_value ) " +
    " VALUES ( '" +
    lineData["sysProgramHeaderId"] +
    "'," +
    " '" +
    lineData["applicationCode"] +
    "'," +
    " '" +
    lineData["jsFilePath"] +
    "'," +
    " '" +
    lineData["jsFunctionName"] +
    "'," +
    " '" +
    JSON.stringify(params) +
    "', 'NEW' ,";
  if (scheduleStartTime.length > 0) {
    insertSql += " '" + scheduleStartTime + "',";
  } else {
    insertSql += " null,";
  }
  if (scheduleEndTime.length > 0) {
    insertSql += " '" + scheduleEndTime + "',";
  } else {
    insertSql += " null,";
  }
  insertSql += " '" + vvFrequencyUom + "',";
  if(vvFrequencyValue.length > 0){
    insertSql += " '" + vvFrequencyValue + "'";
  }else{
    insertSql += " null";
  }
  insertSql += ");";
  request = {
    sql: insertSql,
    dbType: "Sqlite",
  };
  consoleLog("insertProgramRequestHeader insertSql : " + insertSql);
  sqlInsert(request);
}
