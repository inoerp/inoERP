<?php
$extension = 'view';
$key_field = 'view';
$primary_column = "view_id";
$pageTitle = " View - Create & update view ";
$required_field_flag = 1;
include_once("../../include/basics/header.inc");

$view = new view;

global $db;

$path = new path;
//$all_pages = page::page_page();
//page::all_page_summary();

$query =" SELECT * FROM view_path ";
$result_array = $db->result_array($query);

echo '<pre>';
print_r($result_array);
echo '<pre>';

  

echo '----------Ressut by array -------------';
//$result_array = $db->result_array_assoc($sql);
//$count_of_recods = count($result_array);
//echo '<br/> count of records : ' . $count_of_recods;
//$view_name = '';
//$outPut = "";
//$outPut .= "<table class=view_table \"$view_name\" >";
//$outPut .= "<thead><tr>";
//$header = [];
//foreach ($result_array[0] as $key => $value) {
// $header[] = $key;
// $outPut .= "<th>$key</th>";
//}
//$outPut .= "</tr></thead><tbody>";
//foreach ($result_array as $records) {
// $outPut .= "<tr>";
// foreach ($records as $key => $value) {
//	$outPut .= "<td>$value</td>";
// }
// $outPut .= "</tr>";
//}
//$outPut .= "</tbody></table>";
//
//echo $outPut;

//function result_list_in_table($sql, $pageno="", $per_page="", $query_string="") {
// $view_page_name ='test';
// $view_name = 'name';
// global $db;
//
// $count_result = $db->result_array_assoc($sql);
// $page_string = " ";
//
// if (!empty($per_page)) {
//	$page_string .= '<div id="noOfpages">';
//	$page_string .= '<form action="" method="GET">';
//	$page_string .= 'Show<select name="per_page">';
//	$page_string .= '<option value="3"> 3 </option>';
//	$page_string .= '<option value="5"> 5 </option>';
//	$page_string .= '<option value="10"> 10 </option>';
//	$page_string .= '<option value="20"> 20 </option>';
//	$page_string .= '<option value="50"> 50 </option>';
//	$page_string .= '</select>';
//	$page_string .= '<input type="submit" class="button" value=\"' . gettext('Per Page') . '\" >';
//	$page_string .= '</form>';
//	$page_string .= '</div>';
//	$total_count = count($count_result);
//	$pagination = new pagination($pageno, $per_page, $total_count);
//	$sql .=" LIMIT {$per_page} ";
//	$sql .=" OFFSET {$pagination->offset()}";
//
// }
// 	$result = $db->result_array_assoc($sql);
//
// if (count($result) > 0) {
//	$outPut = "";
//	$outPut .= "<table class=view_table \"$view_name $view_page_name\" >";
//	$outPut .= "<thead><tr>";
//	$header = [];
//	foreach ($result[0] as $key => $value) {
//	 $header[] = $key;
//	 $outPut .= "<th>$key</th>";
//	}
//	$outPut .= "</tr></thead><tbody>";
//	foreach ($result as $records) {
//	 $outPut .= "<tr>";
//	 foreach ($records as $key => $value) {
//		$outPut .= "<td>$value</td>";
//	 }
//	 $outPut .= "</tr>";
//	}
//	$outPut .= "</tbody></table>";
// }
//
// $page_string .= $outPut;
//
// $page_string .= '<div id="pagination" style="clear: both;">';
// if (isset($pagination) && $pagination->total_pages() > 1) {
//	if ($pagination->has_previous_page()) {
//	 $page_string .= "<a href=\"$view_page_name.php?view_name=$view_name&pageno=";
//	 $page_string .= $pagination->previous_page() . '&' . $query_string;
//	 $page_string .= "> &laquo; " . gettext('Previous') . " </a> ";
//	}
//
//	for ($i = 1; $i <= $pagination->total_pages(); $i++) {
//	 if ($i == $pageno) {
//		$page_string .= " <span class=\"selected\">{$i}</span> ";
//	 } else {
//		$page_string .= " <a href=\"$view_page_name.php?view_name=$view_name&pageno={$i}&" . remove_querystring_var($query_string, 'pageno');
//		$page_string .= '">' . $i . '</a>';
//	 }
//	}
//
//	if ($pagination->has_next_page()) {
//	 $page_string .= " <a href=\"$view_page_name.php?view_name=$view_name&pageno=";
//	 $page_string .= $pagination->next_page() . '&' . remove_querystring_var($query_string, 'pageno');
//	 $page_string .= "\">" . gettext('Next') . " &raquo;</a> ";
//	}
// }
// $page_string .= '</div>';
//
// return $page_string;
//}
//
//echo "<br> page no: $pageno";
//echo "<br> per_page no: $per_page";
//echo "<br> query_string no: $query_string";
//echo result_list_in_table($sql, $pageno, $per_page, $query_string)

//echo '----------All Table Name -------------';
//  $table_name_array = extn_view::find_all_tables();
//  echo '----------End All Table Name -------------';
//  
//  echo '----------All Coumns Names of view -------------';
//  $column_name_array = extn_view::find_columns_of_table('view');

