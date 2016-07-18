<?php

class hd_subscription_detail extends dbObject {

 public static $table_name = "hd_subscription_detail";
 public static $primary_column = "hd_subscription_detail_id";
 public static $parent_primary_column = "hd_subscription_line_id";
 public static $key_column = 'line_type';
 public static $module = "hd";
 public $field_a = [
  'hd_subscription_detail_id',
  'hd_subscription_header_id',
  'hd_subscription_line_id',
  'member_name',
  'member_dob',
  'vehcile_no',
  'vehcile_registration',
  'road_tax_expiry_date',
  'vehcile_details',
  'description',
  'line_type',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $requiredField = [
  'hd_subscription_line_id',
 ];
 public $fields_inForm_notInDataBase = [
  "item_number"
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'hd_subscription_line_id',
  'hd_subscription_header_id'
 ];
 public $hd_subscription_detail_id;
 public $hd_subscription_header_id;
 public $hd_subscription_line_id;
 public $member_name;
 public $member_dob;
 public $vehcile_no;
 public $vehcile_registration;
 public $road_tax_expiry_date;
 public $vehcile_details;
 public $description;
 public $line_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public static function find_by_hd_subscription_lineId($hd_subscription_line_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where hd_subscription_line_id = '{$hd_subscription_line_id}'";
  $result_array = self::find_by_sql($sql);
  return $result_array;
 }


}

//end of hd_subscription_detail class
?>