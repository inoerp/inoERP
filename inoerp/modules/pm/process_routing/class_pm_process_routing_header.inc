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
 * pm_process_routing_header CLass
 * Contains all the pm_process_routing_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class pm_process_routing_header extends dbObject {

 public static $table_name = "pm_process_routing_header";
 public static $dependent_classes = ['pm_process_routing_line'];
 public static $primary_column = "pm_process_routing_header_id";
 public static $key_column = 'routing_name';
 public static $module = "pm";
 public static $system_info = [
  'name' => 'Process Routing',
  'number' => '2807',
  'description' => 'Create & Mainten Process Routing',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('pm_process_routing_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];
 public static $line_category_a = [
  'ORDER' => 'Order',
  'RETURN' => 'Return'
 ];
 public static $status_a = [
  'APPROVED' => 'Approved',
  'PEND_APPROVAL' => 'Pening Approval',
  'ON_HOLD' => 'On Hold',
  'INACTIVE' => 'In Active',
 ];
 public $field_a = [
  'pm_process_routing_header_id',
  'routing_name',
  'org_id',
  'status',
  'description',
  'revision',
  'start_date',
  'end_date',
  'routing_class',
  'quantity',
  'uom_id',
  'planned_loss',
  'theoretical_loss',
  'fixed_loss',
  'owner_employee_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'routing_name',
  'status',
  'description',
 ];
 public $requiredField = [
  'routing_name',
  'org_id',
 ];
 public $fields_inForm_notInDataBase = [
  'action',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 
  public static $json_label_fields = [
  'routing_name',
  'description',
  'routing_class',
   'status',
  'org_id',
 ];
 public $pageTitle = " Routing Header "; //page Title
 public $pm_process_routing_header_id;
 public $routing_name;
 public $org_id;
 public $status;
 public $description;
 public $revision;
 public $start_date;
 public $end_date;
 public $routing_class;
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
pm_process_routing_header sah

WHERE sah.pm_process_routing_header_id =stl.service_activity_id
AND sah.pm_process_routing_header_id ='{$service_type_id}'
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

}

//end of pm_process_routing_header class
?>