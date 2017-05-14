<?php

class inv_receipt_line extends dbObject {

 public static $table_name = "inv_receipt_line";
 public static $primary_column = "inv_receipt_line_id";
 public static $parent_primary_column = "inv_receipt_header_id";
 public static $multi_select_template_path = "modules/inv/receipt/receipt_template.php";
 public static $multi_search_primary_column = "inv_receipt_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'item_description';
 public static $module = "inv";
 public static $gl_journal_category = "INV_INVENTORY";
 public $field_a = [
  'inv_receipt_line_id',
  'line_number',
  'inv_receipt_header_id',
  'subinventory_id',
  'transaction_type_id',
  'locator_id',
  'item_id_m',
  'revision_name',
  'item_description',
  'status',
  'uom_id',
  'transaction_quantity',
  'ref_doc_type',
  'ref_doc_number',
  'po_header_id',
  'po_line_id',
  'po_detail_id',
  'sd_so_line_id',
  'sd_so_header_id',
  'po_requisition_detail_id',
  'po_requisition_line_id',
  'po_requisition_header_id',
  'inv_intorg_transfer_line_id',
  'inv_intorg_transfer_header_id',
  "receving_account_id",
  "accrual_account_id",
  'country_of_origin',
  'currency',
  'doc_currency',
  'exchange_rate_type',
  'exchange_rate',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $account = [
  "receving_account_id",
  "accrual_account_id"
 ];
 public $fields_inForm_notInDataBase = [
  'po_received_quantity',
  'po_number',
  'shipment_number',
  'item_number',
  'uom_name',
  'kit_cb',
  'supplier_id',
  'supplier_number',
  'supplier_name',
  'supplier_site_id',
  'supplier_site_number',
  'supplier_site',
  'serial_generation',
  'serial_number',
  'inv_serial_number_id',
  'lot_generation',
  'lot_number',
  'lot_number_id',
  'serial_number_id',
  "customer_name",
  "customer_number",
  "customer_site_name",
  'customer_site_number',
  'ar_customer_id',
  'ar_customer_site_id',
  'so_number',
  'so_line_number',
  'io_order_number',
  'io_line_number',
  'po_requisition_number'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "inv_receipt_header_id",
  'org_id',
  'received_quantity',
  'quantity',
 ];
 public $requiredField = [
  'inv_receipt_header_id',
  'subinventory_id',
  'item_description',
  'uom_id',
  'transaction_quantity'
 ];
 public $checkbox = [
  'kit_cb'
 ];
 public $inv_receipt_line_id;
 public $inv_receipt_header_id;
 public $subinventory_id;
 public $locator_id;
 public $item_id_m;
 public $revision_name;
 public $item_description;
 public $status;
 public $uom_id;
 public $transaction_quantity;
 public $ref_doc_type;
 public $ref_doc_number;
 public $po_header_id;
 public $po_line_id;
 public $po_detail_id;
 public $sd_so_line_id;
 public $sd_so_header_id;
 public $po_requisition_detail_id;
 public $po_requisition_line_id;
 public $po_requisition_header_id;
 public $inv_intorg_transfer_line_id;
 public $inv_intorg_transfer_header_id;
 public $receving_account_id;
 public $accrual_account_id;
 public $country_of_origin;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $org_id;
 public $po_received_quantity;
 public $transaction_type_id;
 public $po_number;
 public $line_number;
 public $currency;
 public $doc_currency;
 public $exchange_rate_type;
 public $exchange_rate;
 public $shipment_number;
 public $item_number;
 public $uom_name;
 public $kit_cb;
 public $supplier_id;
 public $supplier_number;
 public $supplier_name;
 public $supplier_site_id;
 public $supplier_site_number;
 public $supplier_site_name;
 public $po_line_number;
 public $quantity;
 public $received_quantity;
 public $lot_number;
 public $serial_number;
 public $serial_number_id;
 public $inv_serial_number_id;
 public $serial_generation;
 public $lot_generation;
 public $customer_name;
 public $customer_number;
 public $customer_site;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $customer_site_name;
 public $customer_site_number;
 public $so_number;
 public $so_line_number;
 public $io_order_number;
 public $io_line_number;
 public $po_requisition_number;
 private $_standard_cost_for_all_kit_items;
 private $_po_line_id;
 private $_gl_journal_header_id;
 private $_ppv_ac_id;

 Public static function inv_transaction_class() {
  $option_header = option_header::find_by_name('TRANSACTION_TYPE_CLASS');
  $inv_transaction_class = option_line::find_by_option_id($option_header->option_id);
  return $inv_transaction_class;
 }

 public function _after_save() {
//  pa($this);
  if (!empty($this->transaction_type_id) && ($this->transaction_type_id != '4')) {
   $this->_after_save_transactions();
  }
 }

 private function _after_save_transactions() {
  global $dbc;
  if (!empty($this->inv_receipt_line_id) && !empty($this->po_detail_id)) {
   $update_satus = 0;
   try {
    $po_d = new po_detail();
    $po_d_i = $po_d->findBy_id($this->po_detail_id);
    $this->_po_line_id = $po_d_i->po_line_id;
    $this->_ppv_ac_id = $po_d->ppv_ac_id;
//     echo "<br>Existing received qty in PO : " . $po_d_i->received_quantity . '. Qty in new receipt line : ' . $this->transaction_quantity;
    if ($this->transaction_type_id == 5) {
     $new_qty = $this->transaction_quantity + $po_d_i->received_quantity;
     $po_d->received_quantity = $new_qty;
    } else if ($this->transaction_type_id == 21) {
     $new_qty = $po_d_i->received_quantity - $this->transaction_quantity;
     $po_d->received_quantity = $new_qty;
    }
    $po_d->po_detail_id = $po_d_i->po_detail_id;
    $po_d->save();
    echo "<br>PO Received Quantity is SuccessfullyUpdated ";
    if (!empty($this->item_id_m) && empty($this->kit_cb)) {
     try {
      $this->_create_inv_transactions();
      echo "<br>INV Transaction Lines are Successfully Created ";
     } catch (Exception $e) {
      $update_satus = -99;
      $dbc->rollback = true;
      echo "<br>Creating the transaction lines failed @ inv_receipt_line after save" . $e->getMessage();
      return;
     }
    }
    if (!empty($this->kit_cb)) {
     $this->_create_receipt_forKit();
    }
   } catch (Exception $e) {
    $update_satus = -99;
    $dbc->rollback = true;
    echo "<br>PO Detail Update Failed! Receipt Line Error @ " . __LINE__ . $e->getMessage();
    return;
   }
   if ($update_satus > 0) {
    $this->status = 'Success';
   } else {
    $this->status = 'Error';
   }
   $this->save();
  } else if (!empty($this->inv_receipt_line_id) && !empty($this->inv_intorg_transfer_line_id)) {
   if (!empty($this->item_id_m)) {
    try {
     $this->_create_inv_transactions();
     $this->_after_save_interOrgReceipt();
    } catch (Exception $e) {
     echo "<br> Not able to complete inventory transaction. Error @ inv_transaction " . __LINE__ . '<br>' . $e->getMessage();
     $dbc->rollback = true;
    }
   }
  } else if (!empty($this->inv_receipt_line_id) && !empty($this->po_requisition_detail_id)) {
   if (!empty($this->item_id_m)) {
    try {
     $this->_create_inv_transactions();
     $this->_after_save_irReceipt();
    } catch (Exception $e) {
     echo "<br> Not able to complete inventory transaction. Error @ inv_receipt_line " . __LINE__ . '<br>' . $e->getMessage();
     $dbc->rollback = true;
    }
   }
  } else if (!empty($this->inv_receipt_line_id) && !empty($this->sd_so_line_id)) {
   if (!empty($this->item_id_m)) {
    $this->_create_inv_transactions();
   }
   $this->_after_save_rmaReceipt();
  }
 }

 private function _after_save_interOrgReceipt() {
  global $dbc;
  if (!empty($this->inv_intorg_transfer_line_id)) {
   $iitl = new inv_intorg_transfer_line();
   $iitl->findBy_id($this->inv_intorg_transfer_line_id);
   try {
    $iitl->status = 'RECEIVED';
    $iitl->save();
    echo "<br> Inter Org Transfer Line is Successfully updated ";
   } catch (Exception $e) {
    echo "<br> Not able to find inv_intorg_transfer_line_id. Error @ inv_transaction " . __LINE__ . '<br>' . $e->getMessage();
    $dbc->rollback = true;
    return;
   }
  } else {
   echo "<br> Not able to find inv_intorg_transfer_line_id. Error @ inv_transaction " . __LINE__;
   $dbc->rollback = true;
   return;
  }
 }

 private function _after_save_rmaReceipt() {
  global $dbc;
  if (!empty($this->sd_so_line_id)) {
   $so_line = new sd_so_line();
   $so_line->findBy_id($this->sd_so_line_id);
   $newcurrent_shped_qty = !empty($so_line->shipped_quantity) ? ($so_line->shipped_quantity + $this->quantity) : $this->quantity;
   $so_line->shipped_quantity = $newcurrent_shped_qty;
   try {
    $so_line->save();
    echo "<br> SO Line is Successfully updated ";
   } catch (Exception $e) {
    echo "<br> Not able to find sd_so_line_id. Error @ inv_transaction " . __LINE__ . '<br>' . $e->getMessage();
    $dbc->rollback = true;
    return;
   }
  } else {
   echo "<br> Not able to find sd_so_line_id. Error @ inv_transaction " . __LINE__;
   $dbc->rollback = true;
   return;
  }
 }

 private function _after_save_irReceipt() {
  global $dbc;
  if (!empty($this->po_requisition_detail_id)) {
   $req_d = new po_requisition_detail();
   $req_d->findBy_id($this->po_requisition_detail_id);

   $newcurrent_rcved_qty = !empty($req_d->received_quantity) ? ($req_d->received_quantity + $this->quantity) : $this->quantity;
   $req_d->received_quantity = $newcurrent_rcved_qty;
   if ($req_d->received_quantity >= $req_d->quantity) {
    $req_d->ir_status = 'FULL_RECEIVED';
   } else {
    $req_d->ir_status = 'PAR_RECEIVED';
   }

   try {
    $req_d->save();
    echo "<br> IR details are Successfully updated ";
   } catch (Exception $e) {
    echo "<br> Not able to find po_requisition_detail_id. Error @ inv_transaction " . __LINE__ . '<br>' . $e->getMessage();
    $dbc->rollback = true;
    return;
   }
  } else {
   echo "<br> Not able to find po_requisition_detail_id. Error @ inv_transaction " . __LINE__;
   $dbc->rollback = true;
   return;
  }
 }

 public function _before_save() {
  //if there is a line id in the form then return 10 as no changes to paid lines are allowed
  if ($this->inv_receipt_line_id) {
   echo "<br>You can't update any Receipt line. Reverse the transaction, if required ";
   return 10;
  }

  if ((empty($this->line_number)) && (!empty($this->inv_receipt_header_id))) {
   $current_highest_line_no = $this->_highest_line_number_from_header();
   $this->line_number = $current_highest_line_no->line_number + 1;
  }

  if (((empty($this->org_id) || (empty($this->transaction_type_id))) && (!empty($this->inv_receipt_header_id)))) {
   $invrh = new inv_receipt_header();
   $invrh_i = $invrh->findBy_id($this->inv_receipt_header_id);
   $this->org_id = $invrh_i->org_id;
   $this->transaction_type_id = $invrh_i->transaction_type_id;
  }
 }

 private function _create_receipt_forKit() {
  global $dbc;
  $total_cost = 0;
  $bom_config_h = bom_config_header::find_by_referenceData('po_line', $this->po_line_id);
  $bom_config_l = bom_config_line::find_by_parent_id($bom_config_h->bom_config_header_id);
  if (empty($bom_config_l)) {
   return;
  }
  foreach ($bom_config_l as $bom_cl) {
   $bom_config_ln = new bom_config_line();
   $bom_config_ln->findBy_id($bom_cl->bom_config_line_id);
   $new_qty = $bom_config_ln->usage_quantity * $this->transaction_quantity;
   $bom_config_ln->transacted_quantity += $new_qty;
   try {
    $this->_create_inv_transactions($bom_config_ln->component_item_id_m, $bom_config_ln->component_revision, $bom_config_ln->usage_quantity * $this->transaction_quantity);
    $bom_config_ln->save();
    $item_cost = cst_item_cost_v::find_cost_by_itemId_orgId($bom_config_ln->component_item_id_m, $this->org_id);
    if (!empty($item_cost->standard_cost)) {
     $total_cost += ( $item_cost->standard_cost * $new_qty);
    }
   } catch (Exception $e) {
    echo "<br>Failed to update the bom config line quantity. Error @ inv_receipt_line @@ line " . __LINE__ . $e->getMessage();
    $dbc->rollback = true;
   }
  }
  $this->_standard_cost_for_all_kit_items = $total_cost;
  $this->_create_gl_transaction();
 }

 private function _create_gl_transaction() {
  global $dbc;

  $po_line = po_line::find_by_id($this->_po_line_id);

  $inv = new inventory();
  $inv_i = $inv->findRelatedDetail_ByOrgId($this->org_id);
  $gled = new gl_ledger();
  $gled->findBy_id($inv_i->ledger_id);
  $gp = new gl_period();
  $current_open_period = $gp->current_open_period($inv_i->ledger_id);
  $gjh = new gl_journal_header;
  $gjh->ledger_id = $inv_i->ledger_id;
  $gjh->status = 'ENTERED';
  $gjh->currency = $gled->currency_code;
  $gjh->period_id = $current_open_period->gl_period_id;
  $gjh->journal_source = self::$module;
  $gjh->journal_category = self::$gl_journal_category;
  $gjh->reference_type = 'table';
  $gjh->reference_key_name = 'inv_receipt_header';
  $gjh->reference_key_value = $this->inv_receipt_header_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = 'A';
  $gjh->audit_trial();
  $gjh->gl_journal_header_id = null;
  if ($gjh->validate_requiredField()) {
   try {
    $gjh->save();
    $this->_gl_journal_header_id = $gjh->gl_journal_header_id;
    echo "<br> The New Journal Header Id is " . $this->_gl_journal_header_id;
   } catch (Exception $e) {
    echo "<br>Failed to jouranl header. Error @ inv_receipt_line @@ line " . __LINE__ . $e->getMessage();
    $dbc->rollback = true;
   }
  } else {
   return;
  }

//Create debit line
  $line_num = 1;
  $new_gjl = new gl_journal_line();
  $new_gjl->gl_journal_header_id = $this->_gl_journal_header_id;
  $new_gjl->line_num = $line_num;
  $line_num++;
  $new_gjl->status = 'U';
  $new_gjl->code_combination_id = $inv_i->material_ac_id;
  $new_gjl->total_dr = $this->_standard_cost_for_all_kit_items;
  $new_gjl->total_ac_dr = $this->_standard_cost_for_all_kit_items;
  $new_gjl->description = 'Inv Receipt Line Id ' . $this->inv_receipt_line_id . ' item id ' . $this->item_id_m;
  $new_gjl->reference_type = 'table';
  $new_gjl->reference_key_name = 'inv_receipt_line';
  $new_gjl->reference_key_value = $this->inv_receipt_line_id;
  $val_result = $new_gjl->validate_requiredField();

  if ($val_result) {
   try {
    $new_gjl->save();
   } catch (Exception $e) {
    echo "<br>Failed to jouranl line. Error @ inv_receipt_line @@ line " . __LINE__ . $e->getMessage();
    $dbc->rollback = true;
   }
  } else {
   return;
  }

  //create credit line
  $po_unit_price = !empty($po_line->unit_price) ? $po_line->unit_price : 0;

  $new_gjl->gl_journal_line_id = null;
  $new_gjl->line_num = $line_num;
  $line_num++;
  $new_gjl->status = 'U';
  $new_gjl->code_combination_id = $inv_i->expense_ac_id;
  $new_gjl->total_ac_cr = $new_gjl->total_cr = $po_unit_price * $this->transaction_quantity;
  $new_gjl->total_ac_dr = $new_gjl->total_dr = 0;
  $ppv_amnt = $po_unit_price * $this->transaction_quantity - $this->_standard_cost_for_all_kit_items;

  $val_result = $new_gjl->validate_requiredField();
  if ($val_result) {
   try {
    $new_gjl->save();
   } catch (Exception $e) {
    echo "<br>Failed to jouranl line. Error @ inv_receipt_line @@ line " . __LINE__ . $e->getMessage();
    $dbc->rollback = true;
   }
  } else {
   return;
  }

  if (empty($ppv_amnt)) {
   return;
  }
  //create PPV account
  $new_gjl->gl_journal_line_id = null;
  $new_gjl->line_num = $line_num;
  $line_num++;
  $new_gjl->status = 'U';
  $new_gjl->code_combination_id = $this->_ppv_ac_id;
  if ($ppv_amnt > 0) {
   $new_gjl->total_dr = $new_gjl->total_ac_dr = $ppv_amnt;
   $new_gjl->total_ac_cr = $new_gjl->total_cr = 0;
  } else {
   $new_gjl->total_cr = $new_gjl->total_ac_cr = abs($ppv_amnt);
   $new_gjl->total_ac_dr = $new_gjl->total_dr = 0;
  }
  $new_gjl->description = 'PPV for Inv Receipt Line Id ' . $this->inv_receipt_line_id . ' item id ' . $this->item_id_m;
  $val_result = $new_gjl->validate_requiredField();
  if ($val_result) {
   try {
    $new_gjl->save();
   } catch (Exception $e) {
    echo "<br>Failed to jouranl line. Error @ inv_receipt_line @@ line " . __LINE__ . $e->getMessage();
    $dbc->rollback = true;
   }
  } else {
   return;
  }
 }

 private function _create_inv_transactions($item_id_m = '', $revision_name = '', $transaction_qty = '') {
  $inv_transaction = new inv_transaction();
  if ($this->kit_cb) {
   $inv_transaction->setProperty('_gl_transaction', false);
  }
  $item_id_m_f = empty($item_id_m) ? $this->item_id_m : $item_id_m;
  $revision_name_f = empty($revision_name) ? $this->revision_name : $revision_name;
  $transaction_qty_f = empty($transaction_qty) ? $this->transaction_quantity : $transaction_qty;

//  if (!empty($this->exchange_rate)) {
//   $inv_transaction->exchange_rate_type = $this->exchange_rate_type;
//   $inv_transaction->exchange_rate = $this->exchange_rate;
//  }
  $inv_transaction->currency = $this->currency;
//  $inv_transaction->doc_currency = $this->doc_currency;
  $inv_transaction->org_id = $this->org_id;
  $inv_transaction->quantity = $transaction_qty_f;
  $inv_transaction->item_id_m = $item_id_m_f;
  $inv_transaction->revision_name = $revision_name_f;
  $inv_transaction->transaction_type_id = $this->transaction_type_id;
  $inv_transaction->reference_type = 'table';
  $inv_transaction->reference_key_name = 'inv_receipt_line';
  $inv_transaction->reference_key_value = $this->inv_receipt_line_id;

  switch ($this->transaction_type_id) {
   case 5 :
    $inv_transaction->to_subinventory_id = $this->subinventory_id;
    if (!empty($this->locator_id)) {
     $inv_transaction->to_locator_id = $this->locator_id;
    }
    $inv_transaction->po_detail_id = $this->po_detail_id;
    $inv_transaction->document_type = 'PO';
    $inv_transaction->document_number = $this->po_number;
    $inv_transaction->_before_save();
    $inv_transaction->save();
    $update_result = $inv_transaction->_after_save();
    break;

   case 21 :
    $inv_transaction->from_subinventory_id = $this->subinventory_id;
    if (!empty($this->locator_id)) {
     $inv_transaction->from_locator_id = $this->locator_id;
    }
    $inv_transaction->po_detail_id = $this->po_detail_id;
    $inv_transaction->document_type = 'PO';
    $inv_transaction->document_number = $this->po_number;
    $inv_transaction->_before_save();
    $inv_transaction->save();
    $update_result = $inv_transaction->_after_save();
    break;

   case 20 :
    $inv_transaction->to_subinventory_id = $this->subinventory_id;
    if (!empty($this->locator_id)) {
     $inv_transaction->to_locator_id = $this->locator_id;
    }
//    $inv_transaction->reference_key_name = 'inv_intorg_transfer_line';
//    $inv_transaction->reference_key_value = $this->inv_intorg_transfer_line_id;
    $to_org = inventory::find_by_org_id($this->org_id);
//    pa($to_org);
    $inv_transaction->account_id = $to_org->inter_org_payable_ac_id;
    $inv_transaction->document_type = 'Inter Org';
    $inv_transaction->document_number = $this->io_order_number;
    $inv_transaction->_before_save();
    $inv_transaction->save();
    $update_result = $inv_transaction->_after_save();
    break;

   case 23 :
    $inv_transaction->to_subinventory_id = $this->subinventory_id;
    if (!empty($this->locator_id)) {
     $inv_transaction->to_locator_id = $this->locator_id;
    }
    $inv_transaction->sd_so_line_id = $this->sd_so_line_id;
    $inv_transaction->document_type = 'RMA';
    $inv_transaction->document_number = $this->so_number;
    $inv_transaction->_before_save();
    $inv_transaction->save();
    $update_result = $inv_transaction->_after_save();
    break;
    
    case 33 :
    $inv_transaction->to_subinventory_id = $this->subinventory_id;
    if (!empty($this->locator_id)) {
     $inv_transaction->to_locator_id = $this->locator_id;
    }
    $inv_transaction->po_requisition_detail_id = $this->po_requisition_detail_id;
    $inv_transaction->document_type = 'IR';
    $inv_transaction->document_number = $this->po_requisition_number;
    $inv_transaction->_before_save();
    $inv_transaction->save();
    $update_result = $inv_transaction->_after_save();
    break;

   default:
    break;
  }
 }

 private function _highest_line_number_from_header() {
  global $db;
  $sql = " SELECT max(line_number) as line_number FROM " . self::$table_name;
  $sql .= " WHERE inv_receipt_header_id = :inv_receipt_header_id ";
  $param_a = ['inv_receipt_header_id'];
  $value_a = ['inv_receipt_header_id' => $this->inv_receipt_header_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : 0;
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
   'transaction_quantity',
   'subinventory_id',
   'locator_id',
  ];
  return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'action_class_name',
   'org_id',
   'inv_receipt_header_id',
   'mode',
   'action',
   'po_status',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of inv_receipt_line class
?>