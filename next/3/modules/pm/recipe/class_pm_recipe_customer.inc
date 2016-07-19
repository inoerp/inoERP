<?php

class pm_recipe_customer extends dbObject {

 public static $table_name = "pm_recipe_customer";
 public static $primary_column = "pm_recipe_customer_id";
 public static $parent_primary_column = "pm_recipe_header_id";
 public static $key_column = 'ar_customer_id';
 public static $module = "pm";
//  data base variables as stored database column name
 public $field_a = [
  'pm_recipe_customer_id',
  'pm_recipe_header_id',
  'org_id',
  'ar_customer_id',
  'ar_customer_site_id',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'pm_recipe_header_id'
 ];
 public $requiredField = [
  'pm_recipe_header_id',
  'ar_customer_id'
 ];
 public $pm_recipe_customer_id;
 public $pm_recipe_header_id;
 public $org_id;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of pm_recipe_customer class
?>