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
	$(".bc_label_auto_trigger_code").blur(function()
	{
	 if ($("#sys_profile_header_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".bc_label_auto_trigger_code").val("");
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


 $('body').off("change", '.org_id').on("change", '.org_id', function () {
 getSubInventory({
  json_url: 'modules/inv/subinventory/json_subinventory.php',
  org_id: $(this).val()
 });
});

 copy_sys_profile_header_id();

});