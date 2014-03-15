<?php
ini_set('display_errors',1);
error_reporting(E_ALL);
global $dbc;
global $db;
include_once("../../../include/function/loader.inc"); 
$po = new po_header();
echo 'PO details of id 65<pre>';
print_r($po->find_by_id(65));
//echo "<br>1 ".rtrim('xyz-', '-');
//echo "<br>2 " .rtrim('xyz- ', '- ');
// $query = " UPDATE gl_calendar SET calendar_type = 'MONTH' WHERE calendar_type = 421";
// $dbc->execute($query);
//echo '<pre>';
// print_r(gl_calendar::find_all());
// print_r(coa_combination::find_all());
//$query = " alter table gl_calendar 
//          modify column gl_calendar_id int(12) auto_increment " ;
//$query= " ALTER TABLE gl_calendar 
//CHANGE `calendar_type_id` calendar_type varchar(50) NOT NULL" ;
//$dbc->ddlexecute($query);
//
//print_r($db->show_allColumn_from_table('gl_calendar'));
//print_r($db->show_allColumn_from_table('path'));



//$query1= " ALTER TABLE gl_calendar 
//CHANGE `coa_id` gl_calendar_id int(12) NOT NULL,
//CHANGE `natural_account` calendar_type_id int(12),
//CHANGE `segment2` from_date date,
//CHANGE `inter_company` year int(12),
//CHANGE `segment1` quarter int(4),
//CHANGE `segment3` to_date date,
//CHANGE `segment4` name varchar(256),
//CHANGE `coa_structure_id` adjustment_cb boolean, 
//CHANGE `field1` name_prefix varchar(20)
//"; 
//echo "sql is $query1";
//$dbc->ddlexecute($query1);
////$prepare = $dbc->connection->prepare($query1);

//$sql = "CREATE TABLE gl_calendar LIKE coa" ;
////$query = " UPDATE coa_combination SET coa_structure_id=82 WHERE coa_id=1 ";
////echo " query is $query";
//$dbc->ddlexecute($sql);
//$prepare->execute();
//
//echo '<pre>';
//// print_r(coa::find_by_structure(80));
// print_r(coa_combination::find_all());
//$string = 'echo "Hello";';
//	ob_start();
//	echo eval($string);
//	$evaled_string = ob_get_contents();
//	ob_end_clean();
// 	echo $evaled_string;
//	
//	echo '<br> end of eval testing';
//	
//global $db;
//$sql="SELECT content.content_id as content_id, content.subject as subject from content, c_forum  where c_forum.content_id=content.content_id order by content.creation_date desc LIMIT 0, 10";
//$result = $db->find_by_sql($sql);
//
//echo '<ul class="forum_list">';
//foreach($result as $records){
//echo '<pre>';
//    print_r($records);
//}


//	$sql = " SELECT * FROM option_header ";
//	$sql .= " WHERE option_assignments IS NOT NULL ";
//	$result = $db->find_by_sql($sql);
//	
//	echo '<pre>';
//print_r($result);


//$structure = option_header::find_by_name('COA01');
//echo '<br><br><br><br>strucrte is <pre>';
//
//$segments = option_line::find_by_option_id($structure->option_header_id);
//print_r($segments);
//



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
global $dbc;
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
//$query1= "ALTER TABLE gl_calendar 
//  ADD `field1` VARCHAR(50) AFTER segment4,
//	ADD `field2` VARCHAR(50) AFTER field1,
//	ADD `field3` VARCHAR(50) AFTER field2,
//	ADD `field4` VARCHAR(50) AFTER field3,
//	ADD `field5` VARCHAR(50) AFTER field4,
//	ADD `field6` VARCHAR(50) AFTER field5,
//	ADD `field7` VARCHAR(50) AFTER field6,
//	ADD `field8` VARCHAR(50) AFTER field7 ";
//
//$dbc->ddlexecute($query1);

//$sql_fields = " SHOW COLUMNS FROM gl_calendar ";
//$field_array = $dbc->execute($sql_fields);
////$prepare = $dbc->connection->prepare($sql_fields);
////$prepare->execute();
//$field_array = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);

echo '<br><br><br><br>Shwoing columns<pre>';
print_r($db->show_column_from_table('gl_calendar'));

//$prepare = $dbc->connection->prepare($query1);
//$prepare->execute();
//$result = $db->query_by_sql($query1);
//
//$query1="ALTER TABLE block ADD UNIQUE INDEX (block_number, inventory_id)";
// ADD `serial_generation` varchar(50) NOT NULL AFTER serial_uniqueness,
// ADD `serial_prefix` varchar(50) NOT NULL AFTER serial_generation,
// ADD `serial_starting_number` varchar(50) NOT NULL AFTER serial_prefix ";

// ";
//////////
//////////

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


