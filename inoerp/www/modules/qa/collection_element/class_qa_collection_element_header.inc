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
 * Contains all the qa_collection_element_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class qa_collection_element_header extends dbObject {

 public static $table_name = "qa_collection_element_header";
 public static $dependent_classes = ['qa_collection_element_line', 'qa_collection_element_action'];
 public static $primary_column = "qa_collection_element_header_id";
 public static $key_column = 'element_name';
 public static $module = "qa";
 public static $system_info = [
  'name' => 'Collection Element',
  'number' => '6015',
  'description' => 'Create & Mainten Collection Element',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('qa_collection_element_line', 'qa_collection_element_action'),
  'primary_entity_cb' => '',
  'module_name' => 'qa',
  'weight' => 1
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
  'qa_collection_element_header_id',
  'element_name',
  'sys_element_name',
  'description',
  'data_type',
  'data_length',
  'display_type',
  'element_type',
  'element_label',
  'hint',
  'option_header_id',
  'decimal_position',
  'uom_id',
  'default_value',
  'target_value',
  'user_range_low',
  'user_range_high',
  'specification_range_high',
  'specification_range_low',
  'reasonable_range_high',
  'reasonable_range_low',
  'active_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'element_name',
  'sys_element_name',
  'description',
  'data_type',
 ];
 public $requiredField = [
  'element_name',
  'sys_element_name',
  'data_type',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Collection Element "; //page Title
 public $qa_collection_element_header_id;
 public $element_name;
 public $sys_element_name;
 public $description;
 public $data_type;
 public $data_length;
 public $display_type;
 public $element_type;
 public $element_label;
 public $hint;
 public $decimal_position;
 public $uom_id;
 public $option_header_id;
 public $default_value;
 public $target_value;
 public $user_range_low;
 public $user_range_high;
 public $specification_range_high;
 public $specification_range_low;
 public $reasonable_range_high;
 public $reasonable_range_low;
 public $active_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

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
   echo "<br> Error in veriyfing existing table for new field . Error @ " . __FILE__ . ' @@ ' . __LINE__ . $e->getMessage();
   $dbc->rollback = 1;
  }
  return $result;
 }

 private function _create_table($table_name) {
  global $dbc;
  switch ($this->data_type) {
   case 'FILE' :
   case 'IMAGE' :
    $field_type = 'INT';
    $this->data_length = 12;
    break;

   case 'LIST' :
   case 'MULTI_SELECT' :
   case 'OPTION_LIST' :
    $field_type = 'VARCHAR';
    $this->data_length = empty($this->data_length) ? 256 : $this->data_length;
    break;

   case 'DECIMAL' :
    $field_type = $this->data_type;
    $this->data_length = empty($this->data_length) ? 5 : $this->data_length;
    break;

   default :
    $field_type = $this->data_type;
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
  $sql .="  qa_cp_header_id int(12) DEFAULT NULL , ";
  $sql .="  created_by varchar(256) NOT NULL , ";
  $sql .="  creation_date date NOT NULL , ";
  $sql .="  last_update_by varchar(256) NOT NULL , ";
  $sql .="  last_update_date date NOT NULL , ";
  $sql .="  $value_column $field_type ";
  if (in_array($field_type, array('VARCHAR', 'INT'))) {
   $sql .="(" . $this->data_length . ")";
  } else if (($field_type == 'DECIMAL')) {
   $sql .=" (20,$this->data_length) ";
  }
  $sql .=" DEFAULT NULL ";
  $sql .=" , ";
  $sql .= " PRIMARY KEY (`$primary_column`) , ";
  $sql .= " UNIQUE KEY  `colletion_element_value` (`$value_column`, `reference_key_name`,`reference_key_value`  ) ";
  $sql .=" ) ";
  $sql .="ENGINE=InnoDB DEFAULT CHARSET=latin1;";
//	 echo '$sql is ' . $sql;

  try {
   $dbc->connection->exec($sql);
   return 1;
  } catch (Exception $e) {
   echo "<br> Error in creating collection element field table . Error @ class_qa_colletion_element @@ " . __LINE__ . $e->getMessage();
   $dbc->rollback = 1;
   return -1;
  }
 }

 public static function sysElementName_from_elementName($field_name) {
  return strtolower(str_replace(' ', '_', trim($field_name)));
 }

 public static function tableName_from_elementName($field_name) {
  return 'qa_ce_' . $field_name;
 }

 public function _before_save() {
  if (empty($this->sys_element_name)) {
   $this->sys_element_name = self::sysElementName_from_elementName($this->element_name);
  }
 }

 public function _after_save() {
  if (!empty($this->qa_collection_element_header_id)) {
   /* verify that table exists 
     -If not create the table
    */
//   $table_name = 'qa_ce_' . $this->sys_element_name;
   $table_name = self::tableName_from_elementName($this->sys_element_name);
   $existing_table_info = $this->_verify_table_exists($table_name);

   if (empty($existing_table_info)) {
    $this->_create_table($table_name);
   }
  }
 }

}

//end of qa_collection_element_header class
?>