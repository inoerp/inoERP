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
 * hd_service_type_header CLass
 * Contains all the hd_service_type_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class hd_service_type_header extends dbObject {

 public static $table_name = "hd_service_type_header";
 public static $dependent_classes = ['hd_service_type_line'];
 public static $primary_column = "hd_service_type_header_id";
 public static $key_column = 'service_type';
 public static $module = "hd";
 public static $system_info = [
  'name' => 'Service Activity',
  'number' => '5107',
  'description' => 'Create & Mainten Service Activity',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hd_service_type_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];
 public static $line_category_a = [
  'ORDER' => 'Order',
  'RETURN' => 'Return'
 ];
 public static $repair_mode_a = [
  'WO' => 'Work Order',
  'TASK' => 'Task',
  'NO_TRACKING' => 'No Tracking',
 ];
 public $field_a = [
  'hd_service_type_header_id',
  'service_type',
  'description',
  'active_cb',
  'repair_mode',
  'primary_service_type',
  'pre_repair_activity_rma',
  'pre_repair_activity_so',
  'post_repair_activity_rma',
  'post_repair_activity_so',
  'auto_create_so_rma_cb',
  'prices_list_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'activity_name',
  'activity_description',
  'line_category',
 ];
 public $requiredField = [
  'service_type',
  'primary_service_type'
 ];
 public $fields_inForm_notInDataBase = [
  'action',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 public $pageTitle = " Service Type "; //page Title
 public $hd_service_type_header_id;
 public $service_type;
 public $description;
 public $active_cb;
 public $repair_mode;
 public $primary_service_type;
 public $pre_repair_activity_rma;
 public $pre_repair_activity_so;
 public $post_repair_activity_rma;
 public $post_repair_activity_so;
 public $auto_create_so_rma_cb;
 public $prices_list_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function primary_service_type() {
  $option_header = option_header::find_by_name('HD_PRI_SERVICE_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function billing_type() {
  $option_header = option_header::find_by_name('SYS_BILLING_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

}

//end of hd_service_type_header class
?>