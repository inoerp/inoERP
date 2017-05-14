<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * hd_ro_header CLass
 * Contains all the pm_batch_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class pm_batch_header extends dbObject {

 public static $table_name = "pm_batch_header";
 public static $dependent_classes = ['pm_batch_line', 'pm_batch_ingredient', 'pm_batch_byproduct'];
 public static $primary_column = "pm_batch_header_id";
 public static $key_column = 'batch_name';
 public static $module = "pm";
 public static $system_info = [
  'name' => 'batch',
  'number' => '2801',
  'description' => 'Create & Mainten Process Batch',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('pm_batch_line', 'pm_batch_ingredient', 'pm_batch_byproduct'),
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 1
 ];
 public static $status_a = [
  'PENDING' => 'Pending',
  'WIP' => 'WIP',
  'COMPLETED' => 'Completed',
  'CLOSED' => 'Closed',
  'CANCELLED' => 'Cancelled',
 ];
 public $action_a = [
  'RELEASE' => 'Release',
  'PRINT' => 'Print',
  'CANCEL' => 'Cancel',
  'CLOSE' => 'Close'
  ];
 public $field_a = [
  'pm_batch_header_id',
  'batch_name',
  'org_id',
  'pm_recipe_header_id',
  'wip_accounting_group_id',
  'recipe_version',
  'comment',
  'status',
  'description',
  'terminate_reason',
  'planned_start_date',
  'planned_completion_date',
  'required_completion_date',
  'actual_completion_date',
  'actual_start_date',
  'update_invnetory_cb',
  'batch_exploded_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'batch_name',
  'description',
  'status',
 ];
 public $requiredField = [
  'org_id',
  'pm_recipe_header_id',
 ];
 public static $json_label_fields = [
  'batch_name',
  'description',
  'status',
  'org_id',
 ];
 public $fields_inForm_notInDataBase = [
  'recipe_name',
  "routing_name",
  'formula_name',
  'action'
 ];
 public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Production Batch "; //page Title
 public $pm_batch_header_id;
 public $org_id;
 public $batch_name;
 public $pm_recipe_header_id;
 public $wip_accounting_group_id;
 public $recipe_version;
 public $comment;
 public $status;
 public $description;
 public $terminate_reason;
 public $planned_start_date;
 public $planned_completion_date;
 public $required_completion_date;
 public $actual_completion_date;
 public $actual_start_date;
 public $update_invnetory_cb;
 public $batch_exploded_cb;
  public $actual_quantity;
 public $allocated_quantity;
 public $planned_quantity;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $action;
 public $recipe_name;
 private $_pm_formula_header_id;
 private $_pm_process_routing_header_id;

 private function _do_action() {
  switch ($this->action) {
   case 'RELEASE':
    $this->status = 'WIP';
    break;

   default :
    echo $this->action;
    break;
  }
 }

 public function _before_save() {
  if (!empty($this->action)) {
   $this->_do_action();
  }

  if (empty($this->status)) {
   $this->status = 'PENDING';
  }
 }

 public function _after_save() {
  global $dbc, $ie;
  if ((!empty($this->pm_batch_header_id)) && empty($this->batch_name)) {
   $this->batch_name = $this->org_id . '-' . $this->pm_batch_header_id;
   echo ' System generated Batch number is ' . $this->batch_name;
   $this->save();
  }

  //copy line details
  if ((!empty($this->pm_recipe_header_id)) && (empty($this->batch_exploded_cb))) {
   try {
    $this->_copy_batch_lines();
    $this->batch_exploded_cb = 1;
    echo ' System generated Batch number is ' . $this->batch_name;
    $this->save();
   } catch (Exception $e) {
    array_push($ie->user_exp, 'Unable to copy batch product details. Error @ ' . basename(__FILE__) . ' @@ ' . __LINE__ . ' - ' . $e->getMessage());
    $dbc->rollback = 1;
   }
  }
 }

 private function _copy_batch_lines() {
  $recipe_details = pm_recipe_header::find_by_id($this->pm_recipe_header_id);
  $this->_pm_formula_header_id = $recipe_details->pm_formula_header_id;
  $this->_pm_process_routing_header_id = $recipe_details->pm_process_routing_header_id;

  $this->_copy_batch_products();
  $this->_copy_batch_ingredients();
  $this->_copy_batch_byproducts();
  $this->_copy_batch_routings();
 }

 private function _copy_batch_products() {
  global $dbc, $ie;
  $all_product_lines = pm_formula_line::find_by_headerId_recipeMaterial($this->_pm_formula_header_id);
   //check if batch products exists
  $bacth_lines = pm_batch_line::find_by_parent_id($this->pm_batch_header_id);
  if (!empty($bacth_lines) || empty($all_product_lines)) {
   return -1;
  }
  $pbl = new pm_batch_line();
  foreach ($all_product_lines as $product_line) {
   $pbl->pm_batch_line_id = null;
   foreach ($pbl->field_a as $pbl_k => $pbl_v) {
    if (property_exists($product_line, $pbl_v)) {
     $pbl->$pbl_v = $product_line->$pbl_v;
    }
   }
   $pbl->pm_batch_header_id = $this->pm_batch_header_id;
   try {
    $pbl->save();
   } catch (Exception $e) {
    array_push($ie->user_exp, 'Unable to copy batch product. Error @ ' . basename(__FILE__) . ' @@ ' . __LINE__ . ' - ' . $e->getMessage());
    $dbc->rollback = 1;
   }
  }
 }

 private function _copy_batch_byproducts() {
  global $dbc, $ie;
  $all_byproduct_lines = pm_formula_byproduct::find_by_headerId_recipeMaterial($this->_pm_formula_header_id);
  //check if batch products exists
  $byproduct_lines = pm_batch_byproduct::find_by_parent_id($this->pm_batch_header_id);
  if (!empty($byproduct_lines) || empty($all_byproduct_lines)) {
   return -1;
  }
  $pbb = new pm_batch_byproduct();
  foreach ($all_byproduct_lines as $byproduct_line) {
   $pbb->pm_batch_byproduct_id = null;
   foreach ($pbb->field_a as $pbb_k => $pbb_v) {
    if (property_exists($byproduct_line, $pbb_v)) {
     $pbb->$pbb_v = $byproduct_line->$pbb_v;
    }
   }
   $pbb->pm_batch_header_id = $this->pm_batch_header_id;
   try {
    $pbb->save();
   } catch (Exception $e) {
    array_push($ie->user_exp, 'Unable to copy batch by product. Error @ ' . basename(__FILE__) . ' @@ ' . __LINE__ . ' - ' . $e->getMessage());
    $dbc->rollback = 1;
   }
  }
 }

 private function _copy_batch_ingredients() {
  global $dbc, $ie;
  $all_ingredient_lines = pm_formula_ingredient::find_by_headerId_recipeMaterial($this->_pm_formula_header_id);
  //check if batch products exists
  $ingredient_lines = pm_batch_ingredient::find_by_parent_id($this->pm_batch_header_id);
  if (!empty($ingredient_lines)|| empty($all_ingredient_lines)) {
   return -1;
  }
    $pbi = new pm_batch_ingredient();
  foreach ($all_ingredient_lines as $ingredient_line) {
   $pbi->pm_batch_ingredient_id = null;
   foreach ($pbi->field_a as $pbi_k => $pbi_v) {
    if (property_exists($ingredient_line, $pbi_v)) {
     $pbi->$pbi_v = $ingredient_line->$pbi_v;
    }
   }
   $pbi->pm_batch_header_id = $this->pm_batch_header_id;
   try {
    $pbi->save();
   } catch (Exception $e) {
    array_push($ie->user_exp, 'Unable to copy batch ingredient. Error @ ' . basename(__FILE__) . ' @@ ' . __LINE__ . ' - ' . $e->getMessage());
    $dbc->rollback = 1;
   }
  }
 }

 private function _copy_batch_routings() {
  /*
   * 
   */
  global $dbc, $ie;
  $all_routing_lines = pm_process_routing_line::find_by_parent_id($this->_pm_process_routing_header_id);
  //check if batch products exists
  $batch_routing_lines_check = pm_batch_operation_line::find_by_parent_id($this->pm_batch_header_id);
  if (!empty($batch_routing_lines_check)) {
   return -1;
  }
  $pbol = new pm_batch_operation_line();
  foreach ($all_routing_lines as $routing_line) {
   $all_operation_lines = pm_process_operation_line::find_by_parent_id($routing_line->pm_process_operation_header_id);
//   pa($all_operation_lines);pa($pbol);
   if (empty($all_operation_lines)) {
    continue;
   }
   foreach ($all_operation_lines as $operation_line) {
    $pbol->pm_batch_operation_line_id = null;
    foreach ($pbol->field_a as $pbol_k => $pbol_v) {
     if (property_exists($operation_line, $pbol_v)) {
      $pbol->$pbol_v = $operation_line->$pbol_v;
     }
    }
    $pbol->pm_batch_header_id = $this->pm_batch_header_id;
    $pbol->step_no = $routing_line->step_no;
    $pbol->release_type = $routing_line->release_type;
    $pbol->pm_process_routing_header_id = $routing_line->pm_process_operation_header_id;
    try {
     $pbol->save();
     $this->_copy_batch_operation_details($pbol);
    } catch (Exception $e) {
     array_push($ie->user_exp, 'Unable to copy batch routing line. Error @ ' . basename(__FILE__) . ' @@ ' . __LINE__ . ' - ' . $e->getMessage());
     $dbc->rollback = 1;
    }
   }
  }
 }

 private function _copy_batch_operation_details($pbol) {
  global $dbc, $ie;

//  $pbol = new pm_batch_operation_line();

  $all_detail_lines = pm_process_operation_detail::find_by_fieldVal(['pm_process_operation_header_id', $pbol->pm_process_operation_header_id]);
  $pbod = new pm_batch_operation_detail();
  foreach ($all_detail_lines as $routing_detail) {
   $pbod->pm_batch_operation_line_id = null;
   foreach ($pbod->field_a as $pbod_k => $pbod_v) {
    if (property_exists($routing_detail, $pbod_v)) {
     $pbod->$pbod_v = $routing_detail->$pbod_v;
    }
   }
   $pbod->pm_batch_operation_line_id = $pbol->pm_batch_operation_line_id;
   try {
    $pbod->save();
   } catch (Exception $e) {
    array_push($ie->user_exp, 'Unable to copy batch detail line. Error @ ' . basename(__FILE__) . ' @@ ' . __LINE__ . ' - ' . $e->getMessage());
    $dbc->rollback = 1;
   }
  }
 }
 



}

//end of pm_batch_header class
?>