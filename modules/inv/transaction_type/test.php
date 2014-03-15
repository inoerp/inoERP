<?php
include_once('transaction_type.inc');

$transaction_type = new transaction_type;
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
//$transaction_type_types = transaction_type::transaction_type_types();
//  echo '<pre>';
//  print_r($transaction_type_types);
//  echo '<pre>';
$query = "SHOW COLUMNS FROM transaction_type ";
////
////$query="Select * from information_schema.tables where table_name='transaction_type'";
//
////$query="select *
////from information_schema.key_column_usage
////where constraint_schema = 'inoideas_erp' AND TABLE_NAME LIKE '%transaction_type%'";
//
$result = $db->query($query);
while($rows = $db->fetch_array($result)){
//  echo '<pre>';
//  print_r($rows);
//  echo '<pre>';
  echo '<br /> field is : ' . $rows['Field'];
}
//$query1= "ALTER TABLE transaction_type 
//  ADD `status` VARCHAR(25) NOT NULL AFTER ef_id";
//
//$query1="ALTER TABLE transaction_type ADD UNIQUE INDEX (transaction_type_number, inventory_id)";
// ADD `serial_generation` varchar(50) NOT NULL AFTER serial_uniqueness,
// ADD `serial_prefix` varchar(50) NOT NULL AFTER serial_generation,
// ADD `serial_starting_number` varchar(50) NOT NULL AFTER serial_prefix ";
$query1= "ALTER TABLE transaction_type 
 CHANGE `rev_start_number` rev_number  varchar(256)";
//
//
$result1 = $db->query($query1);
//$query = "RENAME TABLE transaction_type_master TO transaction_type ";
//$result = $db->query($query);
$query = "SHOW COLUMNS FROM transaction_type ";
//
echo '<h2>New values </h2>' ;
////$query="Select * from information_schema.tables where table_name='enterprise'";
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
//  $transaction_type_masters= inventory_org::find_all_transaction_type_master();
//  echo '<pre>';
//  print_r($transaction_type_masters);
//  echo '<pre>';
//  foreach ($transaction_type_masters as $key=>$value) {
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


