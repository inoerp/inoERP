function setValFromSelectPage(hr_payroll_id, item_id_m, item_number, item_description, uom_id) {
 this.hr_payroll_id = hr_payroll_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var hr_payroll_id = this.hr_payroll_id;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 
 
  if (hr_payroll_id) {
	$("#hr_payroll_id").val(hr_payroll_id);
 }
 
  rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (item_id_m) {
	$('#content').find(rowClass).find('.item_id_m').val(item_id_m);
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
//	if (!$('#hr_payroll_id').val()) {
//	 alert('No header Id : First enter/save header details');
//	} else {
//	 var headerId = $('#hr_payroll_id').val();
//	 if (!$(this).find('.hr_payroll_id').val()) {
//		$(this).find('.hr_payroll_id').val(headerId);
//	 }
//	}
//
// });


 //Popup for selecting option type
 $(".hr_payroll_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_payroll', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //Check the option_id while entering the option line code
 function copy_hr_payroll_id() {
	$(".hr_payroll_schedule_code").blur(function()
	{
	 if ($("#hr_payroll_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".hr_payroll_schedule_code").val("");
	 } else {
		$(".hr_payroll_id").val($("#hr_payroll_id").val());
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


 copy_hr_payroll_id();

 onClick_add_new_row('tr.hr_payroll_schedule0', 'tbody.hr_payroll_schedule_values', 4);

//context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'hr_payroll_id';
 classContextMenu.docLineId = 'hr_payroll_schedule_id';
 classContextMenu.btn1DivId = 'hr_payroll';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'hr_payroll_schedule';
 classContextMenu.tbodyClass = 'hr_payroll_schedule_values';
 classContextMenu.noOfTabbs = 4;
 classContextMenu.contextMenu();


//deleteData('json.option.php');
// save('json.value_group.php', '#hr_payroll', 'line_id_cb', 'code', '#hr_payroll_id');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=hr_payroll';
 classSave.form_header_id = 'hr_payroll';
 classSave.primary_column_id = 'hr_payroll_id';
 classSave.line_key_field = 'code';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.enable_select = true;
 classSave.headerClassName = 'hr_payroll';
 classSave.lineClassName = 'hr_payroll_schedule';
 classSave.saveMain();
});

