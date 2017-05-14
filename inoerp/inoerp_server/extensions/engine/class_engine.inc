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
class engine extends dbObject {

 public static $table_name = "engine";
 public static $module = "sys";
 public static $primary_column = "engine_id";
 public static $key_column = "obj_class_name";
  public static $system_info = [
  'name' => 'Engine',
  'number' => '10001',
  'description' => 'System Engine',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 1
 ];
 public $field_a = [
  'engine_id',
  'obj_class_name',
  'number',
  'type',
  'enabled_cb',
  'db_version',
  'primary_entity_cb',
  'module_name',
  'path',
  'dependent_class',
  'weight',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'engine_id',
  'obj_class_name',
  'type',
  'status',
 ];

 public $requiredField = [
  'type',
  'obj_class_name',
  'module_name'
 ];
 public $checkbox = [
  'primary_entity_cb',
  'uninstall_cb',
  'update_db_cb'
 ];
 public $fields_inForm_notInDataBase = [
  "uninstall_cb",
  'update_db_cb'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=engine&mode=9',
  '_show_update_path' => 1,
  '_view_path' => 'form.php?class_name=engine&mode=2',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Engine "; //page Title
 public $engine_id;
 public $obj_class_name;
 public $type;
 public $number;
 public $enabled_cb;
 public $db_version;
 public $primary_entity_cb;
 public $module_name;
 public $path;
 public $dependent_class;
 public $weight;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $uninstall_cb;
 public $update_db_cb;

 public function _before_save() {

 }

 public function _after_save() {
  if ((!empty($this->obj_class_name)) && ($this->enabled_cb == 1)) {
   $this_class = new $this->obj_class_name;
   if (method_exists($this_class, '_enable')) {
    call_user_func(array($this_class, '_enable'));
   }
  }

  if ((!empty($this->obj_class_name)) && ( empty($this->enabled_cb) || ($this->enabled_cb != 1))) {
   $this_class = new $this->obj_class_name;
   if (method_exists($this_class, '_disable')) {
    call_user_func(array($this_class, '_disable'));
   }
  }

  if ((!empty($this->obj_class_name)) && ( empty($this->enabled_cb) || ($this->uninstall_cb == 1))) {
   $this_class = new $this->obj_class_name;
   if (method_exists($this_class, '_uninstall')) {
    call_user_func(array($this_class, '_uninstall'));
   }
  }
 }

 public function findBy_className($obj_class_name) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE obj_class_name = :obj_class_name ";
  $sql = ino_perPageSql_i($sql, 1);

  $value_a = ['obj_class_name' => $obj_class_name];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

  public static function find_by_className($obj_class_name) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE obj_class_name = '{$obj_class_name}' ";
  $sql = ino_perPageSql_i($sql, 1);

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }
 
}

//end of engine class
?>