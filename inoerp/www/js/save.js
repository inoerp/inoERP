//save
/*
 * 
 * @param {type} json_url - The url to which form is posted
 * @param {type} form_header_id - header  of the form with out # - same as class name
 * @param {type} primary_column_id - primary column id of the class - used to update the primary id field on form
 * @param {type} single_line - shows if its a single line in the form - ex: item, supplier, customer
 * @param {type} line_key_field - is only used to check if any line checkbox is checked or not..
 * to save that particular line...
 * @param {type} form_line_id - line of the form with out # - same as class name
 * form_line_id is used for collecting form data for single line forms
 * its used as default class name if the line class name is not mentioned
 * @param {type} primary_column_id2
 * @param {type} enable_select - enable/disbale select fields
 * @ headerClassName - Class name of the header - not mnadatory - defaults from form_header_id if not specified
 * @ lineClassName - Class name of the Line - not mnadatory - defaults from form_line_id if not specified
 * @returns {undefined}
 * savetype1 - header
 * savetype2 - single line
 * savetype3a - multiple lines checked with tab
 * savetype3b - multiple lines checked - w/o tab
 * savetype4a - multiple lines un checked with tab
 * savetype4b - multiple lines un checked - w/o tab
 * savetype5a - third class form with tab
 * savetype5a - third class form w/o tab
 */

function saveHeader(json_url, headerData, primary_column_id, primary_column_id2, primary_column_id3, savingOnlyHeader,
        form_header, onlyHeaderOverLay) {
 if (localStorage.getItem("dont_save_header") == 9) {
  localStorage.removeItem("dont_save_header");
  return true;
 }
 var dont_show_save_msg = $('ul#js_saving_data').find('.dont_show_save_msg').data('dont_show_save_msg');
 if ($(primary_column_id).val()) {
  var trigger_save_for_line = false;
 } else {
  var trigger_save_for_line = true;
 }
 return $.ajax({
  url: json_url,
  data: {headerData: headerData,
   className: form_header},
  type: 'post',
  success: function (result) {

   if (result) {
    var div = $(result).filter('div#json_save_header').html();
//  if ($(div).length > 1) {
//   $(".error").append(div);
//  }

    var message = $(result).find('.message, .rollback_msg').html();
    if (message && message.length > 1 && (!dont_show_save_msg)) {
     $(".error").prepend(result);
     $("#accordion").accordion({active: 0});
    }

    if (primary_column_id) {
     var primary_column_class = primary_column_id.replace('#', '.');
     var header_id = $(result).find('div#headerId').html();
     var header_id2 = $(result).find('div#primary_column2').html();
     var header_id3 = $(result).find('div#primary_column3').html();

     if (header_id && header_id !== 'undefined') {
      $(primary_column_id).val(header_id);
      $(primary_column_class).val(header_id);
     }

     if ($(primary_column_id2)) {
      $('.primary_column2').val(header_id2);
     }
     if ($(primary_column_id3)) {
      $('.primary_column3').val(header_id3);
     }
    }
    if (localStorage.getItem("save_all_lines") == 9) {
     $('input[name="line_id_cb"]').prop('checked', true);
     $('input[name="detail_id_cb"]').prop('checked', true);
     localStorage.removeItem("save_all_lines");
     localStorage.setItem("dont_save_header", 9);
     $('#save').trigger('click');
    } else if ($('ul#js_saving_data').find('.lineClassName').data('lineclassname') && trigger_save_for_line) {
     localStorage.setItem("dont_save_header", 9);
     $('#save').trigger('click');
    }
    if (savingOnlyHeader || onlyHeaderOverLay) {
     $('#overlay').css('display', 'none');
     $('#form_top_image').css('display', 'block');
    }
   }
  },
  beforeSend: function () {
   if (!dont_show_save_msg) {
    $('#overlay').css('display', 'block');
    $('#form_top_image').css('display', 'none');
   }
  },
  error: function (request, errorType, errorMessage) {
   alert('Request ' + request + ' has errored with ' + errorType + ' : ' + errorMessage);
  },
  complete: function () {
   $('.show_loading_small').hide();
   $('body').find('.remove_after_save').val('');
  }
 });
}

function saveSingleLine(json_url, lineData, primary_column_id, lineClassName) {
 var header_id = $(primary_column_id).val();
 return $.ajax({
  url: json_url,
  data: {
   lineData: lineData,
   header_id: header_id,
   className: lineClassName},
  type: 'post',
  beforeSend: function () {
   $('#overlay').css('display', 'block');
   $('#form_top_image').css('display', 'none');
  }
 }).done(function (result) {
//  var div = $(result).filter('div#json_save_line').html();
  var message = $(result).find('.message, .rollback_msg').html();
  if (message && message.length > 1) {
   $(".error").prepend(result);
   $("#accordion").accordion({active: 0});
  }

  var line_id = $(result).filter('#lineId').html();
//	$('#form_data_table tbody tr' + '.' + trclass).find(".line_id").val(line_id);
  $('#overlay').css('display', 'none');
  $('#form_top_image').css('display', 'block');
  $('body').find('.remove_after_save').val('');
 }).fail(function (error, textStatus, xhr) {
  $('#overlay').css('display', 'none');
  $('#form_top_image').css('display', 'block');
  alert("save failed \n" + error + textStatus + xhr);
 });
}

function saveLine(json_url, lineData, trclass, detailData, primary_column_id, lineClassName, detailClassName) {
 var header_id = $(primary_column_id).val();
 $.ajax({
  url: json_url,
  data: {lineData: lineData,
   detailData: detailData,
   header_id: header_id,
   className: lineClassName,
   detail_classname: detailClassName,
   trclass: trclass
  },
  type: 'post',
  beforeSend: function () {
   $('#overlay').css('display', 'block');
   $('#form_top_image').css('display', 'none');
  }
 }).done(function (result) {
  var div = $(result).filter('div#json_save_line').html();

  var message = $(result).find('.message, .rollback_msg').html();
  if (message && message.length > 1) {
   $(".error").prepend(result);
   $("#accordion").accordion({active: 0});
  }

  var line_id = $(result).find('.lineId').data('trclass');

  if (typeof line_id == 'undefined') {
   console.log('existing line_id is ' + line_id);
  } else {
   $('#content ' + '.' + trclass).find(".line_id").val(line_id);
  }

  $('#overlay').css('display', 'none');
  $('#form_top_image').css('display', 'block');
  $('body').find('.remove_after_save').val('');
 }).fail(function (error, textStatus, xhr) {
  $('#overlay').css('display', 'none');
  $('#form_top_image').css('display', 'block');
  alert("save failed \n" + error + textStatus + xhr);
 });
}

