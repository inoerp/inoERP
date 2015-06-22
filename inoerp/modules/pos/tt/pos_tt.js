function setValFromSelectPage(pos_transaction_header_id, terminal_name) {
 this.pos_transaction_header_id = pos_transaction_header_id;
 this.terminal_name = terminal_name;
}

setValFromSelectPage.prototype.setVal = function () {

 if (this.pos_transaction_header_id) {
  $("#pos_transaction_header_id").val(this.pos_transaction_header_id);
 }

 if (this.terminal_name) {
  $("#terminal_name").val(this.terminal_name);
 }
};

function recalculateAmount() {
 var amount_r = +$('#screen_number').val() - +$('#total_amount').val();
 $('.return_amount').val(amount_r);
}

$(document).ready(function () {
 //Popup for selecting option type
 $("#pos_terminal").off("click", '.pos_transaction_header_id.select_popup')
         .on("click", '.pos_transaction_header_id.select_popup', function () {
          void window.open('select.php?class_name=pos_tt_header', '_blank',
                  'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
         });

 $("#pos_terminal").off("click", '.pos_terminal_header_id.select_popup')
         .on("click", '.pos_terminal_header_id.select_popup', function () {
          void window.open('select.php?class_name=pos_terminal', '_blank',
                  'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
         });

 $('#content').off('blur', '.item_number').on('blur', '.item_number', function () {
  if (!$(this).val()) {
   return true;
  }
  $(this).closest('tr').find('.quantity').val('1');
 });


//Calculate Line Amounts
 $('body').on('calPOSLineAmount', '.line_amount', function () {
  var line_amount_e = $(this);
  if ((!line_amount_e.closest('tr').find('.unit_price').val()) || (!line_amount_e.closest('tr').find('.unit_price').val())) {
   return true;
  }
  var unit_price = +line_amount_e.closest('tr').find('.unit_price').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  var quantity = +line_amount_e.closest('tr').find('.quantity').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  if (line_amount_e.closest('tr').find('.discount_amount').val()) {
   var discount_amount = +line_amount_e.closest('tr').find('.discount_amount').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  } else {
   var discount_amount = 0;
  }
  var line_amount = (unit_price * quantity);
  var amount_after_discount = line_amount - discount_amount;
//  line_amount_e.val(line_amount);
  $(line_amount_e).closest('tr').find('.line_amount').val(line_amount);
  $(line_amount_e).closest('tr').find('.amount_after_discount').val(amount_after_discount);
  var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
  $('#pos_transaction_line_cust_view').find(trClass).find('.amount_after_discount').val(amount_after_discount);
 });

 $('#content').off('blur', '.unit_price, .quantity, .discount_amount').on('blur', '.unit_price, .quantity, .discount_amount', function () {
  $(this).closest('tr').find('.line_amount').trigger('calPOSLineAmount');
 });

 $('body').off('blur', '.discount_code').on('blur', '.discount_code', function () {
  if (!$(this).val() || (isNaN($(this).val()))) {
   return true;
  }
  var discount_amount_per = +$(this).closest('tr').find('.discount_code').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  var line_amount = +$(this).closest('tr').find('.line_amount').val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  var dicount_amount = (discount_amount_per * line_amount) / 100;
//  alert(line_amount +  ' : ' + dicount_amount)
  $(this).closest('tr').find('.discount_amount').val(dicount_amount);
  $(this).closest('tr').find('.line_amount').trigger('calPOSLineAmount');
 });


 //Calculate Header Amounts
 $('body').on('calPOSHeaderAmount', '#total_amount', function () {
  var total_amount_e = $(this);
  var line_amount_sum = 0;
  var discount_amount_sum = 0;
  $('#form_line').find('.line_amount').each(function () {
   line_amount_sum += +$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  });

  $('#form_line').find('.discount_amount').each(function () {
   discount_amount_sum += +$(this).val().replace(/(\d+),(?=\d{3}(\D|$))/g, "$1");
  });

  var total_amount = line_amount_sum - discount_amount_sum;
  total_amount_e.val(total_amount);
  $('.header_amount').val(line_amount_sum);
  $('.total_amount').val(total_amount);
  $('#form_header .discount_amount, #form_header_total_cust .discount_amount').val(discount_amount_sum);
 });

 $('#content').off('blur', '.unit_price, .quantity, .discount_amount, .line_amount').on('blur', '.unit_price, .quantity, .discount_amount, .line_amount', function () {
  $('#total_amount').trigger('calPOSHeaderAmount');
 });


//Re calculate header amount on removing lines
 $('#content').off('click', '.remove_row_img').on('click', '.remove_row_img', function () {
  if (($(this).closest('form').find('tbody').first().children().filter('tr').length) > 1) {
   $(this).closest("tr").remove();
  } else {
   return;
  }
  var headerClassName = $('ul#js_saving_data').find('.headerClassName').data('headerclassname');
  if (headerClassName && headerClassName !== 'undefined' && headerClassName === 'pos_transaction_header') {
   $('#total_amount').trigger('calPOSHeaderAmount');
  }
 });


 var rowCount = 700;
 $('body').on('blur', '#scanned_item', function () {
  if (!$(this).val()) {
   return false;
  }
  var scannedData = $(this).val().split('/');
  $("#pos_transaction_line_line input.item_number").each(function () {
   if (!$(this).val()) {
    var trClass = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
    $(trClass).find('.item_number').val(scannedData[0]);
    if (scannedData[1]) {
     $(trClass).find('.unit_price').val(scannedData[1]);
    }
    if (scannedData[2]) {
     $(trClass).find('.quantity').val(scannedData[2]);
    }
    if (scannedData[3]) {
     $(trClass).find('.discount_code').val(scannedData[3]);
    }

    if (scannedData[4]) {
     $(trClass).find('.discount_amount').val(scannedData[4]);
    } else if (scannedData[3]) {
     $(trClass).find('.discount_code').trigger('blur');
    }

    if (scannedData[5]) {
     $(trClass).find('.line_amount').val(scannedData[5]);
    } else if (scannedData[2]) {
     $(trClass).find('.quantity').trigger('blur');
    }

    if (scannedData[6]) {
     $(trClass).find('.amount_after_discount').val(scannedData[6]);
    }
    $("#pos_transaction_line_line tr.pos_transaction_line0").first().clone().attr('class', 'newLine' + rowCount).appendTo($(this).closest('tbody'));
    $("#pos_transaction_line_cust_view tr.pos_transaction_line0").first().clone().attr('class', 'newLine' + rowCount).appendTo($('#pos_transaction_line_cust_view tbody'));
    $('.newLine' + rowCount).find(':input').not('.hidden').val('');
    rowCount++;
    $('#scanned_item').val('').focus();
    return false;

   }
  });

 });


// Get all the keys from document
 var keys = $('#calculator span');
 var operators = ['+', '-', 'x', '÷'];
 var decimalAdded = false;

 for (var i = 0; i < keys.length; i++) {
  keys[i].onclick = function (e) {
   // Get the input and button values
   var input = $('#screen_number');
   var inputVal = $('#screen_number').val();
   var btnVal = $(this).data('btn_value');
   var finalValue = $('#screen_number').val();


   switch (btnVal) {
    case 'C':
     decimalAdded = false;
     finalValue = '';
     break;

    case '+':
    case '-':
    case 'x':
    case '÷':
     // Operator is clicked
     var lastChar = inputVal[inputVal.length - 1];

     // Only add operator if input is not empty and there is no operator at the last
     if (inputVal != '' && operators.indexOf(lastChar) == -1)
      finalValue += btnVal;

     // Allow minus if the string is empty
     else if (inputVal == '' && btnVal == '-')
      finalValue += btnVal;

     // Replace the last operator (if exists) with the newly pressed operator
     if (operators.indexOf(lastChar) > -1 && inputVal.length > 1) {
      // Here, '.' matches any character while $ denotes the end of string, so anything (will be an operator in this case) at the end of string will get replaced by new operator
      finalValue = inputVal.replace(/.$/, btnVal);
     }

     decimalAdded = false;
     break;

    case '=':
     var equation = inputVal;
     var lastChar = equation[equation.length - 1];

     // Replace x with * and ÷ with /
     equation = equation.replace(/x/g, '*').replace(/÷/g, '/');

     // Remove the last last chacarcter if it's an operator or a decimal, remove it
     if (operators.indexOf(lastChar) > -1 || lastChar == '.')
      equation = equation.replace(/.$/, '');

     if (equation)
      finalValue = eval(equation);
     decimalAdded = false;
     break;

    case '.':
     if (!decimalAdded) {
      finalValue += btnVal;
      decimalAdded = true;
     }
     break;

    case 'new_transaction':
     $('a#new_page_button').trigger('click');
     break;

    case 'card_payment':

     break;

    case 'done':
     recalculateAmount();
     $('#save').trigger('click');
     break;

    case 'reprint':
     recalculateAmount();
     break;

    case 'recalculate':
     recalculateAmount();
     break;

    default:
     finalValue += btnVal;
     break;
   }

   $(input).val(finalValue);
   // prevent page jumps
   e.preventDefault();
  };
 }

 if (!$('#pos_transaction_header_id').val()) {
  if ($('#terminal_name').val() == '00000') {
   alert('Please update your terminal number!');
  } else {
   $('#save').trigger('click');
  }
 }

 $('body').on('click', '.save_terminal_name', function () {
  save_posTerminalName();
 })

});


