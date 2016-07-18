<?php

class pm_batch_ingredient extends dbObject {

 public static $table_name = "pm_batch_ingredient";
 public static $primary_column = "pm_batch_ingredient_id";
 public static $parent_primary_column = "pm_batch_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "pm";
 public static $source_a = [
  'ESTIMATES' => 'Estimates',
  'WORK_ORDER' => 'Work Order',
 ];
 public static $consumption_type_a = [
  'AUTO' => 'Automatic',
  'MANUAL' => 'Manual',
  'INC' => 'Incremental',
  'AUTOBS' => 'Auto By Step',
 ];
//  data base variables as stored database column name
 public $field_a = [
  'pm_batch_ingredient_id',
  'pm_batch_header_id',
  'line_no',
  'revision_name',
  'item_id_m',
  'uom_id',
  'planned_quantity',
  'description',
  'wip_planned_quantity',
  'scale_type',
  'contribute_yield_cb',
  'byproduct_type',
  'consumption_type',
  'phantom_type',
  'allocated_quantity',
  'actual_quantity',
  'requirement_date',
  'subinventory_id',
  'locator_id',
  'step_no',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'pm_batch_header_id'
 ];
 public $requiredField = [
  'pm_batch_header_id',
  'item_id_m'
 ];
 public $pm_batch_ingredient_id;
 public $pm_batch_header_id;
 public $line_no;
 public $revision_name;
 public $item_id_m;
 public $uom_id;
 public $planned_quantity;
 public $description;
 public $wip_planned_quantity;
 public $scale_type;
 public $step_no;
 public $contribute_yield_cb;
 public $byproduct_type;
 public $consumption_type;
 public $phantom_type;
 public $allocated_quantity;
 public $actual_quantity;
 public $requirement_date;
 public $subinventory_id;
 public $locator_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_allLine_byHeaderId($header_id) {
  $sql = " SELECT 
pfi.pm_batch_ingredient_id, pfi.pm_batch_header_id, pfi.line_no, pfi.revision_name, pfi.item_id_m,
pfi.uom_id, pfi.quantity, pfi.description, pfi.scale_type, pfi.contribute_yield_cb, pfi.consumption_type,
pfi.buffer_cb, pfi.phantom_type, pfi.required_qty,
item.item_number, item.item_description

from pm_batch_ingredient pfi,
pm_batch_header pfh,
item

WHERE item.item_id_m = pfi.item_id_m
and pfh.pm_batch_header_id =pfi.pm_batch_header_id
and pfh.org_id =item.org_id
and pfi.pm_batch_header_id = '{$header_id}'
";

  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

 public static function find_all_lines_for_trnx_by_headerId($header_id) {
  $sql = "SELECT
pbi.pm_batch_ingredient_id,   pbi.pm_batch_header_id, pbi.line_no, pbi.step_no, pbi.item_id_m, pbi.uom_id, pbi.planned_quantity,
pbi.actual_quantity, pbi.subinventory_id, pbi.locator_id, item.item_number,
item.item_description, item.lot_generation, item.serial_generation,
pbh.org_id, pbh.wip_accounting_group_id

from pm_batch_ingredient pbi,
item,
pm_batch_header pbh

WHERE pbi.item_id_m = item.item_id_m
AND item.item_id = item.item_id_m
AND pbh.pm_batch_header_id = pbi.pm_batch_header_id
AND pbi.pm_batch_header_id='{$header_id}'
 "
  ;

  $result = self::find_by_sql($sql);

  return !empty($result) ? $result : '';
 }

}

//end of pm_batch_ingredient class
?>