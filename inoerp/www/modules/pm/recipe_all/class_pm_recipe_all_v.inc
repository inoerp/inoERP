<?php

class pm_recipe_all_v extends dbObject {

 public static $table_name = "pm_recipe_all_v";
 public static $primary_column = "pm_recipe_header_id";
 public static $form_class_name = "pm_recipe_header";
 public static $system_info = [
  'name' => 'PO All View',
  'number' => '2810',
  'description' => 'View for all PO Information',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'po',
  'weight' => 1
 ];
 public $field_a = [
  'pm_recipe_header_id',
  'org_id',
  'recipe_name',
  'pm_formula_header_id',
  'pm_process_routing_header_id',
  'item_id_m',
  'formula_name',
  'formula_description',
  'routing_name',
  'routing_description',
  'item_number',
  'item_description',
  'org'
 ];
 public $initial_search = [
  "recipe_name",
  "formula_name",
  'routing_name',
  "item_number",
  
 ];
 public static $json_label_fields = [
  "recipe_name",
  "formula_name",
  'routing_name',
  "item_number",
  'org'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=pm_recipe_header',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_view_path' => 'form.php?class_name=pm_recipe_header_id',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " All Recipes "; //page Title
 public $search_functions = [
  'Organization' => 'search_org_name',
 ];
 public $pm_recipe_header_id;
 public $org_id;
 public $recipe_name;
 public $pm_formula_header_id;
 public $pm_process_routing_header_id;
 public $item_id_m;
 public $formula_name;
 public $formula_description;
 public $routing_name;
 public $routing_description;
 public $item_number;
 public $item_description;
 public $org;

 private function create_pm_recipe_all_v() {
  $sql = "
CREATE OR REPLACE VIEW pm_recipe_all_v
(
pm_recipe_header_id, org_id, recipe_name, pm_formula_header_id, pm_process_routing_header_id, item_id_m,
formula_name, formula_description, routing_name, routing_description, 
item_number, item_description, org
)
AS
SELECT
prh.pm_recipe_header_id, prh.org_id, prh.recipe_name, prh.pm_formula_header_id, prh.pm_process_routing_header_id, prh.item_id_m,
pfh.formula_name, pfh.description as formula_description, pprh.routing_name, pprh.description as routing_description, 
item.item_number, item.item_description as item_description, org.org
FROM 
pm_recipe_header prh
LEFT JOIN item ON item.item_id_m = prh.item_id_m AND item.org_id = prh.org_id ,
pm_formula_header pfh,
pm_process_routing_header pprh,
org

WHERE prh.pm_formula_header_id = pfh.pm_formula_header_id
AND prh.pm_process_routing_header_id = pprh.pm_process_routing_header_id
AND org.org_id = prh.org_id

";
 }

}

//end of po_detail class
?>