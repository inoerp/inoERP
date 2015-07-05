function setValFromSelectPage(fp_mds_header_id, mds) {
 this.fp_mds_header_id = fp_mds_header_id;
 this.mds = mds;
}

setValFromSelectPage.prototype.setVal = function() {
  var mds = this.mds;
 var fp_mds_header_id = this.fp_mds_header_id;
 
 if (mds) {
	$('#content').find('#mds').val(mds);
 }
  if (fp_mds_header_id) {
	$('#fp_mds_header_id').val(fp_mds_header_id);
  $('a.show.fp_mds_header_id').trigger('click');
 }
 
 };

$(document).ready(function() {
//mandatory and field sequence
 var mandatoryCheck = new mandatoryFieldMain();
mandatoryCheck.mandatoryHeader();
 mandatoryCheck.form_area = 'form_header';
 mandatoryCheck.mandatory_fields = ["org_id", "item_number"];
 mandatoryCheck.mandatory_messages = ["First Select Org", "No Item Number"];
// mandatoryCheck.mandatoryField();
 //Popup for selecting mds
 $("#fp_mds_header_divId").off('click', '.fp_mds_header_id.select_popup')
         .on('click', '.fp_mds_header_id.select_popup',function() {
	void window.open('select.php?class_name=fp_mds_header', '_blank',
					'width=1200,height=1000,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
	return false;
 });

});