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
class extn_theme extends dbObject {

 public static $table_name = "extn_theme";
 public static $module = "sys";
 public static $primary_column = "extn_theme_id";
 public static $key_column = "theme_name";
 public static $system_info = [
  'name' => 'extn_theme',
  'number' => '10045',
  'description' => 'System extn_theme',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 1
 ];
 public $field_a = [
  'extn_theme_id',
  'theme_name',
  'developer_name',
  'developer_email',
  'enabled_cb',
  'default_cb',
  'version_number',
  'developer_details',
  'path',
  'dependent_class',
  'weight',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'theme_name',
  'developer_name',
 ];
 public $requiredField = [
  'theme_name'
 ];
 public $checkbox = [
  'enabled_cb',
  'default_cb',
 ];
 public $fields_inForm_notInDataBase = [
  "uninstall_cb",
  'update_db_cb'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Themes "; //page Title
 public $extn_theme_id;
 public $theme_name;
 public $developer_name;
 public $developer_email;
 public $enabled_cb;
 public $default_cb;
 public $version_number;
 public $developer_details;
 public $path;
 public $dependent_class;
 public $weight;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_save() {
  
 }

 public function _after_save() {
  //check if file exists
  $this_class = null;
  if ((!empty($this->theme_name))) {
   $class_file_name = HOME_DIR . DS . 'themes' . DS . $this->theme_name . DS . 'class_theme_' . $this->theme_name . '.inc';
   if (file_exists($class_file_name)) {
    require_once $class_file_name;
    $class_name = 'theme_' . $this->theme_name;
    $this_class = new $class_name;
   }
  }

  if (($this->enabled_cb == 1) && ($this_class)) {
   if (method_exists($this_class, '_enable')) {
    call_user_func(array($this_class, '_enable'));
   }
  }

  if (($this_class) && ( empty($this->enabled_cb) || ($this->enabled_cb != 1))) {
   if (method_exists($this_class, '_disable')) {
    call_user_func(array($this_class, '_disable'));
   }
  }

  if (($this_class) && ( empty($this->enabled_cb) || ($this->uninstall_cb == 1))) {
   if (method_exists($this_class, '_uninstall')) {
    call_user_func(array($this_class, '_uninstall'));
   }
  }
 }

 public function findBy_themeName($theme_name) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE theme_name = :theme_name ";
  $sql = ino_perPageSql_i($sql, 1);

  $value_a = ['obj_class_name' => $theme_name];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_themeName($theme_name) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE theme_name = '{$theme_name}' ";
  $sql = ino_perPageSql_i($sql, 1);

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_default_theme() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE default_cb = 1 ";
  $sql = ino_perPageSql_i($sql, 1);

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }
 
  public static function find_all_enabled_theme() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE enabled_cb = 1 ";

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }
 
 

}

//end of extn_theme class
?>