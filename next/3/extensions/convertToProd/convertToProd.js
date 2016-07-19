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

$(document).ready(function() {

//  var Mandatory_Fields = ["#org_id", "First Select Org Name", "#item_number", "First Select Item Number"];
// select_mandatory_fields(Mandatory_Fields);
//
// $('#form_line').on("click", function() {
//	if (!$('#sys_profile_header_id').val()) {
//	 alert('No header Id : First enter/save header details');
//	} else {
//	 var headerId = $('#sys_profile_header_id').val();
//	 if (!$(this).find('.sys_profile_header_id').val()) {
//		$(this).find('.sys_profile_header_id').val(headerId);
//	 }
//	}
//
// });


 //Popup for selecting option type
 $(".sys_profile_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sys_profile_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //Check the option_id while entering the option line code
 function copy_sys_profile_header_id() {
	$(".sys_profile_line_code").blur(function()
	{
	 if ($("#sys_profile_header_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".sys_profile_line_code").val("");
	 } else {
		$(".sys_profile_header_id").val($("#sys_profile_header_id").val());
	 }
	});
 }

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
 $('a.show.sys_profile_header_id').click(function(e) {
	var headerId = $('#sys_profile_header_id').val();
	var profile_level = $('#profile_level').val();
	$(this).attr('href', modepath() + 'sys_profile_header_id=' + headerId + '&profile_level=' +  profile_level);
 });

 onClick_add_new_row('tr.sys_profile_line0', 'tbody.sys_profile_line_values', 4);

//context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'sys_profile_header_id';
 classContextMenu.docLineId = 'sys_profile_line_id';
 classContextMenu.btn1DivId = 'sys_profile_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'sys_profile_line';
 classContextMenu.tbodyClass = 'sys_profile_line_values';
 classContextMenu.noOfTabbs = 1;
 classContextMenu.contextMenu();

// save('json.value_group.php', '#sys_profile_header', 'line_id_cb', 'code', '#sys_profile_header_id');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=sys_profile_header';
 classSave.form_header_id = 'sys_profile_header';
 classSave.primary_column_id = 'sys_profile_header_id';
 classSave.line_key_field = 'level_name';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.enable_select = true;
 classSave.headerClassName = 'sys_profile_header';
 classSave.lineClassName = 'sys_profile_line';
 classSave.saveMain();
});

