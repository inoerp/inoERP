<?php
include_once('item.inc');

$item = new item;

//$all_master_orgs = org::find_all_item_master();
//	 $all_master_orgs_array = (array)$all_master_orgs;
	$sql = "SELECT org.org_id FROM org, inventory " .
					" WHERE org.type = 'INVENTORY_ORG'
             AND inventory.org_id=org.org_id
             AND inventory.item_master_cb=1 ";
	$result_array = $db->result_array_assoc($sql);
		
$mas = 7;
	 echo '<pre>';
	 print_r($result_array[0]);
	 if(in_array($mas, $result_array[0])){
		echo "<br/> in MAS 7" ;
	 }
	 
//$item_number = 'buy_03';
//function find_all_assigned_org_ids($item_number){
// global $db;
//	$sql = "SELECT org_id FROM " .
//					'item' .
//					" where item_number= '{$item_number}' ";
//$result = $db->result_array_assoc($sql);	
//$assigned_inventory_orgs_array = [];
//
//foreach($result as $orgs ){
// $assigned_inventory_orgs_array[] = $orgs['org_id'];
//}
//
//return $assigned_inventory_orgs_array;
// }
//
//$all_inventory = org::find_all_inventory();
//$assigned_inventory_orgIds = find_all_assigned_org_ids($item_number);
//$all_inventory_statement = "<ul>";
//foreach ($all_inventory as $org_array){
// $all_inventory_statement .= "<li><label>$org_array->org : </label>";
//  if(in_array($org_array->org_id,$assigned_inventory_orgIds)){
//	$value = 1;
// }else{
//	$value = "";
// }
//  $all_inventory_statement .= form::checkBox_field('assigned_orgs', $value, '', '');
//	$all_inventory_statement .= "</li>";
//}
//$all_inventory_statement .="</ul>";
//
//echo $all_inventory_statement;

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


<!--<form action="item_download.php" method="POST" name="item_download">
  
  <input type="hidden"  name="data" value="<?php print base64_encode(serialize($data)) ?>" >
  <input type="submit" class="button" value="download">
</form>-->

<?php 
//global $db;
//$item_types = item::item_types();
//  echo '<pre>';
//  print_r($item_types);
//  echo '<pre>';

        
//$query = "SHOW COLUMNS FROM item ";
//
//$query="Select * from information_schema.tables where table_name='item'";

//$query="select *
//from information_schema.key_column_usage
//where constraint_schema = 'inoideas_erp' AND TABLE_NAME LIKE '%item%'";
//
//$result = $db->query($query);
//while($rows = $db->fetch_array($result)){
//  echo '<pre>';
//  print_r($rows);
//  echo '<pre>';
//}

//$query1= "ALTER TABLE item 
//  ADD `inventory_id` int(12) NOT NULL AFTER item_id";
//
//$query1="ALTER TABLE item ADD UNIQUE INDEX (item_number, inventory_id)";
  
// ADD `serial_generation` varchar(50) NOT NULL AFTER serial_uniqueness,
// ADD `serial_prefix` varchar(50) NOT NULL AFTER serial_generation,
// ADD `serial_starting_number` varchar(50) NOT NULL AFTER serial_prefix ";

//$query1= "ALTER TABLE item 
//  CHANGE `description` item_description  varchar(256)";
////
////
//
//$result1 = $db->query($query1);

//$query = "RENAME TABLE item_master TO item ";
//$result = $db->query($query);

//$query = "SHOW COLUMNS FROM item ";
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



?>
<!--  <select name="inventory_id" id="inventory_id" > 
   
  <?php
//  $item_masters= inventory_org::find_all_item_master();
  
//  echo '<pre>';
//  print_r($item_masters);
//  echo '<pre>';
  
//  foreach ($item_masters as $key=>$value) {
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