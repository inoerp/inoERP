function beforePatch(inputData) {
  let data = inputData["data"];
  let action = data["action"];
  if (action == "eam_create_maintenance_schedule") {
    return createMaintenanceSchedule(data, action);
  } else if (action == "eam_create_maintenance_order") {
    return createMaintenanceWorkOrderInterface(data);
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

  createSchedulesForMeters(
    allAssetWithMeterEntries,
    allMeterIds,
    allInstanceIdsWithMeter,
    allAssetIdsWithMeter,
    allGroupIdsWithMeter
  );

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

function findAllExistingScheduleHeaders(
  allInstanceIds,
  allAssetIds,
  allGroupIds
) {
  let selectSql = "SELECT * FROM am_maintenance_schedule WHERE 1 = 1 ";
  if (allInstanceIds != null && allInstanceIds.length > 0) {
    selectSql +=
      " AND am_asset_instance_id IN (" + allInstanceIds.join(",") + ")";
  } else if (allAssetIds != null && allAssetIds.length > 0) {
    selectSql += " AND fa_asset_id IN (" + allAssetIds.join(",") + ")";
  } else if (allGroupIds != null && allGroupIds.length > 0) {
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
  if (allInstanceIds != null && allInstanceIds.length > 0) {
    selectSql +=
      " AND vv_am_asset_instance_id IN (" + allInstanceIds.join(",") + ")";
  } else if (allAssetIds != null && allAssetIds.length > 0) {
    selectSql += " AND vv_fa_asset_id IN (" + allAssetIds.join(",") + ")";
  } else if (allGroupIds != null && allGroupIds.length > 0) {
    selectSql += " AND vv_am_asset_group_id IN (" + allGroupIds.join(",") + ")";
  } else {
    return [];
  }
  let response = getDataFromSql(selectSql);
  return response;
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

function findMaxLineSeq() {
  let sql =
    "SELECT max(line_seq) as max_line_seq from inoerp.am_schedule_date  ";
  let result = getDataFromSql(sql);
  if (result.length > 0) {
    return result[0]["maxLineSeq"];
  } else {
    return 0;
  }
}

function createMaintenanceWorkOrderInterface(dataObject) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Request is successfully submitted",
  };

  let insertSql =
    "  INSERT INTO `inoerp`.`wip_wo_interface` (`inv_org_id`, `wip_wd_header_id`, `inv_item_master_id`, " +
    " `description`,  `quantity`, `nettable_quantity`,  `am_maintenance_schedule_id`, `start_date` , " +
    " `bom_usage_category` , `wo_cost_category` ) " +
    " SELECT inv_org_id, ifnull(wip_wd_header_id, 1), inv_item_master_id, 'Released from Maintenance',  " +
    "  1,  1, am_maintenance_schedule_id, start_date , 'maintenance',  'expense' " +
    " FROM inoerp.am_schedule_date_for_wo_v WHERE doc_status = 'confirmed'  ";

    consoleLog(
      "\n\n createMaintenanceWorkOrderInterface 1 insertSql " + insertSql
    );

  if (dataObject["amAssetInstanceId"]) {
    insertSql +=
      " AND am_asset_instance_id = '" + dataObject["amAssetInstanceId"] + "'";
  } else if (dataObject["faAssetId"]) {
    insertSql += " AND fa_asset_id = '" + dataObject["faAssetId"] + "'";
  } else if (dataObject["amAssetGroupId"]) {
    insertSql +=
      " AND am_asset_group_id = '" + dataObject["amAssetGroupId"] + "'";
  }

  consoleLog(
    "\n\n createMaintenanceWorkOrderInterface 2 insertSql " + insertSql
  );
  let insertData = insertDataWithSql(insertSql);
  retDataMap["rd_proceed_message"] = JSON.stringify(insertData);
  return retDataMap;
}
