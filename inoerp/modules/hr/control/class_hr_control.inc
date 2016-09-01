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
 * hr_control 
 */
class hr_control extends dbObject {

 public static $table_name = "hr_control";
 public static $primary_column = "hr_control_id";
 public static $key_column = 'bu_org_id';
 public static $module = "hr";
 public static $system_info = [
  'name' => 'HR Control',
  'number' => '3118',
  'description' => 'Create & Mainten HR Controls',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => '',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 4
 ];
 public static $expense_claim_approval_a = [
  'SUPERVISOR' => 'Next Supervisor',
  'AMOUNT_LIMIT' => 'BY Amount Limit'
 ];
 public $field_a = [
  'hr_control_id',
  'bu_org_id',
  'default_job_id',
  'default_grade_id',
  'expense_claim_approval',
  'salary_cash_ac_id',
  'expense_claim_ac_id',
  'salary_exp_ac_id',
  'supplier_id',
  'supplier_site_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'default_job_id',
 ];
 public $requiredField = [
  'bu_org_id'
 ];
 public $account = [
  'salary_cash_ac_id',
  'expense_claim_ac_id',
  'salary_exp_ac_id',
 ];
 
 public $fields_inForm_notInDataBase = [
  "expense_claim_supplier"
 ];
 
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " HR Control "; //page Title
 public $search_functions = [
  'Business Org' => 'search_business_org',
 ];
public $hr_control_id;
public $bu_org_id;
public $default_job_id;
public $default_grade_id;
public $salary_cash_ac_id;
public $expense_claim_approval;
public $expense_claim_ac_id;
public $salary_exp_ac_id;
public $supplier_id;
public $supplier_site_id;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;
public $expense_claim_supplier;

public function findBy_orgId($bu_org_id) {
  global $db;
  $sql = "SELECT * FROM hr_control where bu_org_id=:bu_org_id LIMIT 1";
  $value_a = ['bu_org_id' => $bu_org_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_org_id($org_id) {
  $sql = "SELECT * FROM hr_control where bu_org_id='{$org_id}' LIMIT 1";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of hr_control_org class
?>
