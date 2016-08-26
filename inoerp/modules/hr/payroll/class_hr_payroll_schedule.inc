<?php

class hr_payroll_schedule extends dbObject {

 public static $table_name = "hr_payroll_schedule";
 public static $primary_column = "hr_payroll_schedule_id";
 public static $parent_primary_column = "hr_payroll_id";
 public static $key_column = "hr_payroll_id";
 public static $module = "hr";
 public static $js_fileName_prg = 'modules/hr/payroll/js/program_payroll.js ';
 public static $status_a = [
  'OPEN' => 'Open',
  'CANCELLED' => 'Cancelled',
  'PAID' => 'Paid'
 ];
 public $field_a = [
  'hr_payroll_schedule_id',
  'hr_payroll_id',
  'scheduled_date',
  'start_date',
  'end_date',
  'period_name',
  'description',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'hr_payroll_schedule_id',
  'hr_payroll_id',
 ];
 public $requiredField = [
  'hr_payroll_id',
  'scheduled_date',
  'start_date',
  'end_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hr_payroll_id"
 ];
 public $prg_generate_payroll_schedule_parameters = [
  'Payroll Name' => 'search_payroll',
 ];
 public $prg_generate_payroll_schedule_details = [
  'name' => 'Payroll Schedule Generation',
  'description' => 'Generate Payroll Schedule',
 ];
 public $prg_process_payroll_parameters = [
  'Payroll Name' => 'search_payroll',
  'Schedule Id/Date' => 'search_payroll_schedule',
 ];
 public $prg_process_payroll_details = [
  'name' => 'Process Payroll',
  'description' => 'Process Payroll',
 ];

 public $pageTitle = " Payroll Schedule "; //page Title
 public $hr_payroll_id;
 public $hr_payroll_schedule_id;
 public $scheduled_date;
 public $start_date;
 public $end_date;
 public $description;
 public $period_name;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $message;
 private $_no_days_in_period;
 private $_payroll_process_name;
 private $_payroll_process_description;

