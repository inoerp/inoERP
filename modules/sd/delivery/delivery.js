function setValFromSelectPage(sd_delivery_header_id, sd_delivery_line_id, ar_customer_id, ar_customer_number,
				ar_customer_name, ar_customer_site_id, ar_customer_site_name, ar_customer_site_number,
				item_id, item_number, item_description, uom_id, sd_so_header_id, sd_so_line_id, po_detail_id,
				sd_number, line_number, shipment_number, quantity, shipped_quantity) {
 this.sd_delivery_header_id = sd_delivery_header_id;
 this.sd_delivery_line_id = sd_delivery_line_id;
 this.ar_customer_id = ar_customer_id;
 this.ar_customer_number = ar_customer_number;
 this.ar_customer_name = ar_customer_name;
 this.ar_customer_site_id = ar_customer_site_id;
 this.ar_customer_site_name = ar_customer_site_name;
 this.ar_customer_site_number = ar_customer_site_number;
 this.item_id = item_id;
 this.item_number = item_number;
 this.item_description = item_description;
 this.uom_id = uom_id;
 this.sd_so_header_id = sd_so_header_id;
 this.sd_so_line_id = sd_so_line_id;
 this.po_detail_id = po_detail_id;
 this.sd_number = sd_number;
 this.line_number = line_number;
 this.shipment_number = shipment_number;
 this.quantity = quantity;
 this.shipped_quantity = shipped_quantity;
}

setValFromSelectPage.prototype.setVal = function() {
 var sd_delivery_header_id = this.sd_delivery_header_id;
 var sd_delivery_line_id = this.sd_delivery_line_id;
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 if (sd_delivery_header_id === -1) {
	alert('Selected delivery is assigned to a differnt delivery number');
	return;
 }
 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');

 if (sd_delivery_line_id) {
	$('#content').find(rowClass).find('.sd_delivery_line_id').val(sd_delivery_line_id);
 }

 if (sd_delivery_header_id) {
	$('#sd_delivery_header_id').val(sd_delivery_header_id);
 }


 var item_obj = [{id: 'item_id', data: this.item_id},
	{id: 'sd_so_line_id', data: this.sd_so_line_id},
	{id: 'item_number', data: this.item_number},
	{id: 'item_description', data: this.item_description},
	{id: 'uom_id', data: this.uom_id}
 ];

 var customer_obj = [{id: 'ar_customer_id', data: this.ar_customer_id},
	{id: 'ar_customer_site_id', data: this.ar_customer_site_id},
	{id: 'ar_customer_number', data: this.ar_customer_number},
	{id: 'ar_customer_name', data: this.ar_customer_name},
	{id: 'ar_customer_site_number', data: this.ar_customer_site_number},
	{id: 'ar_customer_site_name', data: this.ar_customer_site_name}
 ];

 var so_obj = [{id: 'sd_so_header_id', data: this.sd_so_header_id},
	{id: 'sd_so_line_id', data: this.sd_so_line_id},
	{id: 'po_detail_id', data: this.po_detail_id},
	{id: 'sd_number', data: this.sd_number},
	{id: 'shipment_number', data: this.shipment_number},
	{id: 'sd_so_line_number', data: this.line_number},
	{id: 'shipment_number', data: this.shipment_number},
	{id: 'shipped_quantity', data: this.shipped_quantity},
	{id: 'quantity', data: this.quantity}
 ];

 $(customer_obj).each(function(i, value) {
	if (value.data) {
	 var fieldClass = '.' + value.id;
	 $('#content').find(rowClass).find(fieldClass).val(value.data);
	}
 });

 $(item_obj).each(function(i, value) {
	if (value.data) {
	 var fieldClass = '.' + value.id;
	 $('#content').find(rowClass).find(fieldClass).val(value.data);
	}
 });

 $(so_obj).each(function(i, value) {
	if (value.data) {
	 var fieldClass = '.' + value.id;
	 $('#content').find(rowClass).find(fieldClass).val(value.data);
	}
 });

 localStorage.removeItem("row_class");
 localStorage.removeItem("row_class");

};

