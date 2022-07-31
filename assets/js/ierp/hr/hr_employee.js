function beforePatch(inputData) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let request = inputData["request"];
  let data = inputData["data"];
  let action = data["action"];

  if (action == "hr_create_assignment_from_entitlement") {
    let hrLeaveEntitlementHeaderId = data["hrLeaveEntitlementHeaderId"];
    if (hrLeaveEntitlementHeaderId) {
      return createNextPayroll(hrLeaveEntitlementHeaderId);
    }else{
      retDataMap["rd_proceed_message"] = "Unable to create assignments as no leave entitlement header id is provided";
    }
  } else {
    return data;
  }

  return retDataMap;
}

function createNextPayroll(hrLeaveEntitlementHeaderId) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let insertSql =
    " INSERT INTO inoerp.hr_leave_assignment (hr_employee_id, hr_leave_entitlement_line_id, hr_leave_type_id, year, period_number, days) \
    SELECT hr_employee_id, hlel.hr_leave_entitlement_line_id, \
    hlel.hr_leave_type_id, hleh.current_year, hleh.current_period, hlel.leave_per_period \
    from inoerp.hr_employee_ev emp, \
    inoerp.hr_leave_entitlement_line hlel, \
    inoerp.hr_leave_entitlement_header hleh \
    where emp.vv_emp_leave_entitlement_header_id = hlel.hr_leave_entitlement_header_id \
    AND emp.vv_emp_leave_entitlement_header_id = hleh.hr_leave_entitlement_header_id \
    AND vv_emp_leave_entitlement_header_id = '" +
    hrLeaveEntitlementHeaderId +
    "' ";

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
