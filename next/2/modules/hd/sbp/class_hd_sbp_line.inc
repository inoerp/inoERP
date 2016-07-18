<?php

class hd_sbp_line extends dbObject {

 public static $table_name = "hd_sbp_line";
 public static $primary_column = "hd_sbp_line_id";
 public static $parent_primary_column = "hd_sbp_header_id";
 public static $key_column = 'hd_service_activity_header_id';
 public static $module = "hd";
 public $field_a = [
  'hd_sbp_line_id',
  'hd_sbp_header_id',
  'hd_service_activity_header_id',
  'start_date',
  'end_date',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'hd_service_activity_header_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hd_sbp_header_id"
 ];
 public $hd_sbp_line_id;
 public $hd_sbp_header_id;
 public $billing_type;
 public $service_activity_id;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of hd_sbp_line class
?>