<?php

class supplier_site extends dbObject {

 public static $table_name = "supplier_site";
 public static $primary_column = "supplier_site_id";
 public static $parent_primary_column = "supplier_id";
 public static $key_column = 'supplier_site_name';
 public static $module = "ap";
 public $field_a = [
  "supplier_site_id",
  'supplier_id',
  "supplier_site_number",
  "supplier_site_name",
  "supplier_site_ref",
  "pay_on",
  "debit_memo_onreturn_cb",
  "fob",
  "freight_terms",
  "transportation",
  "country_of_origin",
  'currency',
  'payment_term_id',
  "supplier_site_type",
  "site_tax_country",
  "site_tax_reg_no",
  "site_tax_payer_id",
  "site_tax_code",
  "site_address_id",
  "site_contact_id",
  "allow_substitute_receipts_cb",
  "allow_unordered_receipts_cb",
  "ap_invoice_match_level",
  "receipt_routing",
  "ship_to_location_variance",
  "positive_qty_tolerance",
  "negative_qty_tolerance",
  "qty_variance",
  "positive_receipt_days_tolerance",
  "negative_receipt_days_tolerance",
  "receipt_days_variance",
  "bank_id",
  "bank_account_id",
  "primary_cb",
  "status",
  "rev_enabled_cb",
  "rev_number",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $initial_search = [
  "supplier_site_id",
  "supplier_site_number",
  "supplier_site_name",
  "supplier_site_ref"
 ];
 public $column = [
  "supplier_site_id",
  "supplier_site_number",
  "supplier_site_name",
  "supplier_site_ref"
 ];
 public $checkbox = [
  "rev_enabled_cb",
  "allow_substitute_receipts_cb",
  "allow_unordered_receipts_cb",
  "debit_memo_onreturn_cb"
 ];
 public $requiredField = [
  "supplier_id",
  "supplier_site_number",
  "supplier_site_name",
 ];
 public static $addressField = [
  "site_address_id"
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
  'supplier_id'
 ];
 public $fields_inForm_notInDataBase = [
  'site_address_name',
  'site_address',
  'site_country',
  'site_postal_code',
 ];
 public $number_fields = [
  'supplier_site_number'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=supplier',
  '_update_action_meassge' => 'Update',
 ];
 public $pageTitle = " Supplier Sites "; //page Title
 public $option_lists = [
  'supplier_site_type' => 'SUPPLIER_SITE_TYPE',
  'ap_pay_on' => 'AP_PAY_ON'
 ];
 public $supplier_site_id;
 public $supplier_site_number;
 public $supplier_site_name;
 public $supplier_site_ref;
 public $supplier_site_type;
 public $site_tax_country;
 public $pay_on;
 public $debit_memo_onreturn_cb;
 public $fob;
 public $freight_terms;
 public $transportation;
 public $country_of_origin;
 public $site_tax_reg_no;
 public $site_tax_payer_id;
 public $site_tax_code;
 public $site_address_id;
 public $site_contact_id;
 public $allow_substitute_receipts_cb;
 public $allow_unordered_receipts_cb;
 public $ap_invoice_match_level;
 public $receipt_routing;
 public $ship_to_location_variance;
 public $positive_qty_tolerance;
 public $negative_qty_tolerance;
 public $qty_variance;
 public $positive_receipt_days_tolerance;
 public $negative_receipt_days_tolerance;
 public $receipt_days_variance;
 public $bank_id;
 public $bank_account_id;
 public $currency;
 public $payment_term_id;
 public $primary_cb;
 public $status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $supplier_id;
 public $site_address_name;
 public $site_address;
 public $site_country;
 public $site_postal_code;

 Public static function ap_pay_on() {
  $option_header = option_header::find_by_name('AP_PAY_ON');
  $ap_pay_on = option_line::find_by_option_id($option_header->option_header_id);
  return $ap_pay_on;
 }

 Public static function supplier_site_types() {
  $option_header = option_header::find_by_name('SUPPLIER_SITE_TYPE');
  $coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
  return $coa_account_types;
 }

 public function _after_save() {

  if ((!empty($this->supplier_site_id)) && empty($this->supplier_site_number)) {
   $this->supplier_site_number = $this->supplier_site_id;
   $this->save();
  }
 }

 public static function find_all_sitesOfSupplier_array($supplier_id = "") {
  global $db;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE supplier_id = '{$supplier_id}' ";
  $final_array = [];
  $result_array = $db->find_by_sql($sql);
  foreach ($result_array as $array) {
   $key = $array->supplier_site_id;
   $value = $array->supplier_site_id . "-" . $array->supplier_site_name;
   $final_array[$key] = $value;
  }

//	$result = self::find_by_sql($sql);
  return $final_array;
 }

 public static function find_all_sitesOfSupplier($supplier_id = "") {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE supplier_id = '{$supplier_id}' ";

  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_primary_supplierSite($supplier_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE supplier_id = '{$supplier_id}' AND primary_cb = '1' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
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

 public function copy($supplier_site_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM supplier_site WHERE `supplier_site_id` = '{$supplier_site_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `supplier_site_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `supplier_site_id` = '{$supplier_site_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `supplier_site` SELECT * FROM tmptable WHERE `supplier_site_id` = '' ";
    if ($db->query($sql3)) {
     $this->supplier_site_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

}

//end of supplier_site class
?>