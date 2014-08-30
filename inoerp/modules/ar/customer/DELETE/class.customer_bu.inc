<?php

class customer_bu extends customer {

 protected static $table_name = "ar_customer_bu";

 public static $field_array = [
		 "ar_customer_id",
		 "org_id",
		 "customer_bu_id",
		 "new_pos_cb",
		 "all_invoices_cb",
		 "unmatched_invoices_cb",
		 "unaccounted_invoices_cb",
		 "unpaid_invoices_cb",
		 "hold_reason",
		 "po_amount_limit",
		 "invoice_amount_limit",
		 "payment_amount_limit",
		 "bu_bank_id",
		 "bu_bank_site_id",
		 "bu_tax_code",
		 "invoice_match_document",
		 "invoice_currency",
		 "payment_priority",
		 "payment_group",
		 "payment_terms",
		 "invoice_date_basis",
		 "pay_date_basis",
		 "default_payment_method",
		 "remittance_advice_method",
		 "remittance_advice_email",
		 "org_shipto_id",
		 "org_billto_id",
		 "liability_account_id",
		 "payable_account_id",
		 "payment_discount_account_id",
		 "pre_payment_account_id",
		 "bank_id",
		 "bank_account_id",
		 'pay_on',
		 'debit_memo_onreturn_cb',
		 'fob',
		 'freight_terms',
		 'transportation',
		 'country_of_origin',
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
		 "customer_bu_id",
		 "customer_number",
		 "customer_name",
		 "ar_customer_id"
 ];
 public static $column_array = [
		 "customer_bu_id",
		 "customer_number",
		 "customer_name",
		 "ar_customer_id"
 ];
  public static $account_array = [
 ];
 public static $checkbox_array = [
		 "rev_enabled_cb",
		 "allow_substitute_receipts_cb",
		 "allow_unordered_receipts_cb",
		 "new_pos_cb",
		 "all_invoices_cb",
		 "unmatched_invoices_cb",
		 "unaccounted_invoices_cb",
		 "unpaid_invoices_cb",
		 "debit_memo_onreturn_cb"
 ];
 public static $addressField_array = [
		 "org_shipto_id",
		 "org_billto_id"
 ];
 public static $requiredField_array = [
		 "ar_customer_id",
		 "org_id"
 ];
 public static $fields_inForm_notInDataBase = [
		 "org"
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = "customer_bu_id";
 public $customer_bu_id;
 public $org_id;
 public $org;
 public $new_pos_cb;
 public $all_invoices_cb;
 public $unmatched_invoices_cb;
 public $unaccounted_invoices_cb;
 public $unpaid_invoices_cb;
 public $hold_reason;
 public $po_amount_limit;
 public $invoice_amount_limit;
 public $payment_amount_limit;
 public $pay_on;
 public $debit_memo_onreturn_cb;
 public $fob;
 public $freight_terms;
 public $transportation;
 public $country_of_origin;
 public $bu_bank_id;
 public $bu_bank_site_id;
 public $bu_tax_code;
 public $invoice_match_document;
 public $invoice_currency;
 public $payment_priority;
 public $payment_group;
 public $payment_terms;
 public $invoice_date_basis;
 public $pay_date_basis;
 public $default_payment_method;
 public $remittance_advice_method;
 public $remittance_advice_email;
 public $org_shipto_id;
 public $org_billto_id;
 public $customer_number;
 public $customer_name;
 public $ar_customer_id;
 public $address_id;
 public $contact_id;
 public $liability_account_id;
 public $payable_account_id;
 public $payment_discount_account_id;
 public $pre_payment_account_id;
 public $bank_id;
 public $bank_account_id;
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

 public static function find_by_orgId_customerId($ar_customer_id, $org_id) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where ar_customer_id= '{$ar_customer_id}' " .
					" AND org_id = '{$org_id}' " .
					" LIMIT 1 ";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_all_assigned_org_ids($ar_customer_id) {
	global $db;
	$sql = "SELECT org_id FROM " .
					self::$table_name .
					" where ar_customer_id= '{$ar_customer_id}' ";
	$result = $db->result_array_assoc($sql);
	$assigned_inventory_orgs_array = [];

	foreach ($result as $orgs) {
	 $assigned_inventory_orgs_array[] = $orgs['org_id'];
	}

	return $assigned_inventory_orgs_array;
 }

 public static function validate_customerBuAssignment($ar_customer_id, $org_id) {
	global $db;
	$sql = "SELECT org_id FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE ar_customer_id= '{$ar_customer_id}' ";
	$sql .= " AND org_id= '{$org_id}' ";
	$result = self::count_all_by_sql($sql);

	if($result > 0 ){
	 $returnValue = 1;
	}else{
	 $returnValue = 0;
	}

	return $returnValue;
 }

}

//end of customer_bu class
?>