<?php

class hr_expense_v extends dbObject {

 public static $table_name = "hr_expense_all_v";
 public static $primary_column = "hr_expense_header_id";
 public $field_a = [
		 'hr_expense_header_id',
		 'bu_org_id',
		 'document_type',
		 'so_number',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'sales_person',
		 'document_currency',
		 'header_amount',
		 'so_status',
		 'payment_term_id',
		 'customer_name',
		 'customer_number',
		 'customer_site_name',
		 'customer_site_number',
		 'payment_term',
		 'description',
		 'hr_expense_line_id',
		 'line_status',
		 'line_type',
		 'line_number',
		 'item_id_m',
		 'item_description',
		 'line_description',
		 'line_quantity',
		 'picked_quantity',
		 'shipped_quantity',
		 'unit_price',
		 'line_price',
		 'item_number',
		 'uom_id',
		 'item_status',
		 'org',
		 'shipping_org_id',
		 'requested_date',
		 'promise_date',
		 'schedule_ship_date',
		 'actual_ship_date',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'so_number',
		 'customer_name',
		 'customer_site_name',
		 'item_number',
		 'line_status',
		 'schedule_ship_date',
 ];
 public $column = [
		 'so_number',
		 'so_status',
		 'customer_name',
		 'customer_site_name',
		 'item_number',
		 'line_quantity',
		 'picked_quantity',
		 'schedule_ship_date',
 ];
 public $multi_select_column = [
		 'so_number',
		 'line_number',
		 'org',
		 'customer_name',
		 'item_number',
		 'line_quantity',
		 'onhand',
		 'picked_quantity',
		 'shipped_quantity',
		 'staging_subinventory',
		 'staging_locator',
		 'document_type',
		 'hr_expense_header_id',
		 'bu_org_id',
		 'shipping_org_id',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'sales_person',
		 'document_currency',
		 'header_amount',
		 'so_status',
		 'staging_subinventory_id',
		 'staging_locator_id',
		 'payment_term_id',
		 'customer_number',
		 'customer_site_name',
		 'customer_site_number',
		 'payment_term',
		 'description',
		 'hr_expense_line_id',
		 'line_status',
		 'line_type',
		 'item_id_m',
		 'item_description',
		 'line_description',
		 'unit_price',
		 'line_price',
		 'uom_id',
		 'item_status',
		 'requested_date',
		 'promise_date',
		 'schedule_ship_date',
		 'actual_ship_date',
 ];
 public $dateField = [
		 'requested_date',
		 'promise_date',
		 'schedule_ship_date',
		 'actual_ship_date',
 ];
 public $search = [
		 '_update_path' => 'form.php?class_name=hr_expense_header',
		 '_show_update_path' => 1,
		 '_view_path' => 'form.php?class_name=hr_expense_header',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
		 '_extra_path' => array('form.php?class_name=ar_transaction_header&mode=9' => 'Invoice',
				 'form.php?class_name=sd_delivery_header&mode=9' => 'Ship')
 ];
 public $pageTitle = " SO - Sales Orders "; //page Title
 public $option_lists = [
		 'approval_status' => 'APPROVAL_STATUS',
 ];
 public $hr_expense_header_id;
 public $bu_org_id;
 public $document_type;
 public $so_number;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $sales_person;
 public $staging_subinventory;
 public $staging_locator;
 public $staging_subinventory_id;
 public $staging_locator_id;
 public $document_currency;
 public $header_amount;
 public $so_status;
 public $payment_term_id;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $customer_site_number;
 public $payment_term;
 public $description;
 public $hr_expense_line_id;
 public $line_status;
 public $line_type;
 public $line_number;
 public $item_id_m;
 public $onhand;
 public $item_description;
 public $line_description;
 public $line_quantity;
 public $picked_quantity;
 public $shipped_quantity;
 public $unit_price;
 public $line_price;
 public $item_number;
 public $uom_id;
 public $item_status;
 public $org;
 public $shipping_org_id;
 public $requested_date;
 public $promise_date;
 public $schedule_ship_date;
 public $actual_ship_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $action;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 private function create_hr_expense_all_v() {
	$sql = "
CREATE OR REPLACE VIEW hr_expense_all_v
(
hr_expense_header_id, bu_org_id, document_type, so_number, ar_customer_id, ar_customer_site_id, sales_person,
document_currency, header_amount, so_status,  payment_term_id, onhand, customer_name, customer_number, 
customer_site_name, customer_site_number, payment_term, payment_term_description, hr_expense_line_id, line_type,
line_number, item_id_m, item_description, line_description, line_quantity,  picked_quantity,
shipped_quantity, unit_price, line_price, line_status, staging_subinventory_id, staging_locator_id,
staging_subinventory, staging_locator, requested_date, promise_date , schedule_ship_date ,actual_ship_date,
item_number, uom_id, item_status,  org, shipping_org_id, created_by,  creation_date, last_update_by,
last_update_date
)
AS
 SELECT 
sdsh.hr_expense_header_id, sdsh.bu_org_id, sdsh.document_type, sdsh.so_number, sdsh.ar_customer_id, 
sdsh.ar_customer_site_id, sdsh.sales_person, sdsh.document_currency,  sdsh.header_amount, sdsh.so_status, sdsh.payment_term_id,
osv.onhand,
ar_customer.customer_name, ar_customer.customer_number,
ar_customer_site.customer_site_name, ar_customer_site.customer_site_number,
payment_term.payment_term, payment_term.description,
sdsl.hr_expense_line_id, sdsl.line_type, sdsl.line_number,	sdsl.item_id_m, 
sdsl.item_description, sdsl.line_description, sdsl.line_quantity,
sdsl.picked_quantity, sdsl.shipped_quantity, sdsl.unit_price, sdsl.line_price, sdsl.line_status,
ssc.staging_subinventory_id,ssc.staging_locator_id,subinventory.subinventory,locator.locator,
sdsl.requested_date, sdsl.promise_date , sdsl.schedule_ship_date ,sdsl.actual_ship_date,
item.item_number, item.uom_id, item.item_status,
org.org, sdsl.shipping_org_id,
sdsl.created_by, sdsl.creation_date, sdsl.last_update_by, sdsl.last_update_date
FROM hr_expense_header sdsh
LEFT JOIN payment_term ON sdsh.payment_term_id = payment_term.payment_term_id,
ar_customer, 
ar_customer_site, 
hr_expense_line sdsl
LEFT JOIN onhand_summary_v osv ON osv.item_id_m = sdsl.item_id_m AND osv.org_id = sdsl.shipping_org_id,
item,
org,
sd_shipping_control ssc 
LEFT JOIN subinventory ON subinventory.subinventory_id = ssc.staging_subinventory_id
LEFT JOIN locator ON locator.locator_id = ssc.staging_locator_id

WHERE
sdsh.hr_expense_header_id = sdsl.hr_expense_header_id
AND sdsh.ar_customer_id = ar_customer.ar_customer_id
AND sdsh.ar_customer_site_id = ar_customer_site.ar_customer_site_id
AND sdsl.item_id_m = item.item_id_m AND item.org_id = sdsl.shipping_org_id
AND sdsl.shipping_org_id = org.org_id
AND ssc.org_id = sdsl.shipping_org_id

";
 }

 

