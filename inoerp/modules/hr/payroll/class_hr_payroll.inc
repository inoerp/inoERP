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
 * hr_payroll
 * Employee payroll information
 * Contains all the hr_payroll information, such as - Payroll, period_type , start_date, end_date, etc
 * 
 */

class hr_payroll extends dbObject {

 public static $table_name = "hr_payroll";
 public static $primary_column = "hr_payroll_id";
 public static $dependent_classes = ['hr_payroll_schedule'];
 public static $key_column = "payroll";
 public static $module = "hr";
 public static $system_info = [
  'name' => 'Payroll',
  'number' => '3301',
  'description' => 'HR Payroll',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hr_payroll_schedule'),
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 14
 ];
 public $field_a = [
  'hr_payroll_id',
  'payroll',
  'period_type',
  'start_date',
  'end_date',
  'description',
  'payment_method_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'hr_payroll_id',
  'payroll',
  'period_type',
 ];
 public $requiredField = [
  'payroll',
  'period_type',
  'start_date',
  'end_date',
  'payment_method_id',
 ];
 public $checkbox = ['schedule_payroll_cb'];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $fields_inForm_notInDataBase = [
  "schedule_payroll_cb",
 ];
 public $pageTitle = " HR Payroll "; //page Title
 public $hr_payroll_id;
 public $payroll;
 public $period_type;
 public $start_date;
 public $end_date;
 public $description;
 public $payment_method_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $schedule_payroll_cb;

 public static function find_by_module($module_name) {
  $sql = " SELECT * FROM " . self::$table_name . " WHERE module_name = '{$module_name}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_all_purchasing_pl() {
  return self::find_by_module('PO');
 }

 public static function find_all_sales_pl() {
  return self::find_by_module('SD');
 }

}

//end of path class
?>
