function setValFromSelectPage(inv_abc_valuation_id, valuation_name, scope_org_id) {
 this.inv_abc_valuation_id = inv_abc_valuation_id;
 this.valuation_name = valuation_name;
 this.scope_org_id = scope_org_id;
}


setValFromSelectPage.prototype.setVal = function() {
 var inv_abc_valuation_id = this.inv_abc_valuation_id;
 var valuation_name = this.valuation_name;
 var scope_org_id = this.scope_org_id;
 if (inv_abc_valuation_id) {
	$("#inv_abc_valuation_id").val(inv_abc_valuation_id);
 }
 if (valuation_name) {
	$("#valuation_name").val(valuation_name);
 }
 if (scope_org_id) {
	$("#org_id").val(scope_org_id);
 }
};

$(document).ready(function() {
 //selecting Id
 $(".valuation_name.select_popup, #valuation_name").on("click", function() {
	void window.open('select.php?class_name=inv_abc_valuation', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
});
