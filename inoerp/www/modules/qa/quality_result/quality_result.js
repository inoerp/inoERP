$(document).ready(function () {
$('#content').off('change', '#qa_cp_header_id') .on('change', '#qa_cp_header_id' , function(){
$('a.show').trigger('click');
})
 });