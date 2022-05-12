function afterGet(inputData) {
  return validationForAfterGet(inputData);
}

function beforePatch(inputData) {
  consoleLog(
    "\n\nIn beforePatch gl_journal_header " + JSON.stringify(inputData)
  );

  var retDataMap = {
    rd_proceed_status: false,
    rd_proceed_message: "Action is successfully submitted",
  };

  let data = inputData["data"];
  let action = data["action"];
  let glJournalHeaderId = data["glJournalHeaderId"];

  if (action == "js_gl_reverse_sign" || action == "js_gl_reverse_drcr") {
    let insertSql = " ";
    if (action == "js_gl_reverse_sign") {
      insertSql =
        "select inoerp.glReverseJournal('reverse_sign', " +
        glJournalHeaderId +
        ")   ";
    } else {
      insertSql =
        "select inoerp.glReverseJournal('reverse_drcr', " +
        glJournalHeaderId +
        ")   ";
    }

    request = {
      sql: insertSql,
      dbType: "MySQL",
      connName: "Inoerp",
    };
    let response = sqlSelect(request);
    if(typeof response["data"] != "undefined" && response["data"].length > 0){
        retDataMap["rd_proceed_message"] = "Database Error : " +  JSON.stringify(response["data"][0]);
    }else{
        retDataMap["rd_proceed_message"] = JSON.stringify(response);
    }

     // retDataMap["rd_proceed_message"] = "Journal is  successfully reversed";

    return retDataMap;
  } else {
    return data;
  }


  
}
