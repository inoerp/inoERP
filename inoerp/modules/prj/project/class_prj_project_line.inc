<?php

class prj_project_line extends dbObject {

 public static $table_name = "prj_project_line";
 public static $primary_column = "prj_project_line_id";
 public static $parent_primary_column = "prj_project_header_id";
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
  'prj_project_line_id',
  'prj_project_header_id',
  'task_number',
  'task_name',
  'task_level_weight',
  'parent_prj_task_num',
  'description',
  'start_date',
  'end_date',
  'manager_user_id',
  'org_id',
  'service_type',
  'work_type',
  'allow_charges_cb',
  'capitalizable_cb',
  'milestone_cb',
  'currency',
  'rate_type',
  'cip_asset_id',
  'line_description',
  'task_status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'prj_project_header_id',
  'task_level_weight',
  'task_number',
  'task_name',
  'work_type',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "prj_project_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  'task_seq_number',
 ];
 public $prj_project_line_id;
 public $prj_project_header_id;
 public $task_number;
 public $task_name;
 public $task_level_weight;
 public $parent_prj_task_num;
 public $description;
 public $start_date;
 public $end_date;
 public $manager_user_id;
 public $org_id;
 public $service_type;
 public $work_type;
 public $allow_charges_cb;
 public $capitalizable_cb;
 public $milestone_cb;
 public $cip_asset_id;
 public $currency;
 public $rate_type;
 public $cip_asset_it;
 public $line_description;
 public $task_status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $task_seq_number;

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

 public function findBy_parentId($prj_project_header_id, $order_by_field = '', $order_by_seq = '') {
  /*
   * 1. Find all where parent project task number is null
   */
  $final_result = [];
  if (!ino_validate_num($prj_project_header_id)) {
   return false;
  }
  $this->prj_project_header_id = $prj_project_header_id;
  $sql = " SELECT * FROM prj_project_line WHERE prj_project_header_id = '{$prj_project_header_id}' AND parent_prj_task_num IS NULL ";
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
  $sql = " SELECT * FROM prj_project_line WHERE prj_project_header_id = '{$this->prj_project_header_id}' AND parent_prj_task_num ='{$result_line->task_number}' ";
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
   prl.prj_project_line_id, prl.prj_project_header_id, prl.parent_prj_task_num
FROM prj_project_line prl
WHERE    
prl.prj_project_header_id = '{$header_id}'
prl.task_number NOT IN(
SELECT prl.parent_prj_task_num
FROM prj_project_line prl
WHERE    prl.parent_prj_task_num IS NOT NULL
)
";

  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

}

//end of prj_project_line class
?>