<?php

class pm_process_operation_detail extends dbObject {

 public static $table_name = "pm_process_operation_detail";
 public static $primary_column = "pm_process_operation_detail_id";
 public static $parent_primary_column = "pm_process_operation_line_id";
 public static $key_column = 'bom_resource_id';
 public static $module = "pm";
 public $field_a = [
  'pm_process_operation_detail_id',
  'pm_process_operation_header_id',
  'pm_process_operation_line_id',
  'resource_sequence',
  'description',
  'bom_resource_id',
  'process_quantity',
  'resource_usage',
  'uom_id',
  'process_uom_id',
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
  'pm_process_operation_line_id',
  'pm_process_operation_header_id'
 ];
 public $requiredField = [
  'pm_process_operation_line_id',
  'pm_process_operation_header_id',
  'resource_sequence',
  'bom_resource_id',
  'resource_usage',
 ];
 public $pm_process_operation_detail_id;
 public $pm_process_operation_header_id;
 public $pm_process_operation_line_id;
 public $resource_sequence;
 public $description;
 public $bom_resource_id;
 public $process_quantity;
 public $resource_usage;
 public $uom_id;
 public $process_uom_id;
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

}

//end of bom_detail_line class
?>