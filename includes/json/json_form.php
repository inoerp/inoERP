<?php include_once("../basics/basics.inc"); ?>
<?php
if (!empty($_GET['class_name'])) {
 $class_names = $_GET['class_name'];
 echo '<div id="json_serch_result">';
$search_parameters = $_GET['search_parameters'];
$_GET = $search_parameters;
$_GET['mode'] = array('2');
$_GET['submit_search'] = 'Search';
$_GET['search_class'] = $class_names;
include_once("../functions/loader.inc");
require_once(INC_BASICS . DS . "search_page.inc");
 echo '</div>';
}
?>

