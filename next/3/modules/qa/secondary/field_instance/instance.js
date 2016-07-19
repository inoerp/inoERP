function setValFromSelectPage(sys_secondary_field_instance_id) {
 this.sys_secondary_field_instance_id = sys_secondary_field_instance_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var sys_secondary_field_instance_id = this.sys_secondary_field_instance_id;
 if (sys_secondary_field_instance_id) {
	$("#sys_secondary_field_instance_id").val(sys_secondary_field_instance_id);
 }
};
