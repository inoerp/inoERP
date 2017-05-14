<?php

class inv_abc_assignment_line extends dbObject {

 public static $table_name = "inv_abc_assignment_line";
 public static $primary_column = "inv_abc_assignment_line_id";
 public static $parent_primary_column = "inv_abc_assignment_header_id";
 public static $key_column = "item_id_m";
 public static $module = "inv";
 public $field_a = [
   'inv_abc_assignment_line_id',
   'inv_abc_assignment_header_id',
   'item_id_m',
   'abc_class',
   'description',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
 ];
 public $initial_search = [
   'inv_abc_assignment_header_id',
   'item_id_m',
   'abc_class',
 ];
 public $column = [
   'inv_abc_assignment_header_id',
   'item_id_m',
   'abc_class',
 ];
 public $requiredField = [
   'inv_abc_assignment_header_id',
   'item_id_m',
   'abc_class',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
   "inv_abc_assignment_header_id"
 ];
 public $fields_inForm_notInDataBase = [
   "item_number",
   'item_description',
 ];
 public $pageTitle = " ABC Assignment  "; //page Title
 public $inv_abc_assignment_line_id;
 public $inv_abc_assignment_header_id;
 public $item_id_m;
 public $abc_class;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $item_number;
 public $item_description;

 public static function find_by_header_id($id) {
  $vgl = new inv_abc_assignment_line();
  return $vgl->findBy_parentId($id);
 }

 public function _before_save() {
  if (!(empty($this->item_number)) && empty($this->item_id_m)) {
   $item_s = item::find_by_itemNumber_fromMasterOrg($this->item_number);
   $this->item_id_m = $item_s->item_id_m;
  }
 }

 public static function find_by_parentId_classCode($parent_id, $class_code) {
  $sql = "SELECT * FROM " . self::$table_name . " 
      where inv_abc_assignment_header_id= '{$parent_id}' AND abc_class = '{$class_code}' ";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }
 
  public static function find_by_parentId_classCode_forCycleCount($parent_id, $class_code, $org_id) {
  $sql = " SELECT 
     ail.inv_abc_assignment_line_id, ailinv_abc_assignment_header_id , ail.item_id_m ,
     ail.abc_class, ail.description

     FROM
     inv_abc_assignment_line ail,
     item

     WHERE ail.inv_abc_assignment_header_id= '{$parent_id}' 
     AND ail.abc_class = '{$class_code}'  
     AND item.item_id_m = ail.item_id_m
     AND item.org_id = '{$org_id}'
     AND item.cycle_count_enabled_cb = '1'
 ";
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

}

//end of path class
?>