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




}

//end of lms_student_fee class
?>