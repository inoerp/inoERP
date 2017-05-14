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
 * hr_payroll_process
 * Processes payroll schedules
 * * Contains all the hr_payroll information, such as - Payroll, period_type , start_date, end_date, etc
 * 
 */
class hr_payroll_process extends dbObject {

 public static $table_name = "hr_payroll_process";
 public static $primary_column = "hr_payroll_process_id";
 public static $key_column = "hr_payroll_schedule_id";
 public static $dependent_classes = ['hr_payslip_header'];
 public static $module = "hr";
 public static $js_fileName_prg = 'modules/hr/payroll/js/program_payroll.js ';
 public static $system_info = [
  'name' => 'HR Payroll Process',
  'number' => '3303',
  'description' => 'HR Payroll Process',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hr_payroll_process'),
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 16
 ];
 public static $status_a = [
  'OPEN' => 'Open',
  'PAID' => 'Paid',
  'CANCELLED' => 'Cancelled',
 ];
 public $field_a = [
  'hr_payroll_process_id',
  'hr_payroll_id',
  'hr_payroll_schedule_id',
  'proces_name',
  'status',
  'gl_journal_header_id',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'proces_name',
 ];
 public $requiredField = [
  'hr_payroll_id',
  'hr_payroll_schedule_id',
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $prg_confirm_payroll_process_parameters = [
  'Payroll Process Name/Id' => 'search_payroll_process',
 ];
 public $prg_confirm_payroll_process_details = [
  'name' => 'Confirm Payroll Process',
  'description' => 'Confirm Processed Payroll',
 ];
 public $prg_cancel_payroll_process_parameters = [
  'Payroll Process Name/Id' => 'search_payroll_process',
 ];
 public $prg_cancel_payroll_process_details = [
  'name' => 'Cancel Payroll Process',
  'description' => 'Cancel Processed Payroll',
 ];
 public $pageTitle = " HR Process Payroll "; //page Title
 public $hr_payroll_process_id;
 public $gl_journal_header_id;
 public $hr_payroll_id;
 public $hr_payroll_schedule_id;
 public $proces_name;
 public $status;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $message;
 private $_max_line_num;

 public static function find_payroll_available_for_cancelAndConfirmation() {
  $sql = " SELECT * from hr_payroll_process ";
  $sql .= " WHERE status IS NULL OR status =  'OPEN' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public function prg_cancel_payroll_process($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message .= '<br> Cancelling Processed payroll...';

  if (!empty($parameters['hr_payroll_process_id'][0])) {
   $this->hr_payroll_process_id = $parameters['hr_payroll_process_id'][0];
   $this->message .= '<br> Entered hr_payroll_process_id is : ' . $this->hr_payroll_process_id;
  } else {
   $this->message .= '<br> No hr_payroll_process_id found. Exiting Program @ payroll_process @@ Line' . __LINE__;
   return $this->message;
  }


  if (!empty($this->hr_payroll_process_id)) {
   $this->message .= "<br> Creating Payroll schedule by  hr_payroll_process_id  " . $this->hr_payroll_process_id;
   try {
    $this->_cancel_payroll_process();
    $this->message .= "<br>Payroll schdule cancel program is Successfullycompleted.";
   } catch (Exception $e) {
    $this->message .= "<br>_cancel_payroll_process schdule program failed!. Error @ payroll_process @@ Line " . __LINE__ . $e->getMessage();
   }
  }
  return $this->message;
 }

 private function _cancel_payroll_process() {
  /*
   * Check the status of hr_payroll_process_id. If PAID then return.
   * Find all payslip_header containing the hr_payroll_process_id
   * Delete all the payslip lines for each of the payslip_header
   * Delete all the payslip headers
   * Delete the payroll_process_id
   */
  $hr_pp = new hr_payroll_process();
  $hr_pp->findBy_id($this->hr_payroll_process_id);

  if ($hr_pp->status == 'PAID' || $hr_pp->status == 'CANCELLED') {
   $this->message .= "<br> Payroll process is in PAID/CANCELLED status and can not be cancelled " . $this->hr_payroll_process_id;
   return;
  }

  $all_ps_header = hr_payslip_header::find_by_payrollProcessId($this->hr_payroll_process_id);
  foreach ($all_ps_header as $ps_header) {
   $psl = new hr_payslip_line();
   $psl->deleteBy_parentId($ps_header->hr_payslip_header_id);
   $psh = new hr_payslip_header();
   $psh->hr_payslip_header_id = $ps_header->hr_payslip_header_id;
   $psh->delete();
  }
  $hr_pp->status = 'CANCELLED';
  $hr_pp->save();
 }

 public function prg_confirm_payroll_process($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message .= '<br> Confirming Processed payroll...';

  if (!empty($parameters['hr_payroll_process_id'][0])) {
   $this->hr_payroll_process_id = $parameters['hr_payroll_process_id'][0];
   $this->message .= '<br> Entered hr_payroll_process_id is : ' . $this->hr_payroll_process_id;
  } else {
   $this->message .= '<br> No hr_payroll_process_id found. Exiting Program @ payroll_process @@ Line' . __LINE__;
   return $this->message;
  }


  if (!empty($this->hr_payroll_process_id)) {
   $this->message .= "<br> Confirming payroll proces with hr_payroll_process_id  " . $this->hr_payroll_process_id;
   try {
    $this->_confirm_payroll_process();
    $this->message .= "<br>Payroll schdule confirm program is Successfullycompleted.";
   } catch (Exception $e) {
    $this->message .= "<br>_confirm_payroll_process program failed!. Error @ payroll_process @@ Line " . __LINE__ . $e->getMessage();
   }
  }
  return $this->message;
 }

 private function _confirm_payroll_process() {
  global $dbc;
  /*
   * Check the status of hr_payroll_process_id. If PAID/CANCELLED then return.
   * Find all payslip_header containing the hr_payroll_process_id
   * Delete all the payslip lines for each of the payslip_header
   * Delete all the payslip headers
   * Delete the payroll_process_id
   */
  $hr_pp = new hr_payroll_process();
  $hr_pp->findBy_id($this->hr_payroll_process_id);

  if ($hr_pp->status == 'PAID' || $hr_pp->status == 'CANCELLED') {
   $this->message .= "<br> Payroll process is in PAID/CANCELLED status and can not be confirmed " . $this->hr_payroll_process_id;
   return;
  }

  $all_ps_header = hr_payslip_header::find_by_payrollProcessId($this->hr_payroll_process_id);
  foreach ($all_ps_header as $ps_header) {
   $psh = new hr_payslip_header();
   $psh->hr_payslip_header_id = $ps_header->hr_payslip_header_id;
   $psh->status = 'PAID';
   $psh->save();
  }
  //create accounting
  try {
   $this->_save_journal_header($hr_pp->hr_payroll_id);
  } catch (Exception $e) {
   echo "Create accounting failed" . $e->getMessage();
   $dbc->rollback = true;
  }

  $hr_pp->status = 'PAID';
  $hr_pp->gl_journal_header_id = $this->gl_journal_header_id;
  $hr_pp->save();

  $hr_ps = new hr_payroll_schedule();
  $hr_ps->findBy_id($hr_pp->hr_payroll_schedule_id);
  $hr_ps->status = 'PAID';
  $hr_ps->save();
 }

 private function _save_journal_header($hr_payroll_id) {
  global $dbc;
  $hr_pr = hr_payroll::find_by_id($hr_payroll_id);
  $hr_pm = new hr_payroll_payment_method();
  $hr_pm->findBy_id($hr_pr->payment_method_id);
  $gjh = new gl_journal_header;
  $gjh->ledger_id = $hr_pm->ledger_id;
  $gjh->status = 'ENTERED';
  $gjh->currency = $hr_pm->currency;
  $gp = new gl_period();
  $gjh->period_id = $gp->current_open_period($hr_pm->ledger_id, 'OPEN')->gl_period_id;
  $gjh->journal_source = self::$module;
  $gjh->journal_category = 'HR_PAYROLL';
  $gjh->reference_type = 'table';
  $gjh->reference_key_name = self::$table_name;
  $gjh->reference_key_value = $this->hr_payroll_process_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = 'A';
  try {
   $gjh->save();
   $this->gl_journal_header_id = $gjh->gl_journal_header_id;
   echo "<br> Jounral Header Id #" . $this->gl_journal_header_id . ' is created';
   $this->_save_journal_lines($hr_pm);
  } catch (Exception $e) {
   echo "<br> Failed Saving Journal Header" . $e->getMessage();
   $dbc->rollback = true;
  }
 }

 private function _save_journal_lines($hr_pm) {
  global $dbc;
  $total_dr_amount = 0;
  $all_ps_header = hr_payslip_header::find_by_payrollProcessId($this->hr_payroll_process_id);
  $this->_max_line_num = 1;
  foreach ($all_ps_header as $ps_header) {
   $new_gjl = new gl_journal_line();
   $new_gjl->gl_journal_header_id = $this->gl_journal_header_id;
   $new_gjl->reference_key_name = 'hr_payslip_header';
   $new_gjl->reference_key_value = $ps_header->hr_payslip_header_id;
   //check if line lready exists
   $jl_exists = $new_gjl->findBy_reference_keyName_keyValue();
   if ($jl_exists) {
    echo "<br> Failed Saving Journal Line. Payslip header reference exists in GL. Error @ payroll_process @@ line " . __LINE__;
    $dbc->rollback = true;
   } else {
    $new_gjl->gl_journal_line_id = null;
    $new_gjl->line_num = $this->_max_line_num;
    $new_gjl->status = 'U';
    $this->_max_line_num++;
   }
   $new_gjl->code_combination_id = hr_employee::find_by_id($ps_header->employee_id)->salary_ac_id;
   $payslip_header_amt = hr_payslip_header::find_headerAmount_by_headerId($ps_header->hr_payslip_header_id);
   $new_gjl->total_dr = $payslip_header_amt;
   $new_gjl->total_ac_dr = $payslip_header_amt;
   $total_dr_amount += $payslip_header_amt;

   $new_gjl->description = 'HR Payroll Header Id #' . $ps_header->hr_payslip_header_id;
   $new_gjl->reference_type = 'table';
   $new_gjl->save();
  }

//	save the Accrual Account
  $payroll_accrual = new gl_journal_line();
  $payroll_accrual->gl_journal_header_id = $this->gl_journal_header_id;
  $payroll_accrual->reference_key_name = 'hr_payroll_process';
  $payroll_accrual->reference_key_value = $this->hr_payroll_process_id;
  //check if line lready exists
  $jl_exists_liability = $payroll_accrual->findBy_reference_keyName_keyValue();
  if ($jl_exists_liability) {
   echo "<br> Failed Saving Journal Line. Payslip header reference exists in GL. Error @ payroll_process @@ line " . __LINE__;
   $dbc->rollback = true;
  } else {
   $payroll_accrual->gl_journal_line_id = null;
   $payroll_accrual->line_num = $this->_max_line_num;
   $this->_max_line_num++;
  }
  $payroll_accrual->status = 'U';
  $payroll_accrual->code_combination_id = $hr_pm->salary_payable_ac_id;
  $payroll_accrual->total_cr = $total_dr_amount;
  $payroll_accrual->total_ac_cr = $total_dr_amount;

  $new_gjl->description = 'HR Payroll Header Id #' . $ps_header->hr_payslip_header_id;
  $payroll_accrual->reference_type = 'table';
  $payroll_accrual->save();
 }

}

//end of path class
?>
