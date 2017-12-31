<?php

class pm_batch_byproduct extends dbObject {

 public static $table_name = "pm_batch_byproduct";
 public static $primary_column = "pm_batch_byproduct_id";
 public static $parent_primary_column = "pm_batch_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "pm";
 public static $byproduct_type_a = [
  'REWORK' => 'Rework',
  'SAMPLE' => 'Sample',
  'WASTE' => 'Waste',
  'YIELD' => 'Yield',
 ];
//  data base variables as stored database column name
 public $field_a = [
  'pm_batch_byproduct_id',
  'pm_batch_header_id',
  'line_no',
  'line_type',
  'item_id_m',
  'uom_id',
  'allocated_quantity',
  'step_no',
  'planned_quantity',
  'actual_quantity',
  'description',
  'scale_type',
  'yield_type',
  'byproduct_type',
  'subinventory_id',
  'locator_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data

 public $fields_inHeader_needsToBeInserted_inPOST = [
  'pm_batch_header_id'
 ];
 public $requiredField = [
  'pm_batch_header_id',
  'item_id_m',
 ];
 public $pm_batch_byproduct_id;
 public $pm_batch_header_id;
 public $line_no;
 public $line_type;
 public $item_id_m;
 public $uom_id;
 public $quantity;
 public $description;
 public $scale_type;
 public $yield_type;
 public $step_no;
 public $actual_quantity;
 public $allocated_quantity;
 public $planned_quantity;
 public $byproduct_type;
 public $subinventory_id;
 public $locator_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of pm_batch_byproduct class
?>