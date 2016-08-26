<?php

class wip_wol_transaction_line extends dbObject {

 public static $table_name = "inv_transaction";
 public static $primary_column = "inv_transaction_id";
 public static $key_column = 'item_id_m';
 public static $module = "wip";
 public $field_a = [
  'wip_wo_bom_id',
  'wip_wo_header_id',
  'bom_sequence',
  'routing_sequence',
  'component_item_id_m',
  'usage_basis',
  'usage_quantity',
  'yield',
  'wip_supply_type',
  'supply_sub_inventory',
  'supply_locator',
  'required_quantity',
  'issued_quantity',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $wip_wo_bom_id;
 public $wip_wo_header_id;
 public $bom_sequence;
 public $routing_sequence;
 public $component_item_id_m;
 public $usage_basis;
 public $usage_quantity;
 public $yield;
 public $required_quantity;
 public $issued_quantity;
 public $wip_supply_type;
 public $supply_sub_inventory;
 public $supply_locator;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $component_item_number;
 public $component_description;
 public $component_uom;
 public $open_quantity;
 public $lot_number;
 public $serial_number;
 public $inv_serial_number_id;
 public $serial_number_id;
 public $serial_generation;
 public $lot_generation;
 private $_serial_type;
 public $wip_wol_transaction_id;
 public $transaction_type_id;
 public $org_id;

// public function _after_save() {
//  if (!empty($this->inv_intorg_transfer_line_id)) {
//   $update_satus = 0;
//   try {
//    if (!empty($this->item_id_m)) {
//     try {
//      $this->_create_inv_transactions();
//      echo "<br>INV Transaction Lines are Successfully Created ";
//     } catch (Exception $e) {
//      $update_satus = -99;
//      echo "<br>Creating the transaction lines failed @ inv_intorg_transfer_line after save" . $e->getMessage();
//     }
//    }
//   } catch (Exception $e) {
//    $update_satus = -99;
//    echo "<br>PO Detail Update Failed! interorg_transfer Line Error @ " . __LINE__ . $e->getMessage();
//   }
//   if ($update_satus > 0) {
//    $this->status = 'Success';
//   } else {
//    $this->status = 'Error';
//   }
//   $this->save();
//  }
// }

 public function _before_save() {
  if (!empty($_POST['wip_wol_transaction_id'][0])) {
   $this->_create_inv_transactions();
  }else{
//   pa($_POST);
  }
  return 10;
 }

 private function _create_inv_transactions() {
  global $dbc;
  
  if (!empty($_POST['wip_wol_transaction_id'][0])) {
   $wip_wol_tran = new wip_wol_transaction();
   $wip_wol_tran->findBy_id($_POST['wip_wol_transaction_id'][0]);
   if (!empty($wip_wol_tran->transaction_status) && ($wip_wol_tran->transaction_status == 'Completed')) {
    echo "You can't modify any completed WIP Work Order Less Transaction";
    return;
   }
  } else {
   return;
  }
  
  for ($i = 0; $i < count($_POST['wip_wol_transaction_id']); $i++) {
   $inv_transaction_i = new inv_transaction();
   switch ($_POST['transaction_type_id'][$i]) {
    case 10 :
     $inv_transaction_i->org_id = $_POST['org_id'][$i];
     $inv_transaction_i->from_subinventory_id = $_POST['supply_sub_inventory'][$i];
     if (!empty($_POST['supply_locator'][$i])) {
      $inv_transaction_i->from_locator_id = $_POST['supply_locator'][$i];
     }
     $inv_transaction_i->quantity = $_POST['quantity'][$i];
     $inv_transaction_i->item_id_m = $_POST['item_id_m'][$i];
     $inv_transaction_i->transaction_type_id = 6;
     $inv_transaction_i->reference_type = 'table';
     $inv_transaction_i->reference_key_name = 'wip_wol_transaction';
     $inv_transaction_i->reference_key_value = $_POST['wip_wol_transaction_id'][$i];
     $inv_transaction_i->document_type = 'WOL Completion';
     $inv_transaction_i->document_number = $_POST['wip_wol_transaction_id'][$i];
     $inv_transaction_i->wip_wo_bom_id = '1';
     $inv_transaction_i->setProperty('_wip_accounting_group_id', $wip_wol_tran->wip_accounting_group_id);
     $inv_transaction_i->_before_save();
     $inv_transaction_i->save();
     $inv_transaction_i->_after_save();
     break;

    case 12 :
     $inv_transaction_i->org_id = $_POST['org_id'][$i];
     $inv_transaction_i->to_subinventory_id = $_POST['supply_sub_inventory'][$i];
     if (!empty($_POST['supply_locator'][$i])) {
      $inv_transaction_i->to_locator_id = $_POST['supply_locator'][$i];
     }
     $inv_transaction_i->quantity = $_POST['quantity'][$i];
     $inv_transaction_i->item_id_m = $_POST['item_id_m'][$i];
     $inv_transaction_i->transaction_type_id = 7;
     $inv_transaction_i->reference_type = 'table';
     $inv_transaction_i->reference_key_name = 'wip_wol_transaction';
     $inv_transaction_i->reference_key_value = $_POST['wip_wol_transaction_id'][$i];
     $inv_transaction_i->document_type = 'WOL Completion';
     $inv_transaction_i->document_number = $_POST['wip_wol_transaction_id'][$i];
     $inv_transaction_i->wip_wo_bom_id = '1';
     $inv_transaction_i->setProperty('_wip_accounting_group_id', $wip_wol_tran->wip_accounting_group_id);
     $inv_transaction_i->_before_save();
     $inv_transaction_i->save();
     $inv_transaction_i->_after_save();
     break;

    default:
     break;
   }
   //do WOL Completion
   $inv_transaction_c = new inv_transaction();
   $inv_transaction_c->org_id = $wip_wol_tran->org_id;
   $inv_transaction_c->to_subinventory_id = $wip_wol_tran->completion_sub_inventory;
   if (!empty($wip_wol_tran->completion_locator)) {
    $inv_transaction_c->to_locator_id = $wip_wol_tran->completion_locator;
   }
   $inv_transaction_c->quantity = $wip_wol_tran->quantity;
   $inv_transaction_c->item_id_m = $wip_wol_tran->item_id_m;
   $inv_transaction_c->revision_name = $wip_wol_tran->revision_name;
   $inv_transaction_c->transaction_type_id = $wip_wol_tran->transaction_type_id;
   $inv_transaction_c->reference_type = 'table';
   $inv_transaction_c->reference_key_name = 'wip_wol_transaction';
   $inv_transaction_c->reference_key_value = $wip_wol_tran->wip_wol_transaction_id;
   $inv_transaction_c->document_type = 'WOL Completion';
   $inv_transaction_c->document_number = 'NA';
   $inv_transaction_c->wip_wo_bom_id = '1';
   $inv_transaction_c->setProperty('_wip_accounting_group_id', $wip_wol_tran->wip_accounting_group_id);
   $inv_transaction_c->_before_save();
   $inv_transaction_c->save();
   $inv_transaction_c->_after_save();

   //update WOL status
   try {
    $wip_wol_tran->transaction_status = 'Completed';
    $wip_wol_tran->save();
    echo '<br>All transactions are Successfullycompleted';
   } catch (Exception $e) {
    echo '<br>Transaction failed. Error @ wol_transaction_line @@ line ' . __LINE__ . '<br>' . $e->getMessage();
    $dbc->rollback = true;
   }
  }

  //complete the FGI
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