 public static function find_all_lines() {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE status = 'OPEN' ORDER BY scheduled_date ASC ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_open_schedules_by_headerId($hr_payroll_id) {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE status = 'OPEN' AND hr_payroll_id = '{$hr_payroll_id}' "
   . " ORDER BY scheduled_date ASC ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_header_id($id) {
  $vgl = new hr_payroll_schedule();
  return $vgl->findBy_parentId($id);
 }

 public static function find_latest_open_schedule_by_headerId($header_id) {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE hr_payroll_id = '{$header_id}' AND status = 'OPEN' ";
  $sql .= " ORDER BY scheduled_date  ASC ";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_optionId_lineCode($header_id, $code) {
  $sql = "SELECT * FROM " . self::$table_name .
   " where code={$code} AND hr_payroll_id={$header_id}  ";
   $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_push($result) : $result;
 }

 private function _assign_no_days_in_period($period_type) {
  switch ($period_type) {
   case 'WEEK' :
    $this->_no_days_in_period = 7;
    break;

   case 'SEMI_MONTH' :
    $this->_no_days_in_period = 15;
    break;

   case 'MONTH' :
    $this->_no_days_in_period = 30;
    break;

   case 'ALERTNATE_MONTH' :
    $this->_no_days_in_period = 60;
    break;

   case 'QUARTER' :
    $this->_no_days_in_period = 90;
    break;

   case 'YEAR' :
    $this->_no_days_in_period = 365;
    break;

   default :
    $this->_no_days_in_period = 30;
    break;
  }
 }

 private function _create_payroll_schedule() {
  $ph = hr_payroll::find_by_id($this->hr_payroll_id);
  $this->_assign_no_days_in_period($ph->period_type);

  $date_start = new DateTime($ph->start_date);
  $schedule_date_start_i = new DateTime($ph->start_date);
  $schedule_date_start = new DateTime($schedule_date_start_i->format('Y-m-01'));
//  $date_intvl_st = $this->_no_days_in_period - 1;
//  $schedule_date_start->sub(new DateInterval('P' . $date_intvl_st . 'D'));
  $date_end = new DateTime($ph->end_date);


  $total_no_days = $date_end->diff($date_start, 1)->days;
  $no_of_periods = $total_no_days / $this->_no_days_in_period;
//pa($date_end->diff($date_start, 1));

  while ($no_of_periods > 0) {
   $date_intvl = 'P' . $this->_no_days_in_period . 'D';
   $ps = new hr_payroll_schedule();
   $ps->hr_payroll_id = $this->hr_payroll_id;
   if ($ph->period_type == 'MONTH') {
    $ps->end_date = $ps->scheduled_date = $schedule_date_start->format('Y-m-t');
    $ps->start_date = $schedule_date_start->format('Y-m-01');
    $ps->period_name = $schedule_date_start->format('M-y');
   } else {
    $ps->end_date = $ps->scheduled_date = $date_start->format('Y-m-d');
    $ps->start_date = $schedule_date_start->format('Y-m-d');
   }
   $ps->status = 'OPEN';
   $ps->description = 'System generated on ' . current_time();
   $ps->save();
   if ($ph->period_type == 'MONTH') {
    $schedule_date_start->add(new DateInterval('P1M'));
   } else {
    $date_start->add(new DateInterval($date_intvl));
    $schedule_date_start->add(new DateInterval($date_intvl));
   }

   $no_of_periods--;
  }
 }

 public function prg_generate_payroll_schedule($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message .= '<br> Starting Payroll Schdule Program';

//	foreach ($parameters as $key => $val) {
//	 $this->message .='<br>' . $key . ' - ' . implode(' ; <br>', $val);
//	}
  if (!empty($parameters['hr_payroll_id'][0])) {
   $this->hr_payroll_id = $parameters['hr_payroll_id'][0];
   $this->message .= '<br> Entered hr_payroll_id is : ' . $this->hr_payroll_id;
  } else {
   $this->message .= '<br> No hr_payroll_id found. Exiting Program @ payroll_schedule @@ Line' . __LINE__;
   return $this->message;
  }


  if (!empty($this->hr_payroll_id)) {
   $this->message .= "<br> Creating Payroll schedule by  hr_payroll_id  " . $this->hr_payroll_id;
   try {
    $this->_create_payroll_schedule();
    $this->message .= "<br>Payroll schdule is Successfully Created";
   } catch (Exception $e) {
    $this->message .= "<br>_create_payroll_schedule schdule program failed!. Error @ payroll_schedule @@ Line " . __LINE__ . $e->getMessage();
   }
  }
  return $this->message;
 }

 private function _do_payroll_processing() {
  /* 1. Create a new payroll process
   * 2. Find all employees assigned to the payroll.
   * 3. Create pay slip for all the employees 
   */
  $pr_s = new hr_payroll_schedule();
  $pr_s->findBy_id($this->hr_payroll_schedule_id);

  $pr = new hr_payroll();
  $pr->findBy_id($this->hr_payroll_id);
  $pl_pm = hr_payroll_payment_method::find_by_id($pr->payment_method_id);

  $pr_process = new hr_payroll_process();
  $pr_process->hr_payroll_id = $this->hr_payroll_id;
  $pr_process->hr_payroll_schedule_id = $this->hr_payroll_schedule_id;
  $pr_process->proces_name = $this->_payroll_process_name;
  $pr_process->description = $this->_payroll_process_description;
  $pr_process->save();

  $all_employees = hr_employee::find_by_payrollId($this->hr_payroll_id);
  if (empty($all_employees)) {
   return;
  }


  foreach ($all_employees as $emp) {
   //create the payslip header
   $ps_h = new hr_payslip_header();
   $ps_h->employee_id = $emp->hr_employee_id;
   $ps_h->job_id = $emp->job_id;
   $ps_h->position_id = $emp->position_id;
   $ps_h->grade_id = $emp->grade_id;
   $ps_h->bank_ac_id = $emp->bank_account_id;
   $ps_h->tax_reg_number = $emp->tax_reg_number;
   $ps_h->social_ac_no = $emp->social_ac_no;
   $ps_h->social_ac_no2 = $emp->social_ac_no2;
   $ps_h->period_name = $pr_process->proces_name;
   $ps_h->status = 'OPEN';
   $ps_h->pay_date = $pr_s->scheduled_date;
   $start_date = new DateTime($pr_s->start_date);
   $end_date = new DateTime($pr_s->end_date);
   $ps_h->no_of_days = $end_date->diff($start_date, 1)->days;
   $ps_h->mode_of_payment = $pl_pm->payment_type;
   $ps_h->pay_duration_type = $pr->period_type;
   $ps_h->period_name_id = $pr_s->hr_payroll_schedule_id;
   $ps_h->hr_payroll_process_id = $pr_process->hr_payroll_process_id;
   $ps_h->save();

   $elemet_header = hr_element_entry_header::find_by_employeeId($emp->hr_employee_id);
   if ($elemet_header) {
    $elemet_lines = hr_element_entry_line::find_by_parent_id($elemet_header->hr_element_entry_header_id);
    if (empty($elemet_lines)) {
     return;
    }
//    pa($elemet_lines);
    foreach ($elemet_lines as $line) {
     $ps_l = new hr_payslip_line();
     $ps_l->hr_payslip_header_id = $ps_h->hr_payslip_header_id;
     $ps_l->hr_compensation_element_id = $line->element_id;
     $ps_l->element_value = hr_element_entry_line::find_monetary_value_by_id($line->element_id);
     $ps_l->save();
    }
   }
  }
 }

 public function prg_process_payroll($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message .= '<br> Processing payroll...';

//	foreach ($parameters as $key => $val) {
//	 $this->message .='<br>' . $key . ' - ' . implode(' ; <br>', $val);
//	}
  if (!empty($parameters['hr_payroll_id'][0])) {
   $this->hr_payroll_id = $parameters['hr_payroll_id'][0];
   $this->message .= '<br> Entered hr_payroll_id is : ' . $this->hr_payroll_id;
  } else {
   $this->message .= '<br> No hr_payroll_id found. Exiting Program @ payroll_schedule @@ Line' . __LINE__;
   return $this->message;
  }

  if (!empty($parameters['hr_payroll_schedule_id'][0])) {
   $this->hr_payroll_schedule_id = $parameters['hr_payroll_schedule_id'][0];
   $this->message .= '<br> Entered hr_payroll_schedule_id is : ' . $this->hr_payroll_schedule_id;
  } else {
   $pr_schedule = self::find_latest_open_schedule_by_headerId($this->hr_payroll_id);
   $this->hr_payroll_schedule_id = $pr_schedule->hr_payroll_schedule_id;
   $this->message .= '<br> No hr_payroll_id found. Using the latest payroll schdule id' . $this->hr_payroll_schedule_id;
   return $this->message;
  }

  if (!empty($parameters['payroll_process_name'][0])) {
   $this->_payroll_process_name = $parameters['payroll_process_name'][0];
  }

  if (!empty($parameters['payroll_process_description'][0])) {
   $this->_payroll_process_description = $parameters['payroll_process_description'][0];
  }


  if (!empty($this->hr_payroll_schedule_id)) {
   $this->message .= "<br> Creating pay roll process by  hr_payroll_schedule_id  " . $this->hr_payroll_schedule_id;
   try {
    $this->_do_payroll_processing();
    $this->message .= "<br>Payroll process is Successfully Created";
   } catch (Exception $e) {
    $this->message .= "<br>_create_payroll_process schdule program failed!. Error @ payroll_schedule @@ Line " . __LINE__ . $e->getMessage();
   }
  }
  return $this->message;
 }

}

//end of path class
?>