<?php

class po_requisition_all_v extends dbObject {

 public static $form_class_name = "po_requisition_header";
 public static $table_name = "po_requisition_all_v";
 public static $primary_column = "po_requisition_header_id";
 public $field_a = [
		 'po_requisition_header_id',
		 'bu_org_id',
		 'po_requisition_type',
		 'po_requisition_number',
		 'supplier_id',
		 'supplier_site_id',
		 'buyer',
		 'currency',
		 'header_amount',
		 'requisition_status',
		 'payment_term_id',
		 'supplier_name',
		 'supplier_number',
		 'supplier_site_name',
		 'supplier_site_number',
		 'payment_term',
		 'payment_term_description',
		 'po_requisition_line_id',
		 'line_type',
		 'po_requisition_line_number',
		 'item_id_m',
		 'item_description',
		 'line_description',
		 'line_quantity',
		 'unit_price',
		 'line_price',
		 'item_number',
		 'uom_id',
		 'item_status',
		 'po_requisition_detail_id',
		 'order_number',
		 'shipment_number',
		 'ship_to_inventory',
		 'sub_inventory_id',
		 'locator_id',
		 'requestor',
		 'quantity',
		 'need_by_date',
		 'promise_date',
		 'received_quantity',
		 'accepted_quantity',
		 'delivered_quantity',
		 'invoiced_quantity',
		 'paid_quantity',
		 'ship_to_org',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
 'po_requisition_header_id',
		 'po_requisition_number',
		 'buyer',
		 'requisition_status',
		 'supplier_name',
		 'supplier_number',
		 'supplier_site_name',
		 'supplier_site_number',
		 'item_number',
		 'requestor',
		  ];
 public $column = [
		 'po_requisition_header_id',
		 'bu_org_id',
		 'po_requisition_type',
		 'po_requisition_number',
		 'supplier_id',
		 'supplier_site_id',
		 'buyer',
		 'currency',
		 'header_amount',
		 'requisition_status',
		 'payment_term_id',
		 'supplier_name',
		 'supplier_number',
		 'supplier_site_name',
		 'supplier_site_number',
		 'payment_term',
		 'payment_term_description',
		 'po_requisition_line_id',
		 'line_type',
		 'po_requisition_line_number',
		 'item_id_m',
		 'item_description',
		 'line_description',
		 'line_quantity',
		 'unit_price',
		 'line_price',
		 'item_number',
		 'uom_id',
		 'item_status',
		 'po_requisition_detail_id',
		 'order_number',
		 'shipment_number',
		 'ship_to_inventory',
		 'sub_inventory_id',
		 'locator_id',
		 'requestor',
		 'quantity',
		 'need_by_date',
		 'promise_date',
		 'received_quantity',
		 'accepted_quantity',
		 'delivered_quantity',
		 'invoiced_quantity',
		 'paid_quantity',
		 'ship_to_org',
 ];
 public $dateField = [
		 'need_by_date',
		 'promise_date'
 ];
 public $search = [
		 '_update_path' => 'form.php?class_name=po_requisition_header',
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_view_path' => 'form.php?class_name=po_requisition_header',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
		 '_extra_path' => array('form.php?class_name=po_header&mode=9' => 'Convert')
 ];
 public $pageTitle = " Requistion - Find All Requisitions "; //page Title
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
 public $currency;
 public $header_amount;
 public $requisition_status;
 public $payment_term_id;
 public $supplier_name;
 public $supplier_number;
 public $supplier_site_name;
 public $supplier_site_number;
 public $payment_term;
 public $payment_term_description;
 public $po_requisition_line_id;
 public $line_type;
 public $po_requisition_line_number;
 public $item_id_m;
 public $item_description;
 public $line_description;
 public $line_quantity;
 public $unit_price;
 public $line_price;
 public $item_number;
 public $uom_id;
 public $item_status;
 public $po_requisition_detail_id;
 public $shipment_number;
 public $ship_to_inventory;
 public $subinventory_id;
 public $locator_id;
 public $requestor;
 public $quantity;
 public $po_requisition_received_quantity;
 public $need_by_date;
 public $promise_date;
 public $ship_to_org;
 //extra fields
 public $receipt_line_id;
 public $received_quantity;
 public $order_number;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 private function create_po_requisition_all_v() {
	$sql = "
CREATE OR REPLACE VIEW po_requisition_all_v
(
po_requisition_header_id, bu_org_id, po_requisition_type, po_requisition_number, supplier_id, supplier_site_id, buyer, currency, header_amount, requisition_status,
payment_term_id,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
payment_term, payment_term_description,
po_requisition_line_id, line_type, po_requisition_line_number,	item_id_m, item_description, line_description, line_quantity, unit_price, line_price,
item_number, uom_id, item_status,
po_requisition_detail_id, shipment_number, ship_to_inventory, subinventory_id, locator_id, requestor, quantity,
need_by_date, promise_date,
received_quantity, accepted_quantity, delivered_quantity, invoiced_quantity, paid_quantity,	order_number,
ship_to_org, created_by, creation_date, last_update_by, last_update_date
)
AS
SELECT 
po_requisition_header.po_requisition_header_id, po_requisition_header.bu_org_id, po_requisition_header.po_requisition_type, po_requisition_header.po_requisition_number, po_requisition_header.supplier_id, 
po_requisition_header.supplier_site_id, po_requisition_header.buyer, po_requisition_header.currency, po_requisition_header.header_amount, po_requisition_header.requisition_status,
po_requisition_header.payment_term_id,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
payment_term.payment_term, payment_term.description,
po_requisition_line.po_requisition_line_id, po_requisition_line.line_type, po_requisition_line.line_number,	po_requisition_line.item_id_m, po_requisition_line.item_description, po_requisition_line.line_description, 
po_requisition_line.line_quantity, po_requisition_line.unit_price, po_requisition_line.line_price,
item.item_number, item.uom_id, item.item_status,
po_requisition_detail.po_requisition_detail_id, po_requisition_detail.shipment_number, po_requisition_detail.ship_to_inventory, po_requisition_detail.subinventory_id, 
po_requisition_detail.locator_id, po_requisition_detail.requestor, po_requisition_detail.quantity, po_requisition_detail.need_by_date, po_requisition_detail.promise_date,
po_requisition_detail.received_quantity, po_requisition_detail.accepted_quantity, po_requisition_detail.delivered_quantity, 
po_requisition_detail.invoiced_quantity, po_requisition_detail.paid_quantity,	po_requisition_detail.order_number,
org.org,
po_requisition_header.created_by, po_requisition_header.creation_date, po_requisition_header.last_update_by, po_requisition_header.last_update_date

FROM po_requisition_header 
LEFT JOIN supplier ON po_requisition_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON po_requisition_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON po_requisition_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN po_requisition_line ON po_requisition_header.po_requisition_header_id = po_requisition_line.po_requisition_header_id
LEFT JOIN item ON po_requisition_line.item_id_m = item.item_id_m AND  item.org_id = po_requisition_line.receving_org_id
LEFT JOIN po_requisition_detail ON po_requisition_line.po_requisition_line_id = po_requisition_detail.po_requisition_line_id
LEFT JOIN org ON po_requisition_detail.ship_to_inventory = org.org_id

";
 }

 public function findBy_po_requisitionDetailId() {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE po_requisition_detail_id = :po_requisition_detail_id ";
	$sql = ino_perPageSql_i($sql, 1);

	$param_a = ['po_requisition_detail_id'];
	$value_a = ['po_requisition_detail_id' => $this->po_requisition_detail_id];
	$result = $this->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? array_po_requisitionp($result) : false;
 }

}

//end of po_requisition_detail class
?>