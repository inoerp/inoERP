function setValFromSelectPage(mdm_price_list_header_id, item_id_m, item_number, item_description, uom_id) {
 this.mdm_price_list_header_id = mdm_price_list_header_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var mdm_price_list_header_id = this.mdm_price_list_header_id;
 var item_id_m = this.item_id_m;
 var item_number = this.item_number;
 var item_description = this.item_description;
 var uom_id = this.uom_id;
 
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 
 
  if (mdm_price_list_header_id) {
	$("#mdm_price_list_header_id").val(mdm_price_list_header_id);
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
 $('#form_line').on("click", function() {
	if (!$('#mdm_price_list_header_id').val()) {
	 alert('No header Id : First enter/save header details');
	} else {
	 var headerId = $('#mdm_price_list_header_id').val();
	 if (!$(this).find('.mdm_price_list_header_id').val()) {
		$(this).find('.mdm_price_list_header_id').val(headerId);
	 }
	}

 });


 //Popup for selecting option type
 $(".mdm_price_list_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=mdm_price_list_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //Check the option_id while entering the option line code
 function copy_mdm_price_list_header_id() {
	$(".mdm_price_list_line_code").blur(function()
	{
	 if ($("#mdm_price_list_header_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".mdm_price_list_line_code").val("");
	 } else {
		$(".mdm_price_list_header_id").val($("#mdm_price_list_header_id").val());
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


 copy_mdm_price_list_header_id();

 //Get the option_id on find button click
 $('a.show.mdm_price_list_header_id').click(function() {
	var headerId = $('#mdm_price_list_header_id').val();
	$(this).prop('href', modepath() + 'pageno=1&per_page=10&submit_search=Search&search_class=mdm_price_list_line&search_asc_desc=desc&class_name=mdm_price_list_line&mdm_price_list_header_id=' + headerId);
 });

 onClick_add_new_row('tr.mdm_price_list_line0', 'tbody.mdm_price_list_line_values', 4);

//context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'mdm_price_list_header_id';
 classContextMenu.docLineId = 'mdm_price_list_line_id';
 classContextMenu.btn1DivId = 'mdm_price_list_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'mdm_price_list_line';
 classContextMenu.tbodyClass = 'mdm_price_list_line_values';
 classContextMenu.noOfTabbs = 4;
 classContextMenu.contextMenu();


//deleteData('json.option.php');
// save('json.value_group.php', '#mdm_price_list_header', 'line_id_cb', 'code', '#mdm_price_list_header_id');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=mdm_price_list_header';
 classSave.form_header_id = 'mdm_price_list_header';
 classSave.primary_column_id = 'mdm_price_list_header_id';
 classSave.line_key_field = 'code';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.enable_select = true;
 classSave.headerClassName = 'mdm_price_list_header';
 classSave.lineClassName = 'mdm_price_list_line';
 classSave.saveMain();
});

