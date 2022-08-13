function createSchedulesForMeters(
  allAssetWithMeterEntries,
  allMeterIds,
  allInstanceIdsWithMeter,
  allAssetIdsWithMeter,
  allGroupIdsWithMeter
) {
  let headerSelectSql = " SELECT * FROM inoerp.am_meter_header WHERE 1 = 1 ";
  if (allMeterIds.length > 0) {
    headerSelectSql +=
      " AND am_meter_header_id IN (" + allMeterIds.join(",") + ")";
  }
  let allMeterHeaders = getDataFromSql(headerSelectSql);

  let lineSelectSql = " SELECT * FROM inoerp.am_meter_line WHERE 1 = 1 ";
  if (allMeterIds.length > 0) {
    lineSelectSql +=
      " AND am_meter_header_id IN (" + allMeterIds.join(",") + ")";
  }
  let allMeterLines = getDataFromSql(lineSelectSql);

  let maximumReadingSql =
    " SELECT * FROM inoerp.am_meter_reading_max_value_v WHERE 1 = 1 ";
  if (allMeterIds.length > 0) {
    maximumReadingSql +=
      " AND am_meter_header_id IN (" + allMeterIds.join(",") + ")";
  }
  let allReadingMaximumLInes = getDataFromSql(maximumReadingSql);

  let allAssetsWithInstanceIdMap = {};
  let allAssetsWithAssetIdMap = {};
  let allAssetsWithGroupIdMap = {};
  let meterLinesWithMeterHeaderMap = {};

  for (let i = 0; i < allAssetWithMeterEntries.length; i++) {
    let assetDetail = allAssetWithMeterEntries[i];
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

  for (let i = 0; i < allMeterLines.length; i++) {
    let meterLine = allMeterLines[i];
    if (!meterLinesWithMeterHeaderMap[meterLine["amMeterHeaderId"]]) {
      meterLinesWithMeterHeaderMap[meterLine["amMeterHeaderId"]] = [];
    }
    meterLinesWithMeterHeaderMap[meterLine["amMeterHeaderId"]].push(meterLine);
  }

  if (allMeterHeaders.length > 0) {
    createScheduleForFixedDaysInterval(
      allMeterHeaders,
      meterLinesWithMeterHeaderMap,
      allAssetsWithInstanceIdMap,
      allAssetsWithAssetIdMap,
      allAssetsWithGroupIdMap,
      allInstanceIdsWithMeter,
      allReadingMaximumLInes
    );
  }
}

function createScheduleForMeterReading(
  allMeterHeaders,
  meterLinesWithMeterHeaderMap,
  allAssetsWithInstanceIdMap,
  allAssetsWithAssetIdMap,
  allAssetsWithGroupIdMap,
  allInstanceIdsWithMeter,
  allReadingMaximumLInes
) {
  //Create schedule lines for all instances with calendar entries
  let allExistingScheduleHeadersForInstances = findAllExistingScheduleHeaders(
    allInstanceIdsWithMeter,
    null,
    null
  );

  let allExistingScheduleLInesForInstances = findAllExistingScheduleLines(
    allInstanceIdsWithMeter,
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

  let allExistingScheduleHeadersForInstancesMap = {};
  for (let i = 0; i < allExistingScheduleHeadersForInstances.length; i++) {
    let scheduleHeader = allExistingScheduleHeadersForInstances[i];
    allExistingScheduleHeadersForInstancesMap[
      scheduleHeader["amAssetInstanceId"]
    ] = scheduleHeader;
  }

  let insertSql =
    " INSERT INTO `inoerp`.`am_schedule_date` (`am_maintenance_schedule_id`, `line_seq`, `start_date`, \
`am_meter_line_id`, `am_meter_reading_id`)  VALUES   ";

  //check and create schedule lines for all instances with calendar entries
 const allNewLinesToBeCreated =  CreateNewScheduleLineForMeterReading(
    allReadingMaximumLInes,
    meterLinesWithMeterHeaderMap,
    allExistingScheduleHeadersForInstancesMap,
    allExistingScheduleLInesForInstances
  );

  if (allNewLinesToBeCreated.length > 0) {
    insertSql += allNewLinesToBeCreated.join(", ");
    consoleLog("\n\n CreateNewScheduleLineForInstances insertSql" + insertSql);
    insertDataWithSql(insertSql);
  }
}

//find all asset instances with meter entries
//find all existing schedule headers & lines for asset instances with meter entries
//find all meter header and line details
//find maximum reading for each meter / instance
//check if maximum reading is greater than equal to any meter reading point
//if there is no schedule line for the maximum reading, create a new schedule line for the maximum reading

// loop through all allReadingMaximumLInes
// for the meter header find all the lines less than or equal to the maximum reading (list l1)
// for the asset instance id check all the existing schedule lines (list l2)
// find all the meter reading lines for the meter header (list l3)
// for each meter line in l3, check if there is a schedule line in l2 with the same meter line id
// if there is no schedule line in l2 with the same meter line id, create a new schedule line for the meter line

function CreateNewScheduleLineForMeterReading(
  allReadingMaximumLInes,
  meterLinesWithMeterHeaderMap,
  allExistingScheduleHeadersForInstancesMap,
  allExistingScheduleLInesForInstances
) {
  let allNewLinesToBeCreated = [];

  let existingMaxLineSeq = findMaxLineSeq();
  const currDate = new Date();
  const currDateStr = currDate.toISOString().split("T")[0];

  for (let index = 0; index < allReadingMaximumLInes.length; index++) {
    const element = allReadingMaximumLInes[index];
    const amMeterReadingId = element["amMeterReadingId"];
    const amAssetInstanceId = element["amAssetInstanceId"];
    const amMeterHeaderId = element["amMeterHeaderId"];
    const maxReadingValue = element["maxReadingValue"];
    let scheduleId =
      allExistingScheduleHeadersForInstancesMap[amAssetInstanceId][
        "amMaintenanceScheduleId"
      ];
    const maxReadingValueFloat = parseFloat(maxReadingValue);

    const allExistingScheduleLInesForInstance =
      allExistingScheduleLInesForInstances[amAssetInstanceId];

    let meterLinesMightRequireScheduleLine = [];
    let meterLines = meterLinesWithMeterHeaderMap[amMeterHeaderId];
    if (meterLines && meterLines.length > 0) {
    } else {
      continue;
    }

    for (let i = 0; i < meterLines.length; i++) {
      const meterLine = meterLines[i];
      const readingControl = meterLine["readingControl"];
      const readingControlValue = parseFloat(readingControl);
      if (readingControlValue <= maxReadingValueFloat) {
        //check if there is a schedule line for the meter line
        if (
          allExistingScheduleLInesForInstance != null &&
          allExistingScheduleLInesForInstance.length > 0
        ) {
          addTheLine = true;
          for (let j = 0; j < allExistingScheduleLInesForInstance.length; j++) {
            const scheduleLine = allExistingScheduleLInesForInstance[j];
            const amMeterLineId = scheduleLine["amMeterLineId"];
            if (amMeterLineId == meterLine["amMeterLineId"]) {
              addTheLine = false;
              break;
            }
          }
          if (addTheLine) {
            meterLinesMightRequireScheduleLine.push(meterLine);
          }
        } else {
          meterLinesMightRequireScheduleLine.push(meterLine);
        }
      }
    }

    if (meterLinesMightRequireScheduleLine.length > 0) {
      for (let i = 0; i < meterLinesMightRequireScheduleLine.length; i++) {
        existingMaxLineSeq++;
        const meterLine = meterLinesMightRequireScheduleLine[i];
        let newLine =
          "('" +
          scheduleId +
          "', '" +
          existingMaxLineSeq +
          "', '" +
          currDateStr +
          "', '" +
          meterLine["amMeterLineId"] +
          "', '" +
          meterLine["amMeterReadingId"] +
          "'" +
          ")";
        allNewLinesToBeCreated.push(newLine);
      }
    }
  }

  return allNewLinesToBeCreated;
}
