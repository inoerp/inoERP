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
 * lms_term
 * All Job information
 * Contains all the lms_term information, such as - lms_term_id, job_code , job_name, etc
 * 
 */
class lms_term extends dbObject {

 public static $table_name = "lms_term";
 public static $primary_column = "lms_term_id";
 public static $key_column = 'term_name';
 public static $module = "lms";
 public static $system_info = [
		 'name' => 'Term',
		 'number' => '8304',
		 'description' => 'Term',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'lms',
		 'weight' => 8
 ];
 public $field_a = [
		 'lms_term_id',
		 'term_name',
		 'term_code',
		 'overview',
		 'description',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'term_name',
		 'term_code',
 ];
 public $column = [
		 'lms_term_id',
		 'term_name',
		 'term_code',
		 'overview',
 ];
 public $requiredField = [
		 'term_name',
		 'term_code'
 ];
 
 public $lms_term_id;
public $term_name;
public $term_code;
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
 public $pageTitle = " Term  "; //page Title


}

//end of lms_term class
?>