<?php

class pm_formula_line extends dbObject {

 public static $table_name = "pm_formula_line";
 public static $primary_column = "pm_formula_line_id";
 public static $parent_primary_column = "pm_formula_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "pm";
 public static $yield_type_a = [
  'AUTO' => 'Automatic',
  'MANUAL' => 'Manual',
  'INC' => 'Incremental',
  'AUTOBS' => 'Auto By Step',
 ];
 public static $scale_type_a = [
  'FIX' => 'Fixed',
  'PROP' => 'Proportional',
 ];
 public $field_a = [
  'pm_formula_line_id',
  'pm_formula_header_id',
  'line_no',
  'line_type',
  'item_id_m',
  'uom_id',
  'quantity',
  'description',
  'cost_allocation',
  'scale_type',
  'yield_type',
  'byproduct_type',
  'consumption_type',
  'phantom_type',
  'required_qty',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'pm_formula_header_id',
  'item_id_m',
  'uom_id',
  'quantity',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "pm_formula_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  'item_description',
 ];
 public $pm_formula_line_id;
 public $pm_formula_header_id;
 public $line_no;
 public $line_type;
 public $item_id_m;
 public $uom_id;
 public $quantity;
 public $description;
 public $cost_allocation;
 public $scale_type;
 public $yield_type;
 public $byproduct_type;
 public $consumption_type;
 public $phantom_type;
 public $required_qty;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $item_description;

 private function _find_all_childs($result_line, &$child_final_result) {
  $sql = " SELECT * FROM pm_formula_line WHERE pm_formula_header_id = :pm_formula_header_id AND parent_prj_task_num = :parent_prj_task_num ";
  $sql .= " ORDER BY task_level_weight ASC ";
	  global $db;
  $value_a = ['pm_formula_header_id' => $this->pm_formula_header_id , 'parent_prj_task_num' => $result_line->task_number ];
  $result = $db->findBySql($sql, $value_a);
  
  if ($result) {
   foreach ($result as $result_line_l) {
    $child_final_result_a = [];
    $this->_find_all_childs($result_line_l, $child_final_result_a);
    array_push($child_final_result, $result_line_l);
    if (!empty($child_final_result_a)) {
     foreach ($child_final_result_a as $k => $obj) {
      array_push($child_final_result, $obj);
     }
    }
   }
  }
 }

 public static function find_allLine_byHeaderId($header_id) {
  $sql = " SELECT
pfl.pm_formula_line_id,   pfl.pm_formula_header_id,   pfl.line_no,   pfl.line_type,   pfl.item_id_m,   pfl.uom_id,   pfl.quantity,
pfl.description,   pfl.cost_allocation,   pfl.scale_type,   pfl.yield_type,   pfl.byproduct_type,   pfl.consumption_type,   pfl.phantom_type,
pfl.required_qty, item.item_number, item.item_description

from pm_formula_line pfl,
pm_formula_header pfh,
item

WHERE item.item_id_m = pfl.item_id_m
and pfh.pm_formula_header_id = pfl.pm_formula_header_id
and pfh.org_id =item.org_id
and pfl.pm_formula_header_id = :pm_formula_header_id
";

	  global $db;
  $value_a = ['pm_formula_header_id' => $header_id];
  $result_array = $db->findBySql($sql, $value_a);

  return !empty($result_array) ? $result_array : false;
 }

 public static function find_by_headerId_recipeMaterial($header_id) {
  $sql = "  SELECT 
   pfl.pm_formula_line_id,   pfl.pm_formula_header_id,   pfl.line_no,   pfl.line_type,   pfl.item_id_m,   pfl.uom_id,   pfl.quantity,
pfl.description,   pfl.cost_allocation,   pfl.scale_type,   pfl.yield_type,   pfl.byproduct_type,   pfl.consumption_type,   pfl.phantom_type,
pfl.required_qty,
   rml.pm_recipe_material_line_id,  	rml.pm_process_routing_line_id, rml.step_no
  
  FROM pm_formula_line as pfl,
  pm_recipe_material_line rml
  
  WHERE rml.pm_formula_line_id = pfl.pm_formula_line_id
  and pfl.pm_formula_header_id = :pm_formula_header_id
";

  	  global $db;
  $value_a = ['pm_formula_header_id' => $header_id];
  $result_array = $db->findBySql($sql, $value_a);
  
  return !empty($result_array) ? $result_array : false;
 }


  public static function find_all_by_formulaHeaderId($pm_formula_header_id) {
  $sql = " SELECT 
pfl.pm_formula_line_id,   pfl.pm_formula_header_id,   pfl.line_no,   pfl.line_type,   pfl.item_id_m,   pfl.uom_id,   pfl.quantity,
pfl.description,   pfl.cost_allocation,   pfl.scale_type,   pfl.yield_type,   pfl.byproduct_type,   pfl.consumption_type,   pfl.phantom_type,
pfl.required_qty,
item.item_number, item.item_description

from pm_formula_line pfl,
pm_formula_header pfh,
item

WHERE item.item_id_m = pfl.item_id_m
and pfh.pm_formula_header_id =pfl.pm_formula_header_id
and pfh.org_id =item.org_id
and pfh.pm_formula_header_id = :pm_formula_header_id
";


  	  global $db;
  $value_a = ['pm_formula_header_id' => $pm_formula_header_id];
  $result_array = $db->findBySql($sql, $value_a);
  
  return !empty($result_array) ? $result_array : false;
 }

}

//end of pm_formula_line class
?>