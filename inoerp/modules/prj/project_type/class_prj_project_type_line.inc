<?php

class prj_project_type_line extends dbObject {

 public static $table_name = "prj_project_type_line";
 public static $primary_column = "prj_project_type_line_id";
 public static $parent_primary_column = "prj_project_type_header_id";
 public static $key_column = 'prj_category_header_id';
 public static $module = "prj";
 public $field_a = [
  'prj_project_type_line_id',
  'prj_project_type_header_id',
  'prj_category_header_id',
  'required_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'prj_project_type_header_id',
  'prj_category_header_id',
 ];
 public $fields_inForm_notInDataBase = [
  'category_description'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "prj_project_type_header_id"
 ];
 public $prj_project_type_line_id;
 public $prj_project_type_header_id;
 public $prj_category_header_id;
 public $required_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $category_description;

 public static function find_by_headerId_and_status($prj_project_type_header_id, $line_status = 'PENDING_IMPORT') {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where prj_project_type_header_id= '{$prj_project_type_header_id}' AND line_status= '{$line_status}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public function findAll_ByOrgId($org_id, $status = '') {
  $sql = " SELECT * FROM " .
   self::$table_name .
   " WHERE shipping_org_id= :shipping_org_id  ";
  if (!empty($status)) {
   $sql .= " AND line_status = :line_status ";
   $value_a = ['shipping_org_id' => $org_id, 'line_status' => $status];
  } else {
   $value_a = ['shipping_org_id' => $org_id];
  }
  $result_array = $this->findBySql($sql, $value_a);
  return !empty($result_array) ? $result_array : false;
 }

 Public static function prj_project_type_line_types() {
  $option_header = option_header::find_by_name('PO_LINE_TYPE');
  $po_types = option_line::find_by_option_id($option_header->option_header_id);
  return $po_types;
 }

// public static function find_by_hd_ro_headerId($hd_ro_header_id) {
//  $sql = "SELECT * FROM " . self::$table_name . " where hd_ro_header_id = '{$hd_ro_header_id}'";
//  $result_array = self::find_by_sql($sql);
//  return $result_array;
// }

 public static function find_by_orgId_itemId_ssd($org_id, $item_id_m = '', $ssd = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE shipping_org_id = '{$org_id}'";
  $sql .= " AND schedule_ship_date IS NOT NULL ";
  if (!empty($item_id_m)) {
   $sql .= " AND item_id_m = '{$item_id_m}'";
  }
  if (!empty($ssd)) {
   $sql .= " AND schedule_ship_date >= '{$ssd}'";
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

}

//end of prj_project_type_line class
?>