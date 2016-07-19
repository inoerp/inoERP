function setValFromSelectPage(supplier_bu_id, combination) {
 this.supplier_bu_id = supplier_bu_id;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 fieldClass = fieldClass.replace(/\s+/g, '.');
 var supplier_bu_id = this.supplier_bu_id;
 if (supplier_bu_id) {
	$("#supplier_bu_id").val(supplier_bu_id);
 }
 if(combination){
$('#content').find(fieldClass).val(combination);
 localStorage.removeItem("field_class");
 }
};

$(document).ready(function() {
//selecting supplier
 $(".supplier_bu_id.select_popup").click(function() {
	void window.open('select.php?class_name=supplier_bu', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

});
