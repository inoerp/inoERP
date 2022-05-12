// 1	If demand = supply	Reset
// 2	If total demand > total supply 	Reschdeule In	next supply date < lead time
// 		Planned Order

// 3	if total demand < total supply	Reschedule Out

// End	if Reschedule Out >0	Cancel

// totalDemand
// totalSupply	check all the supplies before demandData
// totalSupplyOneLt	check all the supplies before demandData+LeadTime
// rescheduleOutMap
// matchingStartDate

// **Reset**
// Once the Planned Order is created total demand = total supply = 0
// Reschedule Out Id arrays = 0
// Planning Start date = Planned Order creation date
// **Reschedule In**
// Add to rescheduleIn ArrayMap
// Planned Order	Reschedule Out	Cancel
// Planned Order : requirementDate, quantity

function beforePatch(inputData) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let request = inputData["request"];
  let data = inputData["data"];
  let action = data["action"];

  if (
    action == "js_fp_mrp_collect_demand_data" ||
    action == "js_fp_mrp_create_low_level_code" ||
    action == "js_fp_mrp_collect_supply_data" ||
    action == "js_fp_mrp_create_planned_orders" ||
    action == "js_fp_run_full_mrp" ||
    action == "js_fp_mrp_release_planned_order"
  ) {
  } else {
    return data;
  }

  let fpMrpHeaderId = data["fpMrpHeaderId"];

  // Refresh MRP
  let refreshResult = 0;
  if (action == "js_fp_run_mrp" || action == "js_fp_run_full_mrp") {
    createMRP(fpMrpHeaderId, 0);
    // refreshResult = collectDemandData(fpMrpHeaderId);
    // if (refreshResult == 1) {
    //   createLowLevelCode(fpMrpHeaderId);
    //   retDataMap["rd_proceed_message"] = "MRP data is successfully collected";
    // } else {
    //   retDataMap["rd_proceed_status"] = false;
    //   retDataMap["rd_proceed_message"] = "MRP Refresh Failed";
    // }
  } else if (action == "js_fp_mrp_collect_demand_data") {
    collectDemandData(fpMrpHeaderId);
    retDataMap["rd_proceed_message"] =
      "MRP demand data is successfully collected";
  } else if (action == "js_fp_mrp_collect_supply_data") {
    collectSupplyData(fpMrpHeaderId);
    retDataMap["rd_proceed_message"] =
      "MRP supply data is successfully collected";
  } else if (action == "js_fp_mrp_create_low_level_code") {
    createLowLevelCode(fpMrpHeaderId);
    retDataMap["rd_proceed_message"] =
      "Low level codes are successfully created";
  }

  return retDataMap;
}

