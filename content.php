<?php

$dont_check_login = true;
$content_class = true;
$class_names = [
		'content'
];
?>
<?php

include_once("includes/functions/loader.inc");
$read_access = true;
//exit script in case of delete statement
if ((!empty($_GET['delete'])) && ($_GET['delete'] == 1)) {
 return;
}
?>
<?php

//if (((!empty($_SESSION['username'])) && ($content->created_by == $_SESSION['username'])) || ((!empty($_SESSION['user_roles'])) && (in_array('admin', $_SESSION['user_roles'])))) {
// $allow_content_update = true;
// if (!empty($_GET['mode'])) {
//	$mode = $_GET['mode'];
// }
//}
?>
<?php

$crp = getrwuPrivilage($content_type->comment_read_role, $_SESSION['user_roles'][0]);
$cwp = getrwuPrivilage($content_type->comment_write_role, $_SESSION['user_roles'][0]);
$cup = getrwuPrivilage($content_type->comment_update_role, $_SESSION['user_roles'][0]);
$comment_privilage = $crp + $cwp + $cup;

if (($update_access) && ($mode == 9)) {
 include_once(THEME_DIR . '/content_template.inc');
} else if (($write_access) && empty($$class->$class_id_first) && ($mode == 9)) {
 include_once(THEME_DIR . '/content_template.inc');
} else if (($mode == 9)) {
 $session->redirect_login();
} else {
 require_once(INC_EXTENSIONS . DS . 'content' . DS . 'view' . DS . "content_view.php");
 echo!empty($breadCrum) ? $breadCrum : false;
 if ((!empty($content->content_id)) && ($content_type_name)) {
	include_once(THEME_DIR . '/view_content_template.inc');
 } elseif ((!empty($category_id)) && ($content_type_name)) {
	include_once(THEME_DIR . '/contents_list_template.inc');
 } else {
	include_once(THEME_DIR . '/content_search.php');
 }
}
?>
