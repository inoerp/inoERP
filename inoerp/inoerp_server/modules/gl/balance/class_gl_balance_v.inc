<?php

class gl_balance_v extends dbObject {

 public static $form_class_name = "gl_balance";
 public static $table_name = "gl_balance_v";
 public static $primary_column = "gl_journal_header_id";
 public $field_a = [
 ];
 public $initial_search = [
  "field1",
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
 public $prg_update_description_details = [
  'name' => 'Update Account Combination Description',
  'description' => 'Run update Description program',
 ];
 public $prg_balance_sheet_details = [
  'name' => 'Generate Balance Sheet',
  'description' => 'Generate Balance Sheet',
 ];
 public $prg_balance_sheet_parameters = [
  'Period Name' => 'search_gl_period_name',
  'Show Details' => 'search_show_details_cb',
  'Legal Org' => 'search_legal_org_name_m'
 ];
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

 public function create_gl_balance_v() {
  $SQL = "
   SELECT  cc.combination, gjl.code_combination_id,
cc.coa_id, sum(gjl.total_cr), sum(gjl.total_dr),
sum(gjl.total_ac_dr), sum(gjl.total_ac_cr) ,
cc.description, gjl.gl_journal_line_id,
gjl.gl_journal_header_id, gjl.line_num, gjl.line_type, gjl.description,
gjl.reference_type, gjl.reference_key_name, gjl.reference_key_value , 
cc.coa_structure_id, cc.field1, cc.field2, cc.field3,
cc.field4, cc.field5, cc.field6, cc.field7, cc.field8,
gjh.gl_journal_header_id, gjh.period_name, gjh.balance_type, gjh.post_date

FROM gl_journal_line gjl 
LEFT JOIN gl_journal_header gjh ON gjl.gl_journal_header_id = gjh.gl_journal_header_id
LEFT JOIN coa_combination cc ON gjl.code_combination_id=cc.coa_combination_id
group by gjl.code_combination_id  ";

  $sql = "
CREATE OR REPLACE VIEW gl_unposted_journal_lines_v
(
combination, code_combination_id, period_name,
coa_id, sum_total_cr, sum_total_dr,
sum_total_ac_dr, sum_total_ac_cr , ledger_id,
combination_description, gl_journal_line_id, status,
gl_journal_header_id, line_num, line_type, line_description,
reference_type, reference_key_name, reference_key_value , 
coa_structure_id, field1, field2, field3,
field4, field5, field6, field7, field8,
 balance_type, post_date,gl_period_id
)
AS
SELECT  cc.combination, gjl.code_combination_id, gp.period_name,
cc.coa_id, sum(gjl.total_cr), sum(gjl.total_dr),
sum(gjl.total_ac_dr), sum(gjl.total_ac_cr) ,gjh.ledger_id,
cc.description, gjl.gl_journal_line_id,
gjl.gl_journal_header_id, gjl.line_num, gjl.line_type, gjl.description,
gjl.reference_type, gjl.reference_key_name, gjl.reference_key_value , 
cc.coa_structure_id, cc.field1, cc.field2, cc.field3,
cc.field4, cc.field5, cc.field6, cc.field7, cc.field8,
gjh.balance_type, gjh.post_date, gp.gl_period_id

FROM gl_journal_line gjl 
LEFT JOIN gl_journal_header gjh ON gjl.gl_journal_header_id = gjh.gl_journal_header_id
LEFT JOIN gl_period gp ON gp.gl_period_id = gjh.period_id
LEFT JOIN coa_combination cc ON gjl.code_combination_id=cc.coa_combination_id
WHERE gjl.status = 'U'
GROUP BY  gjl.code_combination_id

";


  $sql = "
CREATE OR REPLACE VIEW gl_balance_v
(
period_name, gl_period_id, combination,description, 
gl_balance_id,ledger_id,coa_combination_id,
period_id, balance_type, period_net_dr,period_net_cr,
begin_balance_dr,begin_balance_cr, last_update_by, last_update_date,
field1, field2, field3,field4, field5, field6, field7, field8
)
AS
SELECT
gp.period_name, gp.gl_period_id, 
cc.combination,cc.description,
gb.gl_balance_id,gb.ledger_id,gb.coa_combination_id,
gb.period_id, gb.balance_type, gb.period_net_dr,gb.period_net_cr,
gb.begin_balance_dr,gb.begin_balance_cr, gb.last_update_by, gb.last_update_date,
cc.field1, cc.field2, cc.field3,
cc.field4, cc.field5, cc.field6, cc.field7, cc.field8

FROM gl_balance gb 
LEFT JOIN gl_period gp ON gp.gl_period_id = gb.period_id
LEFT JOIN coa_combination cc ON cc.coa_combination_id = gb.coa_combination_id
ORDER BY gp.gl_period_id DESC
";
 }

 public static function find_balance_between_accounts($account_l, $account_u, $gl_period_id = '') {

  $sql = " SELECT field1, field4, ledger_id, period_id, ( IFNULL(period_net_dr,0) - IFNULL(period_net_cr,0) "
   . " + IFNULL(begin_balance_dr,0) - IFNULL(begin_balance_cr,0) ) AS balance "
   . " FROM gl_balance_v ";
  $sql .= " WHERE field4 >= '{$account_l}' AND  field4 <= '{$account_u}' ";
  if (!empty($gl_period_id)) {
   $sql .= " AND gl_period_id = '{$gl_period_id}' ";
  }

  $sql .= " ORDER BY field4 ASC ";

  $result = self::find_by_sql($sql);

//  echo $sql . '<br><br>';
  return !empty($result) ? $result : false;
 }

 public static function find_balance_sum_between_accounts($account_l, $account_u, $gl_period_id = '') {

  $sql = " SELECT field1, field4, ledger_id, period_id, ( IFNULL(SUM(period_net_dr),0) - IFNULL(SUM(period_net_cr),0) "
   . " + IFNULL(SUM(begin_balance_dr),0) - IFNULL(SUM(begin_balance_cr),0) ) AS balance "
   . " FROM gl_balance_v ";
  $sql .= " WHERE field4 >= '{$account_l}' AND  field4 <= '{$account_u}' ";
  if (!empty($gl_period_id)) {
   $sql .= " AND gl_period_id = '{$gl_period_id}' ";
  }
  $sql .= " GROUP BY  ledger_id, field1, period_id ";
  $result = self::find_by_sql($sql);
//  
//  echo $sql .'<br><br>'; pa($result );
  return !empty($result) ? array_pop($result) : false;
 }

 public function balance_sheet($params) {
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
  $custom_template_name = HOME_DIR . DS . 'themes' . DS . $_SESSION['default_theme'] . '/template/gl_balance_v_balance_sheet_template.php';
  ob_start();
  if (file_exists($custom_template_name)) {
   include_once $custom_template_name;
  } else {
   include_once __DIR__ . '/templates/balance_sheet_template.php';
  }
  $report_date = ob_get_contents();
  ob_end_clean();
  return $report_date;
 }

 public function balance_sheet_detailed($params) {
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

  $custom_template_name = HOME_DIR . DS . 'themes' . DS . $_SESSION['default_theme'] . '/template/gl_balance_v_balance_sheet_detail_template.php';
  ob_start();
  if (file_exists($custom_template_name)) {
   include_once $custom_template_name;
  } else {
   include_once __DIR__ . '/templates/balance_sheet_detail_template.php';
  }
  $report_date = ob_get_contents();
  ob_end_clean();

  return $report_date;
 }

 public function income_statement($params) {
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

  $custom_template_name = HOME_DIR . DS . 'themes' . DS . $_SESSION['default_theme'] . '/template/gl_balance_v_income_statement_template.php';
  ob_start();
  if (file_exists($custom_template_name)) {
   include_once $custom_template_name;
  } else {
   include_once __DIR__ . '/templates/income_statement_template.php';
  }
  $report_date = ob_get_contents();
  ob_end_clean();

  return $report_date;
 }

 public function income_statement_detailed($params) {
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

  $custom_template_name = HOME_DIR . DS . 'themes' . DS . $_SESSION['default_theme'] . '/template/gl_balance_v_income_statement_detail_template.php';
  ob_start();
  if (file_exists($custom_template_name)) {
   include_once $custom_template_name;
  } else {
   include_once __DIR__ . '/templates/income_statement_detail_template.php';
  }
  $report_date = ob_get_contents();
  ob_end_clean();

  return $report_date;
 }

 public function financeStatement_showBalance() {
  $count = $val_sum = 0;
  $ret_ar = [];
  $row_stmt = '';
  $all_parent_segments_ai = $this->parent_segments_arrayIterator;
  $arraySize = sizeof($this->parent_segments_arrayIterator);
  while ($all_parent_segments_ai->valid()) {
   $curr_bal = 0;
   $curr_parent_line = $all_parent_segments_ai->current();
   $key_current = $all_parent_segments_ai->key();
   $key_last = $key_current - 1;

   if ($key_current == ($arraySize - 1)) {
    $account_h = $this->account_code_upper_limit;
   } else {
    $account_h = $curr_parent_line->code;
   }
   if ($key_last >= 0) {
    $all_parent_segments_ai->seek($key_last);
    $parent_last_line = $all_parent_segments_ai->current();
    $account_l = $parent_last_line->code + 1;
    $all_parent_segments_ai->next();
    $all_parent_segments_ai->next();
   } else if (!empty($this->account_code_low_limit)) {
    $account_l = $this->account_code_low_limit;
    $all_parent_segments_ai->next();
   } else {
    continue;
   }

   if ($this->fs_detail_data == 1) {
    $gl_balances = gl_balance_v::find_balance_between_accounts($account_l, $account_h, $this->period_id_for_fs);
    if ($gl_balances) {
     foreach ($gl_balances as $bal_r) {
      $row_stmt .=' <tr class="asset_detail_line label_four' . $count . '">';
      $row_stmt .= ' <td>' . $bal_r->field4 . '</td>';
      $row_stmt .= ' <td>' . $bal_r->balance . '</td>';
      $row_stmt .= '<td></td>';
      $row_stmt .= '</tr>';
      $val_sum += $bal_r->balance;
      $curr_bal += $bal_r->balance;
     }
    } else {
     $curr_bal = null;
    }
    $row_stmt .=' <tr class="asset_parent_line' . $count . '">';
    $row_stmt .= ' <td>' . $curr_parent_line->description . '</td>';
    $row_stmt .= ' <td>' . $curr_bal . '</td>';
    $row_stmt .= '<td></td>';
    $row_stmt .= '</tr>';
   } else {
    $gl_balances = gl_balance_v::find_balance_sum_between_accounts($account_l, $account_h, $this->period_id_for_fs);

    if ($gl_balances) {
     $val_sum += $gl_balances->balance;
     $curr_bal = $gl_balances->balance;
    } else {
     $curr_bal = null;
    }
    $row_stmt .=' <tr class="asset_parent_line' . $count . '">';
    $row_stmt .= ' <td>' . $curr_parent_line->description . '</td>';
    $row_stmt .= ' <td>' . $curr_bal . '</td>';
    $row_stmt .= '<td></td>';
//  $row_stmt .= '<td>'.$curr_parent_line->code. ' & account_low '. $account_l. ' & account_high'. $account_code_upper_limit . '</td>';
    $row_stmt .= '</tr>';
   }



   if ($curr_parent_line->code > $this->account_code_upper_limit) {
    break;
   }
   $count = $count + 1;
  }
  $ret_ar['sum'] = $val_sum;
  $ret_ar['statement'] = $row_stmt;
  return $ret_ar;
 }

 public function financeStatement_calculateBalance() {
  $count = $val_sum = 0;
  $ret_ar = [];
  $all_parent_segments_ai = $this->parent_segments_arrayIterator;
  $arraySize = sizeof($this->parent_segments_arrayIterator);
  while ($all_parent_segments_ai->valid()) {
   $curr_data_array = [];
   $curr_bal = 0;
   $curr_parent_line = $all_parent_segments_ai->current();
   $key_current = $all_parent_segments_ai->key();
   $key_last = $key_current - 1;

   if ($key_current == ($arraySize - 1)) {
    $account_h = $this->account_code_upper_limit;
   } else {
    $account_h = $curr_parent_line->code;
   }
   if ($key_last >= 0) {
    $all_parent_segments_ai->seek($key_last);
    $parent_last_line = $all_parent_segments_ai->current();
    $account_l = $parent_last_line->code + 1;
    $all_parent_segments_ai->next();
    $all_parent_segments_ai->next();
   } else if (!empty($this->account_code_low_limit)) {
    $account_l = $this->account_code_low_limit;
    $all_parent_segments_ai->next();
   } else {
    continue;
   }

   if ($this->fs_detail_data == 1) {
    $gl_balances = gl_balance_v::find_balance_between_accounts($account_l, $account_h, $this->period_id_for_fs);
    if ($gl_balances) {
     foreach ($gl_balances as $bal_r) {
      $curr_data_array['element_type'] = 'account';
      $curr_data_array['element'] = $bal_r->field4;
      $curr_data_array['amount'] = $bal_r->balance;
      $val_sum += $bal_r->balance;
      $curr_bal += $bal_r->balance;
      array_push($ret_ar, $curr_data_array);
     }
    } else {
     $curr_bal = null;
    }

    $curr_data_array['element_type'] = 'description';
    $curr_data_array['element'] = $curr_parent_line->description;
    $curr_data_array['amount'] = $curr_bal;

    array_push($ret_ar, $curr_data_array);
   } else {
    $gl_balances = gl_balance_v::find_balance_sum_between_accounts($account_l, $account_h, $this->period_id_for_fs);

    if ($gl_balances) {
     $curr_data_array['element_type'] = 'account';
     $curr_data_array['element'] = $gl_balances->field4;
     $curr_data_array['amount'] = $gl_balances->balance;
     $val_sum += $gl_balances->balance;
     $curr_bal = $gl_balances->balance;
     array_push($ret_ar, $curr_data_array);
    } else {
     $curr_bal = null;
    }
    $curr_data_array['element_type'] = 'description';
    $curr_data_array['element'] = $curr_parent_line->description;
    $curr_data_array['amount'] = $curr_bal;
    array_push($ret_ar, $curr_data_array);
   }



   if ($curr_parent_line->code > $this->account_code_upper_limit) {
    break;
   }
   $count = $count + 1;
  }
  $curr_data_array['element'] = 'Sum Total';
  $curr_data_array['element_type'] = 'total_sum';
  $curr_data_array['amount'] = $val_sum;
  array_push($ret_ar, $curr_data_array);
  return $ret_ar;
 }

 public function prg_balance_sheet($params) {
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
  $coa->account_qualifier = 'A';
  $total_asset = 0;

  $gbv = new gl_balance_v();
  $gbv->period_id_for_fs = $period_id;
  $gbv->account_code_low_limit = $coa->field4_low = '1';
  $gbv->account_code_upper_limit = $coa->field4_high = '104499';
  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  if (!empty($all_asset_parent_segments)) {
   $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
  }
  $gbv->parent_segments_arrayIterator = $all_asset_parent_segments_ai;
  $show_details = false;
  if (!empty($params['show_details'][0]) && ($params['show_details'][0] == 1)) {
   $gbv->fs_detail_data = 1;
   $show_details = true;
  }

  /* Cash Equivalent */
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
   $cash_n_receviables['element_type'] = 'description';
   $cash_n_receviables['element'] = 'Total Cash & Receivables';
   $cash_n_receviables['amount'] = $ret_a[$sum_key]['amount'];
   $total_asset += $cash_n_receviables['amount'];
   array_push($result_a, $cash_n_receviables);
  }

  /* Gross Inventory */
  $gbv->account_code_low_limit = $coa->field4_low = '104500';
  $gbv->account_code_upper_limit = $coa->field4_high = '105499';
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
   $gross_inv = [];
   $gross_inv['element_type'] = 'description';
   $gross_inv['element'] = 'Gross Inventory';
   $gross_inv['amount'] = $ret_a[$sum_key]['amount'];
   array_push($result_a, $gross_inv);
   $gross_inv_sum = $gross_inv['amount'];
   $total_asset += $gross_inv_sum;
  } else {
   $gross_inv_sum = 0;
  }


