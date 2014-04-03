<?php

class receipt_header extends dbObject {

 protected static $table_name = "receipt_header";
 public static $dependent_classes = ['receipt_line', 'po_all_v'];
 public static $primary_column = "receipt_header_id";
 public static $primary_column2 = "receipt_number";
 public static $multi_select_template_path = "modules/inv/receipt/receipt_template.php";
 
 public static $key_column = 'org_id';
 public static $module = "inv"; //same as gl_journal_source
 public static $gl_journal_category = "INV_RECEIVING";
 public $field_a = [
		 "receipt_header_id",
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
		 "receipt_header_id",
		 "receipt_number",
		 "org_id",
		 "org",
		 "receipt_date",
		 "received_by",
		 "carrier",
		 "comments",
 ];
 public $column = [
		 "receipt_header_id",
		 "receipt_number",
		 "org_id",
		 "receipt_date",
		 "received_by",
		 "carrier",
		 "vechile_number",
 ];
 public $fields_inForm_notInDataBase = [
		 "org"
 ];
 public $requiredField = [
		 "org_id",
		 "receipt_date"
 ];
 public $receipt_header_id;
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

 public function _after_save() {
	if ((!empty($this->receipt_header_id)) && empty($this->receipt_number)) {
	 $receipt_header_id = $this->receipt_header_id;
	 $org_id = $this->org_id;
	 $this->receipt_number = $org_id . '-' . $receipt_header_id;
	 echo '<br/> System created reecipt number is ' . $this->receipt_number;
	 $this->save();
	}

	return $this->msg;
 }
 
}

?>