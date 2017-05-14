<?php

class lms_student_fee extends dbObject {

 public static $table_name = "lms_student_fee";
 public static $module = "lms";
 public static $primary_column = "lms_student_fee_id";
 public static $key_column = "lms_student_id";
 public static $system_info = [
		 'name' => 'Student Fee',
		 'number' => '8307',
		 'description' => 'Student Fee',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'primary_entity_cb' => '',
		 'module_name' => 'lms',
		 'weight' => 'l'
 ];
 public $field_a = [
		 'lms_student_fee_id',
		 'lms_student_id',
		 'lms_fee_struct_header_id',
		 'currency',
		 'fee_amount',
		 'status',
		 'description',
		 'paid_amount',
		 'tax_amount',
		 'invoice_status',
		 'ar_transaction_header_id',
		 'payment_status',
		 'ar_receipt_header_id',
		 'tax_ac_id',
		 'effective_start_date',
		 'effective_end_date',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'org_id',
		 'tax_code',
		 'tax_type',
		 'dr_cr',
		 'description',
 ];
 public $requiredField = [
		 'lms_student_id',
		 'lms_fee_struct_header_id',
		 'currency',
		 'fee_amount',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 'org_id'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Student Fee "; //page Title
 public $option_list = [
		 'tax_type' => 'MDM_TAX_TYPE',
 ]; //list of search fields wh
 
 
 public $lms_student_fee_id;
 public $lms_student_id;
 public $lms_fee_struct_header_id;
 public $currency;
 public $fee_amount;
 public $status;
 public $description;
 public $paid_amount;
 public $tax_amount;
 public $invoice_status;
 public $ar_transaction_header_id;
 public $payment_status;
 public $ar_receipt_header_id;
 public $tax_ac_id;
 public $effective_start_date;
 public $effective_end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;


 public static function find_all_outTax_by_bu_org_id($org_id) {
	$sql = " 
	 SELECT *
	 FROM lms_student_fee
	 WHERE org_id = '{$org_id}'
	 AND in_out = 'OUT'
	";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_all_inTax_by_bu_org_id($org_id) {
	$sql = " 
	 SELECT *
	 FROM lms_student_fee
	 WHERE org_id = '{$org_id}'
	 AND in_out = 'IN'
	";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_all_outTax_by_inv_org_id($org_id) {
	$sql = " 
	 SELECT mtc.lms_student_fee_id, mtc.org_id, mtc.tax_code, mtc.tax_type, mtc.dr_cr,mtc.in_out,
	 mtc.description, mtc.printed_tax_name, mtc.tax_regime, mtc.tax_jurisdiction,
	 mtc.offset_tax_code, mtc.allow_adhoc_rate_cb, mtc.allow_tax_exemptions_cb, mtc.calculation_method,
	 mtc.percentage, mtc.tax_amount, mtc.tax_ac_id, mtc.status, mtc.effective_start_date,
	 mtc.effective_end_date
	 FROM lms_student_fee mtc
	 LEFT JOIN org on org.business_org_id = mtc.org_id
	 WHERE org.org_id = '{$org_id}'
	 AND in_out = 'OUT'
	";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_all_inTax_by_inv_org_id($org_id) {
	$sql = " 
	 SELECT mtc.lms_student_fee_id, mtc.org_id, mtc.tax_code, mtc.tax_type, mtc.dr_cr,
	 mtc.description, mtc.printed_tax_name, mtc.tax_regime, mtc.tax_jurisdiction,
	 mtc.offset_tax_code, mtc.allow_adhoc_rate_cb, mtc.allow_tax_exemptions_cb, mtc.calculation_method,
	 mtc.percentage, mtc.tax_amount, mtc.tax_ac_id, mtc.status, mtc.effective_start_date,
	 mtc.effective_end_date, org.org
	 FROM lms_student_fee mtc
	 LEFT JOIN org on org.business_org_id = mtc.org_id
	 WHERE org.org_id = '{$org_id}'
	 AND in_out = 'IN'
	";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of lms_student_fee class
?>