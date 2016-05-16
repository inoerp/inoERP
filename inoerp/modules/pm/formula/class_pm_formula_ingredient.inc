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

 public static function find_allLine_byHeaderId($header_id) {
  $sql = " SELECT 
pfi.pm_formula_ingredient_id, pfi.pm_formula_header_id, pfi.line_no, pfi.revision_name, pfi.item_id_m,
pfi.uom_id, pfi.quantity, pfi.description, pfi.scale_type, pfi.contribute_yield_cb, pfi.consumption_type,
pfi.buffer_cb, pfi.phantom_type, pfi.required_qty,
item.item_number, item.item_description

from pm_formula_ingredient pfi,
pm_formula_header pfh,
item

WHERE item.item_id_m = pfi.item_id_m
and pfh.pm_formula_header_id =pfi.pm_formula_header_id
and pfh.org_id =item.org_id
and pfi.pm_formula_header_id = '{$header_id}'
";

  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

 public static function find_by_headerId_recipeMaterial($header_id) {
  $sql = "  SELECT fih.pm_formula_ingredient_id,   fih.pm_formula_header_id,   fih.line_no,
  fih.revision_name,   fih.item_id_m,   fih.uom_id,   fih.quantity,
  fih.description,   fih.scale_type,   fih.contribute_yield_cb,   fih.consumption_type,
  fih.buffer_cb,   fih.phantom_type,   fih.required_qty,   fih.created_by,
  fih.creation_date,   fih.last_update_by,   fih.last_update_date,
   rml.pm_recipe_material_line_id,  	rml.pm_process_routing_line_id, rml.step_no
  
  FROM pm_formula_ingredient as fih,
  pm_recipe_material_line rml
  
  WHERE rml.pm_formula_ingredient_id = fih.pm_formula_ingredient_id
  and fih.pm_formula_header_id = '{$header_id}'
";

  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

 public static function find_all_by_formulaHeaderId($pm_formula_header_id) {
  $sql = " SELECT 
pfi.pm_formula_ingredient_id, pfi.pm_formula_header_id, pfi.line_no, pfi.revision_name, pfi.item_id_m,
pfi.uom_id, pfi.quantity, pfi.description, pfi.scale_type, pfi.contribute_yield_cb, pfi.consumption_type,
pfi.buffer_cb, pfi.phantom_type, pfi.required_qty,
item.item_number, item.item_description

from pm_formula_ingredient pfi,
pm_formula_header pfh,
item

WHERE item.item_id_m = pfi.item_id_m
and pfh.pm_formula_header_id =pfi.pm_formula_header_id
and pfh.org_id =item.org_id
and pfh.pm_formula_header_id = '{$pm_formula_header_id}'
";


  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

}

//end of pm_formula_ingredient class
?>