<?php

class hd_service_activity_line extends dbObject {

 public static $table_name = "hd_service_activity_line";
 public static $primary_column = "hd_service_activity_line_id";
 public static $parent_primary_column = "hd_service_activity_header_id";
 public static $key_column = 'header_type_id';
 public static $module = "hd";
 public $field_a = [
  'hd_service_activity_line_id',
  'hd_service_activity_header_id',
  'bu_org_id',
  'header_type_id',
  'line_type_id',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'hd_service_activity_header_id',
  'bu_org_id'
 ];

 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hd_service_activity_header_id"
 ];
 
 public $hd_service_activity_line_id;
 public $hd_service_activity_header_id;
 public $bu_org_id;
 public $header_type_id;
 public $line_type_id;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of hd_service_activity_line class
?>