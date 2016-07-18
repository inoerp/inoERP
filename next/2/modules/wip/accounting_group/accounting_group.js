function setValFromSelectPage(wip_accounting_group_id, combination) {
 this.wip_accounting_group_id = wip_accounting_group_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var wip_accounting_group_id = this.wip_accounting_group_id;
 var combination = this.combination;
 if (wip_accounting_group_id) {
	$("#wip_accounting_group_id").val(wip_accounting_group_id);
  $('a.show.wip_accounting_group_id').trigger('click');
 }
 if (combination) {
	$("#cash_ac_id").val(combination);
 }
};


$(document).ready(function() {
 //selecting Id
 $(".wip_accounting_group_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=wip_accounting_group', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

