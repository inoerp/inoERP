<?php

class all_bom_routing_v extends bom_routing_line {
public static $form_class_name = "bom_routing_header";
 public static $table_name = "all_bom_routing_v";
 public static $account_array = [
 ];
 public static $checkbox_array = [
 ];
 public static $field_array = [
		 "bom_routing_header_id",
		 "bom_routing_number",
		 "bom_routing_status",
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
 public static $initial_search_array = [
		 "bom_routing_header_id",
		 "bom_routing_number",
		 "bom_routing_status",
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

 public static $otherField_array = [
 ];
 public static $primary_column = "bom_routing_header_id";
 public $bom_routing_header_id;
 public $bu_org_id;
 public $bom_routing_type;
 public $bom_routing_number;
 public $supplier_id;
 public $supplier_site_id;
 public $buyer;
 public $currency;
 public $header_amount;
 public $bom_routing_status;
 public $payment_term_id;
 public $supplier_name;
 public $supplier_number;
 public $supplier_site_name;
 public $supplier_site_number;
 public $payment_term;
 public $payment_term_description;
 public $bom_routing_line_id;
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
 public $bom_routing_detail_id;
 public $shipment_number;
 public $ship_to_id;
 public $subinventory_id;
 public $locator_id;
 public $requestor;
 public $quantity;
 public $bom_routing_received_quantity;
 public $need_by_date;
 public $promise_date;
 public $ship_to_org;
 //extra fields
 public $receipt_line_id;
 public $received_quantity;


 public function __set($name, $value) {
	$this->$name = $value;
 }
 
 private  function create_all_bom_routing_v(){
  $sql="
CREATE OR REPLACE VIEW all_bom_routing_v
(
bom_routing_header_id, bu_org_id, bom_routing_type, bom_routing_number, supplier_id, supplier_site_id, buyer, currency, header_amount, bom_routing_status,
payment_term_id,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
payment_term, payment_term_description,
bom_routing_line_id, line_type, line_number,	item_id_m, item_description, line_description, 
line_quantity, unit_price, line_price, uom_id,
item_number, item_status,
bom_routing_detail_id, shipment_number, ship_to_id, sub_inventory_id, locator_id, requestor, quantity,
need_by_date, promise_date,
bom_routing_received_quantity, bom_routing_accepted_quantity, bom_routing_delivered_quantity, bom_routing_invoiced_quantity, bom_routing_paid_quantity,
ship_to_org
)
AS
SELECT 
bom_routing_header.bom_routing_header_id, bom_routing_header.bu_org_id, bom_routing_header.bom_routing_type, bom_routing_header.bom_routing_number, bom_routing_header.supplier_id, 
bom_routing_header.supplier_site_id, bom_routing_header.buyer, bom_routing_header.currency, bom_routing_header.header_amount, bom_routing_header.bom_routing_status,
bom_routing_header.payment_term_id,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
payment_term.payment_term, payment_term.description,
bom_routing_line.bom_routing_line_id, bom_routing_line.line_type, bom_routing_line.line_number,	bom_routing_line.item_id_m, bom_routing_line.item_description, bom_routing_line.line_description, 
bom_routing_line.line_quantity, bom_routing_line.unit_price, bom_routing_line.line_price,bom_routing_line.uom,
item.item_number, item.item_status,
bom_routing_detail.bom_routing_detail_id, bom_routing_detail.shipment_number, bom_routing_detail.ship_to_inventory, bom_routing_detail.sub_inventory_id, 
bom_routing_detail.locator_id, bom_routing_detail.requestor, bom_routing_detail.quantity, bom_routing_detail.need_by_date, bom_routing_detail.promise_date,
bom_routing_detail.received_quantity, bom_routing_detail.accepted_quantity, bom_routing_detail.delivered_quantity, 
bom_routing_detail.invoiced_quantity, bom_routing_detail.paid_quantity,
org.org

FROM bom_routing_header 
LEFT JOIN supplier ON bom_routing_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON bom_routing_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON bom_routing_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN bom_routing_line ON bom_routing_header.bom_routing_header_id = bom_routing_line.bom_routing_header_id
LEFT JOIN item ON bom_routing_line.item_id_m = item.item_id_m
LEFT JOIN bom_routing_detail ON bom_routing_line.bom_routing_line_id = bom_routing_detail.bom_routing_line_id
LEFT JOIN org ON bom_routing_detail.ship_to_inventory = org.org_id

";
 }

}

//end of bom_routing_detail class
?>