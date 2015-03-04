function setValFromSelectPage(ar_transaction_type_id, combination) {
 this.ar_transaction_type_id = ar_transaction_type_id;
this.combination = combination;
}


setValFromSelectPage.prototype.setVal = function() {
 var ar_transaction_type_id = this.ar_transaction_type_id;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (ar_transaction_type_id) {
	$("#ar_transaction_type_id").val(ar_transaction_type_id);
 }
  var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
  if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
 if(this.ar_transaction_type_id){
  $('a.show.ar_transaction_type_id').trigger('click');
 }
};

//get Document Type Details
function getDocumentTypeDetails(json_url, ar_transaction_type_id) {
 json_url = (typeof json_url !== 'undefined') ? json_url : 'modules/sd/document_type/json_document_type.php';
 ar_transaction_type_id = (typeof ar_transaction_type_id !== 'undefined') ? ar_transaction_type_id : '1';
 $.ajax({
	url: json_url,
	type: 'get',
	dataType: 'json',
	data: {
	 ar_transaction_type_id: ar_transaction_type_id,
	 find_document_detail: true,
	},
	success: function(result) {
	 var items = [];
	 var option_stmt = '<option value=""></option>';
	 $.each(result, function(key, val) {
		option_stmt += '<option value="' + val.org_id + '">' + val.org + '</option>';
		items.push("<li id='" + key + "'>" + val + "</li>");
	 });
	 var org_type_id = '#' + org_type + '_id';
	 $(org_type_id).removeAttr('disabled');
	 $(org_type_id).empty().append(option_stmt);
	},
	complete: function() {
	 $('.show_loading_small').hide();
	},
	beforeSend: function() {
	 $('.show_loading_small').show();
	},
	error: function(request, errorType, errorMessage) {
	 alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
	}
 });
}

$(document).ready(function() {
 //selecting Id
 $(".ar_transaction_type_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=ar_transaction_type', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});