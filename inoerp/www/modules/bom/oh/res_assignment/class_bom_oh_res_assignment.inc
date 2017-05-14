<?php

class bom_oh_res_assignment extends dbObject {

 public static $table_name = "bom_oh_res_assignment";
 public static $primary_column = "bom_oh_res_assignment_id";
 public static $key_column = 'bom_overhead_id';
 public static $module = "bom";
//  data base variables as stored database column name
 public $field_a = [
  'bom_oh_res_assignment_id',
  'bom_overhead_id',
  'bom_cost_type',
  'resource_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $fields_inForm_notInDataBase = [
  'bom_cost_type_description',
  'resource_description'
 ];
 public $requiredField = [
  'bom_overhead_id',
  'bom_cost_type',
  'resource_id'
 ];
 public $bom_overhead_id;
 public $bom_cost_type;
 public $bom_oh_res_assignment_id;
 public $resource_id;
 public $bom_cost_type_description;
 public $resource_description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function find_by_bom_overheadId($bom_overheadId) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where bom_overhead_id= '{$bom_overheadId}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public function findBy_resourceId_bomCostType() {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE bom_cost_type =:bom_cost_type AND bom_resource_id = :bom_resource_id ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $param_a = ['bom_cost_type', 'bom_resource_id'];
  $value_a = ['bom_cost_type' => $this->bom_cost_type, 'bom_resource_id' => $this->bom_resource_id];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of bom_oh_res_assignment class
?>