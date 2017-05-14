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
 * hr_timesheet_period
 * Contains all the hr_timesheet_period information, such as - hr_timesheet_period, hr_timesheet_period_id, org_id,  type, etc.
 * 
 */
class hr_timesheet_period extends dbObject {

 public static $table_name = "hr_timesheet_period";
 public static $primary_column = "hr_timesheet_period_id";
 public static $key_column = 'timesheet_period';
 public static $module = "hr";
 public static $multi_select_template_path = 'modules/hr/timesheet_period/multi_action/hr_timesheet_period_template_ma.php';
 public static $js_fileName = 'modules/hr/timesheet_period/timesheet_period.js';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'HR Timesheet Period',
  'number' => '3123',
  'description' => 'hr_timesheet_period',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 17
 ];
 public static $status_a = [
  'OPEN' => 'Open',
  'CLOSED' => 'Closed'
 ];
 public $field_a = [
  'hr_timesheet_period_id',
  'timesheet_period',
  'from_date',
  'to_date',
  'max_work_hour',
  'max_billable_hour',
  'description',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'timesheet_period',
  'description',
 ];
 public $requiredField = [
  'timesheet_period',
  'from_date',
  'to_date',
  'status',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "HR Timesheet Period"; //page Title
 public $hr_timesheet_period_id;
 public $timesheet_period;
 public $from_date;
 public $to_date;
 public $max_work_hour;
 public $max_billable_hour;
 public $description;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 
  public static function find_by_fromDate($date ) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE from_date = '{$date}'  ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of hr_timesheet_period class
?>