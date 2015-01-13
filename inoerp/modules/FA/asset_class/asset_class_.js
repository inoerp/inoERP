function setValFromSelectPage(fa_asset_class_id) {
 this.fa_asset_class_id = fa_asset_class_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var fa_asset_class_id = this.fa_asset_class_id;
 
  if (fa_asset_class_id) {
	$("#fa_asset_class_id").val(fa_asset_class_id);
 }
};

$(document).ready(function() {

 //selecting Id
 $(".fa_asset_class_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=fa_asset_class', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});