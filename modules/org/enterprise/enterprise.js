$(document).ready(function() {

//Popup for selecting enterprise name
  $(".popup").click(function() {
    void window.open('find_enterprise.php', '_blank',
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
	$(window.opener.document).find("#enterprise_id").val(findElement);
	$('#form_box a.show').prop('href', 'enterprise.php?user_id=' + findElement);
 }
 
 //Get the enterprise_id on find button click
  $('#form_header a.show').click(function() {
    var enterpriseId = $('#enterprise_id').val();
    $(this).attr('href', '?enterprise_id=' + enterpriseId);
  });

//Get the enterprise id on fly after clicking the submit header
  $('#submit_header').click(function() {
    var enterpriseId = $('#enterprise_id').val();
    $('#enterprise_header').attr('action', 'enterprise.php?enterprise_id=' + enterpriseId);
  });


//Get the enterprise id on fly after clicking the submit line
  $('#submit_line').click(function() {
    var enterpriseId = $('#enterprise_id').val();
    $('#org_line').attr('action', 'enterprise.php?enterprise_id=' + enterpriseId);
  });

  var objectCount = 1000;
  $("#add_object").click(function() {
    $("#form_box_line0").clone().attr("id", "new_object" + objectCount).appendTo($("#org_line"));
    $("#new_object" + objectCount + " .org_line_id").val("");
    objectCount++;
  }
  );
	 
	 save('json.enterprise.php', '#enterprise', '', 'enterprise','#enterprise_id');

});

