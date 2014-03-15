$(document).ready(function() {
 var Mandatory_Fields = ["#org_id", "First Select Org Name", "#item_number", "First Select Item Number"];
 select_mandatory_fields(Mandatory_Fields);

 $('#form_line').on("click", function() {
	if (!$('#bom_routing_header_id').val()) {
	 alert('No header Id : First enter/save header details');
	} else {
	 var PO_ID = $('#bom_routing_header_id').val();
	 if (!$(this).find('.bom_routing_header_id').val()) {
		$(this).find('.bom_routing_header_id').val(PO_ID);
	 }
	}

 });

 //copy header
 $('#content').on('click', '#copy_docHeader', function() {
	$('#bom_routing_header_id').val('');
	$('#bom_routing_number').val('');
	$('.bom_routing_line_id').val('');
	$('.bom_routing_detail_id').val('');
	$('#save').trigger('click');
 });
 //copy Line
 $('#content').on('click', '#copy_docLine', function() {
	var PO_ID = $('#bom_routing_header_id').val();
	$('#form_line').find('.bom_routing_header_id').val(PO_ID);
	$('#save').trigger('click');
 });


 //setting the first line & shipment number
// $('.routing_sequence:first').val('10');
// $('.resource_sequence:first').val('10');
 

//item number auto complete and bom_routingpulate the other details
 itemNumber_autoComplete('../../inv/item/item_search.php');

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
 $(".find_bom_routingpup.supplierId").on("click", function() {
	localStorage.idValue = "";
	void window.open('../ap/supplier/find_supplier.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 
//add or show linw details
 addOrShow_lineDetails('tr.bom_routing_line0');

 
 //Get the bom_routing_id on find button click
 $('#form_header a.show').click(function() {
	var bom_routingId = $('#bom_routing_header_id').val();
//$(this).prop('href','bom_routing.php?bom_routing_header_id=' + bom_routingId);
	$(this).attr('href', 'bom_routing.php?bom_routing_header_id=' + bom_routingId);
 });



 $("#content").on("click", ".add_row_img", function() {
	add_new_row('tr.bom_routing_line0', 'tbody.form_data_line_tbody', 3);
	$(".tabsDetail").tabs();
 });

 onClick_addDetailLine('tr.bom_routing_detail0-0', 'tbody.form_data_detail_tbody', 4);

//remove bom_routing lines
 $("#remove_row").click(function() {
	$('input[name="bom_routing_line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').remove();
	});
 });

//get the attachement form
 get_attachment_form('../../extensions/file/json.file.php');
 deleteData('json.bom_routing.php');
 save('json.bom_routing.php', '#bom_routing_header', 'line_id_cb', 'item_description', '#bom_routing_header_id', '', '#bom_routing_number');

});
