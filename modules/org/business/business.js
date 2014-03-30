function setValFromSelectPage(business_id, combination) {
 this.business_id = business_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var business_id = this.business_id;
 var combination = this.combination;
 if (business_id) {
	$("#business_id").val(business_id);
 }
  if (combination) {
	$("#cash_ac_id").val(combination);
 }
};


$(document).ready(function() {
 //selecting Id
 $(".business.select_popup").on("click", function() {
	void window.open('select.php?class_name=business', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the business_id on find button click
  $('#form_header a.show').click(function() {
    var business_id = $('#business_id').val();
    $(this).attr('href', modepath() + 'business_id=' + business_id);
  });

//popu for selecting accounts
 $('#content').on('click', '.account_popup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	var fieldClass = $(this).closest('td').find('.select_account').prop('class');
	localStorage.setItem("row_class", rowClass);
	localStorage.setItem("field_class", fieldClass);
	void window.open('select.php?class_name=coa_combination', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
	 	 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'business_id';
 classContextMenu.btn1DivId = 'business_id';
// classContextMenu.contextMenu();


 
 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=business';
 classSave.form_header_id = 'business';
 classSave.primary_column_id = 'business_id';
  classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
  classSave.headerClassName = 'business';
 classSave.saveMain();


});

