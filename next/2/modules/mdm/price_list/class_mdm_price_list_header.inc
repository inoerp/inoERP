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
 * mdm_price_list_header
 * Contains all the mdm_price_list_header information, such as - price_list, module_name, description,  currency_code, etc.
 * 
 */
class mdm_price_list_header extends dbObject {

 public static $table_name = "mdm_price_list_header";
 public static $primary_column = "mdm_price_list_header_id";
 public static $dependent_classes = ['mdm_price_list_line' ,'mdm_price_list_detail'];
 public static $key_column = "price_list";
 public static $module = "mdm";
 public static $system_info = [
  'name' => 'Price List',
  'number' => '9402',
  'description' => 'Define and mainten price list',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'dependent_class' => array('mdm_price_list_line'),
  'primary_entity_cb' => '',
  'module_name' => 'mdm',
  'weight' => 2
 ];
 public static $module_a = [
  'PO' => 'Purchasing',
  'SD' => 'Sales & Distribution'
 ];
 public $field_a = [
  'mdm_price_list_header_id',
  'price_list',
  'module_name',
  'currency_code',
  'description',
  'status',
  'allow_mutli_currency_cb',
  'currency_conversion_type',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $checkbox = [
  'allow_mutli_currency_cb'
 ];
 public $initial_search = [
  'mdm_price_list_header_id',
  'price_list',
  'module_name',
  'currency_code',
 ];
 public $column = [
  'mdm_price_list_header_id',
  'price_list',
  'module_name',
  'currency_code',
  'description',
  'status',
 ];
 public $requiredField = [
  'price_list',
  'module_name',
  'currency_code',
//  'status',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Price List "; //page Title
 public $mdm_price_list_header_id;
 public $price_list;
 public $module_name;
 public $currency_code;
 public $description;
 public $status;
 public $allow_mutli_currency_cb;
 public $currency_conversion_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

// function __construct() {
//	global $dbc;
//	$sql_fields = " SHOW COLUMNS FROM  " . self::$table_name;
//	$prepare = $dbc->connection->prepare($sql_fields);
//	$prepare->execute();
//	$this->field_a = $prepare->fetchAll(PDO::FETCH_COLUMN, 0);
// }

 public function __set($name, $value) {
  $this->$name = $value;
 }

 Public static function validation_types() {
  $header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
  $option_line = new option_line();
  $lines = $option_line->findBy_parentId($header->option_header_id);
  return $lines;
 }

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
