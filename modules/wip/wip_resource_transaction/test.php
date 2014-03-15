<?php
// current directory
//echo getcwd() . "\n";
//
//phpinfo();
include_once('wip_resource_transaction.inc');

$all = wip_resource_transaction::find_by_id(31);

echo '<pre>';
print_r($all);

$all = wip_resource_transaction::find_by_id(32);

echo '<pre>';
print_r($all);

//$wip_wo_header_id = 25;
//
//$wip_wo_routing_line_from = wip_wo_routing_line::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, 10);
//$wip_wo_routing_line_to = wip_wo_routing_line::find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, 20);
//
////$class = wip_resource_transaction::find_all();
//echo '<pre>';
//print_r($wip_wo_routing_line_from);
//print_r($wip_wo_routing_line_to);
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
//$query1 = " CREATE TABLE wip_resource_transaction_resource_assignment(
//  wip_resource_transaction_resource_assignment_id int(12) NOT NULL AUTO_INCREMENT,
//  wip_resource_transaction_id int(12) NOT NULL,
//	cost_type_id int(12) NOT NULL,
//	resource_id int(12) NOT NULL,
//  created_by varchar(256),
//  creation_date date,
//  last_update_by varchar(256),
//  last_update_date date,
//	PRIMARY KEY ( wip_resource_transaction_resource_assignment_id )
//	)";
//
//
//$result1 = $db->query($query1);
//$query11 = " CREATE TABLE wip_resource_transaction_rate_assignment(
//  wip_resource_transaction_rate_assignment_id int(12) NOT NULL AUTO_INCREMENT,
//  wip_resource_transaction_id int(12) NOT NULL,
//	department_id int(12) NOT NULL,
//	default_basis int(12) NOT NULL,
//	rate int(12) NOT NULL,
//  created_by varchar(256),
//  creation_date date,
//  last_update_by varchar(256),
//  last_update_date date,
//	PRIMARY KEY ( wip_resource_transaction_rate_assignment_id )
//	)";
//
//
//$result11 = $db->query($query11);
//$query2= "ALTER TABLE wip_resource_transaction 
//CHANGE `wip_wo_move_transaction_id` wip_resource_transaction_id int(12)";
//////////	CHANGE `delivered_quantity` delivered_quantity int(12),
//////////	CHANGE `invoiced_quantity` invoiced_quantity int(12),
//////////	CHANGE `paid_quantity` paid_quantity int(12)";
//$result2 = $db->query($query2);
//$query2= "ALTER TABLE wip_resource_transaction_routing_detail 
//  CHANGE `lead_time_percentage` start_date date,
//	CHANGE `effective_start_date` completion_date date,
//	CHANGE `effective_end_date` queue_quantity int(12),
//	CHANGE `eco_number` running_quantity int(12),
//	CHANGE `eco_implemented_cb` rejected_quantity int(12),
//		CHANGE `include_in_rollup_cb` scrapped_quantity int(12),
//	CHANGE `referenced_cb` tomove_quantity int(12),
//	CHANGE `cumm_yield` completed_quantity int(12),
//	CHANGE `ef_id` progress_percentage int(12)";
//////	CHANGE `accepted_quantity` accepted_quantity int(12),
//////	CHANGE `delivered_quantity` delivered_quantity int(12),
//////	CHANGE `invoiced_quantity` invoiced_quantity int(12),
//////	CHANGE `paid_quantity` paid_quantity int(12)";
//$result2 = $db->query($query2);
//
//$query3= "ALTER TABLE wip_resource_transaction_bom 
//  ADD `required_quantity` int(12) AFTER supply_locator,
//	ADD `issued_quantity` int(12) AFTER required_quantity" ;
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
//$query1= "ALTER TABLE supplier_site
//  ADD site_tax_country varchar(256) after supplier_site_name,
//	ADD site_tax_reg_no varchar(100) after site_tax_country,
//	ADD site_tax_payer_id varchar(100) after site_tax_reg_no,
//	ADD site_tax_code varchar(100) after site_tax_payer_id";
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
//$result3 = $db->query($query3);
//
echo "<h2>MOVE TRNX Lines</h2>";
$query = "SHOW COLUMNS FROM wip_resource_transaction ";
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
// echo '<br /> field_name is ' . $rows['Field'];
 echo "<pre>";
 print_r($rows);
}

//echo "<h2>Drop Index</h2>";
//$query = "ALTER TABLE wip_resource_transaction DROP INDEX wo_number ";
//$result = $db->query($query);
//
//echo "<h2>Index</h2>";
//$query = "SHOW INDEX FROM wip_resource_transaction ";
//$result = $db->query($query);
////
//while ($rows = $db->fetch_array($result)) {
// echo "<pre>";
// print_r($rows);
//}



//
//while ($rows = $db->fetch_array($result)) {
// echo '<br /> field_name is ' . $rows['Field'];
//}
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