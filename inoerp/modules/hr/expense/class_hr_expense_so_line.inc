<?php

class hr_expense_line extends dbObject {

 public static $table_name = "sd_so_line";
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
		 'item_id_m',
		 'shipping_org_id',
		 'line_status',
		 'requested_date',
		 'promise_date',
		 'schedule_ship_date',
		 'actual_ship_date',
		 'item_description',
		 'line_description',
		 'uom_id',
		 'line_quantity',
		 'picked_quantity',
		 'shipped_quantity',
		 'invoiced_quantity',
		 'price_list_header_id',
		 'price_date',
		 'unit_price',
		 'line_price',
		 'reference_doc_type',
		 'supply_source',
		 'destination_type',
		 'tax_code_id',
		 'tax_amount',
		 'reference_doc_number',
		 'ar_transaction_header_id',
		 'ar_transaction_line_id',
		 "ef_id",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $initial_search = [
		 "sd_so_header_id",
		 "so_number",
		 "item_id_m",
		 "item_number",
		 "item_description"
 ];
 public $column = [
		 "sd_so_header_id",
		 "so_number",
		 "item_id_m",
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
		 "item_number",
		 'tax_code_value',
		 'ar_transaction_number'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "sd_so_header_id"
 ];
 
 public $notUpdatedFromWebForm = [
		 'actual_ship_date',
 ];
 
 public $sd_so_line_id;
 public $sd_so_header_id;
 public $line_type;
 public $line_number;
 public $item_id_m;
 public $item_description;
 public $line_description;
 public $uom_id;
 public $line_quantity;
 public $picked_quantity;
 public $shipped_quantity;
 public $invoiced_quantity;
 public $price_list_header_id;
 public $price_date;
 public $unit_price;
 public $line_price;
 public $tax_code_id;
 public $tax_amount;
 public $reference_doc_type;
 public $reference_doc_number;
 public $ar_transaction_header_id;
 public $ar_transaction_line_id;
 public $supply_source;
 public $destination_type;
 public $ef_id;
 public $po_status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $shipping_org_id;
 public $line_status;
 public $requested_date;
 public $promise_date;
 public $schedule_ship_date;
 public $actual_ship_date;
 public $time;
 public $msg;
 public $item_number;
 public $tax_code_value;
 public $ar_transaction_number;

 public function _before_save() {
	if (!(empty($this->shipping_org_id))) {
	 if (!(empty($this->item_number))) {
		$item_s = item::find_by_itemNumber_orgId($this->item_number, $this->shipping_org_id);
		$this->item_id_m = $item_s->item_id_m;
	 }
	} else {
	 echo "<br> Saving line data failed!. No shipping organization. Error @ po_line @" . __LINE__;
	 return -99;
	}

	if ((empty($this->line_status)) && (!empty($this->schedule_ship_date))) {
	 $this->line_status = 'AWAITING_PICKING';
	} else if (($this->line_status = 'ENTERED') && (!empty($this->schedule_ship_date))) {
	 $this->line_status = 'AWAITING_PICKING';
	} else if ((empty($this->line_status)) && (empty($this->schedule_ship_date))) {
	 $this->line_status = 'ENTERED';
	}
 }

 public function _after_save() {
	
 }

 public function findAll_ByOrgId($org_id, $status = '') {
	$sql = " SELECT * FROM " .
					self::$table_name .
					" WHERE shipping_org_id= :shipping_org_id  ";
	if (!empty($status)) {
	 $sql .= " AND line_status = :line_status ";
	 $value_a = ['shipping_org_id' => $org_id, 'line_status' => $status];
	} else {
	 $value_a = ['shipping_org_id' => $org_id];
	}
	$result_array = $this->findBySql($sql, $value_a);
	return !empty($result_array) ? $result_array : false;
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