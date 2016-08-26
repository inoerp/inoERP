<?php

class qa_ce_line extends dbObject {

 public static $table_name = "qa_ce_line";
 public static $primary_column = "qa_ce_line_id";
 public static $parent_primary_column = "qa_ce_header_id";
 public static $key_column = 'element_value';
 public static $module = "qa";
 public $field_a = [
  'qa_ce_line_id',
  'qa_ce_header_id',
  'element_value',
  'description',
  'end_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'qa_ce_header_id',
  'element_value',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "qa_ce_header_id"
 ];
 public $qa_ce_line_id;
 public $qa_ce_header_id;
 public $element_value;
 public $description;
 public $end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 

 public static function find_by_headerId_and_status($qa_ce_header_id, $line_status = 'PENDING_IMPORT') {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where qa_ce_header_id= '{$qa_ce_header_id}' AND line_status= '{$line_status}' ";
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

}

//end of qa_ce_line class
?>