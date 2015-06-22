<?php

class ap_payment_interface extends dbObject {

 public static $table_name = "ap_payment_interface";
 public static $primary_column = "ap_payment_interface_id";
 public static $key_column = 'supplier_id';
 public static $module = "ap"; //same as gl_journal_source
 public $field_a = [
		 'ap_payment_interface_id',
		 'ap_transaction_header_id',
		 'bu_org_id',
		 'payment_type',
		 'supplier_id',
		 'supplier_site_id',
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
		 'pay_group',
		 'payment_method',
		 'approval_status',
		 'payment_status',
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
		 'ap_payment_interface_id',
		 'bu_org_id',
		 'payment_type',
		 'ap_transaction_header_id',
		 'supplier_id',
		 'from_bank_header_id',
		 'description',
		 'document_date',
		 'document_number',
		 'ledger_id',
		 'period_id',
		 'pay_group',
		 'payment_method',
		 'approval_status',
		 'payment_status',
 ];
 public $column = [
		 'ap_payment_interface_id',
		 'bu_org_id',
		 'payment_type',
		 'ap_transaction_header_id',
		 'amount',
		 'supplier_id',
		 'supplier_site_id',
		 'from_bank_header_id',
		 'description',
		 'document_date',
		 'document_number',
		 'ledger_id',
		 'period_id',
		 'pay_group',
		 'payment_method',
		 'approval_status',
		 'payment_status',
		 'currency',
		 'document_currency',
 ];
 public $requiredField = [
		 'bu_org_id',
		 'payment_type',
		 'supplier_id',
		 'supplier_site_id',
		 'amount',
		 'currency',
		 'ledger_id',
		 'period_id'
 ];
 public $fields_inForm_notInDataBase = [
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 'po_number',
		 'po_header_id',
		 'action',
		 'transaction_action',
		 'ap_transaction_header_id'
 ];
   public $numberField = [
   'amount',
  
  ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " AP Payment  "; //page Title
 public $option_lists = [
		 'payment_types' => 'AP_PAYMENT_TYPE',
//		 'po_status' => 'PO_STATUS',
 ];
 public $ap_payment_interface_id;
 public $bu_org_id;
 public $ap_transaction_header_id;
 public $payment_type;
 public $supplier_id;
 public $supplier_site_id;
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
 public $payment_method;
 public $approval_status;
 public $payment_status;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $gl_journal_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $supplier_name;
 public $supplier_number;
 public $supplier_site_name;
 public $po_number;
 public $po_header_id;
 public $action;
 public $transaction_action;
 public $action_class_name;
 public $mode;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;

 public function _before_save() {
	if ((!empty($this->ap_transaction_header_id)) && ($this->action == 'multi_payment')) {
	 $this->_multi_payment_action();
	}
 }

 public function findAll_groupBySupplier() {
	global $ie;
	global $dbc;
	$sql = " SELECT supplier_site_id, ap_payment_interface_id FROM ";
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

 private function _multi_payment_action() {
	$this->payment_type = 'MULTI_SELECT';
 }

 public function _after_save() {
	
 }

 public function multi_select_verification(&$error_msg = '') {
	//verify if any record us pending. If yes show that
	$any_record = $this->findAll();
	if (!empty($any_record)) {
	 $error_msg = "<div class='error'><br>Interface Records exists in Interface for BU Org Id " . $any_record[0]->bu_org_id .
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

//end of ap_payment_interface class
?>