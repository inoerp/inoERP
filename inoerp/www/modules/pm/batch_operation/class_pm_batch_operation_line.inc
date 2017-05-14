<?php

class pm_batch_operation_line extends dbObject {

 public static $table_name = "pm_batch_operation_line";
 public static $primary_column = "pm_batch_operation_line_id";
 public static $parent_primary_column = "pm_batch_header_id";
 public static $key_column = 'activity_code';
 public static $module = "pm";
 public static $release_type_a = [
  'AUTO' => 'Automatic',
  'MANUAL' => 'Manual'
 ];
 public static $line_action_a = [
  'COMPLETED' => 'Completed',
  'CLOSED' => 'Closed'
 ];
 public static $line_status_a = [
  'COMPLETE' => 'Complete',
  'CLOSE' => 'Close'
 ];
 public $field_a = [
  'pm_batch_operation_line_id',
  'pm_batch_header_id',
  'step_no',
  'pm_process_routing_header_id',
  'activity_code',
  'description',
  'activity_factror',
  'release_type',
  'sequence_dependency_cb',
  'offset_interval',
  'breakable_cb',
  'material_scheduled_cb',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'pm_batch_header_id',
  'activity_code'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "pm_batch_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  'line_action'
 ];
 public $pm_batch_operation_line_id;
 public $pm_batch_header_id;
 public $pm_process_routing_header_id;
 public $release_type;
 public $step_no;
 public $activity_code;
 public $description;
 public $activity_factror;
 public $sequence_dependency_cb;
 public $offset_interval;
 public $breakable_cb;
 public $material_scheduled_cb;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $line_action;

 public function _before_save() {
  if (empty($this->line_action)) {
   return 10;
  } else {
   $this->_do_line_action();
  }
 }

 private function _do_line_action() {
  //complete resource and material transaction
  $existing_line = self::find_by_id($this->pm_batch_operation_line_id);

  if (empty($existing_line->status)) {
   if (empty($this->line_action == 'COMPLETE')) {
    $this->_do_resource_trnx();
    $this->_do_material_trnx();
    $this->status = 'COMPLETED';
   } else if (empty($this->line_action == 'CLOSE')) {
    $this->status = 'CLOSED';
   }
  } else {
   echo "<br>Line status does not allow update";
  }
 }

 private function _do_resource_trnx() {
  $op_details_a = self::find_operationDetails_by_operationLineId($this->pm_batch_operation_line_id);
  foreach ($op_details_a as $op_details) {
   $res_trnx = new pm_resource_transaction();
   foreach ($res_trnx->field_a as $k => $v) {
    if (!empty($op_details->$v)) {
     $res_trnx->$v = $op_details->$v;
    }
   }

   $res_trnx->transaction_date = current_time(1);
   $res_trnx->transaction_type = 'WIP_RESOURCE_TRANSACTION';
   $res_trnx->transaction_quantity = $op_details->process_quantity - $op_details->applied_quantiy;
   if ($res_trnx->transaction_quantity > 0) {
    $res_trnx->save();
    $res_trnx->_after_save();
   } else {
    echo gettext("No quantity to transact. All planned quantities have been issued.");
   }
//   pa($res_trnx);
  }
 }

 private function _do_material_trnx() {
  $pm_batch_ing_object = pm_batch_ingredient::find_all_lines_for_trnx_by_headerId($this->pm_batch_header_id);
  foreach ($pm_batch_ing_object as $ing_details) {
   if (!empty($ing_details->lot_generation) || $ing_details->serial_generation) {
    echo "<br>Item # {$ing_details->item_number} is not transacted as Item is Lot/Serial controlled ";
    continue;
   } else {
    $mat_trnx = new pm_material_transaction();
    foreach ($mat_trnx->field_a as $k => $v) {
     if (!empty($ing_details->$v)) {
      $mat_trnx->$v = $ing_details->$v;
     }
    }
    $mat_trnx->transaction_type_id = '29';
    $mat_trnx->quantity = $ing_details->planned_quantity - $ing_details->actual_quantity;
    if ($mat_trnx->quantity > 0) {
     $mat_trnx->_before_save();
     $mat_trnx->save();
     $mat_trnx->_after_save();
    } else {
     echo gettext("No quantity to transact. All planned quantities have been issued.");
    }

//    pa($mat_trnx);
   }
  }
 }

 public static function find_by_headerId_and_buOrgId($pm_batch_operation_header_id, $bu_org_id) {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where pm_batch_operation_header_id= '{$pm_batch_operation_header_id}' AND bu_org_id= '{$bu_org_id}'  ";
   $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_operationDetails_by_batchHeaderId($pm_batch_header_id) {
  $sql = " SELECT 
pbod.pm_batch_operation_detail_id, pbod.resource_sequence, pbod.description, pbod.bom_resource_id, pbod.process_quantity,
pbod.resource_usage, pbod.batch_uom_id, pbod.uom_id, pbod.batch_quantity, pbod.component_class, pbod.cost_analysis_code,
pbod.plan_type, pbod.resource_count, pbol.pm_batch_operation_line_id, pbol.pm_batch_header_id, pbol.step_no, pbol.pm_process_routing_header_id,
pbol.activity_code, pbol.description, pbol.activity_factror, pbol.sequence_dependency_cb, pbol.offset_interval,
pbol.breakable_cb, pbol.material_scheduled_cb

FROM pm_batch_operation_line pbol,
pm_batch_operation_detail pbod

WHERE pbol.pm_batch_operation_line_id = pbod.pm_batch_operation_line_id
AND pbol.pm_batch_header_id = '{$pm_batch_header_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_operationDetails_by_operationLineId($op_line_id) {
  $sql = " SELECT 
pbod.pm_batch_operation_detail_id, pbod.resource_sequence, pbod.description, pbod.bom_resource_id, pbod.process_quantity, pbod.applied_quantiy,
pbod.resource_usage, pbod.batch_uom_id, pbod.uom_id, pbod.batch_quantity, pbod.component_class, pbod.cost_analysis_code,
pbod.plan_type, pbod.resource_count, pbol.pm_batch_operation_line_id, pbol.pm_batch_header_id, pbol.step_no, pbol.pm_process_routing_header_id,
pbol.activity_code, pbol.description, pbol.activity_factror, pbol.sequence_dependency_cb, pbol.offset_interval,
pbol.breakable_cb, pbol.material_scheduled_cb, pbh.org_id

FROM pm_batch_operation_line pbol,
pm_batch_operation_detail pbod,
pm_batch_header pbh

WHERE pbol.pm_batch_operation_line_id = pbod.pm_batch_operation_line_id
AND pbol.pm_batch_header_id = pbh.pm_batch_header_id
AND pbol.pm_batch_operation_line_id = '{$op_line_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of pm_batch_operation_line class
?>