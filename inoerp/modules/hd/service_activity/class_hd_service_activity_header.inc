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
 * hd_service_activity_header CLass
 * Contains all the hd_service_activity_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class hd_service_activity_header extends dbObject {

 public static $table_name = "hd_service_activity_header";
 public static $dependent_classes = ['hd_service_activity_line'];
 public static $primary_column = "hd_service_activity_header_id";
 public static $key_column = 'activity_name';
 public static $module = "hd";
 public static $system_info = [
  'name' => 'Service Activity',
  'number' => '5113',
  'description' => 'Create & Mainten Service Activity',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hd_service_activity_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];
 public static $line_category_a = [
  'ORDER' => 'Order',
  'RETURN' => 'Return'
 ];
 public $field_a = [
  'hd_service_activity_header_id',
  'activity_name',
  'activity_description',
  'line_category',
  'start_date',
  'end_date',
  'allow_quantity_update_cb',
  'create_charge_cb',
  'create_cost_cb',
  'zero_charge_cb',
  'expense_cb',
  'labor_cb',
  'material_cb',
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
  'activity_name'
 ];
 public $fields_inForm_notInDataBase = [
  'action',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 public $pageTitle = " Service Activity "; //page Title
 public $hd_service_activity_header_id;
 public $activity_name;
 public $activity_description;
 public $line_category;
 public $start_date;
 public $end_date;
 public $allow_quantity_update_cb;
 public $create_charge_cb;
 public $create_cost_cb;
 public $zero_charge_cb;
 public $expense_cb;
 public $labor_cb;
 public $material_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_all_activity_of_serviceType($service_type_id) {
  $sql = "SELECT sah.activity_name, sah.activity_description,
sah.line_category,
stl.billing_type, stl.service_activity_id, stl.description, stl.hd_service_type_line_id, stl.hd_service_type_header_id

FROM hd_service_type_line stl,
hd_service_activity_header sah

WHERE sah.hd_service_activity_header_id =stl.service_activity_id
AND sah.hd_service_activity_header_id ='{$service_type_id}'
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

}

//end of hd_service_activity_header class
?>