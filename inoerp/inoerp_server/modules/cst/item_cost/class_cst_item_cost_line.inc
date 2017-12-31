<?php

class cst_item_cost_line extends dbObject {

 public static $table_name = "cst_item_cost_line";
 public static $primary_column = "cst_item_cost_line_id";
 public static $parent_primary_column = "cst_item_cost_header_id";
 public static $multi_search_primary_column = "cst_item_cost_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'cost_element_type';
 public static $module = "cst";
 public $field_a = [
  'cst_item_cost_line_id',
  'cst_item_cost_header_id',
  'cost_element_type',
  'cost_element_id',
  'amount',
  'cost_basis',
  'this_level_cb',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $requiredField = [
  'cst_item_cost_header_id',
  'cost_element_type',
  'cost_element_id',
  'amount',
  'cost_basis'
 ];
 public $numberField = [
  'amount'
 ];
 public $fields_inForm_notInDataBase = [
  'cst_item_cost_line_id',
  'cst_item_cost_header_id',
  'cost_element_type',
  'cost_element_id',
  'amount',
  'cost_basis'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "cst_item_cost_header_id"
 ];
 public $cst_item_cost_line_id;
 public $cst_item_cost_header_id;
 public $cost_element_type;
 public $cost_element_id;
 public $amount;
 public $cost_basis;
 public $this_level_cb;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _after_save() {
  
 }

 public function _before_save() {
//	debug_backtrace();
 }

 public function findBy_headerId_elementId($level = '') {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE cst_item_cost_header_id =:cst_item_cost_header_id "
   . " AND cost_element_type = :cost_element_type "
   . " AND cost_element_id = :cost_element_id ";
  $value_a = ['cst_item_cost_header_id' => $this->cst_item_cost_header_id,
   'cost_element_type' => $this->cost_element_type,
   'cost_element_id' => $this->cost_element_id
  ];
  if (!empty($level)) {
   $sql .= " AND this_level_cb = :this_level_cb ";
   $value_a['this_level_cb'] = $this->this_level_cb;
  }

  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 Public static function cost_element_types() {
  $option_header = option_header::find_by_name('CST_COST_ELEMENT_TYPE');
  $lines = option_line::find_by_option_id($option_header->option_header_id);
  return $lines;
 }

}

//end of cst_item_cost_line class
?>