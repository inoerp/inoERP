function setValFromSelectPage(sys_extra_field_instance_id) {
 this.sys_extra_field_instance_id = sys_extra_field_instance_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var sys_extra_field_instance_id = this.sys_extra_field_instance_id;
 if (sys_extra_field_instance_id) {
	$("#sys_extra_field_instance_id").val(sys_extra_field_instance_id);
 }
};


$(document).ready(function() {
 //selecting Id
 $(".sys_extra_field_instance_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sys_extra_field_instance', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

