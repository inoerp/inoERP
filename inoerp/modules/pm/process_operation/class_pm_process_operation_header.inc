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
 public static $dependent_classes = ['pm_process_operation_line'];
 public static $primary_column = "pm_process_operation_header_id";
 public static $key_column = 'operation_name';
 public static $module = "pm";
 public static $system_info = [
  'name' => 'Service Activity',
  'number' => '5108',
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
  'class',
  'description',
  'version',
  'start_date',
  'end_date',
  'status',
  'min_quantity',
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
  'owning_org_id',
 ];
 public $fields_inForm_notInDataBase = [
  'action',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 public $pageTitle = " operation Header "; //page Title
 public $pm_process_operation_header_id;
 public $operation_name;
 public $org_id;
 public $status;
 public $description;
 public $revision;
 public $start_date;
 public $end_date;
 public $operation_class;
 public $owner_employee_id;
 public $quantity;
 public $uom_id;
 public $planned_loss;
 public $theoretical_loss;
 public $fixed_loss;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_all_activity_of_serviceType($service_type_id) {
  $sql = "SELECT sah.activity_name, sah.activity_description,
sah.line_category,
stl.billing_type, stl.service_activity_id, stl.description, stl.hd_service_type_line_id, stl.hd_service_type_header_id

FROM hd_service_type_line stl,
pm_process_operation_header sah

WHERE sah.pm_process_operation_header_id =stl.service_activity_id
AND sah.pm_process_operation_header_id ='{$service_type_id}'
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

}

//end of pm_process_operation_header class
?>