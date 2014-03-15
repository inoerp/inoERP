 function setValFromSelectPage(gl_ledger_id){
	this.gl_ledger_id = gl_ledger_id;
 }
 
setValFromSelectPage.prototype.setVal = function(){
 gl_ledger_id = this.gl_ledger_id;
 
 $("#gl_ledger_id").val(gl_ledger_id);
};
$(document).ready(function() {
 
//  var Mandatory_Fields = ["#org_id", "First Select Org Name", "#item_number", "First Select Item Number"];
// select_mandatory_fields(Mandatory_Fields);
//
// $('#form_line').on("click", function() {
//	if (!$('#ledger_id').val()) {
//	 alert('No header Id : First enter/save header details');
//	} else {
//	 var headerId = $('#ledger_id').val();
//	 if (!$(this).find('.ledger_id').val()) {
//		$(this).find('.ledger_id').val(headerId);
//	 }
//	}
//
// });
// 
 
 //Popup for selecting option type
   $("#gl_ledger_id_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=gl_ledger', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Check the option_id while entering the option line code
 function copy_ledger_id() {
	$(".sys_value_group_line_code").blur(function()
	{
	 if ($("#ledger_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".sys_value_group_line_code").val("");
	 } else {
		$(".ledger_id").val($("#ledger_id").val());
	 }
	});
 }
 
 //enable disbale parent & group
 $('.parent_cb').each(function(){
if($(this).is( ":checked" )){
$(this).closest('tr').find('.parent_line_id').attr('disabled','true');
}
});

$('body').on('change','.parent_cb', function(){
if($(this).is( ":checked" )){
$(this).closest('tr').find('.parent_line_id').attr('disabled','true');
}else{
$(this).closest('tr').find('.parent_line_id').removeAttr('disabled');
}
});


 copy_ledger_id();

 //Get the option_id on find button click
 $('a.show.gl_ledger_id').click(function() {
	var headerId = $('#gl_ledger_id').val();
	$(this).attr('href',  modepath() + 'gl_ledger_id=' + headerId);
 });

onClick_add_new_row('tr.gl_ledger_balancing_values0', 'tbody.gl_ledger_balancing_values_values', 2);

deleteData('json_ledger.php');

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'gl_legal_id';
 classContextMenu.docLineId = 'gl_ledger_balancing_values_id';
 classContextMenu.btn1DivId = 'gl_ledger_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'gl_ledger_balancing_values';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 2;
 classContextMenu.contextMenu();

 var ledgerSave = new saveMainClass();
 ledgerSave.json_url = 'form.php?class_name=gl_ledger';
 ledgerSave.form_header_id = 'gl_ledger';
 ledgerSave.primary_column_id = 'gl_ledger_id';
 ledgerSave.line_key_field = 'balancing_values';
 ledgerSave.form_line_id = 'gl_ledger_balancing_values';
 ledgerSave.single_line = false;
ledgerSave.saveMain();

});

