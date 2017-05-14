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
 * hd_sbp_header CLass
 * Contains all the hd_sbp_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class hd_sbp_header extends dbObject {

 public static $table_name = "hd_sbp_header";
 public static $dependent_classes = ['hd_sbp_line'];
 public static $primary_column = "hd_sbp_header_id";
 public static $key_column = 'business_process';
 public static $module = "hd";
 public static $system_info = [
  'name' => 'Business Process',
  'number' => '5102',
  'description' => 'Service Business Process',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hd_sbp_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];

 public $field_a = [
  'hd_sbp_header_id',
  'business_process',
  'description',
  'service_order_cb',
  'service_request_cb',
  'service_contract_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'business_process',
  'description',
 ];
 public $requiredField = [
  'business_process'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 public $pageTitle = " Service Business Process "; //page Title
 public $hd_sbp_header_id;
 public $business_process;
 public $description;
 public $service_order_cb;
 public $service_request_cb;
 public $service_contract_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;


 Public static function billing_type() {
  $option_header = option_header::find_by_name('SYS_BILLING_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

}

//end of hd_sbp_header class
?>