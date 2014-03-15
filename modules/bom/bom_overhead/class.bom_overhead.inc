<?php

class bom_overhead extends dbObject {

 protected static $table_name = "bom_overhead";
//  data base variables as stored database column name
 public static $field_array = [
		 'bom_overhead_id',
		 'overhead',
		 'description',
		 'org_id',
		 'status',
		 'overhead_type',
		 'default_basis',
		 'absorption_ac_id',
		 'resource_assignment_id',
		 'rate_assignment_id',
		 'ef_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
//variables used for showing data
 public static $initial_search_array = [
		 'bom_overhead_id',
		 'overhead',
		 'description',
		 'org_id',
		 'status',
 ];
 public static $column_array = [
		 'bom_overhead_id',
		 'overhead',
		 'description',
		 'org_id',
		 'status',
 ];
 public static $account_array = [
		 'absorption_ac_id'
 ];
 public static $checkbox_array = [
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'overhead',
		 'description',
		 'org_id'
 ];
 public static $primary_column = "bom_overhead_id";
 
public $bom_overhead_id;
public $overhead;
public $description;
public $org_id;
public $status;
public $overhead_type;
public $default_basis;
public $absorption_ac_id;
public $resource_assignment_id;
public $rate_assignment_id;
public $ef_id;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date ;

 public $time;
 public $msg;

// Public static function resource_type() {
//	$option_header = option_header::find_by_exact_name('RESOURCE_TYPE');
//	$resource_type = option_line::find_by_option_id($option_header->option_header_id);
//	return $resource_type;
// }


 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }

}

//end of resource class
?>