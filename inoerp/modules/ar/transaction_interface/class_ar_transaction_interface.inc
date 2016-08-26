<?php

class ar_transaction_interface extends dbObject {

 public static $table_name = "ar_transaction_interface";
 public static $primary_column = "ar_transaction_interface_id";
 public static $multi_search_primary_column = "ar_transaction_header_id"; //this value is used in multi search hidden value
 public static $js_fileName = 'modules/ar/transaction/js/multi_select_ar.js';
 public static $key_column = 'item_description';
 public static $system_info = [
  'name' => 'Transaction Interface',
  'number' => '1306',
  'description' => 'AR Transaction Interface',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 6
 ];
 public $field_a = [
  'ar_transaction_interface_id',
  'ar_transaction_header_id',
  'bu_org_id',
  'transaction_type',
  'ar_customer_id',
  'ar_customer_site_id',
  'currency',
  'payment_term_id',
  'payment_term_date',
  'document_date',
  'ledger_id',
  'receivable_ac_id',
  'revenue_ac_id',
  'line_number',
  'item_id_m',
  'item_description',
  'inv_line_quantity',
  'inv_unit_price',
  'inv_line_price',
  'gl_inv_line_price',
  'gl_tax_amount',
  'tax_code_id',
  'tax_amount',
  'line_type',
  'line_description',
  'asset_cb',
  'fa_asset_category_id',
  'prj_project_header_id',
  'prj_project_line_id',
  'uom_id',
  'ef_id',
  'status',
  'line_source',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'sd_so_header_id',
  'sd_so_line_id',
  'sd_so_detail_id',
  'period_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'bu_org_id',
  'transaction_type',
  'ar_customer_id',
  'item_description',
 ];
 public $dateField = [
  'document_date'
 ];
 public $requiredField = [
  'bu_org_id',
  'transaction_type',
  'ar_customer_id',
  'ar_customer_site_id',
  'currency',
  'payment_term_id',
  'item_description',
  'inv_line_quantity',
  'inv_unit_price',
  'tax_code_id',
  'line_type',
  'uom_id'
 ];
 public $fields_inForm_notInDataBase = [
  'action',
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=ar_transaction_interface',
  '_show_update_path' => 1,
  '_view_path' => 'form.php?class_name=ar_transaction_interface',
  '_show_view_path' => 1,
  '_extra_path' => array('form.php?class_name=ar_transaction_interface' => 'Import')
 ];
 public $prg_import_ar_transaction_parameters = [
  'Business Org' => 'search_business_org',
 ];
 public $prg_import_ar_transaction_details = [
  'name' => 'Import AR Transaction ',
  'description' => 'Import AR Transactions from Interface ',
 ];
 public $pageTitle = " Import AR Transactions "; //page Title
 public $ar_transaction_interface_id;
 public $ar_transaction_header_id;
 public $bu_org_id;
 public $transaction_type;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $currency;
 public $payment_term_id;
 public $payment_term_date;
 public $document_date;
 public $ledger_id;
 public $receivable_ac_id;
 public $revenue_ac_id;
 public $line_number;
 public $item_id_m;
 public $item_description;
 public $inv_line_quantity;
 public $inv_unit_price;
 public $inv_line_price;
 public $gl_inv_line_price;
 public $tax_code_id;
 public $tax_amount;
 public $gl_tax_amount;
 public $line_type;
 public $line_description;
 public $asset_cb;
 public $fa_asset_category_id;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $uom_id;
 public $ef_id;
 public $status;
 public $line_source;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $sd_so_header_id;
 public $sd_so_line_id;
 public $sd_so_detail_id;
 public $period_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $action;
 public $action_class_name;
 public $mode;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 private $_ar_transaction_header_id;

