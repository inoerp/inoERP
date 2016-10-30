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
 * wip_completion_transaction 
 *
 */
class pm_completion_transaction extends inv_transaction {

// public static $table_name = "inv_transaction";
// public static $primary_column = "inv_transaction_id";
// public static $key_column = 'item_id_m';
 public static $module = "pm";
 public static $system_info = [
  'name' => 'Completion Transaction',
  'number' => '2803',
  'description' => 'Process Manufacturing Completion Transaction',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'pm',
  'weight' => 3
 ];
 public static $transaction_type_id_a = [
  '31' => 'Batch Completion',
  '32' => 'Batch Return',
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
  'pm_batch_header_id'
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Process completion Transaction"; //page Title
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
  'line_type_code',
  'planned_quantity',
  'actual_quantity'
 ];
 public $batch_name;
 public $line_type;
 public $line_type_code;
 public $line_id;
 public $planned_quantity;
 public $actual_quantity;

 public function _before_save() {
  global $dbc;
  if (!empty($_POST['line_type_code']) && $_POST['line_type_code'] == 'pm_batch_line') {
   try {
    $this->_do_line_action();
   } catch (Exception $e) {
    $dbc->rollback = true;
    echo "<br>Failed to complete operation line transaction @ " . get_class($this) . ' @@ ' . __LINE__;
    return 10;
   }
  }
 }

 private function _do_line_action() {
  //find all operations and do operation trasaction with line action
  $all_operation_lines = pm_batch_operation_line::find_by_parent_id($this->pm_batch_header_id);
  foreach ($all_operation_lines as $operation_line) {
   if ($operation_line->release_type == 'AUTO' && empty($operation_line->status)) {
    $op_line = new pm_batch_operation_line();
    $op_line->findBy_id($operation_line->pm_batch_operation_line_id);
    $op_line->line_action = 'COMPLETE';
    $op_line->_before_save();
    $op_line->save();
   }
  }
 }

 public static function staticVar_init($staticvar) {
  foreach (self::${$staticvar} as $key => $value) {
   self::${$staticvar}[$key] = gettext($value);
  }
 }

}

//end of inv_transaction class
pm_completion_transaction::staticVar_init('transaction_type_id_a');
?>
