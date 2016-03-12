<?php

class pm_formula_ingredient extends dbObject {

 public static $table_name = "pm_formula_ingredient";
 public static $primary_column = "pm_formula_ingredient_id";
 public static $parent_primary_column = "pm_formula_header_id";
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
  'pm_formula_ingredient_id',
  'pm_formula_header_id',
  'line_no',
  'revision_name',
  'item_id_m',
  'uom_id',
  'quantity',
  'description',
  'scale_type',
  'contribute_yield_cb',
  'consumption_type',
  'buffer_cb',
  'phantom_type',
  'required_qty',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'pm_formula_header_id'
 ];
 public $requiredField = [
  'pm_formula_header_id',
  'item_id_m'
 ];
 public $pm_formula_byproduct_id;
 public $pm_formula_header_id;
 public $line_no;
 public $line_type;
 public $item_id_m;
 public $uom_id;
 public $quantity;
 public $description;
 public $contribute_yield_cb;
 public $scale_type;
 public $yield_type;
 public $step_qty_cb;
 public $consumption_type;
 public $phantom_type;
 public $required_qty;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of pm_formula_ingredient class
?>