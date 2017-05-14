<?php

class prj_status_next extends dbObject {

 public static $table_name = "prj_status_next";
 public static $primary_column = "prj_status_next_id";
 public static $parent_primary_column = "prj_status_header_id";
 public static $key_column = 'status_name';
 public static $module = "prj";
 public static $billing_source_a = [
  'MANUAL' => 'Manual',
  'SYSTEM' => 'System',
 ];
 public static $line_status_a = [
  'PENDING_IMPORT' => 'Pending Import',
  'IMPORTED' => 'Imported',
 ];
//  data base variables as stored database column name
 public $field_a = [
  'prj_status_next_id',
  'prj_status_header_id',
  'status_name',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'prj_status_header_id'
 ];
 public $requiredField = [
  'prj_status_header_id',
  'status_name',
 ];
 public $prj_status_next_id;
 public $prj_status_header_id;
 public $status_name;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $routing_sequence) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where wip_wo_header_id= '{$wip_wo_header_id}' 
					 AND routing_sequence= '{$routing_sequence}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

}

//end of prj_status_next class
?>