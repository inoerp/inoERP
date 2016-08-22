<?php
if(!empty($_GET['view_name'])){
 $view_name = $_GET['view_name'];
}else{
 $view_type_name='view';
}

if(!empty($_GET['sql'])){
 $sql = $_GET['sql'];
}

$viewTitle = " View - Create & update $view_type_name ";
$extension = "view";
$key_field = "view";
$primary_column = "view_id";
$required_field_flag = 1;
$table_name = 'view';
?>
<?php include_once("../../include/basics/header.inc"); ?>
<script src="view.js"></script>

<?php
//echo '<pre>';
//print_r($view);
//echo '<pre>';
if((!empty($view->query))){
 $view_result = extn_view::result_list_in_table(base64_decode($view->query), $view->view_id ,$pageno, $per_page, $query_string);
}else{
 $view_result="";
}
$search_form = search::search_form('view', 'views', 'view_search');
if(!empty($pagination)){
$pagination_statement = $pagination->show_pagination($pagination, 'views', $pageno, $query_string );
}

if (!empty($msg)) {
 $show_message = '<div id="dialog_box">';
  foreach ($msg as $key => $value) {
   $x = $key + 1;
   $show_message .= 'Message ' . $x . ' : ' . $value . '<br />';
  }
 $show_message .= '</div>';
}

?>

<?php require_once('views_template.php') ?>
