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
 * hd_ro_header CLass
 * Contains all the hd_svo_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class hd_svo_header extends dbObject {

 public static $table_name = "hd_svo_header";
 public static $dependent_classes = ['hd_svo_line', 'hd_svo_estimates'];
 public static $primary_column = "hd_svo_header_id";
 public static $primary_column2 = "order_number";
 public static $key_column = 'ar_customer_id';
 public static $module = "hd";
 public static $system_info = [
  'name' => 'Service Order',
  'number' => '2301',
  'description' => 'Create & Mainten Service Order',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hd_svo_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];
 public $action_a = [
  'APPROVE' => 'Approve',
  'PRINT' => 'Copy',
  'CANCEL' => 'Cancel',
  'CLOSE' => 'Close',
  'CREATE_WO' => 'Create Work Order',
 ];
 public $field_a = [
  'hd_svo_header_id',
  'bu_org_id',
  'hd_service_type_header_id',
  'order_number',
  'hd_service_request_id',
  'promise_date',
  'ar_customer_id',
  'ar_customer_site_id',
  'service_person_employee_id',
  'service_team_id',
  'description',
  'ship_to_id',
  'bill_to_id',
  'item_id_m',
  'inv_serial_number_id',
  'lot_number_id',
  'price_list_header_id',
  'quantity',
  'estimate_amount',
  'doc_currency',
  'prepaid_status',
  'prepaid_amount',
  'currency',
  'payment_term_id',
  'payment_term_date',
  'warrenty_status',
  'escalation',
  'exchange_rate_type',
  'exchange_rate',
  'inventory_org_id',
  'close_date',
  'order_reference_table',
  'order_reference_id',
  'repair_status',
  'estimate_status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'hd_service_type_header_id',
  'order_number',
 ];
 public $requiredField = [
  'bu_org_id',
  'hd_service_type_header_id',
  'ar_customer_id',
//  'item_id_m'
 ];
 public $addressField = [
  'ship_to_id',
  'bill_to_id'
 ];
 public $fields_inForm_notInDataBase = [
  'action',
  "customer_name",
  "customer_number",
  "customer_site_name",
  "item_number",
  "item_description",
  'serial_number',
  'lot_number',
 ];
 public $profile_default = [
  'exchange_rate_type' => 'gl_currency_conversion_type',
  'bu_org_id' => 'org_bu_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//  '_extra_path' => array('form.php?class_name=ar_transaction_header&mode=9' => 'Invoice',
//   'form.php?class_name=sd_delivery_header&mode=9' => 'Ship')
 ];
 public $pageTitle = " Service Order "; //page Title
 public $hd_svo_header_id;
 public $bu_org_id;
 public $hd_service_type_header_id;
 public $order_number;
 public $hd_service_request_id;
 public $promise_date;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $service_person;
 public $service_team_id;
 public $service_person_employee_id;
 public $description;
 public $ship_to_id;
 public $bill_to_id;
 public $item_id_m;
 public $inv_serial_number_id;
 public $lot_number_id;
 public $quantity;
 public $estimate_amount;
 public $doc_currency;
 public $prepaid_status;
 public $prepaid_amount;
 public $currency;
 public $payment_term_id;
 public $payment_term_date;
 public $warrenty_status;
 public $escalation;
 public $exchange_rate_type;
 public $exchange_rate;
 public $inventory_org_id;
 public $close_date;
 public $order_reference_table;
 public $order_reference_id;
 public $repair_status;
 public $estimate_status;
 public $price_list_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $item_number;
 public $item_description;
 public $serial_number;
 public $lot_number;

 public function _before_showing() {
  $address = new address();
  if (!empty($this->ship_to_id)) {
   $address_ship_to = $address->findBy_id($this->ship_to_id);
   $this->ship_to_address_name = $address_ship_to->address_name;
   $this->ship_to_address = $address_ship_to->address;
   $this->ship_to_country = $address_ship_to->country;
   $this->ship_to_postal_code = $address_ship_to->postal_code;
   $this->ship_to_phone = $address_ship_to->phone;
  }
  if (!empty($this->bill_to_id)) {
   $address_bill_to = $address->findBy_id($this->bill_to_id);
   $this->bill_to_address_name = $address_bill_to->address_name;
   $this->bill_to_address = $address_bill_to->address;
   $this->bill_to_country = $address_bill_to->country;
   $this->bill_to_postal_code = $address_bill_to->postal_code;
   $this->bill_to_phone = $address_bill_to->phone;
  }
 }

 private function _do_action() {
  switch ($this->action) {
   case 'BOOKED':
    $this->so_status = 'BOOKED';
    break;

   default :
    break;
  }
 }

 public function _before_save() {
  if (!empty($this->action)) {
   $this->_do_action();
  }

  if (empty($this->so_status)) {
   $this->so_status = 'ENTERED';
  }
 }

 public function _after_save() {
  if ((!empty($this->hd_svo_header_id)) && empty($this->order_number)) {
   $hd_svo_header_id = $this->hd_svo_header_id;
   $bu_org_id = $this->bu_org_id;
   $so_number = $bu_org_id . '-' . $hd_svo_header_id;
   $this->order_number = $so_number;
   echo '<br/> New SO number is ' . $so_number;
   $this->update_soNumber();
  }
 }

 private function update_soNumber() {
  $sql = " UPDATE " . self::$table_name;
  $sql .= " SET order_number = '{$this->order_number}'  ";
  $sql .= " WHERE hd_svo_header_id = '{$this->hd_svo_header_id}'  ";
  try {
   $this->runSQL($sql);
  } catch (Exception $e) {
   echo "<br>SO Number update failed!" . $e->getMessage();
  }
 }

 public static function instantiate_extra_fields(&$array_of_objects) {
  if (count($array_of_objects) > 0) {
   foreach ($array_of_objects as &$this_object) {
    $customer_details = supplier::find_by_id($this_object->ar_customer_id);
    $this_object->customer_name = $customer_details->customer_name;
    $this_object->customer_number = $customer_details->customer_number;
    $customer_site_details = customer_site::find_by_id($this_object->customer_site_id);
    $this_object->customer_site_name = $customer_site_details->customer_site_name;
   }
  }
  return $array_of_objects;
 }

 Public static function so_types() {
  $option_header = option_header::find_by_name('SO_TYPE');
  $so_types = option_line::find_by_option_id($option_header->option_header_id);
  return $so_types;
 }

 Public static function so_status() {
  $option_header = option_header::find_by_name('hd_ro_STATUS');
  $so_status = option_line::find_by_option_id($option_header->option_header_id);
  return $so_status;
 }

 public function copy($hd_svo_header_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM hd_svo_header WHERE `hd_svo_header_id` = '{$hd_svo_header_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `hd_svo_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `hd_svo_header_id` = '{$hd_svo_header_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `hd_svo_header` SELECT * FROM tmptable WHERE `hd_svo_header_id` = '' ";
    if ($db->query($sql3)) {
     $this->hd_svo_header_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

 private function _pick_sales_order() {
  
 }

// public function save() {
//	$primary_column = static::$primary_column;
//	if (empty($this->$primary_column)) {
//	 $this->approval_status = 'Entered';
//	 $this->create();
//	} else {
//	 $this->update($this->$primary_column);
//	}
//	return $this->msg;
// }
}

//end of hd_svo_header class
?>