$(document).ready(function() {

 $('.line_id_cb').on('click', function() {
	var Onhand = +$(this).closest('tr').find('.onhand').val();
	var lineQuantity = +$(this).closest('tr').find('.line_quantity').val();
	if (Onhand < lineQuantity) {
	 $(this).attr('checked', false);
	 alert('Available Onhand is less than line quantity');
	}
 });
 
 $('.line_id_cb').each(function() {
		var Onhand = +$(this).closest('tr').find('.onhand').val();
	var lineQuantity = +$(this).closest('tr').find('.line_quantity').val();
	if (Onhand < lineQuantity) {
	 $(this).closest('tr').find('input').each(function() {
		$(this).css('background', 'rgba(255,40,0,0.5)');
	 });
	}else{
	 	 $(this).closest('tr').find('input').each(function() {
		$(this).css('background', 'rgba(204,255,153,0.8)');
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
