function beforePatch(inputData) {
  let data = inputData["data"];
  let action = data["action"];

  if (action == "create_accounting") {
    return createAccountingFromParams(data, action);
  } else {
    return data;
  }
}

//1. Find all expenditure lines
//2. Find gl_document_type and corresponding journal lines (journal profile lines)from expenditure_header_id
//3. Find all accounts from business unit and expense_type
//4. Create a single gl_journal_header and gl_journal_lines for that gl_header_id

function createAccountingFromParams(data) {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };

  

  const allLines = findAllLinesToBeAccounted(data);
  const journalTemplateLines = getJournalProfiles(data);
  const allAccountProfiles = getAllAccountProfiles(data);

  
  if (allLines.length < 1) {
    retDataMap["rd_proceed_message"] = "No lines to be accounted";
    return retDataMap;
  }
  const headerFirstRow = allLines[0];
  const vvGlLedgerId = headerFirstRow["vvGlLedgerId"];
  const vvGlDocumentType = headerFirstRow["glDocumentType"];
  const expenditureType = headerFirstRow["glDocumentType"];
  
  //createJournalHeader
  const glJournalHeaderId = createJournalHeader(
    vvGlLedgerId,
    "project_expenditure",
    vvGlDocumentType
  );
  
  createJournalLines(
    glJournalHeaderId,
    allLines,
    journalTemplateLines,
    allAccountProfiles
  );

  return retDataMap;
}

function createJournalLines(
  glJournalHeaderId,
  allLines,
  journalTemplateLines,
  allAccountProfiles
) {
  let lineSql =
    " INSERT INTO `inoerp`.`gl_journal_line` (`gl_journal_header_id`, `reference_entity_name`, `reference_key_name`, `reference_key_value`, `src_entity_name`, \
   `src_entity_id_name`, `src_entity_id`, `line_num`, `p_src_entity_name`, `p_src_entity_id_name`, `p_src_entity_id`, `gl_ac_id`, `amount`, `dr_cr`) VALUES ";

  let updateSql =
    " UPDATE `inoerp`.`prj_expenditure_header` SET is_accounted_cb = '1' \
    WHERE prj_expenditure_header_id IN (";

  let prjExpenditureHeaderIds = [];

  for (let i = 0; i < allLines.length; i++) {
    const transactionRow = allLines[i];
    const prjExpenditureHeaderId = transactionRow["prjExpenditureHeaderId"];
    const prjExpenditureLineId = transactionRow["prjExpenditureLineId"];

    for (let index = 0; index < journalTemplateLines.length; index++) {
      const journalLine = journalTemplateLines[index];
      let amountKey = "amount_" + journalLine["seq"];
      let amount = parseFloat(transactionRow["lineAmount"]);
      if (amount == 0) {
        continue;
      }
      const glAcId = getGlAcId(
        allAccountProfiles,
        journalLine["glAcLineType"],
        journalLine["drOrCr"]
      );
      lineSql +=
        " ('" +
        glJournalHeaderId +
        "', 'prj_expenditure_line', 'prj_expenditure_line_id', '" +
        prjExpenditureLineId +
        "', 'prj_expenditure_line', 'prj_expenditure_line_id', '" +
        prjExpenditureLineId +
        "', '" +
        journalLine["seq"] +
        "', 'prj_expenditure_header', 'prj_expenditure_header_id', '" +
        prjExpenditureHeaderId +
        "', '" +
        glAcId +
        "', '" +
        transactionRow["lineAmount"] +
        "', '" +
        journalLine["drOrCr"] +
        "' ) ";

      let addUpdateStmt = false;
      if (prjExpenditureHeaderIds.indexOf(prjExpenditureHeaderId) == -1) {
        prjExpenditureHeaderIds.push(prjExpenditureHeaderId);
        updateSql += "'" + prjExpenditureHeaderId + "'";
      } else if (prjExpenditureHeaderIds.indexOf(prjExpenditureHeaderId) == 0) {
        addUpdateStmt = true;
      }

      if (
        index == journalTemplateLines.length - 1 &&
        i == allLines.length - 1
      ) {
      } else {
        lineSql += " , ";
        if (prjExpenditureHeaderIds.length > 1 && addUpdateStmt) {
          updateSql += " , ";
        }
      }
    }
  }

  updateSql += ")";

  let insertRequest = {
    sql: lineSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const insertResponse = sqlInsert(insertRequest);
  //TODO validate insertResponse before proceeding

  let updateRequest = {
    sql: updateSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const updateResponse = sqlUpdate(updateRequest);
}

function getGlAcId(allAccountProfiles, glAcLineType, drOrCr) {
  let glAcId = "";

  for (const profile of allAccountProfiles) {
    if (
      profile["glAcLineType"] == glAcLineType &&
      profile["drOrCr"] == drOrCr
    ) {
      glAcId = profile["glAcId"];
      break;
    }
  }

  return glAcId;
}

function createJournalHeader(vvGlLedgerId, transactionType, vvGlDocumentType) {
  let headerSql =
    " INSERT INTO `inoerp`.`gl_journal_header` ( `gl_ledger_id`, `journal_source`, `journal_category`, `journal_name`,\
       `description`, `balance_type`) VALUES( '" +
    vvGlLedgerId +
    "', 'PRJ', '" +
    vvGlDocumentType +
    "' , 'Project Expenditure Accounting', 'Expenditure Accounting For " +
    transactionType +
    "', 'A' ) ";

  headerInsertRequest = {
    sql: headerSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };
  const headerResponse = sqlInsert(headerInsertRequest);
  const headerResponseData = headerResponse["data"];
  const headerFirstRow = headerResponseData[0];
  const glJournalHeaderId = headerFirstRow["lastInsertId"];
  return glJournalHeaderId;
}

function findAllLinesToBeAccounted(dataObject) {
  let selectSql =
    "SELECT * FROM prj_expenditure_line_unaccounted_v WHERE 1 = 1 ";

  if (dataObject["vvBuOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["vvBuOrgId"] + "'";
  } else if (dataObject["buOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["buOrgId"] + "'";
  }

  if (dataObject["prjExpenditureHeaderId"]) {
    selectSql +=
      " AND prj_expenditure_header_id = '" +
      dataObject["prjExpenditureHeaderId"] +
      "'";
  }

  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  return response["data"];
}

function getJournalProfiles() {
  let selectSql =
    " SELECT gjpl.*       \
      FROM        inoerp.gl_journal_profile_l gjpl \
      join inoerp.gl_journal_profile_h gjph ON gjpl.gl_journal_profile_h_id =  gjph.gl_journal_profile_h_id \
      AND gjph.profile_code = 'prj_expenditure' ";

  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  return response["data"];
}

function getAllAccountProfiles(dataObject) {
  let selectSql = "SELECT * FROM prj_expenditure_ac_profile_v WHERE 1 = 1 ";

  if (dataObject["vvBuOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["vvBuOrgId"] + "'";
  } else if (dataObject["buOrgId"]) {
    selectSql += " AND bu_org_id = '" + dataObject["buOrgId"] + "'";
  }

  if (dataObject["prjExpenditureHeaderId"]) {
    selectSql +=
      " AND prj_expenditure_header_id = '" +
      dataObject["prjExpenditureHeaderId"] +
      "'";
  }

  request = {
    sql: selectSql,
    dbType: "MySQL",
    connName: "Inoerp",
  };

  let response = sqlSelect(request);

  return response["data"];
}