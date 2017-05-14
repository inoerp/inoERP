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
 * hd_subscription_header CLass
 * Contains all the hd_subscription_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class hd_subscription_header extends dbObject {

 public static $table_name = "hd_subscription_header";
 public static $dependent_classes = ['hd_subscription_line' ,'hd_subscription_detail'];
 public static $primary_column = "hd_subscription_header_id";
 public static $primary_column2 = "number";
 public static $key_column = 'subscription_type';
 public static $module = "hd";
 public static $subscription_type_a = [
  'NEW' => 'New',
  'RENEWAL' => 'Renewal',
 ];
 public static $system_info = [
  'name' => 'Subscription',
  'number' => '5109',
  'description' => 'Create & Mainten Subscription',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hd_subscription_line'),
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 1
 ];
 public $field_a = [
  'hd_subscription_header_id',
  'org_id',
  'subscription_type',
  'document_type',
  'number',
  'ar_customer_id',
  'ar_customer_site_id',
  'hr_employee_id',
  'description',
  'first_name',
  'last_name',
  'full_name',
  'passport_number',
  'dob',
  'gender',
  'marital_status',
  'occupation',
  'nationality',
  'address_line1',
  'address_line2',
  'postal_code',
  'state',
  'house_phone',
  'office_phone',
  'mobile_phone1',
  'mobile_phone2',
  'fax_no',
  'email',
  'ship_to_address_id',
  'bill_to_address_id',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'header_amount',
  'tax_amount',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'first_name',
  'full_name',
  'passport_number',
  'number',
 ];
 public $requiredField = [
  'first_name',
  'full_name',
  'passport_number',
 ];
 public $addressField = [
  'address_id'
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
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//  '_extra_path' => array('form.php?class_name=ar_transaction_header&mode=9' => 'Invoice',
//   'form.php?class_name=sd_delivery_header&mode=9' => 'Ship')
 ];
 public $pageTitle = " Subscription "; //page Title
 public $option_lists = [
  'subscription_type' => 'HD_SUBSCR_DOC_TYPE',
 ];
 public $hd_subscription_header_id;
 public $org_id;
 public $document_type;
 public $number;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $hr_employee_id;
 public $description;
 public $ship_to_address_id;
 public $bill_to_address_id;
 public $first_name;
 public $last_name;
 public $full_name;
 public $passport_number;
 public $dob;
 public $gender;
 public $marital_status;
 public $occupation;
 public $nationality;
 public $address_line1;
 public $address_line2;
 public $postal_code;
 public $state;
 public $house_phone;
 public $office_phone;
 public $mobile_phone1;
 public $mobile_phone2;
 public $fax_no;
 public $email;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

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

  if (empty($this->status)) {
   $this->status = 'ENTERED';
  }

  if (empty($this->hd_subscription_header_id) && !empty($this->bu_org_id)) {
   $this->_do_initial_defaults();
  }
 }

 public function _after_save() {
  if ((!empty($this->hd_subscription_header_id)) && empty($this->number)) {
   $this->_update_number();
  }
 }

 private function _update_number() {
//  global $prl;
//	  $this->number = $prl->find_default_profile('hd_subscription_number_prefix')->level_value .  $this->hd_subscription_header_id;
//  try {
////   $this->save();
//   echo '<br/> New Subscription number is ' . $this->number;
//  } catch (Exception $e) {
//   echo '<br/> Failed to update the Subscription. Error @ ' . __FILE__ . ' @@ ' . __LINE__;
//  }
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

 public function copy($hd_subscription_header_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM hd_subscription_header WHERE `hd_subscription_header_id` = '{$hd_subscription_header_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `hd_subscription_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `hd_subscription_header_id` = '{$hd_subscription_header_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `hd_subscription_header` SELECT * FROM tmptable WHERE `hd_subscription_header_id` = '' ";
    if ($db->query($sql3)) {
     $this->hd_subscription_header_id = $db->insert_id();
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

//end of hd_subscription_header class
?>