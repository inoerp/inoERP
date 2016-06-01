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
 }
 
 private function _do_resource_trnx(){
  
 }
 
  private function _do_material_trnx(){
  
 }

 public static function find_by_headerId_and_buOrgId($pm_batch_operation_header_id, $bu_org_id) {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where pm_batch_operation_header_id= '{$pm_batch_operation_header_id}' AND bu_org_id= '{$bu_org_id}' LIMIT 1 ";
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
pbod.pm_batch_operation_detail_id, pbod.resource_sequence, pbod.description, pbod.bom_resource_id, pbod.process_quantity,
pbod.resource_usage, pbod.batch_uom_id, pbod.uom_id, pbod.batch_quantity, pbod.component_class, pbod.cost_analysis_code,
pbod.plan_type, pbod.resource_count, pbol.pm_batch_operation_line_id, pbol.pm_batch_header_id, pbol.step_no, pbol.pm_process_routing_header_id,
pbol.activity_code, pbol.description, pbol.activity_factror, pbol.sequence_dependency_cb, pbol.offset_interval,
pbol.breakable_cb, pbol.material_scheduled_cb

FROM pm_batch_operation_line pbol,
pm_batch_operation_detail pbod

WHERE pbol.pm_batch_operation_line_id = pbod.pm_batch_operation_line_id
AND pbol.pm_batch_operation_line_id = '{$op_line_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of pm_batch_operation_line class
?>