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
 
//  var Mandatory_Fields = ["#org_id", "First Select Org Name", "#item_number", "First Select Item Number"];
// select_mandatory_fields(Mandatory_Fields);
//
// $('#form_line').on("click", function() {
//	if (!$('#sys_value_group_header_id').val()) {
//	 alert('No header Id : First enter/save header details');
//	} else {
//	 var headerId = $('#sys_value_group_header_id').val();
//	 if (!$(this).find('.sys_value_group_header_id').val()) {
//		$(this).find('.sys_value_group_header_id').val(headerId);
//	 }
//	}
//
// });
 
 
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

 //Get the option_id on find button click
// $('a.show.sys_value_group_header_id').click(function() {
//	var headerId = $('#sys_value_group_header_id').val();
//  $(this).prop('href', modepath() + 'pageno=1&per_page=10&submit_search=Search&search_class_name=sys_value_group_line&search_asc_desc=desc&class_name=sys_value_group_line&sys_value_group_header_id=' + headerId);
////  $(this).attr('href', modepath() + 'sys_value_group_header_id=' + headerId);
// });

//onClick_add_new_row('tr.sys_value_group_line0', 'tbody.sys_value_group_line_values', 4);
//
////context menu
// var classContextMenu = new contextMenuMain();
// classContextMenu.docHedaderId = 'sys_value_group_header_id';
// classContextMenu.docLineId = 'sys_value_group_line_id';
// classContextMenu.btn1DivId = 'sys_value_group_header';
// classContextMenu.btn2DivId = 'form_line';
// classContextMenu.trClass = 'sys_value_group_line';
// classContextMenu.tbodyClass = 'sys_value_group_line_values';
// classContextMenu.noOfTabbs = 4;
// classContextMenu.contextMenu();
//
//
////deleteData('json.option.php');
//// save('json.value_group.php', '#sys_value_group_header', 'line_id_cb', 'code', '#sys_value_group_header_id');
// var classSave = new saveMainClass();
// classSave.json_url = 'form.php?class_name=sys_value_group_header';
// classSave.form_header_id = 'sys_value_group_header';
// classSave.primary_column_id = 'sys_value_group_header_id';
// classSave.line_key_field = 'code';
// classSave.single_line = false;
// classSave.savingOnlyHeader = false;
// classSave.enable_select = true;
// classSave.headerClassName = 'sys_value_group_header';
// classSave.lineClassName = 'sys_value_group_line';
// classSave.saveMain();
});