function saveLineSecondForm(json_url, lineData, trclass, detailData, lineClassName, tbodyClass) {
 var header_id = $("#header_id").val();
 $.ajax({
  url: json_url,
  data: {lineData2: lineData,
   detailData: detailData,
   header_id: header_id,
   className: lineClassName,
   trclass: trclass
  },
  type: 'post'
 }).done(function (result) {
  var div = $(result).filter('div#json_save_line2').html();
  var line_id = $(result).find('.lineId').data('trclass');
  $('tbody.' + tbodyClass + ' tr' + '.' + trclass).find(".line_id").val(line_id);
  var message = $(result).find('.message, .rollback_msg').html();
  if (message && message.length > 1) {
   $(".error").prepend(div);
   $("#accordion").accordion({active: 0});
  }
  $('#overlay').css('display', 'none');
  $('#form_top_image').css('display', 'block');
  $('body').find('.remove_after_save').val('');
 }).fail(function (error, textStatus, xhr) {
  $('#overlay').css('display', 'none');
  $('#form_top_image').css('display', 'block');
  alert("save failed \n" + error + textStatus + xhr);
 });
}

function saveMainClass(json_url, form_header_id, primary_column_id, single_line,
        line_key_field, form_line_id, primary_column_id2, primary_column_id3, enable_select, savingOnlyHeader,
        headerClassName, lineClassName, detailClassName, lineClassName2, lineClassName3, onlyOneLineAtATime,
        allLineTogether, saveVerticalTab, onlyHeaderOverLay) {
 this.json_url = json_url;
 this.form_header_id = form_header_id;
 this.primary_column_id = primary_column_id;
 this.line_key_field = line_key_field;
 this.form_line_id = form_line_id;
 this.primary_column_id2 = primary_column_id2;
 this.primary_column_id3 = primary_column_id3;
 this.single_line = single_line;
 this.enable_select = enable_select;
 this.savingOnlyHeader = savingOnlyHeader;
 this.headerClassName = headerClassName;
 this.lineClassName = lineClassName;
 this.detailClassName = detailClassName;
 this.lineClassName2 = lineClassName2;
 this.lineClassName3 = lineClassName3;
 this.onlyOneLineAtATime = onlyOneLineAtATime;
 this.allLineTogether = allLineTogether;
 this.saveVerticalTab = saveVerticalTab;
 this.onlyHeaderOverLay = onlyHeaderOverLay;
}

