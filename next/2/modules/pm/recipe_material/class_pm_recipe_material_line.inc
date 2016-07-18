<?php

class pm_recipe_material_line extends dbObject {

 public static $table_name = "pm_recipe_material_line";
 public static $primary_column = "pm_recipe_material_line_id";
 public static $parent_primary_column = "pm_recipe_material_header_id";
 public static $key_column = 'step_no';
 public static $module = "pm";
 public $field_a = [
  'pm_recipe_material_line_id',
  'pm_recipe_material_header_id',
  'step_no',
  'pm_formula_ingredient_id',
  'pm_formula_line_id',
  'pm_formula_byproduct_id',
  'description',
  'pm_process_routing_line_id',
  'quantity',
  'uom_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'pm_recipe_material_header_id',
  'step_no'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "pm_recipe_material_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  'operation_name',
  'step_qty',
  'uom_id',
  'item_number',
  'item_type',
  'item_quantity',
  'line_uom_id'
 ];
 public $pm_recipe_material_line_id;
 public $pm_recipe_material_header_id;
 public $step_no;
 public $pm_formula_ingredient_id;
 public $pm_formula_byproduct_id;
 public $pm_formula_line_id;
 public $description;
 public $pm_process_routing_line_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $quantity;
 public $uom_id;

}

//end of pm_recipe_material_line class
?>