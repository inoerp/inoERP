<?php

class prj_status_line extends dbObject {

 public static $table_name = "prj_status_line";
 public static $primary_column = "prj_status_line_id";
 public static $parent_primary_column = "prj_status_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "sd";
 public static $action_a = [
  "PROCESS" => 'Process Order',
  "BOOK" => 'Book Order',
  "CANCEL" => 'Cancel Order',
 ];
 public $line_status_a = [
  'ENTERED' => 'Entered',
  'AWAITING_PICKING' => 'Awaiting Picking',
  'PICKED' => 'Picked',
  'PARTIAL_PICKED' => 'Partially Picked',
  'SHIPPED' => 'Shipped',
  'PARTIAL_SHIPPED' => 'Partial Shipped',
  'CLOSED' => 'Closed',
 ];
 public $field_a = [
  'prj_status_line_id',
  'prj_status_header_id',
  'action_code',
  'allow_cb',
  'default_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
'prj_status_header_id',
  'action_code',
 ];

 public $fields_inHeader_needsToBeInserted_inPOST = [
  "prj_status_header_id"
 ];
 public $prj_status_line_id;
public $prj_status_header_id;
public $action_code;
public $allow_cb;
public $default_cb;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;

 public $time;
 public $msg;


 public static function find_by_headerId_and_status($prj_status_header_id, $line_status = 'PENDING_IMPORT') {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where prj_status_header_id= '{$prj_status_header_id}' AND line_status= '{$line_status}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 Public static function prj_status_line_types() {
  $option_header = option_header::find_by_name('PO_LINE_TYPE');
  $po_types = option_line::find_by_option_id($option_header->option_header_id);
  return $po_types;
 }



}

//end of prj_status_line class
?>