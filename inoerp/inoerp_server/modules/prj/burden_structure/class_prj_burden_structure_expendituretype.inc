<?php

class prj_burden_structure_expendituretype extends dbObject {

 public static $table_name = "prj_burden_structure_expendituretype";
 public static $primary_column = "prj_burden_structure_expendituretype_id";
 public static $parent_primary_column = "prj_burden_structure_header_id";
 public static $key_column = 'prj_expenditure_type_id';
 public static $module = "prj";
 public $field_a = [
  'prj_burden_structure_expendituretype_id',
  'prj_burden_structure_header_id',
  'prj_expenditure_type_id',
  'description',
  'burden_cost_base_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'prj_burden_structure_header_id',
  'prj_expenditure_type_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "prj_burden_structure_header_id"
 ];
 public $prj_burden_structure_expendituretype_id;
 public $prj_burden_structure_header_id;
 public $prj_expenditure_type_id;
 public $description;
 public $burden_cost_base_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;


 public function findAll_ByOrgId($org_id, $status = '') {
  $sql = " SELECT * FROM " .
   self::$table_name .
   " WHERE shipping_org_id= :shipping_org_id  ";
  if (!empty($status)) {
   $sql .= " AND expendituretype_status = :expendituretype_status ";
   $value_a = ['shipping_org_id' => $org_id, 'expendituretype_status' => $status];
  } else {
   $value_a = ['shipping_org_id' => $org_id];
  }
  $result_array = $this->findBySql($sql, $value_a);
  return !empty($result_array) ? $result_array : false;
 }

 Public static function prj_burden_structure_expendituretype_types() {
  $option_header = option_header::find_by_name('PO_expendituretype_TYPE');
  $po_types = option_expendituretype::find_by_option_id($option_header->option_header_id);
  return $po_types;
 }

}

//end of prj_burden_structure_expendituretype class
?>