<?php

class sd_document_type extends dbObject {

 public static $table_name = "sd_document_type";
 public static $primary_column = "sd_document_type_id";
 public static $key_column = 'document_type_name';
 public static $module = "inv"; //same as gl_journal_source
 public $field_a = [
		 'sd_document_type_id',
		 'document_type_name',
		 'bu_org_id_r',
		 'level',
		 'type',
		 'description',
		 'category',
		 'entity',
		 'process_flow_id',
		 'default_line_document',
		 'price_list_header_id',
		 'default_shipfrom_org_id',
		 'ar_transaction_type',
		 'ar_transaction_source',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $initial_search = [
		 'sd_document_type_id',
		 'document_type_name',
		 'level',
		 'type',
		 'description'
 ];
 public $column = [
		 'sd_document_type_id',
		 'document_type_name',
		 'level',
		 'type',
		 'description',
 ];
 public $requiredField = [
		 'document_type_name',
		 'level',
		 'type',
 ];
 public static $level_a = [
		 'HEADER' => 'Header',
		 'LINE' => 'Line'
 ];
 public static $type_a = [
		 'SALES_AGREEMENT' => 'Sales Agreement',
		 'SALES_ORDER' => 'Sales Order'
 ];
 public static $entity_a = [
		 'EXTERNAL' => 'External',
		 'INTERNAL' => 'Internal'
 ];
 public static $category_a = [
		 'ORDER' => 'Order',
		 'RETURN' => 'Return',
		 'BOTH' => 'Both',
 ];
 public $document_type_name;
 public $bu_org_id_r;
 public $level;
 public $type;
 public $entity;
 public $description;
 public $category;
 public $process_flow_id;
 public $default_line_document;
 public $price_list_header_id;
 public $default_shipfrom_org_id;
 public $ar_transaction_type;
 public $ar_transaction_source;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " SD - Document Type  "; //page Title

 public static function find_by_transactionNumber($number) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE sd_document_type_number = '{$number}' LIMIT 1";
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

 public static function find_by_transactionClass($class) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE type_class = '{$class}' AND status='active'";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of sd_document_type class
?>