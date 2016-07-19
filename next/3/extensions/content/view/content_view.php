<?php

//$dont_check_login = true;
//require_once('../content.inc');
?>
<?php

/* category id is defaulted from $_GET where as $categories comes from main_functions. $categories contains an object
  which contains all the categories of the opened content / document. Where as category id ('ll be one of the values
  of categories ) is used show all the releant contents */

//$content_type = content_type::find_by_content_type($content_type_name);
$childs_of_parent_id_array = content::find_childs_of_parent_id($content->content_id);
if ($childs_of_parent_id_array && (count($childs_of_parent_id_array) > 0)) {
 $childs_of_parent_id = "<ul>";
 foreach ($childs_of_parent_id_array as $child_content) {
  $childs_of_parent_id .= '<li><a href="' . HOME_URL . 'content.php?content_type=' . $content_type_name . '&amp;content_id=' . $child_content->content_id . '"   
               class="content_subject"> ' . $child_content->subject . ' </a></li>';
 }
 $childs_of_parent_id .="</ul>";
}

if (!empty($content->parent_id) && !empty($parent_content->subject)) {
 $parent_content = content::find_by_id($content->parent_id);
 $parent_of_content = '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type_name . '&amp;content_id=' . $parent_content->content_id . '"   
               class="content_subject"> ' . $parent_content->subject . ' </a>';
}
//end of parent & child details



if (!empty($category)) {
 $category_statement = "";
 foreach ($category as $object) {
  if (!empty($object->category) && !empty($object->category_id)) {
   $category_statement .= '<a href="' . HOME_URL . 'content.php?content_type=' . $content_type_name . '&amp;category_id=' . $object->category_id . '">' . $object->category . '</a> &nbsp; &nbsp; ';
  }
 }
}

//check if user is allowed to update the content
$allow_content_update = false;
if ((!empty($_SESSION['username'])) && ($content->created_by == $_SESSION['username'])) {
 $allow_content_update = true;
} elseif ((!empty($_SESSION['user_roles'])) && (in_array('ADMIN', $_SESSION['user_roles']))) {
 $allow_content_update = true;
}
?>
