<?php

class receipt_header extends dbObject {

 protected static $table_name = "receipt_header";
 public static $field_array = [
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

 public static $initial_search_array = [
		 "receipt_header_id",
		 "receipt_number",
		 "org_id",
		 "org",
		 "receipt_date",
		 "received_by",
		 "carrier",
		 "comments",
 ];
 public static $column_array = [
		 "receipt_header_id",
		 "receipt_number",
		 "org_id",
		 "receipt_date",
		 "received_by",
		 "carrier",
		 "vechile_number",
 ];
 public static $account_array = [
 ];
 public static $checkbox_array = [
 ];
 public static $fields_inForm_notInDataBase = [
		 "org"
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $requiredField_array = [
		 "org_id",
		 "receipt_date"
 ];
 public static $primary_column = "receipt_header_id";
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

 public function _before_showing() {

//	if (!(empty($this->transaction_type_id))) {
//	 switch ($this->transaction_type_id) {
//		case 1 :
//		 $this->account_id = $this->to_account_id;
//		 break;
//
//		case 2 :
//		 $this->account_id = $this->from_account_id;
//		 break;
//
//		default:
//		 if (!empty($this->to_account_id)) {
//			$this->account_id = $this->to_account_id;
//		 } else {
//			$this->account_id = $this->from_account_id;
//		 }
//
//		 break;
//	 }
//	}
//
//	if (!empty($this->to_account_id)) {
//	 $this->account_id = $this->to_account_id;
//	} else {
//	 $this->account_id = $this->from_account_id;
//	}
	
 }

 public function _before_submit() {
//	if (!(empty($this->transaction_type_id))) {
//	 switch ($this->transaction_type_id) {
//		case 1 :
//		 array_push(self::$requiredField_array, 'to_account_id');
//		 array_push(self::$requiredField_array, 'from_subinventory_id');
//		 $this->from_account_id = "";
//		 $this->to_account_id = $this->account_id;
//		 break;
//
//		case 2 :
//		 array_push(self::$requiredField_array, 'from_account_id');
//		 array_push(self::$requiredField_array, 'to_subinventory_id');
//		 $this->from_account_id = $this->account_id;
//		 $this->to_account_id = "";
//		 break;
//
//		case 3 :
//		 array_push(self::$requiredField_array, 'to_subinventory_id');
//		 array_push(self::$requiredField_array, 'from_subinventory_id');
//		 break;
//
//		default:
//		 break;
//	 }
//	}
 }

  private function update_receiptNumber($receipt_header_id, $receipt_number) {
	global $db;

	$sql = " UPDATE " . self::$table_name;
	$sql .= " SET receipt_number = '{$receipt_number}'  ";
	$sql .= " WHERE receipt_header_id = $receipt_header_id  ";
	
//	    echo "<br/>$sql is <br/>" . $sql;
	if ($db->query($sql)) {
	 $this->msg = 1;
	 $this->receipt_number = $receipt_number;
	} else {
	 $this->msg = 0;
	}

	return $this->msg;
 }
 
 public function _after_save() {
	global $db;
 	if ((!empty($this->receipt_header_id)) && empty($this->receipt_number)) {
	 $receipt_header_id = $this->receipt_header_id;
	 $org_id = $this->org_id;
	 $receipt_number = $org_id . '-' . $receipt_header_id;
	 	 $this->msg = $this->update_receiptNumber($receipt_header_id, $receipt_number);
	}

	return $this->msg;
 }

}
?>