function beforePatch(inputData) {
  let data = inputData["data"];
  let action = data["action"];
  if (action == "prj_update_draft_revenue") {
    return generateDraftRevenue(data, action);
  } else if (action == "create_accounting") {
    return createAccounting(data, "final");
  } else if (action == "create_draft_accounting") {
    return createAccounting(data, "draft");
  } else if (
    action == "delete_draft_accounting" ||
    action == "confirm_draft_accounting"
  ) {
    return completeOtherAction(data, action);
  } else {
    return data;
  }
}

function createAccounting(data, accountingType) {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };

  let allLines = findPrjRevenueLinesToBeAccounted(data);
  let journalTemplateLines = getJournalProfilesForPrjRevenue(data);
  let allAccountProfiles = getAllAccountProfilesForPrjRevenue(data);
  if (journalTemplateLines.length > 0) {
    //Validate if all lines have a profile
  } else {
    retDataMap["rd_proceed_message"] = "No journal profile found";
    return retDataMap;
  }

  if (allAccountProfiles.length > 0) {
    //Validate if all lines have a profile
  } else {
    retDataMap["rd_proceed_message"] = "No account profile found";
    return retDataMap;
  }
  if (allLines.length > 0) {
    const firstRow = allLines[0];
    // const glLedgerId = firstRow.glLedgerId;
    let h = new glJournalHeader(
      firstRow["glLedgerId"],
      "prj_revenue_recognition",
      "revenue_recognition",
      "PRJ",
      "Revenue Recognition",
      "A",
      allLines,
      journalTemplateLines,
      allAccountProfiles,
      "-1",
      "accounting_completed",
      accountingType
    );

    if(accountingType == "draft"){
      let prjRevenueDocHeaderId = "";
      if (data["prjRevenueDocHeaderId"]) {
        prjRevenueDocHeaderId = data["prjRevenueDocHeaderId"].toString();
      }
      h.headerData = {
        pSrcEntityName: "prj_revenue_doc_header",
        pSrcKeyName: "prj_revenue_doc_header_id",
        pSrcKeyValue: prjRevenueDocHeaderId,
        referenceEntityName: "prj_revenue_doc_line",
      };
    }


    retDataMap["rd_proceed_message"] = h.createAccounting();
  } else {
    retDataMap["rd_proceed_message"] = "No lines to be accounted";
  }
  return retDataMap;
}

