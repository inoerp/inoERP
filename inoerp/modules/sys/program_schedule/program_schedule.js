function setValFromSelectPage(extn_contact_id) {
 this.extn_contact_id = extn_contact_id;
}


setValFromSelectPage.prototype.setVal = function () {
 if (this.extn_contact_id) {
  $("#extn_contact_id").val(this.extn_contact_id);
 }
};

