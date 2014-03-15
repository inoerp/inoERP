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
if($("#coa_structure").val()==""){
alert('First Select COA structure');
$("#balancing").val("");
}
});

$("#cost_center").change(function(){
if($("#coa_structure").val()==""){
alert('First Select COA structure');
$("#cost_center").val("");
}
});

$("#natural_account").change(function(){
if($("#coa_structure").val()==""){
alert('First Select COA structure');
$("#natural_account").val("");
}
});



//Show the segments after structure is selected
$("#coa_structure").change(function() {
  $('#loading').show();
var coaId = $("#coa_structure").val();

$.ajax({
     url: '../../system/option/json.option.php?',
     data : { option_id_l : coaId},
     type: 'get'
     }).done(function(data){
     var div = $('#coa_json', $(data)).html();
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
  function getCoaSegmentValuesId(coaIdNameStructure)
  {
     var first_separation=coaIdNameStructure.indexOf("||");
     var second_separation=coaIdNameStructure.indexOf("|1|");
     var coaIdNameStructure_len=coaIdNameStructure.length;
     var coaId=coaIdNameStructure.substr(0,first_separation);
     var coaName=coaIdNameStructure.substr(first_separation + 2,second_separation - 3);
     var coaStructure=coaIdNameStructure.substr(second_separation + 3,coaIdNameStructure_len);
    window.opener.$("#coa_segment_values #coa_id").val(coaId);
    window.opener.$("#coa_segment_values #coa_name").val(coaName);
    window.opener.$("#coa_segment_values #coa_structure_id").val(coaStructure);
    $("#coa_segment_values #form_box a.show").prop('href', 'coa_segment_values.php?coa_id=' + coaId);
   }
  
  function getCoaId(coaIdNameStructure)
  {
     var first_separation=coaIdNameStructure.indexOf("||");
     var coaId=coaIdNameStructure.substr(0,first_separation);
     window.opener.$("#coa #coa_id").val(coaId);
     $('#coa #form_box a.show').prop('href', 'coa.php?coa_id=' + coaId);
   }

//Making refresh button work



//Popup for selecting existing COA 
  $(".popup").click(function() {
    void window.open('find_coa.php', '_blank',
            'width=700,height=500,toolbar=0,menubar=0,location=0,status=1,scrollbars=1,resizable=1,left=0,top=0');
    return false;
  });

  $("#selected").click(function() {
    var coaIdNameStructure = $(".select_coa_id:checked").val();
    getCoaSegmentValuesId(coaIdNameStructure);  
    getCoaId(coaIdNameStructure);  
    window.close();
  });

  //Get the coa_id on find button click
  $('#coa #form_box a.show').click(function() {
    var coaId = $('#coa_id').val();
//$(this).prop('href','coa.php?coa_id=' + moduleId);
    $(this).attr('href', 'coa.php?coa_id=' + coaId);
  });

//Get the coa id on fly after clicking the submit header
  $('#coa #submit_header').click(function() {
    var coaId = $('#coa_id').val();
    $('#coa_id').attr('action', 'coa.php?coa_id=' + coaId);
  });

//script for coa_segment_values.php
//change the save & delete button values

 //add a new line on clickint add a new line
  var objectCount = 1000;
  $("#add_object").click(function() {
    $("tr#segment_code_values0").clone().attr("id", "new_object" + objectCount).appendTo($("tbody#segment_code_values"));
//    $("#new_object" + objectCount ).val("");
    remove_row();
    objectCount++;
  }
  );
    
//add new line by using + sign    
  $(".add_row_img").click(function() {
    $("tr#segment_code_values0").clone().attr("id", "new_object" + objectCount).appendTo($("tbody#segment_code_values"));
    $("#new_object" + objectCount + " #coa_segment_values_id").val("");
    objectCount++;
    remove_row();
    
  }
  );    
  
//add a new line by clicking down arrow
  $("tbody#segment_code_values").keydown(function(e){
if (e.keyCode == 40){
var newRow = $("tr#segment_code_values0").clone().attr("id", "segment_code_values" + objectCount);
$(this).append(newRow);
 objectCount++;
  remove_row();
 return false;
 
}
});

//remove the current line clicking delete on key board
function remove_row(){
$(".remove_row").keydown(function(e){
if (e.keyCode == 46){
$(this).closest('tr').remove();
}
});

$(".remove_row_img").click(function(){
$(this).closest('tr').remove();
});

}

//Fetch the account segment values after coa id is selected in coa_segments_vales.php

//Show the segments after structure is selected
$("#coa_segment_values #coa_id").focusout(function(){
$('#loading').show();
var coaId = $("#coa_segment_values #coa_structure_id").val();

$.ajax({
     url: '../../system/option/json.option.php?',
     data : { option_id_l : coaId},
     type: 'get'
     }).done(function(data){
     var div = $('#coa_json', $(data)).html();
        $("#coa_segment_values #coa_segments").html(div);
        $('#loading').hide();
      }).fail(function(){
     alert("failed");
     $('#loading').hide();
     });

});


//coa id from #coa_segment_values
  //Get the coa_id on find button click
  $('#coa_segment_values #form_box a.show').click(function() {
    var coaId = $('#coa_id').val();
    var coaSegment = $('#coa_segments').val();
    $(this).attr('href', 'coa_segment_values.php?coa_id=' + coaId + '&' + 'coa_segments=' + coaSegment );
  });

//Get the coa id on fly after clicking the submit header
  $('#coa_segment_values #submit_header').click(function() {
    var coaId = $('#coa_id').val();
    var coaSegment = $('#coa_segments').val();
    $('#coa_id').attr('action', 'coa_segment_values.php?coa_id=' + coaId + '&' + 'coa_segments=' + coaSegment );
  });


});  

