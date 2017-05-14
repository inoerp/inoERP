<?php
/**
 * inoERP 
 *
 * Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * bom_standard_operation
 * Used for creating standard operations for make items to help the process of routing creation
 * Routing specifies the flow of matrial in the production line
 * Contains all the bom_overhead information, such as - effective_date, description , item_id_m, org_id
 * 
 */
class bom_standard_operation extends dbObject {

 public static $table_name = "bom_standard_operation";
 public static $primary_column = "bom_standard_operation_id";
 public static $dependent_classes = ['bom_stnd_op_res_assignment'];
 public static $key_column = 'department_id';
 public static $module = "bom";
 public static $system_info = [
		 'name' => 'Standard Operation',
		 'number' => '2408',
		 'description' => 'Standard Operations',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
		 'dependent_class' => array('bom_stnd_op_res_assignment'),
  'primary_entity_cb' => '',
  'module_name' => 'bom',
  'weight' => 7
 ];
//  data base variables as stored database column name
 public $field_a = [
		 'bom_standard_operation_id',
		 'standard_operation',
		 'description',
		 'org_id',
		 'count_point_cb',
		 'auto_charge_cb',
		 'backflush_cb',
		 'status',
		 'department_id',
		 'ef_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
//variables used for showing data
 public $initial_search = [
		 'bom_standard_operation_id',
		 'standard_operation',
		 'department_id',
		 'description',
		 'org_id'
 ];
 public $column = [
		 'bom_standard_operation_id',
		 'standard_operation',
		 'department_id',
		 'description',
		 'org_id'
 ];
 public $checkbox = [
		 'count_point_cb',
		 'auto_charge_cb',
		 'backflush_cb'
 ];
 public $requiredField = [
		 'standard_operation',
		 'description',
		 'org_id',
		 'department_id'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 
   public $profile_default = [
   'org_id' => 'org_inv_name_default',
  ];
   
 public $pageTitle = " Standard Operations - Find All Departments "; //page Title
 public $option_list = [
//		 'bom_department_type' => 'BOM_DEPARTMENT_TYPE',
 ]; //list of search fields which have options
 public $bom_standard_operation_id;
 public $standard_operation;
 public $description;
 public $org_id;
 public $status;
 public $department_id;
 public $count_point_cb;
 public $auto_charge_cb;
 public $backflush_cb;
 public $resource_assignment_id;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

// Public static function bom_standard_operation_type() {
//	$option_header = option_header::find_by_exact_name('RESOURCE_TYPE');
//	$resource_type = option_line::find_by_option_id($option_header->option_header_id);
//	return $resource_type;
// }


}

//end of resource class
?>