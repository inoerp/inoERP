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
 * cm_sys_control
 * Contains all the cm_sys_control information, such as - org_id, staging_subinventory_id, staging_locator_id
 *
 */
class cm_sys_control extends dbObject {

 public static $table_name = "cm_sys_control";
 public static $primary_column = "cm_sys_control_id";
 public static $key_column = 'legal_org_id';
 public static $module = "cm";
 public static $system_info = [
		 'name' => 'Sys Control',
		 'number' => '2315',
		 'description' => 'Sys Control',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'sd',
		 'weight' => 2
 ];
 public $field_a = [
		 'cm_sys_control_id',
		 'legal_org_id',
		 'start_date',
		 'show_cleared_trnx_cb',
		 'show_void_trnx_cb',
		 'allow_lines_cb',
		 'signing_auth_approval',
		 'archive_cb',
		 'purge_cb',
		 'exchange_rate_type',
		 'cf_rate_date',
		 'bank_transfer_rate_date',
		 'authorization',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $initial_search = [
		 'cm_sys_control_id',
		 'legal_org_id',
 ];
 public $requiredField = [
		 'legal_org_id'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Sys Control "; //page Title
 public $search_functions = [
		 'Legal Org' => 'search_legal_org',
 ];
 public $cm_sys_control_id;
 public $legal_org_id;
 public $start_date;
 public $show_cleared_trnx_cb;
 public $show_void_trnx_cb;
 public $allow_lines_cb;
 public $signing_auth_approval;
 public $archive_cb;
 public $purge_cb;
 public $exchange_rate_type;
 public $cf_rate_date;
 public $bank_transfer_rate_date;
 public $authorization;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function findBy_orgId($org_id) {
	$sql = "SELECT * FROM cm_sys_control where legal_org_id=:org_id ";
	$sql = ino_perPageSql_i($sql, 1);
	$value_a = ['org_id' => $org_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_org_id($org_id) {
	$sql = "SELECT * FROM cm_sys_control where org_id='{$org_id}' ";
	$sql = ino_perPageSql_i($sql, 1);
	$result = self::find_by_sql($sql);

	return !empty($result) ? array_pop($result) : false;
 }

}

//end of sd_so_sales_control_org class
?>