saveMainClass.prototype.saveMain = function (beforeSave)
{
 var form_header_id_h = '#' + this.form_header_id;
 if (this.form_line_id) {
  var form_line_id = this.form_line_id;
 } else {
  var form_line_id = 'form_line';
 }
 var form_line_id_h = '#' + this.form_line_id;
 if (this.primary_column_id) {
  var primary_column_id_h = '#' + this.primary_column_id;
 }
 var primary_column_id2_h = '#' + this.primary_column_id2;
 var primary_column_id3_h = '#' + this.primary_column_id3;
 var json_url = this.json_url;
 var form_header_id = this.form_header_id;
 var single_line = this.single_line;
 var line_key_field = this.line_key_field;
 var enable_select = this.enable_select;
 var savingOnlyHeader = this.savingOnlyHeader;
 var headerClassName = this.headerClassName;
 var lineClassName = this.lineClassName;
 var detailClassName = this.detailClassName;
 var lineClassName2 = this.lineClassName2;
 var lineClassName3 = this.lineClassName3;
 var onlyOneLineAtATime = this.onlyOneLineAtATime;
 var allLineTogether = this.allLineTogether;
 var onlyHeaderOverLay = this.onlyHeaderOverLay;
 var saveVerticalTab = this.saveVerticalTab;
 var line_key_field_d = '.' + line_key_field;
 $('body').off('click', '#save').on('click', '#save', function (e) {
  json_url = 'form.php?class_name=' + $('ul#js_saving_data').find('.headerClassName').data('headerclassname');
  remove_unsaved_msg();
  if ($.isFunction(window.beforeSave)) {
   var beforeSaveResult = window.beforeSave();
   if (beforeSaveResult < 0) {
    return;
   }
  }

  if (typeof beforeSave === 'function') {
   var beforeSaveResult = beforeSave();
   if (beforeSaveResult < 0) {
    return;
   }
  }

  //verify if header id exists or not - if header id is blank then check header level required fields
//if header id exists then check line level required fields
  var noOfRequiredFileValuesMissing = 0;
  var missingMandatoryValues = [];
  if ((primary_column_id_h) && !$(primary_column_id_h).val()) {
//check header level missing required values - text & select
   $(form_header_id_h + " :required").each(function () {
    if (!$(this).val())
    {
     missingMandatoryValues.push($(this).attr('name').replace(/(\[])|(\_)/g, ' '));
     noOfRequiredFileValuesMissing++;
    }
   });
  } else {
   $(":required").each(function () {
    if (!$(this).val())
    {
     missingMandatoryValues.push($(this).attr('name').replace(/(\[])|(\_)/g, ' '));
     noOfRequiredFileValuesMissing++;
    }
   });
  }
  if (noOfRequiredFileValuesMissing > 0) {
   var showMessage = ' <div id="dialog_box" class="dialog mandatory_message"> ' + noOfRequiredFileValuesMissing + ' mandatory field(s) is/are missing....... <br>';
   $.map(missingMandatoryValues, function (val, i) {
    j = i + 1;
    showMessage += j + ' : ' + val.replace(/_+/, ' ') + ' <br>';
   });
   showMessage += '</div>';
   $("#content").append(showMessage);
   show_dialog_box();
   return;
  }

  if (onlyOneLineAtATime) {
   var numberOfCheckedBoxes = 0;
   $('input[name="line_id_cb"]').each(function () {
    if ($(this).prop("checked")) {
     numberOfCheckedBoxes++;
    }
   });
   if (numberOfCheckedBoxes !== 1) {
    alert(numberOfCheckedBoxes + " Number of Lines are seleceted\nYou can save only one line at a time!");
    return;
   }
  }

  e.preventDefault();
//for all form headers - savetype1
  /*-----------------------------------Completion of mandator fields check & start of header save--------------------------------
   * Check if saving only header data.
   */
  if ($('select:disabled').length > 0) {
   var disabledId = [];
   if (enable_select) {
    $('select:disabled').each(function () {
     disabledId.push($(this).attr('id'));
    });
    $('select:disabled').attr('disabled', false);
   }
  }



  var headerData = $(form_header_id_h + ' :input').not('.search, .text_search').serializeArray();
  if (savingOnlyHeader) {
   savingOnlyHeader = true;
  } else if (($('#form_line').html()) && ($(primary_column_id_h).val()) && ($('input[name="line_id_cb"]:checked').length > 0) && ($(line_key_field_d).val())) {
   savingOnlyHeader = false;
  } else {
   savingOnlyHeader = true;
  }

  if (headerClassName === undefined) {
   headerClassName = form_header_id;
  }

  if (lineClassName === undefined) {
   lineClassName = $('ul#js_saving_data').find('.lineClassName').data('lineclassname');
  }

  if ((typeof headerData !== undefined) && (headerData.length > 0)) {
   saveHeader(json_url, headerData, primary_column_id_h, primary_column_id2_h, primary_column_id3_h, savingOnlyHeader, headerClassName, onlyHeaderOverLay);
  }

  /*---Special for multi select*/
  if (allLineTogether) {
   var allData = [];
   $('input[name="line_id_cb"]:checked').each(function () {
    var trclass = $(this).closest('tr').attr('class');
    var lineData = [];
    $("#form_line").find('.' + trclass + ' > td').each(function () {
     if (!$(this).hasClass('add_detail_values')) {
      var ThisLineData = $(this).find(":input").serializeArray();
      lineData = $.merge(lineData, ThisLineData);
     }
    });
    allData = $.merge(allData, lineData);
   });

   if (allData !== null) {
    if (lineClassName && (lineClassName !== undefined) && $(primary_column_id_h).val()) {
//     alert($(primary_column_id_h).val() + ' : ' + lineClassName)
     saveHeader(json_url, allData, primary_column_id_h, primary_column_id2_h, primary_column_id3_h, savingOnlyHeader, lineClassName);
    } else if ($(primary_column_id_h).length < 1) {
//     alert(2 + ' : ' + $(primary_column_id_h).val() + ' : ' + lineClassName +  ' : ' + $(primary_column_id_h).length)
     saveHeader(json_url, allData, primary_column_id_h, primary_column_id2_h, primary_column_id3_h, savingOnlyHeader, headerClassName);
    }

   }
   return;
  }
  if (enable_select && $('select:disabled').length > 0) {
   $(disabledId).each(function (i, v) {
    $('body').find('#' + v).attr('disabled', true);
   });
  }

  /*-----------------------------------Completion of save header & start of single line form save--------------------------------
   for standard forms liks item, supplier - one header & one line savetype2
   */
  if (saveVerticalTab) {
   $('.tabContainer_v').find('.tabContent').each(function () {
    var lineData = $(this).find(":input").serializeArray();
    saveSingleLine(json_url, lineData, primary_column_id_h, lineClassName);
   });
   return;
  }

  if (single_line) {
   var lineData = $(form_line_id_h).serializeArray();
//   alert('315' + ' :  ' + form_line_id_h + lineData );
   saveSingleLine(json_url, lineData, primary_column_id_h, lineClassName);
  } else {
   /*-----------------------------------Completion of single line & start of multiple lines form save--------------------------------
    for option type of form - one header & multiple lines 
    */
//if  a line is checkeed-----------------------------------------------------------------------
   if ($('input[name="line_id_cb"]:checked').length > 0) {
//for forms with tab @line level - PO-----------------------------savetype3a
    if ($("#tabsLine-1").html()) {
     var count = 0;
     $('input[name="line_id_cb"]:checked').each(function () {
      var trclass = $(this).closest('tr').attr('class');
      var trclass_d = '.' + $(this).closest('tr').attr('class').replace(/\s+/g, '.');
      var lineData = [];
      $("#form_line").find(trclass_d + ' > td').each(function () {
       if (!$(this).hasClass('add_detail_values')) {
        var ThisLineData = $(this).find(":input").serializeArray();
        lineData = $.merge(lineData, ThisLineData);
       }
      });
      if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
       var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
      } else {
       detailData = "";
      }
      count++;
      saveLine(json_url, lineData, trclass, detailData, primary_column_id_h, lineClassName, detailClassName);
     });
//     alert('Saving ' + count + ' Record(s)');
    } else {
//		 for option type form - line w/o any tab------------------savetype3b
     $('input[name="line_id_cb"]:checked').each(function () {
      var lineData = $(this).closest("tr").find(":input").serializeArray();
      var trclass = $(this).closest("tr").attr('class');
      if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
       var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
      } else {
       detailData = "";
      }
//      console.log('446');
      saveLine(json_url, lineData, trclass, detailData, primary_column_id_h, lineClassName, detailClassName);
     });
    }
   }
//i--------------completion of checked line -- start of all lines---------------------------------

//   else if (($(line_key_field_d).val()) && $(primary_column_id_h).val()) {
////for forms with tab @line level - PO - savetype4a
//    if ($("#tabsLine-1").html()) {
//     $("#tabsLine-1 tbody.form_data_line_tbody > tr").each(function () {
//      var trclass = $(this).attr('class');
//      var lineData = [];
//      $("#form_line").find('.' + trclass).each(function () {
//       var ThisLineData = $(this).find(":input").serializeArray();
//       lineData = $.merge(lineData, ThisLineData);
//      });
//      if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
//       var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
//      } else {
//       detailData = "";
//      }
//      if (lineData.length > 1) {
//       saveLine(json_url, lineData, trclass, detailData, primary_column_id_h, lineClassName, detailClassName);
//      }
//
//     });
//    } else {
////for forms without tabs @ line level - Options - savetype4b
//     $("tbody.form_data_line_tbody > tr").each(function () {
//      var lineData = $(this).find(":input").serializeArray();
//      var trclass = $(this).attr('class');
//      if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
//       var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
//      } else {
//       detailData = "";
//      }
////      alert('388');
//      saveLine(json_url, lineData, trclass, detailData, primary_column_id_h, lineClassName, detailClassName);
//     });
//    }
//   }
   /*----------------------End of single header multiple line ----start of second form---------------------------------------------------------------------------*/
//for the third form (second form in line) - savetype5a
   if ((typeof lineClassName2 !== undefined) && (lineClassName2 !== null)) {
    $('#form_line2 input[name="line_id_cb"]:checked').each(function () {
     var trclass = $(this).closest('tr').attr('class');
     var lineData = [];
     $("#form_line2").find('.' + trclass + ' > td').each(function () {
      if (!$(this).hasClass('add_detail_values')) {
       var ThisLineData = $(this).find(":input").serializeArray();
       lineData = $.merge(lineData, ThisLineData);
      }
     });
     if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
      var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
     } else {
      detailData = "";
     }
     count++;
     saveLineSecondForm(json_url, lineData, trclass, detailData, lineClassName2, 'form_data_line_tbody2');
    });
   }

   /*---------------Save 4th form - third line class--------------------*/
   if ((typeof lineClassName3 !== undefined) && (lineClassName3 !== null)) {
    $('#form_line3 input[name="line_id_cb"]:checked').each(function () {
     var trclass = $(this).closest('tr').attr('class');
     var lineData = [];
     $("#form_line3").find('.' + trclass + ' > td').each(function () {
      if (!$(this).hasClass('add_detail_values')) {
       var ThisLineData = $(this).find(":input").serializeArray();
       lineData = $.merge(lineData, ThisLineData);
      }
     });
     if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
      var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
     } else {
      detailData = "";
     }
     count++;
     saveLineSecondForm(json_url, lineData, trclass, detailData, lineClassName3, 'form_data_line_tbody3');
    });
   }
  }
 });
};
/*primary_column_id is the primary_column_id of header form
 * form_header = header class name = form
 line_form_id is REQUIRED FOR one header & one line but  header id = form header name
 * * form_line = line class name = form header id = form header name
 line_form_id is REQUIRED FOR one header & one line but not required for one header & multiple lines
 primary_column_id2 is required for forms which generate a number from id like PO number
 line_key_field is only used to check if any line checkbox is checked or not..to save that particular line...
 ...and its  mandatory..used in all forms but not in all forms that use more 3 different table sets (ex: overhead,WO) (exception : payment term with SEQ)
 line_key_field determines if line ajax should be called or not (correct usage ledger)
 onlyHeader is not mandatory - value 1 shows the form contains only header and 
 the save button is enabled after header saving
 **/

