<?php

class prj_default_account extends dbObject {

 public static $table_name = "prj_default_account";
 public static $module = "prj";
 public static $primary_column = "prj_default_account_id";
 public static $key_column = "document_type";
 public static $system_info = [
  'name' => 'Project Accounts',
  'number' => '9404',
  'description' => 'Define and Mainten Default Project Accountig',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'mdm',
  'weight' => 4
 ];
 public $field_a = [
  'prj_default_account_id',
  'prj_project_type_header_id',
  'accounting_group',
  'ac_id',
  'document_type',
  'description',
  'status',
  'effective_start_date',
  'effective_end_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'document_type',
  'description',
 ];
 public $requiredField = [
  'prj_project_type_header_id',
  'ac_id',
  'document_type',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'prj_project_type_header_id'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Default Project Accounts "; //page Title
 public $prj_default_account_id;
 public $prj_project_type_header_id;
 public $ac_id;
 public $accounting_group;
 public $document_type;
 public $description;
 public $status;
 public $effective_start_date;
 public $effective_end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function tax_type() {
  $option_header = option_header::find_by_name('MDM_TAX_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 public function find_all_ofyear($year) {
  global $db;
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE year= :year ";
  $param_a = ['year'];
  $value_a = ['year' => $year];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return $result;
 }

 public static function find_all_by_projectTypeHeaderId($prj_project_type_header_id) {
  $sql = " 
	 SELECT *
	 FROM prj_default_account
	 WHERE prj_project_type_header_id = '{$prj_project_type_header_id}'
	";
  $result = self::find_by_sql($sql);
  return $result;
 }

}

//end of prj_default_account class
?>