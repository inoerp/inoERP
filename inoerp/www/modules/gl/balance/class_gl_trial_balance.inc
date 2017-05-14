<?php

class gl_trial_balance extends gl_balance_v {

 public static $table_name = "gl_balance_v";
 public static $primary_column = "gl_journal_header_id";
 public $field_a = [
 ];
 public $initial_search = [
  "field1",
  'combination'
 ];
 public $dateField = [
 ];
 public $search = [
 ];
 public $pageTitle = " Balalnce - Find Account Balances "; //page Title
 public $option_lists = [
//		 'po_type' => 'PO_TYPE',
//		 'po_status' => 'PO_STATUS',
 ];
 public $search_functions = [
  'Period Name' => 'search_gl_period_name',
  'Legal Org' => 'search_legal_org_name'
 ];
 public $parent_segments_arrayIterator;
 public $account_code_low_limit;
 public $period_id_for_fs;
 public $account_code_upper_limit;
 public $fs_detail_data = false;
 public $prg_income_statement_details = [
  'name' => 'Generate Income Statement',
  'description' => 'Generate Income Statement',
 ];
 public $prg_income_statement_parameters = [
  'Period Name' => 'search_gl_period_name',
  'Show Details' => 'search_show_details_cb',
  'Legal Org' => 'search_legal_org_name_m'
 ];

 function __construct() {
  if (!empty(static::$table_name)) {
   $this->field_a = get_dbColumns(static::$table_name);
   foreach ($this->field_a as $key => $value) {
    $this->$value = '';
   }
  }
 }

 public function trial_balance($params) {
  global $si;
  $org_name = $si->site_name;
  $last_period = '';
  if (!empty($params['gl_period_id'][0])) {
   $period_id = $params['gl_period_id'][0];
   $current_period = gl_period::find_by_id($period_id)->period_name;
  } else {
   $current_period_p = new DateTime();
   $current_period = $current_period_p->format('M-y');
   $period_id = '';
  }

  $sql = "
   SELECT `period_name` , `combination`, `description`, `balance_type`, 
(IFNULL(begin_balance_dr,0) - IFNULL(begin_balance_cr, 0)) as 'begining_balance' , 
`period_net_dr` as 'debits', `period_net_cr` as 'credits' , 
(IFNULL(begin_balance_dr,0) + IFNULL(period_net_dr,0) - IFNULL(begin_balance_cr, 0) -  IFNULL(period_net_cr,0)) as 'ending_balance'
FROM `gl_balance_v`
WHERE period_id = '{$period_id}' ";

  $result = self::find_by_sql($sql);

  ob_start();
  include_once __DIR__ . '/templates/trial_balance_template.php';
  $report_date = ob_get_contents();
  ob_end_clean();
  return $report_date;
 }

