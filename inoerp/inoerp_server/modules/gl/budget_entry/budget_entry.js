$(document).ready(function() {
 
 $('#ledger_id').on('change', function() {
  getLedgerDetails($(this).val());
 });

 if ($('#ledger_id').val() && (!$('#gl_journal_header_id').val())) {
  getLedgerDetails($('#ledger_id').val());
 }

});