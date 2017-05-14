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
 * adm_task_status
 * Contains all the adm_task_status information, such as - adm_task_status, adm_task_status_id, org_id,  status, etc.
 * 
 */
class adm_task_status extends dbObject {

 public static $table_name = "adm_task_status";
 public static $primary_column = "adm_task_status_id";
 public static $key_column = 'task_status';
 public static $module = "adm";
 public static $multi_select_template_path = 'modules/adm/task_status/multi_action/task_status_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'adm_task_status',
  'number' => '8002',
  'description' => 'Admin Task status',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 17
 ];
 public static $start_by_a = [
  'CREATION_DATE' => 'Creation Date',
  'SCHEDULED_START_DATE' => 'Scheduled Start Date',
  'PLANNED_START_DATE' => 'Planned Start Date',
  'ACTUAL_START_DATE' => 'Actual Start Date'
 ];
  public static $due_date_a = [
  'CREATION_DATE' => 'Creation Date',
  'SCHEDULED_END_DATE' => 'Scheduled End Date',
  'PLANNED_END_DATE' => 'Planned End Date',
  'ACTUAL_END_DATE' => 'Actual End Date'
 ];
 public $field_a = [
  'adm_task_status_id',
  'status',
  'access_level',
  'start_by',
  'due_date',
  'description',
  'from_date',
  'to_date',
  'usage',
  'primary_task_type',
  'send_notification_cb',
  'schedule_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  "task_status",
 ];
 public $checkbox = ["send_notification_cb",
  "schedule_cb"
 ];
 public $requiredField = [
  'access_level',
  'task_status',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Task status"; //page Title
 public $adm_task_status_id;
 public $status;
 public $access_level;
 public $start_by;
 public $due_date;
 public $description;
 public $from_date;
 public $to_date;
 public $usage;
 public $primary_task_type;
 public $send_notification_cb;
 public $schedule_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

   Public static function primary_task_status() {
   $option_header = option_header::find_by_name('ADM_PRIMARY_TASK_STATUS');
   $ol = option_line::find_by_option_id($option_header->option_header_id);
   return $ol;
  }
  
 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of adm_task_status class
?>