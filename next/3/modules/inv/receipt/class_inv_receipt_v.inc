<?php

class inv_receipt_v extends dbObject {

 public static $table_name = "inv_receipt_v";
 public static $primary_column = "ap_transaction_header_id";
 public $field_a = [
		 "ap_transaction_header_id",
		 "po_number",
		 "po_status",
		 "supplier_id",
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 "item_number",
		 "item_id_m",
		 "ship_to_id",
		 "ship_to_org",
		 "need_by_date",
		 "promise_date",
		 "creation_date",
		 "buyer"
 ];
 public $initial_search = [
		 "ap_transaction_header_id",
		 "po_number",
		 "supplier_id",
		 "supplier_name",
		 "supplier_number",
		 "supplier_site_name",
		 "item_number",
		 "item_id_m",
		 "ship_to_id",
		 "ship_to_org",
		 "need_by_date",
		 "buyer"
 ];
 public $column = [
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
 public $dateField = [
		 'need_by_date',
		 'promise_date'
 ];
 public $search = [
		 '_update_path' => 'form.php?class_name=ap_transaction_header',
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_view_path' => 'form.php?class_name=ap_transaction_header',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " PO - Find All Purchase Order Headers "; //page Title
 public $option_lists = [
		 'po_type' => 'PO_TYPE',
		 'po_status' => 'PO_STATUS',
 ];
 public $ap_transaction_header_id;
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
 public $ap_transaction_line_id;
 public $line_type;
 public $line_number;
 public $item_id_m;
 public $item_description;
 public $line_description;
 public $line_quantity;
 public $unit_price;
 public $line_price;
 public $item_number;
 public $uom_id;
 public $item_status;
 public $ap_transaction_detail_id;
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

 private function create_ap_transaction_all_v() {
	$sql = "
CREATE OR REPLACE VIEW ap_transaction_all_v
(
ap_transaction_header_id, bu_org_id, po_type, po_number, supplier_id, supplier_site_id, buyer, currency, header_amount, po_status,
payment_term_id,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
payment_term, payment_term_description,
ap_transaction_line_id, line_type, line_number,	item_id_m, item_description, line_description, line_quantity, unit_price, line_price,
item_number, uom_id, item_status,
ap_transaction_detail_id, shipment_number, ship_to_id, sub_inventory_id, locator_id, requestor, quantity,
need_by_date, promise_date,
po_received_quantity, po_accepted_quantity, po_delivered_quantity, po_invoiced_quantity, po_paid_quantity,
ship_to_org, created_by, creation_date, last_update_by, last_update_date
)
AS
SELECT 
ap_transaction_header.ap_transaction_header_id, ap_transaction_header.bu_org_id, ap_transaction_header.po_type, ap_transaction_header.po_number, ap_transaction_header.supplier_id, 
ap_transaction_header.supplier_site_id, ap_transaction_header.buyer, ap_transaction_header.currency, ap_transaction_header.header_amount, ap_transaction_header.po_status,
ap_transaction_header.payment_term_id,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
payment_term.payment_term, payment_term.description,
ap_transaction_line.ap_transaction_line_id, ap_transaction_line.line_type, ap_transaction_line.line_number,	ap_transaction_line.item_id_m, ap_transaction_line.item_description, ap_transaction_line.line_description, 
ap_transaction_line.line_quantity, ap_transaction_line.unit_price, ap_transaction_line.line_price,
item.item_number, item.uom_id, item.item_status,
ap_transaction_detail.ap_transaction_detail_id, ap_transaction_detail.shipment_number, ap_transaction_detail.ship_to_inventory, ap_transaction_detail.sub_inventory_id, 
ap_transaction_detail.locator_id, ap_transaction_detail.requestor, ap_transaction_detail.quantity, ap_transaction_detail.need_by_date, ap_transaction_detail.promise_date,
ap_transaction_detail.received_quantity, ap_transaction_detail.accepted_quantity, ap_transaction_detail.delivered_quantity, 
ap_transaction_detail.invoiced_quantity, ap_transaction_detail.paid_quantity,
org.org,
ap_transaction_header.created_by, ap_transaction_header.creation_date, ap_transaction_header.last_update_by, ap_transaction_header.last_update_date

FROM ap_transaction_header 
LEFT JOIN supplier ON ap_transaction_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON ap_transaction_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON ap_transaction_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN ap_transaction_line ON ap_transaction_header.ap_transaction_header_id = ap_transaction_line.ap_transaction_header_id
LEFT JOIN item ON ap_transaction_line.item_id_m = item.item_id_m
LEFT JOIN ap_transaction_detail ON ap_transaction_line.ap_transaction_line_id = ap_transaction_detail.ap_transaction_line_id
LEFT JOIN org ON ap_transaction_detail.ship_to_inventory = org.org_id

";
 }

}

//end of ap_transaction_detail class
?>