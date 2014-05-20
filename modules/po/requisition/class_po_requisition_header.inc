<?php

class po_requisition_header extends dbObject {

 protected static $table_name = "po_requisition_header";
 public static $dependent_classes = ['po_requisition_line', 'po_requisition_detail'];
 public static $primary_column = "po_requisition_header_id";
 public static $primary_column2 = "po_requisition_number";
 public static $key_column = 'bu_org_id';
 public static $module = "po";
 public $checkbox = [
		 "rev_enabled_cb"
 ];
 public $field_a = [
		 'po_requisition_header_id',
		 'bu_org_id',
		 'po_requisition_type',
		 'po_requisition_number',
		 'supplier_id',
		 'supplier_site_id',
		 'buyer',
		 "description",
		 'ship_to_id',
		 'bill_to_id',
		 'header_amount',
		 'currency',
		 'payment_term_id',
		 'exchange_rate_type',
		 'exchange_rate',
		 "ef_id",
		 "requisition_status",
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public $initial_search = [
		 "po_requisition_header_id",
		 "po_requisition_number",
		 "supplier_id",
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 "buyer"
 ];
 public $column = [
		 "po_requisition_header_id",
		 "po_requisition_number",
		 "requisition_status",
		 "supplier_id",
		 "creation_date",
		 "buyer",
		 "supplier_name",
		 "supplier_site_name",
 ];
 public $requiredField = [
		 'bu_org_id',
		 'po_requisition_type',
 ];
 public $addressField = [
		 'ship_to_id',
		 'bill_to_id'
 ];
 public $fields_inForm_notInDataBase = [
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 "ship_to_address",
		 "bill_to_address"
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
		 '_extra_path' => array('form.php?class_name=po_header&mode=9' => 'Create PO')
 ];
 public $pageTitle = " Requisition - Purchasing "; //page Title
 public $option_lists = [
		 'po_requisition_type' => 'PO_REQUISITION_TYPE',
		 'requisition_status' => 'PO_STATUS',
 ];
 public $po_requisition_header_id;
 public $bu_org_id;
 public $po_requisition_type;
 public $po_requisition_number;
 public $supplier_id;
 public $supplier_site_id;
 public $buyer;
 public $description;
 public $ship_to_id;
 public $bill_to_id;
 public $header_amount;
 public $currency;
 public $payment_term_id;
 public $agreement_start_date;
 public $aggrement_end_date;
 public $exchange_rate_type;
 public $exchange_rate;
 public $released_amount;
 public $ef_id;
 public $requisition_status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $supplier_name;
 public $supplier_number;
 public $supplier_site_name;
 public $ship_to_address;
 public $bill_to_address;
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
	$primary_column = self::$primary_column;
	if (empty($this->$primary_column)) {
	 $this->requisition_status = 'Entered';
	}

	return;
 }

 public function _after_save() {
	global $db;
	echo '<br/> entered Requisition number is ' . $this->po_requisition_number;
	if ((!empty($this->po_requisition_header_id)) && empty($this->po_requisition_number)) {
	 $po_requisition_header_id = $this->po_requisition_header_id;
	 $bu_org_id = $this->bu_org_id;
	 $po_requisition_number = $bu_org_id . '-' . $po_requisition_header_id;
	 echo '<br/> New PO number is ' . $po_requisition_number;
	 $this->msg = $this->update_po_requisitionNumber($po_requisition_header_id, $po_requisition_number);
	}

	return $this->msg;
 }

 private function update_po_requisitionNumber($po_requisition_header_id, $po_requisition_number) {
	global $dbc;
	$sql = " UPDATE " . self::$table_name;
	$sql .= " SET po_requisition_number = '{$po_requisition_number}'  ";
	$sql .= " WHERE po_requisition_header_id = '{$po_requisition_header_id}'  ";
	try {
	 $dbc->ddlexecute($sql);
	 $this->po_requisition_number = $po_requisition_number;
	} catch (Exception $e) {
	 $this->msg = 0;
	 echo "<br>Error in updating Requisition number" . $e->getMessage();
	}
 }

 public static function instantiate_extra_fields(&$array_of_objects) {
	if (count($array_of_objects) > 0) {
	 foreach ($array_of_objects as &$this_object) {
		$supplier_details = supplier::find_by_id($this_object->supplier_id);
		$this_object->supplier_name = $supplier_details->supplier_name;
		$this_object->supplier_number = $supplier_details->supplier_number;
		$supplier_site_details = supplier_site::find_by_id($this_object->supplier_site_id);
		$this_object->supplier_site_name = $supplier_site_details->supplier_site_name;
	 }
	}
	return $array_of_objects;
 }

 Public static function po_requisition_type() {
	$option_header = option_header::find_by_name('PO_REQUISITION_TYPE');
	$po_requisition_types = option_line::find_by_option_id($option_header->option_header_id);
	return $po_requisition_types;
 }

 Public static function requisition_status() {
	$option_header = option_header::find_by_name('PO_STATUS');
	$po_requisition_status = option_line::find_by_option_id($option_header->option_header_id);
	return $po_requisition_status;
 }

 public function copy($po_requisition_header_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM po_requisition_header WHERE `po_requisition_header_id` = '{$po_requisition_header_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `po_requisition_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `po_requisition_header_id` = '{$po_requisition_header_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `po_requisition_header` SELECT * FROM tmptable WHERE `po_requisition_header_id` = '' ";
		if ($db->query($sql3)) {
		 $this->po_requisition_header_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

// public function save() {
//	$primary_column = static::$primary_column;
//	if (empty($this->$primary_column)) {
//	 $this->requisition_status = 'Entered';
//	 $this->create();
//	} else {
//	 $this->update($this->$primary_column);
//	}
//	return $this->msg;
// }
}

//end of po_requisition_header class
?>