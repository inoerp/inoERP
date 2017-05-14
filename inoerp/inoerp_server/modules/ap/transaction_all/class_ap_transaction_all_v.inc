<?php

class ap_transaction_all_v extends dbObject {

 public static $form_class_name = "ap_transaction_header";
 public static $table_name = "ap_transaction_all_v";
 public static $primary_column = "ap_transaction_header_id";
 public $field_a = [
  'ap_transaction_header_id',
  'bu_org_id',
  'transaction_type',
  'transaction_number',
  'supplier_id',
  'supplier_site_id',
  'hr_employee_id',
  'currency',
  'header_amount',
  'transaction_status',
  'payment_term_id',
  'paid_amount',
  'payment_status',
  'supplier_name',
  'supplier_number',
  'supplier_site_name',
  'supplier_site_number',
  'po_number',
  'po_type',
  'buyer',
  'payment_term',
  'payment_term_description',
  'ap_transaction_line_id',
  'line_type',
  'line_number',
  'item_id_m',
  'item_description',
  'line_description',
  'inv_line_quantity',
  'inv_unit_price',
  'inv_line_price',
  'po_header_id',
  'po_line_id',
  'po_detail_id',
  'ref_transaction_header_id',
  'ref_transaction_line_id',
  'item_number',
  'uom_id',
  'item_status',
  'ap_transaction_detail_id',
  'account_type',
  'detail_description',
  'amount',
  'detail_ac_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'transaction_number',
  'supplier_id',
  'supplier_name',
  'supplier_site_name',
  'po_number',
  'supplier_site_id',
 ];
 public $dateField = [
  'need_by_date',
  'promise_date'
 ];
 public static $json_label_fields = [
  'ap_transaction_header_id',
  'transaction_type',
  'transaction_number',
  'line_number',
  'header_amount',
  'supplier_name',
  'supplier_number',
  'supplier_site_name',
  'item_description',
  'inv_line_quantity',
  'item_number',
  'account_type'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=ap_transaction_header',
  '_show_update_path' => 1,
  '_view_path' => 'form.php?class_name=ap_transaction_header',
  '_show_view_path' => 1,
 ];
 
   public $search_functions = [
  'Organization' => 'search_bu_name',
 ];
	
	 
 public $pageTitle = " AP Transaction View "; //page Title
 public $ap_transaction_header_id;
 public $bu_org_id;
 public $transaction_type;
 public $transaction_number;
 public $supplier_id;
 public $supplier_site_id;
 public $hr_employee_id;
 public $currency;
 public $header_amount;
 public $paid_amount;
 public $payment_status;
 public $transaction_status;
 public $payment_term_id;
 public $supplier_name;
 public $supplier_number;
 public $po_number;
 public $po_type;
 public $buyer;
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
 public $inv_line_quantity;
 public $inv_unit_price;
 public $inv_line_price;
 public $po_header_id;
 public $po_line_id;
 public $po_detail_id;
 public $ref_transaction_header_id;
 public $ref_transaction_line_id;
 public $item_number;
 public $uom_id;
 public $item_status;
 public $ap_transaction_detail_id;
 public $account_type;
 public $detail_description;
 public $amount;
 public $detail_ac_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 private function create_ap_transaction_all_v() {
  $sql = "
CREATE OR REPLACE VIEW ap_transaction_all_v
(
ap_transaction_header_id, bu_org_id, transaction_type, transaction_number, supplier_id, supplier_site_id, hr_employee_id, currency, 
header_amount, transaction_status, payment_term_id, paid_amount, payment_status,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
po_number,po_type, buyer,
payment_term, payment_term_description,
ap_transaction_line_id, line_type, line_number,	item_id_m, item_description, line_description, inv_line_quantity, inv_unit_price, inv_line_price,
po_header_id, po_line_id, po_detail_id, ref_transaction_header_id, ref_transaction_line_id,
item_number, uom_id, item_status,
ap_transaction_detail_id,  account_type, detail_description, amount, detail_ac_id, created_by, 
creation_date, last_update_by, last_update_date
)
AS
SELECT 
ap_transaction_header.ap_transaction_header_id, ap_transaction_header.bu_org_id, ap_transaction_header.transaction_type, ap_transaction_header.transaction_number,
ap_transaction_header.supplier_id, 
ap_transaction_header.supplier_site_id, ap_transaction_header.hr_employee_id, ap_transaction_header.currency, ap_transaction_header.header_amount, ap_transaction_header.transaction_status,
ap_transaction_header.payment_term_id, ap_transaction_header.paid_amount, ap_transaction_header.payment_status,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
ph.po_number,ph.po_type, ph.buyer,
payment_term.payment_term, payment_term.description,
ap_transaction_line.ap_transaction_line_id, ap_transaction_line.line_type, ap_transaction_line.line_number,	ap_transaction_line.item_id_m, ap_transaction_line.item_description, ap_transaction_line.line_description, 
ap_transaction_line.inv_line_quantity, ap_transaction_line.inv_unit_price, ap_transaction_line.inv_line_price,
ap_transaction_line.po_header_id,    ap_transaction_line.po_line_id,    ap_transaction_line.po_detail_id,
ap_transaction_line.ref_transaction_header_id,    ap_transaction_line.ref_transaction_line_id,
item.item_number, item.uom_id, item.item_status,
ap_transaction_detail.ap_transaction_detail_id, ap_transaction_detail.account_type, ap_transaction_detail.description, 
ap_transaction_detail.amount, ap_transaction_detail.detail_ac_id, 
ap_transaction_header.created_by, ap_transaction_header.creation_date, ap_transaction_header.last_update_by, ap_transaction_header.last_update_date

FROM ap_transaction_header 
LEFT JOIN supplier ON ap_transaction_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON ap_transaction_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON ap_transaction_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN ap_transaction_line ON ap_transaction_header.ap_transaction_header_id = ap_transaction_line.ap_transaction_header_id
LEFT JOIN item ON ap_transaction_line.item_id_m = item.item_id_m and item.item_id_m = item.item_id
LEFT JOIN ap_transaction_detail ON ap_transaction_line.ap_transaction_line_id = ap_transaction_detail.ap_transaction_line_id
LEFT JOIN po_header ph ON ph.po_header_id = ap_transaction_line.po_header_id


";
 }

}

//end of ap_transaction_detail class
?>