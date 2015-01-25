<?php

class gl_balance_v extends dbObject {

 public static $table_name = "gl_balance_v";
 public static $primary_column = "gl_journal_header_id";
 public $field_a = [
 ];
 public $initial_search = [
  'period_name',
  "period_id",
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

 function __construct() {
  if (!empty(static::$table_name)) {
   $this->field_a = get_dbColumns(static::$table_name);
   foreach ($this->field_a as $key => $value) {
    $this->$value = '';
   }
  }
 }

 public function create_gl_balance_v() {
  $SQL = "SELECT  cc.combination, gjl.code_combination_id,
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
group by gjl.code_combination_id";

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
 
  public static function find_balance_between_accounts($account_l, $account_u){
  
  $sql = " SELECT field1, field4, ledger_id, period_id, ( IFNULL(period_net_dr,0) - IFNULL(period_net_cr,0) "
   . " + IFNULL(begin_balance_dr,0) - IFNULL(begin_balance_cr,0) ) AS balance "
   . " FROM gl_balance_v " ;
  $sql .= " WHERE field4 > '{$account_l}' AND  field4 <= '{$account_u}' " ;
   $result = self::find_by_sql($sql);
//  
//  echo $sql .'<br><br>';
  return !empty($result) ? $result : false;
 }
 
  public static function find_balance_sum_between_accounts($account_l, $account_u){
  
  $sql = " SELECT field1, ledger_id, period_id, ( IFNULL(SUM(period_net_dr),0) - IFNULL(SUM(period_net_cr),0) "
   . " + IFNULL(SUM(begin_balance_dr),0) - IFNULL(SUM(begin_balance_cr),0) ) AS balance "
   . " FROM gl_balance_v " ;
  $sql .= " WHERE field4 > '{$account_l}' AND  field4 <= '{$account_u}' " ;
  $sql .= " GROUP BY  ledger_id, field1, period_id " ;
  $result = self::find_by_sql($sql);
//  
//  echo $sql .'<br><br>';
  return !empty($result) ? array_pop($result) : false;
 }

 public function calculate_balanceSheet() {
  /* 1. Find all asset parent segments of the coa. If no coa_id provided use coa_id = 1 */


  $total_cash = '104000';
  $total_cash_heading = 'Total Cash & Receivables';

  $deferred_incomeTax_account = '104500';
  $deferred_incomeTax_heading = 'Deferred Income Taxes';

  $gross_inventory_account = '105300';
  $gross_inventory_heading = 'Gross Inventory';

  $inventory_reserve_account = '105500';
  $inventory_reserve_heading = 'Inventory Reserve';

  $net_inventory_heading = 'Net Inventory';

  $prepaid_expense_account = '106000';
  $prepaid_expense_heading = 'Prepaids Expenses';

  $total_current_asset_heading = 'Total Current Assets';
  $total_nonCurrent_asset_heading = 'Total Non-Current Assets';
  $total_asset_heading = 'TOTAL ASSETS';
  
  $total_current_liability_account = '250000';
  $total_current_liability_heading = 'Total Current Liabilities';
  
  $total_longterm_liability_heading = 'Total Long-Term Liabilities';
  
  $total_liability_equity_heading = 'TOTAL LIABILITIES & EQUITY';
  
  
 }

 public function balance_sheet($params) {
  $org_name = 'inoERP';
  $last_period = '2015';
  $current_period = '2014';
  ob_start();
  include_once __DIR__ . '/templates/balance_sheet_template.php';
  $report_date = ob_get_contents();
  ob_end_clean();
  return $report_date;
 }

 
  public function balance_sheet_detailed($params) {
  $org_name = 'inoERP';
  $last_period = '2015';
  $current_period = '2014';
  ob_start();
  include_once __DIR__ . '/templates/balance_sheet_detail_template.php';
  $report_date = ob_get_contents();
  ob_end_clean();
  return $report_date;
 }
 
}

//end of po_detail class
?>