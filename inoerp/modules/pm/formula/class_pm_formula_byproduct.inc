<?php

class pm_formula_byproduct extends dbObject {

 public static $table_name = "pm_formula_byproduct";
 public static $primary_column = "pm_formula_byproduct_id";
 public static $parent_primary_column = "pm_formula_header_id";
 public static $key_column = 'user_id';
 public static $module = "prj";
 public static $byproduct_type_a = [
  'REWORK' => 'Rework',
  'SAMPLE' => 'Sample',
  'WASTE' => 'Waste',
  'YIELD' => 'Yield',
 ];
//  data base variables as stored database column name
 public $field_a = [
  'pm_formula_byproduct_id',
  'pm_formula_header_id',
  'line_no',
  'line_type',
  'item_id_m',
  'uom_id',
  'quantity',
  'description',
  'scale_type',
  'yield_type',
  'byproduct_type',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $fields_inForm_notInDataBase = [
  "member_username",
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'pm_formula_header_id'
 ];
 public $requiredField = [
  'pm_formula_header_id',
  'item_id_m',
 ];
 public $pm_formula_byproduct_id;
 public $pm_formula_header_id;
 public $line_no;
 public $line_type;
 public $item_id_m;
 public $uom_id;
 public $quantity;
 public $description;
 public $yield_contribution_cb;
 public $scale_type;
 public $yield_type;
 public $byproduct_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_headerId_and_status($prj_project_header_id, $line_status = 'PENDING_IMPORT') {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where prj_project_header_id= '{$prj_project_header_id}' AND line_status= '{$line_status}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $routing_sequence) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where wip_wo_header_id= '{$wip_wo_header_id}' 
					 AND routing_sequence= '{$routing_sequence}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public function findBy_woHeaderId_routingSeq() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE wip_wo_header_id = :wip_wo_header_id ";
  $sql .= " AND routing_sequence = :routing_sequence ";

  $param_a = ['wip_wo_header_id', 'routing_sequence'];
  $value_a = ['wip_wo_header_id' => $this->wip_wo_header_id, 'routing_sequence' => $this->routing_sequence];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? $result : false;
 }

}

//end of pm_formula_byproduct class
?>