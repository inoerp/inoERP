<?php include_once("../../include/basics/header.inc"); 

$string = 'echo "Hello";';
	ob_start();
	echo eval($string);
	$evaled_string = ob_get_contents();
	ob_end_clean();
 	echo $evaled_string;
	
	echo '<br> end of eval testing';
	
global $db;
$sql="SELECT content.content_id as content_id, content.subject as subject from content, c_forum  where c_forum.content_id=content.content_id order by content.creation_date desc LIMIT 0, 10";
$result = $db->find_by_sql($sql);

echo '<ul class="forum_list">';
foreach($result as $records){
echo '<pre>';
    print_r($records);
}

//if(!empty($_POST))    {
//echo '<pre>';
//    print_r($_POST);
//    echo '<pre>';
//}
?>
<?php

//$block = new block_content;
//$block = block_content::find_all();
//$x = 10;
//$block_content_deocded = '  value of x is $x ';
//
//eval("\$block_content = \"$block_content_deocded\";");
//
//echo $block_content;

//$sql =" DELETE FROM block_content WHERE block_id=0 ";
//$db->query($sql);
//
//echo '<pre>';
//print_r($block);
//echo '<pre>';

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
//$block_types = block::block_types();
//  echo '<pre>';
//  print_r($block_types);
//  echo '<pre>';
//$query = "SHOW COLUMNS FROM block ";
////
////$query="Select * from information_schema.tables where table_name='block'";
//
////$query="select *
////from information_schema.key_column_usage
////where constraint_schema = 'inoideas_erp' AND TABLE_NAME LIKE '%block%'";
//
//$result = $db->query($query);
//while($rows = $db->fetch_array($result)){
////  echo '<pre>';
////  print_r($rows);
////  echo '<pre>';
//  echo '<br /> field is : ' . $rows['Field'];
//}
//$query1= "ALTER TABLE block 
//  ADD `status` VARCHAR(25) NOT NULL AFTER ef_id";
//
//$query1="ALTER TABLE block ADD UNIQUE INDEX (block_number, inventory_id)";
// ADD `serial_generation` varchar(50) NOT NULL AFTER serial_uniqueness,
// ADD `serial_prefix` varchar(50) NOT NULL AFTER serial_generation,
// ADD `serial_starting_number` varchar(50) NOT NULL AFTER serial_prefix ";
//$query1= "ALTER TABLE block 
// CHANGE `allow_negative_balance` allow_negative_balance_cb TINYINT(1) 
// ";
//////////
//////////
//$result1 = $db->query($query1);
//////$query = "RENAME TABLE block_master TO block ";
//////$result = $db->query($query);
//$query = "SHOW COLUMNS FROM block ";
////////
//////echo '<h2>New values </h2>' ;
//////$query="Select * from information_schema.tables where table_name='enterprise'";
//////$result = $db->query($query);
//////while($rows = $db->fetch_array($result)){
//////  echo '<br /> field_name is '.$rows['Field'];
//////}
//echo '<h2>New values </h2>' ;
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
//  $block_masters= inventory_org::find_all_block_master();
//  echo '<pre>';
//  print_r($block_masters);
//  echo '<pre>';
//  foreach ($block_masters as $key=>$value) {
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


