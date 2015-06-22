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
 * fa_depreciation_header
 * Contains all the fa_depreciation_header information, such as - depreciation_header, method_type, description,  calcualtion_basis, etc.
 * 
 */
class fa_depreciation_header extends dbObject {

 public static $table_name = "fa_depreciation_header";
 public static $primary_column = "fa_depreciation_header_id";
 public static $dependent_classes = ['fa_depreciation_line'];
 public static $key_column = "fa_asset_book_id";
 public static $module = "fa";
 public static $js_fileName_prg = 'modules/fa/depreciation/depreciation.js';
 public static $system_info = [
  'name' => 'depreciation',
  'number' => '1406',
  'description' => 'Depreciation ',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'dependent_class' => array('fa_depreciation_line'),
  'primary_entity_cb' => '',
  'module_name' => 'fp',
  'weight' => 2
 ];
 public static $status_a = [
  'ENTERED' => 'Entered',
  'CONFIRMED' => 'Confirmed',
  'COMPLETED' => 'Completed'
 ];
 public $field_a = [
  'fa_depreciation_header_id',
  'fa_asset_book_id',
  'gl_period_id',
  'status',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'fa_depreciation_header_id',
 ];
 public $requiredField = [
  'fa_asset_book_id',
  'gl_period_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Depreciation "; //page Title
 public $fa_depreciation_header_id;
 public $fa_asset_book_id;
 public $gl_period_id;
 public $status;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $prg_run_depreciation_parameters = [
  'Depreciation Id' => 'search_depreciation_id',
  'Asset Book' => 'search_asset_book',
  'Period' => 'search_depreciation_period'
 ];
 public $prg_run_depreciation_details = [
  'name' => 'Run Depreciation',
  'description' => 'Run depreciation program',
 ];

// public static function profile_mdm_price_list_org() {
//  $line_data_array = [];
//  $line_data_array['line_key'] = 'org_id';
//  $line_data_array['line_desc'] = 'org';
//  $line_data_array['line_values'] = org::find_all_inventory();
//  return $line_data_array;
// }

 private function _calculate_depreciation_amount($asset_r) {
  //$asset_r is aset_book_info
  if (empty($asset_r->depriciation_start_date) || empty($asset_r->life_months)) {
   return false;
  }
  $dprn_amount = 0;
  $dprn_method = new fa_depreciation_method();
  $dprn_method->findBy_id($asset_r->fa_depreciation_method_id);
  $curr_cost = $asset_r->current_cost;
  $acc_dprn_amount = $asset_r->accumulated_depreciation;
  $nbv = $asset_r->current_cost - $acc_dprn_amount;
  if ($dprn_method->calculation_basis == 'NBV') {
   $amount_availabe_for_dprn = $nbv - $asset_r->salvage_value_amount;
  } else {
   $amount_availabe_for_dprn = $curr_cost - $asset_r->salvage_value_amount;
  }

  $start_date = new DateTime($asset_r->depriciation_start_date);
  $current_date = new DateTime();
  $date_diff = $current_date->diff($start_date);
  $months_for_dprn_completed = ($date_diff->y * 12 ) + $date_diff->m;
  $months_to_depriciate = $asset_r->life_months - $months_for_dprn_completed;

  switch ($dprn_method->method_type) {
   case 'SLD' :
    $dprn_amount = $amount_availabe_for_dprn / $months_to_depriciate;
    break;

   case 'RBD' :
    $rate = !empty($dprn_method->reducing_balance_rate) ? $dprn_method->reducing_balance_rate : 0;
    $dprn_amount = ($amount_availabe_for_dprn * $rate) / 100;
    break;

   case 'SYDD' :
    $total_years = ceil($asset_r->life_months / 12);
    $total_years_for_dprn = 0;
    for($i =1 ; $i < $total_years; $i++){
     $total_years_for_dprn +=$i;
    }
    $curr_year = floor($date_diff->y);
    $year_no_of_dprn = $total_years - $curr_year;
    $dprn_amount = [($amount_availabe_for_dprn * $year_no_of_dprn)/$total_years_for_dprn] / 12;
    break;

   case 'UAD' :
    break;

   case 'RATE' :
    $rate = fa_depreciation_method_rate::find_by_headerId_year_period($asset_r->fa_depreciation_method_id, $date_diff->y + 1 , $date_diff->m + 1);
    $dprn_amount = ($amount_availabe_for_dprn * $rate) / 100;
    break;
  }
  
  return $dprn_amount;
 }

 private function _create_depreciation_lines() {
  echo '<br> in  line '. __LINE__;
  $fa_dh = new fa_depreciation_header();
  $fa_dh->findBy_id($this->fa_depreciation_header_id);

  /* 1. Find all assets assigned to the depreciation book from asset_book_info
   * 2. For each asset creat a fa_depreciation_line */
  
  $fa_ast_book_info_i = fa_asset_book_info::find_by_bookId($fa_dh->fa_asset_book_id);

  if (empty($fa_ast_book_info_i)) {
   return;
  }

  foreach ($fa_ast_book_info_i as $asset_r) {
   $fa_dprn_line = new fa_depreciation_line();

   $fa_dprn_line->fa_depreciation_header_id = $this->fa_depreciation_header_id;
   $fa_dprn_line->asset_id = $asset_r->fa_asset_id;
   $dprn_amount = $this->_calculate_depreciation_amount($asset_r);
   $fa_dprn_line->depreciation_amount = $fa_dprn_line->total_depreciation_amount = $dprn_amount;
   $fa_asset_assgn = fa_asset_assignment::find_by_parent_id($asset_r->fa_asset_id);
   if (!empty($fa_asset_assgn[0]->expense_ac_id)) {
    $fa_dprn_line->depreciation_account_id = $fa_asset_assgn[0]->expense_ac_id;
   } else {
    $fa_dprn_line->depreciation_account_id = '999';
   }
   $fa_dprn_line->cost_before_depreciation = $asset_r->current_cost;
   $fa_dprn_line->nbv_before_depreciation = $asset_r->current_cost - $asset_r->accumulated_depreciation;
   $fa_dprn_line->salvage_value_bd = $asset_r->salvage_value_amount;
   try {
    $fa_dprn_line->save();
   } catch (Exception $e) {
    echo "<br/>Error @ fa_depreciation_header @@ line " . __LINE__ . $e->getMessage();
   }
   unset($dprn_amount);
  }
 }

 public function prg_run_depreciation($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting depreciation program';

  if (!empty($parameters['fa_depreciation_header_id'][0])) {
   $this->fa_depreciation_header_id = $parameters['fa_depreciation_header_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $this->fa_depreciation_header_id;
  } else {
   $this->message .= '<br> Error! : No fa_depreciation_header_id found @ fa_depreciation_header  ' . __LINE__;
   return $this->message;
  }


  if (!empty($this->fa_depreciation_header_id)) {
   $this->message .= "<br/>Using fa_depreciation_header_id $this->fa_depreciation_header_id ";
   try {
    $this->_create_depreciation_lines();
    $this->message .= "<br/>Depreciation program is sucessfully completed for fa_depreciation_header_id " . $this->fa_depreciation_header_id;
   } catch (Exception $e) {
    $this->message .= "<br/>Depreciation program fialed for Item fa_depreciation_header_id " . $this->fa_depreciation_header_id . $e->getMessage();
   }

   return $this->message;
  }
 }

}

//end of path class
?>
