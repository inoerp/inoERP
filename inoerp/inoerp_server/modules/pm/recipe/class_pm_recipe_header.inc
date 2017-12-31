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
 * hd_ro_header CLass
 * Contains all the pm_recipe_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class pm_recipe_header extends dbObject {

 public static $table_name = "pm_recipe_header";
 public static $dependent_classes = ['pm_recipe_line', 'pm_recipe_customer'];
 public static $primary_column = "pm_recipe_header_id";
 public static $key_column = 'recipe_name';
 public static $module = "pm";
 public static $system_info = [
  'name' => 'recipe',
  'number' => '2808',
  'description' => 'Create & Mainten recipe',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('pm_recipe_line', 'pm_recipe_customer'),
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 1
 ];
 public static $recipe_type_a = [
  'GENERAL' => 'General',
  'SITE' => 'Site',
  'MASTER' => 'Master',
 ];
 public $action_a = [];
 public $field_a = [
  'pm_recipe_header_id',
  'org_id',
  'recipe_name',
  'pm_formula_header_id',
  'pm_process_routing_header_id',
  'recipe_type',
  'revision',
  'item_id_m',
  'status',
  'description',
  'owner_employee_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'recipe_name',
  'description',
 ];
 public $requiredField = [
  'org_id',
  'recipe_name',
  'pm_formula_header_id',
 ];
 public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $fields_inForm_notInDataBase = [
  "routing_name",
  'formula_name'
 ];

 public $pageTitle = " Recipe "; //page Title
 public $pm_recipe_header_id;
 public $org_id;
 public $recipe_name;
 public $recipe_type;
 public $pm_formula_header_id;
 public $pm_process_routing_header_id;
 public $revision;
 public $item_id_m;
 public $status;
 public $description;
 public $owner_employee_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $action;
 public $routing_name;
 public $formula_name;

}

//end of pm_recipe_header class
?>