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
 * lms_subject_header CLass
 * Contains all the lms_subject_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class lms_subject_header extends dbObject {

 public static $table_name = "lms_subject_header";
 public static $dependent_classes = ['lms_subject_line'];
 public static $primary_column = "lms_subject_header_id";
 public static $key_column = 'subject_name';
 public static $module = "lms";
 public static $system_info = [
		 'name' => 'LMS Subject',
		 'number' => '8302',
		 'description' => 'Create & Mainten Subject',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'dependent_class' => array('lms_subject_line'),
		 'primary_entity_cb' => '',
		 'module_name' => 'hd',
		 'weight' => 1
 ];
 public static $line_category_a = [
		 'ORDER' => 'Order',
		 'RETURN' => 'Return'
 ];
 public $field_a = [
		 'lms_subject_header_id',
		 'subject_name',
		 'subject_code',
		 'overview',
		 'objectives',
		 'structure',
		 'description',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 
  public $column = [
	 'lms_subject_header_id',
		 'subject_name',
		 'subject_code',
		  'description',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
	
 public $initial_search = [
		 'subject_name',
		 'subject_code',
 ];
 public $requiredField = [
		 'subject_name',
		 'subject_code',
 ];
 public $fields_inForm_notInDataBase = [
		 'action',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1
 ];
 public $pageTitle = " Subject  "; //page Title
 
 public $lms_subject_header_id;
 public $subject_name;
 public $subject_code;
 public $overview;
 public $objectives;
 public $structure;
 public $description;
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

//end of lms_subject_header class
?>