<?php

class pm_batch_line extends dbObject {

 public static $table_name = "pm_batch_line";
 public static $primary_column = "pm_batch_line_id";
 public static $parent_primary_column = "pm_batch_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "pm";
 public $field_a = [
  'pm_batch_line_id',
  'pm_batch_header_id',
  'line_no',
  'line_type',
  'item_id_m',
  'uom_id',
  'planned_quantity',
  'wip_planned_quantity',
  'actual_quantity',
  'allocated_qty',
  'yield_date',
  'subinventory_id',
  'locator_id',
  'description',
  'scale_type',
  'yield_type',
  'step_no',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'pm_batch_header_id',
  'item_id_m',
  'uom_id'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "pm_batch_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  'item_description',
  'line_type',
  'line_id'
 ];
 public static $yield_type_a = [
  'MANUAL' => 'Manual',
//  'INC' => 'Incremental',
//  'AUTOBS' => 'Auto By Step',
//  'AUTO' => 'Automatic',
 ];
 public $pm_batch_line_id;
 public $pm_batch_header_id;
 public $line_no;
 public $line_type;
 public $item_id_m;
 public $uom_id;
 public $planned_quantity;
 public $wip_planned_quantity;
 public $actual_quantity;
 public $allocated_qty;
 public $yield_date;
 public $step_no;
 public $subinventory_id;
 public $locator_id;
 public $description;
 public $scale_type;
 public $yield_type;
 public $cost_allocation;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;
 public $item_description;
 public $batch_name;
 public $line_id;

 public static function find_allLine_byHeaderId($header_id) {
  $sql = " SELECT
pfl.pm_batch_line_id,   pfl.pm_batch_header_id,   pfl.line_no,   pfl.line_type,   pfl.item_id_m,   pfl.uom_id,   pfl.quantity,
pfl.description,   pfl.cost_allocation,   pfl.scale_type,   pfl.yield_type,   pfl.byproduct_type,   pfl.consumption_type,   pfl.phantom_type,
pfl.required_qty, item.item_number, item.item_description

from pm_batch_line pfl,
pm_batch_header pfh,
item

WHERE item.item_id_m = pfl.item_id_m
and pfh.pm_batch_header_id = pfl.pm_batch_header_id
and pfh.org_id =item.org_id
and pfl.pm_batch_header_id = '{$header_id}'
";

  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

 public static function find_all_lines_with_byProduct_by_headerId($header_id) {
  $sql = "SELECT
pbl.pm_batch_line_id as line_id,  'pm_batch_line' as line_type_code , pbl.pm_batch_header_id, 'Finished Goods'  as line_type,
pbl.line_no, pbl.step_no, pbl.item_id_m, pbl.uom_id, pbl.planned_quantity,
pbl.actual_quantity, pbl.subinventory_id, pbl.locator_id, item.item_number,
item.item_description, item.lot_generation, item.serial_generation, pbh.org_id

from pm_batch_line pbl,
pm_batch_header pbh,
item

WHERE pbl.item_id_m = item.item_id_m
AND item.org_id = pbh.org_id
AND pbl.pm_batch_header_id='{$header_id}'
AND pbl.pm_batch_header_id= pbh.pm_batch_header_id

UNION
SELECT
pbb.pm_batch_byproduct_id as line_id,  'pm_batch_byproduct' as line_type_code , pbb.pm_batch_header_id, 'By Product'  as line_type,
pbb.line_no, pbb.step_no, pbb.item_id_m, pbb.uom_id, pbb.planned_quantity,
pbb.actual_quantity, pbb.subinventory_id, pbb.locator_id, item.item_number,
item.item_description, item.lot_generation, item.serial_generation, pbh.org_id

from pm_batch_byproduct pbb,
pm_batch_header pbh,
item

WHERE pbb.item_id_m = item.item_id_m
AND item.item_id = item.item_id_m     
AND pbb.pm_batch_header_id='{$header_id}'    
AND pbb.pm_batch_header_id= pbh.pm_batch_header_id "
  ;

  $result = self::find_by_sql($sql);

  return !empty($result) ? $result : '';
 }

}

//end of pm_batch_line class
?>