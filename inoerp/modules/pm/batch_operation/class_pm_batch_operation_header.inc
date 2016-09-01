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
class pm_batch_operation_header extends pm_process_operation_header {

 public static $table_name = "pm_batch_header";
 public static $dependent_classes = ['pm_batch_operation_line', 'pm_batch_operation_detail'];
 public static $key_column = 'pm_batch_header_id';
 public static $module = "pm";
 public static $system_info = [
  'name' => 'Operation Batch',
  'number' => '2802',
  'description' => 'Create & Mainten Process Batch',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('pm_batch_operation_line', 'pm_batch_operation_detail'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];
 public $field_a = [
  'pm_process_operation_header_id',
  'operation_name',
  'pm_batch_header_id',
  'batch_name',
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
 public $fields_inForm_notInDataBase = [
  "pm_batch_header_id",
 ];
 
  public $requiredField = [

 ];
 public $pm_batch_header_id;
 public $pageTitle = "Batch Operation "; //page Title
 public $org_id;
 public $batch_name;
 public $pm_recipe_header_id;
 public $wip_accounting_group_id;
 public $recipe_version;
 public $comment;
 public $status;
 public $description;
 public $terminate_reason;
 public $planned_start_date;
 public $planned_completion_date;
 public $required_completion_date;
 public $actual_completion_date;
 public $actual_start_date;
 public $update_invnetory_cb;
 public $batch_exploded_cb;
 public $actual_quantity;
 public $allocated_quantity;
 public $planned_quantity;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $action;
 public $recipe_name;
 
 public function _before_save(){
  return 10;
 }

}

//end of pm_process_operation_header class
?>