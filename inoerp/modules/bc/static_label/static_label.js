function setValFromSelectPage(bc_static_label_id, item_number) {
 this.bc_static_label_id = bc_static_label_id;
 this.item_number = item_number;
}


setValFromSelectPage.prototype.setVal = function() {
 if (this.bc_static_label_id) {
	$("#bc_static_label_id").val(this.bc_static_label_id);
 }
 
  if (this.item_number) {
	$("#item_number").val(this.item_number);
 }
};

$(document).ready(function() {
 //selecting Id
 $(".bc_static_label_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=bc_static_label', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the bc_static_label_id on find button click
 $('a.show.bc_static_label_id').click(function() {
	var bc_static_label_id = $('#bc_static_label_id').val();
	$(this).attr('href', modepath() + 'bc_static_label_id=' + bc_static_label_id);
 });
 
 $('#content').on('change', '#org_id', function() {
getSubInventory();
});

$('#content').on('change', '#subinventory_id', function() {
  var subInventoryId = $(this).val();
if (subInventoryId) {
 getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'oneSubinventory', '');
}
});

$('#print_label').on('click', function(){
var printData = $('#print_tab').find(":input").serializeArray();
  printLabel({
    print_parameters : printData
  });
});

$('#print_static_label').on('click', function(){
var printData = $('#print_tab').find(":input").serializeArray();
  printLabel({
    print_parameters : printData
  });
});
});
