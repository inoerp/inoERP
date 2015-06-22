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
 * sd_quote_header
 * Contains all the sd_quote_header information, such as - quote_number, sd_lead_id, customer info, etc
 *
 */
class sd_quote_header extends dbObject {

 public static $table_name = "sd_quote_header";
 public static $dependent_classes = ['sd_quote_line'];
 public static $primary_column = "sd_quote_header_id";
 public static $primary_column2 = "quote_number";
 public static $key_column = 'ar_customer_id';
 public static $module = "sd";
 public static $system_info = [
  'name' => 'Sales Quote',
  'number' => '2303',
  'description' => 'Create & Mainten Sales Quote',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('sd_quote_line'),
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 3
 ];
 public static $action_a = [
  'CONVERT_SO' => 'Convert to SO',
  'CANCEL' => 'Cancel',
  'CLOSE' => 'Close'
 ];
 public $checkbox = [
  "rev_enabled_cb"
 ];
 public $field_a = [
  'sd_quote_header_id',
  'quote_number',
  'sd_lead_id',
  'sd_opportunity_id',
  'new_customer_name',
  'new_customer_address',
  'ar_customer_id',
  'ar_customer_site_id',
  'sales_person_employee_id',
  'status',
  'approval_status',
  'description',
  'ship_to_id',
  'bill_to_id',
  'price_list_header_id',
  'header_amount',
  'tax_amount',
  'doc_currency',
  'payment_term_id',
  'payment_term_date',
  'agreement_start_date',
  'aggrement_end_date',
  'exchange_rate_type',
  'exchange_rate',
  'rev_enabled_cb',
  'rev_number',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  "sd_quote_header_id",
  "quote_number",
  "ar_customer_id",
  "sales_person_employee_id"
 ];
 public $requiredField = [
  'ar_customer_id',
  'ship_to_id',
  'bill_to_id',
  'doc_currency',
  'payment_term_id'
 ];
 public $addressField = [
  'ship_to_id',
  'bill_to_id'
 ];
 public $fields_inForm_notInDataBase = [
  'set_quote_status',
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
  'sales_person_employee_name',
  'action'
 ];
 public $numberField = [
  'sd_quote_header_id',
  'bu_org_id',
  'quote_number',
  'sd_lead_id',
  'sd_opportunity_id',
  'ar_customer_id',
  'ar_customer_site_id',
  'ship_to_id',
  'bill_to_id',
  'price_list_header_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//  '_extra_path' => array('form.php?class_name=ar_transaction_header&mode=9' => 'Invoice',
//   'form.php?class_name=sd_delivery_header&mode=9' => 'Ship')
 ];
 public $pageTitle = " Sales Quote "; //page Title
 public $option_lists = [
  'approval_status' => 'APPROVAL_STATUS',
 ];
 public $sd_quote_header_id;
 public $bu_org_id;
 public $quote_number;
 public $sd_lead_id;
 public $sd_opportunity_id;
 public $new_customer_name;
 public $new_customer_address;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $sales_person_employee_id;
 public $status;
 public $approval_status;
 public $description;
 public $ship_to_id;
 public $bill_to_id;
 public $price_list_header_id;
 public $header_amount;
 public $tax_amount;
 public $doc_currency;
 public $payment_term_id;
 public $payment_term_date;
 public $agreement_start_date;
 public $aggrement_end_date;
 public $exchange_rate_type;
 public $exchange_rate;
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
 public $sales_person_employee_name;
 public $action;

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

 public function _before_save() {
  if (!empty($this->set_quote_status)) {
   $this->quote_status = $this->set_quote_status;
  }

  if (empty($this->quote_status)) {
   $this->quote_status = 'ENTERED';
  }
 }

 public function _after_save() {
  if ((!empty($this->sd_quote_header_id)) && empty($this->quote_number)) {
   $sd_quote_header_id = $this->sd_quote_header_id;
   $quote_number = $sd_quote_header_id;
   $this->quote_number = $quote_number;
   echo '<br/> New Quote number is ' . $quote_number;
   $this->update_soNumber();
  }
  if ((!empty($this->sd_quote_header_id)) && ($this->action = 'CONVERT_SO')) {
   if (empty($this->bu_org_id)) {
    echo gettext('No business organization found. Please enter a business org name in the quote');
   } else if (in_array($this->status, ['ENTERED', 'OPEN'])) {
    //Conevrt to SO
    $this->_convert_to_so();
   } else {
    echo gettext('Quote Status Error. You cannot convert quote in the current status to a sales order');
   }
  }
 }
 
 private function _convert_to_so(){
  //pending
 }

 private function update_soNumber() {
  $sql = " UPDATE " . self::$table_name;
  $sql .= " SET quote_number = '{$this->quote_number}'  ";
  $sql .= " WHERE sd_quote_header_id = '{$this->sd_quote_header_id}'  ";
  try {
   $this->runSQL($sql);
  } catch (Exception $e) {
   echo "<br>Quote Number update failed!" . $e->getMessage();
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

 Public static function quote_types() {
  $option_header = option_header::find_by_name('SO_TYPE');
  $quote_types = option_line::find_by_option_id($option_header->option_header_id);
  return $quote_types;
 }

 Public static function quote_status() {
  $option_header = option_header::find_by_name('SD_SO_STATUS');
  $quote_status = option_line::find_by_option_id($option_header->option_header_id);
  return $quote_status;
 }

}

//end of sd_quote_header class
?>