function findPrjRevenueLinesToBeAccounted(dataObject) {
  let selectSql =
    "SELECT * from prj_revenue_doc_line_unaccounted_v where accounting_status = 'not_created'";

  if (dataObject["vvBuOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["vvBuOrgId"] + "'";
  } else if (dataObject["buOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["buOrgId"] + "'";
  }

  if (dataObject["prjRevenueDocHeaderId"]) {
    selectSql +=
      " AND prj_revenue_doc_header_id = '" +
      dataObject["prjRevenueDocHeaderId"] +
      "'";
  }

  let rows = getDataFromSql(selectSql);
  let lines = [];
  if (rows.length > 0) {
    for (let i = 0; i < rows.length; i++) {
      let row = rows[i];
      let lineMap = {
        glLedgerId: row["vvGlLedgerId"],
        referenceEntityName: "prj_revenue_doc_line",
        referenceKeyName: "prj_revenue_doc_line_id",
        referenceKeyValue: row["prjRevenueDocLineId"],
        pSrcEntityName: "prj_revenue_doc_header",
        pSrcKeyName: "prj_revenue_doc_header_id",
        pSrcKeyValue: row["prjRevenueDocHeaderId"],
        amount: row["revenueAmount"],
      };
      lines.push(lineMap);
    }
  }
  return lines;
}

function getAllAccountProfilesForPrjRevenue(dataObject) {
  let selectSql = "SELECT * FROM prj_revenue_ac_profile_v WHERE 1 = 1 ";

  if (dataObject["vvBuOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["vvBuOrgId"] + "'";
  } else if (dataObject["buOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["buOrgId"] + "'";
  }

  if (dataObject["prjRevenueDocHeaderId"]) {
    selectSql +=
      " AND prj_revenue_doc_header_id = '" +
      dataObject["prjRevenueDocHeaderId"] +
      "'";
  }

  return getDataFromSql(selectSql);
}

function getJournalProfilesForPrjRevenue() {
  let selectSql =
    " SELECT gjpl.*       \
      FROM        inoerp.gl_journal_profile_l gjpl \
      join inoerp.gl_journal_profile_h gjph ON gjpl.gl_journal_profile_h_id =  gjph.gl_journal_profile_h_id \
      AND gjph.profile_code = 'prj_expenditure' ";

  return getDataFromSql(selectSql);
}

function completeOtherAction(dataObject, action) {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };
  let prjRevenueDocHeaderId = "";
  if (dataObject["prjRevenueDocHeaderId"]) {
    prjRevenueDocHeaderId = dataObject["prjRevenueDocHeaderId"];
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant delete as no prj RevenueDocHeader Id is found";
    return retDataMap;
  }

  let journalHeader = new glJournalHeader();
  journalHeader.headerData = {
    pSrcEntityName: "prj_revenue_doc_header",
    pSrcKeyName: "prj_revenue_doc_header_id",
    pSrcKeyValue: prjRevenueDocHeaderId,
    referenceEntityName: "prj_revenue_doc_line",
  };

  if (action == "confirm_draft_accounting") {
    retDataMap = journalHeader.convertDraftToJournal();
    journalHeader.deleteDraftJournalLines();
  } else if (action == "delete_draft_accounting") {
    retDataMap = journalHeader.deleteDraftJournalLines();
  } else {
    retDataMap["rd_proceed_message"] = "Invalid action";
  }

  return retDataMap;
}

function xxdeleteDraftJournalLines(dataObject) {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };
  let deleteSql =
    "DELETE from gl_draft_journal_line \
    WHERE p_src_entity_name='prj_revenue_doc_header'  \
    AND p_src_entity_id_name='prj_revenue_doc_header_id'";

  let selectSql =
    "SELECT * from gl_draft_journal_line \
    WHERE p_src_entity_name='prj_revenue_doc_header'  \
    AND p_src_entity_id_name='prj_revenue_doc_header_id'";

  if (dataObject["prjRevenueDocHeaderId"]) {
    deleteSql +=
      " AND p_src_entity_id = '" + dataObject["prjRevenueDocHeaderId"] + "'";
    selectSql +=
      " AND p_src_entity_id = '" + dataObject["prjRevenueDocHeaderId"] + "'";
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant delete as no prjRevenueDocHeaderId is found";
    return retDataMap;
  }

  let rows = getDataFromSql(selectSql);
  let glDraftJournalHeaderId = 0;
  if (rows.length > 0) {
    glDraftJournalHeaderId = rows[0]["glDraftJournalHeaderId"];
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant delete as no journal lines are found";
    return retDataMap;
  }

  if (glDraftJournalHeaderId > 0) {
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant delete as no glJournalHeaderId are found";
    return retDataMap;
  }

  let headerDeleteSql =
    " DELETE from gl_draft_journal_header WHERE gl_draft_journal_header_id = '" +
    glDraftJournalHeaderId +
    "'";

  let lineData = deleteDataWithSql(deleteSql);
  let returnMessage = JSON.stringify(lineData);
  let headerData = deleteDataWithSql(headerDeleteSql);
  returnMessage += JSON.stringify(headerData);
  retDataMap["rd_proceed_message"] = returnMessage;
  return retDataMap;
}

function xxconvertDraftToJournal(dataObject) {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };
  let prjRevenueDocHeaderId = 0;
  if (dataObject["prjRevenueDocHeaderId"]) {
    prjRevenueDocHeaderId = dataObject["prjRevenueDocHeaderId"];
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant delete as no prjRevenueDocHeaderId is found";
    return retDataMap;
  }

  let insertSql =
    " INSERT INTO `inoerp`.`gl_journal_header` (`gl_ledger_id`, `gl_period_id`, `journal_source`, \
    `journal_category`, `journal_name`,     `description`, `balance_type`, `status`, `doc_status`, \
    `gl_draft_journal_header_id`) \
    SELECT gl_ledger_id, gl_period_id, journal_source, journal_category, journal_name, description, \
     balance_type, status, doc_status,gl_draft_journal_header_id \
     from gl_draft_journal_header WHERE gl_draft_journal_header_id IN ( \
       SELECT   `gl`.`gl_draft_journal_header_id` AS `gl_draft_journal_header_id` \
            FROM \
                (`gl_draft_journal_line` `gl` \
            JOIN `prj_revenue_doc_header` `rheader`) \
            WHERE \
                ((`gl`.`p_src_entity_name` = 'prj_revenue_doc_header') \
                    AND (`gl`.`p_src_entity_id_name` = 'prj_revenue_doc_header_id') \
                    AND (`gl`.`p_src_entity_id` = `rheader`.`prj_revenue_doc_header_id`) \
                    AND  `rheader`.`prj_revenue_doc_header_id` = '" +
    prjRevenueDocHeaderId +
    "')  \
                    ORDER BY gl_draft_journal_header_id desc ) LIMIT 1 ";

  let headerInsertResponse = insertDataWithSql(insertSql);
  if (headerInsertResponse.length > 0) {
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant insert as no journal header is found";
    return retDataMap;
  }
  let headerFirstRow = headerInsertResponse[0];
  let glJournalHeaderId = headerFirstRow["lastInsertId"];
  if (glJournalHeaderId > 0) {
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant convert as no glJournalHeaderId is found";
    return retDataMap;
  }

  let lineSql =
    "INSERT INTO `inoerp`.`gl_journal_line` (`gl_journal_header_id`, `reference_entity_name`, \
   `reference_key_name`, `reference_key_value`, `src_entity_name`,   `src_entity_id_name`, `src_entity_id`, \
    `line_num`, `p_src_entity_name`, `p_src_entity_id_name`, `p_src_entity_id`, `gl_ac_id`, `amount`, `dr_cr`, \
     `gl_draft_journal_line_id`) \
    SELECT '" +
    glJournalHeaderId +
    "', gl.reference_entity_name, gl.reference_key_name, gl.reference_key_value, gl.src_entity_name, \
  gl.src_entity_id_name, gl.src_entity_id, gl.line_num, gl.p_src_entity_name, gl.p_src_entity_id_name, \
   gl.p_src_entity_id, gl.gl_ac_id, gl.amount, gl.dr_cr,gl_draft_journal_line_id \
       FROM \
           (`gl_draft_journal_line` `gl` \
       JOIN `prj_revenue_doc_header` `rheader`) \
       WHERE \
           ((`gl`.`p_src_entity_name` = 'prj_revenue_doc_header') \
               AND (`gl`.`p_src_entity_id_name` = 'prj_revenue_doc_header_id')  \
               AND (`gl`.`p_src_entity_id` = `rheader`.`prj_revenue_doc_header_id`)) ";

  let lineInsertResponse = insertDataWithSql(lineSql);
  if (lineInsertResponse.length > 0) {
    retDataMap["rd_proceed_message"] = JSON.stringify(lineInsertResponse);
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant insert as no journal lines are found";
  }

  //update accounting status
  let updateSql =
    "UPDATE prj_revenue_doc_line SET accounting_status = 'accounting_completed' \
  WHERE prj_revenue_doc_header_id = '" +
    prjRevenueDocHeaderId +
    "';";
  let updateResponse = updateDataWithSql(updateSql);
  retDataMap["rd_proceed_message"] += JSON.stringify(updateResponse);
  return retDataMap;
}

function xxxdeleteDraftJournalLines(dataObject) {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };
  let prjRevenueDocHeaderId = "";
  if (dataObject["prjRevenueDocHeaderId"]) {
    prjRevenueDocHeaderId = dataObject["prjRevenueDocHeaderId"];
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant delete as no prj RevenueDocHeader Id is found";
    return retDataMap;
  }

  let journalHeader = new glJournalHeader();
  journalHeader.headerData = {
    pSrcEntityName: "prj_revenue_doc_header",
    pSrcKeyName: "prj_revenue_doc_header_id",
    pSrcKeyValue: prjRevenueDocHeaderId,
    referenceEntityName: "prj_revenue_doc_line",
  };
  retDataMap = journalHeader.deleteDraftJournalLines();

  return retDataMap;
}
