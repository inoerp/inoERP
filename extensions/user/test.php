<?php
include_once('user.inc');
global $db;
//$item = new item;
//
//
//echo "<br/><br/><br/><br/><br/>current page is : ". thisPage_url();
//
//echo "<br/>decimal of 1 is : ". ino_showDecimal(1);
//echo "<br/>decimal of 1.1 is : ". ino_showDecimal(1.1);
//echo "<br/>decimal of 1.12 is : ". ino_showDecimal(1.12);
//echo "<br/>decimal of 1.123 is : ". ino_showDecimal(1.123);
//echo "<br/>decimal of 1.1234 is : ". ino_showDecimal(1.1234);
//echo "<br/>decimal of 1.12345 is : ". ino_showDecimal(1.12345);
//echo "<br/>decimal of 1.10 is : ". ino_showDecimal(1.10);
//echo "<br/>decimal of 66.00000 is : ". ino_showDecimal(66.00000,'.');
//echo "<br/>decimal of 1.1001 is : ". ino_showDecimal(1.1001);
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
//
//$query1 = " CREATE TABLE user_resource_assignment(
//  user_resource_assignment_id int(12) NOT NULL AUTO_INCREMENT,
//  user_id int(12) NOT NULL,
//	cost_type_id int(12) NOT NULL,
//	resource_id int(12) NOT NULL,
//  created_by varchar(256),
//  creation_date date,
//  last_update_by varchar(256),
//  last_update_date date,
//	PRIMARY KEY ( user_resource_assignment_id )
//	)";
//
//
//$result1 = $db->query($query1);
//
//$query11 = " CREATE TABLE user(
//  user_id int(12) NOT NULL AUTO_INCREMENT,
//	user varchar(20) NOT NULL,
//	standard_operation_id int(12) NOT NULL,
//	count_point_cb boolean,
//	auto_charge_cb boolean,
//	backflush_cb boolean,
//  created_by varchar(256),
//  creation_date date,
//  last_update_by varchar(256),
//  last_update_date date,
//	PRIMARY KEY ( user_id )
//	)";
//
//
//$result11 = $db->query($query11);
//
//$query2 = "ALTER TABLE bom_routing_detail
// 	CHANGE `usage_quantity` usage int(12)";
////	CHANGE `bom_line_id` bom_routing_detail_id int(12),
////	CHANGE `bom_header_id` bom_routing_line_id int(12),
////	CHANGE `bom_sequence` bom_routing_header_id int(12),
////	CHANGE `operation_sequence` resource_sequence int(12),
////		CHANGE `component_item_id` charge_basis varchar(50),
////	CHANGE `usage_basis` resource_id int(12),
////		CHANGE `auto_request_material_cb`  schedule varchar(50),
////	CHANGE `planning_percentage` assigned_units int(12),
////	CHANGE `include_in_cost_rollup_cb` twenty_four_hr_cb boolean,
////		CHANGE `wip_supply_type` charge_type varchar(50),
////	CHANGE `supply_sub_inventory` standard_rate_cb boolean";
//$result2 = $db->query($query2);

