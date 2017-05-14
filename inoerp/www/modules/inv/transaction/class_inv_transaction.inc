<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * inv_transaction
 * Contains all the inv_transaction information, such as - item_id_m, order_number,  from_org_id, to_org_id, etc.
 * 
 */
class inv_transaction extends dbObject {

 public static $table_name = "inv_transaction";
 public static $primary_column = "inv_transaction_id";
 public static $key_column = 'item_id_m';
 public static $module = "inv";
 public static $gl_journal_category = "INV_INVENTORY";
 public static $system_info = [
  'name' => 'INV Transaction',
  'number' => '2107',
  'description' => 'Inventory Transaction',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 7
 ];
 public static $allowed_inv_transactions = [
  '1' => 'Miscellaneous Issue',
  '2' => 'Miscellaneous Receipt',
  '3' => 'Subinventory Transfer'
 ];
 public $field_a = [
  'inv_transaction_id',
  'transaction_type_id',
  'org_id',
  'status',
  'receipt_line_id',
  'item_number',
  'item_id_m',
  'revision_name',
  'uom_id',
  'lot_number_id',
  'logical_transaction_cb',
  'document_type',
  'document_number',
  'document_id',
  'wip_wo_bom_id',
  'am_wo_bom_id',
  'po_header_id',
  'po_line_id',
  'po_detail_id',
  'sd_so_line_id',
  'reason',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'description',
  'from_org_id',
  'from_subinventory_id',
  'from_locator_id',
  'quantity',
  'from_account_id',
  'to_org_id',
  'to_subinventory_id',
  'to_locator_id',
  'to_account_id',
  'unit_cost',
  'costed_amount',
  'gl_journal_header_id',
  'bom_config_header_id',
  'transaction_rev_enabled_cb',
  'rev_start_number',
  'pm_batch_line_id',
  'pm_batch_header_id',
  'pm_batch_ingredient_id',
  'pm_batch_byproduct_id',
  'po_requisition_detail_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  "inv_transaction_id",
  "transaction_type_id",
  'status',
  "item_id_m",
  "org_id",
  "item_number",
  "creation_date",
  "document_type",
  "document_number"
 ];
 public $account = [
  "from_account_id",
  "to_account_id",
  "account_id"];
 public $checkbox = [
  "logical_transaction_cb",
  "transaction_rev_enabled_cb"];
 public $fields_inForm_notInDataBase = [
  "account_id",
  'item_description',
  'serial_generation',
  'serial_number',
  'inv_serial_number_id',
  'lot_generation',
  'lot_number',
  'lot_quantity',
  'kit_cb',
  'onhand',
  'reservable_onhand',
  'line_type'
 ];
 public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "org_id",
  "transaction_type_id",
 ];
 public $requiredField = [
  "uom_id",
  "quantity",
  "org_id",
  "item_id_m",
  "transaction_type_id"
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Transaction - Create & View Transactions"; //page Title
 public $option_lists = [
  'inv_transaction_class' => 'TRANSACTION_TYPE_CLASS'
 ];
 public $inv_transaction_id;
 public $transaction_type_id;
 public $org_id;
 public $status;
 public $receipt_line_id;
 public $item_number;
 public $revision_name;
 public $item_id_m;
 public $uom_id;
 public $lot_number_id;
 public $logical_transaction_cb;
 public $document_type;
 public $document_number;
 public $document_id;
 public $wip_wo_bom_id;
 public $am_wo_bom_id;
 public $po_header_id;
 public $po_line_id;
 public $po_detail_id;
 public $sd_so_line_id;
 public $reason;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $description;
 public $from_org_id;
 public $from_subinventory_id;
 public $from_locator_id;
 public $quantity;
 public $from_account_id;
 public $to_org_id;
 public $to_subinventory_id;
 public $to_locator_id;
 public $to_account_id;
 public $unit_cost;
 public $costed_amount;
 public $gl_journal_header_id;
 public $bom_config_header_id;
 public $transaction_rev_enabled_cb;
 public $rev_start_number;
 public $pm_batch_line_id;
 public $pm_batch_header_id;
 public $pm_batch_ingredient_id;
 public $pm_batch_byproduct_id;
 public $po_requisition_detail_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $item_description;
 public $wip_wo_header_id;
 public $wo_number;
 public $available_quantity;
 public $transacted_quantity;
 public $total_quantity;
 public $account_id;
 private $_cr_amount;
 private $_dr_amount;
 private $_adjustment_amount;
 public $lot_number;
 public $serial_number;
 public $inv_serial_number_id;
 public $serial_number_id;
 public $serial_generation;
 public $lot_generation;
 public $lot_quantity;
 private $_serial_type;
 private $_serial_number_id;
 private $_onhand_id_from;
 private $_onhand_id_to;
 private $_wip_accounting_group_id;
 private $_dr_ac_id;
 private $_cr_ac_id;
 private $_gl_transaction = true;
 public $kit_cb;
 public $ledger_id;
 private $_ledger_id;
 private $_asset_create_journal = true;
 public $am_wo_header_id;
 private $_am_accounting_group_id;
 public $exchange_rate_type;
 public $exchange_rate = null;
 public $currency;
 public $doc_currency;
 public $d_reference_key_name = null;
 public $d_reference_key_value = null;
 public $s_reference_key_name = null;
 public $s_reference_key_value = null;
 public $serial_number_ids = [];
 public $lot_number_ids = [];
 public $reservable_onhand;
 public $onhand;
 public $ar_customer_site_id;
 public $line_type;

 public function setProperty($property, $value) {
  if (property_exists($this, $property)) {
   switch ($property) {
    case '_show_update_path':
     $this->$property = !empty($value) ? true : false;

    default:
     $this->$property = $value;
     break;
   }
  }
 }

 Public static function inv_transaction_class() {
  $option_header = option_header::find_by_name('TRANSACTION_TYPE_CLASS');
  $inv_transaction_class = option_line::find_by_option_id($option_header->option_id);
  return $inv_transaction_class;
 }

 public function _before_showing() {

  if (!(empty($this->transaction_type_id))) {
   switch ($this->transaction_type_id) {
    case 1 :
     $this->account_id = $this->to_account_id;
     break;

    case 2 :
     $this->account_id = $this->from_account_id;
     break;

    default:
     if (!empty($this->to_account_id)) {
      $this->account_id = $this->to_account_id;
     } else {
      $this->account_id = $this->from_account_id;
     }

     break;
   }
  }

  if (!empty($this->to_account_id)) {
   $this->account_id = $this->to_account_id;
  } else {
   $this->account_id = $this->from_account_id;
  }
 }

 private function _create_lot_number($lot_num) {
  $ln = new inv_lot_number();
  $ln->item_id_m = $this->item_id_m;
  $ln->org_id = $this->org_id;
  $ln->lot_number = $lot_num;
  $ln->status = 'ACTIVE';
  $ln->generation = 'AT_RECEIPT';
  $ln->origination_type = 'INVENTORY';
  $ln->origination_date = $ln->activation_date = current_time(1);
  $ln->first_inv_transaction_id = $ln->last_inv_transaction_id = $this->inv_transaction_id;
  $ln->audit_trial();
  $ln->save();
  return $ln->inv_lot_number_id;
 }

 private function _verify_lot_expiration($existing_lot_details) {
  $trnx_allowed_status = 1;
  $exp_date = NEW DateTime($existing_lot_details->lot_expiration_date);
  $interval = $exp_date->diff(new DateTime());
  if ($interval->invert == 0) {
   //period is past
   switch ($existing_lot_details->expiration_action) {
    case 'NO_TRANSACTION' :
     echo "<br>Entered LN is Expired";
     $dbc->rollback = 1;
     $trnx_allowed_status = -90;
     break;

    case 'WARNING' :
     echo "<br>Entered LN is Expired";
     break;

    case 'RTV_MISC' :
     if (!(in_array($this->transaction_type_id, array('1', '2', 21)))) {
      echo "<br>Entered LN is  Expired";
      $trnx_allowed_status = -90;
      $dbc->rollback = 1;
     }
     break;

    case 'ONLY_RTV' :
     if (!($this->transaction_type_id == 21)) {
      echo "<br>Entered LN is  Expired";
      $trnx_allowed_status = -90;
      $dbc->rollback = 1;
     }
     break;

    default :
     break;
   }
  }
  return $trnx_allowed_status;
 }

 private function _update_lot_onhand($lot_id, $update_type) {
  global $dbc;
  $return = false;
  if (!empty($lot_id) && !empty($this->_onhand_id_from) && ($update_type == 'from' )) {
   $loh = new inv_lot_onhand();
   $loh->inv_lot_number_id = $lot_id;
   $loh->onhand_id = $this->_onhand_id_from;
   $loh_i = $loh->findBy_lotID_invOnhandId();
   if ($loh_i) {
    foreach ($loh_i as $key => $val) {
     $loh->$key = $val;
    }
    $loh->lot_quantity -= $this->quantity;
    if ($loh->lot_quantity < 0) {
     $return = -1;
    } else {
     try {
      $loh->save();
      $return = 1;
     } catch (Exception $e) {
      $dbc->rollback = 1;
      $return = -1;
      echo "<br> Failed to update lot onhand. Issue @ inv_transaction @@ Line " . __LINE__;
     }
    }
   } else {
    $dbc->rollback = 1;
    echo "<br> Cant complete the transaction as no lot details found. Issue @ inv_transaction @@ Line " . __LINE__;
   }
  }

  if (!empty($lot_id) && !empty($this->_onhand_id_to) && ($update_type == 'to')) {
   $loh = new inv_lot_onhand();
   $loh->inv_lot_number_id = $lot_id;
   $loh->onhand_id = $this->_onhand_id_to;
   $loh_j = $loh->findBy_lotID_invOnhandId();
   if ($loh_j) {
    foreach ($loh_j as $key => $val) {
     $loh->$key = $val;
    }
   }
   $loh->lot_quantity += $this->quantity;
   try {
    $loh->save();
    $return = 1;
   } catch (Exception $e) {
    $dbc->rollback = 1;
    echo "<br> Failed to update lot onhand. Issue @ inv_transaction @@ Line " . __LINE__;
   }
  }
  return $return;
 }

 private function _transact_lot_receipt() {
  if (!empty($this->lot_number_ids)) {
   $this->_transact_lot_receipt_forNonPostData();
  } else {
   for ($i = 0; $i < count($_POST['lot_quantity']); $i++) {
    $ist = new inv_lot_transaction();
    $ist->lot_quantity = $_POST['lot_quantity'][$i];
    if ($this->_lot_type == 'ID') {
     $existing_lot_details = inv_lot_number::find_by_id($_POST['inv_lot_number_id'][$i]);
     if (!empty($existing_lot_details->lot_expiration_date)) {
      $trnx_allowed_status = $this->_verify_lot_expiration($existing_lot_details);
      if ($trnx_allowed_status < 0) {
       return -90;
      }
     }
     $ist->inv_lot_number_id = $_POST['inv_lot_number_id'][$i];
     try {
      $this->_update_lot_onhand($ist->inv_lot_number_id, 'to');
     } catch (Exception $e) {
      echo "<br> Failed to update lot onhand. Issue @ inv_transaction @@ Line " . __LINE__;
      $dbc->rollback = 1;
      return -90;
     }
    } else {
     $lot_id = $this->_create_lot_number($_POST['lot_number'][$i]);
     $ist->inv_lot_number_id = $lot_id;
     $ist->inv_transaction_id = $this->inv_transaction_id;
     try {
      $ist->save();
      $this->_lot_number_id = $ist->inv_lot_number_id;
      try {
       $this->_update_lot_onhand($ist->inv_lot_number_id, 'to');
      } catch (Exception $e) {
       echo "<br> Failed to update lot onhand. Issue @ inv_transaction @@ Line " . __LINE__;
       $dbc->rollback = 1;
       return -90;
      }
     } catch (Exception $e) {
      echo "<br>Entered Lot Number is not available for transaction . Issue @ inv_transaction @@ Line " . __LINE__;
      $dbc->rollback = 1;
      return -90;
     }
    }
   }
  }

  return 1;
 }

 private function _transact_lot_receipt_forNonPostData() {
  global $dbc;

  if (!empty($this->lot_number_ids)) {
   foreach ($this->lot_number_ids as $ln_id => $q) {
    $existing_lot_details = inv_lot_number::find_by_id($ln_id);
    $ist = new inv_lot_transaction();
    if (!empty($existing_lot_details->lot_expiration_date)) {
     $trnx_allowed_status = $this->_verify_lot_expiration($existing_lot_details);
     if ($trnx_allowed_status < 0) {
      return -90;
     }
    }
    $ist->inv_lot_number_id = $existing_lot_details->inv_lot_number_id;
    $ist->lot_quantity = $q;

    try {
     $this->_update_lot_onhand($ist->inv_lot_number_id, 'to');
     $ist->inv_transaction_id = $this->inv_transaction_id;
     $ist->save();
    } catch (Exception $e) {
     echo "<br> Failed to update lot number. Issue @ inv_transaction @@ Line " . __LINE__;
     $dbc->rollback = 1;
     return -90;
    }
   }
  }
 }

 private function _transact_lot_issue() {
  global $dbc;
  if (!empty($this->lot_number_ids)) {
   $this->_transact_lot_issue_forNonPostData();
  } else {
   for ($i = 0; $i < count($_POST['lot_quantity']); $i++) {
    $ist = new inv_lot_transaction();
    $existing_lot_details = inv_lot_number::find_by_id($_POST['inv_lot_number_id'][$i]);
    if (!empty($existing_lot_details->lot_expiration_date)) {
     $trnx_allowed_status = $this->_verify_lot_expiration($existing_lot_details);
     if ($trnx_allowed_status < 0) {
      return -90;
     }
    }
    $ist->inv_lot_number_id = $_POST['inv_lot_number_id'][$i];
    $ist->lot_quantity = $_POST['lot_quantity'][$i];
    try {
     $this->_update_lot_onhand($ist->inv_lot_number_id, 'from');
     $ist->inv_transaction_id = $this->inv_transaction_id;
     $ist->save();
    } catch (Exception $e) {
     echo "<br> Failed to update lot number. Issue @ inv_transaction @@ Line " . __LINE__;
     $dbc->rollback = 1;
     return -90;
    }
   }
  }
  return 1;
 }

 private function _transact_lot_issue_forNonPostData() {
  global $dbc;
  $qty_issued = 0;
  $pos = 0;
  if (!empty($this->lot_number_ids)) {
   foreach ($this->lot_number_ids as $ln_id => $q) {
    $pos++;

    if ($qty_issued >= $this->quantity) {
     break;
    }
    $existing_lot_details = inv_lot_number::find_by_id($ln_id);
    $ist = new inv_lot_transaction();
    if (!empty($existing_lot_details->lot_expiration_date)) {
     $trnx_allowed_status = $this->_verify_lot_expiration($existing_lot_details);
     if ($trnx_allowed_status < 0) {
      return -90;
     }
    }
    $ist->inv_lot_number_id = $existing_lot_details->inv_lot_number_id;

    if ($q >= ($this->quantity - $qty_issued)) {
     $ist->lot_quantity = $this->quantity - $qty_issued;
     $this->lot_number_ids[$ln_id] = $ist->lot_quantity;
     $this->lot_number_ids = array_slice($this->lot_number_ids, 0, $pos, TRUE);
     break;
    } else {
     $ist->lot_quantity = $q;
     $qty_issued += $q;
    }

    try {
     $lot_oh_s = $this->_update_lot_onhand($ist->inv_lot_number_id, 'from');
     if (empty($lot_oh_s) || $lot_oh_s < 1) {
      unset($this->lot_number_ids[$ln_id]);
      $pos--;
      continue;
     }
     $ist->inv_transaction_id = $this->inv_transaction_id;
     $ist->save();
    } catch (Exception $e) {
     echo "<br> Failed to update lot number. Issue @ inv_transaction @@ Line " . __LINE__;
     $dbc->rollback = 1;
     return -90;
    }
   }
  }
 }

 private function _create_serial_number($serial_num) {
  $sn = new inv_serial_number();
  $sn->item_id_m = $this->item_id_m;
  $sn->org_id = $sn->current_org_id = $this->org_id;
  $sn->serial_number = $serial_num;
  $sn->status = 'IN_STORE';
  $sn->generation = 'AT_RECEIPT';
  $sn->origination_type = 'INVENTORY';
  $sn->origination_date = $sn->activation_date = current_time(1);
  $sn->current_subinventory_id = $this->to_subinventory_id;
  $sn->current_locator_id = $this->to_locator_id;
  $sn->first_inv_transaction_id = $sn->last_inv_transaction_id = $this->inv_transaction_id;
  $sn->audit_trial();
  $sn->save();
  return $sn->inv_serial_number_id;
 }

 private function _transact_serial_receipt() {
  global $dbc;
  for ($i = 0; $i < $this->quantity; $i++) {
   $ist = new inv_serial_transaction();
   if ($this->_serial_type == 'ID') {
    if (!empty($this->serial_number_ids)) {
     $sn_ids = $this->serial_number_ids;
     $existing_serial_details = inv_serial_number::find_by_id($sn_ids[$i]);
    } else {
     $existing_serial_details = inv_serial_number::find_by_id($_POST['inv_serial_number_id'][$i]);
    }
    if (!in_array($existing_serial_details->status, array('DEFINED', 'OUT_STORE', 'INTRANSIT', 'IN_RECEIVING', 'IN_WIP'))) {
     echo "<br>Entered SN is not available for transaction . Issue @ inv_transaction @@ Line " . __LINE__;
     $dbc->rollback = 1;
     return -90;
    }

    if (!empty($this->serial_number_ids)) {
     $ist->inv_serial_number_id = $this->serial_number_ids[$i];
    } else {
     $ist->inv_serial_number_id = $_POST['inv_serial_number_id'][$i];
    }

    try {
     $this->_update_serial_number_receipt($ist->inv_serial_number_id);
    } catch (Exception $e) {
     echo "<br> Failed to update serial number. Issue @ inv_transaction @@ Line " . __LINE__;
     $dbc->rollback = 1;
     return -90;
    }
   } else {
    $serial_id = $this->_create_serial_number($_POST['serial_number'][$i]);
    $ist->inv_serial_number_id = $serial_id;
   }
   $ist->inv_transaction_id = $this->inv_transaction_id;
   try {
    $ist->audit_trial();
    $ist->save();
    $this->_serial_number_id = $ist->inv_serial_number_id;
   } catch (Exception $e) {
    echo "<br>Entered SN is not available for transaction . Issue @ inv_transaction @@ Line " . __LINE__;
    $dbc->rollback = 1;
    return -90;
   }
  }
  return 1;
 }

 private function _transact_serial_issue() {
  global $dbc;
  for ($i = 0; $i < $this->quantity; $i++) {
   $ist = new inv_serial_transaction();
   if (!empty($this->serial_number_ids)) {
    $sn_ids = $this->serial_number_ids;
//    pa($sn_ids);
    $existing_serial_details = inv_serial_number::find_by_id($sn_ids[$i]);
    if (count($sn_ids) < $this->quantity) {
     throw new Exception('No of available serial numbers are less than the transaction quantity. <br>Error @ ' . __FILE__ . ' @@ ' . __LINE__);
    }
   } else {
    $existing_serial_details = inv_serial_number::find_by_id($_POST['inv_serial_number_id'][$i]);
   }

   if ($existing_serial_details->status != 'IN_STORE') {
    echo "<br>Entered SN is not available for transaction . Issue @ inv_transaction @@ Line " . __LINE__;
    $dbc->rollback = 1;
    return -90;
   }
   if (!empty($this->serial_number_ids)) {
    $ist->inv_serial_number_id = $this->serial_number_ids[$i];
   } else {
    $ist->inv_serial_number_id = $_POST['inv_serial_number_id'][$i];
   }

   //verfiy serial reservation - Serial reservation should also be done in the source
   $sl_reservation = inv_reservation::find_by_serialNumberId($ist->inv_serial_number_id);
   if ($sl_reservation && ($sl_reservation->d_reference_key_name != $this->d_reference_key_name || $sl_reservation->d_reference_key_value != $this->d_reference_key_value)) {
    $exp_msg = "<br>Entered SN is not available for transaction . Issue @ inv_transaction @@ Line " . __LINE__;
    $dbc->rollback = 1;
    throw new Exception($exp_msg);
   }

   try {
    $this->_update_serial_number_issue($ist->inv_serial_number_id);
   } catch (Exception $e) {
    echo "<br> Failed to update serial number. Issue @ inv_transaction @@ Line " . __LINE__;
    $dbc->rollback = 1;
    return -90;
   }
   $ist->inv_transaction_id = $this->inv_transaction_id;
   $ist->save();
  }
  return 1;
 }

 private function _transact_serial_number() {
  global $dbc;
  $return_val = 1;
  $item = item::find_by_orgId_item_id_m($this->item_id_m, $this->org_id);
  if (!empty($item->serial_generation) && ($item->serial_generation == 'PRE_DEFINED')) {
   $this->_serial_type = 'ID';
  } else if (!empty($item->serial_generation)) {
   $this->_serial_type = 'NUMBER';
  } else {
   return $return_val;
  }

  if (in_array($this->transaction_type_id, array(1, 3, 6, 7, 9, 12, 13, 14, 15, 18, 19, 20, 21, 22, 24, 25, 26, 29, 30, 33))) {
   $this->_serial_type = 'ID';
  }

  if ($this->transaction_type_id == 1) {
   try {
    $return_val = $this->_transact_serial_issue();
   } catch (Exception $e) {
    echo "<br>Failed to complete _transact_serial_issue " . $e->getMessage();
   }
  }

  if ($this->transaction_type_id == 2) {
   $return_val = $this->_transact_serial_receipt();
  }

  if ($this->transaction_type_id == 3) {
   try {
    $return_val1 = $this->_transact_serial_issue();
   } catch (Exception $e) {
    echo "<br>Failed to complete _transact_serial_issue " . $e->getMessage();
   }
   $return_val2 = $this->_transact_serial_receipt();
   $return_val = $return_val1 && $return_val2;
  }

  if (in_array($this->transaction_type_id, array(6, 18, 19, 13, 14, 15, 21, 24, 26, 29))) {
   try {
    $return_val = $this->_transact_serial_issue();
   } catch (Exception $e) {
    echo "<br>Failed to complete _transact_serial_issue " . $e->getMessage();
   }
  }


  if (in_array($this->transaction_type_id, array(20, 5, 7, 11, 14, 23, 25, 26, 30, 33))) {
   $return_val = $this->_transact_serial_receipt();
  }

  //create serial parent child reltion
  if ($this->transaction_type_id == 11) {
   try {
    inv_serial_number::create_parentChildRelation($this->_serial_number_id, $this->document_id);
   } catch (Exception $e) {
    echo "<br>Error @ class_inv_transaction @@Line " . __LINE__ . $e->getMessage();
   }
  }

  return $return_val;
 }

 private function _transact_lot_number() {
  global $dbc;
  $return_val = 1;
  $item = item::find_by_orgId_item_id_m($this->item_id_m, $this->org_id);
  if (!empty($item->lot_generation) && ($item->lot_generation == 'PRE_DEFINED')) {
   $this->_lot_type = 'ID';
  } else if (!empty($item->lot_generation)) {
   $this->_lot_type = 'NUMBER';
  } else {
   return $return_val;
  }

  if (in_array($this->transaction_type_id, array(1, 3, 6, 9, 12, 13, 14, 15, 18, 19, 20, 21, 22, 24, 26, 29, 33))) {
   $this->_lot_type = 'ID';
  }

  if ($this->transaction_type_id == 1) {
   $return_val = $this->_transact_lot_issue();
  }

  if ($this->transaction_type_id == 2) {
   $return_val = $this->_transact_lot_receipt();
  }

  if ($this->transaction_type_id == 3) {
   $return_val1 = $this->_transact_lot_issue();
   $return_val2 = $this->_transact_lot_receipt();
   $return_val = $return_val1 && $return_val2;
  }

  if (in_array($this->transaction_type_id, array(6, 18, 19, 13, 14, 21, 24, 26, 29))) {
   $return_val = $this->_transact_lot_issue();
  }

  if (in_array($this->transaction_type_id, array(20, 5, 7, 11, 14, 23, 25, 26, 30, 33))) {
   $return_val = $this->_transact_lot_receipt();
  }

  //create lot parent child reltion
//   if ($this->transaction_type_id == 11) {
//    try {
//     inv_lot_number::create_parentChildRelation($this->_lot_number_id, $this->document_id);
//    } catch (Exception $e) {
//     echo "<br>Error @ class_inv_transaction @@Line " . __LINE__ . $e->getMessage();
//    }
//   }

  return $return_val;
 }

 private function _update_serial_number_receipt($serial_id) {
  global $dbc;
  $snu = new inv_serial_number();
  $snu->findBy_id($serial_id);
  $snu->status = 'IN_STORE';
  $snu->activation_date = current_time(1);
  $snu->current_org_id = $this->org_id;
  $snu->current_subinventory_id = $this->to_subinventory_id;
  $snu->current_locator_id = $this->to_locator_id;
  $snu->last_inv_transaction_id = $this->inv_transaction_id;
  try {
   $snu->audit_trial();
   $snu->save();
  } catch (Excetion $e) {
   $dbc->rollback = 1;
   echo "<br> Failed to update serial number. Issue @ inv_transaction @@ Line " . __LINE__;
  }
 }

 private function _update_serial_number_issue($serial_id) {
  global $dbc;
  $snu = new inv_serial_number();
  $snu->findBy_id($serial_id);
  if (in_array($this->transaction_type_id, [6, 29])) {
   $snu->status = 'IN_WIP';
   $snu->current_wip_wo_header_id = $this->document_id;
  } else {
   $snu->status = 'OUT_STORE';
  }
  $snu->activation_date = current_time(1);
  if (in_array($this->transaction_type_id, [6, 29])) {
   $snu->current_org_id = $this->org_id;
  } else {
   $snu->current_org_id = '';
  }
  if ($this->transaction_type_id == 15) {
   $snu->ar_customer_site_id = $this->ar_customer_site_id;
   $snu->sd_so_line_id = $this->sd_so_line_id;
  }
  $snu->current_subinventory_id = '';
  $snu->current_locator_id = '';
  $snu->last_inv_transaction_id = $this->inv_transaction_id;
  try {
   $snu->save();
  } catch (Excetion $e) {
   $dbc->rollback = 1;
   echo "<br> Failed to update serial number. Issue @ inv_transaction @@ Line " . __LINE__;
  }
 }

 private function _validate_before_save() {
  $ret = 1;
  if (!empty($this->inv_transaction_id)) {
   $ret = -90;
   throw new Exception('You cant update any inventory transaction. Try a reverse transaction. <br>Transaction id ' . $this->inv_transaction_id);
  }
  $item = item::find_by_orgId_item_id_m($this->item_id_m, $this->org_id);
  if ($item) {
   if (empty($item->inventory_item_cb) || empty($item->transactable_cb)) {
    $ret = 2;
    echo "<br> The item is not enabled for Inventory Transaction";
   } else if (empty($item->inventory_asset_cb)) {
    $this->_asset_create_journal = false;
   }
  } else {
   $ret = -90;
   echo "<br> The item is not assigned to the organization";
  }
  return $ret;
 }

 private function _entered_lot_quantity_total() {
  $ret_quantity = 0;
  if (!empty($_POST['inv_lot_number_id'])) {
   foreach ($_POST['inv_lot_number_id'] as $key => $value) {
    $ret_quantity +=!empty($_POST['lot_quantity'][$key]) ? $_POST['lot_quantity'][$key] : 0;
   }
   $this->_lot_type = 'ID';
   //good to procedd . $this->_lock_lot_number();
  } else if (!empty($_POST['lot_number'])) {
   foreach ($_POST['lot_number'] as $key => $value) {
    $ret_quantity +=!empty($_POST['lot_quantity'][$key]) ? $_POST['lot_quantity'][$key] : 0;
    $this->_lot_type = 'NUMBER';
   }
  }

  return $ret_quantity;
 }

 public function _before_save() {
  if (method_exists($this, '_before_save_2')) {
   $this->_before_save_2();
  }
  try {
   $validate_before_save_r = $this->_validate_before_save();
  } catch (Exception $e) {
   echo "<br>Failed _before_save. Error @ " . __FILE__ . ' @@ ' . __LINE__ . '<br>' . $e->getMessage();
   return -90;
  }
  if ($validate_before_save_r < 0) {
   return $validate_before_save_r;
  }
  if (!empty($this->org_id)) {
   $inv = new inventory();
   $inv_i = $inv->findRelatedDetail_ByOrgId($this->org_id);
   $this->ledger_id = $this->_ledger_id = $inv_i->ledger_id;
  }
  if (!(empty($this->transaction_type_id))) {
   switch ($this->transaction_type_id) {
    case 1 :
     array_push($this->requiredField, 'to_account_id');
     array_push($this->requiredField, 'from_subinventory_id');
     $this->from_account_id = null;
     $this->to_account_id = $this->account_id;
     break;

    case 2 :
     array_push($this->requiredField, 'from_account_id');
     array_push($this->requiredField, 'to_subinventory_id');
     $this->from_account_id = $this->account_id;
     $this->to_account_id = null;
     break;

    case 3 :
     array_push($this->requiredField, 'to_subinventory_id');
     array_push($this->requiredField, 'from_subinventory_id');
     break;

    case 6 :
    case 7 :
     array_push($this->requiredField, 'wip_wo_bom_id');
     array_push($this->requiredField, 'wip_wo_header_id');
     $this->reference_key_name = !empty($this->reference_key_name) ? $this->reference_key_name : 'wip_wo_header';
     $this->reference_key_value = !empty($this->reference_key_value) ? $this->reference_key_value : $this->wip_wo_header_id;
     break;

    case 24 :
    case 25 :
     array_push($this->requiredField, 'am_wo_bom_id');
     array_push($this->requiredField, 'am_wo_header_id');
     $this->reference_key_name = !empty($this->reference_key_name) ? $this->reference_key_name : 'am_wo_header';
     $this->reference_key_value = !empty($this->reference_key_value) ? $this->reference_key_value : $this->am_wo_header_id;
     break;

    case 29 :
    case 30 :
     array_push($this->requiredField, 'pm_batch_header_id');
     array_push($this->requiredField, 'pm_batch_ingredient_id');
     $this->reference_key_name = !empty($this->reference_key_name) ? $this->reference_key_name : 'pm_batch_header_id';
     $this->reference_key_value = !empty($this->reference_key_value) ? $this->reference_key_value : $this->pm_batch_header_id;
     break;

    default:
     break;
   }
  }

  if ($this->kit_cb) {
   $this->_create_kitTransaction();
   return 10;
  }

//serail verification
  if (!empty($_POST['serial_generation'][0])) {
   if (!empty($_POST['inv_serial_number_id']) && count($_POST['inv_serial_number_id']) >= $this->quantity) {
    $this->_serial_type = 'ID';
    //good to procedd . $this->_lock_serial_number();
   } else if (!empty($_POST['serial_number']) && count($_POST['serial_number']) >= $this->quantity) {
    $this->_serial_type = 'NUMBER';
    //good to procedd . $this->_lock_serial_number();
   } else {
    echo "<br>Incomplete serial numbers for serial controlled items";
    return -99;
   }
  }

  //lot verification  
  if (!empty($_POST['lot_generation'][0]) && empty($this->lot_number_ids)) {
   $entered_lot_quantity_total = $this->_entered_lot_quantity_total();
   if (empty($entered_lot_quantity_total)) {
    echo "<br>Incomplete lot numbers for lot controlled items";
    return -99;
   }
  }



  //barcode
  if ($this->transaction_type_id) {
   $this->_generate_bc_labels();
  }
 }

 private function _create_kitTransaction() {
  global $dbc;
  if (!empty($this->bom_config_header_id)) {
   $bom_config_h = bom_config_header::find_by_id($this->bom_config_header_id);
  } else if (!empty($this->item_id_m) && !empty($this->org_id)) {
   $bom_h = bom_header::find_by_itemId_orgId($this->item_id_m, $this->org_id);
   $bom_config_h = new bom_config_header();
   foreach ($bom_config_h->field_a as $k_bch => $v_bch) {
    if (property_exists($bom_h, $v_bch)) {
     $bom_config_h->$v_bch = $bom_h->$v_bch;
    }
   }
  } else {
   return;
  }

  $bom_config_l = bom_config_line::find_by_parent_id($bom_config_h->bom_config_header_id);
  if (empty($bom_config_l)) {
   return;
  }
//  pa($this);
  foreach ($bom_config_l as $bom_cl) {
   $inv_tran = new inv_transaction();
   foreach ($this->field_a as $this_k => $this_v) {
    $inv_tran->$this_v = $this->$this_v;
   }
   $inv_tran->inv_transaction_id = null;
   $inv_tran->item_number = null;
   $inv_tran->item_id_m = $bom_cl->component_item_id_m;
   $inv_tran->account_id = $this->account_id;
//   pa($this);
   if (!empty($bom_cl->line_quantity)) {
    $new_q = $bom_cl->line_quantity;
   } else {
    $new_q = $bom_cl->usage_quantity * $this->quantity;
   }
   $inv_tran->quantity = $new_q;
   try {
    $inv_tran->_before_save();
    $inv_tran->save();
    $inv_tran->_after_save();
//    pa($inv_tran);
   } catch (Exception $e) {
    echo "<br>Failed to update the bom config line quantity. Error @ inv_transaction @@ line " . __LINE__ . $e->getMessage();
    $dbc->rollback = true;
    return;
   }
  }
 }

 private function _get_barcode_dataObj() {
  switch ($this->transaction_type_id) {
   case 2:
   case 4:
   case 5:
   case 10:
   case 11:
   case 23:
    $data_obj = $this;
    $data_obj->locator = locator::find_by_id($this->to_locator_id)->locator;
    $data_obj->subinventory = subinventory::find_by_id($this->to_subinventory_id)->subinventory;
    $data_obj->creation_date = current_time(1);
    break;
  }
  return $data_obj;
 }

 private function _generate_bc_labels() {
  $bc_auto = bc_label_auto_trigger::find_by_transactionTypId($this);
  if ($bc_auto) {
   //get the correct association level
   $bc_auto_i = $bc_auto[0];

   try {
    if (!empty($this)) {
     $bc_lr = new bc_label_request();
     $bc_lr->sys_printer_id = $bc_auto_i->sys_printer_id;
     $bc_lr->bc_label_format_header_id = $bc_auto_i->bc_label_format_header_id;
     $lbl_frmt_hdr = bc_label_format_header::find_by_id($bc_auto_i->bc_label_format_header_id);
     if (!empty($lbl_frmt_hdr->generator_class_name) && !empty($lbl_frmt_hdr->generator_function_name)) {
      $class_gl = $lbl_frmt_hdr->generator_class_name;
      $$class_gl = new $class_gl;

      if (method_exists($$class_gl, $lbl_frmt_hdr->generator_function_name)) {
       $xml_content_rtn = call_user_func(array($$class_gl, $lbl_frmt_hdr->generator_function_name), $this);
       if (is_array($xml_content_rtn)) {
        foreach ($xml_content_rtn as $xml_content) {
         $bc_lr->print_XMLlabel($xml_content);
        }
       } else {
//        echo $xml_content_rtn;
        $bc_lr->print_XMLlabel($xml_content_rtn);
       }
      }
     } else {
      try {
       $data_obj = $this->_get_barcode_dataObj();
       $xml_content = $bc_lr->generate_label($data_obj);
       $bc_lr->print_XMLlabel($xml_content);
      } catch (Exception $e) {
       $data_obj = $this;
      }
     }
    }
   } catch (Exception $e) {
    echo "<br>Failed to genearte label . Error @ inv_transaction @@ line " . __LINE__ . $e->getMessage();
   }
  }
 }

 private function _save_journal_header() {
  global $dbc;
  $gled = new gl_ledger();
  $gled->findBy_id($this->_ledger_id);
  $gp = new gl_period();
  $current_open_period = $gp->current_open_period($this->_ledger_id);
  $gjh = new gl_journal_header;
  $gjh->ledger_id = $this->_ledger_id;
  $gjh->status = 'ENTERED';
  $gjh->currency = $gled->currency_code;

  if (!empty($this->exchange_rate) && !empty($this->currency)) {
   if ($gjh->currency != $this->currency) {
    echo "<br>GL Currency of ledger (" . $gjh->currency . ") and document " . $this->currency . ") does n't match ";
    $dbc->rollback = true;
    return -90;
   }
   $gjh->doc_currency = $this->doc_currency;
   $gjh->exchange_type = $this->exchange_rate_type;
   $gjh->exchange_rate = $this->exchange_rate;
  }

  $gjh->period_id = $current_open_period->gl_period_id;
  $gjh->journal_source = self::$module;
  $gjh->journal_category = self::$gl_journal_category;
  $gjh->reference_type = 'table';
  $gjh->reference_key_name = self::$table_name;
  $gjh->reference_key_value = $this->inv_transaction_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = 'A';
  $gjh->audit_trial();
  $gjh->gl_journal_header_id = null;
  if ($gjh->validate_requiredField()) {
   $gjh->save();
  } else {
   return;
  }
  $this->gl_journal_header_id = $gjh->gl_journal_header_id;
  echo "<br> The New Journal Header Id is " . $this->gl_journal_header_id;
  return $gjh->gl_journal_header_id;
 }

 private function _save_journal_lines($data_a) {
  $new_gjl = new gl_journal_line();
  $new_gjl->gl_journal_header_id = $this->gl_journal_header_id;
  $new_gjl->line_num = $data_a['line_number'];
  $new_gjl->status = 'U';
  $new_gjl->code_combination_id = $data_a['account_id'];
  if (($data_a['dr_cr']) == 'dr') {
   $new_gjl->total_dr = $data_a['amount'];
   if (!empty($this->exchange_rate)) {
    $new_gjl->total_ac_dr = $data_a['amount'] * $this->exchange_rate;
   } else {
    $new_gjl->total_ac_dr = $data_a['amount'];
   }
  } else {
   $new_gjl->total_cr = $data_a['amount'];
   if (!empty($this->exchange_rate)) {
    $new_gjl->total_ac_cr = $data_a['amount'] * $this->exchange_rate;
   } else {
    $new_gjl->total_ac_cr = $data_a['amount'];
   }
  }
  $new_gjl->description = 'Inv Transaction Id ' . $this->inv_transaction_id . ' item id ' . $this->item_id_m;
  $new_gjl->reference_type = 'table';
  $new_gjl->reference_key_name = 'inv_transaction';
  $new_gjl->reference_key_value = $this->inv_transaction_id;
  $new_gjl->audit_trial();
  $val_result = $new_gjl->validate_requiredField();
  if ($val_result) {
   $new_gjl->save();
  } else {
   return;
  }
//	$dbc->confirm();
 }

 private function _cretae_journal_line_array($element_value_a, $subinventory_id, $dr_cr, $line_number = '1') {
  $journal_line_a = [];
  $subinv = new subinventory();
  $subinv_i = $subinv->findBy_id($subinventory_id);
  $total_amount = 0;
  foreach ($element_value_a as $key => $value) {
   if (!empty($value)) {
    $total_amount += $value * $this->quantity;
    $journal_line['line_number'] = $line_number;
    $line_number++;
    $journal_line['amount'] = $value * $this->quantity;
    switch ($key) {
     case 'mat' :
      $journal_line['account_id'] = $subinv_i->material_ac_id;
      break;
     case 'moh' :
      $journal_line['account_id'] = $subinv_i->material_oh_ac_id;
      break;
     case 'oh' :
      $journal_line['account_id'] = $subinv_i->overhead_ac_id;
      break;
     case 'res' :
      $journal_line['account_id'] = $subinv_i->resource_ac_id;
      break;
     case 'osp' :
      $journal_line['account_id'] = $subinv_i->osp_ac_id;
      break;
     case 'default' :
      $journal_line['account_id'] = $subinv_i->material_ac_id;
      break;
    }
    $journal_line['dr_cr'] = $dr_cr;
    array_push($journal_line_a, $journal_line);
   }
  }
  return $journal_line_a;
 }

 private function _cretae_wipJournal_line_array($element_value_a, $wip_accounting_group_id, $dr_cr, $line_number = '999', $variance = false) {
  $journal_line_a = [];
  $wip_acg = new wip_accounting_group();
  $wip_acg->findBy_id($wip_accounting_group_id);
  $total_amount = 0;
  foreach ($element_value_a as $key => $value) {
   if (!empty($value)) {
    $total_amount += $value * $this->quantity;
    $journal_line['line_number'] = $line_number;
    $line_number++;
    $journal_line['amount'] = $value * $this->quantity;
    switch ($key) {
     case 'mat' :
      $journal_line['account_id'] = ($variance == true) ? $wip_acg->var_material_ac_id : $wip_acg->material_ac_id;
      break;
     case 'moh' :
      $journal_line['account_id'] = ($variance == true) ? $wip_acg->var_material_oh_ac_id : $wip_acg->material_oh_ac_id;
      break;
     case 'oh' :
      $journal_line['account_id'] = ($variance == true) ? $wip_acg->var_overhead_ac_id : $wip_acg->overhead_ac_id;
      break;
     case 'res' :
      $journal_line['account_id'] = ($variance == true) ? $wip_acg->var_resource_ac_id : $wip_acg->resource_ac_id;
      break;
     case 'osp' :
      $journal_line['account_id'] = ($variance == true) ? $wip_acg->var_osp_ac_id : $wip_acg->osp_ac_id;
      break;
     case 'default' :
      $journal_line['account_id'] = ($variance == true) ? $wip_acg->var_material_ac_id : $wip_acg->material_ac_id;
      break;
    }
    $journal_line['dr_cr'] = $dr_cr;
    array_push($journal_line_a, $journal_line);
   }
  }
  return $journal_line_a;
 }

 public function _after_save() {
  global $db;
  global $dbc;

  $onhand = new onhand();

  if ($this->_asset_create_journal) {
   $journal_line_a = [];
   $element_array = ['mat', 'moh', 'oh', 'res', 'osp'];
   foreach ($element_array as $key => $value) {
    $$value = 0;
   }

   $ich = new cst_item_cost_header();
   $ich->item_id_m = $this->item_id_m;
   $ich->bom_cost_type = 'FROZEN';
   $ich->org_id = $this->org_id;
   $ich_i = $ich->findBy_ItemId_orgId_CostType();
   $icl = new cst_item_cost_line();
   if (!empty($ich_i)) {
    $icl_i = $icl->findBy_parentId($ich_i->cst_item_cost_header_id);
   } else {
    echo "<div class='message'>Frozen cost is not available for the entered item id $ich->item_id_m</div>";
    $dbc->rollback = true;
    return;
   }
   if (!empty($icl_i)) {
    foreach ($icl_i as $cost_lines) {
     $mat += array_search('MAT', ((array) $cost_lines)) ? $cost_lines->amount : 0;
     $moh += array_search('MOH', ((array) $cost_lines)) ? $cost_lines->amount : 0;
     $oh += array_search('OH', ((array) $cost_lines)) ? $cost_lines->amount : 0;
     $res += array_search('RES', ((array) $cost_lines)) ? $cost_lines->amount : 0;
     $osp += array_search('OSP', ((array) $cost_lines)) ? $cost_lines->amount : 0;
    }
   }
   $element_value_a = ['mat' => $mat, 'moh' => $moh, 'oh' => $oh, 'res' => $res, 'osp' => $osp];
  }

  switch ($this->transaction_type_id) {
   case 1 :
   case 6 :
   case 12 :
   case 13 :
   case 15 :
   case 16 :
   case 18 :
   case 19 :
   case 21 :
   case 22 :
   case 24 :
   case 29 :
    $onhand->setProperty('_from_org_id', $this->org_id);
    $onhand->setProperty('_from_subinventory_id', $this->from_subinventory_id);
    $onhand->setProperty('_from_locator_id', $this->from_locator_id);
    $onhand->setProperty('_transaction_quantity', $this->quantity);
    $onhand->item_id_m = $this->item_id_m;
    $onhand->revision_name = $this->revision_name;
    $onhand->d_reference_key_name = $this->d_reference_key_name;
    $onhand->d_reference_key_value = $this->d_reference_key_value;
    $onhand->s_reference_key_name = $this->s_reference_key_name;
    $onhand->s_reference_key_value = $this->s_reference_key_value;
    $update_result = $onhand->updateOnhand();
    $this->_onhand_id_from = $update_result->onhand_id;
    if (!$this->_asset_create_journal) {
     break;
    }
    //create journals for Misc Issue/ WIP Return - from locations
    $journal_line_a = $this->_cretae_journal_line_array($element_value_a, $this->from_subinventory_id, 'cr', 1);

    //Dr accounting
    //wip transactions
    $line_number = 1;
    if (in_array($this->transaction_type_id, array(6, 12, 13, 24, 29))) {
     $line_number = 1;
     foreach ($journal_line_a as $journal_line) {
      if ($journal_line['line_number'] > $line_number) {
       $line_number = $journal_line['line_number'];
      }
     }
     $line_number++;
     //get journal lines from wip
     if (empty($this->_wip_accounting_group_id) && !empty($this->wip_wo_header_id)) {
      $woh = new wip_wo_header();
      $woh->findBy_id($this->wip_wo_header_id);
      $this->_wip_accounting_group_id = $woh->wip_accounting_group_id;
     } else if (empty($this->_wip_accounting_group_id) && !empty($this->pm_batch_header_id)) {
      $pm_bh = new pm_batch_header();
      $pm_bh->findBy_id($this->pm_batch_header_id);
      $this->_wip_accounting_group_id = $pm_bh->wip_accounting_group_id;
     }
     $wip_journal_line_a = $this->_cretae_wipJournal_line_array($element_value_a, $this->_wip_accounting_group_id, 'dr', $line_number);
     $journal_line_a = array_merge($journal_line_a, $wip_journal_line_a);
    }

    //form misc issue - debit the entered account
    if (in_array($this->transaction_type_id, array(1, 16, 18, 19))) {
     $total_amount = 0;
     $line_number = 1;
     foreach ($journal_line_a as $journal_line) {
      $total_amount += $journal_line['amount'];
      if ($journal_line['line_number'] > $line_number) {
       $line_number = $journal_line['line_number'];
      }
     }
     $line_number++;
     if (!empty($total_amount)) {
      $journal_line['line_number'] = $line_number;
      $journal_line['amount'] = $total_amount;
      $journal_line['account_id'] = $this->account_id;
      $journal_line['dr_cr'] = 'dr';
      array_push($journal_line_a, $journal_line);
     }
    }
//for SO Shipment Debit the COGS account
    if ($this->transaction_type_id == 15 || $this->transaction_type_id == 22) {
     if (empty($this->_dr_ac_id)) {
      $inv = new inventory();
      $inv_i = $inv->findBy_org_id($this->org_id);
      $this->_dr_ac_id = $inv_i->cogs_ac_id;
     }
     $total_amount = 0;
     $line_number = 1;
     foreach ($journal_line_a as $journal_line) {
      $total_amount += $journal_line['amount'];
      if ($journal_line['line_number'] > $line_number) {
       $line_number = $journal_line['line_number'];
      }
     }
     $line_number++;
     if (!empty($total_amount)) {
      $journal_line['line_number'] = $line_number;
      $journal_line['amount'] = $total_amount;
      $journal_line['account_id'] = $this->_dr_ac_id;
      $journal_line['dr_cr'] = 'dr';
      array_push($journal_line_a, $journal_line);
     }
    }
    break;

   case 2 :
   case 5 :
   case 7 :
   case 10 :
   case 11 :
   case 17 :
   case 20 :
   case 23 :
   case 25 :
   case 30 :
   case 33 :
    $onhand->setProperty('_to_org_id', $this->org_id);
    $onhand->setProperty('_to_subinventory_id', $this->to_subinventory_id);
    $onhand->setProperty('_to_locator_id', $this->to_locator_id);
    $onhand->setProperty('_transaction_quantity', $this->quantity);
    $onhand->item_id_m = $this->item_id_m;
    $onhand->revision_name = $this->revision_name;
    $onhand->d_reference_key_name = $this->d_reference_key_name;
    $onhand->d_reference_key_value = $this->d_reference_key_value;
    $onhand->s_reference_key_name = $this->s_reference_key_name;
    $onhand->s_reference_key_value = $this->s_reference_key_value;
    $update_result = $onhand->updateOnhand();
    $this->_onhand_id_to = $update_result->onhand_id;
    if (!$this->_asset_create_journal) {
     break;
    }
    //create Dr journals lines
    $journal_line_a = $this->_cretae_journal_line_array($element_value_a, $this->to_subinventory_id, 'dr', 1);


    //cretae Cr journal line
    if ($this->transaction_type_id == 5) {
     $po_v = new po_all_v();
     $po_v->po_detail_id = $this->po_detail_id;
     $po_v_i = $po_v->findBy_poDetailId();
     $accural_amount = $this->quantity * ($po_v_i->gl_line_price / $po_v_i->line_quantity);
     $total_amount = 0;
     $line_number = 1;
     foreach ($journal_line_a as $journal_line) {
      $total_amount += $journal_line['amount'];
      if ($journal_line['line_number'] > $line_number) {
       $line_number = $journal_line['line_number'];
      }
     }
     $line_number++;
     if (!empty($accural_amount)) {
      $journal_line['line_number'] = $line_number;
      $journal_line['amount'] = $accural_amount;
      $journal_line['account_id'] = $po_v_i->accrual_ac_id;
      $journal_line['dr_cr'] = 'cr';
      array_push($journal_line_a, $journal_line);
     }

     //PPV if the Accrual & Standard Cost Amounts are different
     if ($accural_amount - $total_amount != 0) {
      $line_number++;
      $ppv_amount = abs($accural_amount - $total_amount);
      $journal_line['line_number'] = $line_number;
      $journal_line['amount'] = $ppv_amount;
      $journal_line['account_id'] = $po_v_i->ppv_ac_id;
      if ($accural_amount - $total_amount > 0) {
       $journal_line['dr_cr'] = 'dr';
      } else {
       $ppv_amount = abs($ppv_amount);
       $journal_line['dr_cr'] = 'cr';
      }
      array_push($journal_line_a, $journal_line);
     }
    }

    if (in_array($this->transaction_type_id, array(7, 10, 11, 30))) {
     $line_number = 1;
     foreach ($journal_line_a as $journal_line) {
      if ($journal_line['line_number'] > $line_number) {
       $line_number = $journal_line['line_number'];
      }
     }
     $line_number++;
     //get journal lines from wip
     if (empty($this->_wip_accounting_group_id) && !empty($this->wip_wo_header_id)) {
      $woh = new wip_wo_header();
      $woh->findBy_id($this->wip_wo_header_id);
      $this->_wip_accounting_group_id = $woh->wip_accounting_group_id;
     }

     if (empty($this->_wip_accounting_group_id) && !empty($this->am_wo_header_id)) {
      $woh = new wip_wo_header();
      $woh->findBy_id($this->am_wo_header_id);
      $this->_wip_accounting_group_id = $woh->wip_accounting_group_id;
     }

     if (empty($this->_wip_accounting_group_id) && !empty($this->pm_batch_header_id)) {
      $pm_bh = new pm_batch_header();
      $pm_bh->findBy_id($this->pm_batch_header_id);
      $this->_wip_accounting_group_id = $pm_bh->wip_accounting_group_id;
     }

     $wip_journal_line_a = $this->_cretae_wipJournal_line_array($element_value_a, $this->_wip_accounting_group_id, 'cr', $line_number);
     $journal_line_a = array_merge($journal_line_a, $wip_journal_line_a);
    }

    //start of cr
    $cr_inv_receving_trnx_a = [2, 17, 23];
    if (!empty($this->_cr_amount) && ($this->transaction_type_id == 20 || $this->transaction_type_id == 33)) {
     $this->_journal_line_for_cr_adjustmet_amount($journal_line_a);
    } else if ($this->transaction_type_id == 20) {
     array_push($cr_inv_receving_trnx_a, 20);
    }else if ($this->transaction_type_id == 33) {
     array_push($cr_inv_receving_trnx_a, 33);
    }
    if (in_array($this->transaction_type_id, $cr_inv_receving_trnx_a)) {
     $total_amount = 0;
     $line_number = 1;
     foreach ($journal_line_a as $journal_line) {
      $total_amount += $journal_line['amount'];
      if ($journal_line['line_number'] > $line_number) {
       $line_number = $journal_line['line_number'];
      }
     }
     $line_number++;
     if (!empty($total_amount)) {
      $journal_line['line_number'] = $line_number;
      $journal_line['amount'] = $total_amount;
      if ($this->transaction_type_id == 23) {
       $inv_d1 = inventory::find_by_org_id($this->org_id);
       if (!empty($inv_d1->cogs_ac_id)) {
        $journal_line['account_id'] = $inv_d1->cogs_ac_id;
       }
      } else {
       $journal_line['account_id'] = $this->account_id;
      }
      $journal_line['dr_cr'] = 'cr';
      array_push($journal_line_a, $journal_line);
     }
    }


    if ($this->transaction_type_id == 21) {
     $this->_after_save_po_return($journal_line_a);
    }

//    if ($this->transaction_type_id == 23) {
//     $this->_after_save_rmaReceipt();
//    }
    break;

   case 3 :
   case 14 :
   case 26 :
    $onhand->setProperty('_from_subinventory_id', $this->from_subinventory_id);
    $onhand->setProperty('_from_locator_id', $this->from_locator_id);
    $onhand->setProperty('_to_subinventory_id', $this->to_subinventory_id);
    $onhand->setProperty('_to_locator_id', $this->to_locator_id);
    $onhand->setProperty('_transaction_quantity', $this->quantity);
    $onhand->item_id_m = $this->item_id_m;
    $onhand->revision_name = $this->revision_name;
    $onhand->org_id = $this->org_id;
    $onhand->d_reference_key_name = $this->d_reference_key_name;
    $onhand->d_reference_key_value = $this->d_reference_key_value;
    $onhand->s_reference_key_name = $this->s_reference_key_name;
    $onhand->s_reference_key_value = $this->s_reference_key_value;
    $update_result = $onhand->updateOnhand();
    $this->_onhand_id_from = $update_result->onhand_id_from;
    $this->_onhand_id_to = $update_result->onhand_id_to;
    if (!$this->_asset_create_journal) {
     break;
    }
    $journal_line_from_a = $this->_cretae_journal_line_array($element_value_a, $this->from_subinventory_id, 'cr', 1);
    $line_number = 1;
    foreach ($journal_line_from_a as $journal_line) {
     if ($journal_line['line_number'] > $line_number) {
      $line_number = $journal_line['line_number'];
     }
    }
    $line_number++;
    $journal_line_to_a = $this->_cretae_journal_line_array($element_value_a, $this->to_subinventory_id, 'dr', $line_number);
    $journal_line_a = array_merge($journal_line_from_a, $journal_line_to_a);
    break;

   default:
    break;
  }

  if ($update_result->update_status > 0) {
   $this->status = 'Success';
  }

  if ($this->_asset_create_journal && $this->_gl_transaction) {
   try {
    $this->_save_journal_header();
    foreach ($journal_line_a as $journal_lines) {
     $this->_save_journal_lines($journal_lines);
    }
   } catch (Exception $e) {
    $dbc->rollback = 1;
    echo "<br> Failed to update Journal details. Issue @ inv_transaction @@ Line " . __LINE__;
   }
  }
  //update the transaction status
  $this->save();

  //update the item issue quantity on WO
  if (($this->transaction_type_id == 6) && (!empty($this->wip_wo_bom_id))) {
   //update issued quantity
   $wo_bom = new wip_wo_bom();
   $wo_bom_i = $wo_bom->findBy_id($this->wip_wo_bom_id);
   $wo_bom->wip_wo_bom_id = $this->wip_wo_bom_id;
   $wo_bom->issued_quantity = $wo_bom_i->issued_quantity + $this->quantity;
   $wo_bom->save();
  }

  //update the item issue quantity on Batch
  if (($this->transaction_type_id == 29) && (!empty($this->pm_batch_ingredient_id))) {
   //update issued quantity
   $pm_batch_ing_i = new pm_batch_ingredient();
   $pm_batch_ing_j = $pm_batch_ing_i->findBy_id($this->pm_batch_ingredient_id);
   $pm_batch_ing_i->pm_batch_ingredient_id = $this->pm_batch_ingredient_id;
   $pm_batch_ing_i->actual_quantity = $pm_batch_ing_j->actual_quantity + $this->quantity;
   $pm_batch_ing_i->save();
  }

  //update the item return quantity on WO
  if (($this->transaction_type_id == 7) && (!empty($this->wip_wo_bom_id))) {
   //update return quantity
   $wo_bom = new wip_wo_bom();
   $wo_bom_i = $wo_bom->findBy_id($this->wip_wo_bom_id);
   $wo_bom->wip_wo_bom_id = $this->wip_wo_bom_id;
   $wo_bom->issued_quantity = $wo_bom_i->issued_quantity - $this->quantity;
   $wo_bom->audit_trial();
   $wo_bom->save();
  }

  //update the item return quantity on Batch
  if (($this->transaction_type_id == 30) && (!empty($this->pm_batch_ingredient_id))) {
   //update issued quantity
   $pm_batch_ing_i = new pm_batch_ingredient();
   $pm_batch_ing_j = $pm_batch_ing_i->findBy_id($this->pm_batch_ingredient_id);
   $pm_batch_ing_i->pm_batch_ingredient_id = $this->pm_batch_ingredient_id;
   $pm_batch_ing_i->actual_quantity = $pm_batch_ing_j->actual_quantity - $this->quantity;
   $pm_batch_ing_i->save();
  }

  //update the item issue quantity on WO
  if (in_array($this->transaction_type_id, array(24, 25)) && (!empty($this->am_wo_bom_id))) {
   //update issued quantity
   $this->_am_wo_update_quantity();
  }


  //update on WO Completion
  if (($this->transaction_type_id == 11) && (!empty($this->document_id))) {
   //update issued quantity
   $wip_woh = new wip_wo_header();
   $wip_woh_i = $wip_woh->findBy_id($this->document_id);
   $wip_woh->wip_wo_header_id = $wip_woh_i->wip_wo_header_id;
   $wip_woh->completed_quantity = $wip_woh_i->completed_quantity + $this->quantity;
   $wip_woh->audit_trial();
   $wip_woh->last_unit_completed_date = $wip_woh->last_update_date;
   if (empty($wip_woh_i->first_unit_completed_date)) {
    $wip_woh->first_unit_completed_date = $wip_woh->last_unit_completed_date;
   }
   if ($wip_woh->completed_quantity == $wip_woh->quantity) {
    $wip_woh->set_wo_status = 'COMPLETED';
   }

   $wip_woh->save();

   //update the to_move qty of last operation
   $last_wo_routing_line = wip_wo_routing_line::find_lastOperation_by_wip_wo_headerId($this->document_id);
   $update_wo_routing_line = new wip_wo_routing_line;
   $update_wo_routing_line->wip_wo_routing_line_id = $last_wo_routing_line->wip_wo_routing_line_id;
   $update_wo_routing_line->tomove_quantity = $last_wo_routing_line->tomove_quantity - $this->quantity;
   $update_wo_routing_line->save();

   /* Start material transaction - issue all WIP Assembly Completion materials */
   $all_bom_lines = wip_wo_bom::find_by_wip_wo_headerId($this->document_id);
   $org_id = $this->org_id;
   $quantity = $this->quantity;
   $document_number = $this->document_number;
   $document_id = $this->document_id;
   foreach ($all_bom_lines as $bomline) {
    if ($bomline->wip_supply_type == 'ASSEMBLY_PULL') {
     $inv_transaction = new inv_transaction;
     $inv_transaction->org_id = $org_id;
     $inv_transaction->transaction_type_id = 6;
     $inv_transaction->item_id_m = $bomline->component_item_id_m;
     $item = item::find_by_id($inv_transaction->item_id_m);
     $inv_transaction->uom_id = $item->uom_id;
     $inv_transaction->item_number = $item->item_number;
     $inv_transaction->quantity = $bomline->usage_quantity * $quantity;
     $inv_transaction->from_subinventory_id = $bomline->supply_sub_inventory;
     $inv_transaction->from_locator_id = $bomline->supply_locator;
     $inv_transaction->document_type = 'Work Order';
     $inv_transaction->document_number = $document_number;
     $inv_transaction->reference = 'wip_wo_header_id';
     $inv_transaction->wip_wo_bom_id = $bomline->wip_wo_bom_id;
     $inv_transaction->document_id = $document_id;
     $inv_transaction->_before_save();
     $inv_transaction->save();
     $inv_transaction->_after_save();
    }
   }
  }

  //update on WO Return
  if (($this->transaction_type_id == 13) && (!empty($this->document_id))) {
   //update issued quantity
   $wip_woh = new wip_wo_header();
   $wip_woh_i = $wip_woh->findBy_id($this->document_id);
   $wip_woh->wip_wo_header_id = $wip_woh_i->wip_wo_header_id;
   $wip_woh->completed_quantity = $wip_woh_i->completed_quantity - $this->quantity;
   $wip_woh->audit_trial();
   $wip_woh->last_unit_completed_date = $wip_woh->last_update_date;
   if (empty($wip_woh_i->first_unit_completed_date)) {
    $wip_woh->first_unit_completed_date = $wip_woh->last_unit_completed_date;
   }
   if ($wip_woh->completed_quantity == $wip_woh->quantity) {
    $wip_woh->set_wo_status = 'COMPLETED';
   }
   $wip_woh->save();

   //update the to_move qty of last operation
   $last_wo_routing_line = wip_wo_routing_line::find_lastOperation_by_wip_wo_headerId($this->document_id);
   $update_wo_routing_line = new wip_wo_routing_line;
   $update_wo_routing_line->wip_wo_routing_line_id = $last_wo_routing_line->wip_wo_routing_line_id;
   $update_wo_routing_line->audit_trial();
   $update_wo_routing_line->tomove_quantity = $last_wo_routing_line->tomove_quantity + $this->quantity;
   $update_wo_routing_line->save();

   /* Start material transaction - issue all WIP Assembly Completion materials */
   $all_bom_lines = wip_wo_bom::find_by_wip_wo_headerId($this->document_id);
   $org_id = $this->org_id;
   $quantity = $this->quantity;
   $document_number = $this->document_number;
   $document_id = $this->document_id;
   foreach ($all_bom_lines as $bomline) {
    if ($bomline->wip_supply_type == 'ASSEMBLY_PULL') {
     $inv_transaction = new inv_transaction;
     $inv_transaction->org_id = $org_id;
     $inv_transaction->transaction_type_id = 7;
     $inv_transaction->item_id_m = $bomline->component_item_id_m;
     $item = item::find_by_orgId_item_id_m($inv_transaction->item_id_m, $this->org_id);
     if (!empty($item->serial_generation)) {
      echo "<br>No Material Issue for serial controlled items";
      return;
     }
     $inv_transaction->uom_id = $item->uom_id;
     $inv_transaction->item_number = $item->item_number;
     $inv_transaction->quantity = $bomline->usage_quantity * $quantity;
     $inv_transaction->to_subinventory_id = $bomline->supply_sub_inventory;
     $inv_transaction->to_locator_id = $bomline->supply_locator;
     $inv_transaction->document_type = 'Work Order';
     $inv_transaction->document_number = $document_number;
     $inv_transaction->reference = 'wip_wo_header_id';
     $inv_transaction->wip_wo_bom_id = $bomline->wip_wo_bom_id;
     $inv_transaction->document_id = $document_id;
     $inv_transaction->_before_save();
     $inv_transaction->save();
     $inv_transaction->_after_save();
    }
   }
  }

  //update serial transaction
  if ($this->_transact_serial_number() < 0) {
   return -99;
  }

  //update lot transaction
  if ($this->_transact_lot_number() < 0) {
   return -99;
  }

  if (method_exists($this, '_after_save_2')) {
   $this->_after_save_2();
  }
 }

 private function _am_wo_update_quantity() {
  $wo_bom = new am_wo_bom();
  $wo_bom->findBy_id($this->am_wo_bom_id);
  $wo_bom->am_wo_bom_id = $this->am_wo_bom_id;
  if ($this->transaction_type_id == 24) {
   $wo_bom->issued_quantity += $this->quantity;
  } else if ($this->transaction_type_id == 25) {
   $wo_bom->issued_quantity -= $this->quantity;
  }

  $wo_bom->save();
 }

 private function _after_save_po_return(&$journal_line_a) {
  $po_v = new po_all_v();
  $po_v->po_detail_id = $this->po_detail_id;
  $po_v_i = $po_v->findBy_poDetailId();
  $accural_amount = $this->quantity * ($po_v_i->gl_line_price / $po_v_i->line_quantity);
  $total_amount = 0;
  $line_number = 1;
  foreach ($journal_line_a as $journal_line) {
   $total_amount += $journal_line['amount'];
   if ($journal_line['line_number'] > $line_number) {
    $line_number = $journal_line['line_number'];
   }
  }
  $line_number++;
  if (!empty($accural_amount)) {
   $journal_line['line_number'] = $line_number;
   $journal_line['amount'] = $accural_amount;
   $journal_line['account_id'] = $po_v_i->accrual_ac_id;
   $journal_line['dr_cr'] = 'dr';
   array_push($journal_line_a, $journal_line);
  }

  //PPV if the Accrual & Standard Cost Amounts are different
  if ($accural_amount - $total_amount != 0) {
   $line_number++;
   $ppv_amount = $accural_amount - $total_amount;
   $journal_line['line_number'] = $line_number;
   $journal_line['amount'] = $ppv_amount;
   $journal_line['account_id'] = $po_v_i->ppv_ac_id;
   if ($ppv_amount > 0) {
    $journal_line['dr_cr'] = 'cr';
   } else {
    $journal_line['dr_cr'] = 'dr';
   }
   array_push($journal_line_a, $journal_line);
  }
 }

 private function _journal_line_for_cr_adjustmet_amount(&$journal_line_a) {
  $total_amount = 0;
  $line_number = 1;
  foreach ($journal_line_a as $journal_line) {
   $total_amount += $journal_line['amount'];
   if ($journal_line['line_number'] > $line_number) {
    $line_number = $journal_line['line_number'];
   }
  }
  $line_number++;
  $ppv_amount = $this->_cr_amount - $total_amount;
  if (!empty($total_amount) || !empty($this->_cr_amount)) {
   $journal_line['line_number'] = $line_number;
   $journal_line['amount'] = !empty($this->_cr_amount) ? ($this->_cr_amount) : $total_amount;
   $journal_line['account_id'] = $this->account_id;
   $journal_line['dr_cr'] = 'cr';
   array_push($journal_line_a, $journal_line);
  }

  if ($ppv_amount != 0) {
   $line_number++;
   $journal_line['line_number'] = $line_number;
   $inv = inventory::find_by_org_id($this->org_id);
   $journal_line['account_id'] = $inv->inter_org_ppv_ac_id;
   if ($ppv_amount > 0) {
    $journal_line['dr_cr'] = 'dr';
   } else {
    $journal_line['dr_cr'] = 'cr';
   }
   $journal_line['amount'] = abs($ppv_amount);
   array_push($journal_line_a, $journal_line);
  }
 }

//  private function _verify_serial_reservation($inv_serial_number_id) {
//  $sql = "SELECT * FROM ";
//  $sql .= self::$table_name;
//  $sql .= " WHERE   reference_key_name = '{$refname}' AND  reference_key_value ='{$refvalue}' LIMIT 1";
//  $result = self::find_by_sql($sql);
//  return !empty($result) ? ($result) : false;
// }

 public static function find_by_refName_refValue($refname, $refvalue) {
  $sql = "SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE   reference_key_name = '{$refname}' AND  reference_key_value ='{$refvalue}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of inv_transaction class
inv_transaction::staticVar_init('allowed_inv_transactions');
?>
