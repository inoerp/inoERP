<?php

class sd_delivery_line extends dbObject {

 public static $table_name = "sd_delivery_line";
 public static $primary_column = "sd_delivery_line_id";
 public static $parent_primary_column = "sd_delivery_header_id";
 public static $multi_select_template_path = "modules/sd/delivery/delivery_template.php";
 public static $multi_search_primary_column = "sd_delivery_header_id"; //this value is used in multi search hidden value
 public static $key_column = 'sd_so_line_id';
 public static $module = "inv";
 public static $delivery_status_a = [
  'AWAITING_SHIPPING' => 'Awaiting Shipping',
  'SHIPPED' => 'Shipped'
 ];
 public $field_a = [
  'sd_delivery_line_id',
  'sd_delivery_header_id',
  'sd_so_header_id',
  'sd_so_line_id',
  'shipping_org_id',
  'item_id_m',
  'quantity',
  'shipped_quantity',
  'staging_subinventory_id',
  'staging_locator_id',
  'delivery_status',
  'picking_date',
  'actual_ship_date',
  'reference_doc_type',
  'reference_doc_number',
  'line_uom_id',
  'volume_uom_id',
  'total_volume',
  'weight_uom_id',
  'total_weight',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $account = [
 ];
 public $fields_inForm_notInDataBase = [
  'so_line_shipped_quantity',
  'so_number',
  'so_line_number',
  'shipment_number',
  'item_number',
  'item_description',
  'line_uom_id',
  'ar_customer_id',
  'ar_customer_number',
  'ar_customer_name',
  'ar_customer_site_id',
  'ar_customer_site_number',
  'ar_customer_site',
  'action',
  'so_qty_change'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "sd_delivery_header_id",
  'shipping_org_id',
  'so_line_number',
  'quantity'
 ];
 public $requiredField = [
  'sd_so_header_id',
  'sd_so_line_id',
  'staging_subinventory_id',
  'item_description',
  'line_uom_id',
  'quantity'
 ];
 public $initial_search = [
  'sd_delivery_line_id',
  'sd_delivery_header_id',
  'sd_so_header_id',
  'sd_so_line_id',
  'shipping_org_id',
  'item_id_m',
  'picking_date',
  'delivery_status'
 ];
 public $column = [
  'sd_delivery_line_id',
  'sd_delivery_header_id',
  'sd_so_header_id',
  'sd_so_line_id',
  'shipping_org_id',
  'item_id_m',
  'quantity',
  'staging_subinventory_id',
  'staging_locator_id',
  'delivery_status',
  'picking_date',
  'actual_ship_date',
  'reference_doc_type',
  'reference_doc_number',
  'line_uom_id',
  'volume_uom_id',
  'total_volume',
  'weight_uom_id',
  'total_weight',
 ];
 public $sd_delivery_line_id;
 public $sd_delivery_header_id;
 public $sd_so_header_id;
 public $sd_so_line_id;
 public $shipping_org_id;
 public $item_id_m;
 public $quantity;
 public $staging_subinventory_id;
 public $staging_locator_id = '';
 public $delivery_status;
 public $picking_date;
 public $actual_ship_date;
 public $reference_doc_type;
 public $reference_doc_number;
 public $line_uom_id;
 public $volume_uom_id;
 public $total_volume;
 public $weight_uom_id;
 public $total_weight;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $line_number;
 public $shipment_number;
 public $item_number;
 public $uom_id;
 public $ar_customer_id;
 public $ar_customer_number;
 public $ar_customer_name;
 public $ar_customer_site_id;
 public $ar_customer_site_number;
 public $ar_customer_site_name;
 public $so_number;
 public $so_line_number;
 public $shipped_quantity;
 public $item_description;
 public $action;
 public $so_qty_change;
 public $sn_ids_a;
 public $ln_ids_a;
 public $res_oh_id;

 public function _before_save() {
  if (($this->action == 'REVERSE_PICKING')) {
   echo "<br> Starting Sales Line Reverse Picking.";
   $this->_reverse_picking();
   return 10;
  } else if (($this->action == 'REMOVE_LINE')) {
   echo "<br> Starting to remove the line from delivery ";
   $this->sd_delivery_header_id = -1;
   $this->save();
   return 10;
  } else if (($this->action == 'ADD_LINE')) {
   echo "<br> Starting to add the line to delivery ";
   if (empty($this->sd_delivery_header_id) || $this->sd_delivery_header_id == -1) {
    echo "<br> Error - No Header Id found! @ sd_delivery_line @@" . __LINE__;
   }
   $this->save();
   return 10;
  } else if (($this->action == 'COMPLETE_SHIPMENT')) {
   echo "<br> Starting to complete the shipment ";
   $this->_complete_shipment();
   return 10;
  } else {
   echo "<br> No Action For Line";
   return 10;
  }
 }

 private function _validate_delete() {
  if (!empty($this->quantity)) {
   echo "<div class='alert alert-danger '>You can n't delete this delivery line. You can remove the line or do a reverse picking </div>";
   return -99;
  } else {
   return 1;
  }
 }

 public function _before_delete() {
  return $this->_validate_delete();
 }

 public function _after_save() {
  
 }

 public function create_reservation() {
  global $dbc;
  $dbc->confirm();
  $this->_create_reservation();
 }

 private function _create_reservation() {
  if (!empty($this->sn_ids_a)) {
   $this->_create_reservation_serialItems();
  } else if (!empty($this->ln_ids_a)) {
   try {
    $this->_create_reservation_lotItems();
   } catch (Exception $e) {
    echo "<br>Failed to create reservation for lot at staging. Error @ " . get_class($this) . ' @@ ' . __LINE__ . $e->getMessage();
   }
  } else {
   try {
    $this->_create_reservation_forItems();
   } catch (Exception $e) {
    echo "<br>Failed to create reservation for item at staging. Error @ " .  get_class($this) . ' @@ ' . __LINE__ . $e->getMessage();
   }
   
  }
 }

 private function _create_reservation_lotItems() {
  global $dbc;
  foreach ($this->ln_ids_a as $ln_id => $q) {
   $irs = new inv_reservation();
   $irs->item_id_m = $this->item_id_m;
   $irs->org_id = $this->shipping_org_id;
   $irs->demand_type = 'DELIVERY_LINE';
   $irs->supply_type = 'ONHAND';
   $irs->d_reference_key_name = 'sd_delivery_line';
   $irs->d_reference_key_value = $this->sd_delivery_line_id;
   $irs->s_reference_key_name = 'onhand';
   $onhand_all = onhand::find_by_itemIdm_location_sv($this->item_id_m, $this->shipping_org_id, $this->staging_subinventory_id, $this->staging_locator_id);
   $onhand_i = inv_lot_onhand::find_by_fieldVal([
     'onhand_id' => $onhand_all->onhand_id,
     'inv_lot_number_id' => $ln_id]);
   if ($onhand_i) {
    $irs->onhand_id = $irs->s_reference_key_value = $onhand_i[0]->onhand_id;
   } else {
    $dbc->rollback = true;
    throw new Exception('No onhand found @ staging. Error @' . __FILE__ . ' @@ ' . __LINE__);
   }

   $irs->need_by_date = $this->picking_date;
   $irs->uom_id = $this->line_uom_id;
   $irs->demand_quantity = $q;
   $irs->subinventory_id = $this->staging_subinventory_id;
   $irs->locator_id = $this->staging_locator_id;
   $irs->inv_lot_number_id = $ln_id;
   $irs->save();
  }
 }

 private function _create_reservation_serialItems() {
  global $dbc;
  foreach ($this->sn_ids_a as $k => $sn_id) {
   if ($k >= $this->quantity) {
    break;
   }
   $irs = new inv_reservation();
   $irs->item_id_m = $this->item_id_m;
   $irs->org_id = $this->shipping_org_id;
   $irs->demand_type = 'DELIVERY_LINE';
   $irs->supply_type = 'ONHAND';
   $irs->d_reference_key_name = 'sd_delivery_line';
   $irs->d_reference_key_value = $this->sd_delivery_line_id;
   $irs->s_reference_key_name = 'onhand';
   $onhand_i = onhand::find_by_itemIdm_location_sv($this->item_id_m, $this->shipping_org_id, $this->staging_subinventory_id, $this->staging_locator_id);
   if ($onhand_i) {
    $irs->onhand_id = $irs->s_reference_key_value = $onhand_i->onhand_id;
   } else {
    $dbc->rollback = true;
    throw new Exception('No onhand found @ staging. Error @' . __FILE__ . ' @@ ' . __LINE__);
   }

   $irs->need_by_date = $this->picking_date;
   $irs->uom_id = $this->line_uom_id;
   $irs->demand_quantity = 1;
   $irs->subinventory_id = $this->staging_subinventory_id;
   $irs->locator_id = $this->staging_locator_id;
   $irs->inv_serial_number_id = $sn_id;
   $irs->save();
  }
 }

 private function _create_reservation_forItems() {
  global $dbc;
  $irs = new inv_reservation();
  $irs->item_id_m = $this->item_id_m;
  $irs->org_id = $this->shipping_org_id;
  $irs->demand_type = 'DELIVERY_LINE';
  $irs->supply_type = 'ONHAND';
  $irs->d_reference_key_name = 'sd_delivery_line';
  $irs->d_reference_key_value = $this->sd_delivery_line_id;
  $irs->s_reference_key_name = 'onhand';
  $onhand_i = onhand::find_by_itemIdm_location_sv($this->item_id_m, $this->shipping_org_id, $this->staging_subinventory_id, $this->staging_locator_id);
  if ($onhand_i) {
   $irs->onhand_id = $irs->s_reference_key_value = $onhand_i->onhand_id;
  } else {
   $dbc->rollback = true;
   throw new Exception('No onhand found @ staging. Error @' . __FILE__ . ' @@ ' . __LINE__);
  }
  $irs->need_by_date = $this->picking_date;
  $irs->uom_id = $this->line_uom_id;
  $irs->demand_quantity = $this->quantity;
  $irs->subinventory_id = $this->staging_subinventory_id;
  $irs->locator_id = $this->staging_locator_id;
  $irs->save();
 }

 private function _reverse_picking() {
  /*
   * 1. Update SO Line status & picked quantity to Make it available for next picking
   * 2. Delete the delivery line
   * 3. Delete all reservation lines
   * 4. No material / finance transaction - Onhand 'll remain in staging location and 
   * needs to be manually moved back to stock through subinventory transfer/move order
   */
  $sol = new sd_so_line();
  $sol->findBy_id($this->sd_so_line_id);
  $sol->line_status = 'AWAITING_PICKING';
  $sol->picked_quantity -= $this->quantity;
  try {
   $sol->save();
   echo "<br>Sales Order Line Status is Successfully Updated";
   $res_i = inv_reservation::find_by_demandReference('sd_delivery_line', $this->sd_delivery_line);
   if ($res_i) {
    foreach ($res_i as $k => $res) {
     $ir = new inv_reservation();
     $ir->inv_reservation_id = $res->inv_reservation_id;
     $ir->delete();
    }
    echo "<br>Reservation Line is Successfully Deleted";
   }

   $this->delete();
   echo "<br>Delivery Line is Successfully Deleted";
  } catch (Exception $e) {
   echo "<br>Upate Failed. Error @sd_delivery_line @@ " . __LINE__ . $e->getMessage();
  }
 }

 private function _update_ar_interface() {
  $ar_ti = new ar_transaction_interface();
  $soh = new sd_so_header();
  $soh->findBy_id($this->sd_so_header_id);
  $ar_ti->bu_org_id = $soh->bu_org_id;
  $legal_org_id = org::find_by_id($ar_ti->bu_org_id)->legal_org_id;
  $ar_ti->ledger_id = legal::find_by_orgId($legal_org_id)->ledger_id;
  $sd_transaction_type = $soh->document_type;
  $sd_doc = new sd_document_type();
  $sd_doc->findBy_id($sd_transaction_type);
  $ar_ti->transaction_type = $sd_doc->ar_transaction_type;
  $ar_ti->ar_customer_id = $soh->ar_customer_id;
  $ar_ti->ar_customer_site_id = $soh->ar_customer_site_id;
  $ar_ti->currency = $soh->doc_currency;
  $ar_ti->payment_term_id = $soh->payment_term_id;
  $ar_tp = new ar_transaction_type();
  $ar_tp->findBy_id($ar_ti->transaction_type);
  $ar_ti->receivable_ac_id = $ar_tp->receivable_ac_id;
  $ar_ti->revenue_ac_id = $ar_tp->revenue_ac_id;
  $ar_ti->tax_code_id = $ar_tp->tax_ac_id;
  $ar_ti->item_id_m = $this->item_id_m;
  $ar_ti->inv_line_quantity = $this->quantity;
  $sol = new sd_so_line();
  $sol->findBy_id($this->sd_so_line_id);
  $ar_ti->inv_unit_price = $sol->unit_price;
  $sd_doc_l = new sd_document_type();
  $sd_doc_l->findBy_id($sol->line_type);
  if (!empty($sd_doc_l->ar_transaction_type)) {
   $ar_ti->transaction_type = $sd_doc_l->ar_transaction_type;
   $ar_tp_i = new ar_transaction_type();
   $ar_tp_i->findBy_id($ar_ti->transaction_type);
   $ar_ti->receivable_ac_id = $ar_tp_i->receivable_ac_id;
   $ar_ti->revenue_ac_id = $ar_tp_i->revenue_ac_id;
   $ar_ti->tax_code_id = $ar_tp_i->tax_ac_id;
  }
  $ar_ti->inv_line_price = $ar_ti->inv_line_quantity * $ar_ti->inv_unit_price;
  if (!empty($soh->exchange_rate)) {
   $ar_ti->gl_inv_line_price = $ar_ti->inv_line_price * $soh->exchange_rate;
  } else {
   $ar_ti->gl_inv_line_price = $ar_ti->inv_line_price;
  }

  $ar_ti->tax_code_id = $sol->tax_code_id;
  $ar_ti->item_description = $sol->item_description;
  $mm_tax = new mdm_tax_code();
  $mm_tax->findBy_id($ar_ti->tax_code_id);
  if (!empty($mm_tax->percentage)) {
   $ar_ti->tax_amount = ($ar_ti->inv_line_price * $mm_tax->percentage) / 100;
  } else if (!empty($mm_tax->tax_amount)) {
   $ar_ti->tax_amount = $mm_tax->tax_amount;
  }
  $ar_ti->gl_tax_amount = $ar_ti->tax_amount * $ar_ti->inv_unit_price;
  $ar_ti->line_type = $sol->line_type;
  $ar_ti->line_description = $sol->line_description;
  $ar_ti->uom_id = $sol->uom_id;
  $ar_ti->reference_type = 'table';
  $ar_ti->reference_key_name = 'sd_so_line';
  $ar_ti->reference_key_value = $ar_ti->sd_so_line_id = $this->sd_so_line_id;
  $ar_ti->sd_so_header_id = $this->sd_so_header_id;
  $ar_ti->audit_trial();
  try {
   $ar_ti->save();
  } catch (Exception $e) {
   echo "<br>Transfer to AR Interface Failed. Error @sd_delivery_line @@ " . __LINE__ . $e->getMessage();
   $this->rollback = true;
  }
 }

 private function _complete_shipment() {
  /*
   * 1. Update SO Line with the shipment qty and status
   * 2. Inventory Trandsaction
   * 3. Update the delivery line to SHIPPED
   * needs to be manually moved back to stock through subinventory transfer/move order
   * 4. Remove rservation from staging
   * 5. Insert the data in ar_transaction_interface
   */
  global $dbc;
  $sol = new sd_so_line();
  $sol->findBy_id($this->sd_so_line_id);
  if (empty($this->shipped_quantity)) {
   $this->shipped_quantity = $this->quantity;
  }

  //update the inv transaction & onhand
  if ($sol->kit_cb) {
   if (!empty($sol->bom_config_header_id)) {
    $bom_lines_all = bom_config_line::find_by_parent_id($sol->bom_config_header_id);
    foreach ($bom_lines_all as $bom_lines) {
     $item_i = item::find_by_item_id_m($bom_lines->component_item_id_m);
     $qty = $this->shipped_quantity * $bom_lines->usage_quantity;
     try {
      $this->_create_inv_transaction($item_i->item_id_m, $qty);
     } catch (Exception $e) {
      echo "<br>Failed to complete the inventory transaction. Error @ sd_delivery_header @@ line " . __LINE__;
      $dbc->rollback = true;
      return;
     }
    }
   }
  } else {
   try {
    $this->_create_inv_transaction($this->item_id_m, $this->shipped_quantity);
   } catch (Exception $e) {
    echo '<br>Failed to complete the inventory transaction. Error @ ' . __FILE__ . '  @@ line ' . __LINE__ . '<br>' . $e->getMessage();
    $dbc->rollback = true;
    return;
   }
  }

  //update AR Interface
  try {
   $this->_update_ar_interface();
  } catch (Exception $e) {
   echo "<br>Failed to update the AR Interface. Error @ sd_delivery_leader @@ line " . __LINE__;
   $dbc->rollback = true;
   return;
  }


  //Update SO 
  try {
   $sol->shipped_quantity += $this->shipped_quantity;
   if ($sol->shipped_quantity == $sol->line_quantity) {
    $sol->line_status = 'SHIPPED';
   } else {
    $sol->line_status = 'PARTIAL_SHIPPED';
   }

   $sol->actual_ship_date = current_time(1);

   if ($this->shipped_quantity != $this->quantity) {
    $qty_reduced = $this->quantity - $this->shipped_quantity;
    $sol->picked_quantity -= $qty_reduced;
   }
   if ($sol->picked_quantity < 0) {
    echo "<br>SO Line picked quantity can not be negative. Error @ sd_delivery_leader @@ line " . __LINE__;
    $dbc->rollback = true;
    return -90;
   }
   $sol->save();
  } catch (Exception $e) {
   echo "<br>Failed to SO Line Status. Error @ sd_delivery_leader @@ line " . __LINE__;
   $dbc->rollback = true;
   return;
  }


  //Update Delivery Line Status
  $this->delivery_status = 'SHIPPED';
  try {
   $this->audit_trial();
   $this->save();
   echo "<br>Delivery Line Status is SuccessfullyUpdated";
  } catch (Exception $e) {
   echo "<br>Failed to update the delivery line Status. Error @ sd_delivery_leader @@ line " . __LINE__;
   $dbc->rollback = true;
   return;
  }
 }

 public $delivery_line_sn_ids_a = [];

 private function _create_inv_transaction($item_id_m, $qty) {
  global $dbc;
  $invt = new inv_transaction();
  $invt->transaction_type_id = 15;
  $invt->org_id = $this->shipping_org_id;
  $invt->from_subinventory_id = $this->staging_subinventory_id;
  $invt->from_locator_id = $this->staging_locator_id;
  $invt->item_id_m = $item_id_m;
  $invt->uom_id = $this->line_uom_id;
  $invt->quantity = $qty;
  $invt->reference_type = 'table';
  $invt->reference_key_name = 'sd_delivery_header';
  $invt->reference_key_value = $this->sd_delivery_header_id;
  $invt->reason = gettext('SO Shipping');
  $invt->sd_so_line_id = $this->sd_so_line_id;
  $invt->d_reference_key_name = 'sd_delivery_line';
  $invt->d_reference_key_value = $this->sd_delivery_line_id;

  //reservation details
  $line_reservation_details = inv_reservation::find_by_demandReference('sd_delivery_line', $this->sd_delivery_line_id);
  if (empty($line_reservation_details)) {
   throw new Exception('No reservation found for the delivery line ' . $this->sd_delivery_line_id . ' Error @ ' . __LINE__ . ' @@ ' . __FILE__);
  }

  foreach ($line_reservation_details as $s_obj) {
   if (property_exists($s_obj, 'inv_serial_number_id')) {
    array_push($this->delivery_line_sn_ids_a, $s_obj->inv_serial_number_id);
   }
  }

//  pa($this->delivery_line_sn_ids_a);
//  pa($line_reservation_details);
  $invt->serial_number_ids = $this->delivery_line_sn_ids_a;

  try {
   $invt->_before_save();
   $invt->save();
   $invt->_after_save();
  } catch (Exception $e) {
   echo "<br>Failed to complete the inventory transaction. Error @ sd_delivery_line @@ line " . __LINE__;
   $dbc->rollback = true;
   return;
  }
//  pa($invt->serial_number_ids);
  //remove reservation
  try {
   $reservationid_qty_a = [];
   if (!empty($invt->serial_number_ids[0])) {
    foreach ($line_reservation_details as $k => $v) {
     if ($k >= $invt->quantity) {
      break;
     }
     $reservationid_qty_a[$v->inv_reservation_id] = 1;
    }
   } else {
    foreach ($line_reservation_details as $k => $v) {
     $reservationid_qty_a[$v->inv_reservation_id] = $invt->quantity;
    }
   }
   $res = new inv_reservation();
//   pa($reservationid_qty_a);
   $res->remove_reservation($reservationid_qty_a);
   echo "<br> Reservation is removed ";
  } catch (Exception $e) {
   $dbc->rollback = true;
   echo "<br>Failed to remove the reservation. Error @ " . __FILE__ . ' @@ ' . __LINE__ . $e->getMessage();
  }
 }

}

//end of sd_delivery_line class
?>
