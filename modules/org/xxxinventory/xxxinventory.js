$(document).ready(function() {
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

//Get the inventory id on fly after clicking the submit header
  $('#submit_header').click(function() {
    var inventoryId = $('#inventory_id').val();
    $('#inventory_header').attr('action', 'inventory.php?inventory_id=' + inventoryId);
  });


//Get the inventory id on fly after clicking the submit line
  $('#submit_line').click(function() {
    var inventoryId = $('#inventory_id').val();
    $('#org_line').attr('action', 'inventory.php?inventory_id=' + inventoryId);
  });

  var objectCount = 1000;
  $("#add_object").click(function() {
    $("#form_box_line0").clone().attr("id", "new_object" + objectCount).appendTo($("#org_line"));
    $("#new_object" + objectCount + " .org_line_id").val("");
    objectCount++;
  }
  );
	 
	 save('json.inventory.php', '#inventory', '', 'inventory','#inventory_id');

});


//validate if the structure is selected
$("#balancing").change(function(){
if($("#inventory_structure").val()==""){
alert('First Select COA structure');
$("#balancing").val("");
}
});

$("#cost_center").change(function(){
if($("#inventory_structure").val()==""){
alert('First Select COA structure');
$("#cost_center").val("");
}
});

$("#natural_account").change(function(){
if($("#inventory_structure").val()==""){
alert('First Select COA structure');
$("#natural_account").val("");
}
});



//Show the segments after structure is selected
$("#inventory_structure").change(function() {
  $('#loading').show();
var inventory_Id = $("#inventory_structure").val();

$.ajax({
     url: '../../system/option/json.option.php?',
     data : { option_id_l : inventory_Id},
     type: 'get'
     }).done(function(result){
			
      var div = $(result).filter("div#inventory_json").html();
        $("#balancing").html(div);
        $("#cost_center").html(div);
        $("#natural_account").html(div);
        $("#inter_company").html(div);
        $("#segment1").append(div);
        $("#segment2").append(div);
        $("#segment3").append(div);
        $("#segment4").append(div);
        $('#loading').hide();
      }).fail(function(){
     alert("failed");
     $('#loading').hide();
     });
});

 
});  
