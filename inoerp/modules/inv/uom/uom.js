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


 //Get the uom_id on find button click
 $('a.show.uom_id').click(function() {
	var uom_id = $('#uom_id').val();
	$(this).attr('href', modepath() + 'uom_id=' + uom_id);
 });

 //popu for selecting accounts
 $('#content').on('click', '.account_popup', function() {
	var fieldClass = $(this).closest('li').find('.select_account').prop('class');
	localStorage.setItem("field_class", fieldClass);
	var openUrl = 'select.php?class_name=coa_combination';
	void window.open(openUrl, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'uom_id';
 classContextMenu.btn1DivId = 'uom_id';
 classContextMenu.contextMenu();



 //save class
 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=uom';
 classSave.form_header_id = 'uom';
 classSave.primary_column_id = 'uom_id';
 classSave.single_line = false;
 classSave.savingOnlyHeader = true;
 classSave.enable_select = true;
 classSave.headerClassName = 'uom';
 classSave.saveMain();


});

