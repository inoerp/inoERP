<?php

$form_page = true;
$dont_check_login = true;
$content_class = true;
$class_names = [
 'content'
];
?>
<?php

include_once('../functions/loader.inc');
$read_access = true;
//exit script in case of delete statement
if ((!empty($_GET['delete'])) && ($_GET['delete'] == 1)) {
 return;
}
if ((!empty($_POST))) {
 return;
}
?>
<?php

if (!empty($content_type)) {
 $content_rp = getrwuPrivilage($content_type->read_role, $_SESSION['user_roles'][0]);
 $content_wp = getrwuPrivilage($content_type->write_role, $_SESSION['user_roles'][0]);
 $content_up = getrwuPrivilage($content_type->update_role, $_SESSION['user_roles'][0]);
 $content_privilage = $content_rp + $content_wp + $content_up;

 $crp = getrwuPrivilage($content_type->comment_read_role, $_SESSION['user_roles'][0]);
 $cwp = getrwuPrivilage($content_type->comment_write_role, $_SESSION['user_roles'][0]);
 $cup = getrwuPrivilage($content_type->comment_update_role, $_SESSION['user_roles'][0]);
 $comment_privilage = $crp + $cwp + $cup;
} else {
 $content_privilage = $content_rp = $content_wp = $content_up = $comment_privilage = $crp = $cwp = $cup = 0;
}


if ($continue) {
// include_once(THEME_DIR . '/header.inc');
} else {
 $continue = false;
 echo "<h2>Could n't call the header</h2>";
 return;
}

if (($content_privilage >= 6) && ($mode == 9)) {
 include_once(THEME_DIR . '/content_template.inc');
} else if (($content_privilage >= 4) && empty($$class->$class_id_first) && ($mode == 9)) {
 include_once(THEME_DIR . '/content_template.inc');
} else if (($content_privilage >= 4) && !empty($_SESSION['username']) && ($$class->created_by == $_SESSION['username']) && ($mode == 9)) {
 include_once(THEME_DIR . '/content_template.inc');
} else if (($mode == 9)) {
 $access_denied_msg = 'You don\'t have access to this page. <br><a href="'.HOME_URL.'extensions/ino_user/user_login.php">Login </a> or request for access';
 include_once(THEME_DIR . '/content_template.inc');
} else {
 require_once(INC_EXTENSIONS . DS . 'content' . DS . 'view' . DS . "content_view.php");
 echo!empty($breadCrum) ? $breadCrum : false;
 if ((!empty($content->content_id)) && ($content_type_name)) {
  include_once(THEME_DIR . '/view_content_template.inc');
 } elseif (!empty($non_db_content_type)) {
  include_once(THEME_DIR . '/nondb_content_template.inc');
 } elseif ((!empty($category_id)) && ($content_type_name)) {
  include_once(THEME_DIR . '/contents_list_template.inc');
 } else if (SHOW_COTENT_LIST == 1) {
  include_once(THEME_DIR . '/contents_list_template.inc');
 } else {
  echo ino_access_denied('Sorry!!! Requested content is not found');
 }
}
?>