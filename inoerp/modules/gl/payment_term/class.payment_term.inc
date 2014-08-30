<?php
class payment_term extends dbObject {

  public static $table_name = "payment_term";
 public static $dependent_classes = ['payment_term_discount','payment_term_schedule'];
 public static $primary_column = "payment_term_id";
 public static $key_column = 'payment_term';
 public static $module = "gl";
 
public $checkbox = [
		 "rev_enabled_cb",
		 "prepayment_cb"
 ];
 public $field_a = [
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
 
 public $initial_search = [
'payment_term_id',
		 'payment_term',
		 'description',
 ];
 public $column = [
'payment_term_id',
		 'payment_term',
		 'description'
 ];
 public $requiredField = [
		 'payment_term',
		 'description'
 ];

  public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Payment Term "; //page Title

 
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