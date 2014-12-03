function setValFromSelectPage(sys_profile_header_id, item_id, item_number, item_description, uom_id) {
 this.sys_profile_header_id = sys_profile_header_id;
 this.item_id = item_id;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var sys_profile_header_id = this.sys_profile_header_id;
 var item_id = this.item_id;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 
 
  if (sys_profile_header_id) {
	$("#sys_profile_header_id").val(sys_profile_header_id);
 }
 
  rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (item_id) {
	$('#content').find(rowClass).find('.item_id').val(item_id);
 }
 if (item_number) {
	$('#content').find(rowClass).find('.item_number').val(item_number);
 }
 if (item_description) {
	$('#content').find(rowClass).find('.item_description').val(item_description);
 }
 if (uom_id) {
	$('#content').find(rowClass).find('.uom_id').val(uom_id);
 }

 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");
 
};

 function copy_sys_profile_header_id() {
	$(".bc_auto_trigger_code").blur(function()
	{
	 if ($("#sys_profile_header_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".bc_auto_trigger_code").val("");
	 } else {
		$(".sys_profile_header_id").val($("#sys_profile_header_id").val());
	 }
	});
 }

$(document).ready(function() {

 //Popup for selecting option type
 $(".sys_profile_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sys_profile_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //Check the option_id while entering the option line code


 //enable disbale parent & group
 $('.parent_cb').each(function() {
	if ($(this).is(":checked")) {
	 $(this).closest('tr').find('.parent_line_id').attr('disabled', 'true');
	}
 });

 $('body').on('change', '.parent_cb', function() {
	if ($(this).is(":checked")) {
	 $(this).closest('tr').find('.parent_line_id').attr('disabled', 'true');
	} else {
	 $(this).closest('tr').find('.parent_line_id').removeAttr('disabled');
	}
 });


 copy_sys_profile_header_id();

  //Get the org_id on find button click
 $('a.show.sys_association_level').click(function(e) {
	var headerId = $('#transaction_type_id').val();
	var association_level = $('#association_level').val();
	$(this).attr('href', modepath() + 'transaction_type_id=' + headerId + '&association_level=' +  association_level);
 });

 onClick_add_new_row('tr.bc_auto_trigger0', 'tbody.bc_auto_trigger_values', 4);

//context menu

deleteData('form.php?class_name=sys_profile_header&line_class_name=bc_auto_trigger');
//deleteData('json.option.php');
 //context menu
 var classContextMenu = new contextMenuMain();
  classContextMenu.docLineId = 'bc_label_auto_trigger_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'bc_auto_trigger';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
// classContextMenu.contextMenu();
 
 var tax_codeSave = new saveMainClass();
 tax_codeSave.json_url = 'form.php?class_name=bc_auto_trigger';
 tax_codeSave.single_line = false;
 tax_codeSave.line_key_field = 'association_level';
 tax_codeSave.form_line_id = 'bc_auto_trigger';
 tax_codeSave.saveMain();
});

