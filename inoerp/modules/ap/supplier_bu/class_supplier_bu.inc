<?php

class supplier_bu extends dbObject {

 public static $table_name = "supplier_bu";
 public static $primary_column = "supplier_bu_id";
 public static $dependent_classes = ['supplier', 'supplier_site'];
 public static $key_column = 'supplier_id';
 public static $module = "ap";
   public static $system_info = [
   'name' => 'Supplier BU ',
   'number' => '1202',
   'description' => 'Supplier Business Unit Association',
   'version' => '0.1.1',
   'db_version' => '1001',
   'mod_version' => '1.1.1',
//   'dependent_class' => array('ap_transaction_line', 'ap_transaction_detail', 'ap_transaction_v'),
   'primary_entity_cb' => '',
   'module_name' => 'ap',
   'weight' => 2
  ];
 public $field_a = [
		 "supplier_id",
		 "org_id",
		 "supplier_bu_id",
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
 public $initial_search = [
		 "supplier_bu_id",
		 "supplier_id",
		 "org_id",
 ];
 public $column = [
		 "supplier_bu_id",
		 "supplier_id",
		 "org_id",
 ];
 public $account = [
		 "liability_account_id",
		 "payable_account_id",
		 "payment_discount_account_id",
		 "pre_payment_account_id",
 ];
 public $checkbox = [
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
 public $addressField = [
		 "org_shipto_id",
		 "org_billto_id"
 ];
 public $requiredField = [
		 "supplier_id",
		 "org_id"
 ];
 public $fields_inForm_notInDataBase = [
		 "org"
 ];
 public $supplier_bu_id;
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
 public $supplier_number;
 public $supplier_name;
 public $supplier_id;
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

 public function findBy_orgId_supplierId($org_id , $supplier_id ) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where supplier_id= :supplier_id " .
					" AND org_id = :org_id " .
					" LIMIT 1 ";
	$param_a = ['supplier_id', 'org_id'];
	$value_a = [ 'supplier_id' => $supplier_id, 'org_id' => $org_id];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
	return !(empty($result)) ? array_pop($result) : false;
 }
 
  public function findBy_supplier_name($limit = 30) {
	global $db;
	$sql = " SELECT * FROM "
					. self::$table_name
					. " where supplier_name LIKE :supplier_name LIMIT $limit";
	$param_a = ['supplier_name'];
	$supplier_name = '%' . $this->supplier_name . '%';
	$value_a = [ 'supplier_name' => $supplier_name];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
	return !(empty($result)) ? $result : false;
	
 }

 public static function find_all_assigned_org_ids($supplier_id) {
	global $db;
	$sql = "SELECT org_id FROM " .
					self::$table_name .
					" where supplier_id= '{$supplier_id}' ";
	$result = $db->find_by_sql($sql);
	$assigned_inventory_orgs_array = [];

	foreach ($result as $orgs) {
	 $assigned_inventory_orgs_array[] = $orgs->org_id;
	}

	return $assigned_inventory_orgs_array;
 }

 public static function validate_supplierBuAssignment($supplier_id, $org_id) {
	global $db;
	$sql = "SELECT org_id FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE supplier_id= '{$supplier_id}' ";
	$sql .= " AND org_id= '{$org_id}' ";
	$result = self::count_all_by_sql($sql);

	if ($result > 0) {
	 $returnValue = 1;
	} else {
	 $returnValue = 0;
	}

	return $returnValue;
 }

}

//end of supplier_bu class
?>