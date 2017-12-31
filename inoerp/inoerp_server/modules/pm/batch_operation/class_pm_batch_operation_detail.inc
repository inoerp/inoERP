<?php

class pm_batch_operation_detail extends dbObject {

 public static $table_name = "pm_batch_operation_detail";
 public static $primary_column = "pm_batch_operation_detail_id";
 public static $parent_primary_column = "pm_batch_operation_line_id";
 public static $key_column = 'bom_resource_id';
 public static $module = "pm";
 public $field_a = [
  'pm_batch_operation_detail_id',
  'pm_batch_operation_line_id',
  'resource_sequence',
  'description',
  'bom_resource_id',
  'process_quantity',
  'resource_usage',
  'batch_uom_id',
  'uom_id',
  'batch_quantity',
  'applied_quantiy',
  'component_class',
  'cost_analysis_code',
  'plan_type',
  'resource_count',
  'offset_interval',
  'scale_type',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'pm_batch_operation_line_id',
  'pm_batch_header_id'
 ];
 public $requiredField = [
  'pm_batch_operation_line_id',
  'pm_batch_header_id',
  'resource_sequence',
  'bom_resource_id',
  'resource_usage',
 ];
 public $pm_batch_operation_detail_id;
 public $pm_batch_operation_line_id;
 public $resource_sequence;
 public $description;
 public $bom_resource_id;
 public $process_quantity;
 public $applied_quantiy;
 public $resource_usage;
 public $batch_uom_id;
 public $batch_quantity;
 public $uom_id;
 public $component_class;
 public $cost_analysis_code;
 public $plan_type;
 public $resource_count;
 public $offset_interval;
 public $scale_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function _before_save() {
  return 10;
 }

}

//end of bom_detail_line class
?>