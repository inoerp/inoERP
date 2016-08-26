<?php

class ap_po_matching_v extends dbObject {

 public static $table_name = "ap_po_matching_v";
 public static $primary_column = "po_header_id";
 public $field_a = [
  'po_header_id',
  'bu_org_id',
  'po_type',
  'po_number',
  'supplier_id',
  'supplier_site_id',
  'buyer',
  'currency',
  'header_amount',
  'po_status',
  'payment_term_id',
  'supplier_name',
  'supplier_number',
  'supplier_site_name',
  'supplier_site_number',
  'payment_term',
  'payment_term_description',
  'po_line_id',
  'line_type',
  'po_line_number',
  'item_id_m',
  'item_description',
  'line_description',
  'line_quantity',
  'unit_price',
  'line_price',
  'gl_line_price',
  'tax_amount',
  'gl_tax_amount',
  'item_number',
  'uom_id',
  'item_status',
  'po_detail_id',
  'shipment_number',
  'receving_org_id',
  'subinventory_id',
  'locator_id',
  'requestor',
  'quantity',
  'received_quantity',
  'receiving_open_quantity',
  'need_by_date',
  'promise_date',
  'accepted_quantity',
  'delivered_quantity',
  'invoiced_quantity',
  'paid_quantity',
  'invoicing_open_quantity',
  'charge_ac_id',
  'accrual_ac_id',
  'budget_ac_id',
  'ppv_ac_id',
  'receving_org',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  "po_number",
  'po_type',
  "supplier_number",
  "receving_org_id",
  "item_number",
  'po_status',
  'supplier_site_id'
 ];
 public $multi_select_column = [
  'unit_price',
  'line_quantity',
  'po_number',
  'po_line_number',
  'shipment_number',
  'quantity',
  'received_quantity',
  'invoicing_open_quantity',
  'accepted_quantity',
  'delivered_quantity',
  'invoiced_quantity',
  'paid_quantity',
  'line_price',
  'gl_line_price',
  'tax_amount',
  'gl_tax_amount',
  'supplier_id',
  'supplier_site_id',
  'supplier_name',
  'supplier_number',
  'supplier_site_name',
  'supplier_site_number',
  'item_number',
  'item_description',
  'item_id_m',
  'uom_id',
  'po_header_id',
  'po_line_id',
  'po_detail_id',
  'po_status',
  'currency',
  'doc_currency'
 ];
 public $dateField = [
  'need_by_date',
  'promise_date'
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Invoicing Matching "; //page Title
 public $option_lists = [
  'po_type' => 'PO_TYPE',
  'po_status' => 'PO_STATUS',
 ];
 public $po_header_id;
 public $bu_org_id;
 public $po_type;
 public $po_number;
 public $supplier_id;
 public $supplier_site_id;
 public $buyer;
 public $currency;
 public $doc_currency;
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
 public $po_line_number;
 public $item_id_m;
 public $item_description;
 public $line_description;
 public $line_quantity;
 public $unit_price;
 public $line_price;
 public $gl_line_price;
 public $tax_amount;
 public $gl_tax_amount;
 public $item_number;
 public $uom_id;
 public $item_status;
 public $po_detail_id;
 public $shipment_number;
 public $receving_org_id;
 public $subinventory_id;
 public $locator_id;
 public $requestor;
 public $quantity;
 public $received_quantity;
 public $receiving_open_quantity;
 public $need_by_date;
 public $promise_date;
 public $accepted_quantity;
 public $delivered_quantity;
 public $invoiced_quantity;
 public $paid_quantity;
 public $invoicing_open_quantity;
 public $charge_ac_id;
 public $accrual_ac_id;
 public $budget_ac_id;
 public $ppv_ac_id;
 public $receving_org;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 private function create_ap_po_matching_v() {
  $sql = "
CREATE OR REPLACE VIEW ap_po_matching_v
(
po_header_id, bu_org_id, po_type, po_number, supplier_id, supplier_site_id, buyer, currency, doc_currency, header_amount, po_status,
payment_term_id,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
payment_term, payment_term_description,
po_line_id, line_type, po_line_number,	item_id_m, item_description, line_description, line_quantity, unit_price,
line_price,gl_line_price,gl_tax_amount,tax_amount,
item_number, uom_id, item_status,
po_detail_id, shipment_number, receving_org_id, subinventory_id, locator_id, requestor, 
quantity,received_quantity, receiving_open_quantity,
need_by_date, promise_date,
 accepted_quantity, delivered_quantity, invoiced_quantity, paid_quantity, invoicing_open_quantity,
charge_ac_id, accrual_ac_id,budget_ac_id, ppv_ac_id,
receving_org, created_by, creation_date, last_update_by, last_update_date
)
AS
SELECT 
po_header.po_header_id, po_header.bu_org_id, po_header.po_type, po_header.po_number, po_header.supplier_id, 
po_header.supplier_site_id, po_header.buyer, po_header.currency, po_header.doc_currency, po_header.header_amount, po_header.po_status,
po_header.payment_term_id,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
payment_term.payment_term, payment_term.description,
po_line.po_line_id, po_line.line_type, po_line.line_number,	po_line.item_id_m, po_line.item_description, po_line.line_description, 
po_line.line_quantity, po_line.unit_price, po_line.line_price,po_line.gl_line_price,po_line.gl_tax_amount,po_line.tax_amount,
item.item_number, item.uom_id, item.item_status,
po_detail.po_detail_id, po_detail.shipment_number, po_line.receving_org_id, po_detail.subinventory_id, 
po_detail.locator_id, po_detail.requestor, 
po_detail.quantity, IFNULL(po_detail.received_quantity,0) as received_quantity, po_detail.quantity - IFNULL(po_detail.received_quantity,0) as receiving_open_quantity, 
po_detail.need_by_date, po_detail.promise_date,
 po_detail.accepted_quantity, po_detail.delivered_quantity, 
po_detail.invoiced_quantity, po_detail.paid_quantity,
CASE po_detail.invoice_match_type 
 WHEN 'THREE_WAY' THEN IFNULL(po_detail.received_quantity,0) - IFNULL(po_detail.invoiced_quantity,0) 
 ELSE po_detail.quantity - IFNULL(po_detail.invoiced_quantity,0) 
 END as invoicing_open_quantity,
po_detail.charge_ac_id, po_detail.accrual_ac_id,po_detail.budget_ac_id, po_detail.ppv_ac_id,
org.org,
po_header.created_by, po_header.creation_date, po_header.last_update_by, po_header.last_update_date
FROM po_header 
LEFT JOIN supplier ON po_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON po_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON po_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN po_line ON po_header.po_header_id = po_line.po_header_id
LEFT JOIN item ON po_line.item_id_m = item.item_id_m AND item.org_id = po_line.receving_org_id
LEFT JOIN org ON po_line.receving_org_id = org.org_id ,
po_detail 
WHERE po_header.po_status='APPROVED'
AND po_header.po_type IN ('BLANKET_RELEASE', 'STANDARD')
AND po_line.po_line_id = po_detail.po_line_id
AND (( IFNULL(po_detail.invoiced_quantity,0) < po_detail.quantity AND ( po_detail.invoice_match_type = 'TWO_WAY' OR ISNULL(po_detail.invoice_match_type)))
OR(( IFNULL(po_detail.invoiced_quantity,0) < IFNULL(po_detail.received_quantity,0) AND ( po_detail.invoice_match_type = 'THREE_WAY' ))
    ))
AND po_detail.po_detail_id IS NOT NULL

";
 }

 public static function find_all_by_poHeaderId($po_header_id) {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE po_header_id = '{$po_header_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_all_by_poLineId($po_line_id) {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE po_line_id = '{$po_line_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public function findBy_poDetailId() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE po_detail_id = :po_detail_id ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $param_a = ['po_detail_id'];
  $value_a = ['po_detail_id' => $this->po_detail_id];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of po_detail class
?>