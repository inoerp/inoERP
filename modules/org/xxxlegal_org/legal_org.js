$(document).ready(function() {
  $('#loading').hide();
//hiding the loader
var $loader = $('#loading'), timer;
$loader.hide().ajaxStart(function()
    {
        timer && clearTimeout(timer);
        timer = setTimeout(function()
        {
            $loader.show();
        },
        10000);
    }).ajaxStop(function()
    {
        clearTimeout(timer);
        $loader.hide();
    });
//creating tabs
$(function() {
    $( "#tabs" ).tabs();
  });
  
//Refresh the page
$('.refresh').click(function() {
    location.reload(true);
});

//validate if the structure is selected
$("#balancing").change(function(){
if($("#legal_org_structure").val()==""){
alert('First Select COA structure');
$("#balancing").val("");
}
});

$("#cost_center").change(function(){
if($("#legal_org_structure").val()==""){
alert('First Select COA structure');
$("#cost_center").val("");
}
});

$("#natural_account").change(function(){
if($("#legal_org_structure").val()==""){
alert('First Select COA structure');
$("#natural_account").val("");
}
});



//Show the segments after structure is selected
$("#legal_org_structure").change(function() {
  $('#loading').show();
var legal_orgId = $("#legal_org_structure").val();

$.ajax({
     url: '../../system/option/json.option.php?',
     data : { option_id_l : legal_orgId},
     type: 'get'
     }).done(function(data){
     var div = $('#legal_org_json', $(data)).html();
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

//function to get value in parent window from child
  function getLegalId(legalId)
  {
     window.opener.$("#legal_org #legal_id").val(legalId);
     $('#legal_org #form_box a.show').prop('href', 'legal_org.php?legal_id=' + legalId);
   }

//Popup for selecting existing COA 
  $(".popup").click(function() {
    void window.open('find_legal_org.php', '_blank',
            'width=700,height=500,toolbar=0,menubar=0,location=0,status=1,scrollbars=1,resizable=1,left=0,top=0');
    return false;
  });

  $("#selected").click(function() {
    var legalId = $(".select_legal_id:checked").val();
    getLegalId(legalId);  
    window.close();
  });

  $(".quick_select").click(function() {
    var legalId = $(this).val();
    getLegalId(legalId);  
    window.close();
  });
  
  //Get the legal_org_id on find button click
  $('#legal_org #form_box a.show').click(function() {
    var legalId = $('#legal_id').val();
//$(this).prop('href','legal_org.php?legal_id=' + moduleId);
    $(this).attr('href', 'legal_org.php?legal_id=' + legalId);
  });

//Get the legal_org id on fly after clicking the submit header
//enables the account field
  $('#legal_org #submit_header').click(function() {
//    $(".account_type").attr("disabled",false);
    var legalId = $('#legal_org_id').val();
    $('#legal_id').attr('action', 'legal_org.php?legal_id=' + legalId);
  });

//script for legal_org_segment_values.php
//change the save & delete button values

 
});  











