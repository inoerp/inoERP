function setValFromSelectPage(sys_process_flow_header_id, user_id, username) {
 this.sys_process_flow_header_id = sys_process_flow_header_id;
 this.user_id = user_id;
 this.username = username;
}

setValFromSelectPage.prototype.setVal = function () {
 var sys_process_flow_header_id = this.sys_process_flow_header_id;
 if (sys_process_flow_header_id) {
  $('#content').find('#sys_process_flow_header_id').val(sys_process_flow_header_id);
 }
  var rowClass = '.' + localStorage.getItem("row_class");
 rowClass = rowClass.replace(/\s+/g, '.');
  if (this.username) {
  $('#content').find(rowClass).find('.username').val(this.username);
 }
   if (this.user_id) {
  $('#content').find(rowClass).find('.user_id').val(this.user_id);
 }
 localStorage.removeItem("row_class");
};

$(document).ready(function () {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
 mandatoryCheck.header_id = 'process_flow_header_id';

 //Popup for selecting process_flow
 $(".process_flow_header_id.select_popup").click(function () {
  void window.open('select.php?class_name=sys_process_flow_header', '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });


 $("#content").on('click','.user_id.select_popup',function () {
  var rowClass = $(this).closest('tr').prop('class');
  localStorage.setItem("row_class", rowClass);
  var link = 'select.php?class_name=user';
  void window.open(link, '_blank',
          'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


// addOrShow_lineDetails();
// onClick_addDetailLine(1);

 if (!($('.line_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 if (!($('.action_number:first').val())) {
  $('.action_number:first').val('1');
 }
});