/*---------------------------------------Complete of save & Start of Export-----------------------------------------------------------------*/
//export to excel
function exportToExcelMain(containerType, divId, numberOfTabs) {
 this.containerType = containerType;
 this.divId = divId;
 this.numberOfTabs = numberOfTabs;
}

exportToExcelMain.prototype.exportToExcel = function ()
{
 var containerType = this.containerType;
 var divId_h = '#' + this.divId;
 var divId = this.divId;
 var numberOfTabs = this.numberOfTabs;
 if (containerType == 'table') {
  var data = '<table>';
  var rowData = "";
  if (numberOfTabs == 0) {
   data += $(divId_h).find('thead').html();
//start of row data	
   $(divId_h).find('tr').each(function (e) {
    rowData += "<tr>";
    $(this).find('td').each(function (f) {
     rowData += "<td>";
//	if (f > 0) {
     if ($(this).children().val()) {
      if ($(this).children().prop('type') === 'text') {
       rowData += ($(this).children().val());
      }
      if ($(this).children().prop('type') === 'select-one') {
       rowData += ($(this).children().children(":selected").text());
      }
     } else {
      rowData += ($(this).text());
     }
//	}
     rowData += "</td>";
    });
    rowData += "</tr>";
   });
  } else {
   data += '<tr>';
   $(divId_h).find('thead').each(function (a) {
    data += $(this).children().html();
   });
   data += '</tr>';
   //start of row data
   var arr = [];
   var i = 0;
   $(divId_h).find('tbody:first').find('tr').each(function (e) {
    arr[i++] = $(this).prop('class');
   });
   $(arr).each(function (index, value) {
    rowData += "<tr>";
    var trclass = '.' + value;
    $(divId_h).find(trclass).each(function (e) {
     $(this).find('td').each(function (f) {
      rowData += "<td>";
//	if (f > 0) {
      if ($(this).children().val()) {
       if ($(this).children().prop('type') === 'text') {
        rowData += ($(this).children().val());
       }
       if ($(this).children().prop('type') === 'select-one') {
        rowData += ($(this).children().children(":selected").text());
       }
      } else {
       rowData += '';
      }
//	}
      rowData += "</td>";
     });
    });
    rowData += "</tr>";
   });
  }
  data += rowData;
  data += '</table>';
 } else if (containerType == 'div') {
  var data = '<table>';
  $(divId_h).find('li').each(function () {
   if ($(this).find('label').text() !== '') {
    data += '<tr><td>';
    data += $(this).find('label').text();
    data += '</td><td>';
    if ($(this).find('input').prop('type') === 'text') {
     data += ($(this).find('input').val());
    } else if ($(this).find('input').prop('type') === 'number') {
     data += ($(this).find('input').val());
    } else if ($(this).find('select').val()) {
     data += ($(this).children().children(":selected").text());
    } else {
     data += ($(this).find('select').val());
    }
    data += '</td></tr>';
   }
  });
  data += '<table>';
 }
 window.open('data:application/vnd.ms-excel,' + encodeURIComponent(data));
};
/*------------------------------------End of Export to Excel & Sratt of Copy--------------------------------*/
//add new line
function add_new_rowMain(trClass, tbodyClass, noOfTabs, copyFirstLine,
        removeDefault, divClassNotToBeCopied, divClassToBeCopied, lineNumberIncrementValue, enableUpdate) {
 this.trClass = trClass;
 this.tbodyClass = tbodyClass;
 this.copyFirstLine = copyFirstLine;
 this.noOfTabs = noOfTabs;
 this.removeDefault = removeDefault;
 this.divClassNotToBeCopied = divClassNotToBeCopied;
 this.divClassToBeCopied = divClassToBeCopied;
 this.lineNumberIncrementValue = lineNumberIncrementValue;
 this.enableUpdate = enableUpdate;
}

var objectCount = 491;
add_new_rowMain.prototype.add_new_row = function (afterAddNewRow) {
 var tbodyClass = this.tbodyClass;
 var trClass = this.trClass;
 var divClassToBeCopied = this.divClassToBeCopied;
 var enableUpdate = this.enableUpdate;
 var lineNumberIncrementValue = this.lineNumberIncrementValue;
 var enableUpdate_c = '.' + enableUpdate;
 var divClassToBeCopied_c = '.' + this.divClassToBeCopied;
 trClass = trClass.replace(/tr\./g, '');
 trClass = trClass.replace(/0/g, '');
 trClass = trClass.replace(/-/g, '');
 tbodyClass = tbodyClass.replace(/tbody\./g, '');
 tbodyClass = '.' + tbodyClass;
 var highest_line_num = 1;
 var highest_seq_num = 1;
 $('.lines_number').each(function () {
  if (+$(this).val() > highest_line_num) {
   highest_line_num = +$(this).val();
  }
 });
 if ($(tbodyClass).find('.seq_number').last().val()) {
  highest_seq_num = $(tbodyClass).find('.seq_number').last().val();
 }
 var nextSeqNumber = (+highest_seq_num) + 1;

 if ($(lineNumberIncrementValue).length < 1) {
  lineNumberIncrementValue = 1;
 }
 var nextLineSeqNumber = (+highest_line_num + (+lineNumberIncrementValue));
 if (this.copyFirstLine) {
  var newtrClass = '.' + $("tr[class*='" + trClass + "']:first").first().prop('class');
 } else {
  var newtrClass = '.' + $("tr[class*='" + trClass + "']:last").first().prop('class');
 }

 if (this.noOfTabs > 1) {
  var startingTab = $("tr[class*='" + trClass + "']").first().closest('.tabContent').attr('id');
  var startingTabArray = startingTab.split('-');
  var startingTabNumber = startingTabArray[1];
  tabCount = 1;
  do {
   $("#tabsLine-" + startingTabNumber + " " + newtrClass).clone().attr("id", "new_object" + startingTabNumber + "_" + objectCount).attr("class", "new_object" + objectCount).appendTo($("#tabsLine-" + startingTabNumber + " " + tbodyClass));
   startingTabNumber++;
   tabCount++;
  } while (tabCount <= this.noOfTabs);
 } else {
  $(newtrClass).clone().attr("class", "new_object" + objectCount).appendTo($(tbodyClass));
 }

 $("tr.new_object" + objectCount).find('.' + this.divClassNotToBeCopied).each(function () {
  $(this).attr('value', '').prop('value', '').val('');
 });

 $("tr.new_object" + objectCount).find('.dont_copy_r').each(function () {
  $(this).attr('value', '').prop('value', '').val('');
 });

 if (this.removeDefault === true) {
  $("tr.new_object" + objectCount).find("td input[type=text],td input[type=number], td input[type=select]").not(divClassToBeCopied_c).each(function () {
   $(this).val('');
   $(this).attr('value', '');
   $(this).removeAttr('id, readonly', 'disabled');
   $(this).removeClass('readonly');
  });
  $("tr.new_object" + objectCount).find(".checkBox.dontCopy").not(divClassToBeCopied_c).each(function () {
   $(this).attr('checked', false);
  });
  $("tr.new_object" + objectCount).find("td.text_not_tobe_copied").each(function () {
   $(this).val('');
   $(this).attr('value', '');
  });
 }

 $("tr.new_object" + objectCount).find(enableUpdate_c).removeAttr("disabled", "readonly").removeClass('always_readonly readonly');
 $("tr.new_object" + objectCount).find(".class_detail_form").replaceWith("");
 $("tr.new_object" + objectCount).find(".seq_number").val(nextSeqNumber);
 $('.lines_number:last').val(nextLineSeqNumber);
 $(".new_object" + objectCount).find(".date").each(function () {
  $(this).attr("id", "date" + dateCount);
  $(this).removeClass('hasDatepicker');
  dateCount++;
 });
 if (typeof afterAddNewRow === 'function') {
  afterAddNewRow();
 }
 objectCount++;
};
/*------------------------------------End of copy row and start of conext menu----------------------------------*/
function copy_document(doc_header_id, doc_line_id, doc_detail_id) {
 var doc_header_id_h = '#' + doc_header_id;
 var doc_header_id_c = '.' + doc_header_id;
 var doc_line_id_c = '.' + doc_line_id;
 var doc_detail_id_d = '.' + doc_detail_id;
 $(doc_header_id_h).val('');
 $('.dont_copy, .dontCopy').val('');
 $('.primary_column2').val('');
 $(doc_header_id_c).val('');
 $(doc_line_id_c).val('');
 $(doc_detail_id_d).val('');
 $('#content').find(':input').each(function () {
  $(this).prop('readonly', false);
  $(this).prop('disabled', false);
 });
 localStorage.setItem("save_all_lines", 9);
}