$(document).ready(function() {

//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'sd_delivery_header_id';
// mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["bu_org_id", "receipt_type_id"];
 mandatoryCheck.mandatory_messages = ["First Select BU Org", "No Receipt Type"];
// mandatoryCheck.mandatoryField();

//verify entered qty is less than open quantity
 $('#content').on('change', '.shipped_quantity', function() {
	var newQty = $(this).val();
	var shipmentQty = $(this).closest('tr').find('.quantity').val();
	var poReceivedQty = $(this).closest('tr').find('.po_shipped_quantity').val();
	if ((+poReceivedQty + +newQty) > shipmentQty) {
	 alert('Entered quantity is more than open quantity!');
	 $(this).val('');
	 $(this).focus();
	}
 });

//Default header values to line
 $('#content').on('change', '.transaction_quantity', function() {
	var trClass = '.' + $(this).closest('tr').prop('class');
	trClass = trClass.replace(/\s+/g, '.');
	$(this).closest('.tabContainer').find(trClass).find('.transaction_type_id').val($('#transaction_type_id').val());
	$(this).closest('.tabContainer').find(trClass).find('.org_id').val($('#org_id').val());
	$(this).closest('.tabContainer').find(trClass).find('.sd_delivery_header_id').val($('#sd_delivery_header_id').val());
 });


//popu for delivery lines
 $('#content').on('click', '.select_delivery_line.select_popup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	var fieldClass = $(this).closest('td').find('.select_sd_number').prop('class');
	localStorage.setItem("row_class", rowClass);
	localStorage.setItem("field_class", fieldClass);
	var openUrl = 'select.php?class_name=sd_delivery_line&sd_delivery_header_id=-1';
	void window.open(openUrl, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //selecting Header Id
 $(".sd_delivery_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sd_delivery_header&status=AWAITING_SHIPPING', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 //Get the receipt_id on find button click
 $('a.show.sd_delivery_header').click(function() {
	var receiptId = $('#sd_delivery_header_id').val();
	$(this).attr('href', modepath() + 'sd_delivery_header_id=' + receiptId);
 });

 $("#content").on("click", ".add_row_img", function() {
	var addNewRow = new add_new_rowMain();
	addNewRow.trClass = 'sd_delivery_line';
	addNewRow.tbodyClass = 'form_data_line_tbody';
	addNewRow.noOfTabs = 5;
	addNewRow.removeDefault = true;
	addNewRow.add_new_row();
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'sd_delivery_header_id';
 classContextMenu.docLineId = 'sd_delivery_line_id';
 classContextMenu.btn1DivId = 'receipt_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'receipt_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 5;
 classContextMenu.contextMenu();


 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=sd_delivery_header';
 classSave.form_header_id = 'sd_delivery_header';
 classSave.primary_column_id = 'sd_delivery_header_id';
 classSave.line_key_field = 'sd_so_line_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'sd_delivery_header';
 classSave.lineClassName = 'sd_delivery_line';
 classSave.enable_select = true;
 classSave.saveMain();


 $('#action').on('change', function() {
	var actionValue = $(this).val();
	$('input[name="line_id_cb"]:checked').each(function() {
	 $(this).closest('tr').find('.action').val(actionValue);
	});
	switch (actionValue) {
	 case 'COMPLETE_SHIPMENT' :
		if (confirm("Do you want to ship all the lines?")) {
		 $('.action').val(actionValue);
		 $('input[name="line_id_cb"]').each(function() {
			$(this).prop('checked', true);
		 });
		} else {
		 alert('No Line Selected For Shipment\nRemove/Reverse the required lines and the select the shipment action again');
		 $('.action').val('');
		}

		break;

	 default :
		break;
	}
 });

});
