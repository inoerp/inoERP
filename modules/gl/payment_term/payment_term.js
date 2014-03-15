$(document).ready(function() {
//selecting payment_term
 $("#payment_term_id_find_popup").on("click", function() {
	localStorage.idValue = "";
	void window.open('find_payment_term.php', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });
 
   function setParnetWindowValues(payment_termId, payment_term)
 {
	 window.opener.$(".payment_term_id").val(payment_termId);
	 window.opener.$(".payment_term").val(payment_term);
	}


 $(".quick_select").on("click", function() {
	var payment_termId = $(this).val();
	var payment_term = $(this).closest("td").siblings("td.payment_term").html();
	setParnetWindowValues(payment_termId, payment_term);
	window.close();
  });


 //Get the payment_term_id on refresh button click
 $('#payment_term_id_show').on("click", function() {
	var payment_term_id = $('#payment_term_id').val();
//	$(this).attr('href', '?payment_term_id=' + payment_term_id);
	window.location = '?payment_term_id=' + payment_term_id;
 });

$("#content tbody.payment_term_schedule_values").on("click", ".add_row_img", function() {
add_new_row('tr.payment_term_schedule0', 'tbody.payment_term_schedule_values', 1);
});

$("#content tbody.payment_term_discount_values").on("click", ".add_row_img", function() {
add_new_row('tr.payment_term_discount0', 'tbody.payment_term_discount_values', 1);
});

// get the attachement form
 get_attachment_form('../../extensions/file/json.file.php');
 deleteData('json.payment_term.php');
 save('json.payment_term.php', '#payment_term_header', 'line_id_cb', 'seq_number', '#payment_term_id');

});
