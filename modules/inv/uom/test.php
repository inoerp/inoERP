<?php
require_once ('uom.inc');
global $page, $per_page;
//get_pageNo_perPage($page, $per_page);
echo "<br>page is : $page </br >";
echo "per page is : $per_page </br >";

//echo '<br />$search_array';
//echo  '<pre>';
//print_r($search_array);
//echo  '<pre>';

//$locator_structure_array = locator::locator_structure();
//echo  '<pre>';
//print_r($locator_structure_array);
//echo  '<pre>';

//$subinventory = new subinventory;
//$subinventory = subinventory::find_all();
//
//echo '<pre>';
//print_r($subinventory);
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
//$subinventory_types = subinventory::subinventory_types();
//  echo '<pre>';
//  print_r($subinventory_types);
//  echo '<pre>';
//$query = "SHOW COLUMNS FROM subinventory ";
////
////$query="Select * from information_schema.tables where table_name='subinventory'";
//
////$query="select *
////from information_schema.key_column_usage
////where constraint_schema = 'inoideas_erp' AND TABLE_NAME LIKE '%subinventory%'";
//
//$result = $db->query($query);
//while($rows = $db->fetch_array($result)){
////  echo '<pre>';
////  print_r($rows);
////  echo '<pre>';
//  echo '<br /> field is : ' . $rows['Field'];
//}
//$query1= "ALTER TABLE subinventory 
//  ADD `status` VARCHAR(25) NOT NULL AFTER ef_id";
//
//$query1="ALTER TABLE subinventory ADD UNIQUE INDEX (subinventory_number, inventory_id)";
// ADD `serial_generation` varchar(50) NOT NULL AFTER serial_uniqueness,
// ADD `serial_prefix` varchar(50) NOT NULL AFTER serial_generation,
//// ADD `serial_starting_number` varchar(50) NOT NULL AFTER serial_prefix ";
//$query1= "ALTER TABLE uom 
// CHANGE `rev_enabled` rev_enabled_cb boolean DEFAULT NULL 
// ";
//////////////
//////////////
//$result1 = $db->query($query1);
//////$query = "RENAME TABLE subinventory_master TO subinventory ";
//////$result = $db->query($query);
$query = "SELECT * FROM uom LIMIT 5 OFFSET 0 ";
//////
////echo '<h2>New values </h2>' ;
////$query="Select * from information_schema.tables where table_name='enterprise'";
////$result = $db->query($query);
////while($rows = $db->fetch_array($result)){
////  echo '<br /> field_name is '.$rows['Field'];
////}
echo '<h2>New values </h2>' ;
//$query="Select * from information_schema.tables where table_name='enterprise'";
$result = $db->result_array_assoc($query);
  echo '<pre>';
  print_r($result);
  echo '<pre>';
//while($rows = $db->fetch_array($result)){
//  echo '<pre>';
//  print_r($result);
//  echo '<pre>';
//}


?>
<!--  <select name="inventory_id" id="inventory_id" > 
   
<?php
//  $subinventory_masters= inventory_org::find_all_subinventory_master();
//  echo '<pre>';
//  print_r($subinventory_masters);
//  echo '<pre>';
//  foreach ($subinventory_masters as $key=>$value) {
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