function copy_header(doc_header_id) {
 var doc_header_id_h = '#' + doc_header_id;
 $(doc_header_id_h).val('');
 $('.dont_copy, dontCopy').val('');
 $('.primary_column2').val('');
 var trClass = '.' + $("#form_line tbody tr:first").prop('class');
 $("#form_line tbody tr:not(" + trClass + ")").remove();
 $("#form_line tbody tr").find(':input').each(function () {
  $(this).attr('value', '');
 });
 $('#content').find(':input').each(function () {
  $(this).prop('readonly', false);
  $(this).prop('disabled', false);
 });
}

//right click menu
function rightClickMenu(menuContent) {
 if (localStorage.getItem("disableContextMenu")) {
  return;
 }
 var menu = "<div id='right_click_menu'>" + menuContent + "</div>";
 $("#content").bind("contextmenu", function (event) {
  event.preventDefault();
  if ($("#right_click_menu")) {
   $("div#right_click_menu").remove();
  }
  $(menu).appendTo('body').css({top: event.pageY + "px", left: event.pageX + "px"});
 });
 $('body').bind("click", function (event) {
  $("div#right_click_menu").remove();
 });
}

//right click menu
function rightClickDocMenu(menuContent) {
 if (localStorage.getItem("disableContextMenu")) {
  return;
 }
 var menu = "<div id='right_click_doc_menu'>" + menuContent + "</div>";
 $('.right_click_doc_menu_field').bind("contextDocMenu", function (event) {
  event.preventDefault();
  if ($("#right_click_doc_menu")) {
   $("div#right_click_doc_menu").remove();
  }
  $(menu).appendTo('body').css({top: event.pageY + "px", left: event.pageX + "px"});
 });
 $('body').bind("click", function (event) {
  $("div#right_click_doc_menu").remove();
 });
}

function contextMenuMain(docHedaderId, docLineId, docDetailId, trClass, tbodyClass, noOfTabbs, btn1DivId, btn2DivId,
        btn2_1DivId, btn6DivId, btn7DivId, btn8DivId,
        btn9DivId, btn9_1DivId, btn9_2DivId, btn9_3DivId, btn10DivId, btn10_1DivId, btn11DivId,
        beforeCopy, afterCopy) {
 this.docHedaderId = docHedaderId;
 this.docLineId = docLineId;
 this.docDetailId = docDetailId;
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
 this.btn10_1DivId = btn10_1DivId;
 this.btn11DivId = btn11DivId;
 this.beforeCopy = beforeCopy;
 this.afterCopy = afterCopy;
}

