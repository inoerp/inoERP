<?php

class po_line extends dbObject {

 public static $table_name = "po_line";
 public static $primary_column = "po_line_id";
 public static $parent_primary_column = "po_header_id";
 public static $key_column = 'line_number';
 public static $module = "po";
 public $checkbox = [
		 "rev_enabled_cb"
 ];
 public $field_a = [
		 'po_line_id',
		 'po_header_id',
		 'line_type',
		 'line_number',
		 'receving_org_id',
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
		 "po_header_id",
		 "po_number",
		 "item_id",
		 "item_number",
		 "item_description"
 ];
 public $column = [
		 "po_header_id",
		 "po_number",
		 "item_id",
		 "item_number",
		 "item_description"
 ];
 public $requiredField = [
		 'po_header_id',
		 'line_number',
		 'item_description'
 ];
 public $fields_inForm_notInDataBase = [
		 "po_number",
		 "item_number"
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "po_header_id"
 ];
 public $po_line_id;
 public $po_header_id;
 public $line_type;
 public $line_number;
 public $receving_org_id;
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

 public function _before_save() {
	if (!(empty($this->receving_org_id))) {
	 if (!(empty($this->item_number))) {
    $item_s = item::find_by_itemNumber_orgId($this->item_number, $this->receving_org_id);
			$this->item_id = $item_s->item_id;
	 }
	} else {
	 echo "<br> Saving line data failed!. No receving org. Error @ po_line @" . __LINE__;
	 return -99;
	}
 }

 public function _after_save() {
	
 }

 Public static function po_line_types() {
	$option_header = option_header::find_by_name('PO_LINE_TYPE');
	$po_types = option_line::find_by_option_id($option_header->option_header_id);
	return $po_types;
 }

 public static function find_by_po_headerId($po_header_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where po_header_id = '{$po_header_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

 public function copy($po_line_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM po_line WHERE `po_line_id` = '{$po_line_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `po_line_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `po_line_id` = '{$po_line_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `po_line` SELECT * FROM tmptable WHERE `po_line_id` = '' ";
		if ($db->query($sql3)) {
		 $this->po_line_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

}

//end of po_line class
?>