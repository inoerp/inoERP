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

 $('body').off('change', '#org_id').on('change', '#org_id', function() {
getSubInventory();
});

$('body').off('change', '#subinventory_id').on('change', '#subinventory_id', function() {
  var subInventoryId = $(this).val();
if (subInventoryId) {
 getLocator('modules/inv/locator/json_locator.php', subInventoryId, 'oneSubinventory', '');
}
});

$('body').off('click', '#print_label').on('click', '#print_label' , function(){
var printData = $('#print_tab').find(":input").serializeArray();
  printLabel({
    print_parameters : printData
  });
});

$('body').off('click', '#print_static_label').on('click', '#print_static_label',function(){
var printData = $('#print_tab').find(":input").serializeArray();
  printLabel({
    print_parameters : printData
  });
});
});
