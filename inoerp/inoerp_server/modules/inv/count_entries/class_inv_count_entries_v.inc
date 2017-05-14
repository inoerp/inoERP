<?php

class inv_count_entries_v extends dbObject {

 public static $form_class_name = "inv_count_entries";
 
 public static $table_name = "inv_count_entries_v";
 public static $primary_column = "inv_count_entries_id";
 public $field_a = [
  'inv_count_entries_id',
  'inv_count_schedule_id',
  'item_id_m',
  'uom_id',
  'org_id',
  'subinventory_id',
  'locator_id',
  'lot_number',
  'serial_number',
  'schedule_date',
  'adjustment_ac_id',
  'status',
  'reason',
  'reference',
  'counted_by',
  'count_date',
  'count_qty',
  'system_qty',
  'adjusted_qty',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
  'item_number',
  'item_description',
  'subinventory',
  'locator',
  'uom_name',
  'org',
 ];
 public $initial_search = [
  'item_number',
  'item_description',
  'subinventory',
  'locator',
  'uom_name',
  'org',
 ];
 public $column = [
  'item_number',
  'item_description',
  'subinventory',
  'locator',
  'uom_name',
  'org',
  'status',
  'count_qty',
  'system_qty',
  'adjusted_qty',
  'inv_count_entries_id',
  'inv_count_schedule_id',
  'item_id_m',
  'uom_id',
  'org_id',
  'subinventory_id',
  'locator_id',
  'lot_number',
  'serial_number',
  'schedule_date',
  'adjustment_ac_id',
  'reason',
  'reference',
  'counted_by',
  'count_date',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $search_functions = [
  'Count Status' => 'search_inv_count_entry_status',
 ];
 public $search = [
 ];
 public $pageTitle = " Count Entries View "; //page Title
 public $inv_count_entries_id;
 public $inv_count_schedule_id;
 public $item_id_m;
 public $uom_id;
 public $org_id;
 public $subinventory_id;
 public $locator_id;
 public $lot_number;
 public $serial_number;
 public $schedule_date;
 public $adjustment_ac_id;
 public $status;
 public $reason;
 public $reference;
 public $counted_by;
 public $count_date;
 public $count_qty;
 public $system_qty;
 public $adjusted_qty;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $item_number;
 public $item_description;
 public $subinventory;
 public $locator;
 public $uom_name;
 public $org;

 private function create_inv_count_entries_v() {
  $sql = "
CREATE OR REPLACE VIEW inv_count_entries_v
(
inv_count_entries_id, inv_count_schedule_id, item_id_m, uom_id, org_id,
subinventory_id, locator_id, lot_number, serial_number, schedule_date,
adjustment_ac_id, status, reason, reference, counted_by, count_date,
count_qty, system_qty, adjusted_qty, description, created_by, creation_date,
last_update_by, last_update_date,
item_number, item_description,
subinventory, locator,uom_name,org
)
AS
SELECT 
ice.inv_count_entries_id, ice.inv_count_schedule_id, ice.item_id_m, ice.uom_id, ice.org_id,
ice.subinventory_id, ice.locator_id, ice.lot_number, ice.serial_number, ice.schedule_date,
ice.adjustment_ac_id, ice.status, ice.reason, ice.reference, ice.counted_by, ice.count_date,
ice.count_qty, ice.system_qty, ice.adjusted_qty, ice.description, ice.created_by, ice.creation_date,
ice.last_update_by, ice.last_update_date,
item.item_number, item.item_description,
sin.subinventory, loc.locator,uom_name, org
FROM inv_count_entries ice
LEFT JOIN item ON item.item_id_m = ice.item_id_m AND item.org_id = ice.org_id
LEFT JOIN subinventory sin ON sin.subinventory_id = ice.subinventory_id 
LEFT JOIN locator loc ON loc.locator_id = ice.locator_id
LEFT JOIN uom ON uom.uom_id = ice.uom_id
LEFT JOIN org ON org.org_id = ice.org_id

";
 }

 public function findBy_ItemId_CostType() {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE bom_cost_type =:bom_cost_type AND item_id_m = :item_id_m ";
  $sql = ino_perPageSql_i($sql, 1);

  $param_a = ['bom_cost_type', 'item_id_m'];
  $value_a = ['bom_cost_type' => $this->bom_cost_type, 'item_id_m' => $this->item_id_m];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_cost_by_itemId_orgId($item_id, $org_id, $bom_cost_type = 'FROZEN') {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE bom_cost_type = '{$bom_cost_type}' AND org_id = '{$org_id}'  AND item_id_m = '{$item_id}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of ap_transaction_detail class
?>