 public function findBY_soLineId($line_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE hr_expense_line_id = :hr_expense_line_id ";
	$sql = ino_perPageSql_i($sql, 1);
	$value_a = ['hr_expense_line_id' => $line_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

}


$sql = " 
 CREATE OR REPLACE VIEW xx_hr_expense_all_v
(
hr_expense_header_id, bu_org_id, document_type, so_number, ar_customer_id, ar_customer_site_id, sales_person,
document_currency, header_amount, so_status,  payment_term_id, onhand, customer_name, customer_number, 
customer_site_name, customer_site_number, payment_term, payment_term_description, hr_expense_line_id, line_type,
line_number, item_id_m, item_description, line_description, line_quantity,  picked_quantity,
shipped_quantity, unit_price, line_price, line_status, staging_subinventory_id, staging_locator_id,
staging_subinventory, staging_locator, requested_date, promise_date , schedule_ship_date ,actual_ship_date,
item_number, uom_id, item_status,  org, shipping_org_id, created_by,  creation_date, last_update_by,
last_update_date
)
AS
 SELECT 
sdsh.hr_expense_header_id, sdsh.bu_org_id, sdsh.document_type, sdsh.so_number, sdsh.ar_customer_id, 
sdsh.ar_customer_site_id, sdsh.sales_person, sdsh.document_currency,  sdsh.header_amount, sdsh.so_status, sdsh.payment_term_id,
osv.onhand,
ar_customer.customer_name, ar_customer.customer_number,
ar_customer_site.customer_site_name, ar_customer_site.customer_site_number,
payment_term.payment_term, payment_term.description,
sdsl.hr_expense_line_id, sdsl.line_type, sdsl.line_number,	sdsl.item_id_m, 
sdsl.item_description, sdsl.line_description, sdsl.line_quantity,
ssc.staging_subinventory_id,ssc.staging_locator_id,subinventory.subinventory,locator.locator,
sdsl.requested_date, sdsl.promise_date , sdsl.schedule_ship_date ,sdsl.actual_ship_date,
sdsl.picked_quantity, sdsl.shipped_quantity, sdsl.unit_price, sdsl.line_price, sdsl.line_status,
item.item_number, item.uom_id, item.item_status,
org.org, sdsl.shipping_org_id,
sdsl.created_by, sdsl.creation_date, sdsl.last_update_by, sdsl.last_update_date
FROM hr_expense_header sdsh
LEFT JOIN payment_term ON sdsh.payment_term_id = payment_term.payment_term_id,
ar_customer, 
ar_customer_site, 
hr_expense_line sdsl
LEFT JOIN onhand_summary_v osv ON osv.item_id_m = sdsl.item_id_m AND osv.org_id = sdsl.shipping_org_id,
item,
org,
sd_shipping_control ssc 
LEFT JOIN subinventory ON subinventory.subinventory_id = ssc.staging_subinventory_id
LEFT JOIN locator ON locator.locator_id = ssc.staging_locator_id

WHERE sdsh.hr_expense_header_id= 30
AND sdsh.hr_expense_header_id = sdsl.hr_expense_header_id
AND sdsh.ar_customer_id = ar_customer.ar_customer_id
AND sdsh.ar_customer_site_id = ar_customer_site.ar_customer_site_id
AND sdsl.item_id_m = item.item_id_m AND item.org_id = sdsl.shipping_org_id
AND sdsl.shipping_org_id = org.org_id
AND ssc.org_id = sdsl.shipping_org_id
"
//end of so_detail class
?>