<?php

class customer_site extends dbObject {

 protected static $table_name = "ar_customer_site";

 public static $field_array = [
		 "customer_site_id",
		 'ar_customer_id',
		 "customer_site_number",
		 "customer_site_name",
		 "customer_site_ref",
		 "pay_on",
		 "debit_memo_onreturn_cb",
		 "fob",
		 "freight_terms",
		 "transportation",
		 "country_of_origin",
		 'currency',
		 'payment_term_id',
		 "customer_site_type",
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
		 "ef_id",
		 "status",
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $initial_search_array = [
		 "customer_site_id",
		 "customer_site_number",
		 "customer_site_name",
		 "customer_site_ref"
 ];
 public static $column_array = [
		 "customer_site_id",
		 "customer_site_number",
		 "customer_site_name",
		 "customer_site_ref"
 ];
 
  public static $account_array = [
 ];
 public static $checkbox_array = [
		 "rev_enabled_cb",
		 "allow_substitute_receipts_cb",
		 "allow_unordered_receipts_cb",
		 "debit_memo_onreturn_cb"
 ];
 
 public static $requiredField_array = [
		 "ar_customer_id",
		 "customer_site_number",
		 "customer_site_name",
 ];
 public static $addressField_array = [
		 "site_address_id"
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
		 'ar_customer_id'
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = "ar_customer_site_id";
 public $ar_customer_site_id;
 public $customer_site_number;
 public $customer_site_name;
 public $customer_site_ref;
 public $customer_site_type;
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
 public $ef_id;
 public $status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $ar_customer_id;

 
 Public static function customer_site_types() {
	$option_header = option_header::find_by_name('CUSTOMER_SITE_TYPE');
	$coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
	return $coa_account_types;
 }

 public static function find_all_sitesOfCustomer_array($customer_id = "") {
	global $db;
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE ar_customer_id = '{$customer_id}' ";
	$final_array = [];
	$result_array = $db->result_array_assoc($sql);
	foreach ($result_array as $array) {
	 $key = $array['customer_site_id'];
	 $value = $array['customer_site_id'] . "-" . $array['customer_site_name'];
	 $final_array[$key] = $value;
	}

//	$result = self::find_by_sql($sql);
	return $final_array;
 }

 public static function find_all_sitesOfCustomer($customer_id = "") {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE ar_customer_id = '{$customer_id}' ";

	$result = self::find_by_sql($sql);
	return $result;
 }

 public function copy($customer_site_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM customer_site WHERE `customer_site_id` = '{$customer_site_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `customer_site_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `customer_site_id` = '{$customer_site_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `customer_site` SELECT * FROM tmptable WHERE `customer_site_id` = '' ";
		if ($db->query($sql3)) {
		 $this->customer_site_id = $db->insert_id();
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