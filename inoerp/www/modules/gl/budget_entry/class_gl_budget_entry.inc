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
 * gl_budget_entry 
 *
 */
class gl_budget_entry extends dbObject {

 public static $table_name = "gl_budget_entry";
 
 public static $primary_column = "gl_budget_entry_id";
 public static $key_column = 'gl_budget_ac_line_id';
 public static $module = "gl";
 public static $system_info = [
		 'name' => 'Budget Entry',
		 'number' => '1111',
		 'description' => 'GL Budget Entry',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'wip',
		 'weight' => 5
 ];
 public static $gl_journal_category = "GL_BUDGET_ENTRY";
//  data base variables as stored database column name
 public $field_a = [
		 'gl_budget_entry_id',
		 'gl_budget_id',
		 'ledger_id',
		 'gl_budget_ac_line_id',
		 'gl_budget_ac_header_id',
		 'status',
		 'currency',
		 'description',
		 'gl_ac_id',
		 'budget_amount',
		 'gl_period_id',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
		 'gl_budget_ac_line_id',
		 'gl_budget_ac_header_id',
 ];
 public $fields_inForm_notInDataBase = [
		 'remaining_quantity',
		 'first_period_id'
 ];

 public $fields_inHeader_needsToBeInserted_inPOST = [
		 'gl_budget_ac_header_id',
		 'status',
		 'gl_budget_ac_line_id',
		 
 ];
 public $requiredField = [
		 'gl_budget_ac_line_id',
		 'gl_budget_ac_header_id',
		 'gl_ac_id'
 ];
 
  public $profile_default = [
  'ledger_id' => 'gl_ledger_id_default',
 ];

 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " GL Budget Entry "; //page Title
 public $gl_budget_entry_id;
 public $gl_budget_id;
 public $gl_budget_ac_line_id;
 public $gl_budget_ac_header_id;
 public $status;
 public $currency;
 public $description;
 public $gl_ac_id;
 public $budget_amount;
 public $gl_period_id;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $first_period_id;

 

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
	$gjh->reference_key_value = $this->gl_budget_entry_id;
	$gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
	$gjh->description = $gjh->journal_name . '-' . current_time();
	$gjh->balance_type = 'B';
	$gjh->audit_trial();
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
	 $new_gjl->description = 'WIP Resource Transaction Id ' . $this->gl_budget_entry_id;
	 $new_gjl->reference_type = 'table';
	 $new_gjl->reference_key_name = 'gl_budget_entry_id';
	 $new_gjl->reference_key_value = $this->gl_budget_entry_id;
	 $new_gjl->audit_trial();
	 $new_gjl->save();
	}
 }

 public function _after_save() {
	global $db;
	//Insert in WIP WO BOM - item issues for operational pull
	if ((!empty($this->gl_budget_entry_id)) && (!(empty($this->wip_wo_routing_detail_id))) && (!(empty($this->transaction_quantity)))) {
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


}

//end of resource class
?>