<?php

/**
 * inoERP 
 *
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * bom_routing_header
 * Used for creating different user defined routings for make items
 * Routing specifies the flow of matrial in the production line
 * Contains all the bom_overhead information, such as - effective_date, description , item_id_m, org_id
 * 
 */
class fp_forecast_header extends dbObject {

 public static $table_name = "fp_forecast_header";
 public static $primary_column = "fp_forecast_header_id";
 public static $dependent_classes = ['fp_forecast_line', 'fp_forecast_line_date'];
 public static $key_column = 'forecast';
 public static $module = "fp";
 public static $system_info = [
  'name' => 'Forecast',
  'number' => '2501',
  'description' => 'Forecast',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('fp_forecast_line', 'fp_forecast_line_date'),
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 1
 ];
 public $field_a = [
  'fp_forecast_header_id',
  'org_id',
  'forecast',
  'forecast_group_id',
  'description',
  'status',
  'demand_class',
  'ar_customer_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'fp_forecast_header_id',
  'org_id',
  'forecast',
  'description',
 ];
 public $column = [
  'fp_forecast_header_id',
  'org_id',
  'forecast',
  'description',
  'status',
  'demand_class',
  'ar_customer_id',
 ];
 public $requiredField = [
  'org_id',
  'forecast'
 ];
 public $fields_inForm_notInDataBase = [
  "customer_name",
  "customer_number",
 ];
 public $pageTitle = " Forecast - FP  "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $fp_forecast_header_id;
 public $org_id;
 public $forecast;
 public $description;
 public $forecast_group_id;
 public $status;
 public $demand_class;
 public $ar_customer_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function fp_bucket() {
  $option_header = option_header::find_by_name('FP_BUCKET');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 Public static function demand_type() {
  $option_header = option_header::find_by_name('FP_DEMAND_TYPE');
  $type = option_line::find_by_option_id($option_header->option_header_id);
  return $type;
 }

 public function findBy_itemId() {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where item_id_m= :item_id_m";

  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $param_a = ['item_id_m'];
  $value_a = ['item_id_m' => $this->item_id_m];
  $result_array = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function findAll_2columns() {
  $result = $this->findAll();
  $id = self::$primary_column;
  $name = self::$key_column;
  $data = array();
  if (!empty($result)) {
   foreach ($result as $obj) {
    $data[] = array(
     'label' => $obj->$name,
     'name' => $obj->$name,
     'id' => $obj->$id
    );
   }
  }
  return $data;
 }

}

//end of forecast class
?>