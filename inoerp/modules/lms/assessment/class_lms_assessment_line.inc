<?php

class lms_assessment_line extends dbObject {

 public static $table_name = "lms_assessment_line";
 public static $primary_column = "lms_assessment_line_id";
 public static $parent_primary_column = "lms_assessment_header_id";
 public static $key_column = 'student_id';
 public static $module = "lms";
 public $field_a = [
		 'lms_assessment_line_id',
		 'lms_assessment_header_id',
		 'student_exam_id',
		 'student_id',
		 'student_mark',
		 'student_grade',
		 'description',
		 'rank',
		 'percentile',
		 'attempt_number',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $requiredField = [
		 'lms_assessment_header_id',
		 'lms_term_id'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "lms_assessment_header_id"
 ];
 public $lms_assessment_line_id;
 public $lms_assessment_header_id;
 public $student_exam_id;
 public $student_id;
 public $student_mark;
 public $student_grade;
 public $description;
 public $rank;
 public $percentile;
 public $attempt_number;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of lms_assessment_line class
?>