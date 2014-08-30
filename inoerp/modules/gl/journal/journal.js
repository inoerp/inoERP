function setValFromSelectPage(gl_journal_header_id, combination, coa_id) {
 this.gl_journal_header_id = gl_journal_header_id;
 this.combination = combination;
 this.coa_id = coa_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var gl_journal_header_id = this.gl_journal_header_id;
 var combination = this.combination;
 var coa_id = this.coa_id;
 var ledger_coa_id = $('#coa_id').val();
 var rowClass = '.' + localStorage.getItem("row_class");
 var fieldClass = '.' + localStorage.getItem("field_class");
 rowClass = rowClass.replace(/\s+/g, '.');
 fieldClass = fieldClass.replace(/\s+/g, '.');

 if (gl_journal_header_id) {
	$("#gl_journal_header_id").val(gl_journal_header_id);
 }

 if (typeof coa_id !== 'undefined') {
	if ((ledger_coa_id === coa_id)) {
	 $('#content').find(rowClass).find(fieldClass).val(combination);
	} else {
	 alert('Wrong COA id selected - ledger_coa_id is : ' + ledger_coa_id + ' selected coa_id is :' + coa_id);
	}
 }

 localStorage.removeItem("row_class");

};

$(document).ready(function() {
//mandatory and field sequence
var mandatoryCheck = new mandatoryFieldMain();
mandatoryCheck.header_id = 'gl_journal_header_id';
mandatoryCheck.mandatoryHeader();
mandatoryCheck.form_area = 'form_header';
mandatoryCheck.mandatory_fields = ["ledger_id", "currency", "gl_period_id"];
mandatoryCheck.mandatory_messages = ["First Select Ledger", "No Currency", "No GL Period"];
//mandatoryCheck.mandatoryField();



 //setting the first line & shipment number
 if (!($('.line_num:first').val())) {
	$('.line_num:first').val('1');
 }

 //exchange rate calcualtions
 $('#content').on('blur', '.total_dr', function() {
	if ($(this).val()) {
	 if ($('#exchange_rate').val()) {
		var exchange_rate_s = $('#exchange_rate').val();
		var exchange_rate = +exchange_rate_s.replace(/,/g, "");
	 } else {
		var exchange_rate = 1;
	 }
	 $(this).closest('tr').find('.total_cr').val('');
	 $(this).closest('tr').find('.total_ac_cr').val('');
	 var total_ac_dr_s = $(this).val();
	 var total_ac_dr = (+total_ac_dr_s.replace(/,/g, "")) * (exchange_rate);
	 $(this).closest('tr').find('.total_ac_dr').val(total_ac_dr);
	}
 });

 $('#content').on('blur', '.total_cr', function() {
	if ($(this).val()) {
	 if ($('#exchange_rate').val()) {
		var exchange_rate_s = $('#exchange_rate').val();
		var exchange_rate = +exchange_rate_s.replace(/,/g, "");
	 } else {
		var exchange_rate = 1;
	 }
	 $(this).closest('tr').find('.total_dr').val('');
	 $(this).closest('tr').find('.total_ac_dr').val('');
	 var total_ac_cr_s = $(this).val();
	 var total_ac_cr = (+total_ac_cr_s.replace(/,/g, "")) * (exchange_rate);
	 $(this).closest('tr').find('.total_ac_cr').val(total_ac_cr);
	}
 });

//-- change all line values on chaning the rate
 $('#exchange_rate').on('change', function() {
	var exchange_rate_s = $('#exchange_rate').val();
	var exchange_rate = +exchange_rate_s.replace(/,/g, "");
	$('#form_line').find('tr').each(function() {
	 if ($(this).find('.total_dr').val()) {
		var total_dr_s = $(this).find('.total_dr').val();
		var total_dr = (+total_dr_s.replace(/,/g, "")) * (exchange_rate);
		$(this).find('.total_ac_dr').val(total_dr);
	 } else if ($(this).find('.total_cr').val()) {
		var total_cr_s = $(this).find('.total_cr').val();
		var total_cr = (+total_cr_s.replace(/,/g, "")) * (exchange_rate);
		$(this).find('.total_ac_cr').val(total_cr);
	 }
	});

 });


 //Coa auto complete
// var coaCombination = new autoCompleteMain();
// var coa_id = $('#coa_id').val();
// coaCombination.json_url = 'modules/gl/coa_combination/coa_search.php';
// coaCombination.primary_column1 = coa_id;
// coaCombination.select_class = 'select_account';
// coaCombination.min_length = 4;
// coaCombination.autoComplete();

//popu for selecting accounts
 $('#content').on('click', '.account_popup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	var fieldClass = $(this).closest('td').find('.select_account').prop('class');
	var coa_id = $('#coa_id').val();
	localStorage.setItem("row_class", rowClass);
	localStorage.setItem("field_class", fieldClass);
	var link = 'select.php?class_name=coa_combination&coa_id=' + coa_id;
		if ($(this).siblings('.code_combination_id').val()) {
	 link += '&combination=' + $(this).siblings('.code_combination_id').val();
	}
	localStorage.setItem("reset_link_ofSelect", link);
	void window.open(link, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Select the header id
 $("a.select.header_id_popup").click(function() {
	void window.open('select.php?class_name=gl_journal_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 //Get the header id on find button click
 $('a.show.gl_journal_header_id').click(function() {
	var gl_journal_header_id = $('#gl_journal_header_id').val();
//$(this).prop('href','po.php?po_header_id=' + poId);
	$(this).attr('href', modepath() + 'gl_journal_header_id=' + gl_journal_header_id);
 });

 $('a.show.ledger_id').click(function() {
	var ledger_id = $('#ledger_id').val();
	$(this).attr('href', modepath() + 'ledger_id=' + ledger_id);
 });

 onClick_add_new_row('gl_journal_line', 'gl_journal_line_values', 2, 'status');

//context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'gl_journal_header_id';
 classContextMenu.docLineId = 'gl_journal_line_id';
 classContextMenu.btn1DivId = 'gl_journal_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'gl_journal_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
 classContextMenu.contextMenu();

// deleteData('json.po.php');

//before save & save function
 function beforeSave() {
	var sum_total_dr = 0;
	$('.total_dr').each(function() {
	 var sum_total_dr_s = $(this).val();
	 sum_total_dr += +sum_total_dr_s.replace(/,/g, "");
	});
	var sum_total_cr = 0;
	$('.total_cr').each(function() {
	 var sum_total_cr_s = $(this).val();
	 sum_total_cr += +sum_total_cr_s.replace(/,/g, "");
	});
	if (sum_total_dr === sum_total_cr) {
	 return 1;
	} else {
	 alert('Cant save data as journal is not in balance \nSum of total debit is : ' + sum_total_dr + ' & total credit is : ' + sum_total_cr);
	 return -99;
	}
 }

 var classSave = new saveMainClass();
 classSave.json_url = 'form.php?class_name=gl_journal_header';
 classSave.form_header_id = 'gl_journal_header';
 classSave.primary_column_id = 'gl_journal_header_id';
 classSave.line_key_field = 'code_combination_id';
 classSave.single_line = false;
 classSave.enable_select = true;
 classSave.savingOnlyHeader = false;
 classSave.headerClassName = 'gl_journal_header';
 classSave.lineClassName = 'gl_journal_line';
 classSave.saveMain(beforeSave);

 //Reverse Journal
// $('#change_satus').on('change', function() {
//	var classSave = new saveMainClass();
//	classSave.json_url = 'form.php?class_name=gl_journal_header';
//	classSave.form_header_id = 'gl_journal_header';
//	classSave.primary_column_id = 'gl_journal_header_id';
//	classSave.single_line = false;
//	classSave.enable_select = true;
//	classSave.savingOnlyHeader = false;
//	classSave.headerClassName = 'gl_journal_header';
//	classSave.saveMain();
//	$("#save").trigger("click");
// });


 $('#change_satus').on('change', function() {
	var headerId = $('#gl_journal_header_id').val();
	if ($(this).val() === 'REVERSED') {
	 var disabledId = [];
	 $('select:disabled').each(function() {
		disabledId.push($(this).attr('id'));
	 });
	 $('select:disabled').attr('disabled', false);
	 if (confirm("Do you really want to reverse the journal header ?\n" + headerId)) {
		$(".error").append('Reversing Journal..');
		var form_header_id = '#gl_journal_header';
		var headerData = $(form_header_id).serializeArray();
		saveHeader('form.php?class_name=gl_journal_header', headerData, '#gl_journal_header_id', '', true, 'gl_journal_header');
	 }
	}
	$(disabledId).each(function(i, v) {
	 var divId = '#' + v;
	 $('#content').find(divId).attr('disabled', false);
	});
 });

});
