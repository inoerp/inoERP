function setValFromSelectPage(ar_customer_id, customer_number, customer_name,
				address_id, address_name, address, country, postal_code) {
 this.ar_customer_id = ar_customer_id;
 this.customer_number = customer_number;
 this.customer_name = customer_name;
 this.address_id = address_id;
 this.address_name = address_name;
 this.address = address;
 this.country = country;
 this.postal_code = postal_code;
}

setValFromSelectPage.prototype.setVal = function() {
 var ar_customer_id = this.ar_customer_id;
 var customer_number = this.customer_number;
 var customer_name = this.customer_name;
 var address_id = this.address_id;
 var address_name = this.address_name;
 var address = this.address;
 var country = this.country;
 var postal_code = this.postal_code;
 var addressPopupDivClass = '.' + localStorage.getItem("addressPopupDivClass");
 addressPopupDivClass = addressPopupDivClass.replace(/\s+/g, '.');
 if (address_id) {
	$('#content').find(addressPopupDivClass).find('.address_id').val(address_id);
 }
 if (address_name) {
	$('#content').find(addressPopupDivClass).find('.address_name').val(address_name);
 }
 if (address) {
	$('#content').find(addressPopupDivClass).find('.address').val(address);
 }
 if (country) {
	$('#content').find(addressPopupDivClass).find('.country').val(country);
 }
 if (postal_code) {
	$('#content').find(addressPopupDivClass).find('.postal_code').val(postal_code);
 }

 if (ar_customer_id) {
	$("#ar_customer_id").val(ar_customer_id);
 }
 if (customer_number) {
	$("#customer_number").val(customer_number);
 }
 if (customer_name) {
	$("#customer_name").val(customer_name);
 }

};


$(document).ready(function() {

 //Popup for selecting address 
 $(".address_popup").click(function() {
	var addressPopupDivClass = $(this).closest('div').prop('class');
	localStorage.setItem("addressPopupDivClass", addressPopupDivClass);
	void window.open('select.php?class_name=address', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the ar_customer_id on refresh button click
 $('a.show.ar_customer_id').click(function() {
	var ar_customer_id = $('#ar_customer_id').val();
	$(this).attr('href', modepath() + 'ar_customer_id=' + ar_customer_id);
 });

 $('a.show.customer_number').click(function() {
	var customer_number = $('#customer_number').val();
	$(this).attr('href', modepath() + 'customer_number=' + customer_number);
 });

 $('a.show.ar_customer_site_id').click(function() {
	var ar_customer_id = $('#ar_customer_id').val();
	var ar_customer_site_id = $('#ar_customer_site_id').val();
	$(this).attr('href', modepath() + 'ar_customer_id=' + ar_customer_id + '&ar_customer_site_id=' + ar_customer_site_id);
 });

 $("#customer_site_name").on("change", function() {
	if ($(this).val() === 'newentry') {
	 if (confirm("Do you want to create a new customer site?")) {
		$(this).replaceWith('<input id="customer_site_name" class="textfield customer_site_name" type="text" size="25" maxlength="50" name="customer_site_name[]">');
		$(".show.ar_customer_site_id").hide();
		$("#ar_customer_site_id").val("");
		$("#customer_site_number").val("");
	 }

	}
 });


//context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'ar_customer_id';
 classContextMenu.docLineId = 'ar_customer_line_id';
 classContextMenu.btn1DivId = 'ar_customer';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'ar_customer_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 1;
// classContextMenu.contextMenu();

//FILE attachment
 var fu = new fileUploadMain();
 fu.json_url = 'extensions/file/upload.php';
 fu.module_name = 'ar';
 fu.class_name = 'customer';
 fu.document_type = 'customer';
// fu.directory = 'ar/customer';
 fu.fileUpload();


//Save record
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=ar_customer';
 classSave.form_header_id = 'customer_header';
 classSave.primary_column_id = 'ar_customer_id';
 classSave.line_key_field = 'customer_site_name';
 classSave.single_line = true;
 classSave.form_line_id = 'customer_site';
 classSave.enable_select = true;
 if (!$('#ar_customer_id').val()) {
	classSave.savingOnlyHeader = true;
 } else {
	classSave.savingOnlyHeader = false;
 }
 classSave.headerClassName = 'ar_customer';
 classSave.lineClassName = 'ar_customer_site';
 classSave.saveMain();

//delete line
 deleteData('json.customer.php');

});
