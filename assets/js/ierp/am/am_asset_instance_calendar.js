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

  let allCalendarHeadersWithFixedDaysIntervalMap = {};
  for (let i = 0; i < allCalendarHeadersWithFixedDaysInterval.length; i++) {
    let calendarHeader = allCalendarHeadersWithFixedDaysInterval[i];
    allCalendarHeadersWithFixedDaysIntervalMap[
      calendarHeader["amCalendarHeaderId"]
    ] = calendarHeader;
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
  CreateNewScheduleLineForFixedDaysIntervalAndInstances(
    allCalendarHeadersWithFixedDaysIntervalMap,
    allAssetsWithInstanceIdMap,
    allExistingScheduleHeadersForInstances,
    allExistingScheduleLInesForInstances
  );
}

//find all asset instances with calendar fixed days interval
//find all existing schedule headers & lines for asset instances with calendar fixed days interval
//find all required schedule lines as per calendar fixed days interval, asset instance date and current date
//create new schedule lines if required
function CreateNewScheduleLineForFixedDaysIntervalAndInstances(
  allCalendarHeadersWithFixedDaysIntervalMap,
  allAssetsWithInstanceIdMap,
  allExistingScheduleHeadersForInstances,
  allExistingScheduleLInesForInstances
) {
  let allExistingScheduleHeadersForInstancesMap = {};
  for (let i = 0; i < allExistingScheduleHeadersForInstances.length; i++) {
    let scheduleHeader = allExistingScheduleHeadersForInstances[i];
    allExistingScheduleHeadersForInstancesMap[
      scheduleHeader["amAssetInstanceId"]
    ] = scheduleHeader;
  }

  let insertSql =
    " INSERT INTO `inoerp`.`am_schedule_date` (`am_maintenance_schedule_id`, `line_seq`, `start_date`) \
   VALUES   ";
  let allNewLinesToBeCreated = expectedScheduleLinesForFixedDaysInterval(
    allCalendarHeadersWithFixedDaysIntervalMap,
    allAssetsWithInstanceIdMap,
    allExistingScheduleHeadersForInstancesMap
  );

  if (allNewLinesToBeCreated.length > 0) {
    insertSql += allNewLinesToBeCreated.join(", ");
    consoleLog("\n\n CreateNewScheduleLineForInstances insertSql" + insertSql);
    insertDataWithSql(insertSql);
  }
}

//end date of schedule = current date + schedulingHorizon
//no of days to be scheduled = end date of schedule - lastScheduleDate
//no lines to be created = no of days to be scheduled / fixed days interval

function expectedScheduleLinesForFixedDaysInterval(
  allCalendarHeadersWithFixedDaysIntervalMap,
  allAssetsWithInstanceIdMap,
  allExistingScheduleHeadersForInstancesMap
) {
  let allNewLinesToBeCreated = [];
  //key schedule header Id, value array of schedule lines
  let expectedScheduleLinesMap = {};
  let instanceIds = Object.keys(allAssetsWithInstanceIdMap);
  let existingMaxLineSeq = findMaxLineSeq();
  let schedulingHorizon = 365;
  for (let i = 0; i < instanceIds.length; i++) {
    let instanceId = instanceIds[i];
    let assetDetails = allAssetsWithInstanceIdMap[instanceId];
    let lastScheduleDateOriginal = "";
    let activationDate = assetDetails[0]["activationDate"];
    let lastScheduleDate = assetDetails[0]["lastScheduleDate"];
    if (lastScheduleDate == null || lastScheduleDate == "") {
      lastScheduleDate = activationDate;
      lastScheduleDateOriginal = activationDate;
    }else{
      lastScheduleDateOriginal = lastScheduleDate;
    }
    let amCalendarHeaderId = assetDetails[0]["amCalendarHeaderId"];
    let calendarHeader =
      allCalendarHeadersWithFixedDaysIntervalMap[amCalendarHeaderId];
    let scheduleId =
      allExistingScheduleHeadersForInstancesMap[instanceId][
        "amMaintenanceScheduleId"
      ];
    let fixedDays = calendarHeader["fixedDaysInterval"];
    if (fixedDays != null && parseInt(fixedDays) > 0) {
    } else {
      continue;
    }

    let lastDate = Date.parse(lastScheduleDate);
    let horizonEndDate = new Date();
    horizonEndDate.setDate(horizonEndDate.getDate() + schedulingHorizon);
    const diffInDays =
      (horizonEndDate.getTime() - lastDate) / (1000 * 3600 * 24);

    if (diffInDays > fixedDays) {
      let noOfLines = Math.ceil(diffInDays / fixedDays);
      for (let j = 0; j < noOfLines; j++) {
        existingMaxLineSeq++;
        let offset = j * fixedDays;
        let newLine =
          "('" +
          scheduleId +
          "', '" +
          existingMaxLineSeq +
          "', '" +
          lastScheduleDateOriginal +
          "' + INTERVAL " +
          offset +
          " DAY " +
          ")";
        allNewLinesToBeCreated.push(newLine);
      }
    }
  }
  return allNewLinesToBeCreated;
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
      " AND am_calendar_header_id IN (" +
      allCalendarIdsWithCalendarDate.join(",") +
      ")";
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

