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
  $("#tabs").tabs();
 });

//Refresh the page
 $('.refresh').click(function() {
  location.reload(true);
 });

//Make subinevntory locator changes after selcting transaction type
$("#transaction_type_id").blur(function (){

var transaction_type_id  = $(this).val();

switch (transaction_type_id){
case "1":
$(".from_subinventory_id").attr("disabled",false);
$(".from_locator_id").attr("disabled",false);
$(".to_subinventory_id").val("");
$(".to_subinventory_id").attr("disabled",true);
$(".to_locator_id").val("");
$(".to_locator_id").attr("disabled",true);
break;

case "2":
$(".to_subinventory_id").attr("disabled",false);
$(".to_locator_id").attr("disabled",false);
$(".from_subinventory_id").val("");
$(".from_subinventory_id").attr("disabled",true);
$(".from_locator_id").val("");
$(".from_locator_id").attr("disabled",true);

break;

default: 
$(".to_subinventory_id").attr("disabled",false);
$(".to_locator_id").attr("disabled",false);
$(".from_subinventory_id").attr("disabled",false);
$(".from_locator_id").attr("disabled",false);

}

});

//Show the org name after the item_id is selected
 $("#inventory_id.getOrgName").blur(function() {
  getOrgName();
 });
//get the org name function
 function getOrgName() {
  $('#loading').show();
  var inventoryId = $("#inventory_id").val();
  $.ajax({
   url: '../../org/json.org.php',
   data: {inventoryId: inventoryId},
   type: 'get'
  }).done(function(data) {
   var div = $('#inventoryId', $(data)).html();
   $("#org_name").replaceWith(div);
   $('#loading').hide();
  }).fail(function() {
   alert("org name loading failed");
   $('#loading').hide();
  });
 }

//get Subinventory Name
 $(".form_table #org_id").blur(function() {
  getSubInventoryName();
 });

 function getSubInventoryName() {
  $('#loading').show();
  var org_id = $(".form_table #org_id").val();
  $.ajax({
   url: '../subinventory/json.subinventory.php',
   data: {org_id: org_id},
   type: 'get'
  }).done(function(result) {
//   var div = $('#json_subinventory', $(data)).html();
   var div = $(result).filter('div#json_subinventory').html();
   $(".form_table .from_subinventory_id").append(div);
   $(".form_table .to_subinventory_id").append(div);
   $('#loading').hide();
  }).fail(function() {
   alert("org name loading failed");
   $('#loading').hide();
  });
  $(".form_table .from_subinventory_id").attr("disabled", false);
 }


//get locator name

 function getLocator(subinventory_id, subinventory_type, objectCount) {
  $('#loading').show();
  $.ajax({
   url: '../locator/json.locator.php',
   data: {subinventory_id: subinventory_id},
   type: 'get'
  }).done(function(result) {
//   var div = $('#json_locator', $(data)).html();
   var div = $(result).filter('div#json_locator').html();
   if (subinventory_type == "from_subinventory_id") {
    if(objectCount > 0){
     $(".form_table .from_locator_id #new_object" + objectCount).find('option').remove();
    $(".form_table .from_locator_id #new_object" + objectCount).append(div);
    }else{
    $(".form_table .from_locator_id").find('option').remove();
    $(".form_table .from_locator_id").append(div);
    }
   
   }
   if (subinventory_type == "to_subinventory_id") {
    if(objectCount > 0){
     $(".form_table .to_locator_id #new_object" + objectCount).find('option').remove();
    $(".form_table .to_locator_id #new_object" + objectCount).append(div);
    }else{
     $(".form_table .to_locator_id").find('option').remove();
    $(".form_table .to_locator_id").append(div);
    }
    
   }
   $('#loading').hide();
  }).fail(function() {
   alert("Locator name loading failed");
   $('#loading').hide();
  });
  $(".form_table .from_locator_id").attr("disabled", false);
 }
 
 function callGetLocatorForFrom() {
  var subinventory_id = $(".from_subinventory_id").val();
  var subinventory_type = "from_subinventory_id";
  getLocator(subinventory_id, subinventory_type);
 }
 
 function callGetLocatorForTo() {
  var subinventory_id = $(".to_subinventory_id").val();
  var subinventory_type = "to_subinventory_id";
  getLocator(subinventory_id, subinventory_type);
 }
 
 $(".form_table .from_subinventory_id").blur( function(){
  callGetLocatorForFrom();
 });

 $(".form_table .to_subinventory_id").blur( function () {
  callGetLocatorForTo();
 });

