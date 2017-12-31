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
 * hd_service_request
 * All Spport Request information
 * 
 */
class hd_service_request extends dbObject {

 public static $table_name = "hd_service_request";
 public static $primary_column = "hd_service_request_id";
 public static $key_column = 'problem_summary';
 public static $module = "hd";
 public static $system_info = [
  'name' => 'service Request',
  'number' => '5103',
  'description' => 'service Request',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 8
 ];
 public $field_a = [
  'hd_service_request_id',
  'service_request_number',
  'ar_customer_id',
//  'ar_customer_site_id',
  'inv_serial_number_id',
  'item_id_m',
  'urgency',
  'priority',
  'reason',
  'escalation',
  'problem_summary',
  'status',
  'request_type',
  'request_category',
  'assignment_group',
  'assigned_to_user_id',
  'problem_details',
  'resolution_details',
  'hd_change_request_id',
  'close_code',
  'closed_by_user_id',
  'closed_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $initial_search = [
  'service_request_number',
  'problem_summary',
 ];
 public $requiredField = [
  'ar_customer_id',
  'item_id_m',
  'problem_summary',
 ];
 public $fields_inForm_notInDataBase = [
  "assigned_username",
  'closed_by_username',
  'change_request_number',
  'item_number',
  'customer_number',
  'customer_name',
  'serial_number'
 ];
 public $profile_default = [
  'impact' => 'hd_service_request_impact',
  'request_type' => 'hd_service_request_type',
 ];
 public $hd_service_request_id;
 public $request_number;
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
 public $item_number;
 public $customer_number;
 public $customer_name;
 public $serial_number;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " service Request "; //page Title

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
  if (empty($this->request_number) && !empty($this->hd_service_request_id)) {
   $this->request_number = $prl->find_default_profile('hd_service_request_number_prefix')->level_value . $this->hd_service_request_id;
  }

  $this->save();
 }

}

//end of hd_service_request class
?>