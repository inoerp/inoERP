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
 * qa_specification_header
 *
 */
class qa_specification_header extends dbObject {

 public static $table_name = "qa_specification_header";
 public static $primary_column = "qa_specification_header_id";
 public static $dependent_classes = ['qa_specification_line'];
 public static $key_column = "version_name";
 public static $module = "qa";
 public static $system_info = [
  'name' => 'Specification',
  'number' => '2904',
  'description' => 'Project Specification',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'qa',
  'weight' => 11
 ];
 public static $specification_type_a = [
  'ITEM_SPEC' => 'Item Specifications',
  'SUPP_SPEC' => 'Supplier Specifications',
  'CUST_SPEC' => 'Customer Specifications',
  'NO_SPEC' => 'No Specifications',
 ];
 public $field_a = [
  'qa_specification_header_id',
  'specification_name',
  'effective_from',
  'description',
  'effective_to',
  'item_id_m',
  'item_revision',
  'ap_supplier_id',
  'ap_customer_id',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'specification_name',
 ];
 public $requiredField = [
  'specification_name',
 ];
 public $fields_inForm_notInDataBase = [
  "supplier_name",
  "supplier_number",
  "item_number",
  'item_description',
  "customer_name",
  "customer_number",
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Specificaions "; //page Title
 public $qa_specification_header_id;
 public $budget_type;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $version_number;
 public $version_name;
 public $description;
 public $status;
 public $raw_cost;
 public $burdened_cost;
 public $labor_effort;
 public $nlr_effort;
 public $revenue;
 public $current_cb;
 public $original_cb;
 public $baselined_by;
 public $baselined_cb;
 public $baselined_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;
 public $project_number;
 public $action;
 public $item_number;
 public $item_description;
 public $supplier_name;
 public $supplier_number;
 public $customer_name;
 public $customer_number;

// Public static function validation_types() {
//  $header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
//  $option_line = new option_line();
//  $lines = $option_line->findBy_parentId($header->option_header_id);
//  return $lines;
// }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of path class
qa_specification_header::staticVar_init('specification_type_a');
?>
