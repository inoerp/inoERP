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
 * Asset Activities
 * Inventory, Non Inventory, Asset and Expense Items
 * Contains all the fp_mds_header information, such as - item_number, description ,  org_id, etc.
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use item rev only
class am_asset_activity extends item {
 
  public static $system_info = [
  'name' => 'Asset Activity',
  'number' => '4103',
  'description' => 'Asset Maintenance',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 1
 ];

 public $pageTitle = " Asset Activity "; //page Title

 Public static function activity_type() {
	$option_header = option_header::find_by_name('AM_ACTIVITY_TYPE');
	$coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
	return $coa_account_types;
 }
 
  Public static function activity_cause() {
	$option_header = option_header::find_by_name('AM_ACTIVITY_CAUSE');
	$coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
	return $coa_account_types;
 }
 
   Public static function activity_source() {
	$option_header = option_header::find_by_name('AM_ACTIVITY_SOURCE');
	$coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
	return $coa_account_types;
 }

}

//end of item class
?>