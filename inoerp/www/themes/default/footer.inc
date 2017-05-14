<!--footer content-->
<div id="comment_form" class="none">
 <?php
 
 if (!empty($reference_table) && !empty($reference_id)) {
  include_once HOME_DIR . '/comment.php';
 }
 ?>
</div>

<div class="make-bg-full">
 <div class="calloutbox-full-mini nocontainer">
  <div class="long-twitter">
   <p class="lead"><i class="fa fa-star"></i>
    All inoERP code is Copyright by the Original Authors as mentioned on COPYRIGHT.txt file.
    <br>inoERP is an open Source software; you can redistribute it and/or modify
    it under the terms of the Mozilla Public License Version 2.0 </p>
  </div>
 </div><!-- end calloutbox -->
</div><!-- make bg -->

<div id="footer-style-1">
 <div class="container">
  <div id="footer_top"></div>
 </div>
</div>
<div id="copyrights">
 <div class="container">
  <div class="col-lg-5 col-md-6 col-sm-12">
   <div class="copyright-text">
    <p>
     <?php
     global $si;
     echo nl2br($si->footer_message);
     ?>
    </p>
   </div><!-- end copyright-text -->
  </div><!-- end widget -->
  <div class="col-lg-7 col-md-6 col-sm-12 clearfix">
   <div class="footer-menu">
    <ul class="menu">
       <li><a href="http://inoideas.org/content.php?mode=9&content_type=web_contact">Contact</a></li>
       <li><a href="https://github.com/inoerp/inoERP/releases">Releases</a></li>
       <li><a href="https://www.mozilla.org/MPL/2.0/">MPL 2</a></li>
       <li><a href="https://www.facebook.com/inoerp">Facebook</a></li>
       <li><a href="https://www.linkedin.com/company/inoerp">LinkedIn</a></li>

    </ul>
   </div>
  </div><!-- end large-7 --> 
 </div><!-- end container -->
</div><!-- end copyrights -->

<?php
global $f;
echo (!empty($footer_bottom)) ? "<div id=\"footer_bottom\"> $footer_bottom </div>" : "";
echo $f->hidden_field_withId('home_url', HOME_URL);
echo $si->analytics_code;
?>
</body>
</html>
<?php
// 5. Close connection
if (isset($dbc)) {
 $dbc->close_connection();
}
?>
