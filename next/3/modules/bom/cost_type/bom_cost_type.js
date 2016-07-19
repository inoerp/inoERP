function setValFromSelectPage(bom_cost_type_id) {
 this.bom_cost_type_id = bom_cost_type_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var bom_cost_type_id = this.bom_cost_type_id;
 $("#bom_cost_type_id").val(bom_cost_type_id);
 
   if (this.bom_cost_type_id) {
  $('a.show.bom_cost_type_id').trigger('click');
 }
 
};

$(document).ready(function() {

 //selecting data
 $(".bom_cost_type_id.select_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('select.php?class_name=bom_cost_type', '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the bom_cost_type_id on refresh button click
 $('a.show.bom_cost_type_id_show').click(function() {
	var bom_cost_type_id = $('#bom_cost_type_id').val();
	$(this).attr('href', modepath() + 'bom_cost_type_id=' + bom_cost_type_id);
 });
 
  //context menu
// var classContextMenu = new contextMenuMain();
// classContextMenu.docHedaderId = 'bom_cost_type_id';
// classContextMenu.btn1DivId = 'bom_cost_type_id';
// classContextMenu.contextMenu();
// 
// var classSave = new saveMainClass();
// classSave.json_url = 'form.php?class_name=bom_cost_type';
// classSave.form_header_id = 'bom_cost_type';
// classSave.primary_column_id = 'bom_cost_type_id';
// classSave.single_line = false;
// classSave.savingOnlyHeader = true;
// classSave.headerClassName = 'bom_cost_type';
// classSave.saveMain();
});


