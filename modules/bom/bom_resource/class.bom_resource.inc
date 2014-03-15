<?php

class bom_resource extends dbObject {

 protected static $table_name = "bom_resource";
//  data base variables as stored database column name
 public static $field_array = [
		 'bom_resource_id',
		 'resource',
		 'description',
		 'org_id',
		 'status',
		 'resource_type',
		 'charge_type',
		 'uom',
		 'basis',
		 'osp_cb',
		 'osp_item_id',
		 'costed_cb',
		 'standard_rate_cb',
		 'absorption_ac_id',
		 'variance_ac_id',
		 'overheads',
		 'rate_reference_id',
		 'ef_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
//variables used for showing data
 public static $initial_search_array = [
		 'bom_resource_id',
		 'resource',
		 'description',
		 'org_id',
		 'status',
		 'resource_type'
 ];
 public static $column_array = [
		 'bom_resource_id',
		 'resource',
		 'description',
		 'org_id',
		 'status',
		 'resource_type'
 ];
 public static $account_array = [
		 'absorption_ac_id',
		 'variance_ac_id'
 ];
 public static $checkbox_array = [
		 'osp_cb',
		 'costed_cb',
		 'standard_rate_cb'
 ];
 public static $fields_inForm_notInDataBase = [
		 "osp_item_number",
		 "osp_item_description"
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 'resource',
		 'org_id',
		 'resource_type',
		 'charge_type',
		 'uom'
 ];
 public static $primary_column = "bom_resource_id";
 public $bom_resource_id;
 public $resource;
 public $description;
 public $org_id;
 public $status;
 public $resource_type;
 public $charge_type;
 public $uom;
 public $basis;
 public $osp_cb;
 public $osp_item_id;
 public $osp_item_number;
 public $osp_item_description;
 public $costed_cb;
 public $standard_rate_cb;
 public $absorption_ac_id;
 public $variance_ac_id;
 public $overheads;
 public $rate_reference_id;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 
 
 Public static function resource_type() {
	$option_header = option_header::find_by_exact_name('RESOURCE_TYPE');
	$bom_resource_type = option_line::find_by_option_id($option_header->option_header_id);
	return $bom_resource_type;
 }

 Public static function charge_type() {
	$option_header = option_header::find_by_exact_name('CHARGE_TYPE');
	$charge_type = option_line::find_by_option_id($option_header->option_header_id);
	return $charge_type;
 }

 public function _before_showing() {
	
 }

 public function _before_submit() {
	
 }

}

//end of bom_resource class
?>