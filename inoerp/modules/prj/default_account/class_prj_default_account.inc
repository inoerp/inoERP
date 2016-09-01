<?php

class prj_default_account extends dbObject {

 public static $table_name = "prj_default_account";
 public static $module = "prj";
 public static $primary_column = "prj_default_account_id";
 public static $key_column = "document_type";
 public static $system_info = [
  'name' => 'Project Accounts',
  'number' => '6027',
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

 public static function find_all_by_projectTypeHeaderId($prj_project_type_header_id, $accounting_group) {
  $sql = " 
	 SELECT *
	 FROM prj_default_account
	 WHERE prj_project_type_header_id = '{$prj_project_type_header_id}' AND accounting_group = '{$accounting_group}'	";
//   echo $sql;
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_default_account($account_type, $prj_project_type_header_id, $accounting_group = '') {
  $sql = " 
	 SELECT *
	 FROM prj_default_account
	 WHERE prj_project_type_header_id = '{$prj_project_type_header_id}' AND document_type = '{$account_type}'	";
  if (!empty($accounting_group)) {
   $sql .= " AND accounting_group = '{$accounting_group}'	";
  }
  
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
//   echo $sql;
//   pa($result);
   
  return !empty($result) ? array_pop($result) : false;
 
  
   }

}

//end of prj_default_account class
?>