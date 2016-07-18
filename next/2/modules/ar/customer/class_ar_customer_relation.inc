<?php

class ar_customer_relation extends dbObject {

 public static $table_name = "ar_customer_relation";
 public static $primary_column = "ar_customer_relation_id";
 public static $parent_primary_column = "ar_customer_id";
 public static $key_column = 'customer_relation_name';
 public static $module = "ar";
 public $field_a = [
  'ar_customer_relation_id',
  'ar_customer_id',
  'customer_relation_number',
  'customer_relation_name',
  'relation_tax_country',
  'relation_tax_reg_no',
  'relation_tax_payer_id',
//		 'relation_tax_code',
//		 'customer_relation_ref',
  'customer_relation_type',
  'status',
//		 'profile_id',
  'currency',
  'payment_term_id',
  'ar_sales_region_id',
//		 'finance_profile_id',
		 'payment_method_id',
		 'order_type_id',
		 'price_list_id',
		 'internal_org_id',
//		 'fob',
//		 'freight_terms',
//		 'transportation',
		 'country_of_origin',
  'ship_to_id',
  'bill_to_id',
//		 'relation_contact_id',
//		 'customer_relation_attachement_id',
//		 'bank_id',
//		 'bank_account_id',
//		 'rev_enabled_cb',
//		 'rev_number',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $requiredField = [
  "ar_customer_id",
  "customer_relation_number",
  "customer_relation_name",
 ];
 public $addressField_array = [
  "relation_address_id"
 ];
 public $fields_inForm_notInDataBase = [
  'relation_address_name',
  'relation_address',
  'relation_country',
  'relation_postal_code',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'ar_customer_id'
 ];
 public $ar_customer_relation_id;
 public $ar_customer_id;
 public $customer_relation_number;
 public $customer_relation_name;
 public $relation_tax_country;
 public $relation_tax_reg_no;
 public $relation_tax_payer_id;
 public $relation_tax_code;
 public $customer_relation_ref;
 public $customer_relation_type;
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
 public $transportation;
 public $country_of_origin;
 public $bill_to_id;
 public $ship_to_id;
 public $relation_contact_id;
 public $customer_relation_attachement_id;
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
 public $relation_address_name;
 public $relation_address;
 public $relation_country;
 public $relation_postal_code;

   public function _after_save() {

  if ((!empty($this->ar_customer_relation_id)) && empty($this->customer_relation_number)) {
   $this->customer_relation_number = $this->ar_customer_relation_id;
   $this->save();
  }
 }
 
 Public static function customer_relation_types() {
  $option_header = option_header::find_by_name('CUSTOMER_relation_TYPE');
  $coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
  return $coa_account_types;
 }

 public function _before_showing() {
  $address = new address();
  if (!empty($this->relation_address_id)) {
   $address->findBy_id($this->relation_address_id);
   $this->relation_address_name = $address->address_name;
   $this->relation_address = $address->address;
   $this->relation_country = $address->country;
   $this->relation_postal_code = $address->postal_code;
  }
 }

 public static function find_all_relationsOfCustomer_array($customer_id = "") {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ar_customer_id = '{$customer_id}' ";
  $final_array = [];
  $result_array = self::find_by_sql($sql);
  foreach ($result_array as $obj) {
   $key = $obj->ar_customer_relation_id;
   $value = $obj->ar_customer_relation_id . "-" . $obj->customer_relation_name;
   $final_array[$key] = $value;
  }
  return $final_array;
 }

 public static function find_all_relationsOfCustomer($customer_id = "") {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ar_customer_id = '{$customer_id}' ";

  $result = self::find_by_sql($sql);
  return $result;
 }

 public function copy($ar_customer_relation_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM customer_relation WHERE `ar_customer_relation_id` = '{$ar_customer_relation_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `ar_customer_relation_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ar_customer_relation_id` = '{$ar_customer_relation_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `customer_relation` SELECT * FROM tmptable WHERE `ar_customer_relation_id` = '' ";
    if ($db->query($sql3)) {
     $this->ar_customer_relation_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

}

//end of customer_relation class
?>