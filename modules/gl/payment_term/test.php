<?php
include_once('supplier.inc');

$item = new item;


echo "<br/><br/><br/><br/><br/>current page is : ". thisPage_url();

//$item_number = 'buy_03';
////function find_all_assigned_org_ids($item_number){
// global $db;
//	$sql = "SELECT * FROM " .
//					'supplier';
//$result = $db->result_array_assoc($sql);	
//
//$result  = file_reference::find_all();
////$assigned_inventory_orgs_array = [];
//  echo '<pre>';
//  print_r($result);
//  echo '<pre>';

//

?>


<!--<form action="item_download.php" method="POST" name="item_download">
  
  
  <input type="submit" class="button" value="download">
</form>-->

<?php 
global $db;
//$item_types = item::item_types();

        
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
//$query1="ALTER TABLE supplier_bu
//ADD pay_on  varchar(50)   after remittance_advice_email,
//ADD debit_memo_onreturn boolean   after pay_on,
//ADD fob  varchar(256)   after debit_memo_onreturn,
//ADD freight_terms  varchar(256)   after fob,
//ADD transportation  varchar(256)   after freight_terms,
//ADD country_of_origin  varchar(256)   after transportation
// ";
//
//$query1= "ALTER TABLE supplier_site
//  ADD site_tax_country varchar(256) after supplier_site_name,
//	ADD site_tax_reg_no varchar(100) after site_tax_country,
//	ADD site_tax_payer_id varchar(100) after site_tax_reg_no,
//	ADD site_tax_code varchar(100) after site_tax_payer_id";
//	
//	$query1= "ALTER TABLE supplier_bu
//  CHANGE debit_memo_onreturn debit_memo_onreturn_cb boolean";
////
////
//
//$result1 = $db->query($query1);

//$query = "RENAME TABLE item_master TO item ";
//$result = $db->query($query);

$query = "SHOW COLUMNS FROM supplier_bu ";
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