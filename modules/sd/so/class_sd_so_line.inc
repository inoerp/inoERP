<?php

class sd_so_line extends dbObject {

 protected static $table_name = "sd_so_line";
 public static $primary_column = "sd_so_line_id";
 public static $parent_primary_column = "sd_so_header_id";
 public static $key_column = 'line_number';
 public static $module = "sd";

 public $checkbox = [
		 "rev_enabled_cb"
 ];
 public $field_a = [
		 'sd_so_line_id',
		 'sd_so_header_id',
		 'line_type',
		 'line_number',
		 'item_id',
		 'item_description',
		 'line_description',
		 'uom_id',
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
 public $initial_search = [
		 "sd_so_header_id",
		 "so_number",
		 "item_id",
		 "item_number",
		 "item_description"
 ];
 public $column = [
		 "sd_so_header_id",
		 "so_number",
		 "item_id",
		 "item_number",
		 "item_description"
 ];
 public $requiredField = [
		 'sd_so_header_id',
		 'line_number',
		 'item_description'
 ];

 public $fields_inForm_notInDataBase = [
		 "so_number",
		 "item_number"
 ];
 
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "sd_so_header_id"
 ];
 
 public $sd_so_line_id;
 public $sd_so_header_id;
 public $line_type;
 public $line_number;
 public $item_id;
 public $item_description;
 public $line_description;
 public $uom_id;
 public $line_quantity;
 public $unit_price;
 public $line_price;
 public $reference_doc_type;
 public $reference_doc_number;
 public $ef_id;
 public $po_status;
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

 Public static function sd_so_line_types() {
	$option_header = option_header::find_by_name('PO_LINE_TYPE');
	$po_types = option_line::find_by_option_id($option_header->option_header_id);
	return $po_types;
 }

 public static function find_by_sd_so_headerId($sd_so_header_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where sd_so_header_id = '{$sd_so_header_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

 public function copy($sd_so_line_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM sd_so_line WHERE `sd_so_line_id` = '{$sd_so_line_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `sd_so_line_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `sd_so_line_id` = '{$sd_so_line_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `sd_so_line` SELECT * FROM tmptable WHERE `sd_so_line_id` = '' ";
		if ($db->query($sql3)) {
		 $this->sd_so_line_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

}
//end of sd_so_line class
?>