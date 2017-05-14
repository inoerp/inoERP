<?php

class content_type_reference extends dbObject {

 public static $table_name = "content_type_reference";
 public static $primary_column = "content_type_reference_id";
 public static $key_column = "field_name";
 public static $module = "extension";
 public  $field_a = [
		 'content_type_reference_id',
		 'content_type_id',
		 'required_cb',
		 'field_name',
		 'field_label',
		 'field_position',
		 'option_type',
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 //variables used for showing data

 public static $reference_values_array = [
		 'field_label',
		 'option_type',
		 'field_position'
 ];
 public $checkbox = [
		 'required_cb'
 ];
 public $requiredField = [
		 'content_type_id',
		 'field_name'
 ];
 public $content_type_reference_id;
 public $field_name;
 public $content_type_id;
 public $required_cb;
 public $field_label;
 public $field_position;
 public $option_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function find_by_contentTypeId_fieldName($content_type_id, $field_name) {
	$sql = "SELECT * FROM " . self::$table_name;
	$sql .= " where content_type_id ='{$content_type_id}' ";
	$sql .= " AND field_name= '{$field_name}' ";
  $sql = ino_perPageSql_i($sql, 1);
//	echo "sql is $sql ";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

}

//end of bom class
?>