<?php

class option_header extends dbObject {

 public static $table_name = "option_header";
 public static $dependent_classes = ['option_line', 'option_detail'];
 public static $primary_column = "option_header_id";
 public static $key_column = 'option_type';
 public static $module = "sys";
 public static $access_level_array = [
		 'system' => 'System',
		 'user' => 'User',
		 'both' => 'Both'
 ];
 public $field_a = [
		 "option_header_id",
		 "option_type",
		 "access_level",
		 "description",
		 "module_id",
		 'option_assignments',
		 "efid",
		 "status",
		 "rev_enabled",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $initial_search = [
		 "option_header_id",
		 "option_type",
		 "description",
 ];
 public $checkbox = [
 ];
 public $column = [
		 "option_header_id",
		 "option_type",
		 "description",
		 "module_id"
 ];
 public $requiredField = [
		 "option_type",
		 "access_level",
		 "description",
		 "module_id",
 ];
 public $search = [
//		 '_update_path' => 'modules/sys/option/option',
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update Option',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " Option - Create & Update differnt option and values "; //page Title
 public $option_list = [
//		 'calendar_option_line_code' => 'GL_CALENDAR_NAME',
 ]; //list of search fields which have options
 public $option_header_id;
 public $access_level;
 public $option_type;
 public $description;
 public $module_id;
 public $option_assignments;
 public $value_group_id;
 public $efid;
 public $status;
 public $rev_enabled;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public static $dir = __DIR__;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 Public static function countries() {
	$option_header = self::find_by_name('COUNTRY');
	$countries = option_line::find_by_option_id($option_header->option_header_id);
	return $countries;
 }

 Public static function modules() {
	$option_header = self::find_by_name('SYS_MODULE');
$lines = option_line::find_by_option_id($option_header->option_header_id);
	return $lines;
 }
 
  Public static function currencies() {
	$option_header = self::find_by_name('CURRENCY');
	$ol = new option_line();
	$currencies = $ol->findBy_parentId($option_header->option_header_id);
	return $currencies;
 }

 Public static function exception_actions() {
	$option_header = self::find_by_name('EXCEPTION_ACTION');
	$exception_actions = option_line::find_by_option_id($option_header->option_header_id);
	return $exception_actions;
 }

 Public static function option_assignments() {
	$option_header = self::find_by_name('OPTION_ASSIGNMENT');
	$ol = new option_line;
	$result = $ol->findBy_parentId($option_header->option_header_id);
	return $result;
 }

 public static function find_all_headers() {
	$sql = " SELECT * FROM " . self::$table_name;
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_by_name($option_types) {
	global $db;
	$sql = "SELECT * FROM " . self::$table_name . " where option_type LIKE '%{$option_types}%' LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_by_exact_name($option_types) {
	global $db;
	$sql = "SELECT * FROM " . self::$table_name . " WHERE option_type = '$option_types' LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public function save() {
	if (empty($this->option_header_id)) {
	 $check_option_type = $this->check_option_type();
	 if ($check_option_type == 0) {
		$this->create();
	 } else {
		$this->msg = "Option type already exists";
	 }
	} else {
	 $this->update($this->option_header_id);
	}
	return $this->msg;
 }

 private function check_option_type() {
	global $db;
	$sql = "SELECT * FROM " . self::$table_name . " where option_type='{$this->option_type}' ";
	$result_array = self::find_by_sql($sql);
	if (count($result_array) > 0) {
	 $this->msg = 1;
	} else {
	 $this->msg = 0;
	}
	return $this->msg;
 }

}

//end of path class
?>
