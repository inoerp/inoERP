<?php

class transaction_type extends dbObject {

 protected static $table_name = "transaction_type";
 public static $field_array = [
		 "transaction_type_id",
		 'transaction_type_number',
		 "transaction_type",
		 "type_class",
		 "transaction_action",
		 "description",
		 "allow_negative_balance_cb",
		 "account_id",
		 "ef_id",
		 "status",
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $initial_search_array = [
		 "transaction_type_id",
		 'transaction_type_number',
		 "transaction_type",
		 "type_class",
		 "transaction_action",
		 "description"
 ];
 public static $column_array = [
		 "transaction_type_id",
		 'transaction_type_number',
		 "transaction_type",
		 "type_class",
		 "transaction_action",
		 "description",
		 "allow_negative_balance_cb",
		 "account_id"
 ];
 public static $account_array = [
		 "account_id"
 ];
 public static $checkbox_array = [
		 "rev_enabled_cb",
		 "allow_negative_balance_cb"
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 "transaction_type",
		 'transaction_type_number',
		 "type_class",
		 "transaction_action"
 ];
 public static $primary_column = "transaction_type_id";
 public $transaction_type_id;
 public $transaction_type;
 public $transaction_type_number;
 public $type_class;
 public $transaction_action;
 public $description;
 public $allow_negative_balance_cb;
 public $account_id;
 public $ef_id;
 public $status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 Public static $tab_header = <<<'VAR'
            <ul class="tabMain">
                          <li><a href="#tabsHeader-1">Mandatory</a></li>
                          <li><a href="#tabsHeader-2">Other Info</a></li>
            </ul>
VAR;
 public static $tabs_header1_tr = <<<'VAR'
              <thead> 
               <tr>
								<th>Action</th>
								<th>Type Id</th>
								<th>Number</th>
								<th>Transaction Type</th>
								<th>Class</th>
								<th>Trnx Action</th>
								<th>Description</th>
								<th>Negative Balance</th>
							</tr>
              </thead>
VAR;
 public static $tabs_header2_tr = <<<'VAR'
              <thead> 
               <tr>
								<th>Account No</th>
								<th>EF Id</th>
								<th>Status</th>
								<th>Rev Enabled</th>
								<th>Rev#</th>
							</tr>
              </thead>
VAR;

 Public static function transaction_type_class() {
	$option_header = option_header::find_by_name('TRANSACTION_TYPE_CLASS');
	$transaction_type_class = option_line::find_by_option_id($option_header->option_header_id);
	return $transaction_type_class;
 }

 Public static function transaction_action() {
	$option_header = option_header::find_by_name('INV_TRANSACTION_ACTION');
	$transaction_action = option_line::find_by_option_id($option_header->option_header_id);
	return $transaction_action;
 }

 Public static function transaction_action_description($line_code) {
	$option_header = option_header::find_by_name('INV_TRANSACTION_ACTION');
	$transaction_action = option_line::find_by_optionId_lineCode($option_header->option_header_id, $line_code);
	return $transaction_action;
 }

 Public static function transaction_action_by_code($code) {
	$option_header = option_header::find_by_name('INV_TRANSACTION_ACTION');
	$transaction_action = option_line::find_by_option_id($option_header->option_header_id);
	return $transaction_action;
 }

 public static function find_by_transactionNumber($number) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE transaction_type_number = '{$number}' LIMIT 1";
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

 public static function find_by_transactionClass($class) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE type_class = '{$class}' ";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of transaction_type class
?>