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
function beforeSave() {
	var sum_total_dr = 0;
	$('.total_dr').each(function() {
	  sum_total_dr += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
	});
	var sum_total_cr = 0;
	$('.total_cr').each(function() {
   sum_total_cr += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
	});
	if (sum_total_dr === sum_total_cr) {
	 return 1;
	} else {
	 alert('Cant save data as journal is not in balance \nSum of total debit is : ' + sum_total_dr + ' & total credit is : ' + sum_total_cr);
	 return -99;
	}
 }


$(document).ready(function() {
//mandatory and field sequence
var mandatoryCheck = new mandatoryFieldMain();
mandatoryCheck.header_id = 'gl_journal_header_id';
mandatoryCheck.mandatoryHeader();
//mandatoryCheck.form_area = 'form_header';
//mandatoryCheck.mandatory_fields = ["ledger_id", "currency", "gl_period_id"];
//mandatoryCheck.mandatory_messages = ["First Select Ledger", "No Currency", "No GL Period"];
////mandatoryCheck.mandatoryField();



 //setting the first line & shipment number
 if (!($('.line_num:first').val())) {
	$('.line_num:first').val('1');
 }


 $('#ledger_id').on('change', function() {
  getLedgerDetails($(this).val());
 });

 if ($('#ledger_id').val() && (!$('#gl_journal_header_id').val())) {
  getLedgerDetails($('#ledger_id').val());
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


 //Select the header id
 $(".gl_journal_header_id.select_popup").click(function() {
	void window.open('select.php?class_name=gl_journal_header', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

 
 $('#action').on('change', function() {
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
		saveHeader('form.php?class_name=gl_journal_header', headerData, '#gl_journal_header_id', '','', true, 'gl_journal_header');
	 }
	}
	$(disabledId).each(function(i, v) {
	 var divId = '#' + v;
	 $('#content').find(divId).attr('disabled', false);
	});
 });
 
 });