<?php

class cst_item_cost_interface extends dbObject {

 public static $table_name = "cst_item_cost_interface";
 public static $primary_column = "cst_item_cost_interface_id";
 public static $key_column = 'ar_customer_id';
 public static $module = "ap"; //same as gl_journal_source
 public $field_a = [
		 'cst_item_cost_interface_id',
		 'ar_transaction_header_id',
		 'bu_org_id',
		 'receipt_type',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'from_bank_header_id',
		 'description',
		 'from_bank_line_id',
		 'to_bank_header_id',
		 'amount',
		 'currency',
		 'document_currency',
		 'to_bank_line_id',
		 'exchange_rate_type',
		 'exchange_rate',
		 'ef_id',
		 'document_date',
		 'document_number',
		 'ledger_id',
		 'period_id',
		 'receipt_method',
		 'approval_status',
		 'receipt_status',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'gl_journal_header_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $initial_search = [
		 'cst_item_cost_interface_id',
		 'bu_org_id',
		 'receipt_type',
		 'ar_transaction_header_id',
		 'ar_customer_id',
		 'from_bank_header_id',
		 'description',
		 'document_date',
		 'document_number',
		 'ledger_id',
		 'period_id',
		 'receipt_method',
		 'approval_status',
		 'receipt_status',
 ];
 public $column = [
		 'cst_item_cost_interface_id',
		 'bu_org_id',
		 'receipt_type',
		 'ar_transaction_header_id',
		 'amount',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'from_bank_header_id',
		 'description',
		 'document_date',
		 'document_number',
		 'ledger_id',
		 'period_id',
		 'receipt_method',
		 'approval_status',
		 'receipt_status',
		 'currency',
		 'document_currency',
 ];
 public $requiredField = [
		 'bu_org_id',
		 'receipt_type',
		 'ar_customer_id',
		 'ar_customer_site_id',
		 'amount',
		 'currency',
		 'ledger_id',
		 'period_id'
 ];
 public $fields_inForm_notInDataBase = [
		 "customer_name",
		 "customer_number",
		 "supplier_site_name",
		 'po_number',
		 'sd_so_header_id',
		 'action',
		 'transaction_action'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " AR Multi Receipt  "; //page Title
 public $option_lists = [
		 'receipt_types' => 'AR_RECEIPT_TYPE',
//		 'po_status' => 'PO_STATUS',
 ];
 public $cst_item_cost_interface_id;
 public $bu_org_id;
 public $ar_transaction_header_id;
 public $receipt_type;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $from_bank_header_id;
 public $description;
 public $from_bank_line_id;
 public $to_bank_header_id;
 public $amount;
 public $currency;
 public $document_currency;
 public $to_bank_line_id;
 public $exchange_rate_type;
 public $exchange_rate;
 public $ef_id;
 public $document_date;
 public $document_number;
 public $ledger_id;
 public $period_id;
 public $pay_group;
 public $receipt_method;
 public $approval_status;
 public $receipt_status;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $gl_journal_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $customer_name;
 public $customer_number;
 public $supplier_site_name;
 public $po_number;
 public $sd_so_header_id;
 public $action;
 public $transaction_action;
 public $action_class_name;
 public $mode;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;

 public function __set($name, $value) {
	switch ($value) {
	 case $value:


		break;

	 default:
		$this->$name = $value;
		break;
	}
 }

 public function _before_save() {
	if ((!empty($this->ar_transaction_header_id)) && ($this->action == 'multi_receipt')) {
	 $this->_multi_receipt_action();
	}
 }

 public function findAll_groupByCustomer() {
	global $ie;
	global $dbc;
	$sql = " SELECT ar_customer_site_id, cst_item_cost_interface_id FROM ";
	$sql.= self::$table_name;
	$stmt = $dbc->connection->prepare(" $sql ");
	try {
	 $stmt->execute();
	 $result = $stmt->fetchAll(PDO::FETCH_COLUMN | PDO::FETCH_GROUP);
	} catch (PDOException $e) {
	 $ie->page_exception = ['dbObject findBy id Error : ' => $e->getMessage()];
	 echo "Record couldnt be saved!!: " . $e->getMessage();
	}
	return $result;
 }

 private function _multi_receipt_action() {
	$this->receipt_type = 'MULTI_SELECT';
 }

 public function _after_save() {
	
 }

 public function multi_select_verification(&$error_msg='') {
	//verify if any record us pending. If yes show that
	$any_record = $this->findAll();
	if(!empty($any_record)){
	 $error_msg = "<div class='error'><br>Interface Records exists in Interface for BU Org Id ". $any_record[0]->bu_org_id.
					 "<br>You should review/import/delete all records in interface before proceeding further! </div>";
	}
 }

 public function multi_select_input_fields() {
	$multi_select_input = [
			'amount',
	];
	return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
	$multi_select_hidden = [
			'action_class_name',
			'mode',
			'action',
			'show_block'
	];

	return $multi_select_hidden;
 }

}

//end of cst_item_cost_interface class
?>