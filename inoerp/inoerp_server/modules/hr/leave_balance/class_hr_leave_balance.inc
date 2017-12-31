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
 * hr_leave_balance
 * Employee leave balance information
 * Contains all the hr_job information, such as - leave_type, employee_id , total_available, etc
 * 
 */
 class hr_leave_balance extends dbObject {

  public static $table_name = "hr_leave_balance";
  public static $module = "hr";
  public static $primary_column = "hr_leave_balance_id";
  public static $key_column = "employee_id";
   public static $system_info = [
  'name' => 'Leave Balance',
  'number' => '3202',
  'description' => 'HR Leave Balance',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 11
 ];
  public $field_a = [
   'hr_leave_balance_id',
   'employee_id',
   'leave_type',
   'leave_per_year',
   'total_available',
   'total_used',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'employee_id',
   'leave_type',
  ];
  public $requiredField = [
   'employee_id',
   'leave_type'
  ];
  public $fields_inForm_notInDataBase = [
   "employee_name",
   'identification_id',
   'available_balance'
  ];
  public $fields_inHeader_needsToBeInserted_inPOST = [
   'employee_id'
  ];
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " Leave Balance "; //page Title
  public $hr_leave_balance_id;
  public $employee_id;
  public $leave_type;
  public $leave_per_year;
  public $total_available;
  public $total_used;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $employee_name;
  public $identification_id;
  public $available_balance;

  Public static function tax_type() {
   $option_header = option_header::find_by_name('MDM_TAX_TYPE');
   $ol = new option_line();
   $option_lines = $ol->findBy_parentId($option_header->option_header_id);
   return $option_lines;
  }

  public function find_all_ofyear($year) {
   global $db;
   $sql = " SELECT * FROM " . self::$table_name;
   $sql .= " WHERE year= :year ";
   $param_a = ['year'];
   $value_a = ['year' => $year];
   $result = $db->findBy_sql($sql, $param_a, $value_a);
   return $result;
  }

  public function findBy_employeeId_leaveType($employee_id, $leave_type) {
   $sql = " SELECT * FROM " . self::$table_name;
   $sql .= " WHERE employee_id= :employee_id AND leave_type = :leave_type ";
   $sql = ino_perPageSql_i($sql, 1);
   $value_a = ['employee_id' => $employee_id, 'leave_type' => $leave_type];
   $result = $this->findBySql($sql, $value_a);
   return !empty($result) ? array_pop($result) : null;
  }

  public function findBy_employeeId($employee_id = '') {
   $employee_id = empty($employee_id) ? $this->employee_id : $employee_id;
   $sql = " SELECT * FROM " . self::$table_name;
   $sql .= " WHERE employee_id= :employee_id ";
   $value_a = ['employee_id' => $employee_id];
   $result = $this->findBySql($sql, $value_a);
   return !empty($result) ? ($result) : null;
  }

 }

//end of hr_leave_balance class
?>