contextMenuMain.prototype.contextMenu = function ()
{
 var docHedaderId = this.docHedaderId;
 var docLineId = this.docLineId;
 var docLineId_c = '.' + this.docLineId;
 var docDetailId = this.docDetailId;
 var docDetailId_c = '.' + this.docDetailId;
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
 var btn10_1DivId = this.btn10_1DivId;
 var btn11DivId = this.btn11DivId;
 var beforeCopy = this.beforeCopy;
 var afterCopy = this.afterCopy;
 var methods = {
  beforeCopyActions: function () {
   if (typeof beforeCopy === 'function') {
    var beforeResult = window[beforeCopy]();
    if (!beforeResult) {
     return;
    }
   }
  },
  afterCopyActions: function () {
   if (typeof afterCopy === 'function') {
    var afterResult = window[afterCopy]();
    if (!afterResult) {
     return;
    }
   }
  }
 };
// var menuContent = '<ul id="level1"> <li id="menu_button1" class="export_excel">Export Header</li> <li id="menu_button2" class="end_li_type export_excel">Export Line  <ul>   <li id="menu_button2_1" class="end_li_type export_excel">Second Line Form</li>  </ul></li> <li id="menu_button3" class="end_li_type print">Print Document</li> <li class="copy_doc"><span id="menu_button4"> Copy Header</span>  <ul>   <li class="copy_doc"><span id="menu_button4_1">Copy & Save Header</span></li>   <li class="copy_doc"><span id="menu_button4_2">Copy Document</span>    <ul>     <li><span id="menu_button4_2_1">Copy & Save Document</span></li>    </ul>   </li>   <li class="copy_doc"><span id="menu_button4_3">Copy Line</span>    <ul>     <li><span id="menu_button4_3_1">Copy First Line</span></li>    </ul>   </li>  </ul> </li> <li class="end_li_type copy_line"><span id="menu_button5">Select All Line</span>  <ul>   <li><span id="menu_button5_1">Un Select All</span></li>  </ul> </li> <li id="menu_button6" class="preference">Preferences</li><li id="menu_button7" class="help help">inoERP Help<ul><li id="menu_button2_1" class="end_li_type export_excel">Shortcut Keys</li>  </ul></li> <li id="menu_button8"  data-target="#document_history" data-toggle="modal"  class="doc_history">Document History</li> <li id="menu_button9" class="end_li_type custom_code">Custom Code  <ul>   <li id="menu_button9_1" class="end_li_type">Disable</li>   <li id="menu_button9_2" class="end_li_type">Enable</li>   <li id="menu_button9_3" class="end_li_type">View & Update</li>  </ul></li> <li class="end_li_type disable_menu"><span id="menu_button10">Disable Context Menu</span>  <ul>   <li><span id="menu_button10_1">Disable All</span></li>  </ul></li> <li id="menu_button11" class="about">About inoERP</li> </ul>';
 var menuContent = '<ul id="level1"><li id="menu_button1" class="export_excel"><i class="fa fa-file-excel-o"></i>Export Header</li><li id="menu_button2" class="end_li_type export_excel"><i class="fa fa-file-excel-o"></i>Export Line  <ul><li id="menu_button2_1" class="export_excel">Second Line Form</li>  </ul></li> <li id="menu_button3" class="end_li_type print"><i class="fa fa-print"></i>Print Document</li> <li class="copy_doc"><span id="menu_button4"><i class="fa fa-copy"></i>Copy Header</span>  <ul>   <li class="copy_doc"><span id="menu_button4_1">Copy & Save Header</span></li>   <li class="copy_doc"><span id="menu_button4_2">Copy Document</span>    <ul>     <li><span id="menu_button4_2_1">Copy & Save Document</span></li>    </ul>   </li>   <li class="copy_doc"><span id="menu_button4_3">Copy Line</span>    <ul>     <li><span id="menu_button4_3_1">Copy First Line</span></li>    </ul>   </li>  </ul> </li> <li class="end_li_type copy_line"><span id="menu_button5"><i class="fa fa-object-group"></i>Select All Line</span>  <ul>   <li><span id="menu_button5_1">Un Select All</span></li>  </ul> </li> <li id="menu_button6" class="preference"><i class="fa fa-gear"></i>Preferences</li><li id="menu_button7" class="help help"><i class="fa fa-support"></i>inoERP Help<ul><li id="menu_button7_1" class="shortcut_key_menu" data-target="#shortcut_keys_divId" data-toggle="modal">Shortcut Keys</li>  </ul></li> <li id="menu_button8"  data-target="#document_history" data-toggle="modal"  class="doc_history"><i class="fa fa-history"></i>Document History</li> <li id="menu_button9" class="end_li_type custom_code"><i class="fa fa-code"></i>Custom Code  <ul>   <li id="menu_button9_1" >Disable</li>   <li id="menu_button9_2">Enable</li>   <li id="menu_button9_3" >View & Update</li>  </ul></li> <li class="disable_menu"><span id="menu_button10"><i class="fa fa-toggle-off"></i>Disable Context Menu</span>  <ul>   <li><span id="menu_button10_1">Disable All</span></li>  </ul></li> <li id="menu_button11" class="about"><i class="fa fa-book"></i>About inoERP</li> </ul>';

 rightClickMenu(menuContent);
 $('body').off('click', '#menu_button1').on('click', '#menu_button1', function () {
  var classDnldExcel = new exportToExcelMain();
  classDnldExcel.containerType = 'div';
  classDnldExcel.divId = btn1DivId;
  classDnldExcel.exportToExcel();
 });
 $("body").off('click', '#menu_button2').on('click', '#menu_button2', function () {
  var classDnldExcel = new exportToExcelMain();
  classDnldExcel.containerType = 'table';
  classDnldExcel.divId = btn2DivId;
  classDnldExcel.numberOfTabs = 1;
  classDnldExcel.exportToExcel();
 });
 $("body").off('click', '#menu_button3').on('click', '#menu_button3', function () {
  window.print();
 });
 $("body").off('click', '#menu_button4').on('click', '#menu_button4', function () {
  methods.beforeCopyActions();
  copy_header(docHedaderId);
  methods.afterCopyActions();
 });
 $("body").off('click', '#menu_button4_1').on('click', '#menu_button4_1', function () {
  methods.beforeCopyActions();
  copy_header(docHedaderId);
  methods.afterCopyActions();
  $('#save').trigger('click');
 });
 $("body").off('click', '#menu_button4_2').on('click', '#menu_button4_2', function () {
  methods.beforeCopyActions();
  copy_document(docHedaderId, docLineId, docDetailId);
  methods.afterCopyActions();
 });
 $("body").off('click', '#menu_button4_2_1').on('click', '#menu_button4_2_1', function () {
  copy_document(docHedaderId, docLineId, docDetailId);
  $('#save').trigger('click');
 });
 $("body").off('click', '#menu_button4_3').on('click', '#menu_button4_3', function () {
  var addNewRow = new add_new_rowMain();
  addNewRow.trClass = trClass;
  addNewRow.tbodyClass = tbodyClass_c;
  addNewRow.noOfTabs = noOfTabbs;
  addNewRow.removeDefault = false;
  addNewRow.divClassNotToBeCopied = docLineId_c;
  addNewRow.add_new_row();
//	add_new_row_withDefault(trClass, tbodyClass_c, noOfTabbs, docLineId_c);
 });
 $('body').off('click', '#menu_button4_3_1').on('click', '#menu_button4_3_1', function () {
  var addNewRow1 = new add_new_rowMain();
  addNewRow1.trClass = trClass;
  addNewRow1.tbodyClass = tbodyClass_c;
  addNewRow1.noOfTabs = noOfTabbs;
  addNewRow1.copyFirstLine = true;
  addNewRow1.removeDefault = false;
  addNewRow1.divClassNotToBeCopied = docLineId_c;
  addNewRow1.add_new_row();
//	add_new_row_withDefault(trClass, tbodyClass_c, noOfTabbs, docLineId_c);
 });

 $('body').off('click', '#menu_button5').on('click', '#menu_button5', function () {
  $('#form_line').find('input[name="line_id_cb"]').prop('checked', true);
 });
 $('body').off('click', '#menu_button5_1').on('click', '#menu_button5_1', function () {
  $('#form_line').find('input[name="line_id_cb"]').prop('checked', false);
 });

 $('body').off('click', '#menu_button7').on('click', '#menu_button7', function () {
  void window.open('http://www.inoideas.org/help', '_blank');
 });

 $('body').off('click', '#menu_button11').on('click', '#menu_button11', function () {
  void window.open('http://www.inoideas.org', '_blank');
 });

 $('body').off('click', '#menu_button8').on('click', '#menu_button8', function () {
  $('#document_history').modal('toggle');
 });

 $('body').off('click', '#menu_button7_1').on('click', '#menu_button7_1', function () {
  $('#shortcut_keys_divId').modal('toggle');
 });

 $('body').off('click', '#menu_button10_1').on('click', '#menu_button10_1', function () {
  localStorage.setItem("disableContextMenu", true);
  $("#content").unbind("contextmenu");
 });

 $('body').on('click', '#menu_button10', function () {
  $("#content").unbind("contextmenu");
 });
};
/*--------------------------------------End of contect menu & start of autocomplte----------------------
 *  coa_id - primary_column,,,,
 *     */

function autoCompleteMain(json_url, field_name, primary_column1, primary_column2, select_class, min_length,
        extra_elements, options) {
 this.json_url = json_url;
 this.field_name = field_name;
 this.primary_column1 = primary_column1;
 this.primary_column2 = primary_column2;
 this.select_class = select_class;
 this.extra_elements = extra_elements;
 this.min_length = min_length;
 this.options = options;
}

