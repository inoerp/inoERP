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
 * wip_wo_completion 
 *
 */
class wip_wol_transaction extends inv_transaction {

 public static $table_name = "inv_transaction";
 public static $primary_column = "inv_transaction_id";
 public static $dependent_classes = ['wip_wo_header'];
 public static $key_column = 'item_id_m';
 public static $module = "wip";
 public static $system_info = [
  'name' => 'WOL Completion',
  'number' => '2608',
  'description' => 'Work Order Less Transaction',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'wip',
  'weight' => 7
 ];
 public static $transaction_type_id_a = [
  '10' => 'Work Order Less Completion',
  '12' => 'Work Order Less Return',
 ];
 public $field_a = [
  'wip_wol_transaction_id',
  'item_id_m',
  'description',
  'revision_name',
  'org_id',
  'wip_accounting_group_id',
  'transaction_type_id',
  'transaction_status',
  'start_date',
  'completion_date',
  'quantity',
  'nettable_quantity',
  'reference_bom_item_id_m',
  'reference_routing_item_id_m',
  'completion_sub_inventory',
  'completion_locator',
  'completed_quantity',
  'scrapped_quantity',
  'line',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'wip_wol_transaction_id',
  'item_id_m',
  'start_date',
 ];
 public $checkbox = [
  "logical_transaction_cb",
  "transaction_rev_enabled_cb"];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "org_id",
  "transaction_type_id"
 ];
 public $requiredField = [
  "item_number",
  "uom_id",
  "quantity",
  "org_id",
  "item_id_m",
  "transaction_type_id"
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $pageTitle = " WIP - Create & View WO Completion"; //page Title
 public $option_lists = [
  'inv_transaction_class' => 'TRANSACTION_TYPE_CLASS'
 ];
 public $fields_inForm_notInDataBase = [
  "account_id",
  'item_description',
  'wip_wo_bom_id',
  'wip_wo_header_id',
  'bom_sequence'
 ];
 public $numberField = [
  'quantity',
  'nettable_quantity',
 ];
 public $wip_wol_transaction_id;
 public $item_id_m;
 public $description;
 public $revision_name;
 public $org_id;
 public $wip_accounting_group_id;
 public $transaction_type_id;
 public $transaction_status;
 public $start_date;
 public $completion_date;
 public $quantity;
 public $nettable_quantity;
 public $reference_bom_item_id_m;
 public $reference_routing_item_id_m;
 public $completion_sub_inventory;
 public $completion_locator;
 public $completed_quantity;
 public $scrapped_quantity;
 public $line;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of inv_transaction class
?>