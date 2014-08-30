<?php $dont_check_login= 1; ?>
<?php
//check if user is allowed to update the content
$allow_content_update = false;
if ((!empty($_SESSION['username'])) && ($$class->created_by == $_SESSION['username'])) {
    $allow_content_update = true;
} elseif ((!empty($_SESSION['user_roles'])) && (in_array('admin', $_SESSION['user_roles']))) {
    $allow_content_update = true;
}
?>

