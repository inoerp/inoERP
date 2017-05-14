<?php
 echo $f->hidden_field_withId('home_url', HOME_URL);
 echo '<div class="hidden">' .$si->analytics_code .'</div>';
?>
</body>
</html>
<?php
// 5. Close connection
if (isset($db)) {
 $db->close_connection();
}
?>
