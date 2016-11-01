<?php

class lms_subject_line extends dbObject {

 public static $table_name = "lms_subject_line";
 public static $primary_column = "lms_subject_line_id";
 public static $parent_primary_column = "lms_subject_header_id";
 public static $key_column = 'lms_chapter_id';
 public static $module = "lms";
 public $field_a = [
		 'lms_subject_line_id',
		 'lms_subject_header_id',
		 'lms_chapter_id',
		 'required_cb',
		 'suggested_reading',
		 'graded_cb',
		 'description',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $requiredField = [
		 'lms_subject_header_id',
		 'billing_type',
		 'service_activity_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "lms_subject_header_id"
 ];
 public $lms_subject_line_id;
 public $lms_subject_header_id;
 public $billing_type;
 public $service_activity_id;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of lms_subject_line class
?>