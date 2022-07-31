let glJournalHeader = function (
  glLedgerId,
  glDocumentType,
  transactionType,
  journalSource,
  journalName,
  balanceType,
  journalLines,
  journalTemplateLines,
  allAccountProfiles,
  glJournalHeaderId,
  docStatus,
  accountingType
) {
  this.glLedgerId = glLedgerId;
  this.glDocumentType = glDocumentType;
  this.transactionType = transactionType;
  this.journalSource = journalSource;
  this.journalName = journalName;
  this.balanceType = balanceType;
  this.journalLines = journalLines;
  this.journalTemplateLines = journalTemplateLines;
  this.allAccountProfiles = allAccountProfiles;
  this.glJournalHeaderId = glJournalHeaderId;
  this.docStatus = docStatus;
  this.accountingType = accountingType;
};

glJournalHeader.prototype.createAccounting = function () {
  let tableName = "gl_journal_header";
  let lineTableName = "gl_journal_line";
  if (this.accountingType == "draft") {
    tableName = "gl_draft_journal_header";
    lineTableName = "gl_draft_journal_line";
    this.docStatus = "not_accounted";
    //delete any existing draft journals
    let pSrcKeyValue2 = this.headerData["pSrcKeyValue"];
    consoleLog(
      "deleting any existing draft journals prototype" +
        Object.prototype.toString.call(pSrcKeyValue2) +
        " : " +
        pSrcKeyValue2.toString()
    );
    if (pSrcKeyValue2.toString() != undefined && parseInt(pSrcKeyValue2) > 0) {
      this.deleteDraftJournalLines();
    }
  }
  let headerId = this.createJournalHeader(tableName);
  if (headerId > 0) {
  } else {
    return "Error in creating journal header";
  }
  return this.createJournalLines(lineTableName);
};

glJournalHeader.prototype.createJournalHeader = function (tableName) {
  this.glJournalHeaderId = 0;

  let headerSql =
    " INSERT INTO `inoerp`.`" +
    tableName +
    "` ( `gl_ledger_id`, `journal_source`, `journal_category`, `journal_name`,\
   `description`, `balance_type`) VALUES( '" +
    this.glLedgerId +
    "', '" +
    this.journalSource +
    "', '" +
    this.glDocumentType +
    "' , '" +
    this.journalName +
    "', '" +
    this.journalName +
    " for " +
    this.transactionType +
    "', '" +
    this.balanceType +
    "' ) ";

  const headerResponse = insertDataWithSql(headerSql);
  let newGlJournalHeaderId = 0;
  if (headerResponse.length > 0 && headerResponse[0]["lastInsertId"]) {
    let glJournalHeaderIdStr = headerResponse[0]["lastInsertId"];
    newGlJournalHeaderId = parseInt(glJournalHeaderIdStr);
  }
  if (newGlJournalHeaderId > 0) {
    this.glJournalHeaderId = newGlJournalHeaderId;
  }

  return this.glJournalHeaderId;
};

let glJournalLine = function (
  glJournalHeaderId,
  glLedgerId,
  referenceEntityName,
  referenceKeyName,
  referenceKeyValue,
  pSrcEntityName,
  pSrcKeyName,
  pSrcKeyValue,
  amount
) {
  this.glJournalHeaderId = glJournalHeaderId;
  this.glLedgerId = glLedgerId;
  this.referenceEntityName = referenceEntityName;
  this.referenceKeyName = referenceKeyName;
  this.referenceKeyValue = referenceKeyValue;
  this.pSrcEntityName = pSrcEntityName;
  this.pSrcKeyName = pSrcKeyName;
  this.pSrcKeyValue = pSrcKeyValue;
  this.amount = amount;
};