autoCompleteMain.prototype.autoComplete = function ()
{
 var json_url = this.json_url;
 var field_name = this.field_name;
 var primary_column1 = this.primary_column1;
 var primary_column2 = this.primary_column2;
 var extra_elements = this.extra_elements;
 var options = this.options;
 if (this.select_class === 'undefined') {
  var select_class = 'select' + field_name;
 } else {
  var select_class = this.select_class;
 }
 var select_class_d = '.' + select_class;
 var min_length = this.min_length;
 $('#content').on("focus.nsAutoComplete", select_class_d, function (e) {
  e.preventDefault();
  if (!$(this).data("autocomplete")) {
   var auto_element = this;
   var primary_column1_h = '#' + primary_column1;
   if ($(primary_column1_h).val()) {
    var primary_column1_v = $(primary_column1_h).val();
   } else if ($(auto_element).closest("tr").attr('class')) {
    var trClass = '.' + $(auto_element).closest("tr").attr('class').replace(/\s+/g, '.');
    var primary_column1_d = '.' + primary_column1;
    var primary_column1_v = $('#form_line').find(trClass).find(primary_column1_d).val();
   }
   $(this).autocomplete({
    source: function (request, response) {
     $.ajax({
      url: json_url,
      dataType: "json",
      data: {
       action: 'search',
       field_name: field_name,
       primary_column1: primary_column1_v,
       primary_column2: primary_column2,
       term: request.term,
       options: options
      },
      success: function (data) {
       response(data);
      },
      error: function (request, errorType, errorMessage) {
       alert("Error : " + errorType + ' with message ' + errorMessage);
       $(this).autocomplete("close");
      }
     });
    },
    autoFocus: true,
    response: function (event, ui) {
     if (ui.content.length === 1)
     {
      $(this).val(ui.content[0].label);
      //if extra element
      if ((typeof extra_elements !== 'undefined') && (extra_elements.length > 0)) {
       var elemenType = $(this).parent().prop('tagName');
       $(extra_elements).each(function (i, v) {
        var selected_value = '';
        var v_d = '.' + v;
        for (key in ui.content[0]) {
         if (key == v) {
          selected_value = ui.content[0][ key ];
         }
        }
        if (elemenType === 'LI') {
         $(auto_element).closest("ul").find(v_d).val(selected_value);
         if (v_d.indexOf('_cb') > -1 && (selected_value == 1)) {
          $(auto_element).closest("ul").find(v_d).prop('checked', true);
         }
        } else if (elemenType === 'TD') {
         $(auto_element).closest("tr").find(v_d).val(selected_value);
         var trClass = '.' + $(auto_element).closest("tr").attr('class').replace(/\s+/g, '.');
         $('#form_line, #form_line2').find(trClass).find(v_d).val(selected_value);
         if (v_d.indexOf('_cb') > -1 && (selected_value == 1)) {
          $('#form_line, #form_line2').find(trClass).find(v_d).prop('checked', true);
         }
        }
       });
      }
      //close the auto complete
      $(this).autocomplete("close");
     } else if (ui.content.length === 0) {
      alert('No Data Found');
      $(this).attr('value', '');
      //if extra element
      if ((typeof extra_elements !== 'undefined') && (extra_elements.length > 0)) {
       var elemenType = $(this).parent().prop('tagName');
       $(extra_elements).each(function (i, v) {
        var v_d = '.' + v;
        if (elemenType === 'LI') {
         $(auto_element).closest("ul").find(v_d).val('');
        } else if (elemenType === 'TD') {
         $(auto_element).closest("tr").find(v_d).val('');
         var trClass = '.' + $(auto_element).closest("tr").attr('class').replace(/\s+/g, '.');
         $('#form_line, #form_line2').find(trClass).find(v_d).val('');
         if (v_d.indexOf('_cb') > -1) {
          $('#form_line, #form_line2').find(trClass).find(v_d).prop('checked', false);
         }
        }
       });
      }
      //close the auto complete
      $(this).autocomplete("close");
     }

    },
    //select
    select: function (event, ui) {
     $(this).val(ui.item.label);
     //if extra element
     if ((typeof extra_elements !== 'undefined') && (extra_elements.length > 0)) {
      var elemenType = $(this).parent().prop('tagName');
      $(extra_elements).each(function (i, v) {
       var selected_value = '';
       var v_d = '.' + v;
       $.each(ui, function (key2, value) {
        for (key2 in value) {
         if (key2 == v) {
          selected_value = value[ key2 ];
         }
        }
       });
       if (elemenType === 'LI') {
        $(auto_element).closest("ul").find(v_d).val(selected_value);
        if (v_d.indexOf('_cb') > -1 && (selected_value == 1)) {
         $(auto_element).closest("ul").find(v_d).prop('checked', true);
        }
       } else if (elemenType === 'TD') {
        var trClass = '.' + $(auto_element).closest("tr").attr('class').replace(/\s+/g, '.');
        $('#form_line, #form_line2').find(trClass).find(v_d).val(selected_value);
        if (v_d.indexOf('_cb') > -1 && (selected_value == 1)) {
         $('#form_line, #form_line2').find(trClass).find(v_d).prop('checked', true);
        }
       }
      });
     }

     //close the auto complete
     $(this).autocomplete("close");
    },
    minLength: min_length
   });
   $('#content').trigger('setInoVal');
  }
 });
};
//file upload
function fileUploadMain(json_url, module_name, document_type, class_name, upload_type, directory, display_type, description, extn_folder_id) {
 this.json_url = json_url;
 this.module_name = module_name;
 this.class_name = class_name;
 this.document_type = document_type;
 this.upload_type = upload_type;
 this.directory = directory;
 this.display_type = display_type;
 this.description = description;
 this.extn_folder_id = extn_folder_id;
}
fileUploadMain.prototype.fileUpload = function () {
 var json_url = this.json_url;
 var module_name = this.module_name;
 var class_name = this.class_name;
 var document_type = this.document_type;
 var upload_type = this.upload_type;
 var directory = this.directory;
 var display_type = this.display_type;
 var description = this.description;
 var extn_folder_id = this.extn_folder_id;
 $('body').on('click', '#attach_submit, #comment_attach_submit, .upload_file', function (e) {
  e.preventDefault();
  var this_e = $(this);
  var divId = '#' + $(this).prop('id');
  $('.show_loading_small').show();
  formData = new FormData();
  if ($(this).hasClass('upload_file')) {
   jQuery.each($(this).closest('ul').find('input')[0].files, function (i, file) {
    formData.append('attachments-' + i, file);
    display_type = $(this_e).closest('.show_attachment').find('.display_type').val();
   });
  } else if ($(this).hasClass('comment_attach_submit')) {
   jQuery.each($('#comment_attachments')[0].files, function (i, file) {
    formData.append('attachments-' + i, file);
   });
  } else {
   jQuery.each($('#attachments')[0].files, function (i, file) {
    formData.append('attachments-' + i, file);
   });
  }
  if ($(this_e).closest('.show_attachment').find('.description').val()) {
   description = $(this_e).closest('.show_attachment').find('.description').val();
  }
    if ($(this_e).closest('.show_attachment').find('.extn_folder_id').val()) {
   extn_folder_id = $(this_e).closest('.show_attachment').find('.extn_folder_id').val();
  }

  if ($('#upload_type').val()) {
   upload_type = $('#upload_type').val();
   class_name = $('.class_name').val();
  }

  if (module_name !== null) {
   formData.append('module_name', module_name);
  }
  if (class_name !== null) {
   formData.append('class_name', class_name);
  }
  if (document_type !== null) {
   formData.append('document_type', document_type);
  }
  if (upload_type !== null) {
   formData.append('upload_type', upload_type);
  }
  if (document_type !== null) {
   formData.append('directory', directory);
  }

  if (display_type !== null) {
   formData.append('display_type', display_type);
  }
  
    if (description !== null) {
   formData.append('description', description);
  }
  
      if (extn_folder_id !== null) {
   formData.append('extn_folder_id', extn_folder_id);
  }
  
  
  
  return $.ajax({
   url: json_url,
   data: formData,
   processData: false,
   contentType: false,
   type: 'post'
  }).done(function (result) {
   var div = $(result).filter('div#uploaded_files').html();
   var message = '';
   $(result).find('.rollback_msg').each(function () {
    message += $(this).html();
   });
   $(result).find('.message').each(function () {
    message += $(this).html();
   });
   $(divId).closest('#file_upload_form').find(".uploaded_file_details").append(result);
   if (message) {
    $('#uploaded_file_details').append(message);
   }
   if (this_e.hasClass('upload_file')) {
    var file_id = +($(result).find('.file_id_values').val().trim());
    $(this_e).closest('.show_attachment').find('.uploaded_file_details').append(result);
    $(this_e).closest('.show_attachment').find('.file_id').val(file_id);
   }
   $('ul.ready-to-upload').remove();
   $('.show_loading_small').hide();
   alert('Upload Completed\nCheck output/errors section for details');
  }).fail(function (error, textStatus, xhr) {
   alert("save failed \n" + error + textStatus + xhr);
   $('ul.ready-to-upload').remove();
   $('.show_loading_small').hide();
  });
 });
};
/*-----------------Completion of file upload and start of mandatory field check--------------------------------*/
function mandatoryFieldMain(form_area, mandatory_fields, mandatory_messages, header_id) {
 this.form_area = form_area;
 this.mandatory_fields = mandatory_fields;
 this.mandatory_messages = mandatory_messages;
 this.header_id = header_id;
}

