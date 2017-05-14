<?php

class prj_project_type_billing extends dbObject {

 public static $table_name = "prj_project_type_billing";
 public static $primary_column = "prj_project_type_billing_id";
 public static $parent_primary_column = "prj_project_type_header_id";
 public static $key_column = 'prj_billing_extn_id';
 public static $module = "prj";
//  data base variables as stored database column name
 public $field_a = [
  'prj_project_type_billing_id',
  'prj_project_type_header_id',
  'prj_billing_extn_id',
  'currency',
  'amount',
  'percentage',
  'active_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $fields_inForm_notInDataBase = [
  "billing_item_number",
  "billing_description",
  "billing_uom"
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'prj_project_type_header_id'
 ];
 public $requiredField = [
  'prj_project_type_header_id',
  'prj_billing_extn_id',
  'currency',
 ];
 public $prj_project_type_billing_id;
 public $prj_project_type_header_id;
 public $prj_billing_extn_id;
 public $currency;
 public $amount;
 public $percentage;
 public $active_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;



}

//end of prj_project_type_billing class
?>