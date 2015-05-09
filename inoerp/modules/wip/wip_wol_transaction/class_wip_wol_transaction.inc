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
 * wip_wol_completion 
 * Need to be tested and completed
 *
 */
class wip_wol_transaction extends dbObject {

 public static $table_name = "wip_wol_transaction";
 public static $primary_column = "wip_wol_transaction_id";
 public static $dependent_classes = ['wip_wo_bom','wip_wol_transaction_line'];
 public static $key_column = 'item_id_m';
 public static $module = "wip";
 public static $system_info = [
  'name' => 'WOL Completion',
  'number' => '2609',
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
  'completion_date',
  'quantity',
  'reference_bom_item_id_m',
  'reference_routing_item_id_m',
  'completion_sub_inventory',
  'completion_locator',
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
  "item_id_m",
  'org_id',
  'quantity',
  'wip_accounting_group_id'
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $pageTitle = " WIP - Create & View WO Completion"; //page Title

 public $fields_inForm_notInDataBase = [
  "account_id",
  'item_description',
  'wip_wo_bom_id',
  'wip_wo_header_id',
  'bom_sequence',
  'item_number'
  
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
 public $reference_bom_item_id_m;
 public $reference_routing_item_id_m;
 public $completion_sub_inventory;
 public $completion_locator;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $bom_sequence;
 public $item_number ;


}

//end of inv_transaction class
?>