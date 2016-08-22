<?php

class sd_store_subinventory extends dbObject {

 public static $table_name = "sd_store_subinventory";
 public static $primary_column = "sd_store_subinventory_id";
 public static $parent_primary_column = "sd_store_id";
 public static $key_column = "sd_store_id";
 public static $module = "sd";
 public $field_a = [
  'sd_store_subinventory_id',
  'sd_store_id',
  'subinventory_id',
  'floor_number',
  'building_number',
  'wing_number',
  'description',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'sd_store_id',
 ];
 public $requiredField = [
  'sd_store_id',
  'subinventory_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "sd_store_id"
 ];
// public $fields_inForm_notInDataBase = [
//  "item_number",
//  'item_description',
// ];
// 
 public $pageTitle = " Store Subinventory List "; //page Title
 public $sd_store_subinventory_id;
 public $sd_store_id;
 public $subinventory_id;
 public $floor_number;
 public $building_number;
 public $wing_number;
 public $description;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 
 public static function find_by_header_id($id) {
  $vgl = new sd_store_subinventory();
  return $vgl->findBy_parentId($id);
 }

 public static function find_by_optionId_lineCode($header_id, $code) {
  $sql = "SELECT * FROM " . self::$table_name .
   " where code={$code} AND sd_store_id={$header_id}  ";
   $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_push($result) : $result;
 }


}

//end of path class
?>