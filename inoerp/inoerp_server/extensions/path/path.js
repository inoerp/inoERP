function setValFromSelectPage(path_id) {
 this.path_id = path_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var path_id = this.path_id;
 if (path_id) {
  $("#path_id").val(path_id);
 }
};

$(document).ready(function() {
 $(".path_id.select_popup").on("click", function() {
  void window.open('select.php?class_name=path', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

// var pathSave = new saveMainClass();
// pathSave.json_url = 'form.php?class_name=path';
// pathSave.form_header_id = 'path';
// pathSave.primary_column_id = 'path_id';
// pathSave.single_line = false;
// pathSave.saveMain();

deleteHeader('form.php?class_name=path', $('#path_id').val());

 $('#path_link').on('blur', function() {
  if (!$(this).val()) {
   return;
  }
  var className_a = $(this).val().split('=');
  var className = className_a[1];
  if ($(this).val().indexOf("&mode=") >= 0) {
   var modeIndex = $(this).val().indexOf('&mode=') + 6;
   var mode = $(this).val().substr(modeIndex, modeIndex + 1);
  } else {
   var mode = 2;
  }
  $('#pmode').val(mode);
  if (className.indexOf("&") >= 0) {
   className_v = className.substr(0, className.indexOf('&'));
   $('#obj_class_name').val(className_v);
   var pathNameStrign = toUpperCase(className.replace(/_/g, " "));
   pathName = pathNameStrign.substr(pathNameStrign.indexOf(' ') + 1);
   pathName = pathName.substr(0, pathName.indexOf('&'));
   $('#name, #description').val(pathName);
  } else {
   $('#obj_class_name').val(className);
   var pathName = toUpperCase(className.replace(/_/g, " "));
   pathName = pathName.substr(pathName.indexOf(' ') + 1);
   $('#name, #description').val(pathName);
  }

 })

});

