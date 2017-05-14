<?php

class lms_section_line extends dbObject {

 public static $table_name = "lms_section_line";
 public static $primary_column = "lms_section_line_id";
 public static $parent_primary_column = "lms_section_header_id";
 public static $key_column = 'lms_student_id';
 public static $module = "lms";
 public $field_a = [
		 'lms_section_line_id',
		 'lms_section_header_id',
		 'lms_student_id',
		 'is_leader_cb',
		 'description',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $requiredField = [
		 'lms_section_header_id',
		 'lms_term_id'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "lms_section_header_id"
 ];
 public $lms_section_line_id;
 public $lms_section_header_id;
 public $lms_student_id;
 public $is_leader_cb;
 public $description;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of lms_section_line class
?>