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
 * ap_payable_control 
 */
class ap_payable_control extends dbObject {

 public static $table_name = "ap_payable_control";
 public static $primary_column = "ap_payable_control_id";
 public static $key_column = 'org_id';
 public static $module = "ap";
 public static $system_info = [
  'name' => 'Payable Control',
  'number' => '1312',
  'description' => 'Create & Mainten Payable Controls',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => '',
  'primary_entity_cb' => '',
  'module_name' => 'po',
  'weight' => 4
 ];
 public static $approval_hierarchy_a = [
  'SUPERVISOR' => 'Next Supervisor',
  'POSITION' => 'Position Based'
 ];
 public $field_a = [
  'ap_payable_control_id',
  'org_id',
  'payment_term_id',
  'ship_to_id',
  'bill_to_id',
  'inv_approval_hierarchy',
  'payment_approval_hierarchy',
  'tax_ac_id',
  'liability_ac_id',
  'pre_payment_ac_id',
  'discount_ac_id',
  'rate_gain_ac_id',
  'rate_loss_ac_id',
  'cash_ac_id',
  'default_exchange_rate_type',
  'expense_payment_term',
  'expense_pay_group',
  'expense_payment_priority',
  'expense_template_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'ap_payable_control_id',
  'org_id',
 ];
 public $requiredField = [
  'org_id'
 ];
 public $fields_inForm_notInDataBase = [
  "ship_to_location",
  "bill_to_location"
 ];
 public $account = [
  'liability_ac_id',
  'pre_payment_ac_id',
  'discount_ac_id',
  'rate_gain_ac_id',
  'rate_loss_ac_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Payable Control "; //page Title
 public $option_lists = [
  'ap_payable_control_org_types' => 'ORG_TYPE',
 ];
 public $search_functions = [
  'Business Org' => 'search_business_org',
 ];
 public $ap_payable_control_id;
 public $org_id;
 public $payment_term_id;
 public $ship_to_id;
 public $bill_to_id;
 public $inv_approval_hierarchy;
 public $payment_approval_hierarchy;
 public $tax_ac_id;
 public $cash_ac_id;
 public $liability_ac_id;
 public $pre_payment_ac_id;
 public $discount_ac_id;
 public $rate_gain_ac_id;
 public $rate_loss_ac_id;
 public $default_exchange_rate_type;
 public $expense_payment_term;
 public $expense_pay_group;
 public $expense_payment_priority;
 public $expense_template_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_showing() {
  if (!empty($this->ship_to_id)) {
   $this->ship_to_location = address::find_by_id($this->ship_to_id)->address_name;
  } else {
   $this->ship_to_location = null;
  }

  if (!empty($this->bill_to_id)) {
   $this->bill_to_location = address::find_by_id($this->bill_to_id)->address_name;
  } else {
   $this->bill_to_location = null;
  }
 }

 public function findBy_orgId($org_id) {
  global $db;
  $sql = "SELECT * FROM ap_payable_control where org_id=:org_id ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $param_a = ['org_id'];
  $value_a = ['org_id' => $org_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_org_id($org_id) {
  $sql = "SELECT * FROM ap_payable_control where org_id='{$org_id}' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of ap_payable_control_org class
?>
