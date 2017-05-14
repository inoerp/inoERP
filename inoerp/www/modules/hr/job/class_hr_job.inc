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
 * hr_job
 * All Job information
 * Contains all the hr_job information, such as - hr_job_id, job_code , job_name, etc
 * 
 */
class hr_job extends dbObject {

 public static $table_name = "hr_job";
 public static $primary_column = "hr_job_id";
 public static $key_column = 'job_code';
 public static $module = "hr";
 public static $system_info = [
  'name' => 'Job',
  'number' => '3108',
  'description' => 'HR Job',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 8
 ];
 public static $template_type = [
  'header_tab' => 1,
  'line_tab' => 2,
  'nooffields_header_tab1' => 5,
  'nooffields_line_tab1' => 6,
  'nooffields_line_tab2' => 6,
 ];
 
 public static $usage_a = [
  'HR' => 'Human Resource',
  'PROJECT' => 'Project',
  'ALL' => 'All',
 ];
 
 public $field_a = [
  'hr_job_id',
  'job_code',
  'job_name',
  'start_date',
  'end_date',
  'description',
  'min_education',
  'min_experience',
  'technology',
  'skillset',
  'position_type',
  'functional_area',
  'job_usage',
  'group_hr_job_id',
  'location',
  'job_level',
  'status',
  'job_details',
  'primary_responsibility',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'hr_job_id',
  'job_code',
  'job_name',
 ];
 public $column = [
  'hr_job_id',
  'job_code',
  'job_name',
  'start_date',
  'end_date',
  'description',
 ];
 public $requiredField = [
  'job_code',
  'job_name',
  'start_date',
 ];
 public $hr_job_id;
 public $job_code;
 public $job_name;
 public $start_date;
 public $end_date;
 public $description;
 public $min_education;
 public $min_experience;
 public $technology;
 public $skillset;
 public $position_type;
 public $functional_area;
 public $location;
 public $job_usage;
 public $job_level;
 public $group_hr_job_id;
 public $status;
 public $job_details;
 public $primary_responsibility;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " HR Jobs  "; //page Title

 Public static function job_position_type() {
  $option_header = option_header::find_by_name('HR_JOB_POSITION_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function job_functional_area() {
  $option_header = option_header::find_by_name('HR_JOB_FUNCTIONAL_AREA');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 public static function find_all_header_levels() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'HEADER' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_all_line_levels() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'LINE' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_transactionClass($class) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE type_class = '{$class}' AND status='active'";
  $result = self::find_by_sql($sql);
  return $result;
 }

}

//end of hr_job class
?>