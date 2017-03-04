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
 * Item
 * Inventory, Non Inventory, Asset and Expense Items
 * Contains all the fp_mds_header information, such as - item_number, description ,  org_id, etc.
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use item rev only
class item extends dbObject {

 public static $table_name = "item";
 public static $primary_column = "item_id";
 public static $dependent_classes = ['inv_item_revision'];
 public static $key_column = 'item_number';
 public static $module = "inv";
// public static $js_fileName = 'modules/inv/item/js/multi_select.js';
 public static $system_info = [
  'name' => 'Item',
  'number' => '2101',
  'description' => 'Item',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 1
 ];
 public static $ls_uniqueness_a = [
  'ITEM' => 'Item Level',
  'ORG' => 'Organization Level',
  'GLOBAL' => 'Global Level',
 ];
 public static $am_asset_type_a = [
  'ASSET_ITEM' => 'Asset Item',
  'ASSET_ACTIVITY' => 'Asset Activity',
  'ASSET_COMPONENT' => 'Asset Component',
 ];
 public static $ls_generation_a = [
  'PRE_DEFINED' => 'Pre Defined',
  'AT_RECEIPT' => 'At Receipt',
  'AT_SHIPMENT' => 'At Shipment',
 ];
 public $account = [
  "material_ac_id",
  "material_oh_ac_id",
  "overhead_ac_id",
  "resource_ac_id",
  "osp_ac_id",
  "expense_ac_id",
  "sales_ac_id",
  "cogs_ac_id",
  "deffered_cogs_ac_id"
 ];
 public $checkbox = [
  "item_rev_enabled_cb",
  'kit_cb',
  "inventory_item_cb",
  "stockable_cb",
  "transactable_cb",
  "reservable_cb",
  "cycle_count_enabled_cb",
  "equipment_cb",
  "electronic_format_cb",
  "rev_enabled_cb",
  "customer_ordered_cb",
  "internal_ordered_cb",
  "shippable_cb",
  "returnable_cb",
  "purchased_cb",
  "use_asl_cb",
  "bom_enabled_cb",
  "costing_enabled_cb",
  "inventory_asset_cb",
  "build_in_wip_cb",
  "allow_negative_balance_cb",
  'update_revision_cb',
  'invoiceable_cb',
  'service_request_cb'
 ];
 public $field_a = [
  "item_id",
  'item_id_m',
  "org_id",
  "item_number",
  "item_description",
  'image_file_id',
  'product_line',
  'product_line_percentage',
  "locator_control",
  "long_description",
  "uom_id",
  "item_type",
  "item_status",
  "bom_type",
  "item_rev_number",
		 'demand_class',
		 'discount_class',
  "default_cost_group",
  "lot_uniqueness",
  "lot_generation",
  "lot_prefix",
  "lot_starting_number",
  "serial_generation",
  "serial_prefix",
  "serial_starting_number",
  "serial_uniqueness",
  "invoice_matching",
  'invoiceable_cb',
  "default_buyer",
  "list_price",
  "contract_item_type",
  "duration_uom_id",
  "over_receipt_percentage",
  "receipt_days_early",
  "receipt_days_late",
  "receipt_day_action",
  "receipt_routing",
  "weight_uom_id",
  "weight",
  "volume_uom_id",
  "volume",
  "dimension_uom_id",
  "length",
  "width",
  "height",
  "planning_method",
  "planner",
  "make_buy",
  'wip_supply_subinventory',
  'wip_supply_locator',
  "fix_order_quantity",
  "fix_days_supply",
  "fix_lot_multiplier",
  "minimum_order_quantity",
  "maximum_order_quantity",
  'rounding_option',
  'minmax_min_quantity',
  'minmax_max_quantity',
  'minmax_multibin_number',
  'minmax_multibin_size',
  'saftey_stock_days',
  'saftey_stock_quantity',
  'saftey_stock_percentage',
  "forecast_method",
  "forecast_control",
  "demand_timefence",
  "planning_timefence",
  "release_timefence",
  "pre_processing_lt",
  "post_processing_lt",
  "processing_lt",
  "cumulative_mfg_lt",
  "cumulative_total_lt",
  "lt_lot_size",
  "wip_supply_type",
  "atp",
  "picking_rule",
  "sourcing_rule_id",
  "ip_tax_class",
  "op_tax_class",
  "ap_payment_term",
  "ar_payment_term",
  "duration",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date",
  "material_ac_id",
  "material_oh_ac_id",
  "overhead_ac_id",
  "resource_ac_id",
  "osp_ac_id",
  "expense_ac_id",
  "sales_ac_id",
  "cogs_ac_id",
  "deffered_cogs_ac_id",
  "onhand_with_rev_cb",
  'kit_cb',
  "inventory_item_cb",
  "stockable_cb",
  "transactable_cb",
  "reservable_cb",
  "cycle_count_enabled_cb",
  "equipment_cb",
  "electronic_format_cb",
  "rev_enabled_cb",
  "customer_ordered_cb",
  "internal_ordered_cb",
  "shippable_cb",
  "returnable_cb",
  "purchased_cb",
  "use_asl_cb",
  "bom_enabled_cb",
  "costing_enabled_cb",
  "inventory_asset_cb",
  "build_in_wip_cb",
  "allow_negative_balance_cb",
  'am_asset_type',
  'am_activity_cause',
  'am_activity_type',
  'am_activity_source',
  'billing_type',
  'service_request_cb'
 ];
 public $initial_search = [
  'item_id',
  'org_id',
  "customer_ordered_cb",
  "internal_ordered_cb",
  "shippable_cb",
  "returnable_cb",
  "purchased_cb",
  "use_asl_cb",
  "bom_enabled_cb",
  "costing_enabled_cb",
  "inventory_asset_cb",
  "build_in_wip_cb",
  "item_number",
  'am_asset_type',
  'transactable_cb'
 ];
// public $column = [
//  'item_id',
//  'item_id_m',
//  "org_id",
//  "item_number",
//  "item_description",
//  "item_type",
//  "serial_generation",
//  "lot_generation",
//  "uom_id",
//  "item_status",
//  'processing_lt',
//  'kit_cb'
// ];
 public $requiredField = [
  "item_number",
  "uom_id",
  "org_id",
  "item_description",
  "item_type",
  "make_buy"];
 public $otherField = [
  "org.org"
 ];
 public $fields_inForm_notInDataBase = [
  'item_category',
  'item_catalog',
  'item_reference',
  'item_template',
  'sourcing_rule',
  'action',
  'multibin_minmax_quantity',
  'overwrite_minmax_min_quantity',
  'overwrite_minmax_max_quantity',
  'overwrite_minmax_multibin_number',
  'overwrite_minmax_multibin_size'
 ];
 public static $json_label_fields = [
  'item_id_m',
  'org_id',
  "item_number",
  "item_description",
  'product_line',
  "item_type",
  "lot_generation",
  "serial_generation",
  "list_price",
  "planner",
  "fix_lot_multiplier",
  'item_id'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $search_functions = [
  'Item From' => 'search_item_number_from',
  'Item To' => 'search_item_number_to',
  'Organization' => 'search_org_name',
 ];
 public $pageTitle = " Item - Create | Update Items"; //page Title
 public $option_lists = [
  'item_types' => 'ITEM_TYPE',
  'item_status' => 'ITEM_STATUS',
  'planning_method' => 'MP_PLANNING_METHOD',
 ];
 public $prg_minmax_update_parameters = [
  'Organization' => 'search_org_name',
  'Min Max Planner ' => 'search_minmax_planner',
  'Item Number From' => 'search_item_number_from',
  'Item Number To' => 'search_item_number_to',
  'Item Id From' => 'search_item_id_from',
  'Item Id To' => 'search_item_id_to'
 ];
 public $prg_minmax_update_details = [
  'name' => 'Min Max Attribute Update ',
  'description' => 'Update Item Attributes related to Min Max ',
 ];
 public $item_id;
 public $item_id_m;
 public $org_id;
 public $org;
 public $item_number;
 public $item_description;
 public $image_file_id;
 public $product_line;
 public $product_line_percentage;
 public $locator_control;
 public $allow_negative_balance_cb;
 public $long_description;
 public $uom_id;
 public $onhand_with_rev_cb;
 public $item_rev_number;
 public $item_type;
 public $item_status;
 public $inventory_item_cb;
 public $stockable_cb;
 public $transactable_cb;
 public $reservable_cb;
 public $cycle_count_enabled_cb;
 public $bom_enabled_cb;
 public $bom_type;
 public $costing_enabled_cb;
 public $inventory_asset_cb;
 public $default_cost_group;
// public $material_ac;
 public $material_oh_ac;
 public $overhead_ac;
 public $resource_ac;
 public $expense_ac;
 public $osp_ac;
 public $material_ac_id;
 public $material_oh_ac_id;
 public $overhead_ac_id;
 public $resource_ac_id;
 public $expense_ac_id;
 public $osp_ac_id;
 public $lot_uniqueness;
 public $lot_generation;
 public $lot_prefix;
 public $lot_starting_number;
 public $serial_generation;
 public $serial_prefix;
 public $serial_starting_number;
 public $serial_uniqueness;
 public $purchased_cb;
 public $kit_cb;
 public $use_asl_cb;
 public $invoice_matching;
 public $default_buyer;
 public $list_price;
 public $contract_item_type;
 public $duration_uom_id;
 public $receipt_sub_inventory;
 public $over_receipt_percentage;
 public $over_receipt_action;
 public $receipt_days_early;
 public $receipt_days_late;
 public $receipt_day_action;
 public $receipt_routing;
 public $weight_uom_id;
 public $weight;
 public $volume_uom_id;
 public $volume;
 public $dimension_uom_id;
 public $length;
 public $width;
 public $height;
 public $equipment_cb;
 public $electronic_format_cb;
 public $planning_method;
 public $planner;
 public $make_buy;
 public $wip_supply_locator;
 public $wip_supply_subinventory;
 public $fix_order_quantity;
 public $fix_days_supply;
 public $fix_lot_multiplier;
 public $minimum_order_quantity;
 public $maximum_order_quantity;
 public $saftey_stock_days;
 public $saftey_stock_quantity;
 public $saftey_stock_percentage;
 public $minmax_min_quantity;
 public $minmax_max_quantity;
 public $minmax_multibin_number;
 public $minmax_multibin_size;
 public $rounding_option;
 public $forecast_method;
 public $forecast_control;
 public $demand_timefence;
 public $planning_timefence;
 public $release_timefence;
 public $pre_processing_lt;
 public $post_processing_lt;
 public $processing_lt;
 public $cumulative_mfg_lt;
 public $cumulative_total_lt;
 public $lt_lot_size;
 public $build_in_wip_cb;
 public $wip_supply_type;
 public $customer_ordered_cb;
 public $internal_ordered_cb;
 public $shippable_cb;
 public $returnable_cb;
 public $invoiceable_cb;
 public $op_tax_class;
 public $ip_tax_class;
 public $ap_payment_term;
 public $ar_payment_term;
 public $atp;
 public $picking_rule;
 public $sourcing_rule_id;
 public $sales_ac;
 public $cogs_ac;
 public $deffered_cogs_ac;
 public $sales_ac_id;
 public $cogs_ac_id;
 public $deffered_cogs_ac_id;
 public $duration;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $item_category;
 public $item_catalog;
 public $item_reference;
 public $item_template;
 public $action;
 public $multibin_minmax_quantity;
 public $overwrite_minmax_min_quantity;
 public $overwrite_minmax_max_quantity;
 public $overwrite_minmax_multibin_number;
 public $overwrite_minmax_multibin_size;
 public $sourcing_rule;
 public $update_revision_cb;
 public $am_asset_type;
 public $am_activity_cause;
 public $am_activity_type;
 public $am_activity_source;
 public $service_request_cb;
 public $billing_type;
 private $_existing_rev_number = false;
 private $_eco_number = false;
 private $_effective_start_date = false;
 private $_origination_date = false;
 private $_implementation_date = false;
 public $template_item_id;

 Public static function product_line() {
  $option_header = option_header::find_by_name('INV_ITEM_PRODUCT_LINE');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 Public static function product_tax_class() {
  $option_header = option_header::find_by_name('INV_ITEM_TAX_CLASS');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 Public static function rounding_option() {
  $option_header = option_header::find_by_name('SYS_ROUNDING_OPTION');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 Public static function item_types() {
  $option_header = option_header::find_by_name('ITEM_TYPE');
  $coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
  return $coa_account_types;
 }

 Public static function bom_types() {
  $option_header = option_header::find_by_name('INV_ITEM_BOM_TYPE');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 Public static function planning_method() {
  $option_header = option_header::find_by_name('MP_PLANNING_METHOD');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 Public static function item_status() {
  $option_header = option_header::find_by_name('ITEM_STATUS');
  $coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
  return $coa_account_types;
 }

 Public static function manufacturing_item_types() {
  $option_header = option_header::find_by_name('MANUFACTURING_ITEM_TYPE');
  $mfg_item_types = option_line::find_by_option_id($option_header->option_header_id);
  return $mfg_item_types;
 }

 public function _before_save() {
  if (!empty($this->sourcing_rule)) {
   $this->sourcing_rule_id = po_sourcing_rule_header::find_by_sourcingRule($this->sourcing_rule)->po_sourcing_rule_header_id;
  }
  if (($this->action == 'update_item_minmax')) {
   echo "<br> saving minmax details before Item SAVE";
   $this->_update_item_minmax();
   return 10;
  }
  if (empty($this->item_id)) {
//before creating item, check if the entered org is a master org or not;
//if the entered org is a master org then create the item else check if item exists in any master org
//items can be created only in master org
   $org = new org();
   $is_master_org = false;
   $all_master_orgs = $org->findAll_item_master();
   foreach ($all_master_orgs as $master_orgs) {
    if ($master_orgs->org_id == $this->org_id) {
     $is_master_org = true;
     return;
    }
   }
   if ($is_master_org) {
    return 1;
   } else {
    //verify if item number exists in master org
    $inv = new inventory();
    $inv_i = $inv->findBy_org_id($this->org_id);
    $item_exists_inItemMaster = $this->findBy_itemNumber_OrgId($inv_i->master_org_id);
    if ($item_exists_inItemMaster) {
     return 1;
    } else {
     echo " Items can be created only in master org ";
     return -99;
    }
   }
  }
 }

 public function _after_save() {
  if (empty($this->item_id_m)) {
   if (!empty($this->org_id)) {
    $inv = inventory::find_by_org_id($this->org_id);
    if (!empty($inv->item_master_cb) && ($inv->item_master_cb == 1)) {
     $this->item_id_m = $this->item_id;
     $this->audit_trial();
     $this->save();
    } else {
     $item_master = $this->findBy_itemNumber_OrgId($inv->master_org_id);
     if (!empty($item_master->item_id)) {
      $this->audit_trial();
      $this->item_id_m = $item_master->item_id;
      $this->save();
     }
    }
   }
  }

  if (!empty($this->item_id_m) && !empty($this->org_id) && !empty($this->update_revision_cb)) {
   $this->_update_item_revision();
  }
 }

 private function _save_revision_record($rid_k) {
  $itm_r = new inv_item_revision();
  foreach ($itm_r->field_a as $rk => $rv) {
//     pa($_POST[$rv]); echo ' $rid_v is ' .$rid_k;
   $itm_r->$rv = isset($_POST[$rv][$rid_k]) ? $_POST[$rv][$rid_k] : null;
  }
  $itm_r->item_id_m = $this->item_id_m;
  $itm_r->org_id = $this->org_id;
  if ($this->_existing_rev_number) {
   $itm_r->revision_name = $this->_existing_rev_number;
   $itm_r->eco_number = $this->_eco_number;
   $itm_r->effective_start_date = $this->_effective_start_date;
   $itm_r->origination_date = $this->_origination_date;
   $itm_r->implementation_date = $this->_implementation_date;
  }
  try {
   $itm_r->save_onWebForm();
  } catch (Exception $e) {
   echo "<br> Failed to update the item revision. Error @ class_item @@ line " . __LINE__ . $e->getMessage();
   $db->rollback = true;
  }
 }

 private function _update_item_revision() {
  global $db;
  foreach ($_POST['inv_item_revision_id'] as $rid_k => $rid_v) {
   if (empty($rid_v)) {
    $this->_save_revision_record($rid_k);
   } else {
    if (in_array($rid_v, $_POST['line_id_cb'])) {
     $item_rev_i = inv_item_revision::find_by_id($rid_v);
     $this->_existing_rev_number = $item_rev_i->revision_name;
     $this->_eco_number = $item_rev_i->eco_number;
     $this->_effective_start_date = $item_rev_i->effective_start_date;
     $this->_implementation_date = $item_rev_i->implementation_date;
     $this->_origination_date = $item_rev_i->origination_date;
     $this->_save_revision_record($rid_k);
    }
   }
  }
 }

 public static function find_by_item_id_m($item_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE item_id = item_id_m ";
  $sql .= " AND item_id = '{$item_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_orgId_item_id_m($item_id, $org_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE item_id_m = '{$item_id}' AND org_id = '{$org_id}'  ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_item_number_by_item_number($item_number) {
  global $db;
  $sql = "SELECT * FROM "
   . self::$table_name
   . " where item_number LIKE '%{$item_number}%' ";
  $sql = ino_perPageSql_i($sql, 30);
  $result = $db->query($sql);
  $data = array();
  if ($result && mysql_num_rows($result)) {
   while ($row = $db->fetch_array($result)) {
    $data[] = array(
     'label' => $row['item_number'],
     'item_number' => $row['item_number'],
     'item_id' => $row['item_id'],
     'description' => $row['item_description'],
     'uom_id' => $row['uom_id']
    );
   }
  }

  return $data;
 }

 public static function find_by_itemNumber_orgId($item_number, $org_id) {
  global $db;
  $sql = "SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " where item_number LIKE '%{$item_number}%' ";
  $sql .= " AND org_id  = '{$org_id}' ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = $db->find_by_sql($sql);
  return !(empty($result)) ? array_pop($result) : false;
 }

 public static function find_by_itemNumber_fromMasterOrg($item_number) {
  global $db;
  $sql = "SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " where item_number LIKE '%{$item_number}%' ";
  $sql .= " AND item_id_m  = item_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = $db->find_by_sql($sql);
  return !(empty($result)) ? array_pop($result) : false;
 }

 public function findBy_item_id_m($item_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE item_id = item_id_m ";
  $sql .= " AND item_id = '{$item_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_orgId_itemIdM($org_id = '', $item_id_m = '') {
  $item_id_m = empty($item_id_m) ? $this->item_id_m : $item_id_m;
  $org_id = empty($org_id) ? $this->org_id : $org_id;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE item_id_m = :item_id_m AND org_id = :org_id  ";
  $sql = ino_perPageSql_i($sql, 1);
  $value_a = ['item_id_m' => $item_id_m, 'org_id' => $org_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 private function _update_item_minmax() {
  if (empty($this->item_id_m) || empty($this->org_id)) {
   echo "<br>Item id or org id is missing";
   return;
  }
//  pa($this);
  echo "<br>acutal minmax_min_quantity" . $this->minmax_min_quantity;
  if (!empty($this->overwrite_minmax_min_quantity)) {
   $this->minmax_min_quantity = $this->overwrite_minmax_min_quantity;
  }
  if (!empty($this->overwrite_minmax_max_quantity)) {
   $this->minmax_max_quantity = $this->overwrite_minmax_max_quantity;
  }
  if (!empty($this->overwrite_minmax_multibin_number)) {
   $this->minmax_multibin_number = $this->overwrite_minmax_multibin_number;
  }
  if (!empty($this->overwrite_minmax_multibin_size)) {
   $this->minmax_multibin_size = $this->overwrite_minmax_multibin_size;
  }
  echo "<br>over written minmax_min_quantity" . $this->minmax_min_quantity;
  $item_n = new item();
  $item_n->org_id = $this->org_id;
  $item_n->item_id_m = $this->item_id_m;
  $item_n_j = $item_n->findBy_orgId_itemIdM();
  foreach ($item_n->field_a as $k => $v) {
   if (property_exists($item_n_j, $v)) {
    $item_n->$v = $item_n_j->$v;
   }
  }
  switch ($item_n->rounding_option) {
   case 'ROUND_UP' :
    $this->multibin_minmax_quantity = ceil($this->multibin_minmax_quantity);
    $this->minmax_multibin_number = ceil($this->minmax_multibin_number);
    $this->minmax_multibin_size = ceil($this->minmax_multibin_size);
    $this->minmax_min_quantity = ceil($this->minmax_min_quantity);
    $this->minmax_max_quantity = ceil($this->minmax_max_quantity);
    break;

   case 'ROUND_DOWN' :
    $this->multibin_minmax_quantity = floor($this->multibin_minmax_quantity);
    $this->minmax_multibin_number = floor($this->minmax_multibin_number);
    $this->minmax_multibin_size = floor($this->minmax_multibin_size);
    $this->minmax_min_quantity = floor($this->minmax_min_quantity);
    $this->minmax_max_quantity = floor($this->minmax_max_quantity);
    break;

   case 'ROUND' :
    $this->multibin_minmax_quantity = round($this->multibin_minmax_quantity);
    $this->minmax_multibin_number = round($this->minmax_multibin_number);
    $this->minmax_multibin_size = round($this->minmax_multibin_size);
    $this->minmax_min_quantity = round($this->minmax_min_quantity);
    $this->minmax_max_quantity = round($this->minmax_max_quantity);
    break;

   case 'default':
    break;
  }
  if ($item_n->planning_method == 'MULTI_MINMAX') {
   if (!empty($this->overwrite_minmax_min_quantity)) {
    $item_n->minmax_min_quantity = $item_n->minmax_max_quantity = $this->overwrite_minmax_min_quantity;
   } else {
    $item_n->minmax_min_quantity = $item_n->minmax_max_quantity = $this->multibin_minmax_quantity;
   }
   $item_n->minmax_multibin_number = $this->minmax_multibin_number;
   $item_n->minmax_multibin_size = $this->minmax_multibin_size;
  } else {
   $item_n->minmax_min_quantity = $this->minmax_min_quantity;
   $item_n->minmax_max_quantity = $this->minmax_max_quantity;
   $item_n->minmax_multibin_number = 0;
   $item_n->minmax_multibin_size = 0;
  }
  try {
   $item_n->save();
//   pa($item_n);
   echo "<br>Update of Min Max numbers for " . $item_n->item_number . ' is Successfully completed ';
  } catch (Exception $e) {
   echo "<br>Update of Min Max numbers for " . $item_n->item_number . ' is failed!' . $e->getMessage();
  }
  return;
 }

 public function prg_minmax_update($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting Min Max Item Updates....<br>';
  $mms = new fp_minmax_suggestion_v();

  if (!empty($parameters['org_id'][0])) {
   $org_id = $parameters['org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $org_id;
  } else {
   $this->message .= '<br> Error! : No org id found @ item ' . __LINE__;
   return $this->message;
  }

  if (!empty($parameters['fp_minmax_header_id'][0])) {
   $fp_minmax_header_id = $parameters['fp_minmax_header_id'][0];
   $mms->plan_id = $fp_minmax_header_id;
   $this->message .= '<br> Entered Min Max Header Id is : ' . $fp_minmax_header_id;
  } else {
   $this->message .= '<br> Error! : No Min Max Header Id is found @ fp_minmax_header ' . __LINE__;
   return $this->message;
  }

  if (!empty($parameters['item_id'][0])) {
   $this->message .= "<br/>Using Min Max Item Update by Item Id ";
   $item_id = $parameters['item_id'][0];
   try {
    $mms->item_id = $item_id;
    $mms_i = $mms->findBy_planId_itemId();
    $mm_item = new item();
    $mm_item->org_id = $org_id;
    foreach ($mms->field_a as $key => $value) {
     if (property_exists($mm_item, $value)) {
      $mm_item->$value = $mms_i->$value;
     }
    }
    $mm_item->_update_item_minmax();
    $this->message .= "<br>Min Max item attributes are successfully updated for item_id - " . $mm_item->item_id_m . ' & org_id ' . $mm_item->org_id .
     ' min max header id : ' . $fp_minmax_header_id;
   } catch (Exception $e) {
    $this->message .= "<br/> Min Max Item Updat fialed for Item id " . $item_id . $e->getMessage();
   }
   return $this->message;
  }

  if (!empty($parameters['from_item_id'][0])) {
   $this->message .= "<br/>Using  Min Max Planner by Item Id Range ";
   $from_item_id = $parameters['from_item_id'][0];
   if (!empty($parameters['to_item_id'][0])) {
    $to_item_id = $parameters['to_item_id'][0];
   } else {
    $to_item_id = $from_item_id;
   }
   $item = new item();
   $item_range = $item->findBy_itemIdRange($from_item_id, $to_item_id);
   foreach ($item_range as $item_record) {
    $mms->item_id = $item_record->item_id;
    $mms_i = $mms->findBy_planId_itemId();
    $mm_item = new item();
    $mm_item->org_id = $org_id;
    foreach ($mms->field_a as $key => $value) {
     if (property_exists($mm_item, $value)) {
      $mm_item->$value = $mms_i->$value;
     }
    }
    try {
     $mm_item->_update_item_minmax();
     $this->message .= "<br>Min Max item attributes are successfully updated for item_id - " . $mm_item->item_id_m . ' & org_id ' . $mm_item->org_id .
      ' fp_minmax_header_id : ' . $fp_minmax_header_id;
    } catch (Exception $e) {
     $this->message .= "<br>Min Max Plannerp failed for Item id " . $mm_item->item_id_m . $e->getMessage();
    }
   }
   return $this->message;
  }

  if (!empty($parameters['from_item_number'][0])) {
   $this->message .= "<br/>Using  Min Max Planner by Item Number Range ";
   $from_item_number = $parameters['from_item_number'][0];
   if (!empty($parameters['to_item_number'][0])) {
    $to_item_number = $parameters['to_item_number'][0];
   } else {
    $to_item_number = $from_item_number;
   }
   $item = new item();
   $item_range = $item->findBy_itemNumberRange_OrgId($from_item_number, $to_item_number, $org_id);
   foreach ($item_range as $item_record) {
    $mms->item_id = $item_record->item_id;
    $mms_i = $mms->findBy_planId_itemId();
    $mm_item = new item();
    $mm_item->org_id = $org_id;
    foreach ($mms->field_a as $key => $value) {
     if (property_exists($mm_item, $value)) {
      $mm_item->$value = $mms_i->$value;
     }
    }
    try {
     $mm_item->_update_item_minmax();
     $this->message .= "<br>Min Max item attributes are successfully updated for item_id - " . $mm_item->item_id_m . ' & org_id ' . $mm_item->org_id .
      ' fp_minmax_header_id : ' . $fp_minmax_header_id;
    } catch (Exception $e) {
     $this->message .= "<br>Min Max Plannerp failed for Item id " . $mm_item->item_id_m . $e->getMessage();
    }
   }
   return $this->message;
  }

  //if no item id/number is given
  $this->message .= "<br/>Updating Min Max Attributes for all Items ";
  $mms_all = $mms->findBy_planId();
  foreach ($mms_all as $mms_records) {
   $mm_item = new item();
   $mm_item->org_id = $org_id;
   foreach ($mms->field_a as $key => $value) {
    if (property_exists($mm_item, $value)) {
     $mm_item->$value = $mms_records->$value;
    }
   }
   try {
    $mm_item->_update_item_minmax();
    $this->message .= "<br>Min Max item attributes are successfully updated for item_id - " . $mm_item->item_id_m . ' & org_id ' . $mm_item->org_id .
     ' fp_minmax_header_id : ' . $mms->plan_id;
   } catch (Exception $e) {
    $this->message .= "<br>Min Max Plannerp failed for Item id " . $mm_item->item_id_m . $e->getMessage();
   }
  }
  return $this->message;
 }

 public function findAll_ofOrgId($org_id = "") {
  global $db;
  $sql = "SELECT * FROM " . self::$table_name;
  $sql .= " WHERE org_id = :org_id ";
  $param_a = ['org_id'];
  $org_id_i = !empty($org_id) ? $org_id : $this->org_id;
  $value_a = ['org_id' => $org_id_i];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !(empty($result)) ? $result : false;
 }

 public function findAll_minmax_ofOrgId($org_id = "") {
  global $db;
  $sql = "SELECT * FROM " . self::$table_name;
  $sql .= " WHERE org_id = :org_id ";
  $sql .= " AND ( planning_method = 'MULTI_MINMAX' || planning_method = 'MINMAX' )";
  $org_id_i = !empty($org_id) ? $org_id : $this->org_id;
  $value_a = ['org_id' => $org_id_i];
  $result = $db->findBysql($sql, $value_a);
  return !(empty($result)) ? $result : false;
 }

 public function findBy_itemNumber_OrgId($org_id = "") {
  global $db;
  $sql = "SELECT * FROM " . self::$table_name;
  $sql .= " where item_number = :item_number ";
  $sql .= " AND org_id = :org_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $param_a = ['item_number', 'org_id'];
  $org_id_i = !empty($org_id) ? $org_id : $this->org_id;
  $value_a = ['item_number' => $this->item_number, 'org_id' => $org_id_i];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !(empty($result)) ? array_pop($result) : false;
 }

 public function findBy_itemNumberRange_OrgId($item_number1, $item_number2, $org_id = "") {
  global $db;
  $sql = "SELECT * FROM " . self::$table_name;
  $sql .= " where item_number BETWEEN :item_number1 AND  :item_number2";
  $sql .= " AND org_id = :org_id ";
  $param_a = ['item_number1', 'item_number2', 'org_id'];
  $org_id_i = !empty($org_id) ? $org_id : $this->org_id;
  $value_a = ['item_number1' => $item_number1,
   'item_number2' => $item_number2,
   'org_id' => $org_id_i];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !(empty($result)) ? $result : false;
 }

 public function findBy_itemIdRange($item_id1, $item_id2) {
  global $db;
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " where item_id BETWEEN :item_id1 AND  :item_id2";
  $param_a = ['item_id1', 'item_id2'];
  $value_a = ['item_id1' => $item_id1, 'item_id2' => $item_id2];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !(empty($result)) ? $result : false;
 }

 public static function find_all_assigned_orgs($item_number) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where item_number= '{$item_number}' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }

 public static function find_all_assigned_org_ids($item_number) {
  global $db;
  $sql = "SELECT org_id FROM " .
   self::$table_name .
   " where item_number= '{$item_number}' ";
  $result = $db->find_by_sql($sql);
  $assigned_inventory_orgs_array = [];

  foreach ($result as $orgs) {
   $assigned_inventory_orgs_array[] = $orgs->org_id;
  }

  return $assigned_inventory_orgs_array;
 }

 public static function find_item_number_by_itemNumber_OrgId($item_number, $org_id = "", $options = '') {
  $sql = "SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " where  ( item_number LIKE '%{$item_number}%' OR item_description LIKE '%{$item_number}%'  )";
  if (!empty($org_id)) {
   $sql .= " AND org_id  = '{$org_id}' ";
  }

  if (!empty($options)) {
   foreach ($options as $key => $val) {
    $sql .= " AND $key  = '{$val}' ";
   }
  }
  
  $result = self::find_by_sql($sql);
    if(empty($result)){
   return false;
  }
  $data = array();
  foreach ($result as $row) {
   $data[] = array(
    'label' => $row->item_number,
    'item_number' => $row->item_number,
    'item_id' => $row->item_id,
    'item_id_m' => $row->item_id_m,
    'item_description' => $row->item_description,
    'uom_id' => $row->uom_id,
    'processing_lt' => $row->processing_lt,
    'lot_generation' => $row->lot_generation,
    'serial_generation' => $row->serial_generation,
    'kit_cb' => $row->kit_cb
   );
  }
//	$return_array['jsonvalue'] = $data;

  return $data;
 }

 public static function find_item_number_by_itemNumber_OrgId_allAttributes($item_number, $org_id = "", $options = '') {
  $sql = "SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " where item_number LIKE '%{$item_number}%' ";
  if (!empty($org_id)) {
   $sql .= " AND org_id  = '{$org_id}' ";
  }
  if (!empty($options)) {
   foreach ($options as $key => $val) {
    if (!empty($val)) {
     $sql .= " AND $key  = '{$val}' ";
    }
   }
  }

  $result = self::find_by_sql($sql);

  if (!empty($result)) {
   foreach ($result as &$obj) {
    $obj->label = $obj->item_number;
   }
  }

  return $result;
 }

 public function copy($item_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM item WHERE `item_id` = '{$item_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `item_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `item_id` = '{$item_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `item` SELECT * FROM tmptable WHERE `item_id` = '' ";
    if ($db->query($sql3)) {
     $this->item_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

 public static function find_itemCategory_byItemId($item_id) {

  $sql = "SELECT category.category_id as category_id,
              category.major_category_id as major_category_id,
               category.category as category, 
               category.parent_id as parent_id, 
               category.description as description,
               category.primary_cb as primary_cb,
               category_reference.category_reference_id as category_reference_id
       FROM 
       category , category_reference
       WHERE category_reference.reference_table = 'item'
       AND category_reference.reference_id = '{$item_id}'
       AND category.category_id = category_reference.category_id";

  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_itemCategory_byItemIdm_and_orgId($item_id_m, $org_id) {

  $sql = "SELECT category.category_id as category_id,
              category.major_category_id as major_category_id,
               category.category as category, 
               category.parent_id as parent_id, 
               category.description as description,
               category.primary_cb as primary_cb,
               category_reference.category_reference_id as category_reference_id
       FROM 
       category , category_reference, item
       WHERE category_reference.reference_table = 'item'
       AND category_reference.reference_id = item.item_id
       AND category.category_id = category_reference.category_id 
       AND item.item_id_m = '{$item_id_m}'
       AND item.org_id = '{$org_id}' ";

  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_ColumnNameVal($columnName, $columnVal, $dependent_fields = '', $hidden_fields = '') {
  $sql = "SELECT * FROM " . static::$table_name . " where " . $columnName . " LIKE  '%{$columnVal}%'  ";
  $show_only_master_items = true;

  if (!empty($hidden_fields)) {
   foreach ($hidden_fields as $k => $v) {
    if (!empty($k) && !empty($v)) {
     if (strpos($k, 'org_id') !== false) {
      $sql .= " AND org_id = '{$v}' ";
      $show_only_master_items = false;
     } else {
      $sql .= " AND $k = '{$v}' ";
     }
    }
   }
  }

  if (!empty($dependent_fields)) {
   foreach ($dependent_fields as $k1 => $v1) {
    if (!empty($k1) && !empty($v1)) {
     if (strpos($k1, 'org_id') !== false) {
      $sql .= " AND org_id = '{$v1}' ";
      $show_only_master_items = false;
     } else {
      $sql .= " AND $k1 = '{$v1}' ";
     }
    }
   }
  }

  if ($show_only_master_items) {
   $sql .= " AND item_id = item_id_m ";
  }

  $result_array = static::find_by_sql($sql);
  return !empty($result_array) ? ($result_array) : false;
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
   'overwrite_minmax_min_quantity',
   'overwrite_minmax_max_quantity',
   'overwrite_minmax_multibin_number',
   'overwrite_minmax_multibin_size'
  ];
  return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'action_class_name',
   'mode',
   'action',
   'show_block',
  ];

  return $multi_select_hidden;
 }

}

//end of item class
?>