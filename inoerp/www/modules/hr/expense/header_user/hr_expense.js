function   beforeCopyFun() {
 var newLink = $('a.show.document_id').prop('href') + '&copydoc=1';
 $('a.show.document_id').prop('href', newLink);
 $('a.show.document_id').trigger('click');
 return false;
}


$(document).ready(function () {
//setting the first line & shipment number
 if (!($('.lines_number:first').val())) {
  $('.lines_number:first').val('1');
 }

 $('body').off('change', '#bu_org_id').on('change', '#bu_org_id', function () {
  getBUDetails($(this).val());
 });

 if ($('#bu_org_id').val() && (!$('#po_header_id').val()) && ($('#bu_org_id').attr('disabled') !== 'disabled')) {
  getBUDetails($('#bu_org_id').val());
 }

 //exhhnge rate
 $('body').on('change', '#doc_currency', function () {
  if ($(this).val() !== $('#currency').val()) {
   $('#exchange_rate').prop('required', true).css('background', 'rgba(233, 209, 234, 0.61)');
  }
 });

 if ($('#currency').val() == $('#doc_currency').val()) {
  $('#exchange_rate').val('1');
 } else if ((!$('#exchange_rate').val()) && $('#currency').val() != $('#doc_currency').val()) {
  getExchangeRate();
 }

 $('body').off('change', '#currency, #doc_currency, #exchange_rate_type')
         .on('change', '#currency, #doc_currency, #exchange_rate_type', function () {
          getExchangeRate();
         });

 $('body').off('change', '#expense_template_id').on('change', '#expense_template_id', function () {
  getSelectOptionsForExpense();
 });

 $('body').off('change', '.expense_type').on('change', '.expense_type', function () {
  var trClass = '.' + $(this).closest('tr').prop('class').replace(/\s+/g, '.');
  var expense_category = $(this).find('option:selected').data('expense_category');

  switch (expense_category) {
   case 'PER_DIEM':
    $(trClass).find('.mileage_uom_id, .mileage_distace, .mileage_rate').val('').prop('readonly', true).addClass('always_readonly');
    $(trClass).find('.per_diem_rate, .per_diem_days').prop('readonly', false).removeClass('always_readonly');
    break;
   case 'MILEAGE':
    $(trClass).find('.per_diem_rate, .per_diem_days').val('').prop('readonly', true).addClass('always_readonly');
    $(trClass).find('.mileage_uom_id, .mileage_distace, .mileage_rate').prop('readonly', false).removeClass('always_readonly');

    break;
   default:
    break;
  }
 });

 $('body').off('change', '.expense_location').on('change', '.expense_location', function () {
  var trClass = '.' + $(this).closest('tr').prop('class').replace(/\s+/g, '.');
  getPerDiemRate({
   hr_location_id: $(this).val(),
   rowClass: trClass,
   hr_employee_id: $('.claim_emplyee_id').val()
  });
 });

 //calculate header amount
//calculate header amount
 $('body').off('blur', '.receipt_amount, .header_amount, .exchange_rate')
         .on('blur', '.receipt_amount, .header_amount, .exchange_rate', function () {
          $('body').trigger('calculateHeaderAmount');
         });
//total header & tax amount
 $('body').on('calculateHeaderAmount', function () {
  var header_amount = 0;
  $('#form_line').find('.receipt_amount').each(function () {
   header_amount += (+$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1"));
  });
  $('#header_amount').val(header_amount);
 });

// $("body").off('click', '#menu_button4_2, #menu_button4_2, #menu_button4')
//         .on('click', '#menu_button4_2, #menu_button4_2, #menu_button4', function () {
//          var newLink = $('a.show.document_id').prop('href') + '&copydoc=1';
//          $('a.show.document_id').prop('href', newLink);
//          $('a.show.document_id').trigger('click');
//         });

});