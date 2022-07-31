function beforePatch(inputData) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let request = inputData["request"];
  let data = inputData["data"];
  let action = data["action"];
  if (action == "hr_start_next_payroll_process") {
    let hrPayrollId = data["hrPayrollId"];
    if (hrPayrollId) {
      return createNextPayroll(hrPayrollId);
    } else {
      retDataMap["rd_proceed_message"] =
        "Unable to create payroll as no leave hrPayrollId is provided";
    }
  } else {
    if (action == "hr_run_payroll") {
      let hrPayrollProcessId = data["hrPayrollProcessId"];
      if (hrPayrollProcessId) {
        return runPayroll(hrPayrollProcessId);
      } else {
        retDataMap["rd_proceed_message"] =
          "Unable to run payroll as no leave hrPayrollProcessId is provided";
      }
    } else if (action == "hr_confirm_payroll") {
      let hrPayrollProcessId = data["hrPayrollProcessId"];
      if (hrPayrollProcessId) {
        return confirmPayroll(hrPayrollProcessId);
      } else {
        retDataMap["rd_proceed_message"] =
          "Unable to confirm payroll as no leave hrPayrollProcessId is provided";
      }
    } else if (action == "hr_change_payroll_status_to_paid") {
      let hrPayrollProcessId = data["hrPayrollProcessId"];
      if (hrPayrollProcessId) {
        return confirmPayroll(hrPayrollProcessId);
      } else {
        retDataMap["rd_proceed_message"] =
          "Unable to confirm payroll as no leave hrPayrollProcessId is provided";
      }
    } else {
      return data;
    }
  }

  return retDataMap;
}

// 1.	Get the payroll id

function createNextPayroll(hrPayrollId) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  const dateSelectSql =
    "SELECT max(end_date) as end_date from hr_last_payroll_process_v where hr_payroll_id = '" +
    hrPayrollId +
    "' ";
  const dateSelectSqlRequest = {
    sql: dateSelectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const dateSelectSqlResponse = sqlSelect(dateSelectSqlRequest);
  let dateResponseData = dateSelectSqlResponse["data"];
  let endDate = "";
  if (dateResponseData.length > 0) {
    endDate = dateResponseData[0]["endDate"];
  }

  if (endDate == null || endDate == "") {
    retDataMap["rd_proceed_message"] =
      "Unable to create payroll as no end date is provided";
    return retDataMap;
  }

  const periodIdSql =
    " SELECT hr_payroll_calendar_period_id from hr_payroll_calendar_period \
  WHERE hr_payroll_calendar_id IN (SELECT hr_payroll_calendar_id from hr_payroll WHERE hr_payroll_id = '" +
    hrPayrollId +
    "' ) \
  AND end_date >  date('" +
    endDate +
    "') ORDER BY end_date asc LIMIT 1";
  const periodIdSqlRequest = {
    sql: periodIdSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const periodIdSqlResponse = sqlSelect(periodIdSqlRequest);
  let periodIdResponseData = periodIdSqlResponse["data"];
  let periodId = 0;
  if (periodIdResponseData.length > 0) {
    periodId = periodIdResponseData[0]["hrPayrollCalendarPeriodId"];
  }

  if (periodId == 0) {
    retDataMap["rd_proceed_message"] =
      "Unable to create payroll as no period id is provided";
    return retDataMap;
  }

  let insertSql =
    " INSERT INTO `inoerp`.`hr_payroll_process` (`hr_payroll_id`, `hr_payroll_calendar_period_id`) \
     VALUES ('" +
    hrPayrollId +
    "', '" +
    periodId +
    "' ) ";

  let insertSqlRequest = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let insertSqlResponse = sqlInsert(insertSqlRequest);

  retDataMap["rd_proceed_message"] =
    getMessageFromSqlResponse(insertSqlResponse);

  return retDataMap;
}

//1. find all employees using the hr_payroll_id from hr_payroll_process_v
//2. find all compensations_lines for each distinct compensation_header_id in step 1
//3. create pay_slip_header for each employee in step 1
//4. get all newly created pay_slip_header_id ( where hr_payroll_process_id = hr_payroll_process_id ) in step 3
//5. find compensation lines from step 2 and add to insert_pay_slip_lines sql
//6. insert pay_slip_line sql
//7. Update status of the hr_payroll_process_v

function runPayroll(hrPayrollProcessId) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let compHeaderIds = [];

  let employeeData = getEmployeeData(hrPayrollProcessId);
  let payrollProcessData = getHrPayrollProcessData(hrPayrollProcessId);

  let insertSql =
    " INSERT INTO `inoerp`.`hr_payslip_header` (`hr_payroll_process_id`, `pay_date`, `hr_employee_id`,  \
  `hr_payroll_calendar_period_id`, `hr_job_id`, `hr_position_id`, `hr_compensation_header_id`)  VALUES ";
  let scheduleTimeStamp = "now()";
  let hrPayrollCalendarPeriodId = 0;
  if (payrollProcessData.length > 0) {
    hrPayrollCalendarPeriodId =
      payrollProcessData[0]["hrPayrollCalendarPeriodId"];
  }

  if (employeeData.length > 0) {
    for (let index = 0; index < employeeData.length; index++) {
      const rowData = employeeData[index];
      insertSql +=
        "('" +
        hrPayrollProcessId +
        "', " +
        scheduleTimeStamp +
        ", '" +
        rowData["hrEmployeeId"] +
        "', '" +
        hrPayrollCalendarPeriodId +
        "', '" +
        rowData["hrJobId"] +
        "', '" +
        rowData["hrPositionId"] +
        "', '" +
        rowData["vvEmpCompensationHeaderId"] +
        "')";
      if (index < employeeData.length - 1) {
        insertSql += ",";
      }
      if (
        rowData["vvEmpCompensationHeaderId"] != null &&
        rowData["vvEmpCompensationHeaderId"] != "" &&
        compHeaderIds.indexOf(rowData["vvEmpCompensationHeaderId"]) == -1
      ) {
        compHeaderIds.push(rowData["vvEmpCompensationHeaderId"]);
      }
    }
  }

  var uniqueIds = compHeaderIds.join(",");

  /*Create PaySlip Headers*/
  request = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let retMessage1 = sqlInsert(request);
  retDataMap["rd_proceed_message"] = getMessageFromSqlResponse(retMessage1);

  createHrPayslipLines(hrPayrollProcessId, uniqueIds);
  updatePayrollStatus(hrPayrollProcessId);

  return retDataMap;
}

