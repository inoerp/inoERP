<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @retirement code https://github.com/inoerp/inoERP
 */

/**
 * fa_asset_retirement 
 *
 */
class fa_asset_retirement extends dbObject implements gl_journal_int {

 public static $table_name = "fa_asset_retirement";
 public static $primary_column = "fa_asset_retirement_id";
 public static $key_column = 'fa_asset_id';
 public static $parent_primary_column = "fa_asset_id";
 public static $module = "fa";
 public static $gl_journal_category = "FA_RETIREMENT";
 public static $system_info = [
  'name' => 'Asset Retirement',
  'number' => '1411',
  'description' => 'Asset Retirement',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fa',
  'weight' => 5
 ];
 public static $status_a = [
  'ENTERED' => 'Entered',
  'CONFIRMED' => 'Confirmed',
  'CLOSED' => 'Closed',
 ];
 public static $action_a = [
  'CONFIRM' => 'Confirm Retirement'
 ];
//  data base variables as stored database column name
 public $field_a = [
  'fa_asset_retirement_id',
  'fa_asset_id',
  'fa_asset_book_id',
  'source_type',
  'reference',
  'status',
  'description',
  'retired_units',
  'retired_cost',
  'proceed_of_sales',
  'cost_of_removals',
  'adjustment_amount',
  'retirement_convention',
  'gl_journal_header_id',
  'retire_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'fa_asset_id',
  'reference',
 ];
 public $fields_inForm_notInDataBase = [
  'asset_number',
  'asset_description',
  'status',
  'type',
  'asset_book_name',
  'original_cost',
  'current_cost',
  'ytd_depreciation',
  'accumulated_depreciation',
  'action'
 ];
 public $numberField = [
  'original_cost',
  'current_cost',
  'ytd_depreciation',
  'retired_units',
  'retired_cost',
  'proceed_of_sales',
  'adjustment_amount'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'fa_asset_id',
 ];
 public $requiredField = [
  'fa_asset_id'
 ];
 public $notUpdatedFromWebForm = [
  'gl_journal_header_id',
  'adjustment_amount'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Asset Retirement "; //page Title
 public $fa_asset_retirement_id;
 public $fa_asset_id;
 public $fa_asset_book_id;
 public $source_type;
 public $reference;
 public $status;
 public $description;
 public $retired_units;
 public $retired_cost;
 public $proceed_of_sales;
 public $cost_of_removals;
 public $retirement_convention;
 public $adjustment_amount;
 public $gl_journal_header_id;
 public $retire_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $asset_number;
 public $asset_description;
 public $asset_book_name;
 public $original_cost;
 public $current_cost;
 public $ytd_depreciation;
 public $accumulated_depreciation;
 public $action;
 private $_sav_jrnl;
 public $prg_confirm_retirement_parameters = [
  'Asset Book' => 'search_asset_book'
 ];
 public $prg_confirm_retirement_details = [
  'name' => 'Confirm Retirement',
  'description' => 'Confirm Retirement Program',
 ];

 public function findBy_assetId_bookId() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_asset_id = :fa_asset_id ";
  $sql .= " AND fa_asset_book_id = :fa_asset_book_id ";
  $value_a = ['fa_asset_id' => $this->fa_asset_id, 'fa_asset_book_id' => $this->fa_asset_book_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public function _before_save() {
  if (!empty($this->action) && !empty($this->fa_asset_retirement_id) && ($this->action == 'CONFIRM')) {
   $this->_confirm_retirement($this->fa_asset_retirement_id);
   return 10;
  }
 }

 private function _confirm_retirement($fa_asset_retirement_id) {
  global $dbc;
  /*
   * 1. Update the new cost (current cost - retirement amount) as current cost
   * 2. Calculate the accumulated depriciation amount as per the new cost.
    Adjustment Accumulated Depriciation Amount = Original Accumulated Depriciation - New Acc Depriciation Amount
   * 3. Create adjustment journa entry
   *         Accumulated Depriciation  A/C @ Acc Dpr Adjustment Amount Dr
   *         Retirement Gain/Loss A/C      @ (Retirement Cost - Acc Dpr Adjustment Amount )
   *                                                  Asset Cost A/C @ Retirement Cost Cr
   * 4. Update the retirement by the adjustment amount
   */
  $fa_ar = new fa_asset_retirement();
  $fa_ar->findBy_id($fa_asset_retirement_id);

  if ($fa_ar->status != 'ENTERED') {
   echo '<br>Retirement is not available for confirmation. You can confirm retirements only in Entered Status';
   $dbc->rollback = true;
   return -90;
  }

  $fa_asb = new fa_asset_book_info();
  $fa_asb->fa_asset_id = $this->fa_asset_id;
  $fa_asb->fa_asset_book_id = $this->fa_asset_book_id;
  $fa_asb_i = $fa_asb->findBy_assetId_bookId();
  foreach ($fa_asb_i as $k => $v) {
   $fa_asb->$k = $v;
  }
  if (empty($fa_asb->accumulated_depreciation)) {
   echo '<br>No depreciation found. You dont need retire assets without any depreciation';
   $dbc->rollback = true;
   return -90;
  }
  $this->_update_new_cost($fa_asb);
  $acc_deprn_asPerNewCost = $this->_accumulated_dprn_asPerNewCost();
//  pa($fa_asb);
//  echo "<br>acc_deprn_asPerNewCost is $acc_deprn_asPerNewCost";
  $acc_dprn_adjust_amt = $fa_asb->accumulated_depreciation - $acc_deprn_asPerNewCost;
  $retirement_adjust_amt = $fa_ar->retired_cost - $acc_dprn_adjust_amt;

  $fa_asb->accumulated_depreciation = $acc_deprn_asPerNewCost;
  $fa_asb->save();

  $sav_jrnl['acc_deprication_amt'] = $acc_dprn_adjust_amt;
  $sav_jrnl['asset_cost_amt'] = $fa_ar->retired_cost;
  $all_asset_book_accounts = fa_book_category_assoc::find_all_accounts_byAssetBookId($fa_ar->fa_asset_id, $fa_ar->fa_asset_book_id);
  if (empty($all_asset_book_accounts)) {
   echo "<br>No accumulated depreciation account found. Exiting save journal. Error @ " . __FILE__ . ' @@ ' . __LINE__;
   $dbc->rollback = true;
   return -90;
  }
  $sav_jrnl['acc_deprication_ac_id'] = $all_asset_book_accounts->accumulated_depreciation_ac_id;
  $sav_jrnl['retirement_gl_ac_id'] = $all_asset_book_accounts->retirement_gl_ac_id;
  $fa_asset_assgn = fa_asset_assignment::find_by_parent_id($fa_asb->fa_asset_id);
  if (!empty($fa_asset_assgn[0]->expense_ac_id)) {
   $sav_jrnl['asset_cost_ac_id'] = $fa_asset_assgn[0]->expense_ac_id;
  } else {
   $sav_jrnl['asset_cost_ac_id'] = '999';
  }

  if (empty($fa_ar->gl_journal_header_id)) {
   $fa_ar->_save_journal_header();
  } else {
   $gjh = new gl_journal_header();
   $gjh->findBy_id($fa_ar->gl_journal_header_id);
  }

  if (!empty($fa_ar->gl_journal_header_id)) {
   $fa_ar->_sav_jrnl = $sav_jrnl;
   $fa_ar->_save_journal_lines();
  } else {
   echo "<br>No gl_journal_header_id found. Error @ " . __FILE__ . ' @@ ' . __LINE__;
   $dbc->rollback = true;
   return -90;
  }

  //4. Update the retirement
  $this->_create_asset_transaction();
  $fa_ar->adjustment_amount = $retirement_adjust_amt;
  $fa_ar->save();
 }

 private function _create_asset_transaction() {
  global $dbc;
  $asset_trnx = new fa_asset_transaction();
  $asset_trnx->fa_asset_id = $this->fa_asset_id;
  $asset_trnx->fa_asset_book_id = $this->fa_asset_book_id;
  $asset_trnx->reference_type = 'table';
  $asset_trnx->reference_key_name = 'fa_asset_retirement';
  $asset_trnx->reference_type = $this->fa_asset_retirement_id;
  $asset_trnx->transaction_type = 'RET';
  $asset_trnx->create_journal = false;
  $asset_trnx->quantity = $this->retired_units;
  $asset_trnx->amout = $this->retired_cost;
  try {
   $asset_trnx->_before_save();
   $asset_trnx->save();
   $asset_trnx->_after_save();
  } catch (Exception $e) {
   echo '<br>Failed to create asset transaction. Error @ fa_asset_retirement @@ ' . __LINE__ . ' <br> ' . $e->getMessage();
   $dbc->rollback = true;
  }
 }

 public function _after_save() {
  if (empty($this->status) && !empty($this->fa_asset_retirement_id)) {
   $this->status = 'ENTERED';
   $this->save();
  }
 }

 private function _validate_delete() {
  if (!empty($this->status) && ($this->status == 'COMPLETED')) {
   echo "<br>Delete is not allowed for retirements in completed status ";
   return -99;
  } else {
   return 1;
  }
 }

 public function _before_delete() {
  return $this->_validate_delete();
 }

 private function _update_new_cost(&$fa_asb) {
  global $dbc;

  try {
   $fa_asb->current_cost = $fa_asb->current_cost - $this->retired_cost;
   $fa_asb->save();
  } catch (Exception $e) {
   echo "<br>Unable to update new cost. Error @ " . __FILE__ . ' @@ line ' . __LINE__ . $e->getMessage();
   $dbc->rollback = true;
  }
 }

 private function _accumulated_dprn_asPerNewCost() {
  $fa_asset_book_info_i = fa_asset_book_info::find_by_assetId_bookId($this->fa_asset_book_id, $this->fa_asset_id);

  $start_date = new DateTime($fa_asset_book_info_i->depriciation_start_date);
  $current_date = new DateTime();
  $date_diff = $current_date->diff($start_date);
  $months_for_dprn_completed = ($date_diff->y * 12 ) + $date_diff->m;
  $fa_asset_book_info_i->depriciation_start_date = current_time(true);
  $fa_asset_book_info_i->accumulated_depreciation = 0;

  $fa_dep_h = new fa_depreciation_header();
  $dep_amt_pm = $fa_dep_h->calucate_depriciation_amount($fa_asset_book_info_i);
  $new_acc_deprn_amount = $dep_amt_pm * $months_for_dprn_completed;

  return $new_acc_deprn_amount;
 }

 public static function find_by_assetId_bookId($fa_asset_book_id, $fa_asset_id) {
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where fa_asset_book_id= '{$fa_asset_book_id}'  AND fa_asset_id = '{$fa_asset_id}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function _save_journal_header() {
  global $dbc;
  $gjh = new gl_journal_header;

  $fa_ab = new fa_asset_book();
  $fa_ab->findBy_id($this->fa_asset_book_id);
  $org_fin_details = org::find_financial_details_from_orgId($fa_ab->bu_org_id);

  $gjh->ledger_id = $org_fin_details->ledger_id;
  $gjh->status = 'ENTERED';
  $gjh->currency = $org_fin_details->currency_code;
  $gp = new gl_period();
  $gjh->period_id = $gp->current_open_period($gjh->ledger_id, 'OPEN')->gl_period_id;
  $gjh->journal_source = self::$module;
  $gjh->journal_category = self::$gl_journal_category;
  $gjh->reference_type = 'table';
  $gjh->reference_key_name = self::$table_name;
  $gjh->reference_key_value = $this->fa_asset_retirement_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = 'A';

  try {
   $gjh->save();
   $this->gl_journal_header_id = $gjh->gl_journal_header_id;
   echo "<br> Jounral Header Id #" . $this->gl_journal_header_id . ' is created';
   $this->status = 'COMPLETED';
   $this->save();
  } catch (Exception $e) {
   echo "<br> Failed Saving Jounral Header. Error @ " . __FILE__ . ' @@ Line ' . __LIN__ . '<br>' . $e->getMessage();
   $dbc->rollback = true;
  }
 }

 public function _post_gl_process($fa_depriciation_header_id) {
  return 1;
//  try {
//   $this->findBy_id($fa_depriciation_header_id);
//   $this->status = 'CLOSED';
//   $this->save();
//   return 1;
//  } catch (Exception $e) {
//   echo "<br>Updating depreciation header status failed.Error @ " . __FILE__ . ' @@ line ' . __LINE__ . $e->getMessage();
//   return -99;
//  }
 }

 public function _save_journal_lines() {
  $sav_jrnl = $this->_sav_jrnl;
  $new_gjl = new gl_journal_line();
  $new_gjl->gl_journal_header_id = $this->gl_journal_header_id;
  $new_gjl->reference_key_name = 'fa_depreciation_line';
  $new_gjl->reference_key_value = $this->fa_asset_retirement_id;
  $new_gjl->gl_journal_line_id = null;
  $new_gjl->line_num = 1;
  $new_gjl->status = 'U';
  $new_gjl->code_combination_id = $sav_jrnl['asset_cost_ac_id'];
  $new_gjl->total_cr = $new_gjl->total_ac_cr = $sav_jrnl['asset_cost_amt'];
  $new_gjl->description = 'Retirement id ' . $this->fa_asset_retirement_id;
  $new_gjl->reference_type = 'table';
  $new_gjl->save();

  $new_gjl1 = new gl_journal_line();
  $new_gjl1->gl_journal_header_id = $this->gl_journal_header_id;
  $new_gjl1->gl_journal_line_id = null;
  $new_gjl1->line_num = 2;
  $new_gjl1->status = 'U';
  $new_gjl1->code_combination_id = $sav_jrnl['acc_deprication_ac_id'];
  $new_gjl1->total_dr = $new_gjl1->total_ac_dr = $sav_jrnl['acc_deprication_amt'];
  $new_gjl1->description = 'acc_deprication_amt for Retirement id ' . $this->fa_asset_retirement_id;
  $new_gjl1->save();

  $new_gjl2 = new gl_journal_line();
  $new_gjl2->gl_journal_header_id = $this->gl_journal_header_id;
  $new_gjl2->gl_journal_line_id = null;
  $new_gjl2->line_num = 3;
  $new_gjl2->status = 'U';
  $new_gjl2->code_combination_id = $sav_jrnl['retirement_gl_ac_id'];
  $new_gjl2->total_dr = $new_gjl2->total_ac_dr = $sav_jrnl['asset_cost_amt'] - $sav_jrnl['acc_deprication_amt'];
  $new_gjl2->description = 'Ajustment amount for retirement ' . $this->fa_asset_retirement_id;
  $new_gjl2->save();
 }

 public function prg_confirm_retirement($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting confirm retirement program';

  if (!empty($parameters['fa_asset_book_id'][0])) {
   $this->fa_asset_book_id = $parameters['fa_asset_book_id'][0];
   $this->message .= '<br> Entered fa_asset_book_id Id is : ' . $this->fa_asset_book_id;
  } else {
   $this->message .= '<br> Error! : No fa_asset_book_id found @ fa_depreciation_header  ' . __LINE__;
   return $this->message;
  }

  $retirements_in_enter_status = self::find_by_bookId_status($this->fa_asset_book_id, 'ENTERED');
  foreach ($retirements_in_enter_status as $asst_retirement) {
   $this->_confirm_retirement($asst_retirement->fa_asset_retirement_id);
  }

  return $this->message;
 }

 public static function find_by_bookId_status($fa_book_id, $status = 'ENTERED') {
  $sql = ' SELECT * FROM  ';
  $sql .= self::$table_name;
  $sql .= " WHERE fa_asset_book_id='{$fa_book_id}'  AND status='{$status}' ";

  $result = self::find_by_sql($sql);

  return !empty($result) ? $result : false;
 }

}

//end of reretirement class
?>
