function setValFromSelectPage(sys_secondary_field_inst_id) {
 this.sys_secondary_field_inst_id = sys_secondary_field_inst_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var sys_secondary_field_inst_id = this.sys_secondary_field_inst_id;
 if (sys_secondary_field_inst_id) {
	$("#sys_secondary_field_inst_id").val(sys_secondary_field_inst_id);
 }
};
