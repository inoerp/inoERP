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
 * fa_asset_category
 * Fixed Asset Class controls all the financial information such as reservation, depreciation, retired account etc.
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use fa_asset_category rev only
 class fa_asset_category extends dbObject {

 public static $table_name = "fa_asset_category";
 public static $primary_column = "fa_asset_category_id";
 public static $dependent_classes = ['fa_book_category_assoc'];
 public static $key_column = 'asset_category';
 public static $module = "fa";
// public static $js_fileName = 'modules/inv/fa_asset_category/js/multi_select.js';
 public static $system_info = [
  'name' => 'Fixed Asset Category',
  'number' => '1402',
  'description' => 'Fixed Asset Category',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fa',
  'weight' => 1
 ];
 public $checkbox = [
  'enabled_cb',
  'capitalize_cb',
  'in_physical_inv_cb',
 ];
 public $field_a = [
  'fa_asset_category_id',
  'asset_category',
  'segment1',
  'segment2',
  'segment3',
  'type',
  'description',
  'enabled_cb',
  'capitalize_cb',
  'in_physical_inv_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $initial_search = [
  'fa_asset_category_id',
 ];
 public $requiredField = [
    'asset_category',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Asset Category"; //page Title
 public $option_lists = [
  'fa_asset_category_types' => 'FA_ASSET_CATEGORY_TYPE',
 ];
 public $fa_asset_category_id;
 public $asset_category;
 public $segment1;
 public $segment2;
 public $segment3;
 public $type;
 public $description;
 public $enabled_cb;
 public $capitalize_cb;
 public $in_physical_inv_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function asset_category_type() {
  $option_header = option_header::find_by_name('FA_ASSET_CATEGORY_TYPE');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

}

//end of fa_asset_category class
?>