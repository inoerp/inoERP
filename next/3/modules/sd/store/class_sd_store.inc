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
 * sd_store
 * Contains all the sd_store information, such as - price_list, module_name, description,  currency_code, etc.
 * 
 */
class sd_store extends dbObject {

 public static $table_name = "sd_store";
 public static $primary_column = "sd_store_id";
 public static $dependent_classes = ['sd_store_subinventory'];
 public static $key_column = "store_name";
 public static $module = "sd";
 public static $system_info = [
  'name' => 'Store',
  'number' => '2019',
  'description' => 'Define and Mainten Stores',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'sd_store',
  'weight' => 1
 ];
 public $field_a = [
  'sd_store_id',
  'org_id',
  'store_name',
  'code',
  'type',
    'cogs_ac_id',
  'revenue_ac_id',
  'cash_ac_id',
  'tax_ac_id',
  'description',
  'status',
  'address_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  "store_name",
  "description",
 ];
 public $account = [
  'cogs_ac_id',
  'revenue_ac_id',
  'cash_ac_id'
 ];
 public $requiredField = [
  'org_id',
  'store_name',
  'code',
  'revenue_ac_id',
  'cash_ac_id'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Stores - Create & Update Diffent Stores"; //page Title
 public $sd_store_id;
 public $org_id;
 public $store_name;
 public $code;
 public $cogs_ac_id;
 public $revenue_ac_id;
 public $cash_ac_id;
 public $tax_ac_id;
 public $type;
 public $description;
 public $status;
 public $address_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function findBy_sd_storeType() {
  global $db;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE type = :type";
  $param_a = ['type'];
  $value_a = ['type' => $this->type];

  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? $result : false;
 }

 public static function find_by_orgId($org_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE org_id = '{$org_id}'";

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of path class
?>
