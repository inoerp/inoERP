function fp_mds_load_mds() {
 var fp_mds_header_id = $("#fp_mds_header_id").val();
 if (fp_mds_header_id) {
  var link = 'program.php?window_type=popup&class_name=fp_mds_header&program_name=prg_load_mds&fp_mds_header_id=' + fp_mds_header_id;
  var width_i = $(window).width();
  var height_i = $(window).height();
  void window.open(link, '_blank',
          'width='+ width_i+',height='+ height_i+',TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  return false;
 } else {
  alert('No fp_mds_header_id found\nEnter or Save The Header Details ');
 }
}

$(document).ready(function () {

 $('body').off('change', '#mds_action').on('change', '#mds_action', function () {
  var selected_value = $(this).val();
  switch (selected_value) {
   case 'LOAD_MDS' :
    fp_mds_load_mds();
    break;

   default :
    break;
  }
 });

});