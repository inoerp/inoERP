<?php

class ar_transaction_line extends dbObject {

 protected static $table_name = "ar_transaction_line";
 public static $primary_column = "ar_transaction_line_id";
 public static $parent_primary_column = "ar_transaction_header_id";
 public static $multi_search_primary_column = "ar_transaction_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'item_description';
 public static $module = "ap";
 public $field_a = [
		 'ar_transaction_line_id',
		 'ar_transaction_header_id',
		 'line_number',
		 'item_id',
		 'item_description',
		 'inv_line_quantity',
		 'inv_unit_price',
		 'inv_line_price',
		 'line_type',
		 'line_description',
		 'asset_cb',
		 'fa_asset_category_id',
		 'prj_project_header_id',
		 'prj_project_line_id',
		 'uom_id',
		 'ef_id',
		 'status',
		 'line_source',
		 'sd_so_header_id',
		 'sd_so_line_id',
		 'sd_so_detail_id',
		 'period_id',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $requiredField = [
		 'ar_transaction_header_id',
		 'line_number',
		 'item_description',
		 'inv_line_quantity',
		 'inv_unit_price',
		 'inv_line_price',
 ];
 public $fields_inForm_notInDataBase = [
		 "transaction_number",
		 "item_number",
		 'customer_name',
		 'customer_number',
		 'item_description',
		 'uom_id',
		 'invoiced_quantity',
		 'action'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "ar_transaction_header_id"
 ];
 public $ar_transaction_line_id;
 public $ar_transaction_header_id;
 public $line_number;
 public $item_id;
 public $inv_line_quantity;
 public $inv_unit_price;
 public $inv_line_price;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $line_type;
 public $line_description;
 public $asset_cb;
 public $fa_asset_category_id;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $uom;
 public $ef_id;
 public $status;
 public $line_source;
 public $sd_so_header_id;
 public $sd_so_line_id;
 public $sd_so_detail_id;
 public $period_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $customer_name;
 public $customer_number;
 public $item_number;
 public $item_description;
 public $uom_id;
 public $invoiced_quantity;
 public $action;

 public function _after_save() {
	if (($this->action === 'match_transaction')&&(!empty($this->sd_so_line_id)) && (!empty($this->sd_so_detail_id))) {
	 $ar_th = new ar_transaction_header();
	 $ar_th_i = $ar_th->findBy_id($this->ar_transaction_header_id);
	 $om_so_d = new om_so_detail();
	 $om_so_d_i = $om_so_d->findBy_id($this->sd_so_detail_id);
	 $ar_td = new ar_transaction_detail();
	 $ar_td->ar_transaction_line_id = $this->ar_transaction_line_id;
	 $ar_td->ar_transaction_header_id = $this->ar_transaction_line_id;
	 $ar_td->detail_number = 1;
	 $ar_td->account_type = 'ITEM';
	 $ar_td->description = '';
	 $ar_td->amount = $this->inv_line_price;
	 $ar_td->detail_ac_id = $om_so_d_i->charge_ac_id;
	 $ar_td->status = '';
	 $ar_td->reference_type = 'table';
	 $ar_td->reference_key_name = 'om_so_header';
	 $ar_td->reference_key_value = $this->sd_so_header_id;
	 $ar_td->sd_so_header_id = $this->sd_so_header_id;
	 $ar_td->sd_so_line_id = $this->sd_so_line_id;
	 $ar_td->sd_so_detail_id = $this->sd_so_detail_id;
	 $ar_td->period_id = $ar_th_i->period_id;
	 $ar_td->audit_trial();
	 //update PO details
	 foreach ($om_so_d_i as $pd_key => $pd_value) {
		$om_so_d->$pd_key = $pd_value;
	 }
	 
	 echo "<br>Quanitities are in PO : " . $om_so_d->invoiced_quantity . ' in Inv Line : ' . $this->inv_line_quantity . ' : Submitted by form ' . $this->invoiced_quantity;
	 $om_so_d->invoiced_quantity = $this->inv_line_quantity + $this->invoiced_quantity;
	 $om_so_d->save();
	 $ar_td->save();
	}
 }

 public function _before_save() {
	if ((!empty($this->sd_so_header_id)) && ($this->ar_transaction_header_id)) {
	 $current_highest_line_no = $this->_highest_line_number_from_header();
	 $this->line_number = $current_highest_line_no->line_number + 1;
	}
	if (empty($this->line_type)) {
	 $this->line_type = 'GOODS';
	}
 }

 private function _highest_line_number_from_header() {
	global $db;
	$sql = " SELECT max(line_number) as line_number FROM " . self::$table_name;
	$sql .= " WHERE ar_transaction_header_id= :ar_transaction_header_id ";
	$param_a = ['ar_transaction_header_id'];
	$value_a = ['ar_transaction_header_id' => $this->ar_transaction_header_id];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? array_pop($result) : 0;
 }

 Public static function ar_transaction_line_types() {
	$option_header = option_header::find_by_name('PO_LINE_TYPE');
	$om_so_types = option_line::find_by_option_id($option_header->option_header_id);
	return $om_so_types;
 }

 public static function find_by_ar_transaction_headerId($ar_transaction_header_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where ar_transaction_header_id = '{$ar_transaction_header_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

 public function multi_select_input_fields() {
	$multi_select_input = [
			'inv_line_quantity',
			'inv_unit_price',
			'inv_line_price',
			'inv_line_type'
	];
	return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
	$multi_select_hidden = [
			'action_class_name',
			'customer_id',
			'sd_so_header_id',
			'ar_transaction_header_id',
			'mode',
			'action',
			'om_so_status'
	];

	return $multi_select_hidden;
 }

 public function copy($ar_transaction_line_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM ar_transaction_line WHERE `ar_transaction_line_id` = '{$ar_transaction_line_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `ar_transaction_line_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `ar_transaction_line_id` = '{$ar_transaction_line_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `ar_transaction_line` SELECT * FROM tmptable WHERE `ar_transaction_line_id` = '' ";
		if ($db->query($sql3)) {
		 $this->ar_transaction_line_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

}

//end of ar_transaction_line class
?>