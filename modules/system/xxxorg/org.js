$(document).ready(function() {

  //basic finction --making background colors for form fields
  $("input").focus(function() {
    $(this).css("background-color", "#cccccc");
  });
  $("input").blur(function() {
    $(this).css("background-color", "#ffffff");
  });
  $("input:required").css("background-color", "pink");
  $("input:required").focus(function() {
    $(this).css("background-color", "pink");
  });
  $("input:required").blur(function() {
    $(this).css("background-color", "pink");
  });
  $("input:disabled").css("background-color", "yellow");
  
  //end of basic functions

//controlling org type values - what can be entered

$("#org_type").change(function(){
var selectedVal = $(this).val();
if(selectedVal=="ENTERPRISE"){
$("#enterprise").val("ENTERPRISE");
$("#enterprise").attr("disabled",true);
$("#legal_org").val("ENTERPRISE");
$("#legal_org").attr("disabled",true);
$("#bo").val("ENTERPRISE");
$("#bo").attr("disabled",true);
$("input:disabled").css("background-color", "yellow");
}

if(selectedVal=="LEGAL_ORG"){
$("#legal_org").val("LEGAL_ORG");
$("#legal_org").attr("disabled",true);
$("#bo").val("LEGAL_ORG");
$("#bo").attr("disabled",true);
$("input:disabled").css("background-color", "yellow");
}

if(selectedVal=="BUSINESS_ORG"){
$("#bo").val("BUSINESS_ORG");
$("#bo").attr("disabled",true);
$("input:disabled").css("background-color", "yellow");
}
});

//Popup for selecting option type
  $(".popup").click(function() {
    void window.open('find_option.php', '_blank',
            'width=700,height=500,toolbar=0,menubar=0,location=0,status=1,scrollbars=1,resizable=1,left=0,top=0');
    return false;
  })

  $("#selected").click(function() {
    var findElement = $(".select_option_id:checked").val();
    window.opener.parentWindow(findElement);
    window.close();
  });

  //Get the option_id on find button click
  $('#form_box a.show').click(function() {
    var optionId = $('#option_id').val();
//$(this).prop('href','option.php?option_id_l=' + optionId);
    $(this).attr('href', 'option.php?option_id_l=' + optionId);
  });

//Get the option id on fly after clicking the submit header
  $('#submit_header').click(function() {
    var optionId = $('#option_id').val();
    $('#option_header').attr('action', 'option.php?option_id_l=' + optionId);
  });


//Get the option id on fly after clicking the submit line
  $('#submit_line').click(function() {
    var optionId = $('#option_id').val();
    $('#option_line').attr('action', 'option.php?option_id_l=' + optionId);
  });

  var objectCount = 1000;
  $("#add_object").click(function() {
    $("#form_box_line0").clone().attr("id", "new_object" + objectCount).appendTo($("#option_line"));
    $("#new_object" + objectCount + " .option_line_id").val("");
    objectCount++;
  }
  );

});

