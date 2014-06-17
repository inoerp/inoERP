function setValFromSelectPage(site_info_id, address_id) {
 this.site_info_id = site_info_id;
 this.address_id = address_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var site_info_id = this.site_info_id;
 var address_id = this.address_id;
 if (site_info_id) {
	$("#site_info_id").val(site_info_id);
 }
  if (address_id) {
	$("#address_id").val(address_id);
 }
};

$(document).ready(function() {
 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=site_info';
 classSave.form_header_id = 'site_info';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'site_info';
 classSave.saveMain();
});