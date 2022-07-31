function glJournalLin2(
  referenceEntityName,
  referenceKeyName,
  referenceKeyValue,
  pSrcEntityName,
  pSrcKeyName,
  pSrcKeyValue,
  amount
) {
  this.referenceEntityName = referenceEntityName;
  this.referenceKeyName = referenceKeyName;
  this.referenceKeyValue = referenceKeyValue;
  this.pSrcEntityName = pSrcEntityName;
  this.pSrcKeyName = pSrcKeyName;
  this.pSrcKeyValue = pSrcKeyValue;
  this.amount = amount;
};

let glJournalHeader2 = function (journalLines) {
  this.journalLines = journalLines;
}

glJournalHeader2.prototype.printData = function () {
  for(let i = 0; i < this.journalLines.length; i++) {
    let line  = this.journalLines[i];
    console.log(line.amount + " " + line.referenceKeyName + " " + line.referenceKeyValue);
  }
}


let journalLines = [new glJournalLin2("prj_expenditure_header", "prj_expenditure_header_id", "1", "prj_expenditure_line", "prj_expenditure_line_id", "1", "100")];  
journalLines.push(new glJournalLin2("prj_expenditure_header", "prj_expenditure_header_id", "2", "prj_expenditure_line", "prj_expenditure_line_id", "2", "200"));
journalLines.push(new glJournalLin2("prj_expenditure_header", "prj_expenditure_header_id", "3", "prj_expenditure_line", "prj_expenditure_line_id", "3", "300"));

let journalHeader = new glJournalHeader2(journalLines);
journalHeader.printData();