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
 * inv_moveorder_header
 * Contains all the inv_moveorder_header information, such as - item_id_m, order_number,  from_org_id, to_org_id, etc.
 * 
 */
class inv_moveorder_header extends dbObject {

 public static $table_name = "inv_moveorder_header";
 public static $dependent_classes = ['inv_moveorder_line'];
 public static $primary_column = "inv_moveorder_header_id";
 public static $primary_column2 = "order_number";
 public static $key_column = 'org_id';
 public static $module = "inv"; //same as gl_journal_source
 public static $gl_journal_category = "INV_RECEIVING";
 public static $system_info = [
  'name' => 'Move Order Transaction',
  'number' => '2139',
  'description' => 'Move Order Transaction',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('inv_moveorder_line'),
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 6
 ];
 public static $transaction_type_id_a = [
  '26' => 'Inv Move Transaction',
  '27' => 'Sales Move Transaction',
  '28' => 'WIP Move Transaction',
 ];
 public $action_a = [
  'COMPLETE_TRNX' => 'Complete Transaction',
  'GENERATE_DOC' => 'Generate Documents',
 ];
 public static $status_a = [
  'ENTERED' => 'Entered',
  'COMPLETED' => 'Completed',
  'ON_HOLD' => 'On Hold',
 ];
 public $field_a = [
  'inv_moveorder_header_id',
  'order_number',
  'comment',
  'org_id',
  'transaction_type_id',
  'status',
  'transfer_to_gl',
  'transaction_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data

 public $initial_search = [
  'inv_moveorder_header_id',
  'order_number',
  'comment',
 ];
 public $requiredField = [
  'org_id',
  'transaction_type_id',
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $fields_inForm_notInDataBase = [
  'action'
 ];
 public $pageTitle = " Move Order "; //page Title
 public $option_lists = [
  'inv_transaction_class' => 'TRANSACTION_TYPE_CLASS'
 ];
 public $inv_moveorder_header_id;
 public $order_number;
 public $comment;
 public $org_id;
 public $transaction_type_id;
 public $status;
 public $transfer_to_gl;
 public $transaction_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $action;

 public function _before_save() {
  global $dbc;

  if (empty($this->status)) {
   $this->status = 'ENTERED';
  }

  if (($this->action == 'COMPLETE_TRNX')) {
   echo "<br> Starting move transaction.";
   try {
    $this->_complete_moveTransaction();
   } catch (Exception $e) {
    $dbc->rollback = true;
    echo "<br>Failed to complete the move transaction. " . $e->getMessage();
   }

   return 10;
  }
 }

 public function _after_save() {
  if ((!empty($this->inv_moveorder_header_id)) && empty($this->order_number)) {
   $this->order_number = $this->org_id . '-' . $this->inv_moveorder_header_id;
   echo '<br/> System created order number is ' . $this->order_number;
   $this->save();
  }
 }

 private function _complete_moveTransaction() {
  global $dbc;
  if ($this->status != 'ENTERED') {
   throw new Exception('You can transact only orders in Entered status');
  } else {
   $all_lines = inv_moveorder_line::find_by_parent_id($this->inv_moveorder_header_id);
  }

  if (empty($all_lines)) {
   throw new Exception('No move order lines found for transactions');
  } else {
   foreach ($all_lines as $mo_l) {
    $invt = new inv_transaction();
    $invt->transaction_type_id = 26;
    $invt->to_subinventory_id = $mo_l->to_subinventory_id;
    $invt->to_locator_id = $mo_l->to_locator_id;
    $invt->from_subinventory_id = $mo_l->from_subinventory_id;
    $invt->from_locator_id = $mo_l->from_locator_id;
    $invt->item_id_m = $mo_l->item_id_m;
    $invt->uom_id = $mo_l->uom_id;
    $invt->org_id = $this->org_id;
    $invt->quantity = $mo_l->transaction_quantity;
    $invt->reference_type = 'table';
    $invt->reference_key_name = 'inv_moveorder_line';
    $invt->reference_key_value = $mo_l->inv_moveorder_line_id;
    $invt->reason = 'Move Trasaction';
    $invt->d_reference_key_name = 'inv_moveorder_line';
    $invt->d_reference_key_value = $mo_l->inv_moveorder_line_id;

//    $serial_reservation_exists = false;
////serial reservation details   
//    if (!empty($_POST['serial_generation'][$i])) {
//     //check for reservation for serial controlled items
//     $serial_number_ids_obj = inv_reservation::find_by_demandReference_onhandReference('inv_moveorder_line', $invt->sd_so_line_id, $oh_data->onhand_id);
//     if (empty($serial_number_ids_obj) || empty($serial_number_ids_obj[0])) {
//      $serial_number_ids_obj = inv_serial_number::find_by_currentLocation($invt->item_id_m, $invt->org_id, $invt->from_subinventory_id, $invt->from_locator_id, 1);
//     } else {
//      $reservation_exists = true;
//      $serial_reservation_exists = true;
//     }
////    $serial_number_ids_a = [];
//     if (empty($serial_number_ids_obj)) {
//      throw new Exception('No Serial Number Found for Serial conrolled Item error @ ' . __FILE__ . ' @@ ' . __LINE__, '1');
//     }
//     foreach ($serial_number_ids_obj as $s_obj) {
//      array_push($this->delivery_line_sn_ids_a, $s_obj->inv_serial_number_id);
//     }
//     $invt->serial_number_ids = $this->delivery_line_sn_ids_a;
//    }
//
////lot reservation
//    $lot_reservation_exists = false;
//    if (!empty($_POST['lot_generation'][$i])) {
//     //check for reservation for lot controlled items
//     $lot_number_ids_obj = inv_reservation::find_by_demandReference_onhandReference('sd_so_line', $invt->sd_so_line_id, $oh_data->onhand_id);
//     if (empty($lot_number_ids_obj) || empty($lot_number_ids_obj[0])) {
//      $lot_number_ids_obj = inv_lot_onhand_v::find_by_fieldVal([
//        'item_id_m' => $invt->item_id_m,
//        'org_id' => $invt->org_id,
//        'subinventory_id' => $invt->from_subinventory_id,
//        'locator_id' => $invt->from_locator_id]);
//     } else {
//      $reservation_exists = true;
//      $lot_reservation_exists = true;
//     }
//     if (empty($lot_number_ids_obj)) {
//      throw new Exception('No Lot Number Found For Lot Conrolled Item error @ ' . __FILE__ . ' @@ ' . __LINE__, '1');
//     }
//     $lot_no_ids_awv = [];
//     foreach ($lot_number_ids_obj as $s_obj) {
//      if ($lot_reservation_exists) {
//       $lot_no_ids_awv[$s_obj->inv_lot_number_id] = $s_obj->demand_quantity < $transaction_quantity ? $s_obj->demand_quantity : $transaction_quantity;
//      } else {
//       $lot_no_ids_awv[$s_obj->inv_lot_number_id] = $s_obj->lot_quantity < $transaction_quantity ? $s_obj->lot_quantity : $transaction_quantity;
//      }
//     }
//     $invt->lot_number_ids = $this->delivery_line_ln_ids_a = $lot_no_ids_awv;
////    $invt->lot_number_ids = array_keys($lot_no_ids_awv);
//    }
//
////item reservation   
//    if (!$reservation_exists) {
//     $line_reservation_details = inv_reservation::find_by_demandReference_onhandReference('sd_so_line', $invt->sd_so_line_id, $oh_data->onhand_id);
//     if ($line_reservation_details) {
//      $reservation_exists = true;
//     }
//    }

    $invt->_before_save();
    $invt->save();
    $invt->_after_save();
   }

   try {
    $this->status = 'COMPLETED';
    $this->save();
   } catch (Exception $e) {
    $dbc->rollback = true;
    echo "<br>Failed to save the move order status. " . $e->getMessage();
   }
  }
 }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

inv_moveorder_header::staticVar_init('transaction_type_id_a');
?>
