<?php

class transaction_type extends dbObject {

 protected static $table_name = "transaction_type";
 public static $field_array = [
		 "transaction_type_id",
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
		 "transaction_type",
		 "type_class",
		 "transaction_action",
		 "description"
 ];
 public static $column_array = [
		 "transaction_type_id",
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
		 "type_class",
		 "transaction_action"
 ];
 public static $primary_column = "transaction_type_id";
 public $transaction_type_id;
 public $transaction_type;
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
								<th> Transaction Type</th>
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

// public static function find_by_sql($sql = "") {
//	global $db;
//	$result_set = $db->query($sql);
//	$object_array = array();
//	while ($row = $db->fetch_array($result_set)) {
//	 $object_array[] = self::instantiate($row);
//	}//end of while Loop
//	return $object_array;
// }
//
// public static function find_all() {
//	$sql = " SELECT * FROM " . self::$table_name;
//	$result = self::find_by_sql($sql);
//	return $result;
// }
//
// public static function count_all() {
//	global $db;
//	$sql = "SELECT COUNT(*) FROM " . self::$table_name;
//	$result_set = $db->query($sql);
//	$row = $db->fetch_array($result_set);
//	return array_shift($row);
// }
//
// public static function count_all_by_sql($sql) {
//	global $db;
//	$result_set = $db->query($sql);
//	$row = $db->fetch_array($result_set);
//	return array_shift($row);
// }
//
// public static function find_by_id($transaction_type_id) {
//	$sql = "SELECT * FROM " . self::$table_name . " where transaction_type_id={$transaction_type_id} LIMIT 1";
//	$result_array = self::find_by_sql($sql);
//	return !empty($result_array) ? array_shift($result_array) : false;
// }
//
// private static function instantiate($record) {
//	$object = new self;
//	foreach ($record as $attribute => $value) {
//	 if ($object->has_attribute($attribute)) {
//		$object->$attribute = $value;
//	 }
//	}
//	return $object;
// }
//
// Private function has_attribute($attribute) {
//	$object_vars = get_object_vars($this);
//	return array_key_exists($attribute, $object_vars);
// }
//
// public static function install() {
//	global $db;
//	$sql = "
//		 ";
//	$result = $db->query($sql);
//	return !empty($result) ? $result : false;
// }
//
// public function save() {
//	if (empty($this->transaction_type_id)) {
//	 $this->create();
//	} else {
//	 $this->update($this->transaction_type_id);
//	}
//	return $this->msg;
// }
//
// public function create() {
//	global $db;
//	$field_arry_colums = array();
//	$field_arry_values = array();
//	foreach (self::$field_array as $key => $value) {
//	 $field_arry_colums[] = sprintf("`%s`", $value);
//	}
//	$field_colums = implode(',', $field_arry_colums);
//
//	foreach (self::$field_array as $key => $value) {
//	 if (!empty($this->$value)) {
//		$field_arry_values[] = sprintf("'%s'", $this->$value);
//	 } else {
//		$field_arry_values[] = 'NULL';
//	 }
//	}
//	$field_values = implode(',', $field_arry_values);
//
//	$sql = " INSERT INTO ";
//	$sql.= self::$table_name;
//	$sql.= ' ( ';
//	$sql.= $field_colums;
//	$sql.= ' ) ';
//	$sql.= 'VALUES';
//	$sql.= ' ( ';
//	$sql.= $field_values;
//	$sql.= ' ) ';
//
//	if ($db->query($sql)) {
//	 $this->transaction_type_id = $db->insert_id();
//	 $this->msg = 1;
//	} else {
//	 $this->msg = 0;
//	}
//	return $this->msg;
// }
//
////end of create transaction_type
//
// public function update($transaction_type_id) {
//	global $db;
//	$field_arry_values = array();
//
//	foreach (self::$field_array as $key => $value) {
//	 if (!empty($this->$value)) {
//		$field_arry_values[] = sprintf("`%s` = '%s'", $value, $this->$value);
//	 }
//	}
//	$field_values = implode(',', $field_arry_values);
//
//	$time = time();
//	$last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
//	$last_update_by = $_SESSION['user_name'];
//
//	$sql = " UPDATE ";
//	$sql.= self::$table_name;
//	$sql .= " SET ";
//	$sql.= $field_values;
////    $sql.= "`last_update_date` = '{$last_update_date}'," ;
////    $sql.= "`last_update_by` = '{$last_update_by }'" ;
//	$sql.= " WHERE `transaction_type_id` = '{$transaction_type_id}' ";
//
////    echo "<br/>$sql is <br/>" . $sql;
//
//	if ($db->query($sql)) {
//	 $this->msg = 1;
//	} else {
//	 $this->msg = 0;
//	}
//	return $this->msg;
// }
//
// public static function transaction_type_page() {
//	echo '<table class="normal"><thead><tr>';
//	foreach (self::$field_array as $key => $value) {
//	 echo '<th>' . $value . '</th>';
//	}
//	echo '</tr></thead><tbody>';
//
//	$transaction_type = self::find_all();
////    echo '<pre>';
////    print_r($transaction_type);
////    echo '<pre>';
//	foreach ($transaction_type as $record) {
//	 echo '<tr>';
//	 foreach (self::$field_array as $key => $value) {
//		echo '<td>' . $record->$value . '</td>';
//	 }
//	 echo '</tr>';
//	}
//	echo ' </tbody> </table>';
// }
}

//end of transaction_type class
?>



