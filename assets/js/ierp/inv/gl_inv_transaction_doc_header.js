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

  let allAccountProfiles = getAllAccountProfiles(data);

  if (allAccountProfiles.length > 0) {
    //Validate if all lines have a profile
  } else {
    retDataMap["rd_proceed_message"] = "No account profile found";
    return retDataMap;
  }

  if (allLines.length > 0) {
  } else {
    retDataMap["rd_proceed_message"] = "No lines to be accounted";
    return retDataMap;
  }

  const firstRow = allLines[0];
  
  const headerDocTransactionType =(firstRow["vvTransactionType"]);

  consoleLog("\n firstRow " + JSON.stringify(firstRow) + " headerDocTransactionType " + headerDocTransactionType.toString(  ));

  if(isNotNull(headerDocTransactionType)){

  }else{
    retDataMap["rd_proceed_message"] = "Transaction type is not defined";
    return retDataMap;
  }

  let journalTemplateLines = getAllJournalProfilesForInvTransaction(
    headerDocTransactionType
  );



//let journalTemplateLines =  getDataFromSql(selectSqlForJournalProfiles2);

  if (journalTemplateLines.length > 0) {
    //Validate if all lines have a profile
  } else {
    retDataMap["rd_proceed_message"] =
      "No journal profile found for inventory transaction line";
    return retDataMap;
  }

  // const glLedgerId = firstRow.glLedgerId;
  let h = new glJournalHeader(
    firstRow["glLedgerId"],
    "inv_transaction",
    "inv_transaction",
    "INV",
    "Inventory Transaction",
    "A",
    allLines,
    journalTemplateLines,
    allAccountProfiles,
    "-1",
    "accounting_completed",
    accountingType
  );

  if (accountingType == "draft") {
    let invTransactionDocHeaderId = "";
    if (data["invTransactionDocHeaderId"]) {
      invTransactionDocHeaderId = data["invTransactionDocHeaderId"].toString();
    }
    h.headerData = {
      pSrcEntityName: "inv_transaction_doc_header",
      pSrcKeyName: "inv_transaction_doc_header_id",
      pSrcKeyValue: invTransactionDocHeaderId,
      referenceEntityName: "inv_transaction_doc_line",
    };
  }

  retDataMap["rd_proceed_message"] = h.createAccounting();

  return retDataMap;
}

function findLinesToBeAccounted(dataObject) {
  let selectSqlForLinesToBeAccounted =
    "SELECT * from inv_transaction_doc_line_unaccounted_v where accounting_status = 'not_accounted'";

  if (dataObject["vvInvOrgId"]) {
    selectSqlForLinesToBeAccounted += " AND inv_org_id = '" + dataObject["vvInvOrgId"] + "'";
  } else if (dataObject["invOrgId"]) {
    selectSqlForLinesToBeAccounted += " AND inv_org_id = '" + dataObject["invOrgId"] + "'";
  }

  if (dataObject["invTransactionDocHeaderId"]) {
    selectSqlForLinesToBeAccounted +=
      " AND inv_transaction_doc_header_id = '" +
      dataObject["invTransactionDocHeaderId"] +
      "'";
  }

  let rows = getDataFromSql(selectSqlForLinesToBeAccounted);
  let lines = [];
  if (rows.length > 0) {
    for (let i = 0; i < rows.length; i++) {
      let row = rows[i];
      let lineMap = {
        glLedgerId: row["vvGlLedgerId"],
        referenceEntityName: "inv_transaction_doc_line",
        referenceKeyName: "inv_transaction_doc_line_id",
        referenceKeyValue: row["invTransactionDocLineId"],
        pSrcEntityName: "inv_transaction_doc_header",
        pSrcKeyName: "inv_transaction_doc_header_id",
        pSrcKeyValue: row["invTransactionDocHeaderId"],
        amount: row["vvLineAmount"],
        vvTransactionType: row["vvTransactionType"],
      };
      lines.push(lineMap);
    }
  }
  return lines;
}

function getAllAccountProfiles(dataObject) {
  let selectSqlForAccountProfile =
    "SELECT * FROM inv_transaction_doc_line_ac_profile_v WHERE 1 = 1 ";

  if (dataObject["vvInvOrgId"]) {
    selectSqlForAccountProfile += " AND inv_org_id = '" + dataObject["vvInvOrgId"] + "'";
  } else if (dataObject["invOrgId"]) {
    selectSqlForAccountProfile += " AND inv_org_id = '" + dataObject["invOrgId"] + "'";
  }

  if (dataObject["invTransactionDocHeaderId"]) {
    selectSqlForAccountProfile +=
      " AND inv_transaction_doc_header_id = '" +
      dataObject["invTransactionDocHeaderId"] +
      "'";
  }

  consoleLog("\n getAllAccountProfiles selectSql " + selectSqlForAccountProfile);

  return getDataFromSql(selectSqlForAccountProfile);
}

function getAllJournalProfilesForInvTransaction(headerDocTransactionType) {
  const headerDocTransactionTypeVal = headerDocTransactionType.toString().trim();

  let selectSqlForJournalProfiles3 =
  " SELECT gjpl.*       \
    FROM        inoerp.gl_journal_profile_l gjpl \
    join inoerp.gl_journal_profile_h gjph ON gjpl.gl_journal_profile_h_id =  gjph.gl_journal_profile_h_id \
    AND gjph.profile_code = '" +
    headerDocTransactionTypeVal +
  " ' ";

consoleLog("\n getAllJournalProfiles selectSql " + selectSqlForJournalProfiles3);

  return getDataFromSql(selectSqlForJournalProfiles3);
}

function completeOtherAction(dataObject, action) {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };
  let invTransactionDocHeaderId = "";
  if (dataObject["invTransactionDocHeaderId"]) {
    invTransactionDocHeaderId = dataObject["invTransactionDocHeaderId"];
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant delete as no prj RevenueDocHeader Id is found";
    return retDataMap;
  }

  let journalHeader = new glJournalHeader();
  journalHeader.headerData = {
    pSrcEntityName: "inv_transaction_doc_header",
    pSrcKeyName: "inv_transaction_doc_header_id",
    pSrcKeyValue: invTransactionDocHeaderId,
    referenceEntityName: "inv_transaction_doc_line",
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
