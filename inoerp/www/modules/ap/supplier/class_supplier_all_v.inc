<?php

class supplier_all_v extends dbObject {

 public static $form_class_name = "supplier";
 public static $table_name = "supplier_all_v";
 public static $primary_column = "supplier_id";
 public $field_a = [
  'supplier_id',
  'supplier_site_id',
  'supplier_type',
  'ar_customer_id',
  'creation_date',
  'supplier_bu_id',
  'payable_account_id',
  'site_tax_country',
  'currency',
  'supplier_number',
  'supplier_site_number',
  'tax_country',
  'status',
  'last_update_by',
  'org_id',
  'payment_discount_account_id',
  'site_tax_reg_no',
  'payment_term_id',
  'supplier_name ',
  'supplier_site_name',
  'created_by',
  'last_update_date',
  'liability_account_id',
  'pre_payment_account_id',
  'site_status'
 ];
 public $initial_search = [
  "supplier_id",
  "supplier_number",
  "supplier_name",
  "supplier_site_id",
  "supplier_site_number",
  "supplier_site_name",
  "customer_id",
  "status"
 ];
 public $column = [
  "supplier_id",
  "supplier_number",
  "supplier_name",
  "supplier_site_id",
  "supplier_site_number",
  "supplier_site_name",
  "ar_customer_id",
  "status"
 ];
 public $dateField = [
  'need_by_date',
  'promise_date'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=supplier',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_view_path' => 'form.php?class_name=supplier',
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " Supplier - Find All Supplierss "; //page Title
 public $option_lists = [
  'supplier_type' => 'SUPPLIER_TYPE'
 ];
 public $supplier_id;
//  public $bu_org_id;
 public $po_type;
 public $po_number;
 public $supplier_site_id;
 public $ar_customer_id;
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

 private function create_supplier_all_v() {
  $sql = "
CREATE OR REPLACE VIEW supplier_all_v
(
supplier_id,supplier_number, supplier_name ,
supplier_site_id, supplier_site_number, supplier_site_name,
 supplier_type, tax_country, created_by,
ar_customer_id, status,
creation_date, last_update_by, last_update_date,
 supplier_bu_id, org_id, liability_account_id,
payable_account_id, payment_discount_account_id, pre_payment_account_id,
site_tax_country, site_tax_reg_no, site_status,
currency, payment_term_id)
AS
SELECT 
su.supplier_id,su.supplier_number, su.supplier_name ,
ss.supplier_site_id, ss.supplier_site_number, ss.supplier_site_name,
 su.supplier_type, su.tax_country, su.created_by,
su.ar_customer_id, su.status,
su.creation_date, su.last_update_by, su.last_update_date,
 sb.supplier_bu_id, sb.org_id, liability_account_id,
payable_account_id, payment_discount_account_id, pre_payment_account_id,
ss.site_tax_country, ss.site_tax_reg_no, ss.status,
ss.currency, ss.payment_term_id

FROM supplier su
LEFT JOIN supplier_site ss ON ss.supplier_id = su.supplier_id
LEFT JOIN supplier_bu sb ON su.supplier_id = sb.supplier_id

";
 }

 public static function find_by_supplier_siteId($supplier_site_id) {
  $sql = " SELECT * FROM " . self::$table_name . " WHERE supplier_site_id = '{$supplier_site_id}' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : null;
 }

}

//end of po_detail class
?>