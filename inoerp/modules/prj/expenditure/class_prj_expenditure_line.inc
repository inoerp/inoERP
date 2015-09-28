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
 * prj_expenditure_line
 *
 */
class prj_expenditure_line extends dbObject {

 public static $table_name = "prj_expenditure_line";
 public static $primary_column = "prj_expenditure_line_id";
 public static $parent_primary_column = "prj_expenditure_header_id";
 public static $key_column = "prj_expenditure_type_header_id";
 public static $module = "prj";
 public static $status_a = [
  'ENTERED' => 'Entered',
  'DISTRIBUTED' => 'Distributed',
 ];
 public $field_a = [
  'prj_expenditure_line_id',
  'prj_expenditure_header_id',
  'org_id',
  'hr_employee_id',
  'description',
  'job_id',
  'expenditure_date',
  'prj_project_header_id',
  'prj_project_line_id',
  'prj_nlr_header_id',
  'prj_expenditure_type_header_id',
  'uom_id',
  'quantity',
  'rate',
  'debit_ac_id',
  'credit_ac_id',
  'burden_amount',
  'gl_journal_header_id',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'description',
  'gl_journal_header_id',
  'status'
 ];
 public $requiredField = [
  'prj_expenditure_header_id',
  'prj_expenditure_type_header_id',
  'quantity',
 ];
 public $fields_inForm_notInDataBase = [
  "employee_name",
  'project_number',
  "task_number",
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Expenditure Lines"; //page Title
 public $prj_expenditure_line_id;
 public $prj_expenditure_header_id;
 public $org_id;
 public $hr_employee_id;
 public $description;
 public $job_id;
 public $expenditure_date;
 public $status;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $prj_nlr_header_id;
 public $prj_expenditure_type_header_id;
 public $uom_id;
 public $quantity;
 public $rate;
 public $debit_ac_id;
 public $credit_ac_id;
 public $gl_journal_header_id;
 public $burden_amount;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $project_number;
 public $employee_name;
 public $task_number;
 public $status_f;
 public $action;

 public function _before_save() {
  if (empty($this->prj_project_line_id)) {
   $this->status = 'ENTERED';
  }
  if (empty($this->action == 'create_accounting')) {
   pa($this);
   $this->_create_accounting();
   return 10;
  }
 }

// private function _save_journal_header($hr_payroll_id) {
//  global $dbc;
//  $hr_pr = hr_payroll::find_by_id($hr_payroll_id);
//  $hr_pm = new hr_payroll_payment_method();
//  $hr_pm->findBy_id($hr_pr->payment_method_id);
//  $gjh = new gl_journal_header;
//  $gjh->ledger_id = $hr_pm->ledger_id;
//  $gjh->status = 'ENTERED';
//  $gjh->currency = $hr_pm->currency;
//  $gp = new gl_period();
//  $gjh->period_id = $gp->current_open_period($hr_pm->ledger_id, 'OPEN')->gl_period_id;
//  $gjh->journal_source = self::$module;
//  $gjh->journal_category = 'HR_PAYROLL';
//  $gjh->reference_type = 'table';
//  $gjh->reference_key_name = self::$table_name;
//  $gjh->reference_key_value = $this->hr_payroll_process_id;
//  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
//  $gjh->description = $gjh->journal_name . '-' . current_time();
//  $gjh->balance_type = 'A';
//  try {
//   $gjh->save();
//   $this->gl_journal_header_id = $gjh->gl_journal_header_id;
//   echo "<br> Jounral Header Id #" . $this->gl_journal_header_id . ' is created';
//   $this->_save_journal_lines($hr_pm);
//  } catch (Exception $e) {
//   echo "<br> Failed Saving Journal Header" . $e->getMessage();
//   $dbc->rollback = true;
//  }
// }
//
// private function _save_journal_lines($hr_pm) {
//  global $dbc;
//  $total_dr_amount = 0;
//  $all_ps_header = hr_payslip_header::find_by_payrollProcessId($this->hr_payroll_process_id);
//  $this->_max_line_num = 1;
//  foreach ($all_ps_header as $ps_header) {
//   $new_gjl = new gl_journal_line();
//   $new_gjl->gl_journal_header_id = $this->gl_journal_header_id;
//   $new_gjl->reference_key_name = 'hr_payslip_header';
//   $new_gjl->reference_key_value = $ps_header->hr_payslip_header_id;
//   //check if line lready exists
//   $jl_exists = $new_gjl->findBy_reference_keyName_keyValue();
//   if ($jl_exists) {
//    echo "<br> Failed Saving Journal Line. Payslip header reference exists in GL. Error @ payroll_process @@ line " . __LINE__;
//    $dbc->rollback = true;
//   } else {
//    $new_gjl->gl_journal_line_id = null;
//    $new_gjl->line_num = $this->_max_line_num;
//    $new_gjl->status = 'U';
//    $this->_max_line_num++;
//   }
//   $new_gjl->code_combination_id = hr_employee::find_by_id($ps_header->employee_id)->salary_ac_id;
//   $payslip_header_amt = hr_payslip_header::find_headerAmount_by_headerId($ps_header->hr_payslip_header_id);
//   $new_gjl->total_dr = $payslip_header_amt;
//   $new_gjl->total_ac_dr = $payslip_header_amt;
//   $total_dr_amount += $payslip_header_amt;
//
//   $new_gjl->description = 'HR Payroll Header Id #' . $ps_header->hr_payslip_header_id;
//   $new_gjl->reference_type = 'table';
//   $new_gjl->save();
//  }
//
////	save the Accrual Account
//  $payroll_accrual = new gl_journal_line();
//  $payroll_accrual->gl_journal_header_id = $this->gl_journal_header_id;
//  $payroll_accrual->reference_key_name = 'hr_payroll_process';
//  $payroll_accrual->reference_key_value = $this->hr_payroll_process_id;
//  //check if line lready exists
//  $jl_exists_liability = $payroll_accrual->findBy_reference_keyName_keyValue();
//  if ($jl_exists_liability) {
//   echo "<br> Failed Saving Journal Line. Payslip header reference exists in GL. Error @ payroll_process @@ line " . __LINE__;
//   $dbc->rollback = true;
//  } else {
//   $payroll_accrual->gl_journal_line_id = null;
//   $payroll_accrual->line_num = $this->_max_line_num;
//   $this->_max_line_num++;
//  }
//  $payroll_accrual->status = 'U';
//  $payroll_accrual->code_combination_id = $hr_pm->salary_payable_ac_id;
//  $payroll_accrual->total_cr = $total_dr_amount;
//  $payroll_accrual->total_ac_cr = $total_dr_amount;
//
//  $new_gjl->description = 'HR Payroll Header Id #' . $ps_header->hr_payslip_header_id;
//  $payroll_accrual->reference_type = 'table';
//  $payroll_accrual->save();
// }

 public static function find_burdenDetails_fromExpenditureLine($prj_expenditure_line_id) {
  $sql = " SELECT pel.prj_expenditure_line_id,   pel.prj_expenditure_header_id,   pel.org_id,
pel.prj_project_header_id,   pel.prj_project_line_id,   pel.prj_nlr_header_id,
pel.prj_expenditure_type_header_id,   pel.uom_id,   pel.quantity ,
pbse.prj_burden_structure_header_id, pbse.burden_cost_base_id, pbsc.burden_cost_code_id, pbll.bu_org_id, pbll.multiplier, 
pbll.burden_value, pbll.prj_burden_list_header_id

FROM prj_expenditure_line pel,
prj_burden_structure_expendituretype pbse,
prj_burden_structure_costcode pbsc,
prj_burden_list_line pbll,
prj_project_header pph,
prj_burden_list_header bplh

WHERE pbse.prj_expenditure_type_id = pel.prj_expenditure_type_header_id
AND pbse.prj_burden_structure_header_id =  pbsc.prj_burden_structure_header_id
AND pbse.burden_cost_base_id = pbsc.burden_cost_base_id
AND pbll.prj_burden_costcode_id = pbsc.burden_cost_code_id
AND pph.prj_project_header_id = pel.prj_project_header_id
AND pph.bu_org_id = pbll.bu_org_id
AND pph.prj_burden_list_header_id = pbll.prj_burden_list_header_id
AND bplh.prj_burden_list_header_id = pbll.prj_burden_list_header_id
AND bplh.prj_burden_structure_header_id =  pbsc.prj_burden_structure_header_id
AND pel.prj_expenditure_line_id = '{$prj_expenditure_line_id}' ";

//echo "<br>$sql";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_accountDetails_fromExpenditureLine($prj_expenditure_line_id) {
  $sql = " 
        SELECT pel.prj_expenditure_line_id,   pel.prj_expenditure_header_id,   pel.org_id,
        pel.prj_project_header_id,   pel.prj_project_line_id,   pel.prj_nlr_header_id,
        pel.prj_expenditure_type_header_id,   pel.uom_id,   pel.quantity ,
        peh.expenditure_class, pph.accounting_group, pph.prj_project_type_id,
        pda.document_type, pda.ac_id

        FROM prj_expenditure_line pel,
        prj_expenditure_header peh,
        prj_project_header pph,
        prj_default_account pda

        WHERE pel.prj_expenditure_header_id = peh.prj_expenditure_header_id
        AND pph.prj_project_header_id = pel.prj_project_header_id
        AND pda.accounting_group = pph.accounting_group 
        AND pda.prj_project_type_header_id = pph.prj_project_type_id 
        AND (pda.document_type = 'DEFAULT_EXPEN_CLEAR' || pda.document_type = 'DEFAULT_EXPEN' )
        AND pel.prj_expenditure_line_id = '{$prj_expenditure_line_id}'

        UNION
        SELECT pel.prj_expenditure_line_id,   pel.prj_expenditure_header_id,   pel.org_id,
        pel.prj_project_header_id,   pel.prj_project_line_id,   pel.prj_nlr_header_id,
        pel.prj_expenditure_type_header_id,   pel.uom_id,   pel.quantity ,
        peh.expenditure_class, pph.accounting_group, pph.prj_project_type_id,
        pda.document_type, pda.ac_id

        FROM prj_expenditure_line pel,
        prj_expenditure_header peh,
        prj_project_header pph,
        prj_default_account pda,
        option_line ol

        WHERE pel.prj_expenditure_header_id = peh.prj_expenditure_header_id
        AND pph.prj_project_header_id = pel.prj_project_header_id
        AND pda.accounting_group = pph.accounting_group 
        AND pda.prj_project_type_header_id = pph.prj_project_type_id 
        AND pda.accounting_group = pph.accounting_group 
        AND pda.prj_project_type_header_id = pph.prj_project_type_id 
        AND pda.document_type = ol.option_line_code
        AND ol.mapper1 = peh.expenditure_class
        AND pel.prj_expenditure_line_id = '{$prj_expenditure_line_id}'
";

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_headerId_Status($project_header_id, $status = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE  prj_project_header_id = '{$project_header_id}' ";
  if (!empty($status)) {
   $sql .= " AND  status = '{$status}' ";
  } else {
   $sql .= " AND ( status IS NULL || status = 'ENTERED' ) ";
  }

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of path class
?>