glJournalHeader.prototype.createJournalLines = function (lineTableName) {
  let headerIdName = "gl_journal_header_id";
  if (lineTableName == "gl_draft_journal_line") {
    headerIdName = "gl_draft_journal_header_id";
  }
  let lineSql =
    " INSERT INTO `inoerp`.`" +
    lineTableName +
    "` (`" +
    headerIdName +
    "`, `reference_entity_name`, `reference_key_name`, \
  `reference_key_value`, `src_entity_name`,  `src_entity_id_name`, `src_entity_id`, `line_num`,`line_seq`, `p_src_entity_name`, \
   `p_src_entity_id_name`, `p_src_entity_id`, `gl_ac_id`, `amount`, `dr_cr`) VALUES ";

  let updateSql = "UPDATE ";

  let countOfLines = 0;
  const journalLinesLength = this.journalLines.length;
  for (let i = 0; i < journalLinesLength; i++) {
    const journalLine = this.journalLines[i];
    const journalLineReferenceEntityName = journalLine["referenceEntityName"];
    const journalLineReferenceKeyName = journalLine["referenceKeyName"];
    const journalLineReferenceKeyValue = journalLine["referenceKeyValue"];
    const journalLineCategory = journalLine["lineCategory"];
    consoleLog("\n\n journalLine " + JSON.stringify(journalLine));

    if (i == 0 && this.docStatus == "accounting_completed") {
      updateSql +=
        "  `inoerp`.`" +
        journalLineReferenceEntityName.toString() +
        "` SET accounting_status = 'accounting_completed'     WHERE " +
        journalLineReferenceKeyName.toString() +
        " IN (";
    }
    const journalTemplateLinesLength = this.journalTemplateLines.length;
    for (let index = 0; index < journalTemplateLinesLength; index++) {
      const journalTemplateLine = this.journalTemplateLines[index];
      let amount = parseFloat(journalLine.amount);
      if (amount == 0) {
        continue;
      }

      //check line category is same for transaction/document line and the template line
      let journalTemplateLineCategory = journalTemplateLine["lineCategory"];
      if (isNotNull(journalTemplateLineCategory)) {
        consoleLog("\n\n journalLineCategory " + journalLineCategory);
        if (journalLineCategory != journalTemplateLineCategory) {
          continue;
        }
      }

      const glAcId = this.getGlAcId(
        this.allAccountProfiles,
        journalTemplateLine["glAcLineType"],
        journalTemplateLine["drOrCr"],
        journalTemplateLine["lineCategory"]
      );
      countOfLines++;
      lineSql +=
        " ('" +
        this.glJournalHeaderId +
        "', '" +
        journalLineReferenceEntityName +
        "', '" +
        journalLineReferenceKeyName +
        "', '" +
        journalLineReferenceKeyValue +
        "', '" +
        journalLineReferenceEntityName +
        "', '" +
        journalLineReferenceKeyName +
        "', '" +
        journalLineReferenceKeyValue +
        "', '" +
        journalTemplateLine["seq"] +
        "', '" +
        countOfLines.toString() +
        "', '" +
        journalLine.pSrcEntityName +
        "', '" +
        journalLine.pSrcKeyName +
        "', '" +
        journalLine.pSrcKeyValue +
        "', '" +
        glAcId +
        "', '" +
        journalLine.amount +
        "', '" +
        journalTemplateLine["drOrCr"] +
        "' ) ";

      lineSql += " ,";
    }

    if (this.docStatus == "accounting_completed") {
      if (i == journalLinesLength - 1) {
        updateSql += " '" + journalLineReferenceKeyValue.toString() + "' ) ";
      } else {
        updateSql += " '" + journalLineReferenceKeyValue.toString() + "' , ";
      }
    }
  }

  if (countOfLines > 0) {
    if (this.docStatus == "accounting_completed") {
      updateDataWithSql(updateSql);
    }
    lineSql = lineSql.substring(0, lineSql.length - 1);
    const insertResponse = insertDataWithSql(lineSql);
    return JSON.stringify(insertResponse);
  } else {
    return "No lines to insert. Check the journal rule and accounting rules";
  }
};

glJournalHeader.prototype.getGlAcId = function (
  allAccountProfiles,
  glAcLineType,
  drOrCr
) {
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
};

glJournalHeader.prototype.headerData = {
  pSrcEntityName: "",
  pSrcKeyName: "",
  pSrcKeyValue: "",
  referenceEntityName: "",
};