  /* Inventory Reservse */
  $inv_res = 0;
  $gbv->account_code_low_limit = $coa->field4_low = '105500';
  $gbv->account_code_upper_limit = $coa->field4_high = '105599';
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


  /* Net Inventory */
  if (!empty($sum_key)) {
   $net_inv = [];
   $net_inv['element_type'] = 'description';
   $net_inv['element'] = 'Net Inventory';
   $inv_res = $ret_a[$sum_key]['amount'];
   $total_asset += $inv_res;
   $net_inv['amount'] = $gross_inv_sum + $inv_res;
   array_push($result_a, $net_inv);
  }


  /* Total Current Asset */
  $other_current_asset = 0;
  $gbv->account_code_low_limit = $coa->field4_low = '106000';
  $gbv->account_code_upper_limit = $coa->field4_high = '109999';
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


  $this_data_a = [];
  $this_data_a['element_type'] = 'description';
  $this_data_a['element'] = 'Total Current Asset';
  $total_asset += $other_current_asset;
  $this_data_a['amount'] = $total_asset;
  array_push($result_a, $this_data_a);


  /* Total Non Current Asset */
  $total_nc_asset = 0;
  $gbv->account_code_low_limit = $coa->field4_low = '108000';
  $gbv->account_code_upper_limit = $coa->field4_high = '199999';
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


