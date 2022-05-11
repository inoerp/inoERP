function beforePatch(inputData) {
 
  let request = inputData["request"];
  let data = inputData["data"];
  let action = data["action"];

  var retDataMap = {
    rd_proceed_status: true,
    rd_proceed_message: data,
  };

  if(action == "js_inv_complete_abc_analysis"){

  }else{
    return data;
  }


  let invAbcValHeaderId = data["invAbcValHeaderId"];
  let invOrgId;
  let aPercentage = 0;
  let bPercentage = 0;
  let cPercentage = 0;
  let dPercentage = 0;
  let ePercentage = 0;

  let criteria = "ONHAND_QTY";

  let deleteSql =
    " DELETE " +
    " FROM inv_abc_val_line WHERE inv_abc_val_header_id  = '" +
    invAbcValHeaderId +
    "'";

  let deleteRequest = {
    sql: deleteSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let deleteResponse = sqlDelete(deleteRequest);

  let abcValSql =
    " SELECT inv_org_id  inv_org_id, ifnull(a_percentage, 0)  a_percentage, " +
    " ifnull(b_percentage, 0) b_percentage , ifnull(c_percentage, 0) c_percentage , " +
    " ifnull(d_percentage, 0) d_percentage, ifnull(e_percentage, 0)  e_percentage, criteria " +
    " FROM inv_abc_val_header WHERE inv_abc_val_header_id  = '" +
    invAbcValHeaderId +
    "'";

  let abcValRequest = {
    sql: abcValSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let abcValResponse = sqlSelect(abcValRequest);
  let abcValData = abcValResponse["data"];
  if (abcValData.length > 0) {
    firstRow = abcValData[0];
    invOrgId = firstRow["invOrgId"];
    aPercentage = firstRow["aPercentage"];
    bPercentage = firstRow["bPercentage"];
    cPercentage = firstRow["cPercentage"];
    dPercentage = firstRow["dPercentage"];
    ePercentage = firstRow["ePercentage"];
    criteria = firstRow["criteria"];
  }

 retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Valuation completed submitted",
  };


  if (!invOrgId) {
    retDataMap["rd_proceed_message"] = "Please select correct organization";
  }

  retMessage = createOhQtyValuation(
    invOrgId,
    invAbcValHeaderId,
    aPercentage,
    bPercentage,
    cPercentage,
    dPercentage,
    ePercentage,
    criteria
  );
  



  retDataMap["rd_proceed_message"] = "Valuation completed successfully";

  return retDataMap;
}

function createOhQtyValuation(
  invOrgId,
  invAbcValHeaderId,
  aPercentage,
  bPercentage,
  cPercentage,
  dPercentage,
  ePercentage,
  criteria
) {
  let totalNoOfItems = 0;
  let aItemsCount = 0;
  let bItemsCount = 0;
  let cItemsCount = 0;
  let dItemsCount = 0;
  let eItemsCount = 0;
  let countSql = getCountSql(criteria, invOrgId);

  let countRequest = {
    sql: countSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let countResponse = sqlSelect(countRequest);
  let countData = countResponse["data"];

  if (countData.length > 0) {
    totalNoOfItems = countData.length;
    aItemsCount = Math.ceil((totalNoOfItems * aPercentage) / 100);
    bItemsCount = Math.ceil((totalNoOfItems * bPercentage) / 100) + aItemsCount;
    cItemsCount = Math.ceil((totalNoOfItems * cPercentage) / 100) + bItemsCount;
    dItemsCount = Math.ceil((totalNoOfItems * dPercentage) / 100) + cItemsCount;
    eItemsCount = Math.ceil((totalNoOfItems * ePercentage) / 100) + dItemsCount;
    let completedCount = 0;
    let cumQuantity = 0;
    let cumValue = 0;
    let insertSql =
      " INSERT INTO `inoerp`.`inv_abc_val_line` (`inv_abc_val_header_id`, `seq_number`, `inv_item_master_id`, " +
      "`quantity`, `value`, `cum_quantity`, `cum_value`, `sys_suggested_abc`, `abc_class`) VALUES  ";
    while (completedCount < totalNoOfItems) {
      let currData = countData[completedCount];
      if (!isNaN(currData["onhand"])) {
        cumQuantity += parseFloat(currData["onhand"]);
      }
      if (!isNaN(currData["onhandValue"])) {
        cumValue += parseFloat(currData["onhandValue"]);
      }
      let abcClass = "E";
      if (completedCount < aItemsCount) {
        abcClass = "A";
      } else if (completedCount < bItemsCount) {
        abcClass = "B";
      } else if (completedCount < cItemsCount) {
        abcClass = "C";
      } else if (completedCount < dItemsCount) {
        abcClass = "D";
      }
      insertSql +=
        "('" +
        invAbcValHeaderId +
        "', '" +
        (completedCount + 1) +
        "', '" +
        currData["invItemMasterId"] +
        "', '" +
        currData["onhand"] +
        "', '" +
        currData["onhandValue"] +
        "', '" +
        cumQuantity +
        "', '" +
        cumValue +
        "', '" +
        abcClass +
        "', '" +
        abcClass +
        "')";

      if (completedCount < totalNoOfItems - 1) {
        insertSql += ",";
      }
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

function getCountSql(criteria, invOrgId){
  let countSql ;

  switch (criteria) {

    case "STD_COST":
      countSql =
      " SELECT inv_item_master_id, ifnull(onhand, 0) onhand, ifnull(cost, 0) cost, ifnull(onhand_value, 0) onhand_value, inv_org_id" +
      " FROM inoerp.inv_onhand_summary_v " +
      " WHERE inv_org_id =  '" +
      invOrgId +
      "'" +
      " ORDER by cost desc";
      break;
  


    case "ONHAND_VALUE":
      countSql =
      " SELECT inv_item_master_id, ifnull(onhand, 0) onhand, ifnull(cost, 0) cost, ifnull(onhand_value, 0) onhand_value, inv_org_id" +
      " FROM inoerp.inv_onhand_summary_v " +
      " WHERE inv_org_id =  '" +
      invOrgId +
      "'" +
      " ORDER by onhand_value desc";
      break;
  
    default:
      case "ONHAND_QTY":
          countSql =
          " SELECT inv_item_master_id, ifnull(onhand, 0) onhand, ifnull(cost, 0) cost, ifnull(onhand_value, 0) onhand_value, inv_org_id" +
          " FROM inoerp.inv_onhand_summary_v " +
          " WHERE inv_org_id =  '" +
          invOrgId +
          "'" +
          " ORDER by onhand desc";
      break;
  }

  return countSql;

}
