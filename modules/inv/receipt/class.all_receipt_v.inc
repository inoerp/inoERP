<?php

class all_receipt_v extends receipt_line {

 protected static $table_name = "all_receipt_v";
 public static $account_array = [
 ];
 public static $checkbox_array = [
 ];
 public static $field_array = [
		 "po_header_id",
		 "po_number",
		 "po_status",
		 "supplier_id",
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 "item_number",
		 "item_id",
		 "ship_to_id",
		 "ship_to_org",
		 "need_by_date",
		 "promise_date",
		 "creation_date",
		 "buyer"
 ];
 public static $initial_search_array = [
		 "po_header_id",
		 "po_number",
		 "po_status",
		 "supplier_id",
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 "item_number",
		 "item_id",
		 "ship_to_id",
		 "ship_to_org",
		 "need_by_date",
		 "buyer"
 ];
 public static $column_array = [
		 "po_number",
		 "line_number",
		 "shipment_number",
		 "po_status",
		 "ship_to_org",
		 "supplier_name",
		 "supplier_site_name",
		 "item_number",
		 "need_by_date"
 ];
 public static $requiredField_array = [
 ];
 public static $addressField_array = [
 ];
 public static $dateField_array = [
		 'need_by_date',
		 'promise_date'
 ];
 public static $fields_inForm_notInDataBase = [
 ];
 public static $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public static $otherField_array = [
 ];
 public static $primary_column = "receipt_line_id";
 
 public $carrier;
public $vechile_number;
public $receipt_line_id;
public $receipt_header_id;
public $subinventory_id;
public $locator_id;
public $received_quantity;
public $receving_account_id;
public $accrual_account_id;
public $country_of_origin;
public $lot_number;
public $serial_number;
public $po_header_id;
public $bu_org_id;
public $po_type;
public $po_number;
public $supplier_id;
public $supplier_site_id;
public $buyer;
public $currency;
public $header_amount;
public $po_status;
public $payment_term_id;
public $supplier_name;
public $supplier_number;
public $supplier_site_name;
public $supplier_site_number;
public $payment_term;
public $payment_term_description;
public $po_line_id;
public $line_type;
public $line_number;
public $item_description;
public $line_description;
public $item_id;
public $line_quantity;
public $unit_price;
public $line_price;
public $uom_id;
public $item_number;
public $item_status;
public $po_detail_id;
public $shipment_number;
public $ship_to_id;
public $sub_inventory_id;
public $requestor;
public $quantity;
public $need_by_date;
public $promise_date;
public $po_received_quantity;
public $po_accepted_quantity;
public $po_delivered_quantity;
public $po_invoiced_quantity;
public $po_paid_quantity;
public $ship_to_org ;


 public function __set($name, $value) {
	$this->$name = $value;
 }
 
  public static function find_all_by_receiptHeaderId($receipt_headerId) {

	$sql = " Select * from ";
	$sql .= self::$table_name;
	$sql .= " WHERE receipt_header_id = '{$receipt_headerId}'";

	$all_receipt_lines = self::find_by_sql($sql);

	return $all_receipt_lines;
 }
 
 private  function create_all_receipt_v(){
  $sql="
CREATE OR REPLACE VIEW all_receipt_v
(
receipt_number, carrier, vechile_number,
receipt_line_id, receipt_header_id, subinventory_id, locator_id, received_quantity,
receving_account_id, accrual_account_id, country_of_origin, lot_number, serial_number,
po_header_id, bu_org_id, po_type, po_number, supplier_id, 
supplier_site_id, buyer, currency,
header_amount, po_status, payment_term_id,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
payment_term, payment_term_description,
po_line_id, line_type, line_number,	item_id, item_description, line_description, 
line_quantity, unit_price, line_price, uom_id,
item_number, item_status,
po_detail_id, shipment_number, ship_to_id, sub_inventory_id, requestor, quantity,
need_by_date, promise_date,
po_received_quantity, po_accepted_quantity, po_delivered_quantity, po_invoiced_quantity, po_paid_quantity,
ship_to_org
)
AS
SELECT 
receipt_header.receipt_number, receipt_header.carrier, receipt_header.vechile_number,
receipt_line.receipt_line_id, receipt_line.receipt_header_id, receipt_line.subinventory_id, receipt_line.locator_id, 
receipt_line.received_quantity, receipt_line.receving_account_id, receipt_line.accrual_account_id, 
receipt_line.country_of_origin, receipt_line.lot_number, receipt_line.serial_number,
po_header.po_header_id, po_header.bu_org_id, po_header.po_type, po_header.po_number, po_header.supplier_id, 
po_header.supplier_site_id, po_header.buyer, po_header.currency, po_header.header_amount, 
po_header.po_status, po_header.payment_term_id,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
payment_term.payment_term, payment_term.description,
po_line.po_line_id, po_line.line_type, po_line.line_number,	po_line.item_id, po_line.item_description, po_line.line_description, 
po_line.line_quantity, po_line.unit_price, po_line.line_price,po_line.line_uom,
item.item_number, item.item_status,
po_detail.po_detail_id, po_detail.shipment_number, po_detail.ship_to_inventory, po_detail.sub_inventory_id, 
po_detail.requestor, po_detail.quantity, po_detail.need_by_date, po_detail.promise_date,
po_detail.received_quantity, po_detail.accepted_quantity, po_detail.delivered_quantity, 
po_detail.invoiced_quantity, po_detail.paid_quantity,
org.org

FROM receipt_header
LEFT JOIN receipt_line ON receipt_header.receipt_header_id = receipt_line.receipt_header_id
LEFT JOIN po_detail ON receipt_line.po_detail_id = po_detail.po_detail_id
LEFT JOIN po_line ON po_detail.po_line_id = po_line.po_line_id
LEFT JOIN po_header ON po_line.po_header_id = po_header.po_header_id
LEFT JOIN supplier ON po_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON po_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON po_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN item ON po_line.item_id = item.item_id
LEFT JOIN org ON po_detail.ship_to_inventory = org.org_id

";
 }

}
?>