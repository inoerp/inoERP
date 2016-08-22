<?php

class inv_abc_valuation_result extends dbObject {

 public static $table_name = "inv_abc_valuation_result";
 public static $primary_column = "inv_abc_valuation_result_id";
 public static $parent_primary_column = "inv_abc_valuation_id";
 public static $key_column = 'item_id_m';
 public static $module = "inv";
 public $field_a = [
  'seq_number',
  'inv_abc_valuation_result_id',
  'inv_abc_valuation_id',
  'item_id_m',
  'quantity',
  'value',
  'cum_quantity',
  'cum_value',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'inv_abc_valuation_result_id',
  'inv_abc_valuation_id',
  'seq_number',
  'item_id_m',
 ];
 public $column = [
  'inv_abc_valuation_result_id',
  'inv_abc_valuation_id',
  'seq_number',
  'item_id_m',
  'item_number',
  'item_description',
  'cum_quantity',
  'cum_value',
  'quantity',
  'value',
 ];
 public $requiredField = [
  'inv_abc_valuation_id',
  'seq_number',
  'item_id_m',
 ];
 public $fields_inForm_notInDataBase = [
  'item_number',
  'item_description'
 ];
 public $search = [
 ];
 public $pageTitle = " ABC Valuation Result "; //page Title
 public $inv_abc_valuation_result_id;
 public $inv_abc_valuation_id;
 public $seq_number;
 public $item_id_m;
 public $quantity;
 public $value;
 public $cum_quantity;
 public $cum_value;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $item_number;
 public $item_description;

 public function _before_showing() {
  if (!empty($this->legal_org_id)) {
//	 echo "<br> legal org ". $this->legal_org_id;
   $legal_org = legal::find_by_orgId($this->legal_org_id);
//	 pa($legal_org);
   $ledger_id = $legal_org->ledger_id;
   $ledger = new gl_ledger();
   $ledger_i = $ledger->findBy_id($ledger_id);
   $this->ledger = $ledger_i->ledger;
  }
 }

 public static function find_impInfo_by_headerid($header_id) {
  $sql = "SELECT COUNT(item_id_m) as total_no_of_items, max(cum_value) as total_value
FROM inv_abc_valuation_result
WHERE inv_abc_valuation_id = '{$header_id}' ";

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_orgId($org_id) {
  $sql = "SELECT * FROM " . self::$table_name . " 
      where org_id={$org_id} ";
  $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_parentId_seqNumber($parent_id, $seq_number) {
  $sql = "SELECT * FROM " . self::$table_name . " 
      where inv_abc_valuation_id= '{$parent_id}' AND seq_number = '{$seq_number}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public static function find_by_parentId_cumValue($parent_id, $cum_value) {
  $sql = "SELECT * FROM " . self::$table_name . " 
      where inv_abc_valuation_id= '{$parent_id}' AND cum_value >= '{$cum_value}' "
   . " ORDER BY  cum_value ASC ";
  $sql = ino_perPageSql_i($sql, 1);
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function findBy_parentId_SeqNumberLimit($seq_number_l = '', $seq_number_u, $parent_id = '') {
  $parent_id = empty($parent_id) ? $this->inv_abc_valuation_id : $parent_id;
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE  inv_abc_valuation_id = '{$parent_id}' ";
  $sql .= " AND  seq_number > '{$seq_number_l}' ";
  $sql .= " AND  seq_number <= '{$seq_number_u}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of inv_abc_valuation_result class
?>
