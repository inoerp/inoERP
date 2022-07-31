//Modified values
// 1. Line Categories
// let lineMap = {
//   glLedgerId: row["vvGlLedgerId"],
//   referenceEntityName: "ar_transaction_line",
//   referenceKeyName: "ar_transaction_line_id",
//   referenceKeyValue: row["arTransactionLineId"],
//   pSrcEntityName: "ar_transaction_header",
//   pSrcKeyName: "ar_transaction_header_id",
//   pSrcKeyValue: row["arTransactionHeaderId"],
//   amount: row["vvLineAmount"],
//   lineCategory: row["lineCategory"],
// };

function beforePatch(inputData) {
  let data = inputData["data"];
  let action = data["action"];
 if (action == "create_accounting") {
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

  let allLines = findLinesToBeAccounted(data);
  let journalTemplateLines = getAllJournalProfiles(data);
  let allAccountProfiles = getAllAccountProfiles(data);
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
      "ar_transaction",
      "ar_transaction",
      "AR",
      "Receivable Transaction",
      "A",
      allLines,
      journalTemplateLines,
      allAccountProfiles,
      "-1",
      "accounting_completed",
      accountingType
    );

    if(accountingType == "draft"){
      let arTransactionHeaderId = "";
      if (data["arTransactionHeaderId"]) {
        arTransactionHeaderId = data["arTransactionHeaderId"].toString();
      }
      h.headerData = {
        pSrcEntityName: "ar_transaction_header",
        pSrcKeyName: "ar_transaction_header_id",
        pSrcKeyValue: arTransactionHeaderId,
        referenceEntityName: "ar_transaction_line",
      };
    }


    retDataMap["rd_proceed_message"] = h.createAccounting();
  } else {
    retDataMap["rd_proceed_message"] = "No lines to be accounted";
  }
  return retDataMap;
}

function findLinesToBeAccounted(dataObject) {
  let selectSql =
    "SELECT * from ar_transaction_line_unaccounted_v where accounting_status = 'not_accounted'";

  if (dataObject["vvBuOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["vvBuOrgId"] + "'";
  } else if (dataObject["buOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["buOrgId"] + "'";
  }

  if (dataObject["arTransactionHeaderId"]) {
    selectSql +=
      " AND ar_transaction_header_id = '" +
      dataObject["arTransactionHeaderId"] +
      "'";
  }

  let rows = getDataFromSql(selectSql);
  let lines = [];
  if (rows.length > 0) {
    for (let i = 0; i < rows.length; i++) {
      let row = rows[i];
      let lineMap = {
        glLedgerId: row["vvGlLedgerId"],
        referenceEntityName: "ar_transaction_line",
        referenceKeyName: "ar_transaction_line_id",
        referenceKeyValue: row["arTransactionLineId"],
        pSrcEntityName: "ar_transaction_header",
        pSrcKeyName: "ar_transaction_header_id",
        pSrcKeyValue: row["arTransactionHeaderId"],
        amount: row["vvLineAmount"],
        lineCategory: row["lineCategory"],
      };
      lines.push(lineMap);
    }
  }
  return lines;
}

function getAllAccountProfiles(dataObject) {
  let selectSql = "SELECT * FROM ar_transaction_ac_profile_v WHERE 1 = 1 ";

  if (dataObject["vvBuOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["vvBuOrgId"] + "'";
  } else if (dataObject["buOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["buOrgId"] + "'";
  }

  if (dataObject["arTransactionHeaderId"]) {
    selectSql +=
      " AND ar_transaction_header_id = '" +
      dataObject["arTransactionHeaderId"] +
      "'";
  }

  return getDataFromSql(selectSql);
}

function getAllJournalProfiles() {
  let selectSql =
    " SELECT gjpl.*       \
      FROM        inoerp.gl_journal_profile_l gjpl \
      join inoerp.gl_journal_profile_h gjph ON gjpl.gl_journal_profile_h_id =  gjph.gl_journal_profile_h_id \
      AND gjph.profile_code = 'ar_invoice ' ";

  return getDataFromSql(selectSql);
}

function completeOtherAction(dataObject, action) {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };
  let arTransactionHeaderId = "";
  if (dataObject["arTransactionHeaderId"]) {
    arTransactionHeaderId = dataObject["arTransactionHeaderId"];
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant delete as no prj RevenueDocHeader Id is found";
    return retDataMap;
  }

  let journalHeader = new glJournalHeader();
  journalHeader.headerData = {
    pSrcEntityName: "ar_transaction_header",
    pSrcKeyName: "ar_transaction_header_id",
    pSrcKeyValue: arTransactionHeaderId,
    referenceEntityName: "ar_transaction_line",
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
