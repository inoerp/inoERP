<?php
$f = new inoform();
 echo $f->hidden_field_withId('home_url', HOME_URL);
?>
</body>
</html>
<?php
// 5. Close connection
if (isset($db)) {
 $db->close_connection();
}
?>
