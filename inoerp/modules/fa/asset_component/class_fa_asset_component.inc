<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @component code https://github.com/inoerp/inoERP
 */

/**
 * fa_asset_component 
 *
 */
class fa_asset_component extends dbObject {

 public static $table_name = "fa_asset_component";
 public static $primary_column = "fa_asset_component_id";
 public static $key_column = 'fa_asset_id';
 public static $parent_primary_column = "fa_asset_id";
 public static $module = "fa";
 public static $system_info = [
  'name' => 'Asset component',
  'number' => '1410',
  'description' => 'Asset component',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fa',
  'weight' => 5
 ];
//  data base variables as stored database column name
 public $field_a = [
  'fa_asset_component_id',
  'fa_asset_id',
  'component_asset_id',
  'source_type',
  'component_type',
  'line_number',
  'description',
  'reference1',
  'reference2',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'fa_asset_id',
  'component_type',
  'line_number',
 ];
 public $fields_inForm_notInDataBase = [
  'asset_number',
  'description',
  'status',
  'type',
  'component_asset_number',
  'component_asset_description',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'fa_asset_id',
 ];
 public $requiredField = [
  'fa_asset_id'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Asset component "; //page Title
 public $fa_asset_component_id;
 public $fa_asset_id;
 public $source_type;
 public $component_type;
 public $component_asset_id;
 public $line_number;
 public $description;
 public $reference1;
 public $reference2;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $asset_number;
 public $component_asset_number;
 public $component_asset_description;

}

//end of recomponent class
?>