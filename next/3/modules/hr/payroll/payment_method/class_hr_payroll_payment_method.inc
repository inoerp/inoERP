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
 * 
 */
 class hr_payroll_payment_method extends dbObject {

  public static $table_name = "hr_payroll_payment_method";
  public static $primary_column = "hr_payroll_payment_method_id";
  public static $key_column = 'payment_method';
  public static $module = "hr";
   public static $system_info = [
  'name' => 'HR Payment Method',
  'number' => '3302',
  'description' => 'HR Payroll Payment Method',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hr_payroll_schedule'),
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 15
 ];
  public $field_a = [
   'hr_payroll_payment_method_id',
   'ledger_id',
   'payment_method',
   'payment_type',
   'start_date',
   'end_date',
   'description',
   'currency',
   'bank_account_id',
   'cash_ac_id',
   'clearing_ac_id',
   'bank_charge_ac_id',
   'salary_payable_ac_id',
   'costed_cb',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'hr_payroll_payment_method_id',
   'payment_method',
   'payment_type',
  ];
  public $fields_inForm_notInDataBase = [
   'country',
   'bank_name',
   'bank_number',
   'description',
   'bank_name_short',
   'bank_name_alt',
   'branch_name',
   'branch_number',
   'ifsc_code',
   'swift_code',
   'routing_number',
   'iban_code',
   'account_description',
   'bank_header_id',
   'bank_site_id'
  ];
  public $requiredField = [
   'payment_method',
   'payment_type',
  ];
  public $hr_payroll_payment_method_id;
  public $ledger_id;
  public $payment_method;
  public $payment_type;
  public $start_date;
  public $end_date;
  public $description;
  public $currency;
  public $bank_account_id;
  public $cash_ac_id;
  public $clearing_ac_id;
  public $bank_charge_ac_id;
  public $salary_payable_ac_id;
  public $costed_cb;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $country;
  public $bank_name;
  public $bank_number;
  public $bank_name_short;
  public $bank_name_alt;
  public $branch_name;
  public $branch_number;
  public $ifsc_code;
  public $swift_code;
  public $routing_number;
  public $iban_code;
  public $account_usage;
  public $account_type;
  public $account_number;
  public $mdm_bank_account_id;
  public $mdm_bank_header_id;
  public $mdm_bank_site_id;
  public $account_description;
  public $bank_header_id;
  public $bank_site_id;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " HR Payroll Payment Methods  "; //page Title

  Public static function payment_method_type() {
   $option_header = option_header::find_by_name('HR_PAYMENT_METHOD_TYPE');
   $ol = new option_line();
   $option_lines = $ol->findBy_parentId($option_header->option_header_id);
   return $option_lines;
  }

 }

//end of hr_payroll_payment_method class
?>