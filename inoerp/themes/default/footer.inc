<!--footer content-->
<div id="comment_form" class="none">
 <?php
  global $reference_table,$reference_id, $comment  ;
  if (!empty($reference_table) && !empty($reference_id)) {
   include_once HOME_DIR . '/comment.php';
  }
 ?>
</div>
<?php echo (!empty($footer_top)) ? "<div id=\"footer_top\"> $footer_top </div>" : ""; ?>
<div id="footer" class="topBottomBG">
 <div id="footer_top"></div>
 <div id="footer_message">
  <?php
   global $si;
   echo nl2br($si->footer_message);
  ?>
 </div>
</div>

<?php
 global $f;
 echo (!empty($footer_bottom)) ? "<div id=\"footer_bottom\"> $footer_bottom </div>" : "";
 echo $f->hidden_field_withId('home_url', HOME_URL);
?>
</body>
</html>
<?php
// 5. Close connection
 if (isset($dbc)) {
  $dbc->close_connection();
 }
?>
