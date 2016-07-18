<?php

class fp_source_list_line extends dbObject {

 public static $table_name = "fp_source_list_line";
 public static $primary_column = "fp_source_list_line_id";
 public static $parent_primary_column = "fp_source_list_header_id";
 public static $key_column = 'source_list_line_type';
 public static $module = "fp";
 public $field_a = [
		 'fp_source_list_line_id',
		 'fp_source_list_header_id',
		 'source_list_line_type',
		 'source_list_id',
		 'description',
		 'total_original',
		 'fp_consumption_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 //variables used for showing data

 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "fp_source_list_header_id"
 ];
 public $requiredField = [
		 'fp_source_list_header_id',
		 'source_list_line_type',
		 'source_list_id'
 ];
  public $fields_inForm_notInDataBase = [

 ];
 public $fp_forecast_line_id;
 public $fp_source_list_header_id;
 public $source_list_line_type;
 public $source_list_id;
 public $total_current;
 public $total_original;
 public $fp_consumption_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $description;

 Public static function source_list_line_type() {
	$option_header = option_header::find_by_name('FP_SOURCE_LIST_LINE_TYPE');
	$ol = option_line::find_by_option_id($option_header->option_header_id);
	return $ol;
 }



}

//end of inv_transaction class
?>