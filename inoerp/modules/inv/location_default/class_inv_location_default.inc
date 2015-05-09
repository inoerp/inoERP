<?php

class inv_location_default extends dbObject {

 public static $table_name = "inv_location_default";
 public static $module = "inv";
 public static $primary_column = "inv_location_default_id";
 public static $key_column = "item_id_m";
 public static $system_info = [
  'name' => 'Location Default',
  'number' => '2118',
  'description' => 'Item Transaction Location Default',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'mdm',
  'weight' => 4
 ];
 public $field_a = [
  'inv_location_default_id',
  'org_id',
  'priority',
  'item_id_m',
  'default_type',
  'description',
  'subinventory_id',
  'locator_id',
  'address_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'item_id_m',
 ];
 public $requiredField = [
  'org_id',
  'item_id_m',
  'default_type',
 ];
 
  public $fields_inForm_notInDataBase = [
		 "item_number",
 ];
  
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'org_id'
 ];
 public $search = [
  '_show_update_path' => 1,
   '_show_view_path' => 1,
 ];
 public $pageTitle = " Location Default For Item Transaction "; //page Title
 
 public $option_list = [
  'default_type' => 'INV_LOC_DEFAULT_TYPE',
 ]; //list of search fields wh
 
public $inv_location_default_id;
public $priority;
public $org_id;
public $item_id_m;
public $default_type;
public $description;
public $subinventory_id;
public $locator_id;
public $address_id;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;
public $item_number;

 Public static function location_default_types() {
  $option_header = option_header::find_by_name('INV_LOC_DEFAULT_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

  public static function find_all_by_OrgId($org_id) {
  $sql = " 
	 SELECT *
	 FROM inv_location_default
	 WHERE org_id = '{$org_id}'
	";
  $result = self::find_by_sql($sql);
  return $result;
 }
}

//end of inv_location_default class
?>