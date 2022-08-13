function beforePatch(inputData) {
  let data = inputData["data"];
  let action = data["action"];
  if (action == "eam_create_maintenance_schedule") {
    return createMaintenanceSchedule(data, action);
  } else {
    return data;
  }
}

//1. find all asset details
//2. find all existing maintenance schedules
//3. check if a new maintenance schedule is required
function createMaintenanceSchedule(data) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Request is successfully submitted",
  };

  const allAssetDetails = findAllAssetDetails(data);

  let allAssetWithCalendarEntries = [];
  let allAssetWithMeterEntries = [];
  let allCalendarIds = [];
  let allMeterIds = [];
  let allInstanceIdsWithCalendar = [];
  let allInstanceIdsWithMeter = [];
  let allAssetIdsWithCalendar = [];
  let allAssetIdsWithMeter = [];
  let allGroupIdsWithCalendar = [];
  let allGroupIdsWithMeter = [];

  if (allAssetDetails != null && allAssetDetails.length > 0) {
  } else {
    return retDataMap;
  }

  for (let i = 0; i < allAssetDetails.length; i++) {
    const assetDetail = allAssetDetails[i];
    if (
      assetDetail["amCalendarHeaderId"] != null &&
      assetDetail["amCalendarHeaderId"] != ""
    ) {
      allAssetWithCalendarEntries.push(assetDetail);
      if (allCalendarIds.indexOf(assetDetail["amCalendarHeaderId"]) == -1) {
        allCalendarIds.push(assetDetail["amCalendarHeaderId"]);
      }

      if (
        assetDetail["amAssetInstanceId"] &&
        !allInstanceIdsWithCalendar.includes(assetDetail["amAssetInstanceId"])
      ) {
        allInstanceIdsWithCalendar.push(assetDetail["amAssetInstanceId"]);
      } else if (
        assetDetail["faAssetId"] &&
        !allAssetIdsWithCalendar.includes(assetDetail["faAssetId"])
      ) {
        allAssetIdsWithCalendar.push(assetDetail["faAssetId"]);
      } else if (
        assetDetail["amAssetGroupId"] &&
        !allGroupIdsWithCalendar.includes(assetDetail["amAssetGroupId"])
      ) {
        allGroupIdsWithCalendar.push(assetDetail["amAssetGroupId"]);
      }
    } else if (
      assetDetail["amMeterHeaderId"] != null &&
      assetDetail["amMeterHeaderId"] != ""
    ) {

      allAssetWithMeterEntries.push(assetDetail);
      if (allMeterIds.indexOf(assetDetail["amMeterHeaderId"]) == -1) {
        allMeterIds.push(assetDetail["amMeterHeaderId"]);
      }
      if (
        assetDetail["amAssetInstanceId"] &&
        !allInstanceIdsWithMeter.includes(assetDetail["amAssetInstanceId"])
      ) {
        allInstanceIdsWithMeter.push(assetDetail["amAssetInstanceId"]);
      } else if (
        assetDetail["faAssetId"] &&
        !allAssetIdsWithMeter.includes(assetDetail["faAssetId"])
      ) {
        allAssetIdsWithMeter.push(assetDetail["faAssetId"]);
      } else if (
        assetDetail["amAssetGroupId"] &&
        !allGroupIdsWithMeter.includes(assetDetail["amAssetGroupId"])
      ) {
        allGroupIdsWithMeter.push(assetDetail["amAssetGroupId"]);
      }
    }
  }

  createSchedulesForCalendars(
    allAssetWithCalendarEntries,
    allCalendarIds,
    allInstanceIdsWithCalendar,
    allAssetIdsWithCalendar,
    allGroupIdsWithCalendar
  );

  return retDataMap;
  const journalTemplateLines = getAllJournalProfiles(data);
  const allAccountProfiles = getAllAccountProfiles(data);

  if (allAssetDetails.length < 1) {
    retDataMap["rd_proceed_message"] = "No lines to be accounted";
    return retDataMap;
  }

  const headerFirstRow = allAssetDetails[0];
  const vvGlLedgerId = headerFirstRow["vvGlLedgerId"];
  const vvGlDocumentType = headerFirstRow["glDocumentType"];

  //createJournalHeader
  const glJournalHeaderId = createJournalHeader(
    vvGlLedgerId,
    "project_expenditure",
    vvGlDocumentType
  );

  let message = createJournalLines(
    glJournalHeaderId,
    allAssetDetails,
    journalTemplateLines,
    allAccountProfiles
  );

  retDataMap["rd_proceed_message"] = message;

  return retDataMap;
}

