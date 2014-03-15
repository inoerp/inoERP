<?php

class om_so_line extends om_so_header {

 protected static $table_name = "om_so_line";
 public static $account_array = [
 ];
 public static $checkbox_array = [
		 "rev_enabled_cb"
 ];
 public static $field_array = [
		 'om_so_line_id',
		 'om_so_header_id',
		 'line_type',
		 'line_number',
		 'item_id',
		 'item_description',
		 'line_description',
		 'uom',
		 'line_quantity',
		 'unit_price',
		 'line_price',
		 'reference_doc_type',
		 'reference_doc_number',
		 "ef_id",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $initial_search_array = [
		 "om_so_header_id",
		 "om_so_number",
		 "item_id",
		 "item_number",
		 "item_description"
 ];
 public static $column_array = [
		 "om_so_header_id",
		 "om_so_number",
		 "item_id",
		 "item_number",
		 "item_description"
 ];
 public static $requiredField_array = [
		 'om_so_header_id',
		 'line_number',
		 'item_description'
 ];
 public static $addressField_array = [
 ];
 public static $fields_inForm_notInDataBase = [
		 "om_so_number",
		 "item_number"
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
		 "om_so_header_id"
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = "om_so_line_id";
 public $om_so_line_id;
 public $om_so_header_id;
 public $line_type;
 public $line_number;
 public $item_id;
 public $item_description;
 public $line_description;
 public $uom;
 public $line_quantity;
 public $unit_price;
 public $line_price;
 public $reference_doc_type;
 public $reference_doc_number;
 public $ef_id;
 public $om_so_status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $item_number;

 public function _after_save() {
	
 }

 Public static function om_so_line_types() {
	$option_header = option_header::find_by_name('PO_LINE_TYPE');
	$om_so_types = option_line::find_by_option_id($option_header->option_header_id);
	return $om_so_types;
 }

 public static function find_by_om_so_headerId($om_so_header_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where om_so_header_id = '{$om_so_header_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

 public function copy($om_so_line_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM om_so_line WHERE `om_so_line_id` = '{$om_so_line_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `om_so_line_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `om_so_line_id` = '{$om_so_line_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `om_so_line` SELECT * FROM tmptable WHERE `om_so_line_id` = '' ";
		if ($db->query($sql3)) {
		 $this->om_so_line_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

}

//end of om_so_line class
?>