//$query3= "ALTER TABLE bom_routing_detail
//ADD `standard_operation_id` int(12) AFTER routing_sequence";
////ADD `completion_subinventory` int(12) AFTER description,
////	ADD `completion_locator` int(12) AFTER completion_subinventory" ;
//$result3 = $db->query($query3);
//$query1="ALTER TABLE resource
//ADD standard_rate_cb  boolean after costed_cb";
//$result1 = $db->query($query1);
//
//ADD debit_memo_onreturn boolean   after pay_on,
//ADD fob  varchar(256)   after debit_memo_onreturn,
//ADD freight_terms  varchar(256)   after fob,
//ADD transportation  varchar(256)   after freight_terms,
//ADD country_of_origin  varchar(256)   after transportation
// ";
//
$query4= "ALTER TABLE user
change `user_name` username varchar(50)";
//	
$result4 = $db->query($query4);
//	
//	$query1= "ALTER TABLE po_detail
//  ADD ship_to_inventory varchar(50)";
//////
//////
////
//$query1="
//	 CREATE OR REPLACE VIEW all_po_v
//(
//po_header_id, bu_org_id, po_type, po_number, supplier_id, supplier_site_id, buyer, currency, header_amount, po_status,
//payment_term_id,
//supplier_name, supplier_number,
//supplier_site_name, supplier_site_number,
//payment_term, payment_term_description,
//po_line_id, line_type, line_number,	item_id, item_description, line_description, line_quantity, unit_price, line_price,
//item_number, uom_id, item_status,
//po_detail_id, shipment_number, ship_to_id, sub_inventory_id, locator_id, requestor, quantity,
//need_by_date, promise_date, 
//ship_to_org
//)
//AS
//SELECT 
//po_header.po_header_id, po_header.bu_org_id, po_header.po_type, po_header.po_number, po_header.supplier_id, 
//po_header.supplier_site_id, po_header.buyer, po_header.currency, po_header.header_amount, po_header.po_status,
//po_header.payment_term_id,
//supplier.supplier_name, supplier.supplier_number,
//supplier_site.supplier_site_name, supplier_site.supplier_site_number,
//payment_term.payment_term, payment_term.description,
//po_line.po_line_id, po_line.line_type, po_line.line_number,	po_line.item_id, po_line.item_description, po_line.line_description, 
//po_line.line_quantity, po_line.unit_price, po_line.line_price,
//item.item_number, item.uom_id, item.item_status,
//po_detail.po_detail_id, po_detail.shipment_number, po_detail.ship_to_inventory, po_detail.sub_inventory_id, 
//po_detail.locator_id, po_detail.requestor, po_detail.quantity, po_detail.need_by_date, po_detail.promise_date,
//org.org
//
//FROM po_header 
//LEFT JOIN supplier ON po_header.supplier_id = supplier.supplier_id
//LEFT JOIN supplier_site ON po_header.supplier_site_id = supplier_site.supplier_site_id
//LEFT JOIN payment_term ON po_header.payment_term_id = payment_term.payment_term_id
//LEFT JOIN po_line ON po_header.po_header_id = po_line.po_header_id
//LEFT JOIN item ON po_line.item_id = item.item_id
//LEFT JOIN po_detail ON po_line.po_line_id = po_detail.po_line_id
//LEFT JOIN org ON po_detail.ship_to_inventory = org.org_id
//
//";
//$result1 = $db->query($query1);
//$query = "RENAME TABLE po_shipment TO po_detail ";
//$result2 = $db->query($query2);
//
$query = "SHOW COLUMNS FROM user ";
//$query = "Select *  FROM all_po_v ";
////
//echo '<h2>New values </h2>' ;
//
////echo "<pre>"; 
////print_r(po_header::find_all());
////$query="Select * from information_schema.tables where table_name='enterprise'";
$result = $db->query($query);
////
//echo "<pre>";
//print_r($result);
//echo "<pre>";
////
while ($rows = $db->fetch_array($result)) {
 echo '<br /> field_name is ' . $rows['Field'];
// echo "<pre>";
// print_r($rows);
}

echo "<br/><br/><b><u>BOM Routing Line</b></u></br>";
$query = "SHOW COLUMNS FROM bom_routing_line ";
//$query = "Select *  FROM all_po_v ";
////
//echo '<h2>New values </h2>' ;
//
////echo "<pre>"; 
////print_r(po_header::find_all());
////$query="Select * from information_schema.tables where table_name='enterprise'";
$result = $db->query($query);
////
//echo "<pre>";
//print_r($result);
//echo "<pre>";
////
while ($rows = $db->fetch_array($result)) {
 echo '<br /> field_name is ' . $rows['Field'];
// echo "<pre>";
// print_r($rows);
}

echo "<br/><br/><b><u>BOM Detail Line</b></u></br>";
$query = "SHOW COLUMNS FROM bom_routing_detail ";
//$query = "Select *  FROM all_po_v ";
////
//echo '<h2>New values </h2>' ;
//
////echo "<pre>"; 
////print_r(po_header::find_all());
////$query="Select * from information_schema.tables where table_name='enterprise'";
$result = $db->query($query);
////
//echo "<pre>";
//print_r($result);
//echo "<pre>";
////
while ($rows = $db->fetch_array($result)) {
 echo '<br /> field_name is ' . $rows['Field'];
// echo "<pre>";
// print_r($rows);
}
//echo '<h2>New values </h2>' ;
//$query="Select * from information_schema.tables where table_name='po_header'";
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
include_template('footer.inc')
?>