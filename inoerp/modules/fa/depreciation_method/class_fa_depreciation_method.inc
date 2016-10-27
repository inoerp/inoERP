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
 public static $key_column = "depreciation_method";
 public static $module = "fa";
 public static $system_info = [
  'name' => 'depreciation',
  'number' => '1403',
  'description' => 'Define and mainten Depreciation Method',
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
  'UAD' => 'Units of Activity Depreciation',
  'RATE' => 'Custom Rate'
 ];
 public static $calculation_basis_a = [
  'COST' => 'Cost',
  'NBV' => 'Net Book Value',
 ];
 public static $status_a = [
  'ENTERED' => 'Entered',
  'NEED_VALIDATION' => 'Needs Validation',
  'ACTIVE' => 'Active'
 ];
 public $field_a = [
  'fa_depreciation_method_id',
  'depreciation_method',
  'method_type',
  'calculation_basis',
  'life_month',
  'reducing_balance_rate',
  'status',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $checkbox = [
  'validate_cb'
 ];
 public $fields_inForm_notInDataBase = [
  "validate_cb"
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
 public $reducing_balance_rate;
 public $validate_cb;
 public $life_month;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

// 
// public function _before_save(){
//  pa($this);
// }

 public static function profile_mdm_price_list_org() {
  $line_data_array = [];
  $line_data_array['line_key'] = 'org_id';
  $line_data_array['line_desc'] = 'org';
  $line_data_array['line_values'] = org::find_all_inventory();
  return $line_data_array;
 }

 public function _after_save() {
  $save_again = false;
  if (!empty($this->fa_depreciation_method_id) && !empty($this->validate_cb) && $this->method_type == 'RATE') {
   $save_again = true;
   $all_rate_lines = fa_depreciation_method_rate::find_rateSum_by_depriciationMethod($this->fa_depreciation_method_id);
   if (!empty($all_rate_lines) && $all_rate_lines == 100) {
    $this->status = 'ACTIVE';
   } else {
    $this->status = 'NEED_VALIDATION';
   }
  } else if (!empty($this->fa_depreciation_method_id) && !empty($this->validate_cb) && $this->method_type != 'RATE') {
   $save_again = true;
   $this->status = 'ACTIVE';
  }
  if ($save_again) {
   $this->save();
  }
 }

}

//end of path class
?>