//  echo '----------End All Table Name -------------';
//
// $data = array(
//    array("firstname" => "Ma ry", "lastname" => "Joh & nson", "a!ge" => 25),
//    array("firstname" => "Amanda", "lastname" => "Miller", "a_ge" => 18),
//    array("firstname" => "James", "lastname" => "Brown", "age" => 31),
//    array("firstname" => "Patricia", "lastname" => "Williams", "age" => 7),
//    array("firstname" => "Michael", "lastname" => "Davis", "age" => 43),
//    array("firstname" => "Sarah", "lastname" => "Miller", "age" => 24),
//    array("firstname" => "Patrick", "lastname" => "Miller", "age" => 27)
//  );
//   
//      function cleanData(&$str)
//  {
//    if($str == 't') $str = 'TRUE';
//    if($str == 'f') $str = 'FALSE';
//    if(preg_match("/^0/", $str) || preg_match("/^\+?\d{8,}$/", $str) || preg_match("/^\d{4}.\d{1,2}.\d{1,2}/", $str)) {
//      $str = "'$str";
//    }
//    if(strstr($str, '"')) $str = '"' . str_replace('"', '""', $str) . '"';
//    $str = mb_convert_encoding($str, 'UTF-16LE', 'UTF-8');
//  }
//  
// echo serialize($data);
//echo '<br/><br/><br/>';
// echo json_encode($data);
?>

<?php
global $db;
//$inv_transaction_types = inv_transaction::inv_transaction_types();
//  echo '<pre>';
//  print_r($inv_transaction_types);
//  echo '<pre>';
$query = "SHOW COLUMNS FROM view_path ";
//

//$query="Select * from information_schema.tables where table_name='inv_transaction'";
//$query = "Select TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE'";
//
//$query="select *
//from information_schema.key_column_usage
//where constraint_schema = 'inoideas_erp'" ;
//
////"AND TABLE_NAME LIKE '%inv_transaction%'"
//
$result = $db->result_array($query);
//
////foreach ($result as $object){
//// echo "<br/>Field : ".$object['Field'];
////}
//
echo '<pre>';
print_r($result);
echo '<pre>';




//while($rows = $db->fetch_array($result)){
////  echo '<pre>';
////  print_r($rows);
////  echo '<pre>';
//  echo '<br /> TABLE_NAME]  is : ' . $rows['TABLE_NAME'];
//}
$query1= "ALTER TABLE view_path 
ADD view_id  int(12) AFTER view_path_id";
//
//$query1= "ALTER TABLE view 
//  ADD `logical_settings` TEXT  AFTER description";
//$query1 = "ALTER TABLE view_path ADD view_path_id INT(12) NOT NULL AUTO_INCREMENT KEY FIRST ";
////////$query1="ALTER TABLE inv_transaction ADD UNIQUE INDEX (inv_transaction_number, inventory_id)";
//////// ADD `serial_generation` varchar(50) NOT NULL AFTER serial_uniqueness,
//////// ADD `serial_prefix` varchar(50) NOT NULL AFTER serial_generation,
//////// ADD `serial_starting_number` varchar(50) NOT NULL AFTER serial_prefix ";
////////$query1= "ALTER TABLE inv_transaction 
//////// CHANGE `rev_start_number` rev_number  varchar(256)";
//////////
//////////
$result1 = $db->query($query1);

  $query = "SHOW COLUMNS FROM view_path ";
$result = $db->result_array($query);

  echo '<pre>';
  print_r($result);
  echo '<pre>';
//
//echo '---------------------show columns after change-----------------';
//  $query = "SHOW COLUMNS FROM view ";
//$result = $db->result_array($query);
//
//  echo '<pre>';
//  print_r($result);
//  echo '<pre>';
//$query = "RENAME TABLE mtl_transactions TO inv_transaction ";
//$result = $db->query($query);
//$query = "SHOW COLUMNS FROM category_reference ";
////////
//echo '<h2>New values </h2>' ;
////////$query="Select * from information_schema.tables where table_name='enterprise'";
//$result = $db->query($query);
//while($rows = $db->fetch_array($result)){
//  echo '<br /> field_name is '.$rows['Field'];
//}
//
//echo '<h2>New values </h2>' ;
//
//   $all_columns = array();
//    $all_columns_sql = " SHOW COLUMNS FROM  ". 'inv_transaction' ;
//    $all_columns_result = $db->query($all_columns_sql);
//    if ($all_columns_result && mysql_num_rows($all_columns_result)) {
//   while ($row = $db->fetch_array($all_columns_result)) {
//    array_push($all_columns, $row['Field']);
//   }
//   }
//   print_r($all_columns);
////$query="Select * from information_schema.tables where table_name='enterprise'";
//$result = $db->query($query);
//while($rows = $db->fetch_array($result)){
//  echo '<pre>';
//  print_r($rows);
//  echo '<pre>';
//}
?>
<!--  <select name="inventory_id" id="inventory_id" > 
	 
<?php
//  $inv_transaction_masters= inventory_org::find_all_inv_transaction_master();
//  echo '<pre>';
//  print_r($inv_transaction_masters);
//  echo '<pre>';
//  foreach ($inv_transaction_masters as $key=>$value) {
//    echo '<option value="' . $value->inventory_id .'"';
////    echo $types[$i]->option_line_code == $org->type ? 'selected' : 'NONE';
//    echo '>' . $value->code . ' (inventory id '. $value->inventory_id .') </option>';
//  }
?> 
<option value="" ></option> 
  </select> -->
<!--   end of structure-->

<?php
execution_time();
include_template('footer.inc')
?>