//helper function to check and create if a new maintenance schedule is required
//if asset has calendar, then use it else check if asset has meter

//for calendar, check the calendar type

// for fixed_days_interval, check the last maintenance date /asset activation date
// if last maintenance date and asset activation date are in past then create a new maintenance schedule for the current date
// find the next 3 maintenance dates
// check if the next 3 maintenance dates are already scheduled
// if not, create a new maintenance schedule for the next 3 dates

//for calendar date, find the next 3 maintenance dates from yesterday
// check if the next 3 maintenance dates are already scheduled
// if not, create a new maintenance schedule for the next 3 dates

//for meter, find all meter maintenance points
//check if the asset meter value is greater than the meter maintenance point
//if yes, create a new maintenance schedule for the current date

function findAllAssetDetails(dataObject) {
  let selectSql = "SELECT * FROM am_asset_details_v WHERE 1 = 1 ";

  if (dataObject["amAssetInstanceId"]) {
    selectSql +=
      " AND am_asset_instance_id = '" + dataObject["amAssetInstanceId"] + "'";
  } else if (dataObject["faAssetId"]) {
    selectSql += " AND fa_asset_id = '" + dataObject["faAssetId"] + "'";
  } else if (dataObject["amAssetGroupId"]) {
    selectSql +=
      " AND am_asset_group_id = '" + dataObject["amAssetGroupId"] + "'";
  } else {
    return "No asset details found";
  }

  let response = getDataFromSql(selectSql);

  return response;
}

function createSchedulesForCalendars(
  allAssetWithCalendarEntries,
  allCalendarIds,
  allInstanceIdsWithCalendar,
  allAssetIdsWithCalendar,
  allGroupIdsWithCalendar
) {
  let allCalendarIdsWithFixedDaysInterval = [];
  let allCalendarHeadersWithFixedDaysInterval = [];
  let allCalendarIdsWithCalendarDate = [];
  let headerSelectSql = " SELECT * FROM am_calendar_header WHERE 1 = 1 ";
  if (allCalendarIds.length > 0) {
    headerSelectSql +=
      " AND am_calendar_header_id IN (" + allCalendarIds.join(",") + ")";
  }

  let allCalendarHeaders = getDataFromSql(headerSelectSql);

  for (let i = 0; i < allCalendarHeaders.length; i++) {
    let calendarHeader = allCalendarHeaders[i];
    if (calendarHeader["calendarCategory"] == "fixed_days_interval") {
      allCalendarIdsWithFixedDaysInterval.push(
        calendarHeader["amCalendarHeaderId"]
      );
      allCalendarHeadersWithFixedDaysInterval.push(calendarHeader);
    } else if (calendarHeader["calendarCategory"] == "calendar_date") {
      allCalendarIdsWithCalendarDate.push(calendarHeader["amCalendarHeaderId"]);
    }
  }
  

  let allAssetsWithInstanceIdMap = {};
  let allAssetsWithAssetIdMap = {};
  let allAssetsWithGroupIdMap = {};

  for (let i = 0; i < allAssetWithCalendarEntries.length; i++) {
    let assetDetail = allAssetWithCalendarEntries[i];
    if (assetDetail["amAssetInstanceId"]) {
      if (!allAssetsWithInstanceIdMap[assetDetail["amAssetInstanceId"]]) {
        allAssetsWithInstanceIdMap[assetDetail["amAssetInstanceId"]] = [];
      }
      allAssetsWithInstanceIdMap[assetDetail["amAssetInstanceId"]].push(
        assetDetail
      );
    } else if (assetDetail["faAssetId"]) {
      if (!allAssetsWithAssetIdMap[assetDetail["faAssetId"]]) {
        allAssetsWithAssetIdMap[assetDetail["faAssetId"]] = [];
      }
      allAssetsWithAssetIdMap[assetDetail["faAssetId"]].push(assetDetail);
    } else if (assetDetail["amAssetGroupId"]) {
      if (!allAssetsWithGroupIdMap[assetDetail["amAssetGroupId"]]) {
        allAssetsWithGroupIdMap[assetDetail["amAssetGroupId"]] = [];
      }
      allAssetsWithGroupIdMap[assetDetail["amAssetGroupId"]].push(assetDetail);
    }
  }


  if (allCalendarIdsWithFixedDaysInterval.length > 0) {
    createScheduleForFixedDaysInterval(
      allCalendarIdsWithFixedDaysInterval,
      allCalendarHeadersWithFixedDaysInterval,
      allAssetsWithInstanceIdMap,
      allAssetsWithAssetIdMap,
      allAssetsWithGroupIdMap,
      allInstanceIdsWithCalendar
    );
  }

  if (allCalendarIdsWithCalendarDate.length > 0) {
    createScheduleForCalendarDates(
      allCalendarIdsWithCalendarDate,
      allAssetsWithInstanceIdMap,
      allAssetsWithAssetIdMap,
      allAssetsWithGroupIdMap,
      allInstanceIdsWithCalendar
    );
  }
}

