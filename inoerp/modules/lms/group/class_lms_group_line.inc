<?php

class lms_group_line extends dbObject {

 public static $table_name = "lms_group_line";
 public static $primary_column = "lms_group_line_id";
 public static $parent_primary_column = "lms_group_header_id";
 public static $key_column = 'lms_term_id';
 public static $module = "lms";
 public $field_a = [
		 'lms_group_line_id',
		 'lms_group_header_id',
		 'lms_term_id',
		 'term_start_date',
		 'term_end_date',
		 'description',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $requiredField = [
		 'lms_group_header_id',
		 'lms_term_id'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "lms_group_header_id"
 ];
 public $lms_group_line_id;
 public $lms_group_header_id;
 public $lms_term_id;
 public $term_start_date;
 public $term_end_date;
 public $description;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of lms_group_line class
?>