glJournalHeader.prototype.deleteDraftJournalLines = function () {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };

  let deleteSql =
    "DELETE from gl_draft_journal_line \
    WHERE p_src_entity_name='" +
    this["headerData"].pSrcEntityName +
    "' AND p_src_entity_id_name='" +
    this["headerData"].pSrcKeyName +
    "'  ";

  let selectSql =
    "SELECT * from gl_draft_journal_line \
    WHERE p_src_entity_name='" +
    this["headerData"].pSrcEntityName +
    "' AND p_src_entity_id_name='" +
    this["headerData"].pSrcKeyName +
    "'";

  if (this["headerData"].pSrcKeyValue) {
    deleteSql +=
      " AND p_src_entity_id = '" + this["headerData"].pSrcKeyValue + "'";
    selectSql +=
      " AND p_src_entity_id = '" + this["headerData"].pSrcKeyValue + "'";
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
  let deleteHeaderData = deleteDataWithSql(headerDeleteSql);
  returnMessage += JSON.stringify(deleteHeaderData);
  retDataMap["rd_proceed_message"] = returnMessage;
  return retDataMap;
};

glJournalHeader.prototype.convertDraftToJournal = function (dataObject) {
  let retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Accounting request is successfully submitted",
  };
  let docIdToBeConverted = 0;
  if (this["headerData"].pSrcKeyValue) {
    docIdToBeConverted = this["headerData"].pSrcKeyValue;
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
            JOIN `" +
    this["headerData"].pSrcEntityName +
    "` `rheader`) \
            WHERE \
                ((`gl`.`p_src_entity_name` = '" +
    this["headerData"].pSrcEntityName +
    "') \
                    AND (`gl`.`p_src_entity_id_name` = '" +
    this["headerData"].pSrcKeyName +
    "') \
                    AND (`gl`.`p_src_entity_id` = `rheader`.`" +
    this["headerData"].pSrcKeyName +
    "`) \
                    AND  `rheader`.`" +
    this["headerData"].pSrcKeyName +
    "` = '" +
    docIdToBeConverted +
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
   `line_num`,   `line_seq`, `p_src_entity_name`, `p_src_entity_id_name`, `p_src_entity_id`, `gl_ac_id`, `amount`, `dr_cr`, \
     `gl_draft_journal_line_id`) \
    SELECT '" +
    glJournalHeaderId +
    "', gl.reference_entity_name, gl.reference_key_name, gl.reference_key_value, gl.src_entity_name, \
  gl.src_entity_id_name, gl.src_entity_id, gl.line_num,  gl.line_seq, gl.p_src_entity_name, gl.p_src_entity_id_name, \
   gl.p_src_entity_id, gl.gl_ac_id, gl.amount, gl.dr_cr,gl_draft_journal_line_id \
       FROM \
           (`gl_draft_journal_line` `gl` \
       JOIN `" +
    this["headerData"].pSrcEntityName +
    "` `rheader`) \
       WHERE \
           ((`gl`.`p_src_entity_name` = '" +
    this["headerData"].pSrcEntityName +
    "') \
               AND (`gl`.`p_src_entity_id_name` = '" +
    this["headerData"].pSrcKeyName +
    "')  \
               AND (`gl`.`p_src_entity_id` = `rheader`.`" +
    this["headerData"].pSrcKeyName +
    "`)) ";

  let lineInsertResponse = insertDataWithSql(lineSql);
  if (lineInsertResponse.length > 0) {
    retDataMap["rd_proceed_message"] = JSON.stringify(lineInsertResponse);
  } else {
    retDataMap["rd_proceed_message"] =
      "Cant insert as no journal lines are found";
  }

  //update accounting status
  let updateSql =
    "UPDATE " +
    this["headerData"].referenceEntityName +
    " SET accounting_status = 'accounting_completed' \
  WHERE " +
    this["headerData"].pSrcKeyName +
    " = '" +
    docIdToBeConverted +
    "';";
  let updateResponse = updateDataWithSql(updateSql);
  retDataMap["rd_proceed_message"] += JSON.stringify(updateResponse);
  return retDataMap;
};

