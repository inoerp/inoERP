<?php include_once(__DIR__ . '/../inoerp_server/includes/basics/basics.inc'); ?>
<script src="<?php echo HOME_URL; ?>include/js/jquery-2.0.3.min.js"></script> 
<script>
$(document).ready(function() {
  var doc = window.opener.$("#print").html();
  $("#print_doc").html(doc);
  window.print();
});
</script>
<h2>Printing Document</h2>
      <div id="print_doc">
        
        
      </div>
      