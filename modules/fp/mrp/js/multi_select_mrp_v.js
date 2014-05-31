$(document).ready(function() {

 $('#content').on('click', '.line_id_cb', function() {
	if ($(this).closest('tr').find('.order_action').val() === 'None') {
	 alert('This line is not available for release\nOrder action is None');
	 $(this).attr('checked', false);
	}
 });

 $('.order_action').each(function() {
	if ($(this).val() === 'None') {
	 $(this).closest('tr').find('input').each(function() {
		$(this).css('background-color', '#ffb13c');
	 });
	}
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.trClass = 'multi_select_value_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 4;
 classContextMenu.contextMenu();

});
