<?php include_once("../../../include/basics/header.inc"); ?>
<script src="path.js"></script>
<?php
//include_once("upload.php"); 

//global $page, $per_page;
////get_pageNo_perPage($page, $per_page);
//echo "<br>page is : $page </br >";
//echo "per page is : $per_page </br >";
//
////echo '<br />$search_array';
//echo  '<pre>';
//print_r($search_array);
//echo  '<pre>';

$path = new path;
//$all_pages = page::page_page();
//page::all_page_summary();
//$role_id = '261';
//$role_path_object = role_path::find_by_roleId($role_id);

echo '<pre>';
print_r($_SESSION);
echo '<pre>';

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

//$sql="
//CREATE TABLE IF NOT EXISTS `file` (
//  `file_id` int(12) unsigned NOT NULL auto_increment,
//  `file_name` varchar(50) NOT NULL,
//  `file_size` varchar(50) NOT NULL,
//  `file_type` varchar(50) NOT NULL,
//  `description` varchar(200) default NULL,
//  `reference_table` varchar(50) default NULL,
//  `reference_id` int(12) default NULL,
//  `created_by` varchar(40) NOT NULL default '',
//  `creation_date` varchar(50) default NULL,
//  `last_update_by` varchar(40) NOT NULL default '',
//  `last_update_date` varchar(50) default NULL,
//  PRIMARY KEY  (`file_id`)
//) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ; 
//";
//$result = $db->query($sql);
//
////$page_types = page::page_types();
////  echo '<pre>';
////  print_r($page_types);
////  echo '<pre>';

////////
////$query="Select * from information_schema.tables where table_name='path'";
//////
////////$query="select *
////////from information_schema.key_column_usage
////////where constraint_schema = 'inoideas_erp' AND TABLE_NAME LIKE '%page%'";
//////
//while($rows = $db->fetch_array($result)){
////  echo '<pre>';
////  print_r($rows);
////  echo '<pre>';
//  echo '<br /> field is : ' . $rows['Field'];
//}
//
//$query1= "UPDATE path 
//  SET parent_id='0'
//WHERE path_id='85'  
//";
//$query1= "ALTER TABLE path 
//  ADD  id_column_name VARCHAR(256) NULL  AFTER module ";
//////
//////$query1="ALTER TABLE page ADD UNIQUE INDEX (page_number, inventory_id)";
//// ADD `serial_generation` varchar(50) NOT NULL AFTER serial_uniqueness,
//// ADD `serial_prefix` varchar(50) NOT NULL AFTER serial_generation,
//// ADD `serial_starting_number` varchar(50) NOT NULL AFTER serial_prefix ";
//$query1= "ALTER TABLE role_path 
// CHANGE `page_id` path_id INT(12) unsigned ";
//////////////
//////////////
//$result1 = $db->query($query1);

$drop_index_query = "ALTER TABLE  `role_path` DROP unique CONSTRAINT role_id ";
$drop_index_result = $db->result_array($drop_index_query);

$index_query = "SHOW INDEX FROM role_path";
$index_result = $db->result_array($index_query);
  echo '<pre>';
  print_r($index_result);
  echo '<pre>';

	

$query = "SHOW COLUMNS FROM role_path";
$result = $db->result_array($query);
  echo '<pre>';
  print_r($result);
  echo '<pre>';

//////$query = "RENAME TABLE page_master TO page ";
//////$result = $db->query($query);
//$query = "SHOW COLUMNS FROM page ";
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
//  $page_masters= inventory_org::find_all_page_master();
//  echo '<pre>';
//  print_r($page_masters);
//  echo '<pre>';
//  foreach ($page_masters as $key=>$value) {
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


