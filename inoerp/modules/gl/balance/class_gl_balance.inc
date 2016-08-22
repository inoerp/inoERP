<?php

/**
 * inoERP 
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * gl_balance
 *  
 */
class gl_balance extends dbObject {

 public static $table_name = "gl_balance";
 public static $primary_column = "gl_balance_id";
 public static $key_column = 'coa_combination_id';
 public static $module = "gl";
 public static $system_info = [
  'name' => 'GL Balance',
  'number' => '1101',
  'description' => 'General Ledger Account Balance',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'gl',
  'weight' => 1
 ];
 public $field_a = [
  'gl_balance_id',
  'ledger_id',
  'coa_combination_id',
  'period_id',
  'balance_type',
  'period_net_dr',
  'period_net_cr',
  'begin_balance_dr',
  'begin_balance_cr',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public $initial_search = [
  'gl_balance_id',
  'ledger_id',
  'coa_combination_id',
  'period_id',
  'balance_type'
 ];
 public $column = [
  'gl_balance_id',
  'ledger_id',
  'coa_combination_id',
  'period_id',
  'balance_type'
 ];
 public $requiredField = [
  'gl_balance_id',
  'ledger_id',
  'coa_combination_id',
  'period_id',
  'balance_type',
 ];
 public $number_fields = [
  'period_net_dr',
  'period_net_cr',
  'begin_balance_dr',
  'begin_balance_cr',
  'gl_balance_id',
  'ledger_id',
  'coa_combination_id',
  'period_id',
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $pageTitle = " GL Balance "; //page Title
 public $option_lists = [
 ];
 public $gl_balance_id;
 public $ledger_id;
 public $coa_combination_id;
 public $period_id;
 public $gl_calendar_id;
 public $balance_type;
 public $period_net_dr;
 public $period_net_cr;
 public $begin_balance_dr;
 public $begin_balance_cr;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $total_ac_dr;
 public $total_ac_cr;

 public function __set($name, $value) {
  switch ($value) {
   case 'total_ac_dr':
    $this->$name = is_numeric($value) ? $value : null;
    break;

   case 'total_ac_cr':
    $this->$name = is_numeric($value) ? $value : null;
    break;

   default:
    $this->$name = $value;
    break;
  }
 }

 public function _before_save() {
  $this->creation_date = current_time();
  if ((isset($_SESSION)) && (!empty($_SESSION['username']))) {
   $this->created_by = $_SESSION['username'];
  } else {
   $this->created_by = 'system';
  }
  $this->last_update_date = $this->creation_date;
  $this->last_update_by = $this->created_by;

  $current_balance = $this->_check_balance_id();
  if (!empty($current_balance)) {
   $this->gl_balance_id = $current_balance->gl_balance_id;
   if (!empty($this->total_ac_dr)) {
    $this->period_net_dr = $this->total_ac_dr + $current_balance->period_net_dr;
   } else if (!empty($this->total_ac_cr)) {
    $this->period_net_cr = $this->total_ac_cr + $current_balance->period_net_cr;
   }
  } else {
   $this->gl_balance_id = null;
   if (!empty($this->total_ac_dr)) {
    $this->period_net_dr = $this->total_ac_dr;
   } else if (!empty($this->total_ac_cr)) {
    $this->period_net_cr = $this->total_ac_cr;
   }
  }
 }

 public function _after_save() {

  //update the gl_balances table
 }

 private function _check_balance_id() {
  global $db;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ledger_id = :ledger_id AND period_id = :period_id AND coa_combination_id = :coa_combination_id ";
  $param_a = ['ledger_id', 'period_id', 'coa_combination_id'];
  $value_a = [ 'ledger_id' => $this->ledger_id,
   'period_id' => $this->period_id,
   'coa_combination_id' => $this->coa_combination_id
  ];

  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 private function _Actity_inAPeriod($period_id) {
  global $db;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ( period_net_dr IS NOT NULL || period_net_cr IS NOT NULL "
   . "|| begin_balance_dr IS NOT NULL || begin_balance_cr IS NOT NULL) ";
  $sql .= " AND  period_id = :period_id ";
  $param_a = ['period_id'];
  $value_a = [ 'period_id' => $period_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? $result : false;
 }

 private function _verify_if_balance_exists() {
  global $db;
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE  ledger_id = :ledger_id ";
  $sql .= " AND  period_id = :period_id ";
  $sql .= " AND  balance_type = :balance_type ";
  $sql .= " AND  coa_combination_id = :coa_combination_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $param_a = ['ledger_id', 'period_id', 'balance_type', 'coa_combination_id'];
  $value_a = [ 'ledger_id' => $this->ledger_id,
   'period_id' => $this->period_id,
   'balance_type' => $this->balance_type,
   'coa_combination_id' => $this->coa_combination_id
  ];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public function period_open_activities($last_period_id, $current_period_id) {
  $all_last_period_acitivities = $this->_Actity_inAPeriod($last_period_id);
  if (empty($all_last_period_acitivities)) {
   return;
  }
  foreach ($all_last_period_acitivities as $balances) {
   $opening_balance = new $this;
   $opening_balance->period_id = $current_period_id;
   $opening_balance->ledger_id = $balances->ledger_id;
   $opening_balance->balance_type = $balances->balance_type;
   $opening_balance->coa_combination_id = $balances->coa_combination_id;
   $existing_balance = $opening_balance->_verify_if_balance_exists();
   $opening_balance->gl_balance_id = !(empty($existing_balance)) ? $existing_balance->gl_balance_id : null;
   $opening_balance->begin_balance_dr = $balances->period_net_dr + $balances->begin_balance_dr;
   $opening_balance->begin_balance_cr = $balances->period_net_cr + $balances->begin_balance_cr;
   try {
    $opening_balance->_before_save();
    $opening_balance->save();
   } catch (Exception $e) {
    echo " Opening Balance Update Failed!" . $e->getMessage();
   }
  }
 }

}

//end of gl_balance class
?>