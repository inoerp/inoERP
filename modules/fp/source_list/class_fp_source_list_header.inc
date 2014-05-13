<?php

class fp_source_list_header extends dbObject {

 protected static $table_name = "fp_source_list_header";
 public static $primary_column = "fp_source_list_header_id";
 public static $dependent_classes = ['fp_source_list_line'];
 public static $key_column = 'source_list';
 public static $module = "fp";
 public $field_a = [
		 'fp_source_list_header_id',
		 'org_id',
		 'source_list',
		 'description',
		 'status',
		 'source_list_type',
		 'ar_customer_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 //variables used for showing data

 public $initial_search = [
		 'fp_source_list_header_id',
		 'org_id',
		 'source_list',
		 'description',
		 'status',
 ];
 public $column = [
		 'fp_source_list_header_id',
		 'org_id',
		 'source_list',
		 'description',
		 'status',
		 'source_list_type',
 ];
 public $requiredField = [
		 'fp_source_list_header_id',
		 'source_list',
		 'source_list_type',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $pageTitle = " Source List - Forecast & Planning  "; //page Title
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $option_lists = [
		 'source_list_type' => 'PO_TYPE',
		 'po_status' => 'PO_STATUS',
 ];
 public $fp_source_list_header_id;
 public $org_id;
 public $source_list;
 public $description;
 public $status;
 public $source_list_type;
 public $ar_customer_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_submit() {
	
 }

 Public static function source_list_type() {
	$option_header = option_header::find_by_name('FP_SOURCE_LIST_TYPE');
	$ol = option_line::find_by_option_id($option_header->option_header_id);
	return $ol;
 }

 public function findBy_itemId() {
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where item_id= :item_id LIMIT 1 ";
	$param_a = ['item_id'];
	$value_a = ['item_id' => $this->item_id];
	$result_array = $this->findBy_sql($sql, $param_a, $value_a);
	return !empty($result_array) ? array_pop($result_array) : false;
 }

}

//end of source_list class
?>