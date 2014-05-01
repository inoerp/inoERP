function setValFromSelectPage(wip_accounting_group_id, combination) {
 this.wip_accounting_group_id = wip_accounting_group_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var wip_accounting_group_id = this.wip_accounting_group_id;
 var combination = this.combination;
 if (wip_accounting_group_id) {
	$("#wip_accounting_group_id").val(wip_accounting_group_id);
 }
 if (combination) {
	$("#cash_ac_id").val(combination);
 }
};


$(document).ready(function() {
 //selecting Id
 $(".wip_accounting_group.select_popup").on("click", function() {
	void window.open('select.php?class_name=wip_accounting_group', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the wip_accounting_group_id on find button click
 $('#form_header a.show').click(function() {
	var wip_accounting_group_id = $('#wip_accounting_group_id').val();
	$(this).attr('href', modepath() + 'wip_accounting_group_id=' + wip_accounting_group_id);
 });

//context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'wip_accounting_group_id';
 classContextMenu.btn1DivId = 'wip_accounting_group_id';
 classContextMenu.contextMenu();



 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=wip_accounting_group';
 classSave.form_header_id = 'wip_accounting_group';
 classSave.primary_column_id = 'wip_accounting_group_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'wip_accounting_group';
 classSave.saveMain();


});

