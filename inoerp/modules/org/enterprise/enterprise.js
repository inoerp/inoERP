function setValFromSelectPage(enterprise_id, combination) {
 this.enterprise_id = enterprise_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var enterprise_id = this.enterprise_id;
 var combination = this.combination;
 if (enterprise_id) {
	$("#enterprise_id").val(enterprise_id);
 }
  if (combination) {
	$("#cash_ac_id").val(combination);
 }
};


$(document).ready(function() {
 //selecting Id
 $(".enterprise_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=enterprise', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the enterprise_id on find button click
  $('a.show.enterprise_id').click(function() {
    var enterprise_id = $('#enterprise_id').val();
    $(this).attr('href', modepath() + 'enterprise_id=' + enterprise_id);
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
 classContextMenu.docHedaderId = 'enterprise_id';
 classContextMenu.btn1DivId = 'enterprise_id';
 classContextMenu.contextMenu();


 
 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=enterprise';
 classSave.form_header_id = 'enterprise';
 classSave.primary_column_id = 'enterprise_id';
  classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
  classSave.headerClassName = 'enterprise';
 classSave.saveMain();


});

