<?php

class inv_abc_assignment_header extends dbObject {

 public static $table_name = "inv_abc_assignment_header";
 public static $primary_column = "inv_abc_assignment_header_id";
 public static $dependent_classes = ['inv_abc_assignment_line'];
 public static $key_column = "abc_assignment_name";
 public static $module = "inv";
 public $field_a = [
		 'inv_abc_assignment_header_id',
		 'abc_assignment_name',
		 'inv_abc_valuation_id',
		 'org_id',
		 'description',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'inv_abc_assignment_header_id',
		 'abc_assignment_name',
 ];
 public $column = [
		 'inv_abc_assignment_header_id',
		 'abc_assignment_name',
		 'inv_abc_valuation_id',
		 'org_id',
 ];
 public $requiredField = [
		 'abc_assignment_name',
		 'inv_abc_valuation_id',
		 'org_id',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " ABC Assignment "; //page Title
 public $inv_abc_assignment_header_id;
 public $abc_assignment_name;
 public $inv_abc_valuation_id;
 public $org_id;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 Public static function validation_types() {
	$header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
	$option_line = new option_line();
	$lines = $option_line->findBy_parentId($header->option_header_id);
	return $lines;
 }

}

//end of path class
?>
