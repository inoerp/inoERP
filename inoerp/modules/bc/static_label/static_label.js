function setValFromSelectPage(bc_static_label_id) {
 this.bc_static_label_id = bc_static_label_id;
}


setValFromSelectPage.prototype.setVal = function() {
 if (this.bc_static_label_id) {
	$("#bc_static_label_id").val(this.bc_static_label_id);
 }
};

$(document).ready(function() {
 //selecting Id
 $(".bc_static_label_id.select_popup").on("click", function() {
	void window.open('select.php?class_name=bc_static_label', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

 //Get the bc_static_label_id on find button click
 $('a.show.bc_static_label_id').click(function() {
	var bc_static_label_id = $('#bc_static_label_id').val();
	$(this).attr('href', modepath() + 'bc_static_label_id=' + bc_static_label_id);
 });

});
