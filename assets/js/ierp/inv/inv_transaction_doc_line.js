function beforeGet(inputData) {
  consoleLog("\n\nIn beforeGet 1 ");

  var data = inputData["data"];

  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message:
      "No lines found. Enter a document number on transaction header.",
  };

  let selectSql = "";

  let invTransactionDocHeaderId = data["invTransactionDocHeaderId"];

  if (data["poHeaderId"] > 0) {
    selectSql =
      "SELECT * from po_detail_tv where po_header_id = '" +
      data["poHeaderId"] +
      "' ";
  } else if (data["sdSoHeaderId"] > 0) {
    selectSql =
      " SELECT * from sd_so_detail_tv where vv_sd_so_header_id = '" +
      data["sdSoHeaderId"] +
      "' ";
  } else if (data["wipWoHeaderId"] > 0) {
    selectSql =
      " SELECT * from wip_wo_line_mat_tv where wip_wo_header_id  = '" +
      data["wipWoHeaderId"] +
      "' ";
  } else if (data["prjProjectHeaderId"] > 0) {
    selectSql =
      " SELECT * FROM inoerp.prj_project_all_mat_tv where prj_project_header_id  = '" +
      data["prjProjectHeaderId"] +
      "' ";
  }

  if (selectSql.length > 10) {
    let selectRequest = {
      sql: selectSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };

    let selectResponse = sqlSelect(selectRequest);
    let selectData = selectResponse["data"];

    let updatedData = [];

    for (let index = 0; index < selectData.length; index++) {
      const element = selectData[index];
      element["invTransactionDocHeaderId"] = invTransactionDocHeaderId;
      element["quantity"] = "";
      updatedData.push(element);
    }

    //consoleLog("before1 selectData " + JSON.stringify(updatedData));

    retDataMap = {
      rd_proceed_status: false,
      rd_data_contains_item: true,
      rd_proceed_message: { items: updatedData },
    };

    return retDataMap;
  }

  return retDataMap;
}

 function afterGet() {
  for (let index = 0; index < 10; index++) {
    console.log("\n\nIn afterGet 1 " + index);
  }
}

 function mainFunction() {
  console.log("\n\nIn mainFunction 1 ");
  setTimeout(function () {
    afterGet();
  }, 0);
  console.log("\n\nIn mainFunction 2 ");
}

mainFunction();
