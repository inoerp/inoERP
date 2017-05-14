 function setValFromSelectPage(gl_ledger_id){
	this.gl_ledger_id = gl_ledger_id;
 }
 
setValFromSelectPage.prototype.setVal = function(){
 gl_ledger_id = this.gl_ledger_id;
 
 $("#gl_ledger_id").val(gl_ledger_id);
};

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
 
$(document).ready(function() {
 //Popup for selecting option type
   $(".gl_ledger_id.select_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=gl_ledger', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 
 $('#coa_id').on('change', function(){
  var coa_structure_id = $(this).find('option:selected').data('coa_structure_id');
  $('#coa_structure_id').val(coa_structure_id);
});

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

 

});

