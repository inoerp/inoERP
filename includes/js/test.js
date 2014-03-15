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
 * @param {type} primary_column_id2
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

function saveHeader(json_url, headerData, primary_column_id, primary_column_id2, savingOnlyHeader, form_header) {
 $.ajax({
	url: json_url,
	data: {headerData: headerData,
	 className: form_header},
	type: 'post'
 }).done(function(result) {
	var primary_column_class = primary_column_id.replace('#', '.');
	var div = $(result).filter('div#json_save_header').html();
	var header_id = $(result).find('div#headerId').html();
	var header_id2 = $(result).find('div#headerId2').html();
//	alert('primary_column_id2 is '+ primary_column_id2 + 'header_id2 is ' + header_id2);
	$(".error").append(div);
	$(primary_column_id).val(header_id);
	$(primary_column_class).val(header_id);
	if ($(primary_column_id2).val()) {
	 $(primary_column_id2).val(header_id2);
	}
	if (savingOnlyHeader) {
	 $('.show_loading_small').hide();
	 $("#save").removeClass("opacity_2");
	}
 }).fail(function(error, textStatus, xhr) {
	alert("save failed \n" + error + textStatus + xhr);
	if (savingOnlyHeader) {
	 $('.show_loading_small').hide();
	 $("#save").removeClass("opacity_2");
	}
 });
}

function saveSingleLine(json_url, lineData, primary_column_id, form_line) {
 var header_id = $(primary_column_id).val();
 $.ajax({
	url: json_url,
	data: {
	 lineData: lineData,
	 header_id: header_id,
	 className: form_line},
	type: 'post'
 }).done(function(result) {
	var div = $(result).filter('div#json_save_singleLine').html();
	$(".error").append(div);
	$("#save").removeClass("opacity_2");
	$('.show_loading_small').hide();
 }).fail(function(error, textStatus, xhr) {
	alert("save failed \n" + error + textStatus + xhr);
	$('.show_loading_small').hide();
	$("#save").removeClass("opacity_2");
 });
}

function saveLine(json_url, lineData, trclass, detailData, primary_column_id, form_line) {
 var header_id = $(primary_column_id).val();
 $.ajax({
	url: json_url,
	data: {lineData: lineData,
	 detailData: detailData,
	 header_id: header_id,
	 className: form_line},
	type: 'post'
 }).done(function(result) {
	var div = $(result).filter('div#json_save_line').html();
	var line_id = $(div).filter('.lineId').html();
	$('#form_data_table tbody tr' + '.' + trclass).find(".line_id").val(line_id);
	$(".error").append(div);
	$('.show_loading_small').hide();
	$("#save").removeClass("opacity_2");
 }).fail(function(error, textStatus, xhr) {
	alert("save failed \n" + error + textStatus + xhr);
	$('.show_loading_small').hide();
	$("#save").removeClass("opacity_2");
 });
}

function saveLineSecondForm(json_url, lineData, trclass, detailData, form_line) {
 var header_id = $("#header_id").val();
 $.ajax({
	url: json_url,
	data: {lineData2: lineData,
	 detailData: detailData,
	 header_id: header_id,
	 className: form_line},
	type: 'post'
 }).done(function(result) {
	var div = $(result).filter('div#json_save_line2').html();
	var line_id = $(div).filter('.lineId').html();
	$('tbody.form_data_line_tbody2 tr' + '.' + trclass).find(".line_id").val(line_id);
	$(".error").append(div);
	$('.show_loading_small').hide();
	$("#save").removeClass("opacity_2");
 }).fail(function(error, textStatus, xhr) {
	alert("save failed \n" + error + textStatus + xhr);
	$('.show_loading_small').hide();
	$("#save").removeClass("opacity_2");
 });
}

function saveMainClass(json_url, form_header_id, primary_column_id, single_line, line_key_field, form_line_id, primary_column_id2) {
 this.json_url = json_url;
 this.form_header_id = form_header_id;
 this.primary_column_id = primary_column_id;
 this.line_key_field = line_key_field;
 this.form_line_id = form_line_id;
 this.primary_column_id2 = primary_column_id2;
 this.single_line = single_line;
}

