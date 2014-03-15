<?php
include_once('uom.inc');

$uom = new uom;
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
//$uom_types = uom::uom_types();
//  echo '<pre>';
//  print_r($uom_types);
//  echo '<pre>';

        
//$query = "SHOW COLUMNS FROM uom ";
////
////$query="Select * from information_schema.tables where table_name='uom'";
//
////$query="select *
////from information_schema.key_column_usage
////where constraint_schema = 'inoideas_erp' AND TABLE_NAME LIKE '%uom%'";
//
//$result = $db->query($query);
//while($rows = $db->fetch_array($result)){
////  echo '<pre>';
////  print_r($rows);
////  echo '<pre>';
//  echo '<br /> field is : ' . $rows['Field'];
//}

//$query1= "ALTER TABLE uom 
//  ADD `inventory_id` int(12) NOT NULL AFTER uom_id";
//
//$query1="ALTER TABLE uom ADD UNIQUE INDEX (uom_number, inventory_id)";
  
// ADD `serial_generation` varchar(50) NOT NULL AFTER serial_uniqueness,
// ADD `serial_prefix` varchar(50) NOT NULL AFTER serial_generation,
// ADD `serial_starting_number` varchar(50) NOT NULL AFTER serial_prefix ";

//$query1= "ALTER TABLE uom 
////  CHANGE `deffered_cogs_ac` deferred_cogs_ac  varchar(256)";
//
//

//$result1 = $db->query($query1);

//$query = "RENAME TABLE uom_master TO uom ";
//$result = $db->query($query);

//$query = "SHOW COLUMNS FROM uom ";
//
//echo '<h2>New values </h2>' ;
////$query="Select * from information_schema.tables where table_name='enterprise'";
//$result = $db->query($query);
//while($rows = $db->fetch_array($result)){
//  echo '<br /> field_name is '.$rows['Field'];
//}
//echo '<h2>New values </h2>' ;
////$query="Select * from information_schema.tables where table_name='enterprise'";
//$result = $db->query($query);
//while($rows = $db->fetch_array($result)){
//  echo '<pre>';
//  print_r($rows);
//  echo '<pre>';
//}

uom::uom_page();

?>
<!--  <select name="inventory_id" id="inventory_id" > 
   
  <?php
//  $uom_masters= inventory_org::find_all_uom_master();
  
//  echo '<pre>';
//  print_r($uom_masters);
//  echo '<pre>';
  
//  foreach ($uom_masters as $key=>$value) {
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
include_template('footer.inc') ?>