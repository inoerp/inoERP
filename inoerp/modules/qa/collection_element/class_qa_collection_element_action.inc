<?php

class qa_collection_element_action extends dbObject {

 public static $table_name = "qa_collection_element_action";
 public static $primary_column = "qa_collection_element_action_id";
 public static $parent_primary_column = "qa_collection_element_header_id";
 public static $key_column = 'condition';
 public static $module = "qa";
//  data base variables as stored database column name
 public $field_a = [
  'qa_collection_element_action_id',
  'qa_collection_element_header_id',
  'condition',
  'comparison',
  'value_from',
  'value_to',
  'exact_value',
  'action_id',
  'description',
  'end_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'qa_collection_element_header_id'
 ];
 public $requiredField = [
  'qa_collection_element_header_id',
  'condition',
  'comparison',
 ];
 public $qa_collection_element_action_id;
 public $qa_collection_element_header_id;
 public $condition;
 public $comparison;
 public $value_from;
 public $value_to;
 public $exact_value;
 public $action_id;
 public $description;
 public $end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of qa_collection_element_action class
?>