function setValFromSelectPage(hr_payroll_process_id, item_id_m, item_number, item_description, uom_id) {
 this.hr_payroll_process_id = hr_payroll_process_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var hr_payroll_process_id = this.hr_payroll_process_id;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 
 
  if (hr_payroll_process_id) {
	$("#hr_payroll_process_id").val(hr_payroll_process_id);
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
 //Check the option_id while entering the option line code
 function copy_hr_payroll_process_id() {
	$(".hr_payroll_process_schedule_code").blur(function()
	{
	 if ($("#hr_payroll_process_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".hr_payroll_process_schedule_code").val("");
	 } else {
		$(".hr_payroll_process_id").val($("#hr_payroll_process_id").val());
	 }
	});
 }
$(document).ready(function() {


 //Popup for selecting option type
 $(".hr_payroll_process_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=hr_payroll_process', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


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


 copy_hr_payroll_process_id();

// deleteHeader('form.php?class_name=hr_payroll_process', $('#hr_payroll_process_id').val());

});

