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
 * fa_depreciation_method
 * Contains all the fa_depreciation_method information, such as - depreciation_method, method_type, description,  calcualtion_basis, etc.
 * 
 */
class fa_depreciation_method extends dbObject {

 public static $table_name = "fa_depreciation_method";
 public static $primary_column = "fa_depreciation_method_id";
 public static $dependent_classes = ['fa_depreciation_method_rate'];
 public static $key_column = "price_list";
 public static $module = "fa";
 public static $system_info = [
  'name' => 'depriciation',
  'number' => '1403',
  'description' => 'Define and mainten Depriciation Method',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'dependent_class' => array('fa_depreciation_method_rate'),
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 2
 ];
 public static $method_type_a = [
  'SLD' => 'Straight Line Depreciation',
  'RBD' => 'Reducing Balance Depreciation',
  'SYDD' => 'Sum of the Year Digits Depreciation',
  'UAD' => 'Units of Activity Depreciation'
 ];
 public $field_a = [
  'fa_depreciation_method_id',
  'depreciation_method',
  'method_type',
  'calculation_basis',
  'life_month',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $checkbox = [
//  'allow_mutli_currency_cb'
 ];
 public $initial_search = [
  'fa_depreciation_method_id',
 ];
 public $requiredField = [
  'depreciation_method',
  'method_type',
  'calculation_basis',
  'life_month',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Depreciation Method  "; //page Title
 public $fa_depreciation_method_id;
 public $depreciation_method;
 public $method_type;
 public $calculation_basis;
 public $life_month;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;


 public static function profile_mdm_price_list_org() {
  $line_data_array = [];
  $line_data_array['line_key'] = 'org_id';
  $line_data_array['line_desc'] = 'org';
  $line_data_array['line_values'] = org::find_all_inventory();
  return $line_data_array;
 }

 public static function find_by_module($module_name) {
  $sql = " SELECT * FROM " . self::$table_name . " WHERE module_name = '{$module_name}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_all_purchasing_pl() {
  return self::find_by_module('PO');
 }

 public static function find_all_sales_pl() {
  return self::find_by_module('SD');
 }

}

//end of path class
?>
