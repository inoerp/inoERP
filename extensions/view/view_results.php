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
<link href="view.css" media="all" rel="stylesheet" type="text/css" />

<?php
//echo '<pre>';
//print_r($_GET);
//echo '<pre>';
//create query 
$query ="";
if((!empty($view->select))){
 $query .= " SELECT ".$view->select;
}

if((!empty($view->from))){
 $query .= " FROM ".$view->from;
}

if((!empty($view->where))){
 $query .= " WHERE ".$view->where;
}

//if((!empty($view->query))){
// $view_result = view::result_list_in_table(base64_decode($view->query), $view->view_id ,$pageno, $per_page, $query_string);
//}else{
// $view_result="";
//}

if((!empty($view->filters))){
 $view_filter_statement = "<form action=\"\" method=\"get\" name=\"view_filter\" id=\"view_filter\"> ";
 $view_filters_array = explode(",", $view->filters);
 $view_filter_statement .= "<ul class=\"view_filters\">";
 $view_filter_statement .= "<li class=\"hidden\">
				 <input type=\"hidden\" class=\"hidden\" name=\"view_id\" value=\"$view->view_id\" ></li>";
 foreach ($view_filters_array as $key => $value) {
  $view_filter_statement .= "<li><label>$value</label>";
	$view_filter_statement .= "<input type=\"serach\" name=\"$value\" class=\"$value\"></li>";
 }
 $view_filter_statement .= "<li><input type=\"submit\" form=\"view_filter\" value=\"Filter\" class=\"view_filter submit button \"></li>";
 
 $view_filter_statement .= "<li> <a class=\"button\" href=\"view_results.php?view_id=$view->view_id\">Clear</a> </li>";
 $view_filter_statement .= "</ul>";
 $view_filter_statement .= "</form>";
}


if(!empty($view_filters_array)){
foreach ($view_filters_array as $key => $value){
 $value_new = str_replace('.', '_', $value);
  if(!empty($_GET[$value_new])){
	$query .= " AND ". $value.' LIKE \'%'. $_GET[$value_new].'%\' ';
 }
}
 
}

if((!empty($view->order_by))){
 $query .= " ORDER BY ".$view->order_by;
}
//echo '<br/>$query is '. $query;


//if((!empty($query))){
// $view_result = view::result_list_in_table($query, $view->view_id ,$pageno, $per_page, $query_string);
//}else{
// $view_result="";
//}

switch($view->display_type){
	case 'paragraph' :
	 $view_result = view::result_list_in_paragraph($query, $view->view_id ,$pageno, $per_page, $query_string);
	break;
 
	 case 'table' :
		$view_result = view::result_list_in_table($query, $view->view_id ,$pageno, $per_page, $query_string);
		break;
	 
	default:
	 $view_result="";
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

<?php require_once('view_results_template.php') ?>
