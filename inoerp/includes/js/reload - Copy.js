$(document).ready(function() {
 var homeUrl = $('#home_url').val();
 $('.non_clickable').on('click', function(e) {
  e.preventDefault();
 })
 $('#loading').hide();
 $('.show_loading_small').hide();
 
 //show & remove select search icon
 $('.select_popup').hide();
 $('#content').on('focusin', 'input', function() {
  $('#content').find('.select_popup').hide();
  $(this).parent().find('.select_popup').show();
//  if(!$(this).prop('readonly')){
//  $(this).parent().find('.select_popup').show();
// }
 })

 if ($('#display_comment_form').length > 0) {
  $('#display_comment_form').html($('#commentForm_witoutjs').html());
  $('#commentForm_witoutjs').html('');
 }
// drag_drop_urgent_card();
// saveUrgentCards();


 $('body').on('click', '.content_per_page', function(e) {
  var currentUrl = window.location.toString();
  var newURL = currentUrl.replace(/per_page=/g, '');
  newURL = newURL.replace(/&&/g, '&');
  if (newURL.indexOf('?') > -1) {
   newURL = newURL + '&per_page=' + $(this).closest('div').find('select').val();
  } else {
   newURL = newURL + '?per_page=' + $(this).closest('div').find('select').val();
  }
  $(this).attr('href', newURL);
 });

//enable lines with change data for save
 $('#content').data('last', '').on("blur", ':input', function() {
  var last = $(this).data('last');
  var current = $(this).val();
  if (current !== '' && current !== last) {
   var trClass = '.' + $(this).closest('tr').prop('class');
   $('#content').find(trClass).find('input[name="line_id_cb"],input[name="detail_id_cb"]').prop('checked', true);
   $('#content').find('input[name="detail_id_cb"]:checked').each(function() {
    $(this).closest('td.add_detail_values').closest('tr').find('input[name="line_id_cb"]').prop('checked', true);
   })
  }
 });

//hiding the loader
 var $loader = $('#loading'), timer;
 $loader.hide().ajaxStart(function()
 {
  timer && clearTimeout(timer);
  timer = setTimeout(function()
  {
   $loader.show();
  },
   10000);
 }).ajaxStop(function()
 {
  clearTimeout(timer);
  $loader.hide();
 });

//select page data selction in parent window
// $(".quick_select").click(function() {
//  var setData = new opener.setValFromSelectPage;
//  $(this).closest('tr').find('td').each(function() {
//   setData[$(this).prop('class')] = $(this).text();
//  });
//  setData.setVal();
//  localStorage.removeItem("field_class");
//  localStorage.removeItem("reset_link");
//  window.close();
// });

 //search reset button
 var link = localStorage.getItem("reset_link");
 if (link) {
  $('#multi_select a#search_reset_btn').on('click', function() {
   $(this).attr('href', link);
  });
 }

 var reset_link_ofSelect = localStorage.getItem("reset_link_ofSelect");
 if (reset_link_ofSelect) {
  $('#select_page a#search_reset_btn').on('click', function() {
   $(this).attr('href', reset_link_ofSelect);
  });
 }

 //new object
 $('#new_object_button').on('click', function(e) {
  e.preventDefault();
  $('#content').find(':input').val('');
  $('#content').find(':checkbox').prop('checked', false);
 })

 remove_row();

 //Coa auto complete
 var coaCombination = new autoCompleteMain();
// var coa_id = $('#coa_id').val();
 coaCombination.json_url = 'modules/gl/coa_combination/coa_search.php';
 coaCombination.primary_column1 = 'coa_id';
 coaCombination.select_class = 'select_account';
 coaCombination.min_length = 4;
 coaCombination.autoComplete();

 var supplierName = new autoCompleteMain();
 supplierName.json_url = 'modules/ap/supplier/json_supplier.php';
 supplierName.primary_column1 = 'bu_org_id';
 supplierName.select_class = 'select_supplier_name';
 supplierName.extra_elements = ['supplier_id', 'supplier_number'];
 supplierName.min_length = 3;
 supplierName.autoComplete();

 var customerName = new autoCompleteMain();
 customerName.json_url = 'modules/ar/customer/json_customer.php';
 customerName.primary_column1 = 'bu_org_id';
 customerName.select_class = 'select_customer_name';
 customerName.extra_elements = ['ar_customer_id', 'customer_number'];
 customerName.min_length = 3;
 customerName.autoComplete();


 var itemNumber = new autoCompleteMain();
 itemNumber.json_url = 'modules/inv/item/item_search.php';
 itemNumber.select_class = 'select_item_number';
 itemNumber.primary_column1 = 'org_id';
 itemNumber.extra_elements = ['item_id', 'item_id_m', 'item_description', 'uom_id', 'processing_lt', 'lot_generation', 'serial_generation'];
 itemNumber.min_length = 2;
 itemNumber.autoComplete();

 //auto complete for allowed BOM
 var itemNumber = new autoCompleteMain();
 itemNumber.json_url = 'modules/inv/item/item_search.php';
 itemNumber.select_class = 'select_item_number_allowedBOM';
 itemNumber.primary_column1 = 'org_id';
 itemNumber.extra_elements = ['item_id', 'item_id_m', 'item_description', 'uom_id', 'processing_lt', 'lot_generation', 'serial_generation'];
 itemNumber.min_length = 2;
 itemNumber.options = {bom_enabled_cb: "1"};
 itemNumber.autoComplete();

 $('#form_line').on('blur', '.textfield.select_item_number', function() {
  var elemenType = $(this).parent().prop('tagName');
  if (elemenType === 'TD') {
   var trClass = '.' + $(this).closest("tr").attr('class').replace(/\s+/g, '.');
   if ($('#form_line').find(trClass).find('.serial_generation').val()) {
    $('#form_line').find(trClass).find('.serial_number').attr('required', true).css('background-color', 'pink');
   }
   if ($('#form_line').find(trClass).find('.lot_generation').val()) {
    $('#form_line').find(trClass).find('.lot_number').attr('required', true).css('background-color', 'pink');
   }
  }
 });



 //popu for selecting accounts
 $('#content').on('click', '.account_popup', function() {
  if ($(this).closest('td').find('input').hasClass('select_account')) {
   var rowClass = $(this).closest('tr').prop('class');
   var fieldClass = $(this).closest('td').find('.select_account').prop('class');
   localStorage.setItem("row_class", rowClass);
  } else {
   var fieldClass = $(this).closest('li').find('.select_account').prop('class');
  }
  localStorage.setItem("field_class", fieldClass);
  void window.open('select.php?class_name=coa_combination', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //popu for selecting items
 $('#content').on('click', '.select_item_number.select_popup', function() {

  var elemenType = $(this).parent().prop('tagName');
  if (elemenType === 'TD') {
   var rowClass = $(this).closest('tr').prop('class');
   var fieldClass = $(this).closest('td').find('.select_item_number').prop('class');
   localStorage.setItem("row_class", rowClass);
   localStorage.setItem("field_class", fieldClass);
  } else {
   var liId = $(this).closest('li').find('.item_number').prop('id');
   localStorage.setItem("li_divId", liId);
  }
  var openUrl = 'select.php?class_name=item';
  if ($(this).siblings('.org_id').val()) {
   openUrl += '&org_id=' + $(this).siblings('.org_id').val();
  } else if ($('#org_id').val()) {
   openUrl += '&org_id=%3D' + $('#org_id').val();
  }

  if ($(this).siblings('.item_number').val()) {
   openUrl += '&item_number=' + $(this).siblings('.item_number').val();
  }
  void window.open(openUrl, '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 $('#content').on('click', '.select_item_number_only.select_popup', function() {
  var rowClass = $(this).closest('tr').prop('class');
  var fieldClass = $(this).closest('td').find('.select_item_number').prop('class');
  localStorage.setItem("row_class", rowClass);
  localStorage.setItem("field_class", fieldClass);
  var openUrl = 'select.php?class_name=item_select';
  if ($(this).siblings('.item_number').val()) {
   openUrl += '&item_number=' + $(this).siblings('.item_number').val();
  }
  void window.open(openUrl, '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //toggle sereah form
// $('#searchForm').on('dblclick', function() {
//	$(this).find('.search_form').toggle();
// });
 //add new columns
 $('#content').on('change', '.new_column:first', function() {
  if ($(this).val()) {
   $(this).clone().insertBefore($(this));
  }
 });
 //add new order by
 $('#content').on('change', '.search_order_by', function() {
  if ($(this).val() !== 'remove') {
   $(this).closest('li').clone().insertAfter($(this).closest('li'));
  } else {
   $(this).closest('li').remove();
  }
 });

 $('#searchForm').on('change', '.new_search_criteria', function() {
  if ($(this).val()) {
   var newSearchCriteria = $(this).val();
   var newSearchCriteriaName = newSearchCriteria + '[]';
   var elementToBeCloned = $('.text_search').first().closest('li');
   var elementClass = $('.text_search').first().prop('class');
   var elementName = $('.text_search').first().prop('name');
   var elementLabelClass = '.label_' + elementName;
   elementLabelClass = elementLabelClass.replace('[', '');
   elementLabelClass = elementLabelClass.replace(']', '');
   clonedElement = elementToBeCloned.clone();
   $('label[for="' + elementName + '"]').text(newSearchCriteria);
   clonedElement.children().removeClass(elementClass);
   clonedElement.children().addClass(newSearchCriteria);
   clonedElement.children().prop('name', newSearchCriteriaName);
   clonedElement.find("input").each(function() {
    $(this).val("");
   });
//	 clonedElement.appendTo($(this).closest("ul"));
   clonedElement.insertBefore($(this).closest("li"));
   $(elementLabelClass + ':last').text(newSearchCriteria);
  }
 });


 //toggle detail lines
 $(".form_detail_data_fs").hide();
 $(".error").dblclick(function() {
  $(this).html("");
 });
 //export to excel from search result
 $("#content").on('click', '#export_excel_searchResult', function(e) {
  window.open('data:application/vnd.ms-excel,' + encodeURIComponent($('#search_result').html()));
  e.preventDefault();
 });
//remove row
 remove_row();

 //remove attached files
 $('#content').on('click', '.remove_file', function() {
  $(this).closest('ul').remove();
 });


 //date picker
// $('body').on('focus', ".date", function() {
//  var currentDate = new Date();
//  $(this).datepicker({
//   defaultDate: 0,
//   changeMonth: true,
//   changeYear: true,
//   dateFormat: "yy-mm-dd",
//   setDate: currentDate
//  });
// });

 $('body').on('focus', ".dateTime", function() {
  var currentDate = new Date();
  var timeStamp = currentDate.getHours() + ':' + currentDate.getMinutes() + ':' + currentDate.getSeconds();
  $(this).datepicker({
   defaultDate: currentDate,
   changeMonth: true,
   changeYear: true,
   dateFormat: "yy-mm-dd " + timeStamp,
   setDate: currentDate
  });
 });


 $('body').on('focus', ".anyDate", function() {
  if ($(this).hasClass('readonly')) {
   $(this).prop('disabled', true);
   alert('readonly field');
  } else {
   var currentDate = new Date();
   $(this).datepicker({
    defaultDate: 0,
    changeMonth: true,
    changeYear: true,
    dateFormat: "yy-mm-dd",
    setDate: currentDate
   });
  }

 });


 $('body').on('focus', ".dateFromToday", function() {
  if ($(this).hasClass('readonly')) {
   $(this).prop('disabled', true);
   alert('readonly field');
  } else {
   var currentDate = new Date();
   $(this).datepicker({
    defaultDate: 0,
    minDate: 0,
    changeMonth: true,
    changeYear: true,
    dateFormat: "yy-mm-dd",
    setDate: currentDate
   });
  }
 });

 $('body').on('focus', ".MondayFromToday", function() {
  if ($(this).hasClass('readonly')) {
   $(this).prop('disabled', true);
   alert('readonly field');
  } else {
   var currentDate = new Date();
   $(this).datepicker({
    defaultDate: 0,
    minDate: 0,
    changeMonth: true,
    changeYear: true,
    dateFormat: "yy-mm-dd",
    setDate: currentDate,
    beforeShowDay: function(date) {
     var day = date.getDay();
     return [day == 1, ""];
    }
   });
  }
 });


 var today_date = new Date();
 var formatted_date = today_date.getFullYear() + '-' + (today_date.getMonth() + 1) + '-' + today_date.getDate();
 $(".default_date").val(formatted_date);

 //dont allow past dates if manually entered
 $('body').on('change', '.dateFromToday', function() {
  var toDay = new Date();
  var enteredDate = $(this).datepicker("getDate");
  var diff = enteredDate - toDay;
  if ((enteredDate) && (diff < -86400000)) {
   $(this).val('');
   $(this).focus();
   alert("Past date is not allowed");
  }
 });
 //creating tabs
// $("#tabs").tabs();
 //creating tabs
 $(function() {
  var tabs = $("#tabsHeader").tabs();
  var tabs = $("#tabsLine").tabs();
  tabs.find(".ui-tabs-nav").sortable({
   axis: "x",
   stop: function() {
    tabs.tabs("refresh");
   }
  });
 });
 $("#tabsVertical").tabs().addClass("ui-tabs-vertical ui-helper-clearfix");
 $("#tabsVertical li").removeClass("ui-corner-top").addClass("ui-corner-left");
// $("#tabsLine").tabs();
 $("#tabsDetail, #tabsDetailA ,#tabsDetailB, #tabsDetailC, #tabsDetailD").tabs();
 $(".tabsDetail, .tabsDetailA , .tabsDetailB, .tabsDetailC, .tabsDetailD").tabs();

//Refresh the page
 $("#refresh_button").on("click", function() {
  location.reload(true);
  localStorage.removeItem("disableContextMenu");
 });
//setConetntRightLeft();

 tinymce.init({
  selector: '.mediumtext',
  mode: "exact",
//    theme: "modern",
  plugins: 'textcolor link image lists code table emoticons',
  width: 680,
  height: 70,
  toolbar: "styleselect code | emoticons forecolor backcolor bold italic pagebreak | alignleft aligncenter alignright | bullist numlist outdent indent | link image inserttable ",
  menubar: false,
  statusbar: false,
  file_browser_callback: function() {
   $('#attachment_button').click();
  }
 });

 tinymce.init({
  selector: '.bigtext',
  mode: "exact",
//    theme: "modern",
  plugins: 'textcolor link image lists code table emoticons',
  width: 700,
  height: 250,
  toolbar: "styleselect code | emoticons forecolor backcolor bold italic pagebreak | alignleft aligncenter alignright | bullist numlist outdent indent | link image inserttable ",
  menubar: false,
  statusbar: false,
  file_browser_callback: function() {
   $('#attachment_button').click();
  }
 });
 //include tinymce for all text areas
 tinymce.init({
//  selector:'textarea',
  mode: "exact",
  theme: "modern",
  width: 200,
  height: 30,
  toolbar: false,
  menubar: "format edit",
  statusbar: false
 });

 //Popup for selecting address
 $(".address_id.select_popup").click(function(e) {
  e.preventDefault();
  var rowClass = $(this).parent().find('input').first().prop('class');
  localStorage.setItem("field_class", rowClass);
  void window.open('select.php?class_name=address', '_blank',
   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 });

//diable/enable auto complete
 $('#content').on('click', '.disable_autocomplete', function() {
  $(this).parent().siblings().each(function() {
   $(this).autocomplete({
    disabled: true
   });
  });
 });

 $('#content').on('dblclick', ':input', function() {
  if ($(this).hasClass('ui-autocomplete-input')) {
   $(this).autocomplete({
    disabled: false
   });
  }
 });


 //basic finction --making background colors for form fields
 $("[required]").addClass('required');
 $("[readonly]").addClass('readonly');
 //Popup for print
 $(".print").click(function() {
  window.print();
 });
 //all download
 $('#export_excel_allResult').on('click', function() {
  $('#download_all').submit();
 });

 animateCycle();
 $('#all_contents').on('click', '.start_play', function() {
  animateCycle();
 });

 $('#all_contents').on('focusIn', '#animated_block', function() {
  clearInterval(interval);
 });

 $('#all_contents').on('focusOut', '#animated_block', function() {
  animateCycle();
 });

//tree view
 treeView();

 $("#search_message").dialog({
  autoOpen: false,
  dialogClass: "no-close",
  modal: true,
  minWidth: 600,
  title: "Searching Tips",
  show: {
   effect: "blind",
   duration: 1000
  },
  hide: {
   effect: "explode",
   duration: 1000
  },
  buttons: [
   {
    text: "OK",
    click: function() {
     $(this).dialog("close");
    }
   }
  ],
  closeOnEscape: true,
  position: {my: "left top", at: "left top", of: "#structure "}
 });

 $("#search_tip").click(function() {
  $("#search_message").dialog("open");
 });

//save data
 if ($('ul#js_saving_data').length > 0) {
  var classSave = new saveMainClass();
  var headerClassName = $('ul#js_saving_data').find('.headerClassName').data('headerclassname');
  var lineClassName = $('ul#js_saving_data').find('.lineClassName').data('lineclassname');
  var lineClassName2 = $('ul#js_saving_data').find('.lineClassName2').data('lineclassname2');
  var detailClassName = $('ul#js_saving_data').find('.detailClassName').data('detailclassname');
  var form_header_id = $('ul#js_saving_data').find('.form_header_id').data('form_header_id');
  var form_line_id = $('ul#js_saving_data').find('.form_line_id').data('form_line_id');
  var primary_column_id = $('ul#js_saving_data').find('.primary_column_id').data('primary_column_id');
  var primary_column_id2 = $('ul#js_saving_data').find('.primary_column_id2').data('primary_column_id2');
  var line_key_field = $('ul#js_saving_data').find('.line_key_field').data('line_key_field');
  var savingOnlyHeader = $('ul#js_saving_data').find('.savingOnlyHeader').data('savingonlyheader');
  var onlyOneLineAtATime = $('ul#js_saving_data').find('.onlyOneLineAtATime').data('onlyonelineatatime');
  var allLineTogether = $('ul#js_saving_data').find('.allLineTogether').data('alllinetogether');
  var single_line = $('ul#js_saving_data').find('.single_line').data('single_line');
  var before_save_function = $('ul#js_saving_data').find('.before_save_function').data('before_save_function');
  if (!before_save_function) {
   window.beforeSave = function() {
    return false;
   }
  }

  classSave.enable_select = true;
  classSave.json_url = 'form.php?class_name=' + headerClassName;
  classSave.form_header_id = form_header_id;
  classSave.form_line_id = (typeof form_line_id !== 'undefined') ? form_line_id : 'form_line';
  classSave.line_key_field = (typeof line_key_field !== 'undefined') ? line_key_field : null;
  classSave.primary_column_id = primary_column_id;
  classSave.primary_column_id2 = primary_column_id2;
  classSave.savingOnlyHeader = (savingOnlyHeader == true) ? true : false;
  classSave.allLineTogether = (allLineTogether == true) ? true : false;
  classSave.onlyOneLineAtATime = (onlyOneLineAtATime == true) ? true : false;
  classSave.single_line = (single_line == true) ? true : false;
  if (single_line == true) {
   var primary_column_id_h = '#' + primary_column_id;
   if (!$(primary_column_id_h).val()) {
    classSave.savingOnlyHeader = true;
   } else {
    classSave.savingOnlyHeader = false;
   }
  }
  classSave.headerClassName = headerClassName;
  classSave.lineClassName = (typeof lineClassName !== 'undefined') ? lineClassName : null;
  classSave.lineClassName2 = (typeof lineClassName2 !== 'undefined') ? lineClassName2 : null;
  classSave.detailClassName = (typeof detailClassName !== 'undefined') ? detailClassName : null;
  classSave.saveMain(before_save_function);
 }

//context menu
 if ($('ul#js_contextMenu_data').length > 0) {
  var classContextMenu = new contextMenuMain();
  var docHedaderId = $('ul#js_contextMenu_data').find('.docHedaderId').data('dochedaderid');
  var docLineId = $('ul#js_contextMenu_data').find('.docLineId').data('doclineid');
  var docDetailId = $('ul#js_contextMenu_data').find('.docDetailId').data('docdetailid');
  var btn1DivId = $('ul#js_contextMenu_data').find('.btn1DivId').data('btn1divid');
  var btn2DivId = $('ul#js_contextMenu_data').find('.btn2DivId').data('btn2divid');
  var trClass = $('ul#js_contextMenu_data').find('.trClass').data('trclass');
  var tbodyClass = $('ul#js_contextMenu_data').find('.tbodyClass').data('tbodyclass');
  var noOfTabbs = $('ul#js_contextMenu_data').find('.noOfTabbs').data('nooftabbs');

  classContextMenu.docHedaderId = (typeof docHedaderId !== 'undefined') ? docHedaderId : null;
  classContextMenu.docLineId = (typeof docLineId !== 'undefined') ? docLineId : null;
  classContextMenu.docDetailId = (typeof docDetailId !== 'undefined') ? docDetailId : null;
  classContextMenu.btn1DivId = (typeof btn1DivId !== 'undefined') ? btn1DivId : null;
  classContextMenu.btn2DivId = (typeof btn2DivId !== 'undefined') ? btn2DivId : 'form_line';
  classContextMenu.trClass = (typeof trClass !== 'undefined') ? trClass : null;
  classContextMenu.tbodyClass = (typeof tbodyClass !== 'undefined') ? tbodyClass : null;
  classContextMenu.noOfTabbs = (typeof noOfTabbs !== 'undefined') ? noOfTabbs : null;
  classContextMenu.contextMenu();
  
    $("#form_line").on("click", ".add_row_img", function () {
   var addNewRow = new add_new_rowMain();
   addNewRow.trClass = lineClassName;
   addNewRow.tbodyClass = 'form_data_line_tbody';
   addNewRow.noOfTabs = noOfTabbs;
   addNewRow.removeDefault = true;
   addNewRow.add_new_row();
   $(".tabsDetail").tabs();
  });
  
//   addOrShow_lineDetails();
//  onClick_addDetailLine(noOfTabbs);
  
 }

 //FILE attachment

 var fu = new fileUploadMain();
 fu.json_url = homeUrl + 'extensions/file/upload.php';
 fu.fileUpload();

//selecting customer
// $(".ar_customer_id.select_popup").on("click", function() {
//  localStorage.idValue = "";
//  void window.open('select.php?class_name=ar_customer', '_blank',
//   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
// });
//
////selecting supplier
// $(".supplier_id.select_popup").on("click", function() {
//  localStorage.idValue = "";
//  void window.open('select.php?class_name=supplier', '_blank',
//   'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
// });

// onClick_addDetailLine(2, '.add_row_detail_img3', 'tabsDetailC');
 $('#content').on('change', '.sys_extra_field_id', function() {
  var field_type = $(this).find('option:selected').data('field_type');
  $(this).closest('tr').find('.field_type').val(field_type);
 });
$('table.view th').find('img').hide();

// $('#search_page').on('click', '#search_submit_btn', function (e) {
//  e.preventDefault();
//  $('.hideDiv_input').trigger('click');
//  getSearchResult();
// });
//
// $('#search_page').on('click', '.page_nos a', function (e) {
//  e.preventDefault();
//  $('.hideDiv_input').trigger('click');
//  var page_no = getUrlValues('pageno', $(this).prop('href'));
//  var per_page = getUrlValues('per_page', $(this).prop('href'));
//  getSearchResult({
//   pageno: page_no,
//   per_page: per_page
//  });
// });
//
// $('#search_page').on('click', 'a.content_per_page', function (e) {
//  e.preventDefault();
//  $('.hideDiv_input').trigger('click');
//  var per_page = $(this).closest('.noOfcontents').find('.per_page').val();
//  getSearchResult({
//   per_page: per_page
//  });
// });
// 
//   $('#multi_select').on('click', '#search_submit_btn', function (e) {
//  e.preventDefault();
//  $('.hideDiv_input').trigger('click');
//  getMultiSelectResult();
// });
//
// $('#multi_select').on('click', '.page_nos a', function (e) {
//  e.preventDefault();
//  $('.hideDiv_input').trigger('click');
//  var page_no = getUrlValues('pageno', $(this).prop('href'));
//  var per_page = getUrlValues('per_page', $(this).prop('href'));
//  getMultiSelectResult({
//   pageno: page_no,
//   per_page: per_page
//  });
// });
//
// $('#multi_select').on('click', 'a.content_per_page', function (e) {
//  e.preventDefault();
//  $('.hideDiv_input').trigger('click');
//  var per_page = $(this).closest('.noOfcontents').find('.per_page').val();
//  getMultiSelectResult({
//   per_page: per_page
//  });
// });

});