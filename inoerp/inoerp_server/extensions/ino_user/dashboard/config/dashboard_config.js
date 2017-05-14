function setValFromSelectPage(user_id, username) {
 this.user_id = user_id;
 this.username = username;
}

setValFromSelectPage.prototype.setVal = function () {
 var rowClass = '.' + localStorage.getItem("rowClass");
 rowClass = fieldClass.replace(/\s+/g, '.');
 if (this.username) {
  $('#content').find(rowClass).val(this.username);
 }
 if (this.user_id) {
  $('#content').find(rowClass).val(this.user_id);
 }
 localStorage.removeItem("rowClass");
};

$(document).ready(function () {
 //Popup for selecting user
// $(".user_id.select_popup").click(function() {
//  var link = 'select.php?class_name=user';
//  var rowClass = $(this).closest('tr').prop('class');
//  localStorage.setItem("row_class", rowClass);
//  void window.open(link, '_blank',
//   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
// });
// 
 $('#content').on('change', '.report_type', function () {
  if (!$(this).val()) {
   return;
  }

  getDBReportList({
   'trClass': $(this).closest('tr').attr('class'),
   'report_type': $(this).val()
  });

 });

 $('#content').on('blur', '.config_level', function () {
  if (!$(this).val()) {
   return;
  }

  switch ($(this).val()) {
   case 'ROLE' :
    $(this).closest('tr').find('.username,.user_id').val('').attr('readonly', true);
    $(this).closest('tr').find('.user_role').attr('readonly', false);
    break;

   case 'USER' :
    $(this).closest('tr').find('.user_role').val('').attr('disabled', true);
    $(this).closest('tr').find('.username,.user_id').attr('readonly', false);
    break;

   case 'GLOBAL' :
    $(this).closest('tr').find('.user_role').val('').attr('disabled', true);
    $(this).closest('tr').find('.username,.user_id').val('').attr('readonly', true);
    break;

   default:
    break;

  }

 });

// onClick_add_new_row('tr.user_dashboard_config_line0', 'tbody.user_dashboard_config_values', '1', 'copyData');
//
//
// //context menu
// var classContextMenu = new contextMenuMain();
// classContextMenu.docLineId = 'user_dashboard_config_id';
// classContextMenu.btn2DivId = 'form_line';
// classContextMenu.trClass = 'user_dashboard_config_line';
// classContextMenu.tbodyClass = 'form_data_line_tbody';
// classContextMenu.noOfTabbs = 1;
//// classContextMenu.contextMenu();
//
// var user_dashboard_configSave = new saveMainClass();
// user_dashboard_configSave.json_url = 'form.php?class_name=user_dashboard_config';
// user_dashboard_configSave.single_line = false;
// user_dashboard_configSave.line_key_field = 'fav_name';
// user_dashboard_configSave.form_line_id = 'user_dashboard_config';
// user_dashboard_configSave.saveMain();

$('body').off('change' ,'#user_dashboard_config .report_id').on('change', '#user_dashboard_config .report_id' , function(){
 $(this).closest('tr').find('.report_label').val($(this).find('option:selected').text());
});

});

$('#content').on('blur', '.config_level', function () {
 if (!$(this).val()) {
  return;
 }

 switch ($(this).val()) {
  case 'ROLE' :
   $(this).closest('tr').find('.username,.user_id').val('').attr('readonly', true);
   $(this).closest('tr').find('.user_role').attr('readonly', false);
   break;

  case 'USER' :
   $(this).closest('tr').find('.user_role').val('').attr('disabled', true);
   $(this).closest('tr').find('.username,.user_id').attr('readonly', false);
   break;

  case 'GLOBAL' :
   $(this).closest('tr').find('.user_role').val('').attr('disabled', true);
   $(this).closest('tr').find('.username,.user_id').val('').attr('readonly', true);
   break;

  default:
   break;

 }



});