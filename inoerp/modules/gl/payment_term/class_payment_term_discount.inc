<?php

class payment_term_discount extends dbObject {

 public static $table_name = "payment_term_discount";
 public static $parent_primary_column = "payment_term_id";
 public static $primary_column = "payment_term_discount_id";
 public static $key_column = 'discount_percentage';
 public static $module = "gl";

 public $field_a = [
		 'payment_term_discount_id',
		 'payment_term_id',
		 'seq_number',
		 'discount_percentage',
		 'due_days',
		 'due_dates',
		 'due_date_of_month',
		 "ef_id",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];

 public $requiredField = [
		 'payment_term_id',
		 'seq_number',
		 'discount_percentage'
 ];

 public $payment_term_discount_id;
 public $payment_term_id;
 public $seq_number;
 public $discount_percentage;
 public $due_days;
 public $due_dates;
 public $due_date_of_month;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function find_by_payment_termId($term_id) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where payment_term_id= '{$term_id}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of payment_term_discount class
?>