function beforePatch(inputData) {
  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let request = inputData["request"];
  let data = inputData["data"];
  let action = data["action"];

  if (action == "js_fp_refresh_mds" || action == "js_fp_create_consumption") {
  } else {
    return data;
  }

  let fpMdsHeaderId = data["fpMdsHeaderId"];

  // Refresh MDS
  let refreshResult = 0;
  if (action == "js_fp_refresh_mds") {
    refreshResult = createMds(fpMdsHeaderId);
    if (refreshResult == 1) {
      createConsumption(fpMdsHeaderId) ;
      retDataMap["rd_proceed_message"] = "MDS is successfully refreshed";
    } else {
      retDataMap["rd_proceed_status"] = false;
      retDataMap["rd_proceed_message"] = "MDS Refresh Failed";
    }
  } else if (action == "js_fp_create_consumption") {
    createConsumption(fpMdsHeaderId);
    retDataMap["rd_proceed_message"] = "Consumption is successfully completed";
  }

  return retDataMap;
}

function createMds(fpMdsHeaderId) {
  let refreshResult = 0;
  let selectSql =
    " select inoerp.fpCreateMds(" + fpMdsHeaderId + ") as result   ";

  let sqlRequest = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let sqlResponse = sqlSelect(sqlRequest);
  let responseData = sqlResponse["data"];
  if (responseData.length > 0) {
    firstRow = responseData[0];
    refreshResult = firstRow["result"];
  }
  return refreshResult;
}

function createConsumption(fpMdsHeaderId) {
  let refreshResult = 0;
  let selectSql =
    " SELECT * from fp_mds_line_unconsumed_v where source_type = 'SO' and fp_mds_header_id = '" +
    fpMdsHeaderId +
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
      let quantityToBeConsumed = lineData["soUnconsumedQty"];
      let totalQuantityConsumed = 0;
      let sdSoDetailId = lineData["sdSoDetailId"];
      let demandDate = lineData["demandDate"];
      let invItemMasterId = lineData["invItemMasterId"];
      let invOrgId = lineData["vvInvOrgId"];
      let avlQtySql = getConsumptionSql(
        fpMdsHeaderId,
        invItemMasterId,
        demandDate
      );
      let avlQtySqlRequest = {
        sql: avlQtySql,
        dbType: "MySQL",
        connName: "Inoerp",
      };

      let avlQtyResponse = sqlSelect(avlQtySqlRequest);
      let avlQtyResponseData = avlQtyResponse["data"];

      if (avlQtyResponseData.length > 0) {
        for (let j = 0; j < avlQtyResponseData.length; j++) {
          const rowData = avlQtyResponseData[j];
          if (totalQuantityConsumed >= quantityToBeConsumed) {
            break;
          }
          let quantityConsumed = 0;
          if (quantityToBeConsumed > 0) {

            let avlQty = rowData["forecastAvailableQuantity"];
            let fpMdsLineId = rowData["fpMdsLineId"];
            let fpForecastDetailId = rowData["fpForecastDetailId"];
            if (avlQty > 0) {
              if (avlQty > quantityToBeConsumed) {
                quantityConsumed = quantityToBeConsumed;
                quantityToBeConsumed = 0;
              } else {
                quantityConsumed = avlQty;
                quantityToBeConsumed = quantityToBeConsumed - avlQty;
              }
              totalQuantityConsumed = totalQuantityConsumed + quantityConsumed;

              let insertSql =
                " INSERT INTO fp_mds_detail (fp_mds_line_id, sd_so_detail_id, fp_forecast_detail_id, consumption_quantity) " +
                " VALUES ('" +
                fpMdsLineId +
                "', '" +
                sdSoDetailId +
                "', '" +
                fpForecastDetailId +
                "', '" +
                quantityConsumed +
                "') ";

              let insertSqlRequest = {
                sql: insertSql,
                dbType: "MySQL",
                connName: "Inoerp",
              };
              let insertSqlResponse = sqlInsert(insertSqlRequest);
              let responseData = insertSqlResponse["data"];

            }
          }
        }
      }
    }
  }
  return refreshResult;
}

function getConsumptionSql(fpMdsHeaderId, invItemMasterId, demandDate) {
  let sql =
    " SELECT * from fp_mds_line_ev " +
    " where source_type = 'FORECAST' " +
    " and forecast_available_quantity > 0 " +
    " and inv_item_master_id = '" +
    invItemMasterId +
    "' " +
    " and demand_date < DATE('" +
    demandDate +
    "') + INTERVAL 45 DAY " +
    " and demand_date >  DATE('" +
    demandDate +
    "') - INTERVAL 30 DAY " +
    " and demand_date > now() " +
    " and fp_mds_header_id = '" +
    fpMdsHeaderId +
    "' " +
    " ORDER BY demand_date asc  ";

  return sql;
}
