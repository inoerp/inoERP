$(document).ready(function() {

 $('.line_id_cb').on('click', function() {
	var trClass = '.'+$(this).closest('tr').attr('class');
	var sd_so_header_id = $('#form_line').find(trClass).find('.sd_so_header_id').val();
 $('.line_id_cb:checked').each(function() {
	var trClass = '.'+$(this).closest('tr').attr('class');
	if($('#form_line').find(trClass).find('.sd_so_header_id').val() === sd_so_header_id){
	 return;
	}else{
	 alert('You can select only lines from one order to import from this form!\nTo import all lines from different orders use the import ar transaction program');
	  $('.line_id_cb:checked').attr('checked',false);
	 return false;
	}
 });
 });
 
 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.trClass = 'multi_select_value_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 4;
 classContextMenu.contextMenu();

});
