<?php

class bom_material_element extends dbObject {

 protected static $table_name = "bom_material_element";
//  data base variables as stored database column name
 public static $field_array = [
		 'bom_material_element_id',
		 'material_element',
		 'description',
		 'org_id',
		 'status',
		 'default_basis',
		 'ef_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
//variables used for showing data
 public static $initial_search_array = [
		 'bom_material_element_id',
		 'material_element',
		 'description',
		 'org_id',
		 'status'
 ];
 public static $column_array = [
		 'bom_material_element_id',
		 'material_element',
		 'description',
		 'org_id',
		 'status'
 ];
 public static $account_array = [
 ];
 public static $checkbox_array = [
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'material_element',
		 'description',
		 'org_id'
 ];
 public static $primary_column = "bom_material_element_id";
 public $bom_material_element_id;
 public $material_element;
 public $description;
 public $org_id;
 public $status;
 public $default_basis;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
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