saveMainClass.prototype.saveMain = function()
{
 var form_header_id_h = '#' + this.form_header_id;
 var form_line_id = this.form_line_id;
 var form_line_id_h = '#' + this.form_line_id;
 var primary_column_id_h = '#' + this.primary_column_id;
 var primary_column_id2_h = '#' + this.primary_column_id2;
 var json_url = this.json_url;
 var form_header_id = this.form_header_id;
 var single_line = this.single_line;
 var line_key_field = this.line_key_field;
 $("#save").on('click', function(e) {
//verify if header id exists or not - if header id is blank then check header level required fields
//if header id exists then check line level required fields
	var noOfRequiredFileValuesMissing = 0;
	var missingMandatoryValues = [];
	if (!$(primary_column_id_h).val()) {
//check header level missing required values - text & select
	 $(form_header_id_h + " :required").each(function() {
		if (!$(this).val())
		{
		 missingMandatoryValues.push($(this).attr('class'));
		 noOfRequiredFileValuesMissing++;
		}
	 });
	} else {
	 $(":required").each(function() {
		if (!$(this).val())
		{
		 missingMandatoryValues.push($(this).attr('class'));
		 noOfRequiredFileValuesMissing++;
		}
	 });
	}

	if (noOfRequiredFileValuesMissing > 0) {
	 var showMessage = ' <div id="dialog_box" class="dialog mandatory_message"> ' + noOfRequiredFileValuesMissing + ' mandatory field(s) is/are missing....... <br>';
	 $.map(missingMandatoryValues, function(val, i) {
		showMessage += i + ' : ' + val + ' <br>';
	 });
	 showMessage += '</div>';
	 $("#content").append(showMessage);
	 show_dialog_box();
	 return;
	}
	//opacity_2 class checks if the save is avaiable or not
	if ($("#save").hasClass('opacity_2')) {
	 alert('Save is disabled');
	 return;
	}
	$("#save").addClass("opacity_2");
	$('.show_loading_small').show();
	$("#save").prop('disabled', true);
	e.preventDefault();
//for all form headers - savetype1
	/*-----------------------------------Completion of mandator fields check & start of header save--------------------------------
	 * Check if saving only header data.
	 */
	var headerData = $(form_header_id_h).serializeArray();

	if (($('#form_line').html()) && ($(primary_column_id_h).val())) {
	 var savingOnlyHeader = false;
	}
	else {
	 var savingOnlyHeader = true;
	}
	saveHeader(json_url, headerData, primary_column_id_h, primary_column_id2_h, savingOnlyHeader, form_header_id);

	/*-----------------------------------Completion of save header & start of single line form save--------------------------------
	 for standard forms liks item, supplier - one header & one line savetype2
	 */
	if (single_line) {
	 var lineData = $(form_line_id_h).serializeArray();
	 saveSingleLine(json_url, lineData, primary_column_id_h, form_line_id);
	}
	else {
	 /*-----------------------------------Completion of single line & start of multiple lines form save--------------------------------
		for option type of form - one header & multiple lines 
		*/
//if  a line is checkeed-----------------------------------------------------------------------
	 if ($('input[name="line_id_cb"]:checked').length > 0) {
//for forms with tab @line level - PO-----------------------------savetype3a
		if ($("#tabsLine-1").html()) {
		 var count = 0;
		 $('input[name="line_id_cb"]:checked').each(function() {
			var trclass = $(this).closest('tr').attr('class');
			var lineData = [];
			$("#form_line").find('.' + trclass).each(function() {
			 var ThisLineData = $(this).find(":input").serializeArray();
			 lineData = $.merge(lineData, ThisLineData);
			});
			if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
			 var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
			} else {
			 detailData = "";
			}
			count++;
			saveLine(json_url, lineData, trclass, detailData, primary_column_id_h, form_line_id);
		 });
		 alert('count is' + count);
		} else {
//		 for option type form - line w/o any tab------------------savetype3b
		 $('input[name="line_id_cb"]:checked').each(function() {
			var lineData = $(this).closest("tr").find(":input").serializeArray();
			var trclass = $(this).closest("tr").attr('class');
			if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
			 var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
			} else {
			 detailData = "";
			}
			saveLine(json_url, lineData, trclass, detailData, primary_column_id_h, form_line_id);
		 });
		}
	 }
//i--------------completion of checked line -- start of all lines---------------------------------

	 else if (($('.' + line_key_field).val())) {
//for forms with tab @line level - PO - savetype4a
		if ($("#tabsLine-1").html()) {
		 $("#tabsLine-1 tbody.form_data_line_tbody > tr").each(function() {
			var trclass = $(this).attr('class');
			var lineData = [];
			$("#form_line").find('.' + trclass).each(function() {
			 var ThisLineData = $(this).find(":input").serializeArray();
			 lineData = $.merge(lineData, ThisLineData);
			});
			if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
			 var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
			} else {
			 detailData = "";
			}
			saveLine(json_url, lineData, trclass, detailData, primary_column_id_h, form_line_id);
		 });
		} else {
//for forms without tabs @ line level - Options - savetype4b
		 $("tbody.form_data_line_tbody > tr").each(function() {
			var lineData = $(this).find(":input").serializeArray();
			var trclass = $(this).attr('class');
			if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
			 var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
			} else {
			 detailData = "";
			}
			saveLine(json_url, lineData, trclass, detailData, primary_column_id_h, form_line_id);
		 });
		}
	 }
	 /*----------------------End of single header multiple line ----start of second form---------------------------------------------------------------------------*/
//for the third form (second form in line) - savetype5a
	 if (($('.' + line_key_field))) {
		var noOfTabsInForm3 = $("tbody.form_data_line_tbody2").length;
		//if the third form has tab
		if (noOfTabsInForm3 > 1) {
		 var tabsId = '#' + $("tbody.form_data_line_tbody2:first").closest("div").attr('id');
		 $(tabsId + " tbody.form_data_line_tbody2 > tr").each(function() {
			var trclass = $(this).attr('class');
			var lineData = [];
			$("#form_line").find('.' + trclass).each(function() {
			 var ThisLineData = $(this).find(":input").serializeArray();
			 lineData = $.merge(lineData, ThisLineData);
			});
			if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
			 var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
			} else {
			 detailData = "";
			}
			saveLineSecondForm(json_url, lineData, trclass, detailData, primary_column_id_h, form_line_id);
		 });
		} else {//if the third form doesnt have any tab-----------------savetype5b------------------------------------------
		 $("tbody.form_data_line_tbody2 > tr").each(function() {
			var lineData = $(this).find(":input").serializeArray();
			var trclass = $(this).attr('class');
			if ($(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray()) {
			 var detailData = $(this).closest("tr").find("tbody.form_data_detail_tbody").find(":input").serializeArray();
			} else {
			 detailData = "";
			}
			saveLineSecondForm(json_url, lineData, trclass, detailData, primary_column_id_h, form_line_id);
		 });
		}
	 }
	}
 });
};