  $this_data_a['element_type'] = 'description';
  $this_data_a['element'] = 'Total Non Current Asset';
  $total_nc_asset = $ret_a[$sum_key]['amount'];
  $this_data_a['amount'] = $total_nc_asset;
  $total_asset += $total_nc_asset;
  array_push($result_a, $this_data_a);

  $this_data_a['element_type'] = 'description';
  $this_data_a['element'] = 'Total Asset';
  $this_data_a['amount'] = $total_asset;
  array_push($result_a, $this_data_a);


  /* Liability */
  $coa->account_qualifier = 'L';
  $total_liability = 0;

  $gbv->account_code_low_limit = $coa->field4_low = '200000';
  $gbv->account_code_upper_limit = $coa->field4_high = '249999';
  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  if (!empty($all_asset_parent_segments)) {
   $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
  }
  $gbv->parent_segments_arrayIterator = $all_asset_parent_segments_ai;
//  $gbv->fs_detail_data = 1;


  /* Current Liability */
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
   $this_data_a['element'] = 'Total Current Liabilities';
   $this_data_a['amount'] = $ret_a[$sum_key]['amount'];
   $total_liability += $this_data_a['amount'];
   array_push($result_a, $this_data_a);
  }

  /* Long Term Liability */
  $gbv->account_code_low_limit = $coa->field4_low = '250000';
  $gbv->account_code_upper_limit = $coa->field4_high = '299999';
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
   $long_term_l = [];
   $long_term_l['element_type'] = 'description';
   $long_term_l['element'] = 'Total Long-Term Liabilities';
   $long_term_l['amount'] = $ret_a[$sum_key]['amount'];
   array_push($result_a, $long_term_l);
   $total_liability += $long_term_l['amount'];
  }


  /* Total Liability */
  $this_data_a['element_type'] = 'description';
  $this_data_a['element'] = 'Total  Liabilities';
  $this_data_a['amount'] = $total_liability;
  array_push($result_a, $this_data_a);


  /* Equity */
  $coa->account_qualifier = 'E';
  $total_equity = 0;

  $gbv->account_code_low_limit = $coa->field4_low = '300000';
  $gbv->account_code_upper_limit = $coa->field4_high = '399999';
  $all_asset_parent_segments = $coa->findAll_accounts_from_coaId();
  if (!empty($all_asset_parent_segments)) {
   $all_asset_parent_segments_ai = new ArrayIterator($all_asset_parent_segments);
  }
  $gbv->parent_segments_arrayIterator = $all_asset_parent_segments_ai;
//  $gbv->fs_detail_data = 1;


  /* Total Equity */
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
   $total_equity += $ret_a[$sum_key]['amount'];
  }

//  $ret_expected = 0;

  $ret_expected = (- $total_asset ) - $total_liability - $total_equity;
  if (!empty(($ret_expected))) {
   $this_data_a['element_type'] = 'description';
   $this_data_a['element'] = 'Retained Earnings - Expected';
   $this_data_a['amount'] = $ret_expected;
   array_push($result_a, $this_data_a);
  }

  $this_data_a['element_type'] = 'description';
  $this_data_a['element'] = 'Total Shareholders Equity';
  $this_data_a['amount'] = $total_equity + $ret_expected;
  array_push($result_a, $this_data_a);


  $this_data_a['element_type'] = 'description';
  $this_data_a['element'] = 'TOTAL LIABILITIES & EQUITY';
  $this_data_a['amount'] = $total_liability + $ret_expected + $total_equity;
  array_push($result_a, $this_data_a);

  return $result_a;
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