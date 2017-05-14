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
 * inv_serial_number
 * Contains all the inv_serial_number information, such as - serial_number, item_id_m, org_id,  inv_serial_number_id, etc.
 * 
 */
class inv_serial_number extends dbObject {

 public static $table_name = "inv_serial_number";
 public static $primary_column = "inv_serial_number_id";
 public static $key_column = 'item_id_m';
 public static $module = "inv";
 public static $system_info = [
  'name' => 'Serial Number',
  'number' => '2123',
  'description' => 'Inventory Serial Number',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 13
 ];
 public static $origination_type_a = [
  'INVENTORY' => 'Inventory',
  'WIP_COMPLETION' => 'WIP Completion',
  'RECEVING' => 'Receving',
  'SHIPMENT' => 'Shipment',
  'MANUAL' => 'Manual',
  'SYS_GEN' => 'System Generated',
 ];
 public $field_a = [
  'inv_serial_number_id',
  'serial_number',
  'item_id_m',
  'generation',
  'org_id',
  'lock_cb',
  'first_inv_transaction_id',
  'reference_key_name',
  'reference_key_value',
  'status',
  'origination_type',
  'origination_date',
  'activation_date',
  'current_org_id',
  'supplier_site_id',
  'po_header_id',
  'supplier_sn',
  'supplier_ln',
  'inv_lot_number_id',
  'current_subinventory_id',
  'current_locator_id',
  'item_revision',
  'parent_serial_number_id',
  'original_wip_wo_header_id',
  'current_wip_wo_header_id',
  'last_inv_transaction_id',
  'country_of_origin',
  'fixed_asset_cb',
  'description',
  'ar_customer_site_id',
  'sd_so_line_id',
  'fa_asset_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $dateFields = [
  'activation_date',
 ];
 public $initial_search = [
  'item_id_m',
  'current_org_id',
  'current_subinventory_id',
  'current_locator_id'
 ];
 public $fields_inForm_notInDataBase = [
  'org',
  'subinventory',
  'locator',
  'item_number',
  'item_description',
  'org_id',
  'transaction_type',
  'transaction_type_id'
 ];
 public $requiredField = [
  'item_id_m',
  'generation',
  'org_id',
 ];
 public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $search_functions = [
  'Organization' => 'search_org_name',
 ];
 public $prg_create_serial_number_parameters = [
  'Organization' => 'search_org_name',
  'Item Number From' => 'search_item_number_from',
  'Item Number To' => 'search_item_number_to',
  'Number of S/N' => 'search_quantity',
 ];
 public $prg_create_serial_number_details = [
  'name' => 'Create Pre Defined Serail Numbers',
  'description' => 'Create Pre Defined Serail Numbers',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Serial Number ";
 public $inv_serial_number_id;
 public $serial_number;
 public $item_id_m;
 public $generation;
 public $org_id;
 public $lock_cb;
 public $first_inv_transaction_id;
 public $reference_key_name;
 public $reference_key_value;
 public $origination_type;
 public $origination_date;
 public $status;
 public $activation_date;
 public $current_org_id;
 public $supplier_site_id;
 public $po_header_id;
 public $supplier_sn;
 public $supplier_ln;
 public $inv_lot_number_id;
 public $current_subinventory_id;
 public $current_locator_id;
 public $item_revision;
 public $parent_serial_number_id;
 public $original_wip_wo_header_id;
 public $current_wip_wo_header_id;
 public $last_inv_transaction_id;
 public $country_of_origin;
 public $fixed_asset_cb;
 public $description;
 public $ar_customer_site_id;
 public $sd_so_line_id;
 public $fa_asset_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $org;
 public $subinventory;
 public $locator;
 public $item_number;
 public $item_description;
 private $_update_item_starting_serial_number = 0;
 public $message;
 public $inv_serial_transaction_id;
 public $transaction_type_id;
 public $transaction_type;
 public $from_subinventory;
 public $to_subinventory;
 public $from_locator;
 public $to_locator;
 public $uom_id;
 public $lot_number_id;
 public $document_type;
 public $document_number;
 public $document_id;
 public $inv_transaction_id;
 public $reason;
 public $from_org_id;
 public $from_subinventory_id;
 public $to_org_id;
 public $to_subinventory_id;
 public $from_locator_id;
 public $to_locator_id;
 public $serial_generation;
 public $serial_number_id;
 public $find_nonres_serial = false;

 Public static function serail_status() {
  $option_header = option_header::find_by_name('INV_SEARIAL_STATUS');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public function _before_save() {
  if (!empty($this->item_id_m) && !empty($this->org_id) && empty($this->inv_serial_number_id)) {
   $item_i = item::find_by_orgId_item_id_m($this->item_id_m, $this->org_id);
   if (empty($item_i->serial_generation) || ($item_i->serial_generation != 'PRE_DEFINED')) {
    echo "<br>Item serial generation is not pre-defined. You can manually generate serial number for SN pre-defined items";
    return -99;
   } else {
    $this->_update_item_starting_serial_number = 1;
   }
  } else if (empty($this->inv_serial_number_id)) {
   echo "<br>Missing Item Number or Org";
   return -99;
  }
 }

 public function _after_save() {
  if (!empty($this->inv_serial_number_id) && ($this->_update_item_starting_serial_number == 1)) {
   $item = new item();
   $item->org_id = $this->org_id;
   $item->item_id_m = $this->item_id_m;
   $item_i = $item->findBy_orgId_itemIdM();

   $item->item_id = $item_i->item_id;
   $item->serial_starting_number = !empty($item_i->serial_starting_number) ? $item_i->serial_starting_number + 1 : 1;
   $item->audit_trial();
   $item->save();
  }
 }

 public function findBy_itemIdM_OrgId_status() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE item_id_m = :item_id_m  ";
  $sql .= " AND current_org_id = :current_org_id  ";
  $value_a = ['item_id_m' => $this->item_id_m, 'current_org_id' => $this->current_org_id];
  if (!empty($this->status)) {
   $sql .= " AND status = :status  ";
   $value_a['status'] = $this->status;
  }

  if (!empty($this->current_subinventory_id)) {
   $sql .= " AND current_subinventory_id = :current_subinventory_id  ";
   $value_a['current_subinventory_id'] = $this->current_subinventory_id;
  }
  if (!empty($this->current_locator_id)) {
   $sql .= " AND current_locator_id = :current_locator_id  ";
   $value_a['current_locator_id'] = $this->current_locator_id;
  }
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? ($result) : false;
 }

 public function findBasic_SerialInfo() {
  $sql = " SELECT ins.inv_serial_number_id,    ins.serial_number,    ins.item_id_m,    ins.generation,  ins.org_id, ins.current_org_id, "
   . " ins.current_subinventory_id, ins.current_locator_id, ins.status  ";
  $sql .= " FROM  inv_serial_number ins ";
  $sql .= " WHERE ins.item_id_m = :item_id_m  ";
  $sql .= " AND ins.status = :status  ";
  $value_a = ['item_id_m' => $this->item_id_m, 'status' => $this->status];

  if (!empty($this->current_org_id)) {
   $sql .= " AND ins.current_org_id = :current_org_id  ";
   $value_a['current_org_id'] = $this->current_org_id;
  }

  if (!empty($this->current_subinventory_id)) {
   $sql .= " AND ins.current_subinventory_id = :current_subinventory_id  ";
   $value_a['current_subinventory_id'] = $this->current_subinventory_id;
  }
  if (!empty($this->current_locator_id)) {
   $sql .= " AND ins.current_locator_id = :current_locator_id  ";
   $value_a['current_locator_id'] = $this->current_locator_id;
  }

  if (!empty($this->find_nonres_serial)) {
   $sql .= " AND ins.inv_serial_number_id NOT IN";
   $sql .= " (SELECT DISTINCT(inv_serial_number_id) FROM inv_reservation ) ";
  }
//   echo "<br> sql is $sql, $this->item_id_m, $this->current_org_id, $this->status";
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? ($result) : false;
 }

 public function prg_create_serial_number($seralized_parameters) {
  global $dbc;
  $parameters = unserialize($seralized_parameters);
  $this->message .= '<br> Starting serial number generation program';

  if (!empty($parameters['org_id'][0])) {
   $this->org_id = $org_id = $parameters['org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $org_id;
  } else {
   $this->message .= '<br> Error! : No org id found @ cst_item_cost_header ' . __LINE__;
   return $this->message;
  }

  if (!empty($parameters['quantity'][0])) {
   $noof_serial_numbers = $parameters['quantity'][0];
   $this->message .= '<br> Entered Number Of Serial Numbers are : ' . $noof_serial_numbers;
  } else {
   $this->message .= '<br>No parameter found for number of serial numbers. Using default value 1';
   $noof_serial_numbers = 1;
  }

  if (!empty($parameters['from_item_number'][0])) {
   $this->message .= "<br>Creating Serail Numbers By Item Number Range ";
   $from_item_number = $parameters['from_item_number'][0];
   if (!empty($parameters['to_item_number'][0])) {
    $to_item_number = $parameters['to_item_number'][0];
   } else {
    $to_item_number = $from_item_number;
   }
   $item = new item();
   $item_range = $item->findBy_itemNumberRange_OrgId($from_item_number, $to_item_number, $org_id);
   foreach ($item_range as $items) {
    if ($items->serial_generation != 'PRE_DEFINED') {
     $this->message .= "<br>$items->item_number is not pre defined in org_id $org_id ";
     continue;
    }

    for ($i = 0; $i < $noof_serial_numbers; $i++) {
     $isn = new inv_serial_number();
     $isn->item_id_m = $items->item_id_m;
     $isn->org_id = $org_id;
     $isn->current_org_id = $org_id;
     $isn->generation = 'PRE_DEFINED';
     $isn->status = 'DEFINED';
     $isn->origination_type = 'SYS_GEN';
     $isn->origination_date = current_time(1);
     $isn->description = 'Generated by program on' . current_time(1);
     $isn->inv_lot_number_id = null;
     $starting_serial_number = $items->serial_starting_number + $i;
     $isn->serial_number = $items->serial_prefix . $starting_serial_number;
     $isn->audit_trial();
     $isn->save();
     $dbc->confirm();
    }
    $item->serial_starting_number = !empty($items->serial_starting_number) ? $items->serial_starting_number + $i : $i + 1;
    $item->item_id = $items->item_id;
    $item->audit_trial();
    $item->save();
    $item->item_id = null;
   }
  }
  return $this->message;
 }

 public static function find_by_woHeaderId_inWIP($wo_header_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE status = 'IN_WIP' ";
  $sql .= " AND  current_wip_wo_header_id = '{$wo_header_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_currentLocation($item_id_m, $current_org_id, $current_subinventory_id, $current_locator_id = '', $non_reserved = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE status = 'IN_STORE' ";
  $sql .= " AND  item_id_m = '{$item_id_m}' ";
  $sql .= " AND  current_subinventory_id = '{$current_subinventory_id}' ";
  $sql .= " AND  current_org_id = '{$current_org_id}' ";
  if (!empty($current_locator_id)) {
   $sql .= " AND  current_locator_id = '{$current_locator_id}' ";
  }
  if (!empty($non_reserved)) {
   $sql .= " AND inv_serial_number_id NOT IN";
   $sql .= " (SELECT DISTINCT(inv_serial_number_id) FROM inv_reservation  WHERE inv_serial_number_id IS NOT NULL ) ";
  }
//   echo $sql;
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_allChild_bySerialId($serial_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE parent_serial_number_id = '{$serial_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function create_parentChildRelation($parent_serial_id, $wo_header_id, $update_status = true) {
  $all_child_sn = self::find_by_woHeaderId_inWIP($wo_header_id);
  $csn = new inv_serial_number();
  foreach ($all_child_sn as $child_sn) {
   $csn->findBy_id($child_sn->inv_serial_number_id);
   $csn->parent_serial_number_id = $parent_serial_id;
   if ($update_status) {
    $csn->status = 'OUT_STORE';
    $csn->current_wip_wo_header_id = '';
   }
   $csn->audit_trial();
   $csn->save();
  }
 }

}

//end of inv_serial_number class
?>