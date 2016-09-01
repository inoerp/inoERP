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
 * extn_menu_header CLass
 * Contains all the extn_menu_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class extn_menu_header extends dbObject {

 public static $table_name = "extn_menu_header";
 public static $dependent_classes = ['extn_menu_line'];
 public static $primary_column = "extn_menu_header_id";
 public static $key_column = 'menu_name';
 public static $module = "extn";
 public static $system_info = [
  'name' => 'Menu',
  'number' => '10043',
  'description' => 'Create & Mainten Menu',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('extn_menu_line'),
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 1
 ];
 public $field_a = [
  'extn_menu_header_id',
  'menu_name',
  'description',
  'active_cb',
  'priority',
  'css_class',
  'image_file_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'menu_name',
  'description',
 ];
 public $requiredField = [
  'menu_name'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 public $pageTitle = " Menu "; //page Title
 
 public $extn_menu_header_id;
 public $menu_name;
 public $description;
 public $active_cb;
 public $priority;
 public $css_class;
 public $image_file_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_all_activity_of_serviceType($service_type_id) {
  $sql = "SELECT sah.activity_name, sah.activity_description,
sah.line_category,
stl.billing_type, stl.service_activity_id, stl.description, stl.hd_service_type_line_id, stl.hd_service_type_header_id

FROM hd_service_type_line stl,
extn_menu_header sah

WHERE sah.extn_menu_header_id =stl.service_activity_id
AND sah.extn_menu_header_id ='{$service_type_id}'
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

}

//end of extn_menu_header class
?>