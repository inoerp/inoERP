function copy_document(doc_header_id, doc_line_id) {
 var doc_header_id_h = '#' + doc_header_id;
 var doc_header_id_c = '.' + doc_header_id;
 var doc_line_id_c = '.' + doc_line_id;
 $(doc_header_id_h).val('');
 $(doc_header_id_c).val('');
 $(doc_line_id_c).val('');
}

function copy_header(doc_header_id) {
 var doc_header_id_h = '#' + doc_header_id;
 $(doc_header_id_h).val('');
 var trClass = '.' + $("#form_line tbody tr:first").prop('class');
 $("#form_line tbody tr:not(" + trClass + ")").remove();
 $("#form_line tbody tr").find(':input').each(function() {
	$(this).val('');
 });
}

//right click menu
function rightClickMenu(menuContent) {
 var menu = "<div id='right_click_menu'>" + menuContent + "</div>";
 $("#content").bind("contextmenu", function(event) {
	event.preventDefault();
	if ($("#right_click_menu")) {
	 $("div#right_click_menu").remove();
	}
	$(menu).appendTo("#content").css({top: event.pageY + "px", left: event.pageX + "px"});
 });
 $('body').bind("click", function(event) {
	$("div#right_click_menu").remove();
 });
}


//export to excel
function contextMenuMain(docHedaderId, docLineId, trClass, tbodyClass, noOfTabbs, btn1DivId, btn2DivId,
				btn2_1DivId, btn6DivId, btn7DivId, btn8DivId,
				btn9DivId, btn9_1DivId, btn9_2DivId, btn9_3DivId, btn10DivId) {
 this.docHedaderId = docHedaderId;
 this.docLineId = docLineId;
 this.btn1DivId = btn1DivId;
 this.btn2DivId = btn2DivId;
 this.btn2_1DivId = btn2_1DivId;
 this.trClass = trClass;
 this.tbodyClass = tbodyClass;
 this.noOfTabbs = noOfTabbs;
 this.btn6DivId = btn6DivId;
 this.btn7DivId = btn7DivId;
 this.btn8DivId = btn8DivId;
 this.btn9DivId = btn9DivId;
 this.btn9_1DivId = btn9_1DivId;
 this.btn9_2DivId = btn9_2DivId;
 this.btn9_3DivId = btn9_3DivId;
 this.btn10DivId = btn10DivId;
}

contextMenuMain.prototype.contextMenu = function()
{
 var docHedaderId = this.docHedaderId;
 var docLineId = this.docLineId;
 var docLineId_c = '.' + this.docLineId;
 var trClass = this.trClass;
 var trClass_c = '.' + this.trClass;
 var tbodyClass = this.tbodyClass;
 var tbodyClass_c = '.' + this.tbodyClass;
 var noOfTabbs = this.noOfTabbs;
 var btn1DivId = this.btn1DivId;
 var btn2DivId = this.btn2DivId;
 var btn2_1DivId = this.btn2_1DivId;
 var btn6DivId = this.btn6DivId;
 var btn7DivId = this.btn7DivId;
 var btn8DivId = this.btn8DivId;
 var btn9DivId = this.btn9DivId;
 var btn9_1DivId = this.btn9_1DivId;
 var btn9_2DivId = this.btn9_2DivId;
 var btn9_3DivId = this.btn9_3DivId;
 var btn10DivId = this.btn10DivId;

 var menuContent = "<ul id='level1'>";
 menuContent += "<li id='menu_button1' class='export_excel'>Export Header</li>";
 menuContent += "<li id='menu_button2' class='end_li_type export_excel'>Export Line";
 menuContent += "<ul>";
 menuContent += "<li id='menu_button2_1' class='end_li_type export_excel'>Second Line Form</li>";
 menuContent += "</ul></li>";
 menuContent += "<li id='menu_button3' class='end_li_type print'>Print Document</li>";
 menuContent += "<li id='menu_button4' class='copy_doc'>Copy Header";
 menuContent += "<ul>";
 menuContent += "<li id='menu_button4_1' class='copy_doc'>Copy & Save Header</li>";
 menuContent += "<li id='menu_button4_2' class='copy_doc'>Copy Document";
 menuContent += "<ul>";
 menuContent += "<li id='menu_button4_2_1'>Copy & Save Document</li>";
 menuContent += "</ul></li>";
 menuContent += "</ul></li>";
 menuContent += "<li id='menu_button5' class='end_li_type copy_line'>Copy Line</li>";
 menuContent += "<li id='menu_button6' class='preference'>Preferences</li>";
 menuContent += "<li id='menu_button7' class='help help'>Help</li>";
 menuContent += "<li id='menu_button8' class='doc_history'>Document History</li>";
 menuContent += "<li id='menu_button9' class='end_li_type custom_code'>Custom Code";
 menuContent += "<ul>";
 menuContent += "<li id='menu_button9_1' class='end_li_type'>Disable</li>";
 menuContent += "<li id='menu_button9_2' class='end_li_type'>Enable</li>";
 menuContent += "<li id='menu_button9_3' class='end_li_type'>View & Update</li>";
 menuContent += "</ul></li>";
 menuContent += "<li id='menu_button10' class='about'>About inoERP</li>";
 menuContent += "<ul>";
 rightClickMenu(menuContent);

 $("#content").on('click', '#menu_button1', function() {
	var classDnldExcel = new exportToExcelMain();
	classDnldExcel.containerType = 'div';
	classDnldExcel.divId = btn1DivId;
	classDnldExcel.exportToExcel();
 });

 $("#content").on('click', '#menu_button2', function() {
	var classDnldExcel = new exportToExcelMain();
	classDnldExcel.containerType = 'table';
	classDnldExcel.divId = btn2DivId;
	classDnldExcel.numberOfTabs = 1;
	classDnldExcel.exportToExcel();
 });

 $("#content").on('click', '#menu_button3', function() {
	window.print();
 });

 $("#content").on('click', '#menu_button4', function() {
	copy_header(docHedaderId);
 });

 $("#content").on('click', '#menu_button4_1', function() {
	copy_header(docHedaderId);
	$('#save').trigger('click');
 });

 $("#content").on('click', '#menu_button4_2', function() {
	copy_document(docHedaderId, docLineId);
 });

 $("#content").on('click', '#menu_button4_2_1', function() {
	copy_document(docHedaderId, docLineId);
	$('#save').trigger('click');
 });

 $("#content").on('click', '#menu_button5', function() {
	trclass = '.' + $("#form_line tr:last").prop('class');
	add_new_row_withDefault(trClass_c, tbodyClass_c, noOfTabbs, docLineId_c);
 });

};

 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'sys_value_group_header_id';
 classContextMenu.docLineId = 'sys_value_group_line_id';
 classContextMenu.btn1DivId = 'sys_value_group_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'sys_value_group_line';
 classContextMenu.tbodyClass = 'sys_value_group_line_values';
 classContextMenu.noOfTabbs = 4;
 classContextMenu.contextMenu();