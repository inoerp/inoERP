<?php

class om_so_header extends dbObject {

 protected static $table_name = "om_so_header";
 public static $account_array = [
 ];
 public static $checkbox_array = [
		 "rev_enabled_cb"
 ];
 public static $field_array = [
		 'om_so_header_id',
		 'bu_org_id',
		 'om_so_type',
		 'om_so_number',
		 'supplier_id',
		 'supplier_site_id',
		 'buyer',
		 "description",
		 'ship_to_id',
		 'bill_to_id',
		 'header_amount',
		 'currency',
		 'payment_term_id',
		 'agreement_start_date',
		 'aggrement_end_date',
		 'exchange_rate_type',
		 'exchange_rate',
		 'released_amount',
		 "ef_id",
		 "om_so_status",
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $initial_search_array = [
		 "om_so_header_id",
		 "om_so_number",
		 "om_so_status",
		 "supplier_id",
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 "creation_date",
		 "buyer"
 ];
 public static $column_array = [
		 "om_so_header_id",
		 "om_so_number",
		 "om_so_status",
		 "supplier_id",
		 "creation_date",
		 "buyer",
		 "supplier_name",
		 "supplier_site_name",
 ];
 public static $requiredField_array = [
		 'supplier_id',
		 'supplier_site_id',
		 'ship_to_id',
		 'bill_to_id',
		 'currency',
		 'payment_term_id'
 ];
 public static $addressField_array = [
		 'ship_to_id',
		 'bill_to_id'
 ];
 public static $fields_inForm_notInDataBase = [
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 "ship_to_address",
		 "bill_to_address"
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = "om_so_header_id";
 public static $primary_column2 = "om_so_number";
 
 public $om_so_header_id;
 public $bu_org_id;
 public $om_so_type;
 public $om_so_number;
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
 public $om_so_status;
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

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public function _after_save() {
	global $db;
 echo '<br/> entered PO number is '. $this->om_so_number;
	if ((!empty($this->om_so_header_id)) && empty($this->om_so_number)) {
	 $om_so_header_id = $this->om_so_header_id;
	 $bu_org_id = $this->bu_org_id;
	 $om_so_number = $bu_org_id . '-' . $om_so_header_id;
	 echo '<br/> New PO number is '. $om_so_number;
	 $this->msg = $this->update_om_soNumber($om_so_header_id, $om_so_number);
	}

	return $this->msg;
 }

 private function update_om_soNumber($om_so_header_id, $om_so_number) {
	global $db;

	$sql = " UPDATE " . self::$table_name;
	$sql .= " SET om_so_number = '{$om_so_number}'  ";
	$sql .= " WHERE om_so_header_id = $om_so_header_id  ";
	
//	    echo "<br/>$sql is <br/>" . $sql;
	if ($db->query($sql)) {
	 $this->msg = 1;
	 $this->om_so_number = $om_so_number;
	} else {
	 $this->msg = 0;
	}

	return $this->msg;
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

 Public static function om_so_types() {
	$option_header = option_header::find_by_name('PO_TYPE');
	$om_so_types = option_line::find_by_option_id($option_header->option_header_id);
	return $om_so_types;
 }

 Public static function om_so_status() {
	$option_header = option_header::find_by_name('PO_STATUS');
	$om_so_status = option_line::find_by_option_id($option_header->option_header_id);
	return $om_so_status;
 }

 public function copy($om_so_header_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM om_so_header WHERE `om_so_header_id` = '{$om_so_header_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `om_so_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `om_so_header_id` = '{$om_so_header_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `om_so_header` SELECT * FROM tmptable WHERE `om_so_header_id` = '' ";
		if ($db->query($sql3)) {
		 $this->om_so_header_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

 public function save() {
	$primary_column = static::$primary_column;
	if (empty($this->$primary_column)) {
	 $this->om_so_status = 'Entered';
	 $this->create();
	} else {
	 $this->update($this->$primary_column);
	}
	return $this->msg;
 }

 
 
//  private  function create_all_om_so_v(){
//  $sql="
//CREATE OR REPLACE VIEW all_om_so_v
//(
//om_so_header_id, bu_org_id, om_so_type, om_so_number, supplier_id, supplier_site_id, buyer, currency, header_amount, om_so_status,
//payment_term_id,
//supplier_name, supplier_number,
//supplier_site_name, supplier_site_number,
//payment_term, payment_term_description,
//om_so_line_id, line_type, line_number,	item_id, item_description, line_description, line_quantity, unit_price, line_price,
//item_number, uom_id, item_status,
//om_so_detail_id, shipment_number, ship_to_id, sub_inventory_id, locator_id, requestor, quantity,
//need_by_date, promise_date,
//om_so_received_quantity, om_so_accepted_quantity, om_so_delivered_quantity, om_so_invoiced_quantity, om_so_paid_quantity,
//ship_to_org
//)
//AS
//SELECT 
//om_so_header.om_so_header_id, om_so_header.bu_org_id, om_so_header.om_so_type, om_so_header.om_so_number, om_so_header.supplier_id, 
//om_so_header.supplier_site_id, om_so_header.buyer, om_so_header.currency, om_so_header.header_amount, om_so_header.om_so_status,
//om_so_header.payment_term_id,
//supplier.supplier_name, supplier.supplier_number,
//supplier_site.supplier_site_name, supplier_site.supplier_site_number,
//payment_term.payment_term, payment_term.description,
//om_so_line.om_so_line_id, om_so_line.line_type, om_so_line.line_number,	om_so_line.item_id, om_so_line.item_description, om_so_line.line_description, 
//om_so_line.line_quantity, om_so_line.unit_price, om_so_line.line_price,
//item.item_number, item.uom_id, item.item_status,
//om_so_detail.om_so_detail_id, om_so_detail.shipment_number, om_so_detail.ship_to_inventory, om_so_detail.sub_inventory_id, 
//om_so_detail.locator_id, om_so_detail.requestor, om_so_detail.quantity, om_so_detail.need_by_date, om_so_detail.promise_date,
//om_so_detail.received_quantity, om_so_detail.accepted_quantity, om_so_detail.delivered_quantity, 
//om_so_detail.invoiced_quantity, om_so_detail.paid_quantity,
//org.org
//
//FROM om_so_header 
//LEFT JOIN supplier ON om_so_header.supplier_id = supplier.supplier_id
//LEFT JOIN supplier_site ON om_so_header.supplier_site_id = supplier_site.supplier_site_id
//LEFT JOIN payment_term ON om_so_header.payment_term_id = payment_term.payment_term_id
//LEFT JOIN om_so_line ON om_so_header.om_so_header_id = om_so_line.om_so_header_id
//LEFT JOIN item ON om_so_line.item_id = item.item_id
//LEFT JOIN om_so_detail ON om_so_line.om_so_line_id = om_so_detail.om_so_line_id
//LEFT JOIN org ON om_so_detail.ship_to_inventory = org.org_id
//
//";
// }
 
}



//end of om_so_header class
?>



