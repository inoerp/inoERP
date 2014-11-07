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
	$(this).attr('href', modepath() + 'path_id=' + pathId );
 });
 
  $(".path_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=path', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 var pathSave = new saveMainClass();
 pathSave.json_url = 'form.php?class_name=path';
 pathSave.form_header_id = 'path';
 pathSave.primary_column_id = 'path_id';
 pathSave.single_line = false;
 pathSave.saveMain();

});

