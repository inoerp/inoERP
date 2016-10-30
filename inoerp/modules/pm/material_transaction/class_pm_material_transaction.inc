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
 * wip_material_transaction 
 *
 */
class pm_material_transaction extends inv_transaction {

// public static $table_name = "inv_transaction";
// public static $primary_column = "inv_transaction_id";
// public static $key_column = 'item_id_m';
 public static $module = "pm";
 public static $system_info = [
  'name' => 'Material Transaction',
  'number' => '2805',
  'description' => 'Process Manufacturing Material Transaction',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'pm',
  'weight' => 3
 ];
 public static $transaction_type_id_a = [
  '29' => 'Process WIP Issue',
  '30' => 'Process WIP Return',
 ];

 public $initial_search = [
  "inv_transaction_id",
  "transaction_type_id",
  'status',
  "item_id_m",
  "org_id",
  "item_number",
  "creation_date",
  "document_type",
  "document_number"
 ];
 public $account = [
  "from_account_id",
  "to_account_id",
  "account_id"];
 public $checkbox = [
  "logical_transaction_cb",
  "transfer_to_gl_cb",
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
  "transaction_type_id",
  'pm_batch_ingredient_id'
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Process Material Transaction"; //page Title
 public $option_lists = [
  'inv_transaction_class' => 'TRANSACTION_TYPE_CLASS'
 ];
 public $fields_inForm_notInDataBase = [
  "account_id",
  'item_description',
  'serial_generation',
  'serial_number',
  'inv_serial_number_id',
  'lot_generation',
  'lot_number',
  'lot_quantity',
  'kit_cb',
  'onhand',
  'reservable_onhand',
  'line_type',
  'planned_quantity',
  'actual_quantity'
 ];
 public $batch_name;
 public $line_type;
 public $line_id;
 public $planned_quantity;
 public $actual_quantity;

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of inv_transaction class
pm_material_transaction::staticVar_init('transaction_type_id_a');
?>
