function setValFromSelectPage(enterprise_id, combination) {
 this.enterprise_id = enterprise_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var enterprise_id = this.enterprise_id;
 var combination = this.combination;
 if (enterprise_id) {
	$("#enterprise_id").val(enterprise_id);
 }
  if (combination) {
	$("#cash_ac_id").val(combination);
 }
};


$(document).ready(function() {
 //selecting Id
 $(".enterprise_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=enterprise', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

