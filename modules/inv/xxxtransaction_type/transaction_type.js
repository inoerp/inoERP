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
    $( "#tabsHeader" ).tabs();
    $( "#tabsLine" ).tabs();
  });
  
//Refresh the page
$('.refresh').click(function() {
    location.reload(true);
});

//constant ('INC_ORGS');
//constant ('DS');

//Show the org name after the item_id is selected
$("#inventory_id.getOrgName").blur(function() {
getOrgName();
});

//get the org name function
function getOrgName(){
    $('#loading').show();
var inventoryId = $("#inventory_id").val();
$.ajax({
     url:'../../org/json.org.php' ,
     data : { inventoryId : inventoryId},
     type: 'get'
     }).done(function(data){
     var div = $('#inventoryId', $(data)).html();
        $("#org_name").replaceWith(div);
        $('#loading').hide();
      }).fail(function(){
     alert("org name loading failed");
     $('#loading').hide();
     });
}


//get the new search criteria
$("#new_search_criteria_add").click(function(){
  $('#loading').show();
var new_search_criteria = $(".new_search_criteria").val();
$.ajax({
     url:'json.transaction_type.php' ,
     data : { new_search_criteria : new_search_criteria},
     type: 'get'
     }).done(function(data){
      var div = $('#new_search_criteria', $(data)).html();
	  $("ul.search_form").append(div);       
        $('#loading').hide();
      }).fail(function(){
//     alert("org name loading failed");
     $('#loading').hide();
     });
});


//function to get value in parent window from child
  function getItemId(itemId)
  {
     window.opener.$("#item_id").val(itemId);
     $('#item #form_box a.show').prop('href', 'item.php?item_id=' + itemId);
   }

//Popup for selecting existing Item Id 
  $(".item_id_popup").click(function() {
    void window.open('find_item.php', '_blank',
            'width=900,height=900,toolbar=0,menubar=0,location=0,status=1,scrollbars=1,resizable=1,left=0,top=0');
    return false;
  });
  

  $("#selected").click(function() {
    var itemId = $(".select_item_id:checked").val();
    getItemId(itemId);  
    window.close();
  });

  $(".quick_select").click(function() {
    var itemId = $(this).val();
    getItemId(itemId);  
    window.close();
  });
  
    //Get the item_id on find button click
  $('a.show.item_id').click(function() {
    var item_id = $('#item_id').val();
    $(this).attr('href', 'item.php?item_id=' + item_id);
    
  });
  

//Get the item id on fly after clicking the submit header
//enables the account field
  $('#item #submit_header').click(function() {
    var itemId = $('#item_id').val();
    $('#item_id').attr('action', 'item.php?item_id=' + itemId);
    
  });

//add a new line on clickint add a new line
  var objectCount = 1000;
  $("#add_object").on("click",function() {
    $("#tabsHeader-1 tr#transaction_type_values0").clone().attr("id", "new_object" + objectCount).appendTo($("#tabsHeader-1 tbody#transaction_type_values"));
    $("#tabsHeader-2 tr#transaction_type_values0").clone().attr("id", "new_object" + objectCount).appendTo($("#tabsHeader-2 tbody#transaction_type_values"));
    $("#new_object" + objectCount + " .transaction_type_id").val("");
    objectCount++;
    remove_row();
    }
  );
    
//add new line by using + sign    
  $(".add_row_img").on("click",function() {
     $("#tabsHeader-1 tr#transaction_type_values0").clone().attr("id", "new_object" + objectCount).appendTo($("#tabsHeader-1 tbody#transaction_type_values"));
    $("#tabsHeader-2 tr#transaction_type_values0").clone().attr("id", "new_object" + objectCount).appendTo($("#tabsHeader-2 tbody#transaction_type_values"));
    $("#new_object" + objectCount + " .transaction_type_id").val("");
    objectCount++;
    remove_row();
  }
  );    
  
//remove the current line clicking remove image on key board
function remove_row(){
$(".remove_row_img").click(function(){
$(this).closest('tr').remove();
});

}


 
});  
