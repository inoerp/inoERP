function setValFromSelectPage(ar_customer_id, customer_number, customer_name) {
 this.ar_customer_id = ar_customer_id;
 this.customer_number = customer_number;
 this.customer_name = customer_name;
}

setValFromSelectPage.prototype.setVal = function() {
 var ar_customer_id = this.ar_customer_id;
 var customer_number = this.customer_number;
 var customer_name = this.customer_name;

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
//selecting customer
 $(".ar_customer_id_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=ar_customer', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Popup for selecting address 
 $(".address_popup").click(function() {
	localStorage.addressPopupDivId = $(this).parent().siblings().first().attr("id");
	;
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
	if ($('#org_id').val().length > 0) {
	 var org_id = $('#org_id').val();
	 $(this).attr('href', modepath() + 'customer_number=' + customer_number + '&org_id=' + org_id);
	} else {
	 alert("Query Error!!! \n Select the query mode by pressing Ctrl + Q \n Select the organization name");
	}
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
