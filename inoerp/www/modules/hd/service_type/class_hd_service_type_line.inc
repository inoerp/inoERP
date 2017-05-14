<?php

class hd_service_type_line extends dbObject {

 public static $table_name = "hd_service_type_line";
 public static $primary_column = "hd_service_type_line_id";
 public static $parent_primary_column = "hd_service_type_header_id";
 public static $key_column = 'billing_type';
 public static $module = "hd";
 public $field_a = [
  'hd_service_type_line_id',
  'hd_service_type_header_id',
  'billing_type',
  'service_activity_id',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'hd_service_type_header_id',
  'billing_type',
  'service_activity_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hd_service_type_header_id"
 ];
 
 public $hd_service_type_line_id;
public $hd_service_type_header_id;
public $billing_type;
public $service_activity_id;
public $description;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;



}

//end of hd_service_type_line class
?>