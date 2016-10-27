<?php

/**
 * inoERP - Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * fp_planning_control
 * Setups for the forecast & planning activities
 * 
 */
class fp_planning_control extends dbObject {

 public static $table_name = "fp_planning_control";
 public static $primary_column = "fp_planning_control_id";
 public static $key_column = 'org_id';
 public static $module = "fp";
 public static $system_info = [
  'name' => 'Planning Control',
  'number' => '2507',
  'description' => 'Planning Control',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 7
 ];
 public $field_a = [
  'fp_planning_control_id',
  'org_id',
  'auto_consumed_group_id',
  'auto_consumed_frwd_days',
  'auto_consumed_backwd_days',
  'default_abc',
  'net_wip_cb',
  'net_po_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'fp_planning_control_id',
  'org_id',
 ];
 public $requiredField = [
  'org_id'
 ];
 public $checkbox = [
  'net_wip_cb',
  'net_po_cb',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Planning Control "; //page Title
 public $search_functions = [
  'Inventory Org' => 'search_inventory_org',
 ];
 public $fp_planning_control_id;
 public $org_id;
 public $auto_consumed_group_id;
 public $auto_consumed_frwd_days;
 public $auto_consumed_backwd_days;
 public $default_abc;
 public $net_wip_cb;
 public $net_po_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function findBy_orgId($org_id) {
  global $db;
  $sql = "SELECT * FROM fp_planning_control where org_id=:org_id ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $param_a = ['org_id'];
  $value_a = ['org_id' => $org_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_org_id($org_id) {
  global $dbc;
  $sql = "SELECT * FROM fp_planning_control where org_id=:org_id ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $stmt = $dbc->connection->prepare(" $sql ");
  try {
   $stmt->execute();
   $result = $stmt->fetchObject();
  } catch (PDOException $e) {
   echo gettext("No Records Found!") . ". Error @ PO Purchasing Control " . __LINE__ . $e->getMessage();
  }
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of sd_so_planning_control_org class
?>
