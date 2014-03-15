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

 //Get the path_id on find button click
 $('a.show.path_id').click(function() {
	var pathId = $('#path_id').val();
//$(this).prop('href','path.php?path_id=' + pathId);
	$(this).attr('href', modepath() + 'path_id=' + pathId );
 });

////Get the path id on fly after clicking the submit header
// $('#submit_header').click(function() {
//	var pathId = $('#path_id').val();
//	$('#path_header').attr('action', 'path.php?path_id=' + pathId);
// });

 var pathSave = new saveMainClass();
 pathSave.json_url = 'form.php?class_name=path';
 pathSave.form_header_id = 'path';
 pathSave.primary_column_id = 'path_id';
 pathSave.single_line = false;
 pathSave.saveMain();

});

