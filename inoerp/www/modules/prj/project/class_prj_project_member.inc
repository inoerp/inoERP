<?php

class prj_project_member extends dbObject {

 public static $table_name = "prj_project_member";
 public static $primary_column = "prj_project_member_id";
 public static $parent_primary_column = "prj_project_header_id";
 public static $key_column = 'user_id';
 public static $module = "prj";
//  data base variables as stored database column name
 public $field_a = [
  'prj_project_member_id',
  'prj_project_header_id',
  'user_id',
  'prj_role_id',
  'description',
  'start_date',
  'end_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $fields_inForm_notInDataBase = [
  "member_username",
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'prj_project_header_id'
 ];
 public $requiredField = [
  'user_id',
  'prj_role_id',
 ];
 public $prj_project_member_id;
 public $prj_project_header_id;
 public $user_id;
 public $prj_role_id;
 public $description;
 public $start_date;
 public $end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $member_username;


 public static function find_by_headerId_and_status($prj_project_header_id, $line_status = 'PENDING_IMPORT') {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where prj_project_header_id= '{$prj_project_header_id}' AND line_status= '{$line_status}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $routing_sequence) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where wip_wo_header_id= '{$wip_wo_header_id}' 
					 AND routing_sequence= '{$routing_sequence}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

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

//end of prj_project_member class
?>