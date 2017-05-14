<?php

class pm_recipe_line extends dbObject {

 public static $table_name = "pm_recipe_line";
 public static $primary_column = "pm_recipe_line_id";
 public static $parent_primary_column = "pm_recipe_header_id";
 public static $key_column = 'org_id';
 public static $module = "pm";
 public static $org_type_a = [
  'PLANT' => 'Plant',
  'LABORATORY' => 'Laboratory'
 ];
 public $field_a = [
  'pm_recipe_line_id',
  'pm_recipe_header_id',
  'org_id',
  'org_type',
  'planned_loss',
  'fixed_loss_uom_id',
  'fixed_loss',
  'description',
  'contiguous_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'pm_recipe_header_id',
  'org_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "pm_recipe_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  'item_description',
 ];
 
 public $pm_recipe_line_id;
 public $pm_recipe_header_id;
 public $org_id;
 public $org_type;
 public $planned_loss;
 public $fixed_loss_uom_id;
 public $fixed_loss;
 public $description;
 public $contiguous_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;




}

//end of pm_recipe_line class
?>