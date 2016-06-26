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
 * ar_transaction_adjustment 
 *
 */
class ar_transaction_adjustment extends dbObject {

 public static $table_name = "ar_transaction_adjustment";
 public static $primary_column = "ar_transaction_adjustment_id";
 public static $key_column = 'ar_transaction_line_id';
 public static $parent_primary_column = "ar_transaction_header_id";
 public static $module = "ar";
 public static $system_info = [
  'name' => 'Transaction Adjustments',
  'number' => '2605',
  'description' => 'Transaction Adjustments',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ar',
  'weight' => 5
 ];
 public static $gl_journal_category = "AR_ADJUSTMENT";
 public static $transaction_type_a = [
  'ADJ' => 'Adjustment'
 ];
//  data base variables as stored database column name
 public $field_a = [
  'ar_transaction_adjustment_id',
  'ar_transaction_header_id',
  'ar_receivable_activity_id',
  'adjustment_amount',
  'description',
  'adjustment_date',
  'adjustment_ac_id',
  'ar_transaction_line_id',
  'reason',
  'status',
  'line_source',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'period_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
//variables used for showing data
 public $initial_search = [
  'ar_transaction_header_id',
  'ar_receivable_activity_id',
 ];
 public $fields_inForm_notInDataBase = [
  'transaction_number',
  'line_number',
  'transaction_status',
  'transaction_type'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'org_id',
  'ar_transaction_header_id'
 ];
 public $requiredField = [
  'ar_transaction_header_id',
  'ar_receivable_activity_id',
  'adjustment_amount',
  'description',
  'adjustment_date',
  'adjustment_ac_id',
  'ar_transaction_line_id',
 ];
 public $profile_default = [
  'org_id' => 'org_bu_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Transaction Adjustments"; //page Title
 public $ar_transaction_adjustment_id;
 public $ar_transaction_header_id;
 public $ar_receivable_activity_id;
 public $adjustment_amount;
 public $description;
 public $adjustment_date;
 public $adjustment_ac_id;
 public $ar_transaction_line_id;
 public $reason;
 public $status;
 public $line_source;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $period_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $transaction_number;
 public $line_number;
 public $transaction_status;
 public $transaction_type;

 private function _save_journal_header() {
  $inv = new inventory();
  $inv_i = $inv->findRelatedDetail_ByOrgId($this->org_id);
  $gled = new gl_ledger();
  $gled->findBy_id($inv_i->ledger_id);
  $gp = new gl_period();
  $current_open_period = $gp->current_open_period($inv_i->ledger_id);
  $gjh = new gl_journal_header;
  $gjh->ledger_id = $inv_i->ledger_id;
  $gjh->status = 'ENTERED';
  $gjh->currency = $gled->currency_code;
  $gjh->period_id = $current_open_period->gl_period_id;
  $gjh->journal_source = self::$module;
  $gjh->journal_category = self::$gl_journal_category;
  $gjh->reference_type = 'table';
  $gjh->reference_key_name = self::$table_name;
  $gjh->reference_key_value = $this->ar_transaction_adjustment_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = 'A';
  $gjh->save();
  $this->gl_journal_header_id = $gjh->gl_journal_header_id;
  echo "<br> The New Journal Header Id is " . $this->gl_journal_header_id;
  return $gjh->gl_journal_header_id;
 }

 private function _save_journal_lines($data) {
  global $dbc;
  foreach ($data as $data_a) {
   $new_gjl = new gl_journal_line();
   $new_gjl->gl_journal_header_id = $this->gl_journal_header_id;
   $new_gjl->line_num = $data_a['line_number'];
   $new_gjl->status = 'U';
   $new_gjl->code_combination_id = $data_a['account_id'];
   if (($data_a['dr_cr']) == 'dr') {
    $new_gjl->total_dr = $data_a['amount'];
    $new_gjl->total_ac_dr = $data_a['amount'];
   } else {
    $new_gjl->total_cr = $data_a['amount'];
    $new_gjl->total_ac_cr = $data_a['amount'];
   }
   $new_gjl->description = 'WIP Resource Transaction Id ' . $this->ar_transaction_adjustment_id;
   $new_gjl->reference_type = 'table';
   $new_gjl->reference_key_name = 'ar_transaction_adjustment_id';
   $new_gjl->reference_key_value = $this->ar_transaction_adjustment_id;
   $new_gjl->save();
  }
 }

 public function _after_save() {
  global $db;
  //Insert in WIP WO BOM - item issues for operational pull
  if ((!empty($this->ar_transaction_adjustment_id)) && (!(empty($this->wip_wo_routing_detail_id))) && (!(empty($this->transaction_quantity)))) {
   $wip_wo_routing_detail = new wip_wo_routing_detail();
   $wip_wo_routing_detail_i = $wip_wo_routing_detail->findBy_id($this->wip_wo_routing_detail_id);
   if ($wip_wo_routing_detail->charge_type != 'WIP_MOVE') {
    return 10;
   }
   $wip_wo_routing_detail->wip_wo_routing_detail_id = $wip_wo_routing_detail_i->wip_wo_routing_detail_id;
   $wip_wo_routing_detail->applied_quantity = $wip_wo_routing_detail_i->applied_quantity + $this->transaction_quantity;
   try {
    $wip_wo_routing_detail->audit_trial();
    $wip_wo_routing_detail->save();
    $resource = new bom_resource();
    $resource->findBy_id($wip_wo_routing_detail->resource_id);
    $bom_resource_cost = bom_resource_cost::find_by_resourceId_bomCostType($wip_wo_routing_detail->resource_id);
    $resource_unit_cost = !empty($bom_resource_cost->resource_rate) ? $bom_resource_cost->resource_rate : 0;
    $total_amount = $resource_unit_cost * $this->transaction_quantity;

    if (!empty($total_amount)) {
     $journal_line_a = [];
     $journal_line = [];
     $this->_save_journal_header();
     $line_number = 1;
     $woh = new wip_wo_header();
     $woh->findBy_id($this->wip_wo_header_id);
     $wip_accounting_group = new wip_accounting_group();
     $wip_accounting_group->findBy_id($woh->wip_accounting_group_id);
     $journal_line['line_number'] = $line_number;
     $journal_line['amount'] = $total_amount;
     $journal_line['account_id'] = $wip_accounting_group->resource_ac_id;
     $journal_line['dr_cr'] = 'dr';
     array_push($journal_line_a, $journal_line);
     $line_number++;
     $journal_line['line_number'] = $line_number;
     $journal_line['amount'] = $total_amount;
     $journal_line['account_id'] = $resource->absorption_ac_id;
     $journal_line['dr_cr'] = 'cr';
     array_push($journal_line_a, $journal_line);
     $this->_save_journal_lines($journal_line_a);
    }
    echo "<br> The resource quantity is Successfullyapplied ";
   } catch (Exception $e) {
    echo "<br> Resource quantity application " . $e->getMessage();
   }
  }
 }

 public function save() {
  $primary_column = static::$primary_column;
  if (empty($this->$primary_column)) {
   $this->create();
  } else {
   echo '<div class="message"> You are not allowed to update a completed adjustment!</div>';
  }
  return $this->msg;
 }

}

//end of resource class
?>