function confirmPayroll(hrPayrollProcessId) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  //1. Get current status of the hr_payroll_process_v and check its open
  //2. If open, update status to confirmed
  //3. Update all payslip header status to confirmed
  let docStatus = "";
  const payrollProcessData = getHrPayrollProcessData(hrPayrollProcessId);
  if (payrollProcessData.length > 0) {
    docStatus = payrollProcessData[0]["docStatus"];
  }
  if (docStatus == "open") {
  } else {
    retDataMap["rd_proceed_message"] =
      "Unable to confirm payroll as doc_status is not open";
    return retDataMap;
  }

  updatePayrollDocStatus(hrPayrollProcessId, "confirmed");
  updatePaySlipHeaderStatus(hrPayrollProcessId, "confirmed");
  retDataMap["rd_proceed_message"] = "Payroll is successfully confirmed";
  return retDataMap;
}

function changePayrollStatusToPaid(hrPayrollProcessId) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  //1. Get current status of the hr_payroll_process_v and check its open
  //2. If open, update status to confirmed
  //3. Update all payslip header status to confirmed
  let docStatus = "";
  const payrollProcessData = getHrPayrollProcessData(hrPayrollProcessId);
  if (payrollProcessData.length > 0) {
    docStatus = payrollProcessData[0]["docStatus"];
  }
  if (docStatus == "confirmed") {
  } else {
    retDataMap["rd_proceed_message"] =
      "Unable to confirm payroll as doc_status is not confirmed";
    return retDataMap;
  }

  updatePayrollDocStatus(hrPayrollProcessId, "paid");
  updatePaySlipHeaderStatus(hrPayrollProcessId, "paid");
  retDataMap["rd_proceed_message"] = "Payroll is successfully paid";
  return retDataMap;
}

