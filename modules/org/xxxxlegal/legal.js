$(document).ready(function() {

//Popup for selecting legal name
  $(".popup").click(function() {
    void window.open('find_legal.php', '_blank',
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
	$(window.opener.document).find("#legal_id").val(findElement);
	$('#form_box a.show').prop('href', 'legal.php?legal_id=' + findElement);
 }
 
 //Get the legal_id on find button click
  $('#form_header a.show').click(function() {
    var legalId = $('#legal_id').val();
    $(this).attr('href', '?legal_id=' + legalId);
  });

	 save('json.legal.php', '#legal', '', 'legal','#legal_id');

});

