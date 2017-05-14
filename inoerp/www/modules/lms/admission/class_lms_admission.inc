<?php

/**
 * inoERP - Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * lms_admission
 * All Job information
 * Contains all the lms_admission information, such as - lms_admission_id, job_code , job_name, etc
 * 
 */
class lms_admission extends dbObject {

 public static $table_name = "lms_admission";
 public static $primary_column = "lms_admission_id";
 public static $key_column = 'lms_group_header_id';
 public static $module = "lms";
 public static $system_info = [
		 'name' => 'admission',
		 'number' => '8304',
		 'description' => 'LMS Academic',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'lms',
		 'weight' => 8
 ];
 public $field_a = [
		 'lms_admission_id',
		 'lms_academic_year_id',
		 'lms_group_header_id',
		 'start_date',
		 'currency_code',
		 'admission_fee',
		 'description',
		 'admission_title',
		 'application_form_route',
		 'addmission_form_route',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'lms_academic_year_id',
		 'lms_group_header_id'
 ];
 public $requiredField = [
		 'lms_academic_year_id',
		 'lms_group_header_id',
 ];
 public $lms_admission_id;
 public $lms_academic_year_id;
 public $lms_group_header_id;
 public $start_date;
 public $currency_code;
 public $admission_fee;
 public $description;
 public $admission_title;
 public $application_form_route;
 public $addmission_form_route;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Academic Year  "; //page Title

}

//end of lms_admission class
?>