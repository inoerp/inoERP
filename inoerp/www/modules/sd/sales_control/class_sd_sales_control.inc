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
 * sd_sales_control
 * Contains all the sd_sales_control information, such as - org_id, staging_subinventory_id, staging_locator_id
 *
 */
class sd_sales_control extends dbObject {

 public static $table_name = "sd_sales_control";
 public static $primary_column = "sd_sales_control_id";
 public static $key_column = 'org_id';
 public static $module = "sd";
 public static $system_info = [
  'name' => 'Sales Control',
  'number' => '2315',
  'description' => 'BU Sales Control',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 2
 ];
 public $field_a = [
  'sd_sales_control_id',
  'org_id',
  'ar_transaction_type_id',
  'mdm_price_list_header_id',
  'deffer_invoicing_cb',
  'default_requested_date_cb',
  'default_schedule_ship_date_cb',
  'default_promise_date_cb',
  'h_default_document_type_id',
  'l_default_document_type_id',
  'iso_h_default_document_type_id',
  'iso_l_default_document_type_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'sd_sales_control_id',
  'org_id',
 ];
 public $requiredField = [
  'org_id'
 ];
 public $checkbox = [
  'deffer_invoicing_cb',
  'default_requested_date_cb',
  'default_schedule_ship_date_cb',
  'default_promise_date_cb',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Sales Control "; //page Title
 public $search_functions = [
  'Inventory Org' => 'search_inventory_org',
 ];
 public $sd_sales_control_id;
 public $org_id;
 public $ar_transaction_type_id;
 public $mdm_price_list_header_id;
 public $deffer_invoicing_cb;
 public $default_requested_date_cb;
 public $default_schedule_ship_date_cb;
 public $h_default_document_type_id;
 public $l_default_document_type_id;
 public $default_promise_date_cb;
 public $iso_h_default_document_type_id;
 public $iso_l_default_document_type_id;
 public $ef_id;
 public $rev_enabled;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $staging_subinventory;
 public $staging_locator;
 public $default_picking_rule;

 public function findBy_orgId($org_id) {
  $sql = "SELECT * FROM sd_sales_control where org_id=:org_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $value_a = ['org_id' => $org_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_org_id($org_id) {
  $sql = "SELECT * FROM sd_sales_control where org_id='{$org_id}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);

  return !empty($result) ? array_pop($result) : false;
 }

}

//end of sd_so_sales_control_org class
?>
