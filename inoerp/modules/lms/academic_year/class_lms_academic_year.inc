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
 * lms_academic_year
 * All Job information
 * Contains all the lms_academic_year information, such as - lms_academic_year_id, job_code , job_name, etc
 * 
 */
class lms_academic_year extends dbObject {

 public static $table_name = "lms_academic_year";
 public static $primary_column = "lms_academic_year_id";
 public static $key_column = 'job_code';
 public static $module = "lms";
 public static $system_info = [
		 'name' => 'academic_year',
		 'number' => '8304',
		 'description' => 'academic_year',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'lms',
		 'weight' => 8
 ];
 public $field_a = [
		 'lms_academic_year_id',
		 'academic_year_name',
		 'academic_year_code',
		 'overview',
		 'description',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'academic_year_name',
		 'academic_year_code',
 ];
 public $column = [
		 'lms_academic_year_id',
		 'academic_year_name',
		 'academic_year_code',
		 'overview',
 ];
 public $requiredField = [
		 'academic_year_name',
		 'academic_year_code'
 ];
 
 public $lms_academic_year_id;
public $academic_year_name;
public $academic_year_code;
public $overview;
public $description;
public $status;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;

 
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " academic_year  "; //page Title


}

//end of lms_academic_year class
?>