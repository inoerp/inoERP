function setValFromSelectPage(extn_contact_id) {
 this.extn_contact_id = extn_contact_id;
}


setValFromSelectPage.prototype.setVal = function () {
 if (this.extn_contact_id) {
  $("#extn_contact_id").val(this.extn_contact_id);
 }
};

$(document).ready(function () {
 //selecting Id
// $(".extn_contact_id.select_popup").on("click", function() {
//	void window.open('select.php?class_name=extn_contact', '_blank',
//					'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
// });

 //Get the extn_contact_id on find button click
 $('a.show.extn_contact_id').click(function () {
  var extn_contact_id = $('#extn_contact_id').val();
  $(this).attr('href', modepath() + 'extn_contact_id=' + extn_contact_id);
 });

});