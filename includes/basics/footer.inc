
<!--footer content-->
<?php echo (!empty($footer_top)) ? "<div id=\"footer_top\"> $footer_top </div>" : "" ; ?>
<div id="footer" class="topBottomBG">Copyright @ 2013 inoERP  </div>
<?php echo (!empty($footer_bottom)) ? "<div id=\"footer_bottom\"> $footer_bottom </div>" : "" ;  ?>
</body>
</html>
<?php
// 5. Close connection
if (isset($db)) {
 $db->close_connection();
}
?>
