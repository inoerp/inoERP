 function setValFromSelectPage(sys_value_group_header_id){
	this.sys_value_group_header_id = sys_value_group_header_id;
 }
 
setValFromSelectPage.prototype.setVal = function(){
 sys_value_group_header_id = this.sys_value_group_header_id;
 $("#sys_value_group_header_id").val(sys_value_group_header_id);
};


 //Check the option_id while entering the option line code
 function copy_sys_value_group_header_id() {
	$(".sys_value_group_line_code").blur(function()
	{
	 if ($("#sys_value_group_header_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".sys_value_group_line_code").val("");
	 } else {
		$(".sys_value_group_header_id").val($("#sys_value_group_header_id").val());
	 }
	});
 }
 

$(document).ready(function() {
 
 //Popup for selecting option type
  $(".sys_value_group_header_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=sys_value_group_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
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


 copy_sys_value_group_header_id();

});