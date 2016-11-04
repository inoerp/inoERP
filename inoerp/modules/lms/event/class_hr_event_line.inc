<?php

class hr_event_line extends dbObject {

 public static $table_name = "hr_event_line";
 public static $primary_column = "hr_event_line_id";
 public static $parent_primary_column = "hr_event_header_id";
 public static $key_column = 'user_id';
 public static $module = "hr";
//  data base variables as stored database column name
 public $field_a = [
'hr_event_line_id',
'hr_event_header_id',
'user_id',
'resource_id',
'expected_status',
'actual_status',
'required_cb',
'description',
'created_by',
'creation_date',
'last_update_by',
'last_update_date',

 ];
//variables used for showing data
 public $fields_inForm_notInDataBase = [
  "username",
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'hr_event_header_id'
 ];
 public $requiredField = [
  'hr_event_header_id',
 ];
public $hr_event_line_id;
public $hr_event_header_id;
public $user_id;
public $resource_id;
public $expected_status;
public $actual_status;
public $required_cb;
public $description;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;

public $username;



 public function findBy_woHeaderId_routingSeq() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE wip_wo_header_id = :wip_wo_header_id ";
  $sql .= " AND routing_sequence = :routing_sequence ";

  $param_a = ['wip_wo_header_id', 'routing_sequence'];
  $value_a = ['wip_wo_header_id' => $this->wip_wo_header_id, 'routing_sequence' => $this->routing_sequence];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? $result : false;
 }

}

//end of hr_event_line class
?>