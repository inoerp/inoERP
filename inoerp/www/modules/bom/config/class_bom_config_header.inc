<?php

/**
 * inoERP 
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * bom_config_standard_operation
 * Used for creating standard operations for make items to help the process of routing creation
 * Routing specifies the flow of matrial in the production line
 * Contains all the bom_config_overhead information, such as - effective_date, description , item_id_m, org_id
 * 
 */
class bom_config_header extends dbObject {

 public static $table_name = "bom_config_header";
 public static $primary_column = "bom_config_header_id";
 public static $dependent_classes = ['bom_config_line'];
 public static $key_column = 'item_id_m';
 public static $module = "bom";
 public static $system_info = [
  'name' => 'BOM',
  'number' => '2410',
  'description' => 'View and Update Config BOM ',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('bom_config_line'),
  'primary_entity_cb' => '',
  'module_name' => 'bom_config',
  'weight' => '1'
 ];
 public $field_a = [
  'bom_config_header_id',
  'item_id_m',
  'bom_header_id',
  'org_id',
  'reference_key_name',
  'reference_key_value',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'bom_config_header_id',
 ];
 public $fields_inForm_notInDataBase = [
  "item_number",
  "item_description",
  "uom",
 ];
 public $requiredField = [
  'item_id_m',
  'bom_header_id',
  'org_id',
  'reference_key_name',
//  'reference_key_value',
 ];
 public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $pageTitle = " Config BOM - Create & Update BOM "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1
 ];
 public $bom_config_header_id;
 public $item_id_m;
 public $bom_header_id;
 public $org_id;
 public $reference_key_name;
 public $reference_key_value;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $uom;
 public $item_number;
 public $item_description;
 public $commonBom_item_number;
 public $commonBom_item_description;
 public $component_item_number;
 public $component_description;
 public $component_uom;
 public $revision_name;
 public $effective_start_date;

 public function _before_showing() {
  if (!empty($this->common_bom_config_item_id_m)) {
   $item = item::find_by_id($this->common_bom_config_item_id_m);
   $this->commonBom_item_number = $item->item_number;
   $this->commonBom_item_description = $item->item_description;
  } else {
   $this->commonBom_item_number = null;
   $this->commonBom_item_description = null;
  }
 }

 public static function find_by_itemId($item_id_m) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where item_id_m= '{$item_id_m}' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public static function find_by_itemId_orgId($item_id_m, $org_id) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where item_id_m= '{$item_id_m}'  AND org_id = '{$org_id}' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public static function find_by_referenceData($reference_key_name, $reference_key_value) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where reference_key_name= '{$reference_key_name}'  AND reference_key_value = '{$reference_key_value}' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function findBy_itemId() {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where item_id_m= :item_id_m ";
    switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $param_a = ['item_id_m'];
  $value_a = ['item_id_m' => $this->item_id_m];
  $result_array = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function findBy_orgId($org_id) {
  IF (!empty($org_id)) {
   $this->org_id = $org_id;
  }
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where org_id= :org_id ";
  $value_a = ['org_id' => $this->org_id];
  $result_array = $this->findBySql($sql, $value_a);
  return !empty($result_array) ? $result_array : false;
 }

 private function _explosion($item_id_m, &$level_array, $level = 0) {
  $boh = new bom_config_header();
  $boh->item_id_m = $item_id_m;
  $boh_i = $boh->findBy_itemId();
  if (empty($boh_i)) {
   return;
  }
  foreach ($boh->field_a as $key => $value) {
   if (isset($boh_i->$value)) {
    $boh->$value = $boh_i->$value;
   }
  }
  $bol = new bom_config_line();
  $bol_i = $bol->findBy_parentId($boh->bom_config_header_id);
  if (empty($bol_i)) {
   return;
  }
  if (empty($level_array[$level])) {
   $level_array[$level] = [];
  }
  foreach ($bol_i as $items) {
   foreach ($level_array as &$existing_val_arr) {
    while (($pos = array_search($items->component_item_id_m, $existing_val_arr)) !== false) {
     unset($existing_val_arr[$pos]);
    }
   }
   array_push($level_array[$level], $items->component_item_id_m);
  }
  $level++;
  foreach ($bol_i as $items) {
   $boh->item_id_m = $items->component_item_id_m;
   $boh_i = $boh->findBy_itemId();
   if (!empty($boh_i)) {
    $this->_explosion($items->component_item_id_m, $level_array, $level);
   }
  }
 }

 private function _indented_bom_config($item_id_m, &$level_array, $level = 0) {
  $boh = new bom_config_header();
  $boh->item_id_m = $item_id_m;
  $boh_i = $boh->findBy_itemId();
  if (empty($boh_i)) {
   return;
  }
  foreach ($boh->field_a as $key => $value) {
   if (isset($boh_i->$value)) {
    $boh->$value = $boh_i->$value;
   }
  }
  $bol = new bom_config_line();
  $bol_i = $bol->findBy_parentId($boh->bom_config_header_id);
  if (empty($bol_i)) {
   return;
  }
  if (empty($level_array[$level])) {
   $level_array[$level] = [];
  }
  foreach ($bol_i as $items) {
   array_push($level_array[$level], $items->component_item_id_m);
  }
  $level++;
  foreach ($bol_i as $items) {
   $boh->item_id_m = $items->component_item_id_m;
   $boh_i = $boh->findBy_itemId();
   if (!empty($boh_i)) {
    $this->_indented_bom_config($items->component_item_id_m, $level_array, $level);
   }
  }
 }

 public function BOM_Explosion($item_id_m) {
  $level_array = [];
  $l = 0;
  $array_level = 'array_' . $l;
  $$array_level = [];
  array_push($$array_level, $item_id_m);
  array_push($level_array, $$array_level);
  $this->_explosion($item_id_m, $level_array, 1);
  return $level_array;
 }

 public function indented_BOM($item_id_m) {
  $level_array = [];
  $l = 0;
  $array_level = 'array_' . $l;
  $$array_level = [];
  array_push($$array_level, $item_id_m);
  array_push($level_array, $$array_level);
  $this->_indented_bom_config($item_id_m, $level_array, 1);
  return $level_array;
 }

}

//end of bom_config class
?>