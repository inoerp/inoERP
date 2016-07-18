<?php

class pm_formula_byproduct extends dbObject {

 public static $table_name = "pm_formula_byproduct";
 public static $primary_column = "pm_formula_byproduct_id";
 public static $parent_primary_column = "pm_formula_header_id";
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
  'pm_formula_byproduct_id',
  'pm_formula_header_id',
  'line_no',
  'line_type',
  'item_id_m',
  'uom_id',
  'allocated_quantity',
  'planned_quantity',
  'actual_quantity',
  'description',
  'scale_type',
  'yield_type',
  'byproduct_type',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $fields_inForm_notInDataBase = [
  "member_username",
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'pm_formula_header_id'
 ];
 public $requiredField = [
  'pm_formula_header_id',
  'item_id_m',
 ];
 public $pm_formula_byproduct_id;
 public $pm_formula_header_id;
 public $line_no;
 public $line_type;
 public $item_id_m;
 public $uom_id;
 public $actual_quantity;
 public $allocated_quantity;
 public $planned_quantity;
 public $description;
 public $yield_contribution_cb;
 public $scale_type;
 public $yield_type;
 public $byproduct_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_all_by_formulaHeaderId($pm_formula_header_id) {
  $sql = " SELECT
pfb.pm_formula_byproduct_id,   pfb.pm_formula_header_id,   pfb.line_no,   pfb.line_type,
pfb.item_id_m,   pfb.uom_id,   pfb.allocated_quantity,   pfb.planned_quantity,   pfb.actual_quantity,
pfb.description,   pfb.scale_type,   pfb.yield_type,   pfb.byproduct_type,   pfb.created_by,
pfb.creation_date,   pfb.last_update_by,   pfb.last_update_date,
item.item_number, item.item_description

from pm_formula_byproduct pfb,
pm_formula_header pfh,
item

WHERE item.item_id_m = pfb.item_id_m
and pfh.pm_formula_header_id =pfb.pm_formula_header_id
and pfh.org_id =item.org_id
and pfh.pm_formula_header_id = '{$pm_formula_header_id}'
";


  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

 public static function find_by_headerId_recipeMaterial($header_id) {
  
    $sql = "  SELECT
pfb.pm_formula_byproduct_id,   pfb.pm_formula_header_id,   pfb.line_no,   pfb.line_type,
pfb.item_id_m,   pfb.uom_id,   pfb.allocated_quantity,   pfb.planned_quantity,   pfb.actual_quantity,
pfb.description,   pfb.scale_type,   pfb.yield_type,   pfb.byproduct_type,   pfb.created_by,
pfb.creation_date,   pfb.last_update_by,   pfb.last_update_date,
   rml.pm_recipe_material_line_id,  	rml.pm_process_routing_line_id, rml.step_no
  
  FROM pm_formula_byproduct as pfb,
  pm_recipe_material_line rml
  
  WHERE rml.pm_formula_byproduct_id = pfb.pm_formula_byproduct_id
  and pfb.pm_formula_header_id = '{$header_id}'
";

  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

}

//end of pm_formula_byproduct class
?>