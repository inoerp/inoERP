<?php

class cm_statement_line extends dbObject {

 public static $table_name = "cm_statement_line";
 public static $primary_column = "cm_statement_line_id";
 public static $parent_primary_column = "cm_statement_header_id";
 public static $key_column = 'line_num';
 public static $module = "cm";
 public static $line_type_a = [
		 'RECE' => 'Receipt',
		 'PAYM' => 'Payment'
 ];
 public static $line_status_a = [
		 'UNREC' => 'Unreconciled',
		 'RECON' => 'Reconciled'
 ];
 public static $source_status_a = [
		 'U' => 'Updated'
 ];
 public $field_a = [
		 'cm_statement_line_id',
		 'cm_statement_header_id',
		 'line_num',
		 'status',
		 'line_type',
		 'description',
		 'line_code',
		 'seq_number',
		 'transaction_value',
		 'reconciled_value',
		 'charge',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'transaction_date',
		 'currency',
		 'exchange_date',
		 'exchange_rate',
		 'exchange_type',
		 'original_amount',
		 'agent_name',
		 'agent_bank_account',
		 'invoice_num',
		 'ar_receipt_line_id',
		 'ar_receipt_header_id',
		 'ap_payment_line_id',
		 'ap_payment_header_id',
		 'source_status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $requiredField = [
		 'cm_statement_header_id',
		 'line_num',
		 'status',
		 'line_type',
 ];
 public $fields_inForm_notInDataBase = [
		 "payment_number",
		 "receipt_number",
		 'line_number',
		 'ar_transaction_number',
		 'line_action'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "cm_statement_header_id"
 ];
 public $notUpdatedFromWebForm = [
		 'actual_ship_date',
 ];
 public $ar_receipt_line_id;
 public $ar_receipt_header_id;
 public $ap_payment_header_id;
 public $ap_payment_line_id;
 public $payment_number;
 public $receipt_number;
 public $line_number;
 public $cm_statement_line_id;
 public $cm_statement_header_id;
 public $line_num;
 public $status;
 public $line_type;
 public $description;
 public $line_code;
 public $seq_number;
 public $transaction_value;
 public $reconciled_value;
 public $charge;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $transaction_date;
 public $currency;
 public $exchange_date;
 public $exchange_rate;
 public $exchange_type;
 public $original_amount;
 public $agent_name;
 public $agent_bank_account;
 public $invoice_num;
 public $source_status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 private function _validate_before_save() {
	$ret = 1;
	if ($this->line_status == 'SHIPPED') {
	 $ret = -90;
	 echo "<br> You cant modify any shipped sales order line ";
	}

	if ($ret > 0) {
	 $item = item::find_by_orgId_item_id_m($this->item_id_m, $this->shipping_org_id);
	 if ($item) {
		if (empty($item->customer_ordered_cb)) {
		 $ret = -90;
		 echo "<br> The item is not enabled for Sales ";
		}
	 } else {
		$ret = -90;
		echo "<br> The item is not assigned to the organization";
	 }
	}

	if ($ret > 0) {
	 if (!empty($this->kit_cb) && empty($this->bom_config_header_id)) {
		$ret = -90;
		echo "<br><div class='message'><div class='alert alert-danger'>Sales line is not saved as selected <strong>configured item has no configuration.</strong></div> "
		. "<br>Select configuration & save again.</div>";
	 } else if (empty($this->bom_config_header_id) && !empty($this->kit_cb) && !empty($this->bom_config_header_id)) {
		$this->bom_config_header_id = 1;
	 }
	}


	return $ret;
 }

 public function _before_save() {
	if (empty($this->source_status) && ($this->status == 'RECON')) {
	 $this->_update_source_status();
	}
 }

 public function _after_save() {
	
 }

 private function _update_source_status() {
	if (!empty($this->ap_payment_line_id)) {
	 $this->_update_payment_status($this->ap_payment_line_id);
	} else if (!empty($this->ar_receipt_line_id)) {
	 $this->_update_receipt_status($this->ar_receipt_line_id);
	}
 }

 private function _update_payment_status($ap_payment_line_id) {
	global $dbc;
	$ap_payment_line_i = new ap_payment_line();
	$ap_payment_line_i->findBy_id($ap_payment_line_id);
	$ap_payment_line_i->status = 'CLEARED';
	try {
	 $ap_payment_line_i->save();
	 $this->status = 'RECON';
	} catch (Exception $e) {
	 echo '<br>Failed to clear the AP payment. ' . $e->getMessage();
	 $dbc->rollback = true;
	}
 }

 private function _update_receipt_status($ar_receipt_line_id) {
	global $dbc;
	$ar_receipt_line_i = new ar_receipt_line();
	$ar_receipt_line_i->findBy_id($ar_receipt_line_id);
	$ar_receipt_line_i->status = 'CLEARED';

	try {
	 $ar_receipt_line_i->save();
	 $this->status = 'RECON';
	} catch (Exception $e) {
	 echo '<br>Failed to clear the AR receipt ' . $e->getMessage();
	 $dbc->rollback = true;
	}
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

 Public static function cm_statement_line_types() {
	$option_header = option_header::find_by_name('PO_LINE_TYPE');
	$po_types = option_line::find_by_option_id($option_header->option_header_id);
	return $po_types;
 }

 public static function find_by_cm_statement_headerId($cm_statement_header_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where cm_statement_header_id = '{$cm_statement_header_id}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

 public static function find_by_orgId_itemId_ssd($org_id, $item_id_m = '', $ssd = '') {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE shipping_org_id = '{$org_id}'";
	$sql .= " AND schedule_ship_date IS NOT NULL ";
	if (!empty($item_id_m)) {
	 $sql .= " AND item_id_m = '{$item_id_m}'";
	}
	if (!empty($ssd)) {
	 $sql .= " AND schedule_ship_date >= '{$ssd}'";
	}
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? $result_array : false;
 }

 public function copy($cm_statement_line_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM cm_statement_line WHERE `cm_statement_line_id` = '{$cm_statement_line_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `cm_statement_line_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `cm_statement_line_id` = '{$cm_statement_line_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `cm_statement_line` SELECT * FROM tmptable WHERE `cm_statement_line_id` = '' ";
		if ($db->query($sql3)) {
		 $this->cm_statement_line_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

}

//end of cm_statement_line class
?>