<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * lms_assessment_header CLass
 * Contains all the lms_assessment_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class lms_assessment_header extends dbObject {

 public static $table_name = "lms_assessment_header";
 public static $dependent_classes = ['lms_assessment_line'];
 public static $primary_column = "lms_assessment_header_id";
 public static $key_column = 'assessment_code';
 public static $module = "lms";
 public static $system_info = [
		 'name' => 'LMS assessment',
		 'number' => '8303',
		 'description' => 'Assessment',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'dependent_class' => array('lms_assessment_line'),
		 'primary_entity_cb' => '',
		 'module_name' => 'lms',
		 'weight' => 1
 ];
 public $field_a = [
		 'lms_assessment_header_id',
		 'assessment_name',
		 'assessment_code',
		 'overview',
		 'assessment_group',
		 'student_group',
		 'description',
		 'supervisor',
		 'examiner',
		 'grading_structure',
		 'start_date',
		 'start_time',
		 'end_date',
		 'end_time',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'assessment_name',
		 'assessment_code',
 ];
 public $requiredField = [
		 'assessment_name',
		 'assessment_code',
 ];
 public $fields_inForm_notInDataBase = [
		 'action',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1
 ];
 public $pageTitle = " Assessment  "; //page Title
 public $lms_assessment_header_id;
 public $assessment_name;
 public $assessment_code;
 public $overview;
 public $assessment_group;
 public $student_group;
 public $description;
 public $supervisor;
 public $examiner;
 public $grading_structure;
 public $start_date;
 public $start_time;
 public $end_date;
 public $end_time;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function primary_service_type() {
	$option_header = option_header::find_by_name('HD_PRI_SERVICE_TYPE');
	$ol = new option_line();
	$option_lines = $ol->findBy_parentId($option_header->option_header_id);
	return $option_lines;
 }

 Public static function billing_type() {
	$option_header = option_header::find_by_name('SYS_BILLING_TYPE');
	$ol = new option_line();
	$option_lines = $ol->findBy_parentId($option_header->option_header_id);
	return $option_lines;
 }

}

//end of lms_assessment_header class
?>