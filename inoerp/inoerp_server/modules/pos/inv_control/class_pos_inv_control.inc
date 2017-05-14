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
 * pos_inv_control
 * Contains all the pos_inv_control information, such as - org_id, staging_subinventory_id, staging_locator_id
 *
 */
class pos_inv_control extends dbObject {

 public static $table_name = "pos_inv_control";
 public static $primary_column = "pos_inv_control_id";
 public static $key_column = 'org_id';
 public static $module = "pos";
 public static $system_info = [
  'name' => 'POS Shipping Control',
  'number' => '2722',
  'description' => 'POS Shipping Control',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 2
 ];
 public $field_a = [
  'pos_inv_control_id',
  'org_id',
  'cogs_ac_id',
  'ar_transaction_type_id',
  'customer_id',
  'transaction_subinventory_id',
  'transaction_locator_id',
  'return_subinventory_id',
  'return_locator_id',
  'item_id_m',
  'allow_negative_onhand_cb',
  'customer_site_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'pos_inv_control_id',
 ];
 public $requiredField = [
  'org_id',
  'cogs_ac_id',
  'ar_transaction_type_id',
//  'customer_id',
 ];
 public $checkbox = [
  'allow_negative_onhand_cb'
 ];

  public $account = [
  'cogs_ac_id'
 ];
  
 public $fields_inForm_notInDataBase = [
		 "item_number",
		 'customer_name',
		 'customer_number',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " POS Inventory Control "; //page Title
 public $search_functions = [
  'Inventory Org' => 'search_inventory_org',
 ];
public $pos_inv_control_id;
public $org_id;
public $cogs_ac_id;
public $ar_transaction_type_id;
public $customer_id;
public $transaction_subinventory_id;
public $transaction_locator_id;
public $return_subinventory_id;
public $return_locator_id;
public $item_id_m;
public $allow_negative_onhand_cb;
public $customer_site_id;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;
public $item_number;


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


 public function findBy_orgId($org_id) {
  global $db;
  $sql = "SELECT * FROM pos_inv_control where org_id=:org_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $param_a = ['org_id'];
  $value_a = ['org_id' => $org_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_org_id($org_id) {
  global $dbc;
  $sql = "SELECT * FROM pos_inv_control where org_id=:org_id ";
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
