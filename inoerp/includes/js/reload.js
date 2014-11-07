$(document).ready(function() {
 $('.non_clickable').on('click', function(e) {
	e.preventDefault();
 })
 $('#loading').hide();
 $('.show_loading_small').hide();

// localStorage.removeItem("jsfile");
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
 $(".quick_select").click(function() {
	var setData = new opener.setValFromSelectPage;
	$(this).closest('tr').find('td').each(function() {
	 setData[$(this).prop('class')] = $(this).text();
	});
	setData.setVal();
	localStorage.removeItem("field_class");
	localStorage.removeItem("reset_link");
	window.close();
 });

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
 itemNumber.extra_elements = ['item_id', 'item_description', 'uom_id', 'processing_lt'];
 itemNumber.min_length = 2;
 itemNumber.autoComplete();

 //popu for selecting accounts
 $('#content').on('click', '.account_popup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	var fieldClass = $(this).closest('td').find('.select_account').prop('class');
	localStorage.setItem("row_class", rowClass);
	localStorage.setItem("field_class", fieldClass);
	void window.open('select.php?class_name=coa_combination', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //popu for selecting items
 $('#content').on('click', '.select_item_number.select_popup', function() {
	var rowClass = $(this).closest('tr').prop('class');
	var fieldClass = $(this).closest('td').find('.select_item_number').prop('class');
	localStorage.setItem("row_class", rowClass);
	localStorage.setItem("field_class", fieldClass);
	var openUrl = 'select.php?class_name=item';
	if ($(this).siblings('.item_number').val()) {
	 openUrl += '&item_number=' + $(this).siblings('.item_number').val();
	}
	void window.open(openUrl, '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });


 //toggle sereah form
 $('#searchForm').on('dblclick', function() {
	$(this).find('.search_form').toggle();
 });
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
	 var elementToBeCloned = $('.text_search').first().closest('li');
	 var elementClass = $('.text_search').first().prop('class');
	 var elementName = $('.text_search').first().prop('name');
	 var elementLabelClass = '.label_' + elementName;
	 clonedElement = elementToBeCloned.clone();
	 $('label[for="' + elementName + '"]').text(newSearchCriteria);
	 clonedElement.children().removeClass(elementClass);
	 clonedElement.children().addClass(newSearchCriteria);
	 clonedElement.children().prop('name', newSearchCriteria);
	 clonedElement.find("input").each(function() {
		$(this).val("");
	 });
//	 clonedElement.appendTo($(this).closest("ul"));
	 clonedElement.insertBefore($(this).closest("li"));
	 $(elementLabelClass + ':last').text(newSearchCriteria);
	}
 });

//get the new search criteria
// var json_url = homePageUrl + 'include/basics/json.basics.php';
// new_searchCriteria_onClick(json_url);
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
 $('body').on('focus', ".date", function() {
	var currentDate = new Date();
	$(this).datepicker({
	 defaultDate: 0,
	 changeMonth: true,
	 changeYear: true,
	 dateFormat: "yy-mm-dd",
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
 //dont allow past dates if manually entered
 $('body').on('change', '.dateFromToday', function() {
	var toDay = new Date();
	var enteredDate = $(this).datepicker("getDate");
	if ((enteredDate) && (enteredDate < toDay)) {
	 $(this).val('');
	 $(this).focus();
	 alert("Cant enter any past date");
	}
 });
 //creating tabs
 $("#tabs").tabs();
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
// $("#tabsHeader").tabs();
// $("#tabsLine").tabs();
 $("#tabsDetail").tabs();
 $(".tabsDetail").tabs();
//Refresh the page
 $("#refresh_button").on("click", function() {
	location.reload(true);
	localStorage.removeItem("disableContextMenu");
 });

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
 $("input").focus(function() {
	$(this).css("background-color", "#cccccc");
 });
 $("input").blur(function() {
	$(this).css("background-color", "#ffffff");
 });
 $(" :required").css("background-color", "pink");
 $("[readonly]").css("background-color", "#ddd");
// $("select:required").css("background-color", "pink");
// $("input:required").focus(function() {
//	$(this).css("background-color", "pink");
// });
 $("input:required").blur(function() {
	$(this).css("background-color", "pink");
 });
 //Popup for print
 $(".print").click(function() {
	window.print();
 });
 //all download
 $('#export_excel_allResult').on('click', function() {
	$('#download_all').submit();
 });

 show_dialog_box();
 //shortcut keys
 $(document).bind('keydown', 'alt+r', function(e) {
	e.preventDefault();
	$("#refresh_button").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+o', function(e) {
	e.preventDefault();
	$("#new_object_button").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+n', function(e) {
	e.preventDefault();
	$(".add_row_img").trigger("click").one();
 });
 $(document).bind('keydown', 'alt+s', function(e) {
	e.preventDefault();
	$("#save").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+d', function(e) {
	e.preventDefault();
	$("#delete_button").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+m', function(e) {
	e.preventDefault();
	$("#remove_row_button").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+t', function(e) {
	e.preventDefault();
	$("#reset_button").first().trigger('click');
 });
 $(document).bind('keydown', 'alt+b', function(e) {
	e.preventDefault();
	$("#go_back_button").first().trigger('click');
 });
});