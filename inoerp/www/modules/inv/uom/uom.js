function setValFromSelectPage(uom_id, uom_name, combination) {
 this.uom_id = uom_id;
 this.uom_name = uom_name;
 this.combination = combination;
}

setValFromSelectPage.prototype.setVal = function() {
 var uom_id = this.uom_id;
 var uom_name = this.uom_name;
 var combination = this.combination;
 var fieldClass = '.' + localStorage.getItem("field_class");
 var is_primary_uom = localStorage.getItem("is_primary_uom");
 fieldClass = fieldClass.replace(/\s+/g, '.');

 if (uom_id) {
	if (is_primary_uom === '1') {
	 $('#primary_uom_id').val(uom_id);
	 $('#primary_uom').val(uom_name);
	 localStorage.removeItem("is_primary_uom");
	}
	else {
	 $("#uom_id").val(uom_id);
	 $("#uom_name").val(uom_name);
	 localStorage.removeItem("is_primary_uom");
	}
 }
 if (combination) {
	$('#content').find(fieldClass).val(combination);
	localStorage.removeItem("field_class");
 }
 
};


$(document).ready(function() {
 //selecting Id
 $(".uom_id.select_popup").on("click", function() {
	localStorage.setItem("is_primary_uom", '9');
	void window.open('select.php?class_name=uom', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //selecting primary UOM Id
 $(".primary_uom_id.select_popup").on("click", function() {
	localStorage.setItem("is_primary_uom", '1');
		void window.open('select.php?class_name=uom', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});


