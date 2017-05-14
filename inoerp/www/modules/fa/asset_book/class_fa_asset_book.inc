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
 * fa_asset_book
 * Fixed Asset Class controls all the financial information such as reservation, depreciation, retired account etc.
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use fa_asset_book rev only
class fa_asset_book extends dbObject {

 public static $table_name = "fa_asset_book";
 public static $primary_column = "fa_asset_book_id";
// public static $dependent_bookes = ['inv_fa_asset_book_revision'];
 public static $key_column = 'asset_book_name';
 public static $module = "fa";
// public static $js_fileName = 'modules/inv/fa_asset_book/js/multi_select.js';
 public static $system_info = [
  'name' => 'Fixed Asset',
  'number' => '1404',
  'description' => 'Fixed Asset',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'fa',
  'weight' => 1
 ];
 public $account = [
  "default_ac_id"
 ];
 public $checkbox = [
  "revalue_ytd_depriciation_cb",
  "retire_revaluation_reserve_cb",
  "revalue_accum_depriciation_cb",
  'allow_gl_posting_cb'
 ];
 public $field_a = [
  'fa_asset_book_id',
  'asset_book_name',
  'bu_org_id',
  'type',
  'primary_fa_asset_book_id',
  'description',
  'inactive_on',
//  'ledger_id',
//  'gl_calendar_id',
  'allow_gl_posting_cb',
  'fa_calendar_code',
  'revalue_accum_depriciation_cb',
  'retire_revaluation_reserve_cb',
  'revalue_ytd_depriciation_cb',
  'sale_proceeds_gain_id',
  'sale_proceeds_loss_id',
  'sale_proceeds_clearing_id',
  'removal_cost_gain_id',
  'removal_cost_loss_id',
  'removal_cost_clearing_id',
  'nbv_retired_gain_id',
  'nbv_retired_loss_id',
  'reval_reserve_retired_gain_id',
  'status',
  'rev_enabled',
  'rev_number',
  'reval_reserve_retired_loss_id',
  'deff_depriciation_reserve_id',
  'deff_depriciation_expense_id',
  'deff_depriciation_adjustment_id',
  'default_ac_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
 public static $json_label_fields = [
  'asset_book_name',
  'asset_book_type',
  'primary_fa_asset_book_id',
  'asset_book_description',
 ];
 public $initial_search = [
  'fa_asset_book_id',
 ];
 public $requiredField = [
  'bu_org_id',
  'asset_book_name',
  'type',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Asset Class"; //page Title
 public $option_lists = [
  'fa_asset_book_types' => 'FA_ASSET_CLASS_TYPE',
 ];
 public $fa_asset_book_id;
 public $asset_book_name;
 public $type;
 public $bu_org_id;
 public $primary_fa_asset_book_id;
 public $description;
 public $inactive_on;
 public $ledger_id;
 public $gl_calendar_id;
 public $allow_gl_posting_cb;
 public $fa_calendar_code;
 public $revalue_accum_depriciation_cb;
 public $retire_revaluation_reserve_cb;
 public $revalue_ytd_depriciation_cb;
 public $sale_proceeds_gain_id;
 public $sale_proceeds_loss_id;
 public $sale_proceeds_clearing_id;
 public $removal_cost_gain_id;
 public $removal_cost_loss_id;
 public $removal_cost_clearing_id;
 public $nbv_retired_gain_id;
 public $nbv_retired_loss_id;
 public $reval_reserve_retired_gain_id;
 public $status;
 public $rev_enabled;
 public $rev_number;
 public $reval_reserve_retired_loss_id;
 public $deff_depriciation_reserve_id;
 public $deff_depriciation_expense_id;
 public $deff_depriciation_adjustment_id;
 public $default_ac_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function asset_book_type() {
  $option_header = option_header::find_by_name('FA_ASSET_CLASS_TYPE');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public function findBy_fa_asset_book_id_m($fa_asset_book_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_asset_book_id = fa_asset_book_id_m ";
  $sql .= " AND fa_asset_book_id = '{$fa_asset_book_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_assigned_orgs($fa_asset_book_number) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where fa_asset_book_number= '{$fa_asset_book_number}' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }

 public static function find_all_withFinanceDetails() {
  $sql = " SELECT   fab.asset_book_name,   fab.type as asset_book_type ,  fab.primary_fa_asset_book_id,   
fab.description as asset_book_description, fab.bu_org_id, fab.fa_asset_book_id,
org.org_id, org.legal_org_id, legal.ledger_id,
gl.ledger, gl.description as ledger_description, gl.coa_id, gl.calendar_option_line_code, gl.currency_code, legal.balancing_segments,
org.org, org.code,org.type, org.description as org_description

FROM
fa_asset_book fab,
org,
legal,
gl_ledger gl

WHERE fab.bu_org_id = org.org_id
AND org.legal_org_id = legal.org_id 
AND gl.gl_ledger_id = legal.ledger_id
 " ;
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_ColumnNameVal($columnName, $columnVal, $dependent_fields = '', $hidden_fields = '') {
  $sql = "SELECT   asset_book_name,   type as asset_book_type ,  primary_fa_asset_book_id,   
            description as asset_book_description
            FROM " . static::$table_name . " where " . $columnName . " LIKE  '%{$columnVal}%'  ";
  if (!empty($dependent_fields)) {
   foreach ($dependent_fields as $k => $v) {
    if (!empty($k) && !empty($v)) {
     $sql .= " AND $k = '{$v}' ";
    }
   }
  }

  if (!empty($hidden_fields)) {
   foreach ($hidden_fields as $k1 => $v1) {
    if (!empty($k1) && !empty($v1)) {
     $sql .= " AND $k1 = '{$v1}' ";
    }
   }
  }
//  echo $sql;
  $result_array = static::find_by_sql($sql);
  return !empty($result_array) ? ($result_array) : false;
 }

}

//end of fa_asset_book class
?>