<?php
require_once ('onhand.inc');
global $page, $per_page, $db;
//get_pageNo_perPage($page, $per_page);
echo "<br>page is : $page </br >";
echo "per page is : $per_page </br >";

//echo '<br />$search_array';
//echo  '<pre>';
//print_r($search_array);
//echo  '<pre>';

//$sql = "Select * from onhand_v";
//$result = $db->query($sql);
//
//while($row = $db->fetch_array($result)){
//echo  '<pre>';
//print_r($row);
//echo  '<pre>';
//}

$onhand = new onhand;
$onhands = onhand::find_all_v();

echo '<pre>';
print_r($onhands);
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
// ADD `serial_starting_number` varchar(50) NOT NULL AFTER serial_prefix ";
//$query1= "ALTER TABLE subinventory 
// CHANGE `allow_negative_balance` allow_negative_balance_cb TINYINT(1) 
// ";
//$query1="CREATE OR REPLACE VIEW onhand_v
//(onhand_id, item_number, item_description, org_name, subinventory, locator,
//uom_id,onhand, item_id, org_id, subinventory_id, 
//locator_id, lot_id, serial_id, reservable_onhand, 
//transactable_onhand, lot_status, serial_status,  
//secondary_uom_id, onhand_status, ef_id, created_by, 
//creation_date, last_update_by, last_update_date)
//AS
//SELECT onhand.onhand_id, 
//item.item_number, item.description, org.name, subinventory.subinventory, locator.locator,
//onhand.uom_id,onhand.onhand,
//onhand.item_id, onhand.org_id, onhand.subinventory_id, 
//onhand.locator_id, onhand.lot_id, onhand.serial_id, onhand.reservable_onhand, 
//onhand.transactable_onhand, onhand.lot_status, onhand.serial_status,  
//onhand.secondary_uom_id, onhand.onhand_status, onhand.ef_id, onhand.created_by, 
//onhand.creation_date, onhand.last_update_by, onhand.last_update_date
//
//FROM onhand 
//LEFT JOIN item ON onhand.item_id = item.item_id
//LEFT JOIN org ON onhand.org_id = org.org_id
//LEFT JOIN subinventory ON onhand.subinventory_id = subinventory.subinventory_id
//LEFT JOIN locator ON onhand.locator_id = locator.locator_id
//";
//
//$result1 = $db->query($query1);
//////$query = "RENAME TABLE subinventory_master TO subinventory ";
//////$result = $db->query($query);
$query = "SHOW COLUMNS FROM onhand_v ";
//////
//echo '<h2>New values </h2>' ;
//$query="Select * from information_schema.tables where table_name='enterprise'";
$result = $db->query($query);
while($rows = $db->fetch_array($result)){
  echo '<br /> field_name is '.$rows['Field'];
}
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


