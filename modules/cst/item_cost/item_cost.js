function setValFromSelectPage(cst_item_cost_header_id, item_id, item_number, item_description,
				uom_id) {
 this.cst_item_cost_header_id = cst_item_cost_header_id;
 this.item_id = item_id;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var cst_item_cost_header_id = this.cst_item_cost_header_id;
 var item_obj = [{id: 'item_id', data: this.item_id},
	{id: 'item_number', data: this.item_number},
	{id: 'item_description', data: this.item_description},
	{id: 'uom_id', data: this.uom_id}
 ];
 if (cst_item_cost_header_id) {
	$("#cst_item_cost_header_id").val(cst_item_cost_header_id);
 }
 $(item_obj).each(function(i, value) {
	if (value.data) {
	 var fieldId = '#' + value.id;
	 $('#content').find(fieldId).val(value.data);
	}
 });
};

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'item_cost_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "ledger_id"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No Ledger Id"];
// mandatoryCheck.mandatoryField();

//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
	$('.lines_number:first').val('1');
 }

 //set the line price
 $('#content').validateAmount();
 $('#content').on('change', '.amount, .invoice_amount', function() {
	var remaining_amount = (+$(this).closest('tr').find('.invoice_amount').val()) -
					((+$(this).closest('tr').find('.amount').val()) + (+$(this).closest('tr').find('.receipt_amount').val()));
	$(this).closest('tr').find('.remaining_amount').val(remaining_amount);
	$(this).closest('tr').find('.remaining_amount').prop('readonly', true);
	$(this).closest('tr').find('.invoice_amount').prop('readonly', true);
	$(this).closest('tr').find('.receipt_amount').prop('readonly', true);
 });

//get ar_customer details
 $("#ar_customer_id, #customer_name, #customer_number").on("focusout", function() {
	if (($("#bu_org_id").val()) && ($('#ar_customer_id').val())) {
	 var bu_org_id = $("#bu_org_id").val();
	 getCustomerDetails('modules/ar/customer/json_customer.php', bu_org_id);
	}
 });

 $("#content").on("change", "#ar_customer_site_id", function() {
	var ar_customer_site_id = $("#ar_customer_site_id").val();
	if (ar_customer_site_id) {
	 getCustomerSiteDetails('modules/ar/customer/json_customer.php', ar_customer_site_id);
	}
 });


 //selecting Header Id
 $(".cst_item_cost_header_id.select_popup").on("click", function() {
	var link = 'select.php?class_name=cst_item_cost_header';
	void window.open(link, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the item_cost_header_id on refresh button click
 $('a.show.cst_item_cost_header_id').click(function() {
	var cst_item_cost_header_id = $('#cst_item_cost_header_id').val();
	$(this).attr('href', modepath() + 'cst_item_cost_header_id=' + cst_item_cost_header_id);

 });


 $('#bom_cost_type').on('change', function() {
	if ($(this).val() === 'FROZEN') {
	 alert('You cant directly entered FROZEN cost.\nEnter pending cost and then run standard cost update');
	}
 });


 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'item_cost_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 2;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });


 deleteData('form.php?class_name=item_cost_header&line_class_name=item_cost_line&detail_class_name=item_cost_detail');

//remove po lines
 $("#remove_row").click(function() {
	$('input[name="item_cost_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'item_cost_header_id';
 classContextMenu.docLineId = 'item_cost_line_id';
 classContextMenu.btn1DivId = 'item_cost_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'item_cost_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 2;
 classContextMenu.contextMenu();

// deleteData('json.po.php');
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=cst_item_cost_header';
 classSave.form_header_id = 'cst_item_cost_header';
 classSave.primary_column_id = 'cst_item_cost_header_id';
 classSave.line_key_field = 'cost_element_type';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'cst_item_cost_header';
 classSave.lineClassName = 'cst_item_cost_line';
 classSave.enable_select = true;
 classSave.saveMain();


//all actions
//Popup for selecting match 
 function create_accounting() {
	var item_cost_header_id = $("#item_cost_header_id").val();
	if (item_cost_header_id) {
	 var link = 'multi_select.php?class_name=item_cost_header&action=create_accounting&mode=9&action_class_name=item_cost_header&item_cost_header_id=' + item_cost_header_id;
	 localStorage.removeItem("reset_link");
	 localStorage.setItem("reset_link", link);
	 localStorage.removeItem("jsfile");
	 localStorage.setItem("jsfile", "modules/ar/receipt/extra_item_cost.js");
	 void window.open(link, '_blank',
					 'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	 return false;
	} else {
	 alert('No Transaction Header ID/nEnter or Save The Header Details ');
	}
 }

 $('#receipt_action').on('change', function() {
	var selected_value = $(this).val();
	switch (selected_value) {
	 case 'CREATE_ACCOUNT' :
		create_accounting();
		break;

	 case 'MATCH' :
		match_transaction();
		break;

	 default :
		break;
	}
 });



//getting item cost elements

 function getCostElement(json_url, cost_element_type, row_class) {
	switch (cost_element_type) {
	 case 'MAT' :
		var className = 'bom_material_element';
		break;

	 case 'MOH' :
	 case 'OH' :
		var className = 'bom_overhead';
		break;

	 case 'RES' :
		var className = 'bom_resource';
		break;

	 case 'default':
		var className = false;
		break;
	}

	if (className === false) {
	 return;
	}

	$.ajax({
	 url: json_url,
	 type: 'get',
	 data: {
		class_name: className,
		element_type: cost_element_type,
		find_cost_elements: '1'
	 },
	 beforeSend: function() {
		$('.show_loading_small').show();
	 },
	 complete: function() {
		$('.show_loading_small').hide();
	 }
	}).done(function(result) {
	 var div = $(result).filter('div#cost_elements_find_all').html();
	 var asisClass = '.' + row_class;
	 var asisClass_d = asisClass.replace(/\s+/g, '.');
	 $("#content").find(asisClass_d).find('.cost_element_id').empty().append(div);
	}).fail(function() {
	 alert(" Cost Element Not Found!");
	});
 }

 $('#content').on('change', '.cost_element_type', function() {
	var json_url = 'modules/cst/item_cost/json_item_cost.php';
	var cost_element_type = $(this).val();
	var row_class = $(this).closest('tr').prop('class');
	getCostElement(json_url, cost_element_type, row_class);
 });
});