//get the new search criteria
 $("#new_search_criteria_add").click(function() {
  $('#loading').show();
  var new_search_criteria = $(".new_search_criteria").val();
  $.ajax({
   url: 'json.inv_transaction.php',
   data: {new_search_criteria: new_search_criteria},
   type: 'get'
  }).done(function(data) {
   var div = $('#new_search_criteria', $(data)).html();
   $("ul.search_form").append(div);
   $('#loading').hide();
  }).fail(function() {
//     alert("org name loading failed");
   $('#loading').hide();
  });
 });

//ajax for char of account combinations
$('.account').autocomplete({source:'../../gl/coa_combination/coa_search.php', minLength:2});

//ajax for char of item number
$('.item_number').autocomplete({source:'../item/item_search.php', minLength:2});


//function to get value in parent window from child
 function getItemId(itemId)
 {
  window.opener.$(".item_id").val(itemId);
  $('#item #form_box a.show').prop('href', 'item.php?item_id=' + itemId);
 }

//Popup for selecting existing Item Id 
 $(".item_number.popup").click(function() {
  void window.open('../item/find_item.php', '_blank',
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
 $('.item #submit_header').click(function() {
  var itemId = $('.item_id').val();
  $('.item_id').attr('action', 'item.php?item_id=' + itemId);

 });

//add a new line on clickint add a new line
 var objectCount = 1000;
 $("#add_object").on("click", function() {
  $("#tabs1 tr#inv_transaction_rowtab1").clone().attr("id", "new_object" + objectCount).appendTo($("#tabs1 tbody.inv_transaction_values"));
  $("#tabs2 tr#inv_transaction_rowtab2").clone().attr("id", "new_object" + objectCount).appendTo($("#tabs2 tbody.inv_transaction_values"));
  $("#tabs3 tr#inv_transaction_rowtab3").clone().attr("id", "new_object" + objectCount).appendTo($("#tabs3 tbody.inv_transaction_values"));
  $("#new_object" + objectCount + " .inv_transaction_id").val("");
  $("#new_object" + objectCount + " .from_subinventory_id").val("");
  $("#new_object" + objectCount + " .to_subinventory_id").val("");
  $("#new_object" + objectCount + " .to_locator_id").val("");
  $("#new_object" + objectCount + " .from_locator_id").val("");
  $("#new_object" + objectCount + " .item_number").autocomplete({source:'../item/item_search.php', minLength:2});
   callGetLocatorForTo();
  callGetLocatorForFrom();  
  objectCount++;
  remove_row();
 }
 );

//add new line by using + sign    
 $(".add_row_img").on("click", function() {
  $("#tabs1 tr#inv_transaction_rowtab1").clone().attr("id", "new_object" + objectCount).appendTo($("#tabs1 tbody.inv_transaction_values"));
  $("#tabs2 tr#inv_transaction_rowtab2").clone().attr("id", "new_object" + objectCount).appendTo($("#tabs2 tbody.inv_transaction_values"));
  $("#tabs3 tr#inv_transaction_rowtab3").clone().attr("id", "new_object" + objectCount).appendTo($("#tabs3 tbody.inv_transaction_values"));
  $("#new_object" + objectCount + " .inv_transaction_id").val("");
  $("#new_object" + objectCount + " .from_subinventory_id").val("");
  $("#new_object" + objectCount + " .to_subinventory_id").val("");
  $("#new_object" + objectCount + " .to_locator_id").val("");
  $("#new_object" + objectCount + " .from_locator_id").val("");
  $("#new_object" + objectCount + " .item_number").autocomplete({source:'../item/item_search.php', minLength:2});
//  var from_subinventory_id=$(" #new_object" + objectCount + " #from_subinventory_id").val();
//  $("#new_object" + objectCount + " #from_subinventory_id").blur(function(){
//   getLocator(from_subinventory_id, "from_subinventory", objectCount)
//  });
//  var to_subinventory_id=$("#new_object" + objectCount + " #to_subinventory_id").val();
//  $("#new_object" + objectCount + "#to_subinventory_id").blur(function (){
//   getLocator(to_subinventory_id, "to_subinventory_id", objectCount)
//  });
  callGetLocatorForTo();
  callGetLocatorForFrom();
  objectCount++;
  remove_row();
 }
 );

//remove the current line clicking remove image on key board
 function remove_row() {
  $(".remove_row_img").click(function() {
   $(this).closest('tr').remove();
  });

 }



});

