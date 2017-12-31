<?php

/**
 * inoERP 
 *
 * Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * lms_resource
 * Used for creating different user defined resource elements
 * Contains all the lms_resource information, such as - resource, description , status, org_id
 * 
 */
class lms_resource extends dbObject {

 public static $table_name = "lms_resource";
 public static $primary_column = "lms_resource_id";
 public static $dependent_classes = ['lms_resource_cost'];
 public static $key_column = 'resource';
 public static $module = "lms";
 public static $system_info = [
		 'name' => 'Resource',
		 'number' => '8307',
		 'description' => 'LMS Resources',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
  'dependent_class' => array('lms_resource_cost'),
		 'primary_entity_cb' => '',
		 'module_name' => 'bom',
		 'weight' => 6
 ];
//  data base variables as stored database column name
 public $field_a = [
		 'lms_resource_id',
		 'resource',
		 'description',
		 'org_id',
		 'status',
		 'resource_type',
		 'charge_type',
		 'uom',
		 'basis',
		 'costed_cb',
		 'standard_rate_cb',
		 'absorption_ac_id',
		 'variance_ac_id',
		 'overheads',
		 'rate_reference_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
		 'resource',
		 'description',
		 'resource_type',
 ];
 public $account = [
		 'absorption_ac_id',
		 'variance_ac_id'
 ];
 public $requiredField = [
		 'resource',
		 'org_id',
		 'resource_type',
		 'charge_type',
		 'uom'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = "LMS Resources "; //page Title
 public $option_lists = [
		 'resource_type' => 'RESOURCE_TYPE',
		 'charge_type' => 'CHARGE_TYPE',
 ];
 public $lms_resource_id;
 public $resource;
 public $description;
 public $org_id;
 public $status;
 public $resource_type;
 public $charge_type;
 public $uom;
 public $basis;
 public $costed_cb;
 public $standard_rate_cb;
 public $absorption_ac_id;
 public $variance_ac_id;
 public $overheads;
 public $rate_reference_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 Public static function resource_type() {
	$option_header = option_header::find_by_exact_name('RESOURCE_TYPE');
	$lms_resource_type = option_line::find_by_option_id($option_header->option_header_id);
	return $lms_resource_type;
 }

 Public static function charge_type() {
	$option_header = option_header::find_by_exact_name('CHARGE_TYPE');
	$charge_type = option_line::find_by_option_id($option_header->option_header_id);
	return $charge_type;
 }

}

//end of lms_resource class
?>