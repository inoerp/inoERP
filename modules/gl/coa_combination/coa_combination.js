 function setValFromSelectPage(coa_id){
	this.coa_id = coa_id;
 }
 
setValFromSelectPage.prototype.setVal = function(){
 coa_id = this.coa_id;
  $("#coa_id").val(coa_id);
};

$(document).ready(function() {
//Show the segments after coa_structure_id is selected
 $("#coa_segment_values #coa_id").focusout(function() {
	$('#loading').show();
	var coaId = $("#coa_segment_values #coa_structure_id").val();

	$.ajax({
	 url: '../../system/option/json.option.php?',
	 data: {option_id_l: coaId},
	 type: 'get'
	}).done(function(data) {
	 var div = $('#coa_json', $(data)).html();
	 $("#coa_segment_values #coa_segments").html(div);
	 $('#loading').hide();
	}).fail(function() {
	 alert("failed");
	 $('#loading').hide();
	});

 });
 
  //selecting Header Id
 $(".coa_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=coa', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

//COA combination
 $('#coa_combination_line').on('focusout', '.field_values', function() {
	var trClass = '.' + $(this).closest('tr').prop('class');
	var coaCombination = '';
	$(this).closest('tr').find('.field_values').each(function() {
	 coaCombination += $(this).val() + '-';
	});
	coaCombination = coaCombination.slice(0, -1);
	$(this).closest('#coa_combination_line').find(trClass).find('.combination').val(coaCombination);
 });
//COA Decsription
$('#coa_combination_line').on('focusout', '.field_values', function() {
var trClass = '.' + $(this).closest('tr').prop('class');
var coaDesc = '';
$(this).closest('tr').find('.field_values').each(function() {
 coaDesc += $(this).children("option:selected").text().split(' - ').pop()+ '-';
});
coaDesc = coaDesc.slice(0, -1);
$(this).closest('#coa_combination_line').find(trClass).find('.description').val(coaDesc);
});

//Get the option_id on find button click
 $('a.show.coa_id_show').click(function() {
	var headerId = $('#coa_id').val();
	$(this).attr('href', modepath() + 'pageno=1&per_page=10&submit_search=Search&search_class=coa_combination&coa_id=' + headerId);
 });

 $('a.show.coa_structure_show').click(function() {
	var headerId = $('#coa_structure_id option:selected').val();
	$(this).attr('href', modepath() + 'pageno=1&per_page=10&submit_search=Search&search_class_name=coa_combination&coa_structure_id=' + headerId);
 });

 //context menu
 var classContextMenu = new contextMenuMain();
 classContextMenu.docHedaderId = 'coa_id';
 classContextMenu.docLineId = 'coa_combination_id';
 classContextMenu.btn1DivId = 'form_header';
 classContextMenu.btn2DivId = 'form_line';
 classContextMenu.trClass = 'coa_combination_line';
 classContextMenu.tbodyClass = 'form_data_line_tbody';
 classContextMenu.noOfTabbs = 3;
 classContextMenu.contextMenu();
 

 onClick_add_new_row('tr.coa_combination_line0', 'tbody.coa_combination_values', 3);
 deleteData('json_coa_combination.php');
// save('json_coa_combination.php', '#coa_combination_line', 'line_id_cb', 'coa_combination', '#coa_combination_id');
 var objSave = new saveMainClass();
 objSave.json_url = 'form.php?class_name=coa_combination';
 objSave.single_line = false;
 objSave.line_key_field = 'combination';
 objSave.form_line_id = 'coa_combination';
 objSave.saveMain();
});  