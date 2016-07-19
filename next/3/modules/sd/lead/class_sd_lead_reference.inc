<?php

class sd_lead_reference extends dbObject {

 public static $table_name = "extn_contact_reference";
 public static $primary_column = "extn_contact_reference_id";
 public static $parent_primary_column = "extn_contact_id";
 public static $key_column = 'printer_name';
 public static $module = "extn";
 public $field_a = [
  'extn_contact_reference_id',
  'extn_contact_id',
  'status',
  'reference_type',
  'reference_table',
  'reference_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'extn_contact_id',
  'printer_type',
 ];
 public $requiredField = [
  'extn_contact_id',
  'reference_table',
  'reference_id',
 ];
 
 public $extn_contact_reference_id;
 public $extn_contact_id;
 public $status;
 public $reference_type;
 public $reference_table;
 public $reference_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
//  '_show_update_path' => 1,
//  '_show_view_path' => 1,
 ];
 public $pageTitle = " Contact Reference  "; //page Title

 public static function find_by_code($code) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE hold_code = '{$code}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of extn_contact_reference class
?>