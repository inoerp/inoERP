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
 * PO_ASL_HEADER CLass
 * Contains all the approved supplier header information, such as - ASL Type, Org Id, Item id 
 * Approved supplier list is used to restrict the buyers to purchase materials from a given list of suppliers
 * ASL is also used to by system to automatically generate POs from requisition
 *
 */
class po_asl_header extends dbObject {

 public static $table_name = "po_asl_header";
 public static $primary_column = "po_asl_header_id";
 public static $dependent_classes = ['po_asl_line'];
 public static $key_column = 'description';
 public static $module = "pur";
 public static $system_info = [
  'name' => 'ASL',
  'number' => '2203',
  'description' => 'Create & Mainten Approved Supplier List',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('po_asl_line'),
  'primary_entity_cb' => '',
  'module_name' => 'po',
  'weight' => 2
 ];
 public static $asl_type_a = [
  'ITEM' => 'Item',
  'ITEM_CATEGORY' => 'Item Category',
 ];
 public $field_a = [
  'po_asl_header_id',
  'bu_org_id',
  'asl_type',
  'item_id_m',
  'item_category_id',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'po_asl_header_id',
  'bu_org_id',
  'asl_type',
 ];
 public $requiredField = [
  'bu_org_id',
  'asl_type',
  'description'
 ];
 public $fields_inForm_notInDataBase = [
  "item_number",
  'item_decription'
 ];
 public $profile_default = [
  'bu_org_id' => 'org_bu_name_default',
 ];
 public $pageTitle = " Approved Supplier List "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $po_asl_header_id;
 public $bu_org_id;
 public $asl_type;
 public $item_id_m;
 public $item_category_id;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $item_number;
 public $item_description;

 public function _before_showing() {
  if (!empty($this->item_id_m)) {
   $item = item::find_by_item_id_m($this->item_id_m);
   $this->item_number = $item->item_number;
  }
 }

 public static function find_by_sourcingRule($asl) {
  global $db;
  $sql = "SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " where asl = '{$asl}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = $db->find_by_sql($sql);
  return !(empty($result)) ? array_pop($result) : false;
 }

 public function findBy_itemId() {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where item_id_m= :item_id_m  ";
  $sql = ino_perPageSql_i($sql, 1);
  $param_a = ['item_id_m'];
  $value_a = ['item_id_m' => $this->item_id_m];
  $result_array = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result_array) ? array_pop($result_array) : false;
 }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of asl class
po_asl_header::staticVar_init('asl_type_a');
?>