 public function prg_income_statement($params) {
  global $si;
  $org_name = $si->site_name;
  $last_period = '';
  if (!empty($params['gl_period_id'][0])) {
   $period_id = $params['gl_period_id'][0];
   $current_period = gl_period::find_by_id($period_id)->period_name;
  } else {
   $current_period_p = new DateTime();
   $current_period = $current_period_p->format('M-y');
   $period_id = '';
  }

  if (!empty($params['org_id'][0])) {
   $org_id = $params['org_id'][0];
   $org_fin_details = org::find_financial_details_from_orgId($org_id);
   if (!empty($org_fin_details)) {
    $coa_id = $org_fin_details->coa_id;
   }
  }

  if (empty($coa_id)) {
   $coa_id = 1;
  }

  $result_a = [];
  $coa = new coa();
  $coa->coa_id = $coa_id;
  $coa->only_parent = true;
  $coa->account_qualifier = 'R';
  $total_sales = 0;
  $total_sales_tracking = 0;

  $gbv = new gl_balance_v();
  $gbv->period_id_for_fs = $period_id;
  $gbv->account_code_low_limit = $coa->field4_low = '400000';
  $gbv->account_code_upper_limit = $coa->field4_high = '499999';
  $all_revenue_parent_segments = $coa->findAll_accounts_from_coaId();
  if (!empty($all_revenue_parent_segments)) {
   $all_revenue_parent_segments_ai = new ArrayIterator($all_revenue_parent_segments);
  }
  $gbv->parent_segments_arrayIterator = $all_revenue_parent_segments_ai;
  $show_details = false;
  if (!empty($params['show_details'][0]) && ($params['show_details'][0] == 1)) {
   $gbv->fs_detail_data = 1;
   $show_details = true;
  }

  /* Sales Data */
  $ret_a = $gbv->financeStatement_calculateBalance();

  $sum_key = '';

  foreach ($ret_a as $count_k => $record) {
   if ($show_details) {
    if (!empty($record['element_type']) && ($record['element_type'] == 'description' || $record['element_type'] == 'account')) {
     array_push($result_a, $record);
    } else if (!empty($record['element_type']) && ($record['element_type'] == 'total_sum')) {
     $sum_key = $count_k;
    }
   } else {
    if (!empty($record['element_type']) && ($record['element_type'] == 'description')) {
     array_push($result_a, $record);
    } else if (!empty($record['element_type']) && ($record['element_type'] == 'total_sum')) {
     $sum_key = $count_k;
    }
   }
  }


  $this_data_a = [];
  if (!empty($sum_key)) {
   $this_data_a['element_type'] = 'description';
   $this_data_a['element'] = 'TOTAL SALES';
   $this_data_a['amount'] = $ret_a[$sum_key]['amount'];
   $total_sales += $this_data_a['amount'];
   $total_sales_tracking = $total_sales;
   array_push($result_a, $this_data_a);
  }

  /* Cost Of Sales */
  $cost_of_sales = 0;
  $coa->account_qualifier = 'X';
  $gbv->account_code_low_limit = $coa->field4_low = '500000';
  $gbv->account_code_upper_limit = $coa->field4_high = '599999';
  $all_cos_parent_segments = $coa->findAll_accounts_from_coaId();
  if (!empty($all_cos_parent_segments)) {
   $all_cos_parent_segments_ai = new ArrayIterator($all_cos_parent_segments);
   $gbv->parent_segments_arrayIterator = $all_cos_parent_segments_ai;
  }

  $ret_a = $gbv->financeStatement_calculateBalance();
  $sum_key = '';
  foreach ($ret_a as $count_k => $record) {
   if ($show_details) {
    if (!empty($record['element_type']) && ($record['element_type'] == 'description' || $record['element_type'] == 'account')) {
     array_push($result_a, $record);
    } else if (!empty($record['element_type']) && ($record['element_type'] == 'total_sum')) {
     $sum_key = $count_k;
    }
   } else {
    if (!empty($record['element_type']) && ($record['element_type'] == 'description')) {
     array_push($result_a, $record);
    } else if (!empty($record['element_type']) && ($record['element_type'] == 'total_sum')) {
     $sum_key = $count_k;
    }
   }
  }


  if (!empty($sum_key)) {
   $this_data_a['element_type'] = 'description';
   $this_data_a['element'] = 'COST OF SALES';
   $this_data_a['amount'] = $ret_a[$sum_key]['amount'];
   array_push($result_a, $this_data_a);
   $cost_of_sales = $this_data_a['amount'];
   $total_sales_tracking += $cost_of_sales;
  } else {
   $cost_of_sales = 0;
  }


  /* Gross Profit */
  $net_inv = [];
  $this_data_a['element_type'] = 'description';
  $this_data_a['element'] = 'Gross Profit';
  $this_data_a['amount'] = $cost_of_sales + $total_sales;
  array_push($result_a, $this_data_a);



  /* Expenses  */
  $expenses = 0;
  $gbv->account_code_low_limit = $coa->field4_low = '600000';
  $gbv->account_code_upper_limit = $coa->field4_high = '699999';
  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  if (!empty($all_asset_parent_segments)) {
   $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
  }
  $gbv->parent_segments_arrayIterator = $all_asset_parent_segments_ai;
  $ret_a = $gbv->financeStatement_calculateBalance();
  $sum_key = '';
  foreach ($ret_a as $count_k => $record) {
   if ($show_details) {
    if (!empty($record['element_type']) && ($record['element_type'] == 'description' || $record['element_type'] == 'account')) {
     array_push($result_a, $record);
    } else if (!empty($record['element_type']) && ($record['element_type'] == 'total_sum')) {
     $sum_key = $count_k;
    }
   } else {
    if (!empty($record['element_type']) && ($record['element_type'] == 'description')) {
     array_push($result_a, $record);
    } else if (!empty($record['element_type']) && ($record['element_type'] == 'total_sum')) {
     $sum_key = $count_k;
    }
   }
  }

  if (!empty($sum_key)) {
   $this_data_a['element_type'] = 'description';
   $this_data_a['element'] = 'EXPENSES';
   $this_data_a['amount'] = $ret_a[$sum_key]['amount'];
   array_push($result_a, $this_data_a);
   $expenses = $this_data_a['amount'];
   $total_sales_tracking += $expenses;
  } else {
   $expenses = 0;
  }


  /* Operating Income */
  $net_inv = [];
  $this_data_a['element_type'] = 'description';
  $this_data_a['element'] = 'Operating Income';
  $this_data_a['amount'] = $total_sales_tracking;
  array_push($result_a, $this_data_a);


  /* Other Income & Expense  */
  $other_ie = 0;
  $gbv->account_code_low_limit = $coa->field4_low = '700000';
  $gbv->account_code_upper_limit = $coa->field4_high = '999999';
  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  if (!empty($all_asset_parent_segments)) {
   $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
  }
  $gbv->parent_segments_arrayIterator = $all_asset_parent_segments_ai;
  $ret_a = $gbv->financeStatement_calculateBalance();
  $sum_key = '';
  foreach ($ret_a as $count_k => $record) {
   if ($show_details) {
    if (!empty($record['element_type']) && ($record['element_type'] == 'description' || $record['element_type'] == 'account')) {
     array_push($result_a, $record);
    } else if (!empty($record['element_type']) && ($record['element_type'] == 'total_sum')) {
     $sum_key = $count_k;
    }
   } else {
    if (!empty($record['element_type']) && ($record['element_type'] == 'description')) {
     array_push($result_a, $record);
    } else if (!empty($record['element_type']) && ($record['element_type'] == 'total_sum')) {
     $sum_key = $count_k;
    }
   }
  }

  if (!empty($sum_key)) {
   $this_data_a['element_type'] = 'description';
   $this_data_a['element'] = 'Total Other Income/Expense';
   $this_data_a['amount'] = $ret_a[$sum_key]['amount'];
   array_push($result_a, $this_data_a);
   $other_ie = $this_data_a['amount'];
   $total_sales_tracking += $other_ie;
  } else {
   $other_ie = 0;
  }


  /* Operating Income */
  $net_inv = [];
  $this_data_a['element_type'] = 'description';
  $this_data_a['element'] = 'PRETAX INCOME';
  $this_data_a['amount'] = $total_sales_tracking;
  array_push($result_a, $this_data_a);




  return $result_a;
 }

}

//end of po_detail class
?>