<?php

/**
 * inoERP - Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * hr_approval_object
 * Approval object defines elements that control the document approval. Ex : Amount, Account
 * Contains all the hr_approval_object information, such as - object_name, object_code , description, etc
 * 
 */
class hr_approval_object extends dbObject {

 public static $table_name = "hr_approval_object";
 public static $primary_column = "hr_approval_object_id";
 public static $key_column = 'object_code';
 public static $module = "hr";
 public static $system_info = [
  'name' => 'Approval Object',
  'number' => '3103',
  'description' => 'HR Approval Object',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 3
 ];
 public static $value_type_a = [
  'STATIC' => 'Static List',
  'DYNAMIC' => 'Dynamic Data',
 ];
 public static $return_type_a = [
  'BOOLEAN' => 'Boolean',
  'DATE' => 'Date',
  'NUMBER' => 'Number',
  'CURRENCY' => 'Currency',
  'STRING' => 'String',
  'LIST' => 'List',
 ];
 public $field_a = [
  'hr_approval_object_id',
  'object_name',
  'object_code',
  'description',
  'value_type',
  'object_value',
  'return_type',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'hr_approval_object_id',
  'name',
  'description',
 ];
 public $requiredField = [
  'object_name',
  'value_type',
  'object_value',
 ];
 public $hr_approval_object_id;
 public $object_name;
 public $object_code;
 public $description;
 public $value_type;
 public $object_value;
 public $return_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " HR Approval Objects  "; //page Title

 public static function find_by_code() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'HEADER' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of hr_approval_object class
?>