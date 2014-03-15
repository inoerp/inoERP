<?php

class payment_term extends dbObject {

 protected static $table_name = "payment_term";
 public static $account_array = [
 ];
 public static $checkbox_array = [
		 "rev_enabled_cb",
		 "prepayment_cb"
 ];
 public static $field_array = [
		 'payment_term_id',
		 'payment_term',
		 'description',
		 'prepayment_cb',
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
'payment_term_id',
		 'payment_term',
		 'description',
 ];
 public static $column_array = [
'payment_term_id',
		 'payment_term',
		 'description'
 ];
 public static $requiredField_array = [
		 'payment_term',
		 'description'
 ];
 public static $addressField_array = [
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = "payment_term_id";
 public $payment_term_id;
 public $payment_term;
 public $description;
 public $prepayment_cb;
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

}

//end of payment_term class
?>