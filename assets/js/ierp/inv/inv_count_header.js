function beforePatch(inputData) {

  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let request = inputData["request"];
  let data = inputData["data"];
  let action = data["action"];

  if (
    action == "js_inv_generate_count_schedule" ||
    action == "js_inv_update_count_schedule" ||
    action == "js_inv_approve_count_schedule"
  ) {
  } else {
    return data;
  }

  let invCountHeaderId = data["invCountHeaderId"];
  let invOrgId;
  let invAbcValHeaderId;
  let aCountPerYear = 0;
  let bCountPerYear = 0;
  let cCountPerYear = 0;
  let dCountPerYear = 0;
  let eCountPerYear = 0;

  let countSql =
    " SELECT inv_org_id  inv_org_id, inv_abc_val_header_id  inv_abc_val_header_id, ifnull(a_count_per_year, 1)  a_count_per_year, " +
    " ifnull(b_count_per_year, 1) b_count_per_year , ifnull(c_count_per_year, 1) c_count_per_year , " +
    " ifnull(d_count_per_year, 1) d_count_per_year, ifnull(e_count_per_year, 1)  e_count_per_year " +
    " FROM inv_count_header WHERE inv_count_header_id  = '" +
    invCountHeaderId +
    "'";

  let selectRequest = {
    sql: countSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let selectResponse = sqlSelect(selectRequest);
  let selectData = selectResponse["data"];
  if (selectData.length > 0) {
    firstRow = selectData[0];
    invOrgId = firstRow["invOrgId"];
    invAbcValHeaderId = firstRow["invAbcValHeaderId"];
    aCountPerYear = firstRow["aCountPerYear"];
    bCountPerYear = firstRow["bCountPerYear"];
    cCountPerYear = firstRow["cCountPerYear"];
    dCountPerYear = firstRow["dCountPerYear"];
    eCountPerYear = firstRow["eCountPerYear"];
  }


  if (action == "js_inv_generate_count_schedule") {
    generateCountSchedule(
      invOrgId,
      invCountHeaderId,
      invAbcValHeaderId,
      aCountPerYear,
      bCountPerYear,
      cCountPerYear,
      dCountPerYear,
      eCountPerYear
    );

    retDataMap["rd_proceed_message"] = "Counts are successfully generated";
  }

  return retDataMap;
}

function generateCountSchedule(
  invOrgId,
  invCountHeaderId,
  invAbcValHeaderId,
  aCountPerYear,
  bCountPerYear,
  cCountPerYear,
  dCountPerYear,
  eCountPerYear
) {
  let deleteSql =
    " DELETE " +
    " FROM inv_count_line WHERE inv_count_header_id  = '" +
    invCountHeaderId +
    "'";

  let deleteRequest = {
    sql: deleteSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let deleteResponse = sqlDelete(deleteRequest);

  let countSql = getCountSql(invAbcValHeaderId);

  let countRequest = {
    sql: countSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let countResponse = sqlSelect(countRequest);
  let countData = countResponse["data"];
  let aDataList = [];
  let bDataList = [];
  let cDataList = [];
  let dDataList = [];
  let eDataList = [];

  for (let i = 0; i < countData.length; i++) {
    let currData = countData[i];

    if (currData["abcClass"] == "A") {
      aDataList.push(currData);
    } else if (currData["abcClass"] == "B") {
      bDataList.push(currData);
    } else if (currData["abcClass"] == "C") {
      cDataList.push(currData);
    } else if (currData["abcClass"] == "D") {
      // D
      dDataList.push(currData);
    } else {
      // E
      eDataList.push(currData);
    }
  }


  insertScheduleLines(aDataList, aCountPerYear, invOrgId, invCountHeaderId);
  insertScheduleLines(bDataList, bCountPerYear, invOrgId, invCountHeaderId);
  insertScheduleLines(cDataList, cCountPerYear, invOrgId, invCountHeaderId);
  insertScheduleLines(dDataList, dCountPerYear, invOrgId, invCountHeaderId);
  insertScheduleLines(eDataList, eCountPerYear, invOrgId, invCountHeaderId);
}

function insertScheduleLines(
  dataList,
  countPerYear,
  invOrgId,
  invCountHeaderId
) {
  if (dataList.length > 0) {
    if (isNaN(countPerYear) || countPerYear < 1) {
      countPerYear = 1;
    }
    let totalNoOfItems = dataList.length;
    let totalCount = totalNoOfItems * countPerYear;
    let dailyCount = Math.ceil(totalCount / 365);
    let timeGap = Math.floor(365 / totalCount) - 1;
    if (timeGap < 0) {
      timeGap = 0;
    }
    let completedCount = 0;
    let scheduleTimeStamp = "now()";
    let totalTimeGap = 0;
    let currentDayCount = 0;
    let insertSql =
      " INSERT INTO `inoerp`.`inv_count_line` (`inv_count_header_id`, `inv_item_master_id`, `inv_org_id`, `uom_code` "+
     " ,`schedule_date`,`sub_inventory`,`locator_id`) VALUES ";
    while (completedCount < totalNoOfItems) {
      if (currentDayCount == dailyCount) {
        currentDayCount = 0;
        totalTimeGap = totalTimeGap + timeGap;
        scheduleTimeStamp = "now() +" + "INTERVAL " + totalTimeGap + " DAY";
      }
      let currData = dataList[completedCount];
      insertSql +=
        "('" +
        invCountHeaderId +
        "', '" +
        currData["invItemMasterId"] +
        "', '" +
        invOrgId +
        "', '" +
        currData["uomCode"] +
        "', " +
        scheduleTimeStamp +
        ", '" +
        currData["subInventory"] +
        "', '" +
        currData["locatorId"] +
        "')";

      if (completedCount < totalNoOfItems - 1) {
        insertSql += ",";
      }
      currentDayCount++;
      completedCount++;
    }

    request = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let retMessage1 = sqlInsert(request);
    return retMessage1;
  }
}

function getCountSql(invAbcValHeaderId) {
  let countSql =
    "SELECT iavl.inv_abc_val_header_id, iavl.inv_item_master_id inv_item_master_id,  " +
    " ifnull(iavl.abc_class, 'E')  abc_class, ioh.uom_code ," +
    " ifnull(ioh.locator_id, '0') locator_id ,  ioh.sub_inventory sub_inventory " +
    " from     inv_abc_val_line_ev iavl," +
    "inv_onhand_v ioh " +
    " where iavl.inv_item_master_id = ioh.inv_item_master_id " +
    " AND  iavl.vv_inv_org_id = ioh.inv_org_id " +
    " AND iavl.inv_abc_val_header_id =  '" +
    invAbcValHeaderId +
    "'";

  return countSql;
}
