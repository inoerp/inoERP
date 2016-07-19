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
 * sys_profile_header
 *
 */


class sys_profile_header extends dbObject {

 public static $table_name = "sys_profile_header";
 public static $primary_column = "sys_profile_header_id";
 public static $dependent_classes = ['sys_profile_line'];
 public static $key_column = "profile_name";
 public static $module = "sys";
 public static $system_info = [
  'name' => 'Process Flow',
  'number' => '9108',
  'description' => 'Create & Mainten Profile',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('sys_profile_line'),
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 8
 ];
 public static $access_level_a = [
  'SYSTEM' => 'System',
  'USER' => 'User',
  'BOTH' => 'Both'
 ];
 public static $profile_level_a = [
  'SITE' => 'Site',
  'BUSINESS' => 'Business Org',
  'INVENTORY' => 'Inventory Org',
  'USER' => 'User',
 ];
 public $field_a = [
  'sys_profile_header_id',
  'access_level',
  'profile_name',
  'profile_class_name',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'sys_profile_header_id',
  'access_level',
  'profile_name',
  'description',
 ];
 public $column = [
  'sys_profile_header_id',
  'access_level',
  'profile_name',
  'description',
 ];
 public $requiredField = [
  'profile_class_name',
  'access_level',
  'profile_name',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $fields_inForm_notInDataBase = [
  "profile_level",
 ];
 public $pageTitle = " Profiles "; //page Title
 public $sys_profile_header_id;
 public $access_level;
 public $profile_name;
 public $profile_class_name;
 public $profile_level;
 public $description;
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


}

$profile_header = new sys_profile_header();
$prh = & $profile;

//end of path class
?>
