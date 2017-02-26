<?php

class category_reference extends dbObject {

 public static $table_name = "category_reference";
 public static $primary_column = "category_reference_id";
 public static $key_column = "category_id";
 public static $module = "extension";
//  data base variables as stored database column name
 public $field_a = [
		 "category_reference_id",
		 "major_category_id",
		 "category_id",
		 "reference_type",
		 "reference_table",
		 "reference_id",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
// public static $base_encoded_array = ["content"];
//variables used for showing data

 public $column = [
		 "major_category_id",
		 "category_id",
		 "reference_type",
		 "reference_table",
		 "reference_id",
 ];
 public $requiredField = [
		 "major_category_id",
		 "category_id",
		 "reference_type",
		 "reference_table",
		 "reference_id",
 ];
 Public static $referenceType = [
		 "1" => "content_type",
		 "2" => "others"
 ];
 public $category_reference_id;
 public $major_category_id;
 public $category_id;
 public $reference_type;
 public $reference_table;
 public $reference_id;
  public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public static function check_majorCategory_in_categoryReference($major_category_id, $reference_table, $reference_id) {
	global $db;

	$sql = "SELECT * FROM  ";
	$sql .= self::$table_name;
	$sql .= " WHERE major_category_id = '{$major_category_id}'
       AND reference_table = '{$reference_table}' 
       AND reference_id = '{$reference_id}'
       ";
$sql = ino_perPageSql_i($sql, 1);
	$result = self::find_by_sql($sql);


	return !empty($result) ? array_shift($result) : false;
 }

}

//end of category class
?>