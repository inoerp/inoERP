<?php
 global $f;
 echo $f->hidden_field_withId('home_url', HOME_URL);
 echo $si->analytics_code;
?>
</body>
</html>
<?php
// 5. Close connection
if (isset($db)) {
 $db->close_connection();
}
?>
