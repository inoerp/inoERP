function setValFromSelectPage(content_type_id, content_type) {
 this.content_type_id = content_type_id;
 this.content_type = content_type;
}

setValFromSelectPage.prototype.setVal = function () {
 var content_type_id = this.content_type_id;
 var content_type = this.content_type;
 if (content_type_id) {
  $("#content_type_id").val(content_type_id);
 }
 if (content_type) {
  $("#content_type").val(content_type);
 }
};

function dropField(field_name, content_name) {
 $('.show_loading_small').show();
 $.ajax({
  url: 'extensions/content_type/json.content_type.php',
  data: {delete: '1',
   field_name: field_name,
   content_name: content_name},
  type: 'get'
 }).done(function (result) {
  var div = $(result).filter('div#json_drop_column').html();
  $(".error").append(div);
  $('.show_loading_small').hide();
 }).fail(function () {
  alert("Column delete failed");
  $('#loading').hide();
 });
// $(".form_table #subinventory_id").attr("disabled",false);
}

function dropTable(content_name) {
 $('.show_loading_small').show();
 $.ajax({
  url: 'extensions/content_type/json.content_type.php',
  data: {delete: '2',
   content_name: content_name},
  type: 'get'
 }).done(function (result) {
  var div = $(result).filter('div#json_drop_column').html();
  $(".error").append(div);
  $('.show_loading_small').hide();
 }).fail(function () {
  alert("Content type drop failed");
  $('#loading').hide();
 });
// $(".form_table #subinventory_id").attr("disabled",false);
}

$(document).ready(function () {
 $(".field_option").attr("disabled", true);
 $(".field_type").attr('disabled', true);
 $(".field_num").attr("readonly", true);
 $(".field_enum").attr("readonly", true);

//Delete columns
 $("#delete_button").click(function () {
  $('input[name="field_name_cb"]:checked').each(function () {
   var field_name = $(this).val();
   var content_name = $("#content_type").val();
   if (field_name == 'content_id') {
    alert('You can\'t delete content_id.\n. Content_id is auto removed on deleting content type. ');
    $(this).attr('checked', false);
   } else if (confirm("Do you want to delete column?\n" + field_name)) {
    dropField(field_name, content_name);
   }
  });
 });

//Delete content type : drop table
 $("#drop_table").click(function () {
  var content_name = $("#content_type").val();
  if (confirm("Are you sure?")) {
   dropTable(content_name);
  }
 });

 //Delete major category
 function removeCategory(category_id, content_type_id) {
  $('.show_loading_small').show();
  $.ajax({
   url: 'extensions/category/json.category.php',
   data: {delete: '1',
    category_id: category_id,
    content_type_id: content_type_id},
   type: 'get'
  }).done(function (result) {
   var div = $(result).filter('div#json_drop_column').html();
   $(".error").append(div);
   $('.show_loading_small').hide();
  }).fail(function () {
   alert("Category reomval failed");
   $('#loading').hide();
  });
// $(".form_table #subinventory_id").attr("disabled",false);
 }

 //add remove category
 var new_object = 1000;
 $("#tabsHeader").on('blur', '.category_id', function () {
  if ($(this).val()) {
   $(this).closest('li').clone().attr('class', 'new_object' + new_object).appendTo($(this).closest('ul'));
   new_object++;
  } else {
   var numberOfBlanckEelements = 0;
   $(this).closest('ul').find('.category_id').each(function () {
    if (!$(this).val()) {
     numberOfBlanckEelements++;
    }
   });
   if (numberOfBlanckEelements > 1) {
    $(this).remove();
   }
  }
 });
//
 $("#tabsHeader").on('click', '.delete_category', function () {
  var category_id = $(this).closest('li').find('.category_id').val();
  var content_type_id = $("#content_type_id").val();
  if (confirm("Do you want to delete \n Category " + category_id + " ?")) {
   removeCategory(category_id, content_type_id);
  }
 });

 //selecting Header Id
 $(".content_type_id.select_popup").on("click", function () {
  void window.open('select.php?class_name=content_type', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 $('#content').on('blur', '.field_type', function () {
  if (($(this).val() == 'int') || ($(this).val() == 'varchar')) {
   $(this).closest('tr').find('.field_num').attr("readonly", false);
   $(this).closest('tr').find('.field_enum').attr("readonly", true);
   $(this).closest('tr').find(".field_option").attr("disabled", true);
  } else if ($(this).val() == 'enum') {
   $(this).closest('tr').find('.field_enum').attr("readonly", false).attr("placeholder", "comma(,) separated values");
   $(this).closest('tr').find('.field_num').attr("readonly", true);
   $(this).closest('tr').find(".field_option").attr("disabled", true);
  } else if ($(this).val() == 'option') {
   $(this).closest('tr').find('.field_num').attr("readonly", true);
   $(this).closest('tr').find('.field_enum').attr("readonly", true);
   $(this).closest('tr').find(".field_option").attr("disabled", false);
  }
  else {
   $(this).closest('tr').find('.field_num').val('');
   $(this).closest('tr').find('.field_num').attr("readonly", true);
   $(this).closest('tr').find('.field_enum').val('');
   $(this).closest('tr').find('.field_enum').attr("readonly", true);
   $(this).closest('tr').find(".field_option").attr("disabled", true);
  }
 });

 $('#content').on('blur', '.field_name', function () {
  if ($(this).val()) {
   $(this).closest('tr').find('.field_type').attr("disabled", false);
  }
 });


 $('#form_line').on('change', '.checkBox', function () {
  if (this.checked) {
   $(this).val(($(this).closest('tr').find('.field_name').val()));
  } else {
   $(this).val(1);
  }
 });


 $('#content').on('change', '.field_type', function () {
  var fieldType = $(this).val();

  switch (fieldType) {
   case 'enum' :
    $(this).closest('tr').find('.field_enum').prop('required', true);
    break;

   case 'option' :
    $(this).closest('tr').find('.option_type').prop('required', true);
    break;

   case 'int' :
   case 'varchar' :
    $(this).closest('tr').find('.number').prop('required', true);
    break;

   case 'default' :
    $(this).closest('tr').find('.number').prop('required', false);
    break;
  }

 });

//delete from multi action
 

// var classSave = new saveMainClass();
// classSave.json_url = 'form.php?class_name=content_type';
// classSave.form_header_id = 'content_type_header';
// classSave.primary_column_id = 'content_type_id';
// classSave.single_line = false;
// classSave.savingOnlyHeader = true;
// classSave.headerClassName = 'content_type';
// classSave.enable_select = true;
// classSave.saveMain();

});