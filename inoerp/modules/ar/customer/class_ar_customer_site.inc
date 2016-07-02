<?php

class ar_customer_site extends dbObject {

 public static $table_name = "ar_customer_site";
 public static $primary_column = "ar_customer_site_id";
 public static $parent_primary_column = "ar_customer_id";
 public static $key_column = 'customer_site_name';
 public static $module = "ar";
 public $field_a = [
  'ar_customer_site_id',
  'ar_customer_id',
  'customer_site_number',
  'customer_site_name',
  'site_tax_country',
  'site_tax_reg_no',
  'site_tax_payer_id',
  'primary_cb',
  'customer_site_type',
  'status',
  'currency',
  'payment_term_id',
  'ar_sales_region_id',
  'payment_method_id',
  'order_type_id',
  'price_list_id',
  'internal_org_id',
  'country_of_origin',
  'ship_to_id',
  'bill_to_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $requiredField = [
  "ar_customer_id",
  "customer_site_number",
  "customer_site_name",
 ];
 public $addressField_array = [
  "site_address_id"
 ];
 public $fields_inForm_notInDataBase = [
  'site_address_name',
  'site_address',
  'site_country',
  'site_postal_code',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'ar_customer_id'
 ];
 public $ar_customer_site_id;
 public $ar_customer_id;
 public $customer_site_number;
 public $customer_site_name;
 public $site_tax_country;
 public $site_tax_reg_no;
 public $site_tax_payer_id;
 public $site_tax_code;
 public $customer_site_ref;
 public $customer_site_type;
 public $status;
 public $profile_id;
 public $currency;
 public $payment_term_id;
 public $finance_profile_id;
 public $payment_method_id;
 public $order_type_id;
 public $price_list_id;
 public $internal_org_id;
 public $fob;
 public $freight_terms;
 public $primary_cb;
 public $transportation;
 public $country_of_origin;
 public $bill_to_id;
 public $ship_to_id;
 public $site_contact_id;
 public $customer_site_attachement_id;
 public $ar_sales_region_id;
 public $bank_id;
 public $bank_account_id;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $site_address_name;
 public $site_address;
 public $site_country;
 public $site_postal_code;

 public function _after_save() {

  if ((!empty($this->ar_customer_site_id)) && empty($this->customer_site_number)) {
   $this->customer_site_number = $this->ar_customer_site_id;
   $this->save();
  }
 }

 Public static function customer_site_types() {
  $option_header = option_header::find_by_name('CUSTOMER_SITE_TYPE');
  $coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
  return $coa_account_types;
 }

 public function _before_showing() {
  $address = new address();
  if (!empty($this->site_address_id)) {
   $address->findBy_id($this->site_address_id);
   $this->site_address_name = $address->address_name;
   $this->site_address = $address->address;
   $this->site_country = $address->country;
   $this->site_postal_code = $address->postal_code;
  }
 }

 public static function find_all_sitesOfCustomer_array($customer_id = "") {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ar_customer_id = '{$customer_id}' ";
  $final_array = [];
  $result_array = self::find_by_sql($sql);
  foreach ($result_array as $obj) {
   $key = $obj->ar_customer_site_id;
   $value = $obj->ar_customer_site_id . "-" . $obj->customer_site_name;
   $final_array[$key] = $value;
  }
  return $final_array;
 }

 public static function find_all_sitesOfCustomer($customer_id = "") {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ar_customer_id = '{$customer_id}' ";

  $result = self::find_by_sql($sql);
  return $result;
 }

  public static function find_customerDetails_byOrgId($org_id = "") {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE internal_org_id = '{$org_id}' ";

  $result = self::find_by_sql($sql);
  return $result;
 }
 
 public function copy($ar_customer_site_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM customer_site WHERE `ar_customer_site_id` = '{$ar_customer_site_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `ar_customer_site_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ar_customer_site_id` = '{$ar_customer_site_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `customer_site` SELECT * FROM tmptable WHERE `ar_customer_site_id` = '' ";
    if ($db->query($sql3)) {
     $this->ar_customer_site_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

}

//end of customer_site class
?>