<?php

class inv_interorg_transfer_v extends dbObject {

 public static $table_name = "inv_interorg_transfer_v";
 public static $primary_column = "inv_intorg_transfer_line_id";
 public static $form_class_name = "inv_interorg_transfer";
 public static $system_info = [
  'name' => 'Move Order Transaction View',
  'number' => '2138',
  'description' => 'Move Order Transaction View',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('inv_moveorder_line'),
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 6
 ];
 public $field_a = [
  'inv_intorg_transfer_header_id',
  'io_order_number',
  'order_number',
  'line_number',
  'io_line_number',
  'item_number',
  'status',
  'inv_intorg_transfer_line_id',
  'comment',
  'from_org_id',
  'to_org_id',
  'carrier',
  'uom_id',
  'vehicle_number',
  'waybill',
  'from_subinventory_id',
  'from_locator_id',
  'item_id_m',
  'item_description',
  'to_subinventory_id',
  'to_locator_id',
  'transaction_quantity',
  'serial_number',
  'lot_number',
 ];
 public $initial_search = [
  'order_number',
  'line_number',
  'item_number',
  'transaction_type_id',
  'status',
  'to_org_id'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=inv_interorg_transfer',
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Inter Org Transfers "; //page Title
 public $inv_intorg_transfer_header_id;
 public $order_number;
 public $io_order_number;
 public $line_number;
 public $io_line_number;
 public $item_number;
 public $status;
 public $inv_intorg_transfer_line_id;
 public $comment;
 public $from_org_id;
 public $transaction_type_id;
 public $to_org_id;
 public $carrier;
 public $vehicle_number;
 public $waybill;
 public $from_subinventory_id;
 public $from_locator_id;
 public $item_id_m;
 public $item_description;
 public $to_subinventory_id;
 public $to_locator_id;
 public $transaction_quantity;
 public $serial_number;
 public $lot_number;
 public $uom_id;

 private function create_inv_interorg_transfer_v() {
  $sql = "
CREATE OR REPLACE VIEW inv_interorg_transfer_v
(
inv_intorg_transfer_header_id, order_number, io_order_number, line_number, io_line_number, item_number, status, inv_intorg_transfer_line_id, 
comment, from_org_id, transaction_type_id, to_org_id, carrier, vehicle_number, waybill, uom_id,
from_subinventory_id, from_locator_id, item_id_m, item_description, to_subinventory_id, to_locator_id,  
transaction_quantity, serial_number, lot_number
)
AS
SELECT
ith.inv_intorg_transfer_header_id, ith.order_number, ith.order_number,itl.line_number, itl.line_number,item.item_number, itl.status, itl.inv_intorg_transfer_line_id, 
ith.comment, ith.from_org_id, ith.transaction_type_id, ith.to_org_id, ith.carrier, ith.vehicle_number, ith.waybill, itl.uom_id,
itl.from_subinventory_id, itl.from_locator_id, itl.item_id_m, itl.item_description, itl.to_subinventory_id, itl.to_locator_id,  
itl.transaction_quantity, itl.serial_number, itl.lot_number
FROM inv_intorg_transfer_header ith,
inv_intorg_transfer_line itl,
item
WHERE ith.inv_intorg_transfer_header_id = itl.inv_intorg_transfer_header_id
AND item.item_id_m = itl.item_id_m
AND item.org_id = ith.from_org_id


";
 }

 public static function find_all_by_poHeaderId($po_header_id) {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE po_header_id = '{$po_header_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_ColumnNameVal($columnName, $columnVal, $dependent_fields = '', $hidden_fields = '') {
  $sql = "SELECT inv_intorg_transfer_header_id, order_number , io_order_number,    io_line_number,   item_number,  
  inv_intorg_transfer_line_id,   from_org_id,   to_org_id,   carrier,   uom_id,
  vehicle_number,  waybill,   from_subinventory_id,   from_locator_id,   item_id_m,
  item_description,   to_subinventory_id,   to_locator_id,   transaction_quantity, 
  serial_number, lot_number
  
FROM " . static::$table_name . " where " . $columnName . " LIKE  '%{$columnVal}%'  ";
  $sql .= " AND status = 'SHIPPED' ";
  if (!empty($_GET['hidden_fields']['to_org_id'])) {
   $rec_org_id = $_GET['hidden_fields']['to_org_id'];
   $sql .= " AND to_org_id = '{$rec_org_id}' ";
  }
  if (!empty($dependent_fields)) {
   foreach ($dependent_fields as $k => $v) {
    if (!empty($k) && !empty($v)) {
     $sql .= " AND $k = '{$v}' ";
    }
   }
  }
  $result_array = static::find_by_sql($sql);
  return !empty($result_array) ? ($result_array) : false;
 }

}

//end of po_detail class
?>