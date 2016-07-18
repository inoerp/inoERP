<?php

/**
 * inoERP
 *
 * @copyright 2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * hr_approval_limit_assignment
 * Approval limit assignment is used for assigning document type, approval limit and job/position.
 * Contains all the hr_approval_limit_assignment information, such as - document_type, bu_org_id , start_date, etc
 * 
 */
class hr_approval_limit_assignment extends dbObject {

 public static $table_name = "hr_approval_limit_assignment";
 public static $primary_column = "hr_approval_limit_assignment_id";
 public static $key_column = 'hr_approval_limit_header_id';
 public static $module = "hr";
 public static $system_info = [
  'name' => 'Limit Assignment',
  'number' => '3102',
  'description' => 'HR Approval Limit Assignment',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 2
 ];
 public $field_a = [
  'hr_approval_limit_assignment_id',
  'hr_approval_limit_header_id',
  'bu_org_id',
  'job_id',
  'position_id',
  'document_type',
  'start_date',
  'end_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'hr_approval_limit_header_id',
  'bu_org_id',
  'job_id',
 ];
 public $requiredField = [
  'hr_approval_limit_header_id',
  'document_type',
 ];
 public $hr_approval_limit_assignment_id;
 public $hr_approval_limit_header_id;
 public $bu_org_id;
 public $job_id;
 public $position_id;
 public $document_type;
 public $start_date;
 public $end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " HR Approval Limit Assignments  "; //page Title

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

 public function findBy_params() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  if (!empty($this->position_id)) {
   $sql .= " WHERE position_id = '{$this->position_id}' ";
  } else if (!empty($this->job_id)) {
   $sql .= " WHERE job_id = '{$this->job_id}' ";
  } else if (!empty($this->bu_org_id)) {
   $sql .= " WHERE bu_org_id = '{$this->bu_org_id}' ";
  } else {
   return false;
  }
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of hr_approval_limit_assignment class
?>