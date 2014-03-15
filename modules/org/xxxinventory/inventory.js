$(document).ready(function() {

//Popup for selecting inventory name
  $(".popup").click(function() {
    void window.open('find_inventory.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
    return false;
  });

 //send adddess from child to parent window
 $(".quick_select").click(function() {
	var findElement = $(this).val();
	parentWindow(findElement);
	window.close();
 });

 function parentWindow(findElement)
 {
	$(window.opener.document).find("#inventory_id").val(findElement);
	$('#form_box a.show').prop('href', 'inventory.php?inventory_id=' + findElement);
 }
 
 //Get the inventory_id on find button click
  $('#form_header a.show').click(function() {
    var inventoryId = $('#inventory_id').val();
    $(this).attr('href', '?inventory_id=' + inventoryId);
  });

	 save('json.inventory.php', '#inventory', '', 'inventory','#inventory_id');

});