function createScheduleForFixedDaysInterval(
  allCalendarIdsWithFixedDaysInterval,
  allCalendarHeadersWithFixedDaysInterval,
  allAssetsWithInstanceIdMap,
  allAssetsWithAssetIdMap,
  allAssetsWithGroupIdMap,
  allInstanceIdsWithCalendar
) {

  
  //Create schedule lines for all instances with calendar entries
  let allExistingScheduleHeadersForInstances = findAllExistingScheduleHeaders(
    allInstanceIdsWithCalendar,
    null,
    null
  );

  let allExistingScheduleLInesForInstances = findAllExistingScheduleLines(
    allInstanceIdsWithCalendar,
    null,
    null
  );

  if (Object.keys(allAssetsWithInstanceIdMap).length > 0) {
  } else {
    return;
  }

  if (allCalendarIdsWithFixedDaysInterval.length > 0) {
  } else {
    return;
  }

   //check and create schedule headers for all instances with calendar entries
   CreateNewScheduleHeader(
    allAssetsWithInstanceIdMap,
    allExistingScheduleHeadersForInstances
  );

    //get updated findAllExistingScheduleHeaders for all instances with calendar entries
    allExistingScheduleHeadersForInstances = findAllExistingScheduleHeaders(
      allInstanceIdsWithCalendar,
      null,
      null
    );

      //check and create schedule lines for all instances with calendar entries
  CreateNewScheduleLineForCalendarDateAndInstances(
    allAssetsWithInstanceIdMap,
    allExistingScheduleHeadersForInstances,
    allExistingScheduleLInesForInstances,
    mappedCalendarLines
  );



}

function createScheduleForCalendarDates(
  allCalendarIdsWithCalendarDate,
  allAssetsWithInstanceIdMap,
  allAssetsWithAssetIdMap,
  allAssetsWithGroupIdMap,
  allInstanceIdsWithCalendar
) {
  let selectSql = "SELECT * FROM am_calendar_line WHERE 1 = 1 ";
  if (allCalendarIdsWithCalendarDate.length > 0) {
    selectSql +=
      " AND am_calendar_header_id IN (" + allCalendarIdsWithCalendarDate.join(",") + ")";
  }

  let allCalendarLines = getDataFromSql(selectSql);

  //Create schedule lines for all instances with calendar entries
  let allExistingScheduleHeadersForInstances = findAllExistingScheduleHeaders(
    allInstanceIdsWithCalendar,
    null,
    null
  );

  let allExistingScheduleLInesForInstances = findAllExistingScheduleLines(
    allInstanceIdsWithCalendar,
    null,
    null
  );

  createScheduleLinesForInstancesWithCalendarDate(
    allInstanceIdsWithCalendar,
    allAssetsWithInstanceIdMap,
    allExistingScheduleHeadersForInstances,
    allExistingScheduleLInesForInstances,
    allCalendarLines
  );
  return selectSql;
}

