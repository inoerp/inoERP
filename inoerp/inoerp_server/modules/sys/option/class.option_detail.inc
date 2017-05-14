<?php

class option_detail extends dbObject{

 public static $table_name = "option_detail";
 public static $primary_column = "option_detail_id";
 public static $key_column = 'option_detail_value';
 public static $module = "sys";
 public $field_a = [
		 "option_detail_id",
		 "option_header_id",
		 "option_line_id",
		 "option_detail_value",
		 "description",
		 "efid",
		 "status",
		 "rev_enabled",
		 "rev_number",
		 "effective_start_date",
		 "effective_end_date",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $initial_search = [
		 "option_header_id",
		 "option_line_id",
		 "option_detail_id",
		 "option_detail_value",
		 "description"
 ];
 public $checkbox = [
 ];
 public $column = [
		 "option_header_id",
		 "option_line_id",
		 "option_detail_id",
		 "option_detail_value",
		 "description"
 ];
  public $requiredField = [
		 "option_header_id",
		 "option_line_id",
		 "option_detail_value",
		 "description"
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "option_header_id",
		 "option_line_id"
 ];
 public $option_detail_id;
 public $option_header_id;
 public $option_line_id;
 public $option_detail_value;
 public $description;
 public $efid;
 public $status;
 public $rev_enabled;
 public $rev_number;
 public $effective_start_date;
 public $effective_end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public static function find_by_option_header_id($option_header_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where option_header_id = '{$option_header_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

 public static function find_by_option_line_id($option_line_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where option_line_id = '{$option_line_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

 public static function find_by_option_line_id_value($option_line_id, $option_detail_value) {
	$sql = "SELECT * FROM " . self::$table_name .
					" where option_detail_value='{$option_detail_value}' AND option_line_id='{$option_line_id}' ";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }


 public static function option_detailObject_ofLine($option_line_id = "") {
	if (!empty($option_line_id)) {
	 $option_detail_object = self::find_by_option_line_id($option_line_id);
	 if (count($option_detail_object) == 0) {
		$option_detail = new option_detail();
		$option_detail_object = array();
		array_push($option_detail_object, $option_detail);
	 }
	}
	return $option_detail_object;
 }

}

//end of path class
?>