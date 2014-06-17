<?php

class fp_mrp_exception extends dbObject {

 public static $table_name = "fp_mrp_exception";
 public static $primary_column = "fp_mrp_exception_id";
 public static $parent_primary_column = "fp_mrp_header_id";
 public static $key_column = 'mrp_id';
 public static $module = "fp";
 public $field_a = [
		 'fp_mrp_exception_id',
		 'org_id',
		 'fp_mrp_header_id',
		 'exception_message',
		 'detailed_message',
		 'exception_type',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'exception_type',
 ];
 public $column = [
		 'fp_mrp_exception_id',
		 'org_id',
		 'fp_mrp_header_id',
		 'exception_message',
		 'exception_type',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
 ];
 public $requiredField = [
		 'org_id',
		 'fp_mrp_header_id',
		 'exception_message',
		 'exception_type',
 ];

 public $search_functions = [
		 'Organization' => 'search_org_name_onevalue',
		 'MRP Planner' => 'search_mrp_name_onevalue',
 ];
  public $search = [
		 '_show_view_path' => 1,
 ];
  public $option_lists = [
		 'fp_mrp_exception_type' => 'FP_MRP_EXCEPTION_TYPE'
 ];
	
 public $pageTitle = " MRP Exceptions"; //page Title
public $fp_mrp_exception_id;
public $org_id;
public $fp_mrp_header_id;
public $exception_message;
public $detailed_message;
public $exception_type;
public $reference_type;
public $reference_key_name;
public $reference_key_value;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;
public $org;
public $mrp_name;

 Public static function mrp_exception_types() {
	$option_header = option_header::find_by_name('FP_MRP_EXCEPTION_TYPE');
	$ol = option_line::find_by_option_id($option_header->option_header_id);
	return $ol;
 }
 
 public function _before_showing() {
if(!empty($this->org_id)){
 $org = org::find_by_id($this->org_id);
 $this->org = $org->org;
}else{
 $this->org = null;
}

if(!empty($this->fp_mrp_header_id)){
 $mrp_header = fp_mrp_header::find_by_id($this->fp_mrp_header_id);
 $this->mrp_name = $mrp_header->mrp_name;
}else{
 $this->mrp_name = null;
}
	
 }
 
 public function _before_save() {

 }



}

?>