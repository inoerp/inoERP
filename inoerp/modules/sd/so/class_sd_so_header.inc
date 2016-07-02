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
 * sd_so_header CLass
 * Contains all the sd_so_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class sd_so_header extends dbObject {

 public static $table_name = "sd_so_header";
 public static $dependent_classes = ['sd_so_line'];
 public static $primary_column = "sd_so_header_id";
 public static $primary_column2 = "so_number";
 public static $key_column = 'ar_customer_id';
 public static $module = "sd";
 public static $system_info = [
  'name' => 'Sales Order',
  'number' => '2301',
  'description' => 'Create & Mainten Sales Order',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('sd_so_line'),
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 1
 ];
 public $checkbox = [
  "rev_enabled_cb"
 ];
 public static $order_source_type_a = [
  'MANUAL' => 'Manual',
  'ECOMMERCE' => 'eCommerce',
  'SERVICE' => 'Serive',
  'INV' => 'Inventory',
  'IR' => 'Internal Requisition',
  'QUOTE' => 'Quote',
  'COPY' => 'Copy',
 ];
 public $field_a = [
  'sd_so_header_id',
  'bu_org_id',
  'document_type',
  'so_number',
  'ar_customer_id',
  'ar_customer_site_id',
  'hr_employee_id',
  "description",
  'ship_to_id',
  'bill_to_id',
  'price_list_header_id',
  'header_amount',
  'tax_amount',
  'currency',
  'doc_currency',
  'payment_term_id',
  'payment_term_date',
  'agreement_start_date',
  'aggrement_end_date',
  'exchange_rate_type',
  'exchange_rate',
  'released_amount',
  'prepaid_amount',
  'prepaid_status',
  "order_source_type",
  "order_reference_table",
  "order_reference_id",
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'so_status',
  "rev_enabled_cb",
  "rev_number",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $initial_search = [
  "sd_so_header_id",
  "so_number",
  "ar_customer_id",
 ];
 public $requiredField = [
  'ar_customer_id',
  'ship_to_id',
  'bill_to_id',
  'doc_currency',
  'document_type'
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
  "ship_to_address_name",
  "bill_to_address_name",
  'sales_action',
  'ship_to_phone',
  'ship_to_email',
  'ship_to_address',
  'ship_to_country',
  'ship_to_postal_code',
  'bill_to_phone',
  'bill_to_email',
  'bill_to_address',
  'bill_to_country',
  'bill_to_postal_code',
  'sales_person'
 ];
 public $fields_inDataBase_notInForm = [
  'currency'
 ];
 public $search_functions = [
  'BU Org' => 'search_business_org',
 ];
 public $profile_default = [
  'exchange_rate_type' => 'gl_currency_conversion_type',
  'bu_org_id' => 'org_bu_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
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
 public $hr_employee_id;
 public $sales_person;
 public $description;
 public $ship_to_id;
 public $bill_to_id;
 public $price_list_header_id;
 public $header_amount;
 public $tax_amount;
 public $prepaid_amount;
 public $prepaid_status;
 public $currency;
 public $doc_currency;
 public $payment_term_id;
 public $payment_term_date;
 public $agreement_start_date;
 public $aggrement_end_date;
 public $exchange_rate_type;
 public $exchange_rate;
 public $released_amount;
 public $order_source_type;
 public $order_reference_table;
 public $order_reference_id;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $action;
 public $so_status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $sales_action;
 public $pick_from_subinventory;
 public $pick_from_locator;
 public $staging_subinventory;
 public $staging_locator;
 public $ship_to_address;
 public $bill_to_address_name;
 public $ship_to_phone;
 public $ship_to_address_name;
 public $ship_to_country;
 public $ship_to_postal_code;
 public $bill_to_phone;
 public $bill_to_address;
 public $bill_to_country;
 public $bill_to_postal_code;

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

  if (empty($this->sd_so_header_id) && !empty($this->bu_org_id)) {
   $this->_do_initial_defaults();
  }
 }

 public function _after_save() {
  if ((!empty($this->sd_so_header_id)) && empty($this->so_number)) {
   $sd_so_header_id = $this->sd_so_header_id;
   $bu_org_id = $this->bu_org_id;
   $so_number = $bu_org_id . '-' . $sd_so_header_id;
   $this->so_number = $so_number;
   echo '<br/> New SO number is ' . $so_number;
   $this->update_soNumber();
  }
 }

 private function update_soNumber() {
  $sql = " UPDATE " . self::$table_name;
  $sql .= " SET so_number = '{$this->so_number}'  ";
  $sql .= " WHERE sd_so_header_id = '{$this->sd_so_header_id}'  ";
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
  $option_header = option_header::find_by_name('SD_SO_STATUS');
  $so_status = option_line::find_by_option_id($option_header->option_header_id);
  return $so_status;
 }

 public function copy($sd_so_header_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM sd_so_header WHERE `sd_so_header_id` = '{$sd_so_header_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `sd_so_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `sd_so_header_id` = '{$sd_so_header_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `sd_so_header` SELECT * FROM tmptable WHERE `sd_so_header_id` = '' ";
    if ($db->query($sql3)) {
     $this->sd_so_header_id = $db->insert_id();
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

//end of sd_so_header class
?>