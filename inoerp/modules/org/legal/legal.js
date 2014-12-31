function setValFromSelectPage(legal_id) {
 this.legal_id = legal_id;
}

setValFromSelectPage.prototype.setVal = function() {
 var legal_id = this.legal_id;
 if (legal_id) {
	$("#legal_id").val(legal_id);
 }
};

$(document).ready(function() {
 
  //selecting Id
 $(".legal.select_popup").on("click", function() {
	void window.open('select.php?class_name=legal', '_blank',
					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
 });

});

