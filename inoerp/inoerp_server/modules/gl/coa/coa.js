function setValFromSelectPage(coa_id) {
 this.coa_id = coa_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var coa_id = this.coa_id;
 if (coa_id) {
	$("#coa_id").val(coa_id);
 }
};

 function change_account_type_for_new_line() {
	$('body').on( 'focusout', '#coa_segment_values .coa_segment_values_id',function() {
	 if ($("#coa_segments option").val() == "ACCOUNT") {
		var x = $(this).val();
		var y = $(this);
		if ((x === "") || $.type(x) === "undefined") {
		 $('#loading').show();
		 $.ajax({
			url: 'json.coa.php',
			type: 'get'
		 }).done(function(data) {
			var div = $('#json_account_type', $(data)).html();
			y.parent().siblings(".account_type_td").html(div);
			$('#loading').hide();
		 }).fail(function() {
			alert("failed");
			$('#loading').hide();
		 });
		}

	 }
	});
 }

$(document).ready(function() {

//validate if the coa_structure_id is selected
 $("#balancing").change(function() {
	if ($("#coa_structure").val() == "") {
	 alert('First Select COA coa_structure_id');
	 $("#balancing").val("");
	}
 });

 $("#cost_center").change(function() {
	if ($("#coa_structure").val() == "") {
	 alert('First Select COA coa_structure_id');
	 $("#cost_center").val("");
	}
 });

 $("#natural_account").change(function() {
	if ($("#coa_structure").val() == "") {
	 alert('First Select COA coa_structure_id');
	 $("#natural_account").val("");
	}
 });



 //Fetch the account segment values after coa id is selected in coa_segments_vales.php
////Show the segments after coa_structure_id is selected
// $('body').on('focusout','#coa_segment_values #coa_id',function() {
//	$('#loading').show();
//	var coaId = $("#coa_segment_values #coa_structure_id").val();
//
//	$.ajax({
//	 url: '../../system/option/json.option.php?',
//	 data: {option_id_l: coaId},
//	 type: 'get'
//	}).done(function(data) {
//	 var div = $('#coa_json', $(data)).html();
//	 $("#coa_segment_values #coa_segments").html(div);
//	 $('#loading').hide();
//	}).fail(function() {
//	 alert("failed");
//	 $('#loading').hide();
//	});
//
// });


//Show the account types for a new line to be called after new line entery
  //selecting Header Id
 $(".coa_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=coa', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get values on refresh button click
 $('a.show_diff.coa_structure_show').click(function() {
	var headerId = $('#coa_structure_id').val();
	$(this).attr('href', modepath() + 'coa_structure_id=' + headerId);
 });
});











