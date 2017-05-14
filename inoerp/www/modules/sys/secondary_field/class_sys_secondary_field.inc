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
 * sys_secondary_field
 *
 */


class sys_secondary_field extends dbObject {

 public static $table_name = "sys_secondary_field";
 public static $primary_column = "sys_secondary_field_id";
 public static $key_column = 'field_name';
 public static $module = "sys"; //same as gl_journal_source
 public static $system_info = [
  'name' => 'Secondary Field',
  'number' => '9110',
  'description' => 'Create & Update Secondary Field',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 10
 ];
 public static $display_type_a = [
  'TEXT' => 'Text',
  'SELECT' => 'Select',
  'MULTI_SELECT' => 'Multi Select',
  'TEXT_AREA' => 'Text Area',
  'CHECK_BOX' => 'Check Box',
  'IMAGE' => 'Image'
 ];
 public $field_a = [
  'sys_secondary_field_id',
  'field_name',
  'sys_field_name',
  'description',
  'field_type',
  'field_length',
  'display_type',
  'active_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'field_name',
  'description',
  'type',
 ];
 public $checkbox = [
  "active_cb",
 ];
 public $requiredField = [
  'field_name',
  'field_type'
 ];
 public $sys_secondary_field_id;
 public $field_name;
 public $sys_field_name;
 public $description;
 public $field_type;
 public $field_length;
 public $display_type;
 public $active_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 private $_table_exists;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Secondary Field  "; //page Title

 Public static function sys_secondary_field_type() {
  $option_header = option_header::find_by_name('SYS_EXTRA_FIELD_TYPE');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public static function find_by_transactionNumber($number) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE sys_secondary_field_number = '{$number}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_transactionClass($class) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE type_class = '{$class}' AND status='active'";
  $result = self::find_by_sql($sql);
  return $result;
 }

 private function _verify_table_exists($table_name) {
  global $dbc;
  //check for existing table name
  $exist_query = " SELECT TABLE_NAME from information_schema.tables where TABLE_TYPE ='BASE TABLE' "
   . " AND TABLE_SCHEMA= '" . DB_NAME . "' AND table_name= :table_name ";
  $stmt = $dbc->connection->prepare("$exist_query");
  $stmt->bindParam(':table_name', $table_name);
  try {
   $stmt->execute();
   $result = $stmt->fetchObject();
   if (!empty($result)) {
    $this->_table_exists = 1;
   } else {
    $this->_table_exists = -1;
   }
  } catch (PDOException $e) {
   echo "<br> Error in finding veriyfing existing table for new field . Error @ class_sys_secondary_field @@ " . __LINE__ . $e->getMessage();
   $dbc->rollback = 1;
  }
  return $result;
 }

 private function _create_table($table_name) {
  global $db;
  global $dbc;
  switch ($this->field_type) {
   case 'FILE' :
   case 'IMAGE' :
    $field_type = 'INT';
    $this->field_length = 12;
    break;

   case 'LIST' :
   case 'MULTI_SELECT' :
   case 'OPTION_LIST' :
    $field_type = 'VARCHAR';
    $this->field_length = empty($this->field_length) ? 256 : $this->field_length;
    break;

   case 'DECIMAL' :
    $field_type = $this->field_type;
    $this->field_length = empty($this->field_length) ? 5 : $this->field_length;
    break;

   default :
    $field_type = $this->field_type;
    break;
  }

  $primary_column = $table_name . '_id';
  $value_column = $table_name . '_value';
  $sql = " CREATE TABLE IF NOT EXISTS " . $table_name;
  $sql .=" ( ";
  $sql .="  $primary_column int(12) NOT NULL AUTO_INCREMENT, ";
  $sql .="  reference_type varchar(30) DEFAULT NULL , ";
  $sql .="  reference_entity varchar(50) DEFAULT NULL , ";
  $sql .="  reference_key_name varchar(50) DEFAULT NULL , ";
  $sql .="  reference_key_value int(12) DEFAULT NULL , ";
  $sql .="  created_by varchar(256) NOT NULL , ";
  $sql .="  creation_date date NOT NULL , ";
  $sql .="  last_update_by varchar(256) NOT NULL , ";
  $sql .="  last_update_date date NOT NULL , ";
  $sql .="  $value_column $field_type ";
  if (in_array($field_type, array('VARCHAR', 'INT'))) {
   $sql .="(" . $this->field_length . ")";
  } else if (($field_type == 'DECIMAL')) {
   $sql .=" (20,$this->field_length) ";
  }
  $sql .=" DEFAULT NULL ";
  $sql .=" , ";
  $sql .= " PRIMARY KEY (`$primary_column`) , ";
  $sql .= " UNIQUE KEY  `secondary_field_value` (`$value_column`, `reference_key_name`,`reference_key_value`  ) ";
  $sql .=" ) ";
  $sql .="ENGINE=InnoDB DEFAULT CHARSET=latin1;";
//	 echo '$sql is ' . $sql;

  try {
   $dbc->connection->exec($sql);
   return 1;
  } catch (Exception $e) {
   echo "<br> Error in creating secondary field table . Error @ class_sys_secondary_field @@ " . __LINE__ . $e->getMessage();
   $dbc->rollback = 1;
   return -1;
  }
 }

 public static function sysFieldName_from_FieldName($field_name) {
  return strtolower(str_replace(' ', '_', trim($field_name)));
 }

 public function _before_save() {
  if (empty($this->sys_field_name)) {
   $this->sys_field_name = self::sysFieldName_from_FieldName($this->field_name);
  }
 }

 public function _after_save() {
  if (!empty($this->sys_secondary_field_id)) {
   /* verify that table exists 
     -If not create the table
    */
   $table_name = 'sf_' . $this->sys_field_name;
   $existing_table_info = $this->_verify_table_exists($table_name);

   if (empty($existing_table_info)) {
    $this->_create_table($table_name);
   }
  }
 }

}

//end of sys_secondary_field class
?>