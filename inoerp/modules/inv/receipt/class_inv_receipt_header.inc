<?php
class inv_receipt_header extends dbObject {
 
 public static $table_name = "inv_receipt_header";
 public static $dependent_classes = ['inv_receipt_line', 'po_all_v'];
 public static $primary_column = "inv_receipt_header_id";
 public static $primary_column2 = "receipt_number";
 public static $key_column = 'org_id';
 public static $module = "inv"; //same as gl_journal_source
 public static $gl_journal_category = "INV_RECEIVING";
 
 public $field_a = [
		 "inv_receipt_header_id",
		 "receipt_number",
		 "org_id",
		 "transaction_type_id",
		 "receipt_date",
		 "received_by",
		 "carrier",
		 "vechile_number",
		 "comment",
		 "ef_id",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//variables used for showing data

 public $initial_search = [
		 "inv_receipt_header_id",
		 "receipt_number",
		 "org_id",
		 "org",
		 "receipt_date",
		 "received_by",
		 "carrier",
		 "comments",
 ];
 public $column = [
		 "inv_receipt_header_id",
		 "receipt_number",
		 "org_id",
		 "receipt_date",
		 "received_by",
		 "carrier",
		 "vechile_number",
 ];
 public $fields_inForm_notInDataBase = [
		 "org",
		 		 'multi_action_class_pc',
		 'multi_action_class_pc_value',
		 'action'
 ];
 public $requiredField = [
		 "org_id",
		 "receipt_date"
 ];
   public $profile_default = [
   'org_id' => 'org_inv_name_default',
  ];
  public $search = [
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Receipt - Create & View Receipts"; //page Title
 public $option_lists = [
		 'inv_transaction_class' => 'TRANSACTION_TYPE_CLASS'
 ];
 
 public $inv_receipt_header_id;
 public $receipt_number;
 public $org_id;
 public $transaction_type_id;
 public $receipt_date;
 public $received_by;
 public $carrier;
 public $vechile_number;
 public $comments;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
  public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $action;
 
  public function _before_save() {
	if (($this->action == 'multi_receipt')) {
	 echo "<br> Starting Receipt.";
	 pa($_POST);
	 return 10;
	}
 }

 public function _after_save() {
	if ((!empty($this->inv_receipt_header_id)) && empty($this->receipt_number)) {
	 $inv_receipt_header_id = $this->inv_receipt_header_id;
	 $org_id = $this->org_id;
	 $this->receipt_number = $org_id . '-' . $inv_receipt_header_id;
	 echo '<br/> System created reecipt number is ' . $this->receipt_number;
	 $this->save();
	}

	return $this->msg;
 }
 
  public function multi_select_input_fields() {
	$multi_select_input = [
						'transaction_quantity',
			'subinventory_id',
			'locator_id',
	];
	return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
	$multi_select_hidden = [
			'action_class_name',
			'mode',
			'action',
			'show_block',
	];

	return $multi_select_hidden;
 }
 
}

?>