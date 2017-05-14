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
 * sd_shipping_control
 * Contains all the sd_shipping_control information, such as - org_id, staging_subinventory_id, staging_locator_id
 *
 */
class sd_shipping_control extends dbObject {

 public static $table_name = "sd_shipping_control";
 public static $primary_column = "sd_shipping_control_id";
 public static $key_column = 'org_id';
 public static $module = "sd";
 public static $system_info = [
  'name' => 'Shipping Control',
  'number' => '2302',
  'description' => 'Inventory Shipping Control',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 2
 ];
 public $field_a = [
  'sd_shipping_control_id',
  'org_id',
  'staging_subinventory_id',
  'staging_locator_id',
  'default_picking_rule_id',
  'delivery_onpicking_cb',
  'autosplit_onpicking_cb',
  'deffer_invoicing_cb',

  'rev_enabled',
  'rev_number',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'sd_shipping_control_id',
  'org_id',
 ];
 public $column = [
  'sd_shipping_control_id',
  'org_id',
  'staging_subinventory_id',
  'staging_locator_id',
 ];
 public $requiredField = [
  'org_id'
 ];
 public $checkbox = [
  'delivery_onpicking_cb',
  'autosplit_onpicking_cb',
  'deffer_invoicing_cb'
 ];
 public $fields_inForm_notInDataBase = [
  "staging_subinventory",
  "staging_locator",
  'default_picking_rule'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Shipping Control "; //page Title
 public $search_functions = [
  'Inventory Org' => 'search_inventory_org',
 ];
 public $sd_shipping_control_id;
 public $org_id;
 public $staging_subinventory_id;
 public $staging_locator_id;
 public $default_picking_rule_id;
 public $delivery_onpicking_cb;
 public $autosplit_onpicking_cb;
 public $deffer_invoicing_cb;
 public $deffer_invoicing;
 public $h_default_document_type_id;
 public $l_default_document_type_id;
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

 public function _before_showing() {
//	if (!empty($this->staging_subinventory_id)) {
//	 $this->staging_subinventory = subinventory::find_by_id($this->staging_subinventory)->subinventory;
//	} else {
//	 $this->staging_subinventory = null;
//	}
//
//	if (!empty($this->staging_locator_id)) {
//	 $locator = locator::find_by_id($this->staging_locator_id);
//	 $this->staging_locator = !empty($locator) ? $locator->locator : null;
//	} else {
//	 $this->staging_locator = null;
//	}
 }

 public function _before_save() {
//	if (!(empty($this->staging_subinventory))) {
//	 $this->staging_subinventory_id = subinventory::find_by_keyColumn($this->staging_subinventory)->subinventory_id;
//	}
//	if (!(empty($this->staging_locator))) {
//	 $this->staging_locator_id = locator::find_by_keyColumn($this->staging_locator)->locator_id;
//	}
 }

 public function findBy_orgId($org_id) {
  global $db;
  $sql = "SELECT * FROM sd_shipping_control where org_id=:org_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $param_a = ['org_id'];
  $value_a = ['org_id' => $org_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_org_id($org_id) {
  global $dbc;
  $sql = "SELECT * FROM sd_shipping_control where org_id=:org_id ";
  $sql = ino_perPageSql_i($sql, 1);
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

//end of sd_so_shipping_control_org class
?>
