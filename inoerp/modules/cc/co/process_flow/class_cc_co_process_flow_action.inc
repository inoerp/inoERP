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
 * cc_co_process_flow_action : Change Control Process Flow Actions
 * Change Control Process Flow Actions is used to track all the actions taken.
 * Contains all the cc_co_header information, such as - change_number, description , template_id, org_id, change_type
 * 
 */
class cc_co_process_flow_action extends dbObject {

 public static $table_name = "cc_co_process_flow_action";
 public static $primary_column = "cc_co_process_flow_action_id";
 public static $parent_primary_column = "cc_co_header_id";
 public static $key_column = "pf_action_type";
 public static $module = "sys";
  public static $system_info = [
  'name' => 'CC Action',
  'number' => '9302',
  'description' => 'Change Control Process Flow Actions',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'cc',
  'weight' => '2'
 ];
  
 public static $pf_action_type_a = [
  'APPROVAL' => 'Approval',
  'INFORMATION' => 'Information',
 ];
 public static $value_a = [
  'APPROVE' => 'Approve',
  'REJECT' => 'Reject',
  'HOLD' => 'Hold'
 ];
 public $field_a = [
  'cc_co_process_flow_action_id',
  'cc_co_header_id',
  'sys_process_flow_line_id',
  'action_number',
  'role_code',
  'user_id',
  'pf_action_type',
  'required_cb',
  'field_value',
  'comment',
  'action_user_id',
  'action_duration',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'cc_co_header_id',
 ];
 public $requiredField = [
  'cc_co_header_id',
  'pf_action_type',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "cc_co_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  "username",
 ];
 public $pageTitle = " CC Process Flow Action "; //page Title
 public $cc_co_process_flow_action_id;
 public $cc_co_header_id;
 public $sys_process_flow_line_id;
 public $action_number;
 public $role_code;
 public $pf_action_type;
 public $user_id;
 public $required_cb;
 public $value;
 public $comment;
 public $action_user_id;
 public $action_duration;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $username;
 public $action_user_name;

 public static function find_by_headerId_pfLineId($header_id, $pf_line_id) {
  $sql = " SELECT *
FROM cc_co_process_flow_action
WHERE 
cc_co_header_id = '{$header_id}' AND sys_process_flow_line_id = '{$pf_line_id}'
";

  $result = self::find_by_sql($sql);

  return !empty($result) ? $result : false;
 }

}

//end of path class
?>