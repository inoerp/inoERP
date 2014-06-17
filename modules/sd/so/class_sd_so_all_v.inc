<?php

class sd_so_all_v extends dbObject {

 public static $table_name = "sd_so_all_v";
 public static $primary_column = "sd_so_header_id";
 public $field_a = [
		 'sd_so_header_id',
		 'bu_org_id',
		 'so_type',
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
		 'sd_so_line_id',
		 'line_status',
		 'line_type',
		 'line_number',
		 'item_id',
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
		 'so_type',
		 'sd_so_header_id',
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
		 'sd_so_line_id',
		 'line_status',
		 'line_type',
		 'item_id',
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
		 '_update_path' => 'form.php?class_name=sd_so_header',
		 '_show_update_path' => 1,
		 '_view_path' => 'form.php?class_name=sd_so_header',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
		 '_extra_path' => array('form.php?class_name=ar_transaction_header&mode=9' => 'Invoice',
				 'form.php?class_name=sd_delivery_header&mode=9' => 'Ship')
 ];
 public $pageTitle = " SO - Sales Orders "; //page Title
 public $option_lists = [
		 'so_type' => 'SO_TYPE',
		 'approval_status' => 'APPROVAL_STATUS',
 ];
 public $sd_so_header_id;
 public $bu_org_id;
 public $so_type;
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
 public $sd_so_line_id;
 public $line_status;
 public $line_type;
 public $line_number;
 public $item_id;
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

 private function create_sd_so_all_v() {
	$sql = "
CREATE OR REPLACE VIEW sd_so_all_v
(
sd_so_header_id, bu_org_id, so_type, so_number, ar_customer_id, ar_customer_site_id, sales_person,
document_currency, header_amount, so_status,  payment_term_id, onhand, customer_name, customer_number, 
customer_site_name, customer_site_number, payment_term, payment_term_description, sd_so_line_id, line_type,
line_number, item_id, item_description, line_description, line_quantity,  picked_quantity,
shipped_quantity, unit_price, line_price, line_status, staging_subinventory_id, staging_locator_id,
staging_subinventory, staging_locator, requested_date, promise_date , schedule_ship_date ,actual_ship_date,
item_number, uom_id, item_status,  org, shipping_org_id, created_by,  creation_date, last_update_by,
last_update_date
)
AS
 SELECT 
sd_so_header.sd_so_header_id, sd_so_header.bu_org_id, sd_so_header.so_type, sd_so_header.so_number, sd_so_header.ar_customer_id, 
sd_so_header.ar_customer_site_id, sd_so_header.sales_person, sd_so_header.document_currency, 
sd_so_header.header_amount, sd_so_header.so_status,
sd_so_header.payment_term_id,
osv.onhand,
ar_customer.customer_name, ar_customer.customer_number,
ar_customer_site.customer_site_name, ar_customer_site.customer_site_number,
payment_term.payment_term, payment_term.description,
sd_so_line.sd_so_line_id, sd_so_line.line_type, sd_so_line.line_number,	sd_so_line.item_id, 
sd_so_line.item_description, sd_so_line.line_description, sd_so_line.line_quantity,
sd_so_line.picked_quantity, sd_so_line.shipped_quantity,
sd_so_line.unit_price, sd_so_line.line_price, sd_so_line.line_status,
ssc.staging_subinventory_id,ssc.staging_locator_id,subinventory.subinventory,locator.locator,
sd_so_line.requested_date, sd_so_line.promise_date , sd_so_line.schedule_ship_date ,sd_so_line.actual_ship_date,
item.item_number, item.uom_id, item.item_status,
org.org,sd_so_line.shipping_org_id,
sd_so_line.created_by, sd_so_line.creation_date, sd_so_line.last_update_by, sd_so_line.last_update_date

FROM sd_so_header 
LEFT JOIN ar_customer ON sd_so_header.ar_customer_id = ar_customer.ar_customer_id
LEFT JOIN ar_customer_site ON sd_so_header.ar_customer_site_id = ar_customer_site.ar_customer_site_id
LEFT JOIN payment_term ON sd_so_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN sd_so_line ON sd_so_header.sd_so_header_id = sd_so_line.sd_so_header_id
LEFT JOIN item ON sd_so_line.item_id = item.item_id
LEFT JOIN org ON sd_so_line.shipping_org_id = org.org_id
LEFT JOIN sd_shipping_control ssc ON ssc.org_id = sd_so_line.shipping_org_id
LEFT JOIN subinventory ON subinventory.subinventory_id = ssc.staging_subinventory_id
LEFT JOIN locator ON locator.locator_id = ssc.staging_locator_id
LEFT JOIN onhand_summary_v osv ON osv.item_id = sd_so_line.item_id AND osv.org_id = sd_so_line.shipping_org_id

";
 }

 public function findBY_soLineId($line_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE sd_so_line_id = :sd_so_line_id ";
	$sql .= " LIMIT 1 ";
	$value_a = ['sd_so_line_id' => $line_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

}

//end of so_detail class
?>