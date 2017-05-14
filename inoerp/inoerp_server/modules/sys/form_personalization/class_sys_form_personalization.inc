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
 * 
 *
 */
class sys_form_personalization extends dbObject {

 public static $module = "sys";
 //  data base variables as stored database column name
 public static $system_info = [
  'name' => 'form personalization',
  'number' => '9112',
  'description' => 'Create & Update sys_form_personalization',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('sys_form_personalization_path'),
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 23
 ];
 public static $condition_operator_type_a = [
  'database' => 'Database',
  'manual' => 'Manual',
  'remove' => 'Remove'
 ];
 public $field_a = [
  "sys_form_personalization_id",

 ];

 public $primary_class_name;

}

//end of sys_form_personalization class
?>