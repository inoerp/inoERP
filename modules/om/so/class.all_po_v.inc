<?php

class all_po_v extends po_line {

 protected static $table_name = "all_po_v";
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
 public static $primary_column = "po_header_id";
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
 public $item_id;
 public $item_description;
 public $line_description;
 public $line_quantity;
 public $unit_price;
 public $line_price;
 public $item_number;
 public $uom_id;
 public $item_status;
 public $po_detail_id;
 public $shipment_number;
 public $ship_to_id;
 public $subinventory_id;
 public $locator_id;
 public $requestor;
 public $quantity;
 public $po_received_quantity;
 public $need_by_date;
 public $promise_date;
 public $ship_to_org;
 //extra fields
 public $receipt_line_id;
 public $received_quantity;


 public function __set($name, $value) {
	$this->$name = $value;
 }
 
 private  function create_all_po_v(){
  $sql="
CREATE OR REPLACE VIEW all_po_v
(
po_header_id, bu_org_id, po_type, po_number, supplier_id, supplier_site_id, buyer, currency, header_amount, po_status,
payment_term_id,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
payment_term, payment_term_description,
po_line_id, line_type, line_number,	item_id, item_description, line_description, 
line_quantity, unit_price, line_price, uom_id,
item_number, item_status,
po_detail_id, shipment_number, ship_to_id, sub_inventory_id, locator_id, requestor, quantity,
need_by_date, promise_date,
po_received_quantity, po_accepted_quantity, po_delivered_quantity, po_invoiced_quantity, po_paid_quantity,
ship_to_org
)
AS
SELECT 
po_header.po_header_id, po_header.bu_org_id, po_header.po_type, po_header.po_number, po_header.supplier_id, 
po_header.supplier_site_id, po_header.buyer, po_header.currency, po_header.header_amount, po_header.po_status,
po_header.payment_term_id,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
payment_term.payment_term, payment_term.description,
po_line.po_line_id, po_line.line_type, po_line.line_number,	po_line.item_id, po_line.item_description, po_line.line_description, 
po_line.line_quantity, po_line.unit_price, po_line.line_price,po_line.uom,
item.item_number, item.item_status,
po_detail.po_detail_id, po_detail.shipment_number, po_detail.ship_to_inventory, po_detail.sub_inventory_id, 
po_detail.locator_id, po_detail.requestor, po_detail.quantity, po_detail.need_by_date, po_detail.promise_date,
po_detail.received_quantity, po_detail.accepted_quantity, po_detail.delivered_quantity, 
po_detail.invoiced_quantity, po_detail.paid_quantity,
org.org

FROM po_header 
LEFT JOIN supplier ON po_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON po_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON po_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN po_line ON po_header.po_header_id = po_line.po_header_id
LEFT JOIN item ON po_line.item_id = item.item_id
LEFT JOIN po_detail ON po_line.po_line_id = po_detail.po_line_id
LEFT JOIN org ON po_detail.ship_to_inventory = org.org_id

";
 }

}

//end of po_detail class
?>



