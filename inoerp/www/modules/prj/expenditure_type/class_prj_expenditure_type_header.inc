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
 * prj_expenditure_type_header
 * Contains all the prj_expenditure_type_header information, such as - prj_expenditure_type_header, prj_expenditure_type_header_id, org_id,  type, etc.
 * 
 */
class prj_expenditure_type_header extends dbObject {

 public static $table_name = "prj_expenditure_type_header";
 public static $primary_column = "prj_expenditure_type_header_id";
 public static $key_column = 'expenditure_type';
 public static $dependent_classes = ['prj_expenditure_type_line'];
 public static $module = "prj";
 public static $multi_select_template_path = 'modules/prj/expenditure_type/multi_action/prj_expenditure_type_header_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Expenditure Type',
  'number' => '6012',
  'description' => 'prj_expenditure_type_header',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 17
 ];
 public $field_a = [
  'prj_expenditure_type_header_id',
  'expenditure_type',
  'description',
  'expenditure_category',
  'effective_from',
  'effective_to',
  'revenue_category',
  'uom_id',
  'inventory_cb',
  'burden_cb',
  'expense_reports_cb',
  'misc_transaction_cb',
  'direct_labor_cb',
  'over_time_cb',
  'invoice_cb',
  'usages_cb',
  'wip_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'expenditure_type',
  'description'
 ];
 public $checkbox = [
  'inventory_cb',
  'burden_cb',
  'expense_reports_cb',
  'misc_transaction_cb',
  'direct_labor_cb',
  'over_time_cb',
  'invoice_cb',
  'usages_cb',
  'wip_cb',
 ];
 public $requiredField = [
  "expenditure_type",
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $search_functions = [
  'Organization' => 'search_org_name'
 ];
 public $pageTitle = " Expenditure Type"; //page Title
 public $prj_expenditure_type_header_id;
 public $expenditure_type;
 public $description;
 public $expenditure_category;
 public $effective_from;
 public $effective_to;
 public $revenue_category;
 public $uom_id;
 public $inventory_cb;
 public $burden_cb;
 public $expense_reports_cb;
 public $misc_transaction_cb;
 public $direct_labor_cb;
 public $over_time_cb;
 public $invoice_cb;
 public $usages_cb;
 public $wip_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 Public static function prj_revenue_category() {
  $option_header = option_header::find_by_exact_name('PRJ_REVENUE_CATEGORY');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 Public static function prj_expenditure_category() {
  $option_header = option_header::find_by_exact_name('PRJ_EXPENDITURE_CATEGORY');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of prj_expenditure_type_header class
?>