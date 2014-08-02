
$(document).ready(function() {
$('.select.status').val('PENDING_APPROVAL').on('change', function(){
alert('You can only search count entries in pending approval status.');
$('.select.status').val('PENDING_APPROVAL');
});

});