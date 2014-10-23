function setValFromSelectPage( combination) {
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
$('#content').on('blur', '.select.path_id', function(){
  if($(this).val() == 'newentry'){
  $(this).closest('tr').find('.external_link').attr('readonly', false);
  }else{
  $(this).closest('tr').find('.external_link').attr('readonly', true);
  }
  $(this).closest('tr').find('.fav_name').val($(this).find(':selected').text());
  })

onClick_add_new_row('tr.user_favourite_line0', 'tbody.user_favourite_values', '1', 'copyData');
// deleteData('json_user_favourite.php');
deleteData('form.php?class_name=user_favourite&line_class_name=user_favourite');

 //context menu
 var classContextMenu = new contextMenuMain();
  classContextMenu.docLineId = 'user_favourite_id';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'user_favourite_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 1;
// classContextMenu.contextMenu();
 
 var user_favouriteSave = new saveMainClass();
 user_favouriteSave.json_url = 'form.php?class_name=user_favourite';
 user_favouriteSave.single_line = false;
 user_favouriteSave.line_key_field = 'fav_name';
 user_favouriteSave.form_line_id = 'user_favourite';
 user_favouriteSave.saveMain();

});  