 public function distinct_customer_sites() {
  $sql = " SELECT DISTINCT(ar_customer_site_id) FROM ";
  $sql .= self::$table_name;
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_customerSiteId_buOrgId($customer_site_id, $bu_org_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ar_customer_site_id = '{$customer_site_id}' AND bu_org_id = '{$bu_org_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? ($result) : false;
 }

 private function _create_transaction_from_post() {
  if (empty($_POST)) {
   return;
  }

//	pa($this);
//	pa($_POST);
//  pa($this->findAll());

  $create_trnx_h = $this->_create_transaction_header();
  if ($create_trnx_h < 0) {
   return;
  }
  $this->_create_transaction_line_from_post();
 }

 private function _create_transaction_header() {
  $sd_so_header_id = $this->sd_so_header_id;
  $sd_so = new sd_so_header();
  $sd_so->findBy_id($sd_so_header_id);

  $ar_th = new ar_transaction_header();
  $ar_th->bu_org_id = $this->bu_org_id;
  $ar_th->ledger_id = $this->ledger_id;
  $ledger = new gl_ledger();
  $ledger->findBy_id($ar_th->ledger_id);

  $ar_th->transaction_type = $this->transaction_type;
  $ar_th->ar_customer_id = $this->ar_customer_id;
  $ar_th->ar_customer_site_id = $this->ar_customer_site_id;
  $ar_th->ship_to_id = $sd_so->ship_to_id;
  $ar_th->bill_to_id = $sd_so->bill_to_id;
  $ar_th->doc_currency = $sd_so->doc_currency;
  $ar_th->currency = $ledger->currency_code;
  $ar_th->bill_to_id = $sd_so->bill_to_id;
  $gp = new gl_period();
  $ar_th->period_id = $gp->current_open_period($ar_th->ledger_id, 'OPEN')->gl_period_id;
  $ar_tt = new ar_transaction_type();
  $ar_tt->findBy_id($ar_th->transaction_type);
  $ar_th->receivable_ac_id = $ar_tt->receivable_ac_id;
  $ar_th->transaction_class = $ar_tt->transaction_class;
  $ar_th->payment_term_id = $sd_so->payment_term_id;
  $ar_th->payment_term_date = $sd_so->payment_term_date;
  $ar_th->document_date = current_time(1);
  $ar_th->reference_type = 'table';
  $ar_th->reference_key_name = 'sd_so_header_id';
  $ar_th->reference_key_value = $ar_th->sd_so_header_id = $sd_so_header_id;
  $ar_th->sd_so_number = $sd_so->so_number;
  $ar_th->audit_trial();
  try {
   $ar_th->save();
  } catch (Exception $e) {

   echo "<br>Failed to create the transaction header. Error @ar_transaction_interface "
   . "@@ Line" . __LINE__ . '<br>' . $e->getMessage();
   $this->rollback = true;
   return -99;
  }
  echo "<br> Transaction header is succefully created. Header Id/ Number - " . $ar_th->ar_transaction_header_id;
  $ar_th->transaction_number = $ar_th->bu_org_id . '-' . $ar_th->ar_transaction_header_id;
  $ar_th->save();
  $this->_ar_transaction_header_id = $ar_th->ar_transaction_header_id;
  return $ar_th->ar_transaction_header_id;
 }

 private function _create_transaction_line_from_post() {
  global $dbc;
  $line_number = 0;

  for ($i = 0; $i < count($_POST['item_description']); $i++) {
   $line_number ++;
   if (empty($this->_ar_transaction_header_id)) {
    return;
   }

   //update the sales order line 
   $sol = new sd_so_line();
   $sol->findBy_id($_POST['sd_so_line_id'][$i]);
   $qty_available_for_inv = $sol->shipped_quantity - $sol->invoiced_quantity;
   if ($qty_available_for_inv <= 0) {
    echo "<br> Line is not available for invoicing . Qty available for invoicing is " . $qty_available_for_inv;
    $dbc->rollback = true;
    return -99;
   }

   $ar_tl = new ar_transaction_line();
   $ar_tl->ar_transaction_line_id = null;
   $ar_tl->line_number = $line_number;
   $ar_tl->ar_transaction_header_id = $this->_ar_transaction_header_id;
   $ar_tl->item_id_m = $_POST['item_id_m'][$i];
   $ar_tl->item_description = $_POST['item_description'][$i];
   $ar_tl->inv_line_quantity = $_POST['inv_line_quantity'][$i];
   $ar_tl->inv_unit_price = $_POST['inv_unit_price'][$i];
   $ar_tl->gl_inv_line_price = $_POST['gl_inv_line_price'][$i];
   $ar_tl->inv_line_price = $_POST['inv_line_price'][$i];
   $ar_tl->tax_code_id = $_POST['tax_code_id'][$i];
   $ar_tl->revenue_ac_id = $_POST['revenue_ac_id'][$i];
   $ar_tl->tax_amount = $_POST['tax_amount'][$i];
   $ar_tl->gl_tax_amount = $_POST['gl_tax_amount'][$i];
   $ar_tl->line_type = $_POST['line_type'][$i];
   $ar_tl->uom_id = $_POST['uom_id'][$i];
   $ar_tl->sd_so_header_id = $_POST['sd_so_header_id'][$i];
   $ar_tl->reference_type = 'table';
   $ar_tl->reference_key_name = 'sd_so_line_id';
   $ar_tl->reference_key_value = $ar_tl->sd_so_line_id = $_POST['sd_so_line_id'][$i];
   $ar_tl->save();

   //update transaction header amount
   $ar_th = new ar_transaction_header();
   $ar_th->findBy_id($ar_tl->ar_transaction_header_id);
   $ar_th->header_amount += $ar_tl->inv_line_price;
   $ar_th->tax_amount += $ar_tl->tax_amount;
   $ar_th->save();

   //update so line details
   $sol->invoiced_quantity = $ar_tl->inv_line_quantity;
   $sol->ar_transaction_header_id = $ar_tl->ar_transaction_header_id;
   $sol->ar_transaction_line_id = $ar_tl->ar_transaction_line_id;
   $sol->line_status = 'CLOSED';
   $sol->save();

   //delete interface line
   $this->ar_transaction_interface_id = $_POST['ar_transaction_interface_id'][$i];
   $this->delete();

   //unset all objects
   unset($ar_tl);
   unset($sol);
   unset($this->ar_transaction_interface_id);
  }
 }

 private function _create_transaction_line_prg($all_lines, $ar_transaction_header_id) {
  $line_number = 0;
  $msg = '<br>Starting to create transaction lines..';
  foreach ($all_lines as $obj) {
   $line_number ++;

   //update the sales order line 
   $sol = new sd_so_line();
   $sol->findBy_id($obj->sd_so_line_id);
   if (in_array($sol->line_status, array('SHIPPED', 'AWAITING_INVOICING'))) {
    $msg .= "<br> Line is not available for invoicing. Line Id is " . $obj->sd_so_line_id;
    continue;
   }

   $ar_tl = new ar_transaction_line();
   $ar_tl->ar_transaction_line_id = null;
   $ar_tl->line_number = $line_number;
   $ar_tl->ar_transaction_header_id = $ar_transaction_header_id;
   $ar_tl->item_id_m = $obj->item_id_m;
   $ar_tl->item_description = $obj->item_description;
   $ar_tl->inv_line_quantity = $obj->inv_line_quantity;
   $ar_tl->inv_unit_price = $obj->inv_unit_price;
   $ar_tl->inv_line_price = $obj->inv_line_price;
   $ar_tl->gl_inv_line_price = $obj->gl_inv_line_price;
   $ar_tl->tax_code_id = $obj->tax_code_id;
   $ar_tl->revenue_ac_id = $obj->revenue_ac_id;
   $ar_tl->tax_amount = $obj->tax_amount;
   $ar_tl->gl_tax_amount = $obj->gl_tax_amount;
   $ar_tl->line_type = $obj->line_type;
   $ar_tl->uom_id = $obj->uom_id;
   $ar_tl->sd_so_header_id = $obj->sd_so_header_id;
   $ar_tl->reference_type = 'table';
   $ar_tl->reference_key_name = 'sd_so_line_id';
   $ar_tl->reference_key_value = $ar_tl->sd_so_line_id = $obj->sd_so_line_id;
   $ar_tl->save();
   $msg .= "<br> Line is Successfully Created. Line id id " . $ar_tl->ar_transaction_line_id;

   //update so line details
   $sol->invoiced_quantity = $ar_tl->inv_line_quantity;
   $sol->ar_transaction_header_id = $ar_tl->ar_transaction_header_id;
   $sol->ar_transaction_line_id = $ar_tl->ar_transaction_line_id;
   $sol->line_status = 'CLOSED';
   $sol->save();
   $msg .= "<br> SO Line is Successfullyupdated. Line id id " . $sol->sd_so_line_id;

   //delete interface line
   $this->ar_transaction_interface_id = $obj->ar_transaction_interface_id;
   $this->delete();

   //unset all objects
   unset($ar_tl);
   unset($sol);
   unset($this->ar_transaction_interface_id);
  }
  return $msg;
 }

 public function _before_save() {

  if (($this->action == 'import_ar_transaction')) {
   echo "<br> Starting to Import Transactions";
   $this->_create_transaction_from_post();
  }
  return 10;
 }

 private function create_ar_transaction_interface() {
  $sql = "
CREATE OR REPLACE VIEW ar_transaction_interface_v
(
po_requisition_header_id, bu_org_id, po_requisition_type, po_requisition_number, supplier_id, supplier_site_id, buyer, currency, header_amount, po_requisition_status,
payment_term_id,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
payment_term, payment_term_description,
po_requisition_line_id, line_type, po_requisition_line_number,	item_id_m, item_description, 
line_description, line_quantity, unit_price, line_price,  receving_org_id,
item_number, uom_id, item_status,
po_requisition_detail_id, shipment_number, sub_inventory_id, locator_id, requestor, quantity,
need_by_date, promise_date,
received_quantity, accepted_quantity, delivered_quantity, invoiced_quantity, paid_quantity,	order_number,
ship_to_org, created_by, creation_date, last_update_by, last_update_date
)
AS
SELECT 
po_requisition_header.po_requisition_header_id, po_requisition_header.bu_org_id, po_requisition_header.po_requisition_type, po_requisition_header.po_requisition_number, po_requisition_header.supplier_id, 
po_requisition_header.supplier_site_id, po_requisition_header.buyer, po_requisition_header.currency, po_requisition_header.header_amount, po_requisition_header.requisition_status,
IFNULL(po_requisition_header.payment_term_id, supplier_site.payment_term_id),
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
payment_term.payment_term, payment_term.description,
po_requisition_line.po_requisition_line_id, po_requisition_line.line_type, po_requisition_line.line_number,	po_requisition_line.item_id_m, po_requisition_line.item_description, po_requisition_line.line_description, 
po_requisition_line.line_quantity, po_requisition_line.unit_price, po_requisition_line.line_price,po_requisition_line.receving_org_id,
item.item_number, item.uom_id, item.item_status,
po_requisition_detail.po_requisition_detail_id, po_requisition_detail.shipment_number,  po_requisition_detail.sub_inventory_id, 
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
LEFT JOIN item ON po_requisition_line.item_id_m = item.item_id_m
LEFT JOIN po_requisition_detail ON po_requisition_line.po_requisition_line_id = po_requisition_detail.po_requisition_line_id
LEFT JOIN org ON po_requisition_line.receving_org_id = org.org_id
WHERE  po_requisition_header.requisition_status = 'APPROVED'
AND (po_requisition_detail.order_number IS NULL OR po_requisition_detail.order_number = '')

";
 }

 public function prg_import_ar_transaction($seralized_parameters) {
  /*
   *  1. First Import all lines with the same customer site id
   */
  
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting to Import AR Transactions....<br>';
  if (!empty($parameters['bu_org_id'][0])) {
   $bu_org_id = $parameters['bu_org_id'][0];
   $this->message .= '<br> Entered Bu org Id is : ' . $bu_org_id;
  } else {
   $this->message .= '<br> Error! : No BU org id found @ po_requisition_interface ' . __LINE__;
   return $this->message;
  }

//	1. Lines with same customer site id
  $all_customer_sites = $this->distinct_customer_sites();
  foreach ($all_customer_sites as $cst_site_id) {
   $all_lines = $this->findBy_customerSiteId_buOrgId($cst_site_id, $bu_org_id);
   if (empty($all_lines)) {
    return;
   }
   //create header on basis of first object
   $ar_ti_prg = new ar_transaction_interface();
   foreach ($all_lines[0] as $key => $value) {
    if (property_exists($ar_ti_prg, $key)) {
     $ar_ti_prg->$key = $value;
    }
   }
   $ar_ti_prg->_create_transaction_header();
   $this->message .= "<br> Transaction header is succefully created. Header Id/ Number - " . $ar_ti_prg->_ar_transaction_header_id;

   //create lines for each object
   $this->message .=$this->_create_transaction_line_prg($all_lines, $ar_ti_prg->_ar_transaction_header_id);
  }

  return $this->message;
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
  ];
  return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'action_class_name',
   'mode',
   'action',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of po_requisition_detail class
?>