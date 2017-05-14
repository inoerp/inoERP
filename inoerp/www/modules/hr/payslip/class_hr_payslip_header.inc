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
 * hr_payroll_payment_method
 *  Payslip is generated for each employee after payroll process r
 * Contains all the conversion information, such as - hr_payslip_header_id, hr_payroll_process_id , period_name_id, pay_date, etc
 */
class hr_payslip_header extends dbObject {

 public static $table_name = "hr_payslip_header";
 public static $primary_column = "hr_payslip_header_id";
 public static $dependent_classes = ['hr_payslip_line'];
 public static $key_column = 'employee_id';
 public static $module = "hr";
 public static $system_info = [
  'name' => 'HR Payslip',
  'number' => '3304',
  'description' => 'Payslip',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hr_payslip_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 16
 ];
 public $field_a = [
  'hr_payslip_header_id',
  'hr_payroll_process_id',
  'period_name_id',
  'pay_date',
  'description',
  'status',
  'job_id',
  'position_id',
  'employee_id',
  'grade_id',
  'no_of_days',
  'bank_account_id',
  'payment_ref_no',
  'social_ac_no',
  'social_ac_no2',
  'mode_of_payment',
  'tax_reg_number',
  'pay_duration_type',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'employee_id',
  'period_name_id',
 ];
 public $fields_inForm_notInDataBase = [
  "employee_name",
  'identification_id',
  'job_name',
  'position_name',
 ];
 public $requiredField = [
  'employee_id',
  'pay_date'
 ];
 public $pageTitle = " Pay Slip "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $hr_payslip_header_id;
 public $hr_payroll_process_id;
 public $period_name_id;
 public $pay_date;
 public $description;
 public $status;
 public $job_id;
 public $position_id;
 public $employee_id;
 public $grade_id;
 public $no_of_days;
 public $bank_account_id;
 public $payment_ref_no;
 public $social_ac_no;
 public $social_ac_no2;
 public $mode_of_payment;
 public $tax_reg_number;
 public $pay_duration_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $employee_name;
 public $identification_id;
 public $job_name;
 public $position_name;

 public static function find_by_payrollProcessId($hr_payroll_process_id) {
  $sql = " SELECT * 
       FROM hr_payslip_header eeh 
       WHERE eeh.hr_payroll_process_id = '{$hr_payroll_process_id}'   
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

 public static function find_by_employeeId($employee_id) {
  $sql = " SELECT * 
       FROM hr_payslip_header eeh 
       WHERE eeh.employee_id = '{$employee_id}'   
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

 public static function find_by_employeeId_periodNameId($employee_id, $period_name_id) {
  $sql = " SELECT * 
       FROM hr_payslip_header eeh 
       WHERE eeh.employee_id = '{$employee_id}'    AND  period_name_id= '{$period_name_id}'
";
  $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_headerAmount_by_headerId($hr_payslip_header_id) {
  $sql = " SELECT SUM(hpl.element_value) as header_amount
       FROM hr_payslip_header eeh ,
       hr_payslip_line hpl
       WHERE eeh.hr_payslip_header_id = '{$hr_payslip_header_id}'    
       AND  eeh.hr_payslip_header_id = hpl.hr_payslip_header_id
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result[0]->header_amount : false;
 }

}

//end of bom class
?>