function setValFromSelectPage(sys_secondary_field_instance_id) {
 this.sys_secondary_field_instance_id = sys_secondary_field_instance_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var sys_secondary_field_instance_id = this.sys_secondary_field_instance_id;
 if (sys_secondary_field_instance_id) {
	$("#sys_secondary_field_instance_id").val(sys_secondary_field_instance_id);
 }
};


$(document).ready(function() {

 //Get the sys_secondary_field_instance_id on find button click
 $('a.show.obj_class_name').click(function() {
	var obj_class_name = $('#obj_class_name').val();
	$(this).attr('href', modepath() + 'obj_class_name=' + obj_class_name);
 });

onClick_add_new_row('tr.sys_secondary_field0', 'tbody.form_data_line_tbody', '2');

});