function createScheduleLinesForInstancesWithCalendarDate(
  allInstanceIdsWithCalendar,
  allAssetsWithInstanceIdMap,
  allExistingScheduleHeadersForInstances,
  allExistingScheduleLInesForInstances,
  allCalendarLines
) {
  if (Object.keys(allAssetsWithInstanceIdMap).length > 0) {
  } else {
    return;
  }

  if (allCalendarLines.length > 0) {
  } else {
    return;
  }

  let mappedCalendarLines = {};
  for (let i = 0; i < allCalendarLines.length; i++) {
    let calendarLine = allCalendarLines[i];
    if (!mappedCalendarLines[calendarLine["amCalendarHeaderId"]]) {
      mappedCalendarLines[calendarLine["amCalendarHeaderId"]] = [];
    }
    mappedCalendarLines[calendarLine["amCalendarHeaderId"]].push(calendarLine);
  }

  //check and create schedule headers for all instances with calendar entries
  CreateNewScheduleHeader(
    allAssetsWithInstanceIdMap,
    allExistingScheduleHeadersForInstances
  );

  //get updated findAllExistingScheduleHeaders for all instances with calendar entries
  allExistingScheduleHeadersForInstances = findAllExistingScheduleHeaders(
    allInstanceIdsWithCalendar,
    null,
    null
  );

  //check and create schedule lines for all instances with calendar entries
  CreateNewScheduleLineForCalendarDateAndInstances(
    allAssetsWithInstanceIdMap,
    allExistingScheduleHeadersForInstances,
    allExistingScheduleLInesForInstances,
    mappedCalendarLines
  );
}

//find calendar lines for all instances
//check if the calendar line is already scheduled
//if not, create a new schedule line for the calendar date
function CreateNewScheduleLineForCalendarDateAndInstances(
  allAssetsWithInstanceIdMap,
  allExistingScheduleHeadersForInstances,
  allExistingScheduleLInesForInstances,
  mappedCalendarLines
) {
  let allExistingScheduleHeadersForInstancesMap = {};
  for (let i = 0; i < allExistingScheduleHeadersForInstances.length; i++) {
    let scheduleHeader = allExistingScheduleHeadersForInstances[i];
    allExistingScheduleHeadersForInstancesMap[
      scheduleHeader["amAssetInstanceId"]
    ] = scheduleHeader;
  }

  let insertSql =
    " INSERT INTO `inoerp`.`am_schedule_date` (`am_maintenance_schedule_id`, `am_calendar_line_id`, `line_seq`, `start_date`) \
   VALUES   ";
  let allNewLinesToBeCreated = [];
  let instanceIds = Object.keys(allAssetsWithInstanceIdMap);

  for (let i = 0; i < instanceIds.length; i++) {
    let instanceId = instanceIds[i];
    let assetDetails = allAssetsWithInstanceIdMap[instanceId];
    let amCalendarHeaderId = assetDetails[0]["amCalendarHeaderId"];
    consoleLog(
      "\n CreateNewScheduleLineForInstances 1.1 assetDetails" +
        JSON.stringify(assetDetails)
    );

    let calendarLinesForInstance = mappedCalendarLines[amCalendarHeaderId];
    let scheduleHeader = allExistingScheduleHeadersForInstancesMap[instanceId];
    let scheduleId = scheduleHeader["amMaintenanceScheduleId"];
    let existingScheduleLinesForInstance =
      allExistingScheduleLInesForInstances[instanceId];
    if (
      !(calendarLinesForInstance != null && calendarLinesForInstance.length > 0)
    ) {
      continue;
    }
    if (!(scheduleId != null && scheduleId > 0)) {
      consoleLog("\n Unable to find scheduleId for " + instanceId);
      continue;
    }

    consoleLog(
      "\n CreateNewScheduleLineForInstances 3 scheduleId" +
        JSON.stringify(scheduleId)
    );

    if (
      existingScheduleLinesForInstance != null &&
      existingScheduleLinesForInstance.length > 0
    ) {
      for (let j = 0; j < calendarLinesForInstance.length; j++) {
        let calendarLine = calendarLinesForInstance[j];
        let addLine = true;
        for (let k = 0; k < existingScheduleLinesForInstance.length; k++) {
          let existingScheduleLine = existingScheduleLinesForInstance[k];
          if (
            existingScheduleLine["amCalendarLineId"] ==
            calendarLine["amCalendarLineId"]
          ) {
            addLine = false;
            break;
          }
        }
        // let existingScheduleLinesForCalendar =
        //   existingScheduleLinesForInstance.filter(
        //     (scheduleLine) =>
        //       scheduleLine["amCalendarLineId"] ==
        //       calendarLine["amCalendarLineId"]
        //   );
        if (addLine) {
          let newLine =
            "('" +
            scheduleId +
            "', '" +
            calendarLine["amCalendarLineId"] +
            "', '" +
            calendarLine["lineSeq"] +
            "', '" +
            calendarLine["calendarDate"] +
            "')";
          allNewLinesToBeCreated.push(newLine);
        }
      }
    } else {
      for (let j = 0; j < calendarLinesForInstance.length; j++) {
        let calendarLine = calendarLinesForInstance[j];
        let newLine =
          "('" +
          scheduleId +
          "', '" +
          calendarLine["amCalendarLineId"] +
          "', '" +
          calendarLine["lineSeq"] +
          "', '" +
          calendarLine["calendarDate"] +
          "')";
        allNewLinesToBeCreated.push(newLine);
      }
    }
  }

  if (allNewLinesToBeCreated.length > 0) {
    insertSql += allNewLinesToBeCreated.join(", ");
    consoleLog("\n\n CreateNewScheduleLineForInstances insertSql" + insertSql);
    insertDataWithSql(insertSql);
  }
}

