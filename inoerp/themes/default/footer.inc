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
<script>
 (function(i, s, o, g, r, a, m) {
  i['GoogleAnalyticsObject'] = r;
  i[r] = i[r] || function() {
   (i[r].q = i[r].q || []).push(arguments)
  }, i[r].l = 1 * new Date();
  a = s.createElement(o),
   m = s.getElementsByTagName(o)[0];
  a.async = 1;
  a.src = g;
  m.parentNode.insertBefore(a, m)
 })(window, document, 'script', '//www.google-analytics.com/analytics.js', 'ga');

 ga('create', 'UA-48829329-1', 'inoideas.org');
 ga('send', 'pageview');

</script>

</html>
<?php
// 5. Close connection
 if (isset($dbc)) {
  $dbc->close_connection();
 }
?>
