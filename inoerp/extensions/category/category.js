function setValFromSelectPage(category_id, address_id) {
 this.category_id = category_id;
 this.address_id = address_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var category_id = this.category_id;
 var address_id = this.address_id;
 if (category_id) {
	$("#category_id").val(category_id);
 }
  if (address_id) {
	$("#address_id").val(address_id);
 }
};

$(document).ready(function() {
$("table#category_list tr.second").hide();
$("table#category_list tr.third").hide();
$("table#category_list tr.four").hide();


$("table#category_list tr.first").click(function(){
$(this).nextUntil("tr.first").toggle();
});

 //selecting Id
 $(".category_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=category', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the header id on find button click
 $('a.show.category_id').click(function() {
	var category_id = $('#category_id').val();
	$(this).attr('href', modepath() + 'category_id=' + category_id);
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'category_id';
 classContextMenu.btn1DivId = 'category_id';
 classContextMenu.contextMenu();



 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=category';
 classSave.form_header_id = 'category';
 classSave.primary_column_id = 'category_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.headerClassName = 'category';
 classSave.saveMain();

deleteData('form.php?class_name=category', 'category_id')

});  