function createMRP(fpMrpHeaderId, lowLevelCode) {
  let demandRowsMap = {};
  let supplyRowsMap = {};
  let demandSql =
    " SELECT * FROM inoerp.fp_mrp_demand     WHERE demand_date < now() + INTERVAL 365 DAY " +
    " AND fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' " +
    " AND inv_item_master_id in (SELECT inv_item_master_id from fp_mrp_lowlevel_code where low_level = '" +
    lowLevelCode +
    "') " +
    " ORDER BY inv_item_master_id, demand_date asc  ";

  let supplySql =
    " SELECT * FROM inoerp.fp_mrp_supply     WHERE supply_date < now() + INTERVAL 365 DAY " +
    " AND fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' " +
    " AND inv_item_master_id in (SELECT inv_item_master_id from fp_mrp_lowlevel_code where low_level = '" +
    lowLevelCode +
    "') " +
    " ORDER BY inv_item_master_id, demand_date asc  ";

  let demandRequest = {
    sql: demandSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let supplyRequest = {
    sql: demandSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let demandResponse = sqlSelect(demandRequest);
  let demandData = demandResponse["data"];
  if (demandData.length > 0) {
    let addedItems = [];
    for (let index = 0; index < demandData.length; index++) {
      const element = demandData[index];
      let invItemMasterId = element["invItemMasterId"];
      if (addedItems.indexOf(invItemMasterId) == -1) {
        addedItems.push(invItemMasterId);
        demandRowsMap[invItemMasterId] = [];
      }
      demandRowsMap[invItemMasterId].push(element);
    }
  }

  let supplyResponse = sqlSelect(supplyRequest);
  let supplyData = supplyResponse["data"];
  if (supplyData.length > 0) {
    let addedItems = [];
    for (let index = 0; index < supplyData.length; index++) {
      const element = supplyData[index];
      let invItemMasterId = element["invItemMasterId"];
      if (addedItems.indexOf(invItemMasterId) == -1) {
        addedItems.push(invItemMasterId);
        supplyRowsMap[invItemMasterId] = [];
      }
      supplyRowsMap[invItemMasterId].push(element);
    }
  }

  let completedSupplyRowIds = [];

  for (const key in demandRowsMap) {
    if (demandRowsMap.hasOwnProperty(key)) {
      const demandRows = demandRowsMap[key];
      let invItemMasterId = key;
      let supplyRows = supplyRowsMap[invItemMasterId];
      matchDemandSupply(invItemMasterId, demandRows, supplyRows);
      completedSupplyRowIds.push(invItemMasterId);
    }
  }

  //TODO create cancel message for extra supply rows

  //consoleLog("\n\n demandRows: " + JSON.stringify(demandRowsMap));
}

function matchDemandSupply(invItemMasterId, demandRows, supplyRows) {
  let plannedOrderList = [];
  let rescheduleInList = []; //reschedule out list
  let rescheduleOutList = []; //reschedule out list
  let finalRescheduleOutList = [];
  //if supply rows exists
  if (supplyRows != undefined) {
    let totalDemand = 0;
    let totalSupply = 0; //total supply for the item before demand date
    let totalSupplyOneLt = 0; //total supply for the item before demand date + 1 lead time
    //reschedule out list
    let finalPlannedOrderList = [];
    let existingPlannedOrderQty = 0;
    let existingRescheduleInQty = 0;
    let existingRescheduleOutQty = 0;
    let matchingStartDate = "";
    let matchedSupplyIndex = 0;
    for (let index = 0; index < demandRows.length; index++) {
      let demandElement = demandRows[index];
      let demandDate = new Date(demandElement["demandDate"]);
      let demandQty = demandElement["quantity"];
      let fpMrpDemandId = demandElement["fpMrpDemandId"];
      totalDemand += demandQty;
      if (index == 0) {
        matchingStartDate = demandDate;
      }

      let matchSupplyIndexIncrement = 0;
      for (let j = matchedSupplyIndex; j < supplyRows.length; j++) {
        const supplyElement = supplyRows[j];
        let supplyDate = new Date(supplyElement["supplyDate"]);
        if (supplyDate > demandDate) {
          break;
        }
        let supplyQty = supplyElement["quantity"];
        totalSupply += supplyQty;
        let fpMrpSupplyId = supplyElement["fpMrpSupplyId"];
        matchSupplyIndexIncrement++;
      }

      if (totalSupply == totalDemand) {
        //reset
        totalDemand = 0;
        totalSupply = 0;
        totalSupplyOneLt = 0;
        if (rescheduleOutList.length > 0) {
          for (let x = 0; x < rescheduleOutList.length; x++) {
            const element = array[x];
            element["rescheduledDate"] = matchingStartDate;
            finalRescheduleOutList.push(element);
          }
        }
        rescheduleOutList = [];
        matchingStartDate = demandDate;
        existingRescheduleOutQty = 0;
      } else if (totalSupply > totalDemand) {
        let rescheduleOutQty = totalSupply - totalDemand;
        //convert existing planned order to reschedule in
        let convertedPlannedOrderQty = 0;
        if (plannedOrderList.length > 0) {
          let rescheduleOutQtyAvailableForConversion = rescheduleOutQty;
          for (let x = 0; x < plannedOrderList.length; x++) {
            if (rescheduleOutQtyAvailableForConversion <= 0) {
              break;
            }
            let plannedOrderElement = plannedOrderList[x];
            let plannedOrderQty = plannedOrderElement["quantity"];
            let plannedOrderDate = plannedOrderElement["requirementDate"];
            let currentPlannedOrderConvertedQty = 0;
            if (plannedOrderQty <= rescheduleOutQtyAvailableForConversion) {
              //find the extra supply and reschedule in
              for (let k = matchSupplyIndexIncrement; k >= 0; k--) {
                if ((currentPlannedOrderConvertedQty) => plannedOrderQty) {
                  plannedOrderList.splice(x, 1);
                  break;
                }
                let availableElement = supplyRows[matchedSupplyIndex + k];
                let availableElementQty = availableElement["quantity"];
                if (availableElementQty == plannedOrderQty) {
                  availableElement["quantity"] = 0;
                  availableElement["rescheduledQuantity"] = availableElementQty;
                  availableElement["rescheduledType"] = "in";
                  availableElement["rescheduledDate"] = plannedOrderDate;
                  rescheduleInList.push(availableElement);
                  convertedPlannedOrderQty += availableElementQty;
                  plannedOrderList.splice(x, 1);
                  break;
                } else if (availableElementQty > plannedOrderQty) {
                  availableElement["quantity"] =
                    availableElementQty - plannedOrderQty;
                  availableElement["rescheduledQuantity"] = plannedOrderQty;
                  availableElement["rescheduledType"] = "in";
                  availableElement["rescheduledDate"] = plannedOrderDate;
                  rescheduleInList.push(availableElement);
                  convertedPlannedOrderQty += plannedOrderQty;
                  plannedOrderList.splice(x, 1);
                  break;
                } else if (availableElementQty < plannedOrderQty) {
                  availableElement["quantity"] = 0;
                  availableElement["rescheduledQuantity"] = availableElementQty;
                  availableElement["rescheduledType"] = "in";
                  availableElement["rescheduledDate"] = plannedOrderDate;
                  rescheduleInList.push(availableElement);
                  convertedPlannedOrderQty += availableElementQty;
                  currentPlannedOrderConvertedQty += availableElementQty;
                  plannedOrderElement["quantity"] =
                    plannedOrderQty - availableElementQty;
                }
              }
            }
          }
        }

        //reschedule out
        rescheduleOutQty = rescheduleOutQty - convertedPlannedOrderQty;
        existingRescheduleOutQty =
          existingRescheduleOutQty - convertedPlannedOrderQty;
        if (rescheduleOutQty <= 0) {
          break;
        }
        if (existingRescheduleOutQty > rescheduleOutQty) {
          rescheduleOutQty = 0;
        } else {
          rescheduleOutQty = rescheduleOutQty - existingRescheduleOutQty;
        }
        let rescheduleOutQtyAvailableQty = rescheduleOutQty;
        if (rescheduleOutQtyAvailableQty > 0) {
          for (let k = matchSupplyIndexIncrement; k >= 0; k--) {
            if (rescheduleOutQtyAvailableQty <= 0) {
              break;
            }
            let availableElement = supplyRows[matchedSupplyIndex + k];
            let availableElementQty = availableElement["quantity"];
            if (availableElementQty > rescheduleOutQtyAvailableQty) {
              rescheduleOutQtyAvailableQty = 0;
              availableElement["rescheduledQuantity"] =
                rescheduleOutQtyAvailableQty;
            } else {
              rescheduleOutQtyAvailableQty =
                rescheduleOutQtyAvailableQty - availableElementQty;
              availableElement["rescheduledQuantity"] = availableElementQty;
            }
            existingRescheduleOutQty =
              existingRescheduleOutQty +
              availableElement["rescheduledQuantity"];
            rescheduleOutList.push(availableElement);
          }
        }
      } else if (totalSupply < totalDemand) {
        //total supply < total demand
        //reschedule in or create new supply
        //Create planned order for all demands
        let plannedOrderQty = totalSupply - totalDemand;
        let plannedOrder = {};
        for (const key in demandElement) {
          if (demandElement.hasOwnProperty(key)) {
            plannedOrder[key] = demandElement[key];
          }
        }
        plannedOrder["quantity"] = plannedOrderQty;
        plannedOrder["requirementDate"] = demandDate;
      }

      matchedSupplyIndex += matchSupplyIndexIncrement;
    }
  } else {
    //Create planned order for all demands
    let plannedOrderQty = totalDemand;
    let plannedOrder = {};
    for (const key in demandElement) {
      if (demandElement.hasOwnProperty(key)) {
        plannedOrder[key] = demandElement[key];
      }
    }
    plannedOrder["quantity"] = plannedOrderQty;
    plannedOrder["requirementDate"] = demandDate;
  }

  //TODO create planned order for all demands
  //TODO create exception messages
  //TODO create reschedule in and reschedule out messages
  if(plannedOrderList.length > 0 ){
    consoleLog("\n\n plannedOrderList", plannedOrderList.length);
  }
  if(rescheduleInList.length > 0 ){
    consoleLog("\n\n rescheduleInList", rescheduleInList.length);
  }
  if(rescheduleOutList.length > 0){
    consoleLog("\n\n rescheduleOutList", rescheduleOutList.length);
  }
  if(finalRescheduleOutList.length > 0){
    consoleLog("\n\n finalRescheduleOutList", finalRescheduleOutList.length);
  }
}

function collectDemandData(fpMrpHeaderId) {
  //delete existing demands
  let deleteSql =
    " DELETE from fp_mrp_demand " +
    " WHERE fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' " +
    " ) ";

  let deleteRequest = {
    sql: deleteSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  sqlDelete(deleteRequest);

  let insertSql =
    " INSERT INTO fp_mrp_demand (fp_mrp_header_id, inv_org_id, inv_item_master_id, demand_date, quantity, " +
    " mrp_demand_type, toplevel_demand_item_id_m, source_type, sd_so_detail_id, fp_forecast_detail_id) " +
    " SELECT '" +
    fpMrpHeaderId +
    "', mdl.vv_inv_org_id, mdl.inv_item_master_id, mdl.demand_date, mdl.quantity, 'independent', " +
    " mdl.inv_item_master_id, mdl.source_type, mdl.sd_so_detail_id, mdl.fp_forecast_detail_id " +
    " from fp_source_list_line fsll , " +
    "  fp_source_list_header fslh, " +
    "  fp_mds_line_ev mdl, " +
    "   fp_mrp_header fmh " +
    " where fslh.fp_source_list_header_id =fsll.fp_source_list_header_id " +
    " AND fsll.fp_source_list_header_id =fmh.mrp_source_list_id " +
    " AND mdl.fp_mds_header_id = fsll.fp_mds_header_id " +
    " AND mdl.quantity > 0 " +
    " AND mdl.source_type = 'SO' " +
    " AND fmh.fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' ";

  let insertSqlRequest = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let insertSqlResponse = sqlInsert(insertSqlRequest);
  let responseData = insertSqlResponse["data"];

  insertSql =
    " INSERT INTO fp_mrp_demand (fp_mrp_header_id, inv_org_id, inv_item_master_id, demand_date, quantity, " +
    " mrp_demand_type, toplevel_demand_item_id_m, source_type, sd_so_detail_id, fp_forecast_detail_id) " +
    " SELECT '" +
    fpMrpHeaderId +
    "', mdl.vv_inv_org_id, mdl.inv_item_master_id, mdl.demand_date, mdl.forecast_available_quantity, 'independent', " +
    " mdl.inv_item_master_id, mdl.source_type, mdl.sd_so_detail_id, mdl.fp_forecast_detail_id " +
    " from fp_source_list_line fsll , " +
    "  fp_source_list_header fslh, " +
    "  fp_mds_line_ev mdl, " +
    "   fp_mrp_header fmh " +
    " where fslh.fp_source_list_header_id =fsll.fp_source_list_header_id " +
    " AND fsll.fp_source_list_header_id =fmh.mrp_source_list_id " +
    " AND mdl.fp_mds_header_id = fsll.fp_mds_header_id " +
    " AND mdl.forecast_available_quantity > 0 " +
    " AND mdl.source_type = 'FORECAST' " +
    " AND fmh.fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' ";

  insertSqlRequest = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  insertSqlResponse = sqlInsert(insertSqlRequest);
  responseData = insertSqlResponse["data"];

  return 1;
}

function collectSupplyData(fpMrpHeaderId) {
  //delete existing supplies
  let deleteSql =
    " DELETE from fp_mrp_supply " +
    " WHERE fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' ";

  let deleteRequest = {
    sql: deleteSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  sqlDelete(deleteRequest);

  let selectSql =
    " SELECT * " +
    " FROM inoerp.fp_mrp_header " +
    " WHERE fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' ";

  let sqlRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let sqlResponse = sqlSelect(sqlRequest);
  let responseData = sqlResponse["data"];
  let invOrgId = 0;
  if (responseData.length > 0) {
    let firstRow = responseData[0];
    invOrgId = firstRow["invOrgId"];
  }
  if (invOrgId > 0) {
    let insertSql =
      " INSERT INTO fp_mrp_supply (fp_mrp_header_id, inv_org_id, inv_item_master_id, supply_date, quantity,  onhand_id) " +
      " SELECT '" +
      fpMrpHeaderId +
      "', '" +
      invOrgId +
      "', inv_item_master_id, CURRENT_TIMESTAMP, onhand,  onhand_id " +
      " FROM inv_onhand " +
      " WHERE inv_org_id  = '" +
      invOrgId +
      "' " +
      " AND inv_item_master_id IN (SELECT distinct(low.inv_item_master_id)" +
      " FROM inoerp.fp_mrp_lowlevel_code low, " +
      " fp_mrp_header fmh " +
      " WHERE fmh.inv_org_id = low.inv_org_id " +
      " AND fmh.fp_mrp_header_id = '" +
      fpMrpHeaderId +
      "' ) ";

    let insertSqlRequest = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    sqlInsert(insertSqlRequest);
  }

  collectPoPendingReceipts(fpMrpHeaderId, invOrgId);
  collectPoPendingDelivery(fpMrpHeaderId, invOrgId);
  collectOpenWorkOrders(fpMrpHeaderId, invOrgId);
  collectPoOpenRequisitions(fpMrpHeaderId, invOrgId);

  return 1;
}

function collectPoOpenRequisitions(fpMrpHeaderId, invOrgId) {
  if (invOrgId > 0) {
    let insertSql =
      " INSERT INTO fp_mrp_supply (fp_mrp_header_id, inv_org_id, inv_item_master_id, supply_type, supply_date, quantity,  po_requisition_detail_id) " +
      " SELECT '" +
      fpMrpHeaderId +
      "', '" +
      invOrgId +
      "', inv_item_master_id, 'purchase_requisition' , need_by_date, quantity,  po_requisition_detail_id " +
      " FROM po_open_requisition_v " +
      " WHERE receiving_org_id  = '" +
      invOrgId +
      "' " +
      " AND inv_item_master_id IN (SELECT distinct(low.inv_item_master_id)" +
      " FROM inoerp.fp_mrp_lowlevel_code low, " +
      " fp_mrp_header fmh " +
      " WHERE fmh.inv_org_id = low.inv_org_id " +
      " AND fmh.fp_mrp_header_id = '" +
      fpMrpHeaderId +
      "' ) ";

    consoleLog("\n\n collectPoPendingReceipts insertSql: " + insertSql);

    let insertSqlRequest = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    sqlInsert(insertSqlRequest);
  }

  return 1;
}

function collectPoPendingReceipts(fpMrpHeaderId, invOrgId) {
  if (invOrgId > 0) {
    let insertSql =
      " INSERT INTO fp_mrp_supply (fp_mrp_header_id, inv_org_id, inv_item_master_id, supply_type, supply_date, quantity,  po_detail_id) " +
      " SELECT '" +
      fpMrpHeaderId +
      "', '" +
      invOrgId +
      "', inv_item_master_id, 'purchase_order' , ifnull(promise_date, need_by_date), receipt_quantity,  po_detail_id " +
      " FROM po_pending_receipts_v " +
      " WHERE receiving_org_id  = '" +
      invOrgId +
      "' " +
      " AND inv_item_master_id IN (SELECT distinct(low.inv_item_master_id)" +
      " FROM inoerp.fp_mrp_lowlevel_code low, " +
      " fp_mrp_header fmh " +
      " WHERE fmh.inv_org_id = low.inv_org_id " +
      " AND fmh.fp_mrp_header_id = '" +
      fpMrpHeaderId +
      "' ) ";

    consoleLog("\n\n collectPoPendingReceipts insertSql: " + insertSql);

    let insertSqlRequest = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    sqlInsert(insertSqlRequest);
  }

  return 1;
}

function collectPoPendingDelivery(fpMrpHeaderId, invOrgId) {
  if (invOrgId > 0) {
    let insertSql =
      " INSERT INTO fp_mrp_supply (fp_mrp_header_id, inv_org_id, inv_item_master_id, supply_type, supply_date, quantity,  po_detail_id) " +
      " SELECT '" +
      fpMrpHeaderId +
      "', '" +
      invOrgId +
      "', inv_item_master_id,  'purchase_order' ,  ifnull(promise_date, need_by_date), quantity,  po_detail_id " +
      " FROM po_pending_delivery_v " +
      " WHERE receiving_org_id  = '" +
      invOrgId +
      "' " +
      " AND inv_item_master_id IN (SELECT distinct(low.inv_item_master_id)" +
      " FROM inoerp.fp_mrp_lowlevel_code low, " +
      " fp_mrp_header fmh " +
      " WHERE fmh.inv_org_id = low.inv_org_id " +
      " AND fmh.fp_mrp_header_id = '" +
      fpMrpHeaderId +
      "' ) ";

    consoleLog("\n\n collectPoPendingDelivery insertSql: " + insertSql);

    let insertSqlRequest = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    sqlInsert(insertSqlRequest);
  }

  return 1;
}

function collectOpenWorkOrders(fpMrpHeaderId, invOrgId) {
  if (invOrgId > 0) {
    let insertSql =
      " INSERT INTO fp_mrp_supply (fp_mrp_header_id, inv_org_id, inv_item_master_id, supply_type, supply_date, quantity,  wip_wo_header_id) " +
      " SELECT '" +
      fpMrpHeaderId +
      "', '" +
      invOrgId +
      "', inv_item_master_id,  'work_order' ,  completion_date, nettable_quantity - ifnull(vv_completed_quantity,0)- ifnull(vv_scrap_quantity,0) , " +
      " wip_wo_header_id " +
      " FROM wip_wo_header_ev " +
      " WHERE inv_org_id  = '" +
      invOrgId +
      "' " +
      " AND inv_item_master_id IN (SELECT distinct(low.inv_item_master_id)" +
      " FROM inoerp.fp_mrp_lowlevel_code low, " +
      " fp_mrp_header fmh " +
      " WHERE fmh.inv_org_id = low.inv_org_id " +
      " AND fmh.fp_mrp_header_id = '" +
      fpMrpHeaderId +
      "' ) ";

    consoleLog("\n\n collectOpenWorkOrders insertSql: " + insertSql);

    let insertSqlRequest = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    sqlInsert(insertSqlRequest);
  }

  return 1;
}

function createLowLevelCode(fpMrpHeaderId) {
  //delete existing codes
  let deleteSql =
    " DELETE from fp_mrp_lowlevel_code " +
    " WHERE inv_org_id IN ( SELECT inv_org_id from fp_mrp_header where fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "') " +
    " AND inv_item_master_id IN ( " +
    " SELECT distinct(inv_item_master_id) " +
    " FROM inoerp.fp_mrp_demand " +
    " WHERE mrp_demand_type = 'independent' " +
    " AND fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' " +
    " ) ";

  let deleteRequest = {
    sql: deleteSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let deleteResponse = sqlDelete(deleteRequest);

  //create new codes for low level 0
  let insertSql =
    " INSERT INTO fp_mrp_lowlevel_code (inv_item_master_id,inv_org_id,  parent_item_master_id, low_level) " +
    " SELECT distinct(inv_item_master_id) inv_item_master_id, inv_org_id, inv_item_master_id , 0 " +
    " FROM inoerp.fp_mrp_demand " +
    " WHERE mrp_demand_type = 'independent'" +
    " AND fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' ";

  let insertSqlRequest = {
    sql: insertSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  let insertSqlResponse = sqlInsert(insertSqlRequest);
  //create new codes for low level 1+
  let selectSql =
    " SELECT distinct(inv_item_master_id) inv_item_master_id, inv_org_id " +
    " FROM inoerp.fp_mrp_demand " +
    " WHERE mrp_demand_type = 'independent'  " +
    " AND fp_mrp_header_id = '" +
    fpMrpHeaderId +
    "' ";

  let sqlRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let sqlResponse = sqlSelect(sqlRequest);
  let responseData = sqlResponse["data"];
  if (responseData.length > 0) {
    for (var i = 0; i < responseData.length; i++) {
      let lineData = responseData[i];
      let invItemMasterId = lineData["invItemMasterId"];
      let invOrgId = lineData["invOrgId"];
      if (invItemMasterId > 0 && invOrgId > 0) {
        createSecondLevelCode(invItemMasterId, invOrgId, 1);
      }
    }
  }

  return 1;
}

function createSecondLevelCode(invItemMasterId, invOrgId, lowLevelCode) {
  let selectSql =
    " SELECT component_item_id_m from bom_line_ev  " +
    " WHERE vv_fg_item_id_m = '" +
    invItemMasterId +
    "' " +
    " AND vv_inv_org_id = '" +
    invOrgId +
    "' ";

  let sqlRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let sqlResponse = sqlSelect(sqlRequest);
  let responseData = sqlResponse["data"];
  if (responseData.length > 0) {
    for (var i = 0; i < responseData.length; i++) {
      let lineData = responseData[i];
      let componentItemIdM = lineData["componentItemIdM"];
      if (componentItemIdM > 0) {
        let insertSql =
          " INSERT INTO fp_mrp_lowlevel_code (inv_item_master_id,inv_org_id,  parent_item_master_id, low_level) VALUES " +
          " ('" +
          componentItemIdM +
          "', '" +
          invOrgId +
          "', '" +
          invItemMasterId +
          "', '" +
          lowLevelCode +
          "') ON DUPLICATE KEY UPDATE low_level='" +
          lowLevelCode +
          "', parent_item_master_id='" +
          invItemMasterId +
          "' ";

        let insertSqlRequest = {
          sql: insertSql,
          dbType: "MySQL",
          connName: "Inoerp",
        };
        sqlInsert(insertSqlRequest);
        if (componentItemIdM > 0 && invOrgId > 0) {
          let nextLevelCode = lowLevelCode + 1;
          createSecondLevelCode(componentItemIdM, invOrgId, nextLevelCode);
        }
      }
    }
  }
}