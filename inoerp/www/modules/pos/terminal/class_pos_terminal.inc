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
 * pos_terminal
 * Used for min max planning
 * Contains all the fp_mds_header information, such as - mds_name, description , fp_source_list_header_id, org_id, status
 * 
 */
class pos_terminal extends dbObject {

 public static $table_name = "pos_terminal";
 public static $primary_column = "pos_terminal_id";
// public static $dependent_classes = ['fp_minmax_line'];
 public static $key_column = 'terminal_name';
 public static $module = "pos";
 public static $system_info = [
  'name' => 'pos_terminal',
  'number' => '2723',
  'description' => 'POS Terminal',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
//  'dependent_class' => array('fp_minmax_line', 'fp_minmax_demand', 'fp_minmax_demand_v', 'fp_minmax_order_v', 'fp_minmax_suggestion_v'),
  'primary_entity_cb' => '',
  'module_name' => 'pos',
  'weight' => 5
 ];
 public $field_a = [
  'pos_terminal_id',
  'sd_store_id',
  'location_id',
  'terminal_name',
  'description',
  'primary_owner_id',
  'terminal_type',
  'status',
  'refresh_time',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'terminal_name',
 ];
 public $requiredField = [
  'sd_store_id',
  'location_id',
  'terminal_name',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " POS Terminal "; //page Title
 public $pos_terminal_id;
 public $sd_store_id;
 public $location_id;
 public $terminal_name;
 public $description;
 public $primary_owner_id;
 public $terminal_type;
 public $status;
 public $refresh_time;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 
  public static function find_by_storeId($store_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE sd_store_id = '{$store_id}'";

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

?>
