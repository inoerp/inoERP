$(document).ready(function() {

//var Mandatory_Fields = ["#customer_number", "First Enter Customer Number", "#customer_name", "First Enter Customer Name"];
// select_mandatory_fields_all('#customer_divId', Mandatory_Fields);
//
// //dont allow line entry with out bom_header id
// $('#form_line').on("click", function() {
//	if (!$('#ar_customer_id').val()) {
//	 alert('No header Id : First enter/save header details');
//	} else {
//	 var headerId = $('#ar_customer_id').val();
//	 if (!$(this).find('.ar_customer_id').val()) {
//		$(this).find('.ar_customer_id').val(headerId);
//	 }
//	}
// });
 
//selecting customer
 $(".ar_customer_id_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('find_customer.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
  function setParnetWindowValues(customerId, customerNumber, customerName, orgId)
 {
		if((typeof localStorage.idValue !=='undefined') &&(localStorage.idValue.length > 0)){
		var RowDivId = 'tr#'+localStorage.idValue;
	 window.opener.$(RowDivId).find(".ar_customer_id").val(customerId);
	 window.opener.$(RowDivId).find(".customer_number").val(customerNumber);
	 window.opener.$(RowDivId).find(".customer_name").val(customerName);
	 window.opener.$(RowDivId).find(".org_id").val(orgId);
	} else {
	 window.opener.$(".ar_customer_id").val(customerId);
	 window.opener.$(".customer_number").val(customerNumber);
	 window.opener.$(".customer_name").val(customerName);
	 window.opener.$(".org_id").val(orgId);
	}
 }

 $(".quick_select").on("click", function() {
	var customerId = $(this).val();
	var customerNumber = $(this).closest("td").siblings("td.customer_number").html();
	var customerName = $(this).closest("td").siblings("td.customer_name").html();
	var orgId = $(this).closest("td").siblings("td.org_id").html();
	setParnetWindowValues(customerId, customerNumber, customerName, orgId);
	window.close();
  window.opener.$('#ar_customer_id').trigger("focusout"); 
 });
 
 
 //Popup for selecting address 
 $(".address_popup").click(function() {
	localStorage.addressPopupDivId = $(this).parent().siblings().first().attr("id");;
	void window.open('../../org/address/find_address.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the ar_customer_id on refresh button click
 $('a.show.ar_customer_id').click(function() {
	var ar_customer_id = $('#ar_customer_id').val();
	$(this).attr('href', '?ar_customer_id=' + ar_customer_id);

 });

 $('a.show.customer_number').click(function() {
	var customer_number = $('#customer_number').val();
	if ($('#org_id').val().length > 0) {
	 var org_id = $('#org_id').val();
	 $(this).attr('href', '?customer_number=' + customer_number + '&org_id=' + org_id);
	} else {
	 alert("Query Error!!! \n Select the query mode by pressing Ctrl + Q \n Select the organization name");
	}
 });
 
  $('a.show.ar_customer_site_id').click(function() {
   var ar_customer_id = $('#ar_customer_id').val();
	 var ar_customer_site_id = $('#ar_customer_site_id').val();
$(this).attr('href', '?ar_customer_id=' + ar_customer_id +'&ar_customer_site_id=' + ar_customer_site_id);
 });
 
$("#customer_site_name").on("change", function(){ 
if($(this).val() == 'newentry'){
if (confirm("Do you want to create a new customer site?")) {
$(this).replaceWith('<input id="customer_site_name" class="textfield customer_site_name" type="text" size="25" maxlength="50" name="customer_site_name[]">');
$(".show.ar_customer_site_id").hide();
$("#ar_customer_site_id").val("");
$("#customer_site_number").val("");
}

}
});


//get the attachement form
get_attachment_form('../../../extensions/file/json.file.php');

//change the save & delete button values
 onClick_add_new_row('tr.customer0', 'tbody.customer_values', 3);

//Save record
save('json.customer.php', '#customer', '', 'customer', '#ar_customer_id', "#customer_site");

//delete line
 deleteData('json.customer.php');

});
