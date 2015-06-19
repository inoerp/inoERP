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
 * inv_item_relation
 *
 */
class inv_item_relation extends dbObject {

 public static $table_name = "inv_item_relation";
 public static $module = "inv";
 public static $primary_column = "inv_item_relation_id";
 public static $key_column = "relation_type";
 public static $system_info = [
  'name' => 'Item Relation',
  'number' => '2119',
  'description' => 'Define and Mainten Item Relations',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 4
 ];
 public static $status_a = [
  'active' => 'Active',
  'inactive' => 'Inactive'
 ];
 public $field_a = [
  'inv_item_relation_id',
  'relation_type',
  'from_item_id_m',
  'to_item_id_m',
  'org_id',
  'from_date',
  'to_date',
  'description',
  'planning_cb',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'from_item_id_m',
  'to_item_id_m',
 ];
 public $requiredField = [
  'relation_type',
  'from_item_id_m',
  'to_item_id_m',
 ];
 public $checkbox = [
  'planning_cb'
 ];
 public $fields_inForm_notInDataBase = [
  'from_item_number',
  'to_item_number',
  'from_item_description',
  'to_item_description',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'relation_type'
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=inv_item_relation&mode=9',
  '_show_update_path' => 1,
  '_view_path' => 'form.php?class_name=inv_item_relation&mode=2',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Item Relations "; //page Title
 public $option_list = [
  'relation_type' => 'INV_ITEM_RELATION',
 ]; //list of search fields wh
 public $inv_item_relation_id;
 public $relation_type;
 public $from_item_id_m;
 public $to_item_id_m;
 public $org_id;
 public $from_date;
 public $to_date;
 public $description;
 public $planning_cb;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $from_item_number;
 public $to_item_number;

 public function _before_save() {
  if (!empty($this->from_item_number)) {
   $item_i = item::find_by_itemNumber_fromMasterOrg($this->from_item_number);
   if ($item_i) {
    $this->from_item_id_m = $item_i->item_id_m;
   } else {
    echo "<br>Wrong item number. Error @ " . __FILE__ . ' @ line num ' . __LINE__;
   }
  }

  if (!empty($this->to_item_number)) {
   $item_j = item::find_by_itemNumber_fromMasterOrg($this->to_item_number);
   if ($item_j) {
    $this->to_item_id_m = $item_j->item_id_m;
   } else {
    echo "<br>Wrong item number. Error @ " . __FILE__ . ' @ line num ' . __LINE__;
   }
  }
 }

 Public static function item_relation() {
  $option_header = option_header::find_by_name('INV_ITEM_RELATION');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 public function find_all_ofyear($year) {
  global $db;
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE year= :year ";
  $param_a = ['year'];
  $value_a = ['year' => $year];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return $result;
 }

 public static function find_all_by_relationType($relation_type) {
  $sql = " 
	 SELECT *
	 FROM inv_item_relation
	 WHERE relation_type = '{$relation_type}'
	";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_all_by_fromItemIdM($from_item_id_m) {
  $sql = " 
	 SELECT *
	 FROM inv_item_relation
	 WHERE from_item_id_m = '{$from_item_id_m}'
	";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of inv_item_relation class
?>