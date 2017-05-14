<?php

class inv_intorg_transfer_line extends dbObject {

 public static $table_name = "inv_intorg_transfer_line";
 public static $primary_column = "inv_intorg_transfer_line_id";
 public static $parent_primary_column = "inv_intorg_transfer_header_id";
// public static $multi_select_template_path = "modules/inv/interorg_transfer/interorg_transfer_template.php";
// public static $multi_search_primary_column = "inv_intorg_transfer_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'item_id_m';
 public static $module = "inv";
 public static $status_a = [
  'ENTERED' => 'Entered',
  'SHIPPED' => 'Shipped',
  'RECEIVED' => 'Received',
  'ERROR' => 'Error'
 ];
 public $field_a = [
  'inv_intorg_transfer_line_id',
  'inv_intorg_transfer_header_id',
  'transaction_type_id',
  'line_number',
  'from_subinventory_id',
  'from_locator_id',
  'item_id_m',
  'revision_name',
  'item_description',
  'status',
  'uom_id',
  'to_subinventory_id',
  'to_locator_id',
  'transaction_quantity',
  'description',
  'reason',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'received_quantity',
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
  'item_number',
  'item_description',
  'from_current_onhand',
  'from_future_onhand',
  'to_current_onhand',
  'to_future_onhand',
  'serial_generation',
  'serial_number',
  'inv_serial_number_id',
  'lot_generation',
  'lot_number',
  'lot_number_id',
  'serial_number_id',
  'action'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "inv_intorg_transfer_header_id",
  'from_org_id',
  'to_org_id',
 ];
 public $requiredField = [
  'inv_intorg_transfer_header_id',
  'transaction_type_id',
  'from_locator_id',
  'item_id_m',
   'uom_id',
  'to_subinventory_id',
  'transaction_quantity',
 ];
 public $inv_intorg_transfer_line_id;
 public $inv_intorg_transfer_header_id;
 public $transaction_type_id;
 public $line_number;
 public $from_subinventory_id;
 public $from_locator_id;
 public $item_id_m;
 public $revision_name;
 public $item_description;
 public $item_number;
 public $status;
 public $uom_id;
 public $to_subinventory_id;
 public $to_locator_id;
 public $transaction_quantity;
 public $received_quantity;
 public $description;
 public $reason;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $country_of_origin;
 public $lot_number_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $from_current_onhand;
 public $from_future_onhand;
 public $to_current_onhand;
 public $to_future_onhand;
 public $lot_number;
 public $serial_number;
 public $serial_number_id;
 public $inv_serial_number_id;
 public $serial_generation;
 public $lot_generation;
 public $action;

 public function _after_save() {
  if ($this->transaction_type_id == '18') {
   if (!empty($this->inv_intorg_transfer_line_id)) {
    $update_satus = 1;
    try {
     if (!empty($this->item_id_m)) {
      try {
       $ret_val = $this->_create_inv_transactions_directTransfer();
       echo "<br>INV Transaction Lines are Successfully Created ";
      } catch (Exception $e) {
       $update_satus = -99;
       echo "<br>Creating the transaction lines failed @ inv_intorg_transfer_line after save" . $e->getMessage();
      }
     }
    } catch (Exception $e) {
     $update_satus = -99;
     echo "<br>PO Detail Update Failed! interorg_transfer Line Error @ " . __LINE__ . $e->getMessage();
    }
    if ($update_satus > 0 && $ret_val > 0) {
     $this->status = 'RECEIVED';
    } else {
     $this->status = 'ERROR';
    }
    $this->save();
   }
  }

  if ($this->transaction_type_id == '19') {
//   pa($this);
   $this->_after_save_for_intransitTransfer();
  }
 }

 public function _before_save() {

  if ((!empty($this->status) && ($this->status == 'RECEIVED' || $this->status == 'SHIPPED'))) {
   $this->status = 'ENTERED';
   echo "<br>You can't update any interorg_transfer line.Create a reverse transaction, if required ";
   return 10;
  } else if ((empty($this->status) && ($this->transaction_type_id == '19'))) {
   $this->status = 'ENTERED';
  }

  //if there is a line id in the form then return 10 as no changes to direct transfer lines are allowed
  if ($this->inv_intorg_transfer_line_id && $this->transaction_type_id != '19') {
   echo "<br>You can't update any interorg_transfer line.Create a reverse transaction, if required ";
   return 10;
  }
 }

 private function _after_save_for_intransitTransfer() {

  switch ($this->action) {
   case 'SHIP' :
    try {
     $this->_create_inv_transactions_indirectTransfer();
     $this->status = 'SHIPPED';
     echo "<br>INV Transaction lines are Successfully Created for Inter Org shipment ";
    } catch (Exception $e) {
     $this->status = 'ERROR';
     echo "<br>Creating the transaction lines failed @ " . __FILE__ . ' line ' . __LINE__ . '<br>' . $e->getMessage();
    }
    break;

   default :
    break;
  }
  $this->save();
 }