function CreateNewScheduleHeader(
  allAssetsWithInstanceIdMap,
  allExistingScheduleHeadersForInstances
) {
  if (
    allAssetsWithInstanceIdMap != null &&
    Object.keys(allAssetsWithInstanceIdMap).length > 0
  ) {
  } else {
    return;
  }

  let keys = Object.keys(allAssetsWithInstanceIdMap);

  let insertSql =
    " INSERT INTO `inoerp`.`am_maintenance_schedule` \
  (`schedule_name`, `am_asset_instance_id`) VALUES ";

  let insertSqlLines = [];
  for (let i = 0; i < keys.length; i++) {
    let k = keys[i];
    //for instanceIdMap each map contains only one asset
    let assetDetails = allAssetsWithInstanceIdMap[k];
    let assetInstanceId = assetDetails[0]["amAssetInstanceId"];
    let allExistingScheduleIdsForInstance =
      allExistingScheduleHeadersForInstances[assetInstanceId];
    if (
      allExistingScheduleIdsForInstance != null &&
      allExistingScheduleIdsForInstance.length > 0
    ) {
      // use the existing headerId
    } else {
      //create new schedule header for the asset
      let insertSqlLine =
        "('Schedule For Instance " +
        assetInstanceId +
        "', '" +
        assetInstanceId +
        "')";
      insertSqlLines.push(insertSqlLine);
    }
  }

  if (insertSqlLines.length > 0) {
    insertSql += insertSqlLines.join(",");
    insertDataWithSql(insertSql);
  }
}

function findAllExistingScheduleHeaders(
  allInstanceIds,
  allAssetIds,
  allGroupIds
) {
  let selectSql = "SELECT * FROM am_maintenance_schedule WHERE 1 = 1 ";
  if (allInstanceIds.length > 0) {
    selectSql +=
      " AND am_asset_instance_id IN (" + allInstanceIds.join(",") + ")";
  } else if (allAssetIds.length > 0) {
    selectSql += " AND fa_asset_id IN (" + allAssetIds.join(",") + ")";
  } else if (allGroupIds.length > 0) {
    selectSql += " AND am_asset_group_id IN (" + allGroupIds.join(",") + ")";
  } else {
    return [];
  }
  let response = getDataFromSql(selectSql);
  return response;
}

function findAllExistingScheduleLines(
  allInstanceIds,
  allAssetIds,
  allGroupIds
) {
  let selectSql = "SELECT * FROM am_schedule_date_tv WHERE 1 = 1 ";
  if (allInstanceIds.length > 0) {
    selectSql +=
      " AND vv_am_asset_instance_id IN (" + allInstanceIds.join(",") + ")";
  } else if (allAssetIds.length > 0) {
    selectSql += " AND vv_fa_asset_id IN (" + allAssetIds.join(",") + ")";
  } else if (allGroupIds.length > 0) {
    selectSql += " AND vv_am_asset_group_id IN (" + allGroupIds.join(",") + ")";
  } else {
    return [];
  }
  let response = getDataFromSql(selectSql);
  return response;
}
