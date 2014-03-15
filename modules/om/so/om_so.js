$(document).ready(function() {
 var Mandatory_Fields = ["#bu_org_id", "First Select BU Name", "#om_so_type", "First Select PO Type"];
 select_mandatory_fields(Mandatory_Fields);

 $('#form_line').on("click", function() {
	if (!$('#om_so_header_id').val()) {
	 alert('No header Id : First enter/save header details');
	} else {
	 var PO_ID = $('#om_so_header_id').val();
	 if (!$(this).find('.om_so_header_id').val()) {
		$(this).find('.om_so_header_id').val(PO_ID);
	 }
	}

 });

 //copy header
 $('#content').on('click', '#copy_docHeader', function() {
	$('#om_so_header_id').val('');
	$('#om_so_number').val('');
	$('.om_so_line_id').val('');
	$('.om_so_detail_id').val('');
	$('#save').trigger('click');
 });
 //copy Line
 $('#content').on('click', '#copy_docLine', function() {
	var PO_ID = $('#om_so_header_id').val();
	$('#form_line').find('.om_so_header_id').val(PO_ID);
	$('#save').trigger('click');
 });


 //setting the first line & shipment number
 $('.line_number:first').val('1');
 $('.shipment_number:first').val('1');
// $('.need_by_date:first').datepicker("setDate", new Date());
// $('.promise_date:first').datepicker("setDate", new Date());
 

 //default quantity
 $("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
	var lineQuantity = $(this).closest('tr').find('.line_quantity:first').val();
	if (!$(this).closest("td").find(".quantity:first").val())
	{
	 $(this).closest("td").find(".quantity:first").val(lineQuantity);
	}
 });

//set the line price
 $('#content').on('focusout', '.unit_price', function() {
	var unitPrice = $(this).val();
	var trClass = '.' + $(this).closest('tr').attr('class');
	var lineQuantity = ($(this).closest('.tabContainer').find(trClass).find('.line_quantity').val());
	var linePrice = unitPrice * lineQuantity;
	$(this).closest('tr').find('.line_price').val(linePrice);
 });

//get supplier details
 $("#supplier_id").on("focusout", function() {
	var bu_org_id = $("#bu_org_id").val();
	getSupplierDetails('../ap/supplier/json.supplier.php', bu_org_id);
 });

//supplier name auto complete and om_sopulate the other details
 supplierName_autoComplete('../ap/supplier/supplier_search.php');

//item number auto complete and om_sopulate the other details
 itemNumber_autoComplete('../inv/item/item_search.php');

 $("#supplier_name").on("focusout", function() {
	if ($("#supplier_site_id").val().length === 0) {
	 var bu_org_id = $("#bu_org_id").val();
	 getSupplierDetails('../ap/supplier/json.supplier.php', bu_org_id);
	}
 });

 $("#content").on("change", "#supplier_site_id", function() {
	var supplier_site_id = $("#supplier_site_id").val();
	getSupplierSiteDetails('../ap/supplier/json.supplier.php', supplier_site_id);
 });



//selecting supplier
 $(".find_om_sopup.supplierId").on("click", function() {
	localStorage.idValue = "";
	void window.open('../ap/supplier/find_supplier.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //Popup for selecting address 
 $(".address_om_sopup").click(function() {
	localStorage.addressPopupDivId = $(this).parent().siblings().first().attr("id");
	;
	void window.open('../../org/address/find_address.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the supplier_id on refresh button click
 $('a.show.om_so_header_id').click(function() {
	var om_so_header_id = $('#om_so_header_id').val();
	$(this).attr('href', '?om_so_header_id=' + om_so_header_id);

 });

 $('a.show.supplier_number').click(function() {
	var supplier_number = $('#supplier_number').val();
	if ($('#org_id').val().length > 0) {
	 var org_id = $('#org_id').val();
	 $(this).attr('href', '?supplier_number=' + supplier_number + '&org_id=' + org_id);
	} else {
	 alert("Query Error!!! \n Select the query mode by pressing Ctrl + Q \n Select the organization name");
	}
 });

 $('a.show.supplier_site_id').click(function() {
	var supplier_id = $('#headerId').val();
	var supplier_site_id = $('#supplier_site_id').val();
	$(this).attr('href', '?supplier_id=' + supplier_id + '&supplier_site_id=' + supplier_site_id);
 });

 $("#supplier_site_name").on("change", function() {
	if ($(this).val() == 'newentry') {
	 if (confirm("Do you want to create a new supplier site?")) {
		$(this).replaceWith('<input id="supplier_site_name" class="textfield supplier_site_name" type="text" size="25" maxlength="50" name="supplier_site_name[]">');
		$(".show.supplier_site_id").hide();
		$("#supplier_site_id").val("");
		$("#supplier_site_number").val("");
	 }

	}
 });


//add or show linw details
 addOrShow_lineDetails('tr.om_so_line0');

 //function to coply line to details
 function copy_line_to_details() {
	$("#content").on("click", "table.form_line_data_table .add_detail_values_img", function() {
	 var detailExists = $(this).closest("td").find(".form_detail_data_fs").length;
	 if (detailExists === 0) {
		var lineQuantity = $(this).closest('tr').find('.line_quantity').val();
		$(this).closest("td").find(".quantity:first").val(lineQuantity);
	 }
	});
 }

 copy_line_to_details();

  $("#content").on("focusout", '.ship_to_inventory', function() {
	var ship_to_inventory = $(this).val();
	var rowTrClass = $(this).closest("tr").attr("class");
	var classValue = "tr." + rowTrClass;
	var classValue1 = classValue.replace(/ /g,'.');
	getAllInventoryAccounts('../org/inventory/json.inventory.php', ship_to_inventory, classValue1);
 });

 //Get the om_so_id on find button click
 $('#form_box a.show').click(function() {
	var om_soId = $('#om_so_header_id').val();
//$(this).prop('href','om_so.php?om_so_header_id=' + om_soId);
	$(this).attr('href', 'om_so.php?om_so_header_id=' + om_soId);
 });



 $("#content").on("click", ".add_row_img", function() {
	add_new_row('tr.om_so_line0', 'tbody.form_data_line_tbody', 3);
	$(".tabsDetail").tabs();
 });

 onClick_addDetailLine('tr.om_so_detail0-0', 'tbody.form_data_detail_tbody', 4);

//remove om_so lines
 $("#remove_row").click(function() {
	$('input[name="om_so_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

//get the attachement form
 get_attachment_form('../../extensions/file/json.file.php');
 deleteData('json.om_so.php');
 save('json.om_so.php', '#om_so_header', 'line_id_cb', 'item_description', '#om_so_header_id', '', '#om_so_number');

});
