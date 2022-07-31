function beforePatch(inputData) {
  let data = inputData["data"];
  let action = data["action"];
  if (action == "prj_update_draft_revenue") {
    return generateDraftRevenue(data, action);
  } else if (action == "create_accounting") {
    return createAccounting(data);
  } else {
    return data;
  }
}

function createAccounting(data) {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };
  consoleLog("\n\n in createAccounting");
  return retDataMap;
  let allLines = findPrjRevenueLinesToBeAccounted(data);
  let journalTemplateLines = getJournalProfilesForPrjRevenue(data);
  let allAccountProfiles = getAllAccountProfilesForPrjRevenue(data);
  if (allLines.length > 0) {
    const vvGlLedgerId = allLines[0]["glLedgerId2"];
    let h = new glJournalHeader(
      vvGlLedgerId,
      "prj_revenue_recognition",
      "revenue_recognition",
      "PRJ",
      "Revenue Recognition",
      "A",
      allLines,
      journalTemplateLines,
      allAccountProfiles
    );
    h.createAccounting();
  }else{
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
      let line = new glJournalLine(
        -1,
        row["vvGlLedgerId"],
        "prj_revenue_doc_line",
        "prj_revenue_doc_line_id",
        row["prjRevenueDocLineId"],
        "prj_revenue_doc_header",
        "prj_revenue_doc_header_id",
        row["prjRevenueDocHeaderId"],
        row["revenueAmount"],
      );
      lines.push(line);
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
