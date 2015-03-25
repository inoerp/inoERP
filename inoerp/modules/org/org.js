function setValFromSelectPage(org_id, address_id, extn_contact_id, contact_name) {
 this.org_id = org_id;
 this.address_id = address_id;
 this.extn_contact_id = extn_contact_id;
 this.contact_name = contact_name;
}

setValFromSelectPage.prototype.setVal = function () {
 var org_id = this.org_id;
 var address_id = this.address_id;
 var contact_field_class = '.' + localStorage.getItem("contact_field_class");
 if (org_id) {
  $("#org_id").val(org_id);
 }
 if (address_id) {
  $("#address_id").val(address_id);
 }

 if (this.extn_contact_id) {
  $('#content').find(contact_field_class).find('.extn_contact_id_new').val(this.extn_contact_id);
 }
 if (this.contact_name) {
  $('#content').find(contact_field_class).find('.contact_name_new').val(this.contact_name);
 }

 localStorage.removeItem("contact_field_class");
};

//  function orgValues(orgType) {
//  var org_type = orgType;
//  $('#loading').show();
//  $.ajax({
//   url: 'modules/org/json_org.php',
//   type: 'get',
//   dataType: 'json',
//   data: {
//    org_type: org_type
//   },
//   success: function(result) {
//    var items = [];
//    var option_stmt = '<option value=""></option>';
//    $.each(result, function(key, val) {
//     option_stmt += '<option value="' + val.org_id + '">' + val.org + '</option>';
//     items.push("<li id='" + key + "'>" + val + "</li>");
//    });
//    var org_type_id = '#' + org_type + '_id';
//    $(org_type_id).removeAttr('disabled');
//    $(org_type_id).empty().append(option_stmt);
//   },
//   complete: function() {
//    $('.show_loading_small').hide();
//   },
//   beforeSend: function() {
//    $('.show_loading_small').show();
//   },
//   error: function(request, errorType, errorMessage) {
//    alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
//   }
//  });
// }
// 
// 
function orgValues(orgType) {
 var org_type = orgType;
 $('#loading').show();
 return $.ajax({
  url: 'modules/org/json_org.php',
  type: 'get',
  dataType: 'json',
  context: this,
  data: {
   org_type: org_type
  },
  success: function (result) {
   var items = [];
   $.each(result, function (key, val) {
    var items = [];
    var option_stmt = '<option value=""></option>';
    $.each(result, function (key, val) {
     option_stmt += '<option value="' + val.org_id + '">' + val.org + '</option>';
     items.push("<li id='" + key + "'>" + val + "</li>");
    });
    var org_type_id = '#' + org_type + '_id';
    $(org_type_id).removeAttr('disabled');
    $(org_type_id).empty().append(option_stmt);
   });
   $('.show_loading_small').hide();
  },
  complete: function () {

  },
  beforeSend: function () {
   $('.show_loading_small').show();
  },
  error: function (request, errorType, errorMessage) {
//   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
   $('.show_loading_small').hide();
  }
 });
}



$(document).ready(function () {
 //controlling org type values - what can be entered
 $("#enterprise_org_id, #legal_org_id,#business_org_id").prop('readonly', true);


 $("#content").off('change', '#org #type').on('change', '#org #type', function () {
  var selectedVal = $(this).val();
  switch (selectedVal) {
   case 'ENTERPRISE' :
    $("#enterprise_org_id").empty().val('');
    $("#enterprise_org_id").prop("disabled", true);
    $("#legal_org_id").empty().val('');
    $("#legal_org_id").prop("disabled", true);
    $("#business_org_id").empty().val('');
    $("#business_org_id").attr("disabled", true);
    break;

   case 'LEGAL_ORG' :
    orgValues('enterprise_org');
    $("#legal_org_id").empty().val('');
    $("#legal_org_id").prop("disabled", true);
    $("#business_org_id").empty().val('');
    $("#business_org_id").attr("disabled", true);
    break;

   case 'BUSINESS_ORG' :
    orgValues('enterprise_org');
    orgValues('legal_org');
    $("#business_org_id").empty().val('');
    $("#business_org_id").attr("disabled", true);
    break;

   case 'INVENTORY_ORG' :
    orgValues('enterprise_org');
    orgValues('legal_org');
    orgValues('business_org');
    break;

   default :
    $("#enterprise_org_id").empty().val('');
    $("#enterprise_org_id").prop("disabled", true);
    $("#legal_org_id").empty().val('');
    $("#legal_org_id").prop("disabled", true);
    $("#business_org_id").empty().val('');
    $("#business_org_id").attr("disabled", true);
    break;
  }
 });

 $(".org_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=org', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 deleteReferences();

});