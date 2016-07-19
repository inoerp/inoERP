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
 * prj_agreement_header
 *
 */
class prj_agreement_header extends dbObject {

 public static $table_name = "prj_agreement_header";
 public static $primary_column = "prj_agreement_header_id";
 public static $dependent_classes = ['prj_agreement_line'];
 public static $key_column = "agreement_number";
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Project Agreement',
  'number' => '6001',
  'description' => 'Project Agreement',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 11
 ];
 public $field_a = [
  'prj_agreement_header_id',
  'bu_org_id',
  'agreement_type',
  'agreement_number',
  'ar_customer_id',
  'ar_customer_site_id',
  'admin_employee_id',
  'description',
  'payment_term_id',
  'start_date',
  'end_date',
  'header_amount',
  'currency',
  'doc_currency',
  'exchange_rate_type',
  'exchange_rate',
  'r_hard_limt_cb',
  'i_hard_limt_cb',
  'advanced_required_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'agreement_number',
  'description',
 ];
 public $fields_inForm_notInDataBase = [
  "customer_name",
  "customer_number",
  "customer_site_name",
  'admin_employee_name'
 ];
 public $requiredField = [
  'bu_org_id',
  'ar_customer_id',
 ];
 public $number_fields = [
  'header_amount'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project Agreements "; //page Title
 public $prj_agreement_header_id;
 public $bu_org_id;
 public $agreement_type;
 public $agreement_number;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $admin_employee_id;
 public $description;
 public $payment_term_id;
 public $start_date;
 public $end_date;
 public $header_amount;
 public $currency;
 public $doc_currency;
 public $exchange_rate_type;
 public $exchange_rate;
 public $r_hard_limt_cb;
 public $i_hard_limt_cb;
 public $advanced_required_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $admin_employee_name;

 Public static function validation_types() {
  $header = option_header::find_by_keyColumn('SYS_VALIDATION_TYPE');
  $option_line = new option_line();
  $lines = $option_line->findBy_parentId($header->option_header_id);
  return $lines;
 }

}

//end of path class
?>
