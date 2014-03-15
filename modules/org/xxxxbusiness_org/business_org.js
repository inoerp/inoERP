$(document).ready(function() {

//Popup for selecting business_org name
  $(".popup").click(function() {
    void window.open('find_business_org.php', '_blank',
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
	$(window.opener.document).find("#business_id").val(findElement);
	$('#form_box a.show').prop('href', 'business_org.php?user_id=' + findElement);
 }
 
 //Get the business_id on find button click
  $('#form_header a.show').click(function() {
    var business_orgId = $('#business_id').val();
    $(this).attr('href', '?business_id=' + business_orgId);
  });

//Get the business_org id on fly after clicking the submit header
  $('#submit_header').click(function() {
    var business_orgId = $('#business_id').val();
    $('#business_org_header').attr('action', 'business_org.php?business_id=' + business_orgId);
  });


//Get the business_org id on fly after clicking the submit line
  $('#submit_line').click(function() {
    var business_orgId = $('#business_id').val();
    $('#org_line').attr('action', 'business_org.php?business_id=' + business_orgId);
  });

  var objectCount = 1000;
  $("#add_object").click(function() {
    $("#form_box_line0").clone().attr("id", "new_object" + objectCount).appendTo($("#org_line"));
    $("#new_object" + objectCount + " .org_line_id").val("");
    objectCount++;
  }
  );
	 
	 save('json.business_org.php', '#business_org', '', 'business_org','#business_id');

});

