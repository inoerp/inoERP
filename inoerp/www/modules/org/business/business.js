function setValFromSelectPage(business_id, combination) {
 this.business_id = business_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var business_id = this.business_id;
 var combination = this.combination;
 if (business_id) {
	$("#business_id").val(business_id);
 }
  if (combination) {
	$("#cash_ac_id").val(combination);
 }
};


$(document).ready(function() {
 //selecting Id
 $(".business.select_popup").on("click", function() {
	void window.open('select.php?class_name=business', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

