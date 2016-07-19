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
 * hd_ro_header CLass
 * Contains all the prj_status_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class prj_status_header extends dbObject {

 public static $table_name = "prj_status_header";
 public static $dependent_classes = ['prj_status_line', 'prj_status_next'];
 public static $primary_column = "prj_status_header_id";
 public static $key_column = 'user_status';
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Project',
  'number' => '6019',
  'description' => 'Create & Mainten Project Status',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('prj_status_line', 'prj_status_next'),
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 1
 ];
 public $action_a = [
  'APPROVE' => 'Approve',
  'PRINT' => 'Print Estimates',
  'CANCEL' => 'Cancel',
  'CLOSE' => 'Close',
  'CREATE_WO' => 'Create Work Order',
  'COPY_ESTIMATES' => 'Copy Estimates to Actuals',
  'COPY_WO' => 'Copy WO Charges to Actuals',
  'PROCESS_LOGISTICS' => 'Process Logistics',
  'PROCESS_ACTUALS' => 'Process Actuals',
 ];
 public $field_a = [
  'prj_status_header_id',
  'user_status',
  'system_status',
  'description',
  'from_date',
  'to_date',
  'starting_status_cb',
  'ending_status_cb',
  'sys_process_flow_header_id',
  'next_allowed_status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'user_status',
  'system_status',
  'description',
 ];
 public $requiredField = [
  'user_status',
  'system_status',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project Status "; //page Title
 public $prj_status_header_id;
 public $user_status;
 public $system_status;
 public $description;
 public $from_date;
 public $to_date;
 public $starting_status_cb;
 public $ending_status_cb;
 public $sys_process_flow_header_id;
 public $next_allowed_status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 Public static function so_types() {
  $option_header = option_header::find_by_name('SO_TYPE');
  $so_types = option_line::find_by_option_id($option_header->option_header_id);
  return $so_types;
 }

 Public static function so_status() {
  $option_header = option_header::find_by_name('hd_ro_STATUS');
  $so_status = option_line::find_by_option_id($option_header->option_header_id);
  return $so_status;
 }
}

//end of prj_status_header class
?>