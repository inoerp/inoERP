<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * sd_lead
 * Contains all the sd_quote_header information, such as - lead_number, sd_lead_id, customer info, etc
 *
 */
class sd_pick_list_v extends dbObject {

// public static $form_class_name = "sd_so_header";
 public static $table_name = "sd_pick_list_v";
 public static $primary_column = "so_number";
 public static $system_info = [
  'name' => 'Pick List',
  'number' => '2325',
  'description' => 'Sales Order Picking',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 7
 ];
 public $field_a = [
  'sd_so_header_id',
  'bu_org_id',
  'document_type',
  'so_number',
  'ar_customer_id',
  'ar_customer_site_id',
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
  'item_number',
  'schedule_ship_date',
  'shipping_org_id',
 ];
 public $multi_select_column = [
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
  'so_number',
  'sd_so_header_id',
  'bu_org_id',
  'shipping_org_id',
  'ar_customer_id',
  'ar_customer_site_id',
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
  'serial_generation',
  'lot_generation'
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
 public $pageTitle = " Pick Sales Orders "; //page Title
 public $option_lists = [
  'approval_status' => 'APPROVAL_STATUS',
 ];
 public $sd_so_header_id;
 public $bu_org_id;
 public $document_type;
 public $so_number;
 public $ar_customer_id;
 public $ar_customer_site_id;
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
 public $serial_generation;
 public $lot_generation;
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

 private function create_sd_pick_list_v() {
  $sql = "
CREATE OR REPLACE VIEW sd_pick_list_v
(
sd_so_header_id, bu_org_id, document_type, so_number, ar_customer_id, ar_customer_site_id, hr_employee_id,
doc_currency, header_amount, so_status,  payment_term_id, onhand, customer_name, customer_number, 
customer_site_name, customer_site_number, payment_term, payment_term_description, sd_so_line_id, line_type,
line_number, item_id_m,
kit_cb,kit_configured_cb,bom_config_header_id,wip_wo_header_id, 
item_description, line_description, line_quantity,  picked_quantity,
shipped_quantity, unit_price, line_price, line_status, staging_subinventory_id, staging_locator_id,
staging_subinventory, staging_locator, requested_date, promise_date , schedule_ship_date ,actual_ship_date,
item_number, uom_id, item_status,  serial_generation, lot_generation, 
org, shipping_org_id, created_by,  creation_date, last_update_by,
last_update_date
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
item.item_number, item.uom_id, item.item_status, item.serial_generation,item.lot_generation,
org.org, sdsl.shipping_org_id,
sdsl.created_by, sdsl.creation_date, sdsl.last_update_by, sdsl.last_update_date
FROM sd_so_header sdsh
LEFT JOIN payment_term ON sdsh.payment_term_id = payment_term.payment_term_id,
ar_customer, 
ar_customer_site, 
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
AND sdsh.ar_customer_site_id = ar_customer_site.ar_customer_site_id
AND sdsl.item_id_m = item.item_id_m AND item.org_id = sdsl.shipping_org_id
AND sdsl.shipping_org_id = org.org_id
AND ssc.org_id = sdsl.shipping_org_id
AND sdsh.so_status = 'BOOKED'
AND sdsl.line_status IN ('AWAITING_PICKING', 'PARTIAL_PICKED','PARTIAL_SHIPPED')

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

 public static function multi_select_field_from_subiventory($data) {
//  pa($data);
  global $f;
  $stmt = $f->select_field_from_object('from_subiventory', subinventory::find_all_of_org_id($data->shipping_org_id), 'subinventory_id', 'subinventory', '', '', 'medium subinventory_id');
  return $stmt;
 }

 public static function multi_select_field_from_locator($data) {
  global $f;
  $stmt = $f->select_field_from_object('from_locator', locator::find_all_of_subinventory(), 'locator_id', 'locator', '', '', 'medium locator_id');
  return $stmt;
 }

 public static function multi_select_field_lot_number($data) {
  $f = new inoform();
  $stmt = $f->val_field('lot_numer', '', '', '', '', '', '', 'inv_lot_onhand_v', 'lot_numer', 'item_id_m');
  $stmt .= $f->hidden_field_withCLass('inv_lot_numer_id', '', 'dontCopy');
  $stmt .= $f->hidden_field_withCLass('org_id', $data->shipping_org_id, 'popup_value');
  $stmt .= $f->hidden_field_withCLass('item_id_m', $data->item_id_m, 'popup_value item_id_m');
  $stmt .= $f->hidden_field_withCLass('subinventory_id', '', 'popup_value subinventory_id');
  $stmt .= $f->hidden_field_withCLass('locator_id', '', 'popup_value locator_id');
  $stmt .= '<i class="select_lot_number_id generic select_popup clickable fa fa-search" data-class_name="inv_lot_onhand_v"></i>';
  return $stmt;
 }

}

//end of extn_contact class
?>