<?php

class pm_formula_line extends dbObject {

 public static $table_name = "pm_formula_line";
 public static $primary_column = "pm_formula_line_id";
 public static $parent_primary_column = "pm_formula_header_id";
 public static $key_column = 'task_number';
 public static $module = "sd";
 public static $action_a = [
  "PROCESS" => 'Process Order',
  "BOOK" => 'Book Order',
  "CANCEL" => 'Cancel Order',
 ];
 public $line_status_a = [
  'ENTERED' => 'Entered',
  'AWAITING_PICKING' => 'Awaiting Picking',
  'PICKED' => 'Picked',
  'PARTIAL_PICKED' => 'Partially Picked',
  'SHIPPED' => 'Shipped',
  'PARTIAL_SHIPPED' => 'Partial Shipped',
  'CLOSED' => 'Closed',
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
  'task_level_weight',
  'task_number',
  'task_name',
  'work_type',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "pm_formula_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  'task_seq_number',
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


 private function _validate_before_save() {
  $ret = 1;
  $item = item::find_by_orgId_item_id_m($this->item_id_m, $this->inv_org_id);
  if ($item) {
   if (empty($item->customer_ordered_cb)) {
    $ret = -90;
    echo "<br> The item is not enabled for Sales ";
   }
  } else {
   $ret = -90;
   echo "<br> The item is not assigned to the organization";
  }

  return $ret;
 }

 public function findBy_parentId($pm_formula_header_id, $order_by_field = '', $order_by_seq = '') {
  /*
   * 1. Find all where parent project task number is null
   */
  $final_result = [];
  if (!ino_validate_num($pm_formula_header_id)) {
   return false;
  }
  $this->pm_formula_header_id = $pm_formula_header_id;
  $sql = " SELECT * FROM pm_formula_line WHERE pm_formula_header_id = '{$pm_formula_header_id}' AND parent_prj_task_num IS NULL ";
  $sql .= " ORDER BY task_level_weight ASC ";
  $result = self::find_by_sql($sql);

  if ($result) {
   foreach ($result as $result_line) {
    $child_final_result = [];
    $this->_find_all_childs($result_line, $child_final_result);
    array_push($final_result, $result_line);
    if (!empty($child_final_result)) {
     foreach ($child_final_result as $k => $obj) {
      array_push($final_result, $obj);
     }
    }
   }
  }
//  pa($final_result);
  return $final_result;
 }

 private function _find_all_childs($result_line, &$child_final_result) {
  $sql = " SELECT * FROM pm_formula_line WHERE pm_formula_header_id = '{$this->pm_formula_header_id}' AND parent_prj_task_num ='{$result_line->task_number}' ";
  $sql .= " ORDER BY task_level_weight ASC ";
  $result = self::find_by_sql($sql);
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

 public function _before_save() {
//  if ($this->_validate_before_save() < 0) {
//   return -90;
//  }

  if (empty($this->task_level_weight) && !empty($this->task_number)) {
   $task_number_a = explode('-', $this->task_number);
   $this->task_level_weight = array_pop($task_number_a);
  }

  if (!empty($this->action)) {
   $this->_do_action();
  }

//  if ((empty($this->line_status)) && (empty($this->sd_so_line_id))) {
//   $this->line_status = 'PENDING_IMPORT';
//   echo "<div class='alert alert-danger'>Line status is updated to <strong> " . $this->line_status . ".</strong></div> ";
//  }
 }

 public function _after_save() {
  
 }

 private function _do_action() {
  switch ($this->action) {
   case 'PROCESS':
    $this->_process_line_to_so();
    break;

   case 'PROCESS_ACTUALS':
    $this->copy_estimates();
    break;

   default :
    break;
  }
 }

 public static function find_allLowestTask_byHeaderId($header_id) {
  $sql = " SELECT prl.task_number, prl.task_name,  prl.description as task_description, 
   prl.pm_formula_line_id, prl.pm_formula_header_id, prl.parent_prj_task_num
FROM pm_formula_line prl
WHERE    
prl.pm_formula_header_id = '{$header_id}'
prl.task_number NOT IN(
SELECT prl.parent_prj_task_num
FROM pm_formula_line prl
WHERE    prl.parent_prj_task_num IS NOT NULL
)
";

  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

}

//end of pm_formula_line class
?>