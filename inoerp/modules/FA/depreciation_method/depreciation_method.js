function setValFromSelectPage(fa_depreciation_method_id) {
 this.fa_depreciation_method_id = fa_depreciation_method_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var fa_depreciation_method_id = this.fa_depreciation_method_id;
   if (fa_depreciation_method_id) {
	$("#fa_depreciation_method_id").val(fa_depreciation_method_id);
  $("a.show.fa_depreciation_method_id").trigger('click');
 }

};

 //Check the option_id while entering the option line code
 function copy_fa_depreciation_method_id() {
	$(".fa_depreciation_method_rate_code").blur(function()
	{
	 if ($("#fa_depreciation_method_id").val() == "") {
		alert("First save header or select an Option Type");
		$(".fa_depreciation_method_rate_code").val("");
	 } else {
		$(".fa_depreciation_method_id").val($("#fa_depreciation_method_id").val());
	 }
	});
 }
 

$(document).ready(function() {
 var mandatoryCheck = new mandatoryFieldMain();
  mandatoryCheck.mandatoryHeader();
 //Popup for selecting option type
 $(".fa_depreciation_method_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=fa_depreciation_method', '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

copy_fa_depreciation_method_id();
});

