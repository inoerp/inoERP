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
 * wip_accounting_group 
 *
 */
class wip_accounting_group extends org {

 public static $table_name = "wip_accounting_group";
 public static $primary_column = "wip_accounting_group_id";
 public static $key_column = 'wip_accounting_group';
 public static $module = "wip";
 public static $system_info = [
  'name' => 'Accounting Group',
  'number' => '2601',
  'description' => 'Create & Mainten Approved Accounting Group',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'wip',
  'weight' => 1
 ];
 public $field_a = [
  'wip_accounting_group_id',
  'org_id',
  'wo_type',
  'wip_accounting_group',
  'description',
  'ef_id',
  'rev_enabled',
  'rev_number',
  'status',
  'material_ac_id',
  'material_oh_ac_id',
  'overhead_ac_id',
  'resource_ac_id',
  'osp_ac_id',
  'var_material_ac_id',
  'var_material_oh_ac_id',
  'var_overhead_ac_id',
  'var_resource_ac_id',
  'var_osp_ac_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'wip_accounting_group_id',
  'wip_accounting_group',
 ];
 public $account = [
  'material_ac_id',
  'material_oh_ac_id',
  'overhead_ac_id',
  'resource_ac_id',
  'osp_ac_id',
  'var_material_ac_id',
  'var_material_oh_ac_id',
  'var_overhead_ac_id',
  'var_resource_ac_id',
  'var_osp_ac_id',
 ];
 public $column = [
  'wip_accounting_group_id',
  'org_id',
  'wo_type',
  'wip_accounting_group',
  'description',
 ];
 public $requiredField = [
  'org_id',
  'wo_type',
  'wip_accounting_group',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $option_lists = [
  'wo_type' => 'WIP_WO_TYPE',
 ];
 public $search_functions = [
  'Organization' => 'search_org_name',
 ];
 public $pageTitle = " WIP - Accounting Group "; //page Title
 public $wip_accounting_group_id;
 public $org_id;
 public $wo_type;
 public $wip_accounting_group;
 public $description;
 public $ef_id;
 public $rev_enabled;
 public $rev_number;
 public $status;
 public $material_ac_id;
 public $material_oh_ac_id;
 public $overhead_ac_id;
 public $resource_ac_id;
 public $osp_ac_id;
 public $var_material_ac_id;
 public $var_material_oh_ac_id;
 public $var_overhead_ac_id;
 public $var_resource_ac_id;
 public $var_osp_ac_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_orgId($org_id) {
  global $db;
  if (!empty($org_id)) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE org_id = '{$org_id}' ";
   $result = $db::find_by_sql($sql);
  } else {
   $result = null_instantitae('subinventory');
  }
  return $result;
 }

 public function findBy_orgId() {
  global $db;
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE org_id= :org_id ";
  $param_a = ['org_id'];
  $value_a = ['org_id' => $this->org_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? $result : false;
 }

 public static function find_by_woType($woType = 'STANDARD') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  if (!empty($woType)) {
   $sql .= " WHERE wo_type = '{$woType}' ";
  } else {
   $sql .= " WHERE wo_type IN ('STANDARD' , 'NON_STANDARD') ";
  }

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of business class
?>
