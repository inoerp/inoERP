<?php include_once("../../../include/basics/header.inc"); ?>
<script src="address.js"></script>
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
$query1= "ALTER TABLE address 
  CHANGE  value address text ";
//////
//////$query1="ALTER TABLE page ADD UNIQUE INDEX (page_number, inventory_id)";
//// ADD `serial_generation` varchar(50) NOT NULL AFTER serial_uniqueness,
//// ADD `serial_prefix` varchar(50) NOT NULL AFTER serial_generation,
//// ADD `serial_starting_number` varchar(50) NOT NULL AFTER serial_prefix ";
//$query1= "ALTER TABLE role_path 
// CHANGE `page_id` path_id INT(12) unsigned ";
//////////////
//////////////
$result1 = $db->query($query1);

//$drop_index_query = "ALTER TABLE  `role_path` DROP unique CONSTRAINT role_id ";
//$drop_index_result = $db->result_array($drop_index_query);
//
//$index_query = "SHOW INDEX FROM role_path";
//$index_result = $db->result_array($index_query);
//  echo '<pre>';
//  print_r($index_result);
//  echo '<pre>';

	

$query = "SHOW COLUMNS FROM address";
$result = $db->result_array_assoc($query);
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