mandatoryFieldMain.prototype.mandatoryHeader = function ()
{
 $('body').off("click", '#form_line, #form_line2').on("click", '#form_line, #form_line2', function () {
  var header_id = $('ul#js_saving_data').find('.primary_column_id').data('primary_column_id');
  var no_headerid_check = $('ul#js_saving_data').find('.no_headerid_check').data('no_headerid_check');
  var lineClassName = $('ul#js_saving_data').find('.lineClassName').data('lineclassname');
  if (no_headerid_check == 9) {
   return;
  }
  if (!lineClassName || lineClassName == 'undefined') {
   return;
  }
  if (header_id) {
   var header_id_h = '#' + header_id;
   var header_id_c = '.' + header_id;
   if (!$(header_id_h).val()) {
    if (move_line_wo_header == 'SAVE_HEADER') {
     $('#save').trigger('click');
    } else if (move_line_wo_header == 'SHOW_WARNING') {
     if (confirm('Header data is not saved : Do you want to save the header')) {
      $('#save').trigger('click');
     }
    }

   } else {
    var headerIdVal = $(header_id_h).val();
    if (!$(this).find(header_id_c).val()) {
     $(this).find(header_id_c).val(headerIdVal);
    }
   }
  }

 });
};
mandatoryFieldMain.prototype.mandatoryField = function ()
{
 return true;
 var form_area = this.form_area;
 var form_area_h = '#' + form_area;
 var mandatory_fields = this.mandatory_fields;
 var mandatory_messages = this.mandatory_messages;
 var numberOfEnteredFields = 0;
 var fieldId = '#' + mandatory_fields[0];
 var msg = mandatory_messages[0];
 $('body').off("focusout", fieldId).on("focusout", fieldId, function () {
  if (!$(fieldId).val()) {
   alert(msg);
   $(fieldId).focus();
  } else {
   if (mandatory_fields.length > 2) {
    mandatory_fields.shift();
    mandatory_messages.shift();
    var mandatoryCheck = new mandatoryFieldMain();
    mandatoryCheck.form_area = 'form_header';
//	  mandatoryCheck.mandatory_fields = $(mandatory_fields).slice(1);
//		mandatoryCheck.mandatory_messages = $(mandatory_messages).slice(1);
    mandatoryCheck.mandatory_fields = mandatory_fields;
    mandatoryCheck.mandatory_messages = mandatory_messages;
    mandatoryCheck.mandatoryField();
   }
  }
 });
 $(form_area_h + " :input").not(fieldId).off('focusin').on("focusin", function () {
  if (!$(fieldId).val()) {
   $(this).prop('value', '');
   alert(msg);
   $(this).focusout(function () {
    return;
   });
  } else {
   $(mandatory_fields).each(function (i, v) {
    var entered_fields = '#' + v;
    if ($(entered_fields).val()) {
     numberOfEnteredFields++;
     if (mandatory_fields.length === numberOfEnteredFields) {
      return;
     }
    }
   });
   if (numberOfEnteredFields < mandatory_fields.length) {
    var mandatoryCheck = new mandatoryFieldMain();
    mandatoryCheck.form_area = 'form_header';
    mandatoryCheck.mandatory_fields = $(mandatory_fields).slice(numberOfEnteredFields);
    mandatoryCheck.mandatory_messages = $(mandatory_messages).slice(numberOfEnteredFields);
    if (($(this).prop('id') !== mandatoryCheck.mandatory_fields[0]) && (
            fieldId !== mandatoryCheck.mandatory_fields[0])) {
//		alert('3' + $(this).prop('id')+ ' : '+ fieldId + ' : '+ mandatoryCheck.mandatory_fields[0] +mandatoryCheck.mandatory_messages[0]); 
    }
    mandatoryCheck.mandatoryField();
   }
  }
 });
};

function lotSerial_quantityValidation(options) {
 var defaults = {
  quantity_divClass: '.transaction_quantity'
 };

 var settings = $.extend({}, defaults, options);
 var retValue = 1;
 $('.add_detail_values1').each(function () {
  if ($(this).children('.serial_generation').val()) {
   var trClass = '.' + $(this).closest("tr").prop('class').replace(/\s+/g, '.');
   var qty = +$('#content').find(trClass).find(settings.quantity_divClass).val();
   var noOfSerialIds = 0;
   $(this).closest('td').find('.inv_serial_number_id').each(function () {
    if ($(this).val()) {
     noOfSerialIds++;
    }
   })

   if (noOfSerialIds != qty) {
    var noOfSerials = 0;
    $(this).closest('td').find('.serial_number').each(function () {
     if ($(this).val()) {
      noOfSerials++;
     }
    })
    if (noOfSerials != qty) {
     alert('Can\'t save data as no of serial numbers doesnt match quantity \nNo of serial numbers entered : ' + noOfSerials + '\nNo of units :' + qty);
     retValue = -10;
     return false;
    }
   }
  }

 });

 $('.add_detail_values0').each(function () {
  if ($(this).children('.lot_generation').val()) {
   var trClass = '.' + $(this).closest("tr").prop('class').replace(/\s+/g, '.');
   var qty = +$('#content').find(trClass).find(settings.quantity_divClass).val();
   var lot_quantity = 0;
   $(this).closest('tr').find('.lot_quantity').each(function () {
    lot_quantity += $(this).val();
   });
   if (lot_quantity != qty) {
    alert('Can\'t save data as no of lot quantities doesnt match line quantity');
    retValue = -10;
    return false;
   }

  }
 });

 return retValue;
}