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
 * sd_delivery_header
 * Contains all the sd_delivery_header information, such as - sd_delivery_header_id, shipping_org_id,  etc
 *
 */
class sd_delivery_header extends dbObject {

 public static $table_name = "sd_delivery_header";
 public static $dependent_classes = ['sd_delivery_line', 'sd_so_all_v'];
 public static $primary_column = "sd_delivery_header_id";
 public static $primary_column2 = "delivery_number";
 public static $key_column = 'shipping_org_id';
 public static $js_fileName = 'modules/sd/delivery/js/multi_select_so.js';
 public static $module = "sd"; //same as gl_journal_source
 public static $gl_journal_category = "";
 public static $system_info = [
  'name' => 'Sales Delivery',
  'number' => '2307',
  'description' => 'Create & Mainten Sales Delivery',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('sd_so_line'),
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 7
 ];
 public static $status_a = [
  'AWAITING_SHIPPING' => 'Awaiting Shipping',
  'SHIPPED' => 'Shipped'
 ];
 public static $action_a = [
  'COMPLETE_SHIPMENT' => 'Complete Shipment',
  'REVERSE_PICKING' => 'Reverse Picking',
  'REMOVE_LINE' => 'Remove Line',
  'ADD_LINE' => 'Add Line'
 ];
 public $field_a = [
  'sd_delivery_header_id',
  'delivery_number',
  'comment',
  'shipping_org_id',
  'transaction_type_id',
  'delivery_date',
  'status',
  'received_by',
  'carrier',
  'vechile_number',
  'delivery_received_by',
  'carrier_receipt_number',
  'expetced_delivery_date',
  'actual_delivery_date',
  'handling_instruction',
  'ef_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data

 public $initial_search = [
  'sd_delivery_header_id',
  'status',
  'delivery_number',
  'comment',
  'shipping_org_id',
 ];
 public $column = [
  'sd_delivery_header_id',
  'delivery_number',
  'status',
  'comment',
  'shipping_org_id',
 ];
 public $fields_inForm_notInDataBase = [
  "org",
  'sd_so_header_id',
  'sd_so_line_id',
  'item_id_m',
  'quantity',
  'delivery_status',
  'picking_date',
  'multi_action_class_pc',
  'multi_action_class_pc_value',
  'action'
 ];
 public $requiredField = [
  "shipping_org_id",
  "delivery_date",
  'status'
 ];
 public $search = [
  '_show_view_path' => 1,
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Ship Confirm'
 ];
 public $pageTitle = " Shipment Delivery"; //page Title
 public $sd_delivery_header_id;
 public $delivery_number;
 public $comment;
 public $shipping_org_id;
 public $transaction_type_id;
 public $delivery_date;
 public $status;
 public $received_by;
 public $carrier;
 public $vechile_number;
 public $delivery_received_by;
 public $carrier_receipt_number;
 public $expetced_delivery_date;
 public $actual_delivery_date;
 public $handling_instruction;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $action;
 public $sd_so_header_id;
 public $sd_so_line_id;
 public $item_id_m;
 public $quantity;
 public $delivery_status;
 public $picking_date;

 public function _before_save() {
//  pa($this);
  if (($this->action == 'sales_order_picking')) {
   echo "<br> Starting Sales Line Picking.";
   $this->_create_delivery();
   return 10;
  } else if (($this->action == 'COMPLETE_SHIPMENT')) {
   $this->status = 'SHIPPED';
   return;
  } else if (!empty($this->sd_delivery_header_id)) {
   echo "<br>No header update";
   return 10;
  }
 }

 private function _create_delivery_header() {
  global $dbc;
  $dh = new sd_delivery_header();
  $dh->shipping_org_id = $_POST['shipping_org_id'][0];
  $dh->delivery_date = date("Y-m-d");
  $dh->status = 'AWAITING_SHIPPING';
  $dh->audit_trial();
  $dh->save();
  echo "<br> Delivery header is succefully created. Header Id/Delivery Number - " . $dh->sd_delivery_header_id;
  $dh->delivery_number = $dh->sd_delivery_header_id;
  $dh->save();
  return $dh->sd_delivery_header_id;
 }

 private function _create_delivery() {
  global $dbc;
  if (empty($_POST)) {
   return;
  }

  $line_number = 0;
  $sd_delivery_header_id = null;
  for ($i = 0; $i < count($_POST['sd_so_line_id']); $i++) {
   $line_number ++;
   if (empty($sd_delivery_header_id)) {
    $sd_delivery_header_id = $this->_create_delivery_header();
   }
   if (!empty($sd_delivery_header_id)) {
    //verify if requested quantity is more than onhand quantity
    if ($_POST['line_quantity'][$i] > $_POST['onhand'][$i]) {
     echo "<br> Line Quantity " . $_POST['line_quantity'][$i] . ' is more than total available quantity ' .
     $_POST['onhand'][$i];
     break;
    }

    //update the sales order line
    $sol = new sd_so_line();
    $sol->findBy_id($_POST['sd_so_line_id'][$i]);
    if ($sol->line_status != 'AWAITING_PICKING') {
     echo "<br> Line is not available for picking";
     return -99;
    }

    $del_line = new sd_delivery_line();
    $del_line->sd_delivery_line_id = null;
    $del_line->line_number = $line_number;
    $del_line->sd_delivery_header_id = $sd_delivery_header_id;
    $del_line->sd_so_header_id = $_POST['sd_so_header_id'][$i];
    $del_line->sd_so_line_id = $_POST['sd_so_line_id'][$i];
    $del_line->shipping_org_id = $_POST['shipping_org_id'][$i];
    $del_line->item_id_m = $_POST['item_id_m'][$i];
    $del_line->quantity = $_POST['line_quantity'][$i];
    $del_line->delivery_status = 'AWAITING_SHIPPING';
    $del_line->picking_date = date("Y-m-d");
    $del_line->line_uom_id = $_POST['uom_id'][$i];
    $del_line->staging_subinventory_id = $_POST['staging_subinventory_id'][$i];
    $del_line->staging_locator_id = $_POST['staging_locator_id'][$i];
    $del_line->audit_trial();
    $del_line->save();


    //update the onhand
    $del_quantity = $del_line->quantity;
    $onhand = new onhand();
    $onhand->item_id_m = $_POST['item_id_m'][$i];
    $onhand_i = $onhand->findOnhand_byItemId();
    foreach ($onhand_i as $oh_data) {
     $transaction_quantity = 0;
     if ($oh_data->onhand <= 0) {
      continue;
     }
     if ($del_quantity <= 0) {
      break;
     }
     if ($oh_data->onhand >= $del_quantity) {
      $transaction_quantity = $del_quantity;
      $del_quantity = 0;
     } else {
      $transaction_quantity = $oh_data->onhand;
      $del_quantity = $del_quantity - $oh_data->onhand;
     }
     $invt = new inv_transaction();
     $invt->transaction_type_id = 14;
     $invt->to_subinventory_id = $_POST['staging_subinventory_id'][$i];
     $invt->to_locator_id = $_POST['staging_locator_id'][$i];
     $invt->from_subinventory_id = $oh_data->subinventory_id;
     $invt->from_locator_id = $oh_data->locator_id;
     $invt->item_id_m = $_POST['item_id_m'][$i];
     $invt->uom_id = $_POST['uom_id'][$i];
     $invt->org_id = $_POST['shipping_org_id'][$i];
     $invt->quantity = $transaction_quantity;
     $invt->reference_type = 'table';
     $invt->reference_key_name = 'sd_so_header';
     $invt->reference_key_value = $_POST['sd_so_header_id'][$i];
     $invt->reason = 'SO Picking';
     $invt->sd_so_line_id = $_POST['sd_so_line_id'][$i];
     $invt->audit_trial();
     $invt->_before_save();
     $invt->save();
     $invt->_after_save();
    }

    $sol->picked_quantity += $_POST['line_quantity'][$i];
    $sol->line_status = 'PICKED';
    $sol->audit_trial();
    $sol->save();
    echo "<br> Delivery Line is succefully created. Line Id - " . $del_line->sd_delivery_line_id;
   }
  }
 }

 public function _after_save() {
  if ((!empty($this->sd_delivery_header_id)) && empty($this->delivery_number)) {
   $sd_delivery_header_id = $this->sd_delivery_header_id;
   $org_id = $this->shipping_org_id;
   $this->delivery_number = $org_id . '-' . $sd_delivery_header_id;
   echo '<br/> System created delivery number is ' . $this->delivery_number;
   $this->save();
  }

  return $this->msg;
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
   'show_block',
   'line_status'
  ];

  return $multi_select_hidden;
 }

}

?>