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
 * adm_task_type
 * Contains all the adm_task_type information, such as - adm_task_type, adm_task_type_id, org_id,  type, etc.
 * 
 */
class adm_task_type extends dbObject {

 public static $table_name = "adm_task_type";
 public static $primary_column = "adm_task_type_id";
 public static $key_column = 'task_type';
 public static $module = "adm";
 public static $multi_select_template_path = 'modules/adm/task_type/multi_action/task_type_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'adm_task_type',
  'number' => '8001',
  'description' => 'Admin Task Type',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 17
 ];
 public $field_a = [
  'adm_task_type_id',
  'access_level',
  'task_type',
  'process_flow_header_id',
  'description',
  'from_date',
  'to_date',
  'effort_uom_id',
  'effort_value',
  'send_notification_cb',
  'schedule_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  "task_type",
 ];
 public $checkbox = ["send_notification_cb",
  "schedule_cb"
 ];
 public $requiredField = [
 'access_level',
  'task_type',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 
 
 public $pageTitle = " Task Type"; //page Title

public $adm_task_type_id;
public $access_level;
public $task_type;
public $process_flow_header_id;
public $description;
public $from_date;
public $to_date;
public $effort_uom_id;
public $effort_value;
public $send_notification_cb;
public $schedule_cb;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;

 public $time;
 public $msg;
 
 public function findBy_parameter_withOrgDetails() {
  $value_a = [];
  $sql = " SELECT si.adm_task_type_id,si.type,si.adm_task_type,si.description, org.org,org.org_id  ";
  $sql .= 'From 
            adm_task_type si,
            org ';
  $sql .= " WHERE si.org_id = org.org_id ";
  if (!empty($this->org_id)) {
   $sql .= " AND org.org_id = :org_id ";
   $value_a['org_id'] = $this->org_id;
  }

  if (!empty($this->adm_task_type_id)) {
   $sql .= " AND si.adm_task_type_id = :adm_task_type_id ";
   $value_a['adm_task_type_id'] = $this->adm_task_type_id;
  }
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? $result : false;
 }

 public static function find_all_of_org_id($org_id) {
  global $db;
  if (!empty($org_id)) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE org_id = '{$org_id}' ";
   $result = $db::find_by_sql($sql);
  } else {
   $result = null_instantitae('adm_task_type');
  }
  return $result;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }
 

}

//end of adm_task_type class
?>