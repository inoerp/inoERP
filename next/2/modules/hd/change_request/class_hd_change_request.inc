<?php

/**
 * inoERP
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * hd_change_request
 * All Spport Request information
 * 
 */
class hd_change_request extends dbObject {

 public static $table_name = "hd_change_request";
 public static $primary_column = "hd_change_request_id";
 public static $key_column = 'subject';
 public static $module = "hd";
 public static $system_info = [
  'name' => 'change Request',
  'number' => '5101',
  'description' => 'change Request',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 8
 ];
 public $field_a = [
  'hd_change_request_id',
  'request_number',
  'requester_user_id',
  'requester_username',
  'requester_email',
  'requester_phone',
  'impact',
  'urgency',
  'priority',
  'reason',
  'requested_by_date',
  'subject',
  'status',
  'request_type',
  'request_category',
  'assignment_group',
  'assigned_to_user_id',
  'description',
  'chane_details',
  'hd_support_request_id',
  'planned_start_date',
  'planned_end_date',
  'work_start_date',
  'work_end_date',
  'technical_approver',
  'functional_approver',
  'dba_approver',
  'work_completed_by',
  'change_plan',
  'rollback_plan',
  'communication_plan',
  'test_paln',
  'test_results',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'request_number',
  'request_type'
 ];
 public $requiredField = [
  'subject',
  'description'
 ];
 public $fields_inForm_notInDataBase = [
  "assigned_username",
  'work_completed_by_username',
  'dba_approver_username',
  'functional_approver_username',
  'technical_approver_username',
  'support_number'
 ];
 public $profile_default = [
  'impact' => 'hd_change_request_impact',
  'request_type' => 'hd_change_request_type',
 ];
 public $hd_change_request_id;
 public $request_number;
 public $requester_user_id;
 public $requester_username;
 public $requester_email;
 public $requester_phone;
 public $impact;
 public $urgency;
 public $priority;
 public $reason;
 public $requested_by_date;
 public $subject;
 public $status;
 public $request_type;
 public $request_category;
 public $assignment_group;
 public $assigned_to_user_id;
 public $description;
 public $chane_details;
 public $hd_support_request_id;
 public $planned_start_date;
 public $planned_end_date;
 public $work_start_date;
 public $work_end_date;
 public $technical_approver;
 public $functional_approver;
 public $dba_approver;
 public $work_completed_by;
 public $change_plan;
 public $rollback_plan;
 public $communication_plan;
 public $test_paln;
 public $test_results;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $dba_approver_username;
 public $functional_approver_username;
 public $technical_approver_username;
 public $assigned_username;
 public $work_completed_by_username;
 public $change_request_number;
 public $support_number;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Change Request "; //page Title

 public function _after_save() {
  global $prl;
  if (empty($this->request_number) && !empty($this->hd_change_request_id)) {
   $this->request_number = $prl->find_default_profile('hd_change_request_number_prefix')->level_value . $this->hd_change_request_id;
  }

  $this->save();
 }

 Public static function cr_type() {
  $option_header = option_header::find_by_name('HD_CR_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

}

//end of hd_change_request class
?>