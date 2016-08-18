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
 * bom_routing_header
 * Used for creating different user defined routings for make items
 * Routing specifies the flow of matrial in the production line
 * Contains all the bom_overhead information, such as - effective_date, description , item_id_m, org_id
 * 
 */
class bom_routing_header extends dbObject {

 public static $table_name = "bom_routing_header";
 public static $dependent_classes = ['bom_routing_line', 'bom_routing_detail'];
 public static $primary_column = "bom_routing_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "bom"; //same as gl_journal_source
 public static $system_info = [
  'name' => 'Routing',
  'number' => '2407',
  'description' => 'Product Routings',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('bom_routing_line', 'bom_routing_detail'),
  'primary_entity_cb' => '',
  'module_name' => 'bom',
  'weight' => 7
 ];
 public $field_a = [
  'bom_routing_header_id',
  'item_id_m',
  'alternate_routing',
  'org_id',
  'routing_revision',
  'effective_date',
  'common_routing_item_id_m',
  'description',
  'completion_subinventory',
  'completion_locator',
  'ef_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $initial_search = [
  'bom_routing_header_id',
  'item_id_m',
  'alternate_routing',
  'org_id'
 ];
 public $column = [
  'bom_routing_header_id',
  'item_id_m',
  'alternate_routing',
  'org_id'
 ];
 public $fields_inForm_notInDataBase = [
  "item_number",
  "item_description",
  "uom",
  "commonRouting_item_number",
  "commonRouting_item_description"
 ];
 public $requiredField = [
  'item_id_m',
  'org_id'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1
 ];
 public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $pageTitle = " Routing - Resource & Usages @ Each Operation "; //page Title
 public $option_lists = [
//		 'po_type' => 'PO_TYPE',
//		 'po_status' => 'PO_STATUS',
 ];
 public $bom_routing_header_id;
 public $item_id_m;
 public $alternate_routing;
 public $org_id;
 public $routing_revision;
 public $effective_date;
 public $common_routing_item_id_m;
 public $description;
 public $completion_subinventory;
 public $completion_locator;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $uom;
 public $item_number;
 public $item_description;
 public $commonRouting_item_number;
 public $commonRouting_item_description;

 public static function find_by_itemId($itemId) {
  $sql = "SELECT * FROM " . self::$table_name . " WHERE item_id_m = '{$itemId}'";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_itemId_orgId($item_id, $org_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where item_id_m = '{$item_id}' AND org_id = '{$org_id}'  ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_itemId() {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where item_id_m= :item_id_m  ";
  $value_a['item_id_m'] = $this->item_id_m;
  if (!empty($this->org_id)) {
   $sql .= " AND org_id= :org_id  ";
   $value_a['org_id'] = $this->org_id;
  }
  $sql = ino_perPageSql_i($sql, 1);
  $result_array = $this->findBySql($sql, $value_a);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 Public static function wip_move_step() {
  $option_header = option_header::find_by_name('WIP_MOVE_STEP');
  $wip_move_step = option_line::find_by_option_id($option_header->option_header_id);
  return $wip_move_step;
 }

}

//end of bom_routing_header class
?>