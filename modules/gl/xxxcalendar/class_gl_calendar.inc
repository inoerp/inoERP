<?php

class gl_calendar extends dbObject {

 protected static $table_name = "gl_calendar";
 public static $initial_search_array = [
		 'name',
		 'year',
		 'quarter',
		 'name_prefix'
 ];
 public static $column_array = [
		 'name',
		 'calendar_type',
		 'year',
		 'quarter',
		 'from_date',
		 'to_date',
		 'name_prefix'
 ];
 public static $account_array = [
		 'combination'
 ];
 public static $checkbox_array = [
		 'adjustment_period_cb',
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
		 'option_line_code'
 ];
 public static $requiredField_array = [
		 'option_line_code',
		 'name',
		 'calendar_type',
		 'year',
		 'quarter',
		 'from_date',
		 'to_date',
		 'name_prefix'
 ];
 public static $primary_column = "gl_calendar_id";
 public static $key_column = "name";
 public static $field_array = [];

 //gl_calendar name is stored in OP
 Public static function gl_calendar_names() {
	$option_header = option_header::find_by_name('GL_CALENDAR_NAME');
	$option_lines = option_line::find_by_option_id($option_header->option_header_id);
	return $option_lines;
 }

 Public static function period_types() {
	$option_header = option_header::find_by_name('GL_PERIOD_TYPE');
	$option_lines = option_line::find_by_option_id($option_header->option_header_id);
	return $option_lines;
 }

 public static function find_all_from_coa($coa_id) {
	$sql = " SELECT * FROM " . self::$table_name;
	$sql .= " WHERE coa_id='{$coa_id}'";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_gl_calendar_by_coa_id($coa_id) {
	$sql = "SELECT * FROM "
					. self::$table_name
					. " where coa_id={$coa_id}";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_gl_calendar_by_gl_calendar($gl_calendar) {
	global $db;
	$sql = " SELECT combination FROM "
					. self::$table_name
					. " where combination LIKE '%{$gl_calendar}%' LIMIT 0, 30";
	$result = $db->find_by_sql($sql);
	$data = array();
	foreach ($result as $obj) {
	 $data[] = array(
			 'label' => $obj->combination,
			 'value' => $obj->combination
	 );
	}
	return $data;
 }

 public static function validate_gl_calendar($coa_id, $gl_calendar) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where coa_id='{$coa_id}' " .
					" AND combination='{$gl_calendar}' " .
					"LIMIT 1";
	$result_set = $db->find_by_sql($sql);
	return !(empty($result_set)) ? true : false;
 }

 public static function find_combination_id_from_combination($coa_id, $gl_calendar) {
	global $db;
	$sql = "SELECT gl_calendar_id FROM " .
					self::$table_name .
					" where coa_id={$coa_id}" .
					" AND combination='{$gl_calendar}' " .
					" LIMIT 1";
	$result = $db->find_by_sql($sql);
	return !(empty($result)) ? array_shift($result) : false;
 }

}

//end of gl_calendar class
?>
