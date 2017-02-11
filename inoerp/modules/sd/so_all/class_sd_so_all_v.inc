<?php

class sd_so_all_v extends dbObject {

 public static $form_class_name = "sd_so_header";
 public static $table_name = "sd_so_all_v";
 public static $primary_column = "sd_so_header_id";
 public $field_a = [
		 'sd_so_header_id',
		 'bu_org_id',
		 'document_type',
		 'so_number',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'sales_person',
		 'hr_employee_id',
		 'doc_currency',
		 'header_amount',
		 'so_status',
		 'payment_term_id',
		 'customer_name',
		 'customer_number',
		 'customer_site_name',
		 'customer_site_number',
		 'payment_term',
		 'sd_so_line_id',
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
		 'so_status',
//		 'item_number',
		 'line_status',
		 'schedule_ship_date',
//  'shipping_org_id',
		 'item_id_m',
		 'sd_so_header_id'
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
		 'sd_so_header_id',
		 'bu_org_id',
		 'shipping_org_id',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'sales_person',
		 'hr_employee_id',
		 'doc_currency',
		 'header_amount',
		 'so_status',
		 'staging_subinventory_id',
		 'staging_locator_id',
		 'payment_term_id',
		 'customer_number',
		 'customer_site_name',
		 'customer_site_number',
		 'payment_term',
		 'sd_so_line_id',
		 'line_status',
		 'line_type',
		 'item_id_m',
		 "kit_cb",
		 'kit_configured_cb',
		 'bom_config_header_id',
		 'wip_wo_header_id',
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
 public $search_functions = [
		 'Item' => 'search_item_number',
		 'Business Org' => 'search_business_org_nm',
		 'Shipping Org' => 'search_shipping_org',
		 'Schedule Date' => 'search_schedule_ship_date',
		 '> Schedule Date' => 'search_schedule_ship_date_gt',
		 '< Schedule Date' => 'search_schedule_ship_date_lt',
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
		 'approval_status' => 'APPROVAL_STATUS',
 ];
 public $sd_so_header_id;
 public $bu_org_id;
 public $document_type;
 public $so_number;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $sales_person;
 public $hr_employee_id;
 public $staging_subinventory;
 public $staging_locator;
 public $staging_subinventory_id;
 public $staging_locator_id;
 public $doc_currency;
 public $header_amount;
 public $so_status;
 public $payment_term_id;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $customer_site_number;
 public $payment_term;
 public $sd_so_line_id;
 public $line_status;
 public $line_type;
 public $line_number;
 public $item_id_m;
 public $kit_configured_cb;
 public $kit_cb;
 public $bom_config_header_id;
 public $wip_wo_header_id;
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

 private function create_sd_so_all_v() {
	$sql = "
CREATE OR REPLACE VIEW sd_so_all_v
(
sd_so_header_id, bu_org_id, document_type, so_number, ar_customer_id, ar_customer_site_id, hr_employee_id,
doc_currency, header_amount, so_status,  payment_term_id, onhand, customer_name, customer_number, 
customer_site_name, customer_site_number, payment_term, payment_term_description, sd_so_line_id, line_type,
line_number, item_id_m,
kit_cb,kit_configured_cb,bom_config_header_id,wip_wo_header_id, 
item_description, line_description, line_quantity,  picked_quantity,
shipped_quantity, unit_price, line_price, line_status, staging_subinventory_id, staging_locator_id,
staging_subinventory, staging_locator, requested_date, promise_date , schedule_ship_date ,actual_ship_date,
item_number, uom_id, item_status,  org, shipping_org_id, created_by,  creation_date, last_update_by,
last_update_date,
sales_person
)
AS
 SELECT 
sdsh.sd_so_header_id, sdsh.bu_org_id, sdsh.document_type, sdsh.so_number, sdsh.ar_customer_id, 
sdsh.ar_customer_site_id, sdsh.hr_employee_id, sdsh.doc_currency,  sdsh.header_amount, sdsh.so_status, sdsh.payment_term_id,
osv.onhand,
ar_customer.customer_name, ar_customer.customer_number,
ar_customer_site.customer_site_name, ar_customer_site.customer_site_number,
payment_term.payment_term, payment_term.description,
sdsl.sd_so_line_id, sdsl.line_type, sdsl.line_number,	sdsl.item_id_m, 
sdsl.kit_cb, sdsl.kit_configured_cb, sdsl.bom_config_header_id,	sdsl.wip_wo_header_id, 
sdsl.item_description, sdsl.line_description, sdsl.line_quantity,
sdsl.picked_quantity, sdsl.shipped_quantity, sdsl.unit_price, sdsl.line_price, sdsl.line_status,
ssc.staging_subinventory_id,ssc.staging_locator_id,subinventory.subinventory,locator.locator,
sdsl.requested_date, sdsl.promise_date , sdsl.schedule_ship_date ,sdsl.actual_ship_date,
item.item_number, item.uom_id, item.item_status,
org.org, sdsl.shipping_org_id,
sdsl.created_by, sdsl.creation_date, sdsl.last_update_by, sdsl.last_update_date,
CONCAT(hre.last_name, ', ' , hre.first_name) as sales_person
FROM sd_so_header sdsh 
LEFT JOIN hr_employee hre ON sdsh.hr_employee_id = hre.hr_employee_id
LEFT JOIN payment_term ON sdsh.payment_term_id = payment_term.payment_term_id
LEFT JOIN ar_customer_site ON sdsh.ar_customer_site_id = ar_customer_site.ar_customer_site_id,
ar_customer, 
sd_so_line sdsl
LEFT JOIN onhand_summary_v osv ON osv.item_id_m = sdsl.item_id_m AND osv.org_id = sdsl.shipping_org_id,
item,
org,
sd_shipping_control ssc 
LEFT JOIN subinventory ON subinventory.subinventory_id = ssc.staging_subinventory_id
LEFT JOIN locator ON locator.locator_id = ssc.staging_locator_id

WHERE
sdsh.sd_so_header_id = sdsl.sd_so_header_id
AND sdsh.ar_customer_id = ar_customer.ar_customer_id
AND sdsl.item_id_m = item.item_id_m 
AND item.org_id = sdsl.shipping_org_id
AND sdsl.shipping_org_id = org.org_id
AND ssc.org_id = sdsl.shipping_org_id

";
 }

 public function findBY_soLineId($line_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE sd_so_line_id = :sd_so_line_id ";
	$sql = ino_perPageSql_i($sql, 1);
	$value_a = ['sd_so_line_id' => $line_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_soLineId($line_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE sd_so_line_id = '{$line_id}' ";
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_pop($result) : false;
 }

}

//end of so_detail class
?>