 private function _create_inv_transactions_directTransfer() {
  $ioh = new inv_intorg_transfer_header();
  $return_val = 1;
  $ioh->findBy_id($this->inv_intorg_transfer_header_id);

  $inv_transaction_from = new inv_transaction();
  $inv_transaction_to = new inv_transaction();

  switch ($this->transaction_type_id) {
   case 18 :
    $inv_transaction_from->org_id = $ioh->from_org_id;
    $inv_transaction_from->from_subinventory_id = $this->from_subinventory_id;
    if (!empty($this->from_locator_id)) {
     $inv_transaction_from->from_locator_id = $this->from_locator_id;
    }
    $inv_transaction_from->quantity = $this->transaction_quantity;
    $inv_transaction_from->item_id_m = $this->item_id_m;
    $from_org = inventory::find_by_org_id($ioh->from_org_id);
    $inv_transaction_from->account_id = $from_org->inter_org_receivable_ac_id;
    $inv_transaction_from->transaction_type_id = $ioh->transaction_type_id;
    $inv_transaction_from->reference_type = 'table';
    $inv_transaction_from->reference_key_name = 'inv_intorg_transfer_line';
    $inv_transaction_from->reference_key_value = $this->inv_intorg_transfer_line_id;
    $inv_transaction_from->document_type = 'Inter-Org Transfer';
    $inv_transaction_from->document_number = $ioh->order_number;
    try {
     $inv_transaction_from->_before_save();
     $inv_transaction_from->save();
     $inv_transaction_from->_after_save();
    } catch (Exception $e) {
     $return_val = -1;
     echo "<br>Failed to update from inventory transaction. Error @ " . __FILE__ . ' @@ line ' . __LINE__ . '<br>' . $e->getMessage();
     return $return_val;
    }


    $inv_transaction_to->org_id = $ioh->to_org_id;
    /* credit value
     * If currency is same then use the same standard cost else use the conversion
     */
    $inventory = new inventory();
    $from_inventory = $inventory->findRelatedDetail_ByOrgId($ioh->from_org_id);
    $from_currency = $from_inventory->currency_code;
    $to_inventory = $inventory->findRelatedDetail_ByOrgId($ioh->to_org_id);
    $to_currency = $to_inventory->currency_code;
    $stnd_cost = cst_item_cost_v::find_cost_by_itemId_orgId($this->item_id_m, $ioh->from_org_id)->standard_cost;
    $cr_amount = $stnd_cost * $this->transaction_quantity;
    if ($from_currency != $to_currency) {
     $rate = gl_currency_conversion::find_rate($from_currency, $to_currency);
     $cr_amount = $cr_amount * $rate;
    }
    $inv_transaction_to->setProperty('_cr_amount', $cr_amount);
    $inv_transaction_to->to_subinventory_id = $this->to_subinventory_id;
    if (!empty($this->to_locator_id)) {
     $inv_transaction_to->to_locator_id = $this->to_locator_id;
    }
    $inv_transaction_to->quantity = $this->transaction_quantity;
    $inv_transaction_to->item_id_m = $this->item_id_m;
    $to_org = inventory::find_by_org_id($ioh->to_org_id);
//    pa($to_org);
    $inv_transaction_to->account_id = $to_org->inter_org_payable_ac_id;
    $inv_transaction_to->transaction_type_id = 20;
    $inv_transaction_to->reference_type = 'table';
    $inv_transaction_to->reference_key_name = 'inv_intorg_transfer_line';
    $inv_transaction_to->reference_key_value = $this->inv_intorg_transfer_line_id;
    $inv_transaction_to->document_type = 'Inter-Org Transfer';
    $inv_transaction_to->document_number = $ioh->order_number;
    try {
     $inv_transaction_to->_before_save();
     $inv_transaction_to->save();
     $inv_transaction_to->_after_save();
    } catch (Exception $e) {
     $return_val = -1;
     echo "<br>Failed to update to inventory transaction. Error @ " . __FILE__ . ' @@ line ' . __LINE__ . '<br>' . $e->getMessage();
     return $return_val;
    }
    break;

   default:
    break;
  }

  return $return_val;
 }

 private function _create_inv_transactions_indirectTransfer() {
  $ioh = new inv_intorg_transfer_header();
  $ioh->findBy_id($this->inv_intorg_transfer_header_id);
  $return_val = 1;
  $inv_transaction_from = new inv_transaction();
  $inv_transaction_to = new inv_transaction();

  switch ($this->transaction_type_id) {
   case 19 :
    $inv_transaction_from->org_id = $ioh->from_org_id;
    $inv_transaction_from->from_subinventory_id = $this->from_subinventory_id;
    if (!empty($this->from_locator_id)) {
     $inv_transaction_from->from_locator_id = $this->from_locator_id;
    }
    $from_org = inventory::find_by_org_id($ioh->from_org_id);
    $inv_transaction_from->account_id = $from_org->inter_org_receivable_ac_id;
    $inv_transaction_from->quantity = $this->transaction_quantity;
    $inv_transaction_from->item_id_m = $this->item_id_m;
    $inv_transaction_from->transaction_type_id = $ioh->transaction_type_id;
    $inv_transaction_from->reference_type = 'table';
    $inv_transaction_from->reference_key_name = 'inv_intorg_transfer_line';
    $inv_transaction_from->reference_key_value = $this->inv_intorg_transfer_line_id;
    $inv_transaction_from->document_type = 'Inter-Org Transfer';
    $inv_transaction_from->document_number = $ioh->order_number;
    try {
     $inv_transaction_from->_before_save();
     $inv_transaction_from->save();
     $inv_transaction_from->_after_save();
    } catch (Exception $e) {
     $return_val = -1;
     echo "<br>Failed to update to inventory transaction. Error @ " . __FILE__ . ' @@ line ' . __LINE__ . '<br>' . $e->getMessage();
     return $return_val;
    }

    break;

   default:
    break;
  }

  return $return_val;
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
   'inv_intorg_transfer_header_id',
   'mode',
   'action',
   'po_status',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of inv_intorg_transfer_line class
?>