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

