<?php

class inv_count_abc_ref extends dbObject {

 public static $table_name = "inv_count_abc_ref";
 public static $primary_column = "inv_count_abc_ref_id";
 public static $parent_primary_column = "inv_count_header_id";
 public static $key_column = "class_code";
 public static $module = "inv";
 public $field_a = [
   'inv_count_abc_ref_id',
   'inv_count_header_id',
   'class_code',
   'count_per_year',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
 ];
 public $initial_search = [
   'inv_count_header_id',
   'class_code',
 ];
 public $column = [
   'inv_count_abc_ref_id',
   'inv_count_header_id',
   'class_code',
   'count_per_year',
 ];
 public $requiredField = [
   'inv_count_header_id',
   'class_code',
   'count_per_year',
 ];
 public $pageTitle = " Count abc_ref  "; //page Title
 public $inv_count_abc_ref_id;
 public $inv_count_header_id;
 public $class_code;
 public $count_per_year;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_header_id($id) {
  $vgl = new inv_count_abc_ref();
  return $vgl->findBy_parentId($id);
 }

 public static function find_by_parentId_abcCode($parent_id, $abc_code) {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE inv_count_header_id = '{$parent_id}' AND class_code = '{$abc_code}' " ;
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of path class
?>