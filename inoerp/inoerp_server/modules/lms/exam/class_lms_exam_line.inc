<?php

class lms_exam_line extends dbObject {

 public static $table_name = "lms_exam_line";
 public static $primary_column = "lms_exam_line_id";
 public static $parent_primary_column = "lms_exam_header_id";
 public static $key_column = 'lms_grade_element_id';
 public static $module = "lms";
 public $field_a = [
		 'lms_exam_line_id',
		 'lms_exam_header_id',
		 'lms_assessment_header_id',
		 'assessment_type',
		 'assessment_date',
		 'description',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $fields_intpl_header_needsToBeInserted_inPOST = [
		 "lms_exam_header_id"
 ];
 public $requiredField = [
		 'lms_exam_header_id',
		 'lms_assessment_header_id',
 ];
 public $fields_inFormr_notinDataBase = [
		 "monetary_value"
 ];
 public $lms_exam_line_id;
 public $lms_exam_header_id;
 public $lms_assessment_header_id;
 public $assessment_type;
 public $assessment_date;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 
}

//end of inv_transaction class
?>