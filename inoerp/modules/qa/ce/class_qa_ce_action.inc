<?php

class qa_ce_action extends dbObject {

 public static $table_name = "qa_ce_action";
 public static $primary_column = "qa_ce_action_id";
 public static $parent_primary_column = "qa_ce_header_id";
 public static $key_column = 'action_condition';
 public static $module = "qa";
 
 public static $system_info = [
  'name' => 'CE Action',
  'number' => '2907',
  'description' => 'Collection Element Action',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'qa',
  'weight' => 11
 ];
  
 public static $comparison_a = [
  'VALUE' => 'Value',
  'SPEC_LIMIT' => 'Specification Limit'
 ];
 public static $spec_value_a = [
  'UR_L' => 'User Range Low',
  'UR_H' => 'User Range High',
  'SR_L' => 'Specification Range Low',
  'SR_H' => 'Specification Range High',
  'RR_L' => 'Reasonable Range Low',
  'RR_H' => 'Reasonable Range High'
 ];
//  data base variables as stored database column name
 public $field_a = [
  'qa_ce_action_id',
  'qa_ce_header_id',
  'action_condition',
  'comparison',
  'value_from',
  'value_to',
  'spec_value',
  'quality_action',
  'description',
  'end_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'qa_ce_header_id'
 ];
 public $requiredField = [
  'qa_ce_header_id',
  'action_condition',
  'comparison',
 ];
 public $qa_ce_action_id;
 public $qa_ce_header_id;
 public $action_condition;
 public $comparison;
 public $value_from;
 public $value_to;
 public $spec_value;
 public $quality_action;
 public $description;
 public $end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of qa_ce_action class
qa_ce_action::staticVar_init('comparison_a');
qa_ce_action::staticVar_init('spec_value_a');
?>
