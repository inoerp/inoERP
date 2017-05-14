<?php

class bom_resource_cost extends dbObject {

 public static $table_name = "bom_resource_cost";
 public static $primary_column = "bom_resource_cost_id";
 public static $parent_primary_column = "bom_resource_id";
 public static $key_column = 'bom_resource_id';
 public static $module = "bom";
//  data base variables as stored database column name
 public $field_a = [
  'bom_resource_cost_id',
  'bom_resource_id',
  'bom_cost_type',
  'resource_rate',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'bom_resource_cost_id',
  'resource',
  'description',
  'org_id',
  'status',
  'resource_type'
 ];
 public $column = [
  'bom_resource_cost_id',
  'resource',
  'description',
  'org_id',
  'status',
  'resource_type'
 ];
 public $fields_inForm_notInDataBase = [
  "bom_cost_type_description",
 ];
 public $requiredField = [
  'bom_resource_id',
  'bom_cost_type',
  'resource_rate',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
//		 '_extra_path' => array('form.php?class_name=ar_payment_header&mode=9' => 'Pay',
//				 'form.php?class_name=ar_transaction_header&mode=9&transaction_type=DEBIT_MEMO' => 'Credit')
 ];
 public $pageTitle = " Resources - Create & Update Resources Rate "; //page Title
 public $search_functions = [
  'Cost Type' => 'search_bom_cost_type',
 ];
 public $bom_resource_cost_id;
 public $bom_resource_id;
 public $bom_cost_type;
 public $resource_rate;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $bom_cost_type_description;

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

 public static function find_by_resourceId_bomCostType($resource_id, $bom_cost_type = 'FROZEN') {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE bom_cost_type = '{$bom_cost_type}' AND bom_resource_id = '{$resource_id}' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of bom_resource_cost class
?>