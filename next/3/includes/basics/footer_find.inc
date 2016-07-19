</div>
         </body>
</html>
<?php
	// 5. Close connection
if (isset($db)){
    
 $db->close_connection();
}
?>
<? ob_flush(); ?>