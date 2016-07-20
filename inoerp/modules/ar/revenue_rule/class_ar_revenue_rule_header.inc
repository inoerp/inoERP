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
 * ar_revenue_rule_header CLass
 * Contains all the ar_revenue_rule_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class ar_revenue_rule_header extends dbObject {

 public static $table_name = "ar_revenue_rule_header";
 public static $dependent_classes = ['ar_revenue_rule_line'];
 public static $primary_column = "ar_revenue_rule_header_id";
 public static $key_column = 'rule_name';
 public static $module = "ar";
 public static $system_info = [
  'name' => 'Recenue Rule',
  'number' => '5108',
  'description' => 'Create & Mainten Revenue Rule',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('ar_revenue_rule_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];
 public static $rule_type_a = [
  'AUTO' => 'Automatic',
  'MANUAL' => 'Manual',
  'MONTH' => 'Monthly',
  'DATE' => 'Date Wise'
 ];
 public $field_a = [
  'ar_revenue_rule_header_id',
  'rule_type',
  'rule_name',
  'description',
  'period',
  'no_of_period',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'rule_type',
  'rule_name',
  'description',
 ];
 public $requiredField = [
  'rule_type',
  'rule_name'
 ];
 public $fields_inForm_notInDataBase = [
  'action',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1
 ];
 public $pageTitle = " Revenue Rule "; //page Title
 public $ar_revenue_rule_header_id;
 public $bu_org_id;
 public $rule_type;
 public $rule_name;
 public $description;
 public $period;
 public $no_of_period;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

}

//end of ar_revenue_rule_header class
?>