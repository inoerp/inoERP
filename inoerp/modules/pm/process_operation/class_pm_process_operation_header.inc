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
 * pm_process_operation_header CLass
 * Contains all the pm_process_operation_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class pm_process_operation_header extends dbObject {

 public static $table_name = "pm_process_operation_header";
 public static $dependent_classes = ['pm_process_operation_line' , 'pm_process_operation_detail'];
 public static $primary_column = "pm_process_operation_header_id";
 public static $key_column = 'operation_name';
 public static $module = "pm";
 public static $system_info = [
  'name' => 'Service Activity',
  'number' => '2806',
  'description' => 'Create & Mainten Process operation',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('pm_process_operation_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];
 public static $line_category_a = [
  'ORDER' => 'Order',
  'RETURN' => 'Return'
 ];
 public $field_a = [
  'pm_process_operation_header_id',
  'operation_name',
  'org_id',
  'operation_class',
  'description',
  'version',
  'start_date',
  'end_date',
  'status',
  'min_quantity',
  'department',
  "material_ac_id",
  "material_oh_ac_id",
  "overhead_ac_id",
  "resource_ac_id",
  "osp_ac_id",
  "expense_ac_id",
  'uom_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'operation_name',
  'status',
  'description',
 ];
 public $requiredField = [
  'operation_name',
  'org_id',
 ];
 public $fields_inForm_notInDataBase = [
  'action',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 public $pageTitle = "Operation Header "; //page Title
 public $pm_process_operation_header_id;
 public $operation_name;
 public $org_id;
 public $operation_class;
 public $description;
 public $version;
 public $start_date;
 public $end_date;
 public $status;
 public $min_quantity;
 public $uom_id;
 public $material_ac_id;
 public $material_oh_ac_id;
 public $overhead_ac_id;
 public $resource_ac_id;
 public $osp_ac_id;
 public $expense_ac_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of pm_process_operation_header class
?>