function updatePayrollDocStatus(hrPayrollProcessId, docStatus) {
  const updateSql =
    " UPDATE `inoerp`.`hr_payroll_process` SET `doc_status` = '" +
    docStatus +
    "' WHERE (`hr_payroll_process_id` = '" +
    hrPayrollProcessId +
    "')    ";
  const sqlRequest = {
    sql: updateSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const sqlResponse = sqlUpdate(sqlRequest);
  sqlResponse["data"];
}

function updatePayslipHeaderStatus(hrPayrollProcessId, docStatus) {
  const updateSql =
    " UPDATE `inoerp`.`hr_payslip_header` SET `doc_status` = '" +
    docStatus +
    "' WHERE (`hr_payroll_process_id` = '" +
    hrPayrollProcessId +
    "')    ";
  const sqlRequest = {
    sql: updateSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const sqlResponse = sqlUpdate(sqlRequest);
  sqlResponse["data"];
}

function updatePayrollStatus(hrPayrollProcessId) {
  const updateSql =
    " UPDATE `inoerp`.`hr_payroll_process` SET `doc_status` = 'open' WHERE (`hr_payroll_process_id` = '" +
    hrPayrollProcessId +
    "')    ";
  const sqlRequest = {
    sql: updateSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const sqlResponse = sqlUpdate(sqlRequest);
  let data = sqlResponse["data"];
  return data;
}

function createHrPayslipLines(hrPayrollProcessId, compHeaderIds) {
  const selectSql =
    " SELECT * FROM inoerp.hr_payslip_header where doc_status = 'entered' and hr_payroll_process_id = '" +
    hrPayrollProcessId +
    "' ";
  const sqlRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const sqlResponse = sqlSelect(sqlRequest);
  let paySlipHeaders = sqlResponse["data"];
  const compensationLinesMap = getAllCompensationLines(compHeaderIds);

  let insertSql =
    " INSERT INTO `inoerp`.`hr_payslip_line` (`hr_payslip_header_id`, `hr_compensation_element_id`, `element_value`)  VALUES ";

  for (let index = 0; index < paySlipHeaders.length; index++) {
    const paySlipHeader = paySlipHeaders[index];
    let compensationLines =
      compensationLinesMap[paySlipHeader["hrCompensationHeaderId"]];
    if (Array.isArray(compensationLines) && compensationLines.length > 0) {
      for (let i = 0; i < compensationLines.length; i++) {
        const compensationLine = compensationLines[i];
        insertSql +=
          "('" +
          paySlipHeader["hrPayslipHeaderId"] +
          "', '" +
          compensationLine["hrCompensationElementId"] +
          "', '" +
          compensationLine["elementValue"] +
          "')";
        if (
          index == paySlipHeaders.length - 1 &&
          i == compensationLines.length - 1
        ) {
        } else {
          insertSql += ",";
        }
      }
    }
  }

  request = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  sqlInsert(request);

  return paySlipHeaders;
}

//group compensation lines by compensation header id
function getAllCompensationLines(compHeaderIds) {
  const selectSql =
    "SELECT * FROM inoerp.hr_compensation_line where hr_compensation_header_id in (" +
    compHeaderIds +
    ")";
  const sqlRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const sqlResponse = sqlSelect(sqlRequest);
  let compensationLines = sqlResponse["data"];
  const groupedCompensationLines = {};
  for (let index = 0; index < compensationLines.length; index++) {
    const rowData = compensationLines[index];
    if (groupedCompensationLines[rowData["hrCompensationHeaderId"]] == null) {
      groupedCompensationLines[rowData["hrCompensationHeaderId"]] = [];
    }
    groupedCompensationLines[rowData["hrCompensationHeaderId"]].push(rowData);
  }
  return groupedCompensationLines;
}

function getHrPayrollProcessData(hrPayrollProcessId) {
  const selectSql =
    " SELECT * from inoerp.hr_payroll_process_v where hr_payroll_process_id = '" +
    hrPayrollProcessId +
    "'  ";
  const sqlRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const sqlResponse = sqlSelect(sqlRequest);
  let data = sqlResponse["data"];
  return data;
}

function getEmployeeData(hrPayrollProcessId) {
  const employeeSelectSql =
    " SELECT * FROM inoerp.hr_employee_ev where vv_emp_hr_payroll_id IN \
    (SELECT hr_payroll_id from hr_payroll_process where hr_payroll_process_id = '" +
    hrPayrollProcessId +
    "' ) ";
  const employeeSelectSqlRequest = {
    sql: employeeSelectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const employeeSelectSqlResponse = sqlSelect(employeeSelectSqlRequest);
  let employeeData = employeeSelectSqlResponse["data"];
  return employeeData;
}

function createPayslipHeader(employeeData) {}
