<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * fa_asset_source 
 *
 */
class fa_asset_source extends dbObject {

 public static $table_name = "fa_asset_source";
 public static $primary_column = "fa_asset_source_id";
 public static $key_column = 'fa_asset_id';
 public static $parent_primary_column = "fa_asset_id";
 public static $module = "fa";
 public static $system_info = [
  'name' => 'Asset Source',
  'number' => '1412',
  'description' => 'Asset Source',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fa',
  'weight' => 5
 ];
//  data base variables as stored database column name
 public $field_a = [
  'fa_asset_source_id',
  'fa_asset_id',
  'source_type',
  'line_number',
  'legacy_invoice_num',
  'ap_transaction_line_id',
  'reference_bumber',
  'fa_distribution_line_id',
  'active_cb',
  'line_amount',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'fa_asset_id',
  'source_type',
  'line_number',
 ];
 public $fields_inForm_notInDataBase = [
  'asset_number',
  'description',
  'status',
  'type',
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
 public $pageTitle = " Asset Source "; //page Title
 public $fa_asset_source_id;
 public $fa_asset_id;
 public $source_type;
 public $line_number;
 public $legacy_invoice_num;
 public $ap_transaction_line_id;
 public $reference_bumber;
 public $fa_distribution_line_id;
 public $active_cb;
 public $line_amount;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $asset_number;
 public $description;

}

//end of resource class
?>