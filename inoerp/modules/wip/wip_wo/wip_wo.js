function setValFromSelectPage(wip_wo_header_id, item_id_m, item_number, item_description,
				uom_id, processing_lt) {
 this.wip_wo_header_id = wip_wo_header_id;
 this.item_id_m = item_id_m;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.processing_lt = processing_lt;
}

setValFromSelectPage.prototype.setVal = function() {
 if(this.wip_wo_header_id){
 $("#wip_wo_header_id").val(this.wip_wo_header_id);
 }
 var rowClass = '.' + localStorage.getItem("row_class");
 var itemType = localStorage.getItem("itemType");
 rowClass = rowClass.replace(/\s+/g, '.');
 

 var item_obj = [{id: 'item_id_m', data: this.item_id_m},
	{id: 'item_number', data: this.item_number},
	{id: 'item_description', data: this.item_description},
	{id: 'uom', data: this.uom_id},
	{id: 'processing_lt', data: this.processing_lt}
 ];

 var component_obj = [{id: 'component_item_id_m', data: this.item_id_m},
	{id: 'component_item_number', data: this.item_number},
	{id: 'component_description', data: this.item_description},
	{id: 'component_uom', data: this.uom_id}
 ];
 
 if (localStorage.getItem("li_divId")) {
  var li_divId = '#' + localStorage.getItem("li_divId");
	$(item_obj).each(function(i, value) {
	 if (value.data) {
		var fieldId = '#' + value.id;
		$('#content').find(fieldId).val(value.data);
	 }
	});
 } else {
	$(component_obj).each(function(i, value) {
   	 if (value.data) {
   		var fieldClass = '.' + value.id;
		$('#content').find(rowClass).find(fieldClass).val(value.data);
	 }
	});
 }
 localStorage.removeItem("row_class");
 localStorage.removeItem("field_class");
 localStorage.removeItem("li_divId");
 localStorage.removeItem("itemType");
};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'wip_wo_header_id';
 mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id",'wo_type', "wip_accounting_group_id"];
 mandatoryCheck.mandatory_messages = ["First Select Org",'No Work Order Type', "No WIP Accounting Group"];
 mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
	$('.lines_number:first').val('10');
 }

 if (!($('.detail_number:first').val())) {
	$('.detail_number:first').val('10');
 }
 
 $('#quantity').on('blur', function(){
    if($(this).val()){
   $('#nettable_quantity').val($(this).val());
  }
 })

 //selecting Header Id
 $(".wip_wo_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=wip_wo_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

// //popu for selecting header item
// $('#content').on('click', '.select_item_number.select_popup_header', function() {
//	localStorage.setItem("itemType", 'header');
//	var openUrl = 'select.php?class_name=item';
//	if ($(this).siblings('.item_number').val()) {
//	 openUrl += '&item_number=' + $(this).siblings('.item_number').val();
//	}
//	void window.open(openUrl, '_blank',
//					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
// });

//start date & completion date calculation
 $('#content').on('change', '.start_date', function() {
	var startDate = $('.start_date').first().val();
	var str = startDate.split(/-/);
  if($('#processing_lt').val()){
   var processing_lt = +$('#processing_lt').val();
  }else{
    var processing_lt = 0;
  }
	var newDate = (parseInt(str[2]) + (processing_lt));
	var cd = new Date(str[0], str[1], newDate);
	var foramtedDate = cd.getFullYear() + '-' + cd.getMonth() + '-' + cd.getDate();
	$('.completion_date').first().val(foramtedDate);
 });

 $('#content').on('change', '.completion_date', function() {
	var completionDate = $('.completion_date').first().val();
	var str = completionDate.split(/-/);
	  if($('#processing_lt').val()){
   var processing_lt = +$('#processing_lt').val();
  }else{
    var processing_lt = 0;
  }
	var newDate = (parseInt(str[2]) + (processing_lt));
	var cd = new Date(str[0], str[1], newDate);
	var foramtedDate = cd.getFullYear() + '-' + cd.getMonth() + '-' + cd.getDate();
	$('.start_date').first().val(foramtedDate);
 });

//Required Resource Quantity
 $('body').on('focusout', '.usage', function() {
	var usageValue = $(this).val();
	var quantity = $("#quantity").val();
	var trClass = '.' + $(this).closest('tr').attr('class');
	var newtrClass = trClass.split(' ').join('.');
	var RequiredQuanity = usageValue * quantity;
	$(this).closest('.tabContainer').find(newtrClass).find('.required_quantity').val(RequiredQuanity);
 });

//Required BOM Quantity
 $('body').on('focusout', '.usage_quantity', function() {
	var usageValue = $(this).val();
	var quantity = $("#quantity").val();
	var trClass = '.' + $(this).closest('tr').attr('class');
	var newtrClass = trClass.split(' ').join('.');
	var RequiredQuanity = usageValue * quantity;
	$(this).closest('.tabContainer').find(newtrClass).find('.required_quantity').val(RequiredQuanity);
 });

 //get Subinventory Name
 $("#org_id").on("change", function() {
	getSubInventory('modules/inv/subinventory/json_subinventory.php', $("#org_id").val());
	getWipAccountingGroup('modules/wip/accounting_group/json_accounting_group.php', $("#org_id").val());
	$('.org_id').val($(this).val());
 });


 //get locatot on Subinventory change in form header
 $('#form_header').on('change', '.subinventory_id', function() {
	var subInventoryId = $(this).val();
	if (subInventoryId > 0) {
	 getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'oneSubinventory', '');
	}
 });

 //get locatot on Subinventory change in form line
 $('#form_line').on('change', '.subinventory_id', function() {
	var subInventoryId = $(this).val();
	if (subInventoryId > 0) {
	 var trClass = '.' + $(this).closest('tr').attr('class');
	 getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'subinventory', trClass);
	}
 });

//add or show linw details
 addOrShow_lineDetails('tr.wip_wo_routing0');

 //add new lines
 //add new lines
 $("#content tbody.form_data_line_tbody2").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'wip_wo_bom';
	addNewRow.tbodyClass = 'form_data_line_tbody2';
	addNewRow.noOfTabs = 2;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 $("#content tbody.form_data_line_tbody").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'wip_wo_routing';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 2;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 onClick_addDetailLine(2);


 //Get the wip_wo_id on refresh button click
 $('a.show.wip_wo_header_id').click(function() {
	var wip_wo_header_id = $('#wip_wo_header_id').val();
	$(this).attr('href', modepath() + 'wip_wo_header_id=' + wip_wo_header_id);
 });

 function afterCopy() {
	$('#bom_exploded_cb').prop('checked', false);
	$('#routing_exploded_cb').prop('checked', false);
	$('#wo_number, #completed_quantity, #remaining_quantity, .anyDate').val('');
	return true;
 }

//context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'wip_wo_header_id';
 classContextMenu.docLineId = 'wip_wo_routing_line_id';
 classContextMenu.btn1DivId = 'wip_wo_header';
 classContextMenu.btn2DivId = 'tabsLine';
 classContextMenu.trClass = 'wip_wo_routing';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 2;
 classContextMenu.afterCopy = afterCopy;
 classContextMenu.contextMenu();

 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=wip_wo_header';
 classSave.form_header_id = 'wip_wo_header';
 classSave.primary_column_id = 'wip_wo_header_id';
 classSave.line_key_field = 'routing_sequence';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'wip_wo_header';
 classSave.lineClassName = 'wip_wo_routing_line';
 classSave.detailClassName = 'wip_wo_routing_detail';
 classSave.lineClassName2 = 'wip_wo_bom';
 classSave.enable_select = true;
 classSave.saveMain();


//delete line
 deleteData('form.php?class_name=wip_wo_header&line2_class_name=wip_wo_bom&line_class_name=wip_wo_routing_line&detail_class_name=wip_wo_routing_detail');

});


