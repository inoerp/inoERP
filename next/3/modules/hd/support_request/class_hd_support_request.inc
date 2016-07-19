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
 * hd_support_request
 * All Spport Request information
 * 
 */
class hd_support_request extends dbObject {

 public static $table_name = "hd_support_request";
 public static $primary_column = "hd_support_request_id";
 public static $key_column = 'subject';
 public static $module = "hd";
 public static $system_info = [
  'name' => 'Support Request',
  'number' => '5104',
  'description' => 'Support Request',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 8
 ];
 public static $template_type = [
  'header_tab' => 1,
  'line_tab' => 2,
  'nooffields_header_tab1' => 5,
  'nooffields_line_tab1' => 6,
  'nooffields_line_tab2' => 6,
 ];
 public $field_a = [
  'hd_support_request_id',
  'support_number',
  'requester_user_id',
  'requester_username',
  'requester_email',
  'requester_phone',
  'impact',
  'urgency',
  'priority',
  'reason',
  'escalation',
  'subject',
  'status',
  'request_type',
  'request_category',
  'assignment_group',
  'assigned_to_user_id',
  'description',
  'resolution_details',
  'hd_change_request_id',
  'close_code',
  'closed_by_user_id',
  'closed_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'support_number',
  'request_type'
 ];
 public $requiredField = [
  'subject',
  'description'
 ];
 public $fields_inForm_notInDataBase = [
  "assigned_username",
  'closed_by_username',
  'change_request_number'
 ];
 public $profile_default = [
  'impact' => 'hd_support_request_impact',
  'request_type' => 'hd_support_request_type',
 ];
 public $hd_support_request_id;
 public $support_number;
 public $request_number;
 public $change_request_number;
 public $requester_user_id;
 public $requester_username;
 public $requester_email;
 public $requester_phone;
 public $impact;
 public $urgency;
 public $priority;
 public $reason;
 public $escalation;
 public $subject;
 public $status;
 public $request_type;
 public $request_category;
 public $assignment_group;
 public $assigned_to_user_id;
 public $description;
 public $resolution_details;
 public $hd_change_request_id;
 public $close_code;
 public $closed_by_user_id;
 public $closed_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $assigned_username;
 public $closed_by_username;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Support Request "; //page Title

 Public static function sr_impact() {
  $option_header = option_header::find_by_name('HD_SR_IMPACT');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function sr_status() {
  $option_header = option_header::find_by_name('HD_SR_STATUS');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function sr_type() {
  $option_header = option_header::find_by_name('HD_SR_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function sr_category() {
  $option_header = option_header::find_by_name('HD_SR_CATEGORY');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function sr_escalation() {
  $option_header = option_header::find_by_name('HD_SR_ESCALATION');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }
 
  Public static function sr_close_code() {
  $option_header = option_header::find_by_name('HD_SR_CLOSE_CODE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 
 public function _after_save() {
  global $prl;
  if (empty($this->request_number) && !empty($this->hd_support_request_id)) {
   $this->request_number = $prl->find_default_profile('hd_support_request_number_prefix')->level_value . $this->hd_support_request_id;
  }
  
  $this->save();
 }

}

//end of hd_support_request class
?>