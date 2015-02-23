<?php

//set $allow_conversion to true when before conversion
class convertToProd extends dbObject {

 public static $allow_conversion = true;
 public static $table_name = "convertToProd";
 public static $primary_column = "username";
 public static $key_column = "profile_name";
 public static $module = "sys";
 public $exclude_tables_only_setup = [
  'block',
  'block_content',
  'bom_cost_type',
  'bom_material_element',
  'category',
  'category_reference',
  'coa',
  'content_type',
  'content_type_reference',
  'engine',
  'enterprise',
  'ext_url_alias',
  'form',
  'gl_calendar',
  'gl_ledger',
  'gl_period',
  'module',
  'option_detail',
  'option_header',
  'option_line',
  'path',
  'product',
  'role_access',
  'site_info',
  'sys_hold',
  'sys_permission',
  'sys_profile_header',
  'sys_profile_line',
  'sys_role_permission',
  'sys_value_group_header',
  'sys_value_group_line',
  'system_path',
  'transaction_type',
  'uom',
  'user',
  'user_role',
  'view',
  'view_path',
  'bc_label_format_header',
  'bc_static_label',
  'bc_label_format_line',
  'bc_label_auto_trigger',
  'sys_process_flow_line',
  'sys_process_flow_header',
  'cc_co_template_header',
  'cc_co_template_line',
  'sd_document_type'
 ];
 public $exclude_tables_limited_setup_mode = [
  'ap_payment_terms',
  'ar_receipt_source',
  'ar_transaction_source',
  'ar_transaction_type',
  'bom_department',
  'bom_department_resource_assignment',
  'bom_overhead',
  'bom_overhead_rate_assignment',
  'bom_overhead_resource_assignment',
  'bom_resource',
  'bom_resource_cost',
  'business',
  'hr_approval_limit_assignment',
  'hr_approval_limit_header',
  'hr_approval_limit_line',
  'hr_approval_object',
  'hr_compensation_element',
  'hr_control',
  'hr_element_entry_header',
  'hr_element_entry_line',
  'hr_element_entry_tpl_header',
  'hr_element_entry_tpl_line',
  'hr_job',
  'hr_leave_type',
  'hr_payroll',
  'hr_payroll_payment_method',
  'hr_payroll_schedule',
  'hr_position',
  'hr_position_hierarchy_header',
  'hr_position_hierarchy_line',
  'inventory',
  'item_status',
  'legal',
  'mdm_tax_code',
  'mdm_tax_region',
  'mdm_tax_rule',
  'org',
  'payment_term',
  'payment_term_discount',
  'payment_term_schedule',
  'po_purchasing_control',
  'role_path',
  'sd_shipping_control',
  'sys_document_sequence',
  'sys_dynamic_block_header',
  'sys_dynamic_block_line',
  'sys_extra_field',
  'sys_extra_field_instance',
  'sys_hold_reference',
  'sys_notification_group',
  'user_favourite',
  'user_password_reset',
  'user_supplier',
  'wip_control',
  'fp_planning_control',
  'sd_document_type'
 ];
 public $exclude_tables_all_setup_mode = [
  'address',
  'am_activity_reference',
  'am_asset',
  'ar_customer',
  'ar_customer_bu',
  'ar_customer_site',
  'bom_commonbom_line',
  'bom_config_header',
  'bom_config_line',
  'bom_header',
  'bom_line',
  'bom_routing_detail',
  'bom_routing_header',
  'bom_routing_line',
  'bom_standard_operation',
  'bom_standard_operation_resource_assignment',
  'c_article',
  'c_collections',
  'c_content',
  'c_documentation',
  'c_forum',
  'c_issue',
  'coa_combination',
  'coa_segment_values',
  'comment',
  'common_bom_line',
  'content',
  'cst_item_cost_header',
  'cst_item_cost_line',
  'cst_item_cost_line_pre',
  'ext_test_case_header',
  'ext_test_case_line',
  'extn_contact',
  'extn_contact_reference',
  'extn_web_tracking',
  'fa_asset',
  'fa_asset_assignment',
  'fa_asset_book',
  'fa_asset_book_info',
  'fa_asset_category',
  'fa_book_category_association',
  'fa_depreciation_method',
  'fa_depreciation_method_rate',
  'file',
  'file_reference',
  'fp_forecast_group',
  'fp_forecast_header',
  'fp_mds_header',
  'fp_mrp_header',
  'gl_balance',
  'gl_currency_conversion',
  'hr_employee',
  'hr_employee_education',
  'hr_employee_experience',
  'hr_employee_termination',
  'hr_leave_balance',
  'hr_leave_entitlement_header',
  'hr_leave_entitlement_line',
  'hr_leave_transaction',
  'hr_payslip_header',
  'hr_payslip_line',
  'hr_team_header',
  'hr_team_line',
  'inv_abc_assignment_header',
  'inv_abc_assignment_line',
  'inv_abc_valuation',
  'inv_abc_valuation_result',
  'inv_item_revision',
  'inv_location_default',
  'item',
  'locator',
  'mdm_bank_account',
  'mdm_bank_header',
  'mdm_bank_site',
  'mdm_price_list_header',
  'mdm_price_list_line',
  'po_asl_document',
  'po_asl_header',
  'po_asl_line',
  'po_sourcing_rule_header',
  'po_sourcing_rule_line',
  'pos_barcode_list_header',
  'pos_barcode_list_line',
  'pos_inv_control',
  'pos_terminal',
  'sd_document_relation',
  'sd_sales_control',
  'sd_store',
  'sd_store_subinventory',
  'subinventory',
  'supplier',
  'supplier_bu',
  'supplier_site',
  'sys_printer',
  'sys_secondary_field',
  'sys_secondary_field_instance',
  'user_dashboard_config',
  'user_group',
  'user_group_access',
  'wip_accounting_group',
 ];
 public $pageTitle = " Conver to Production "; //page Title
 public $convertToProd_id;
 public $message;
 public $convert_to_prod_mode;
 public $exclusion_mode;
 public $exclude_tables_final = '';
 public $prg_convert_to_prod_parameters = [
  'Program Mode' => 'search_convert_to_prod_mode',
  'Exclusion Mode (Data to Keep)' => 'search_exclusion_mode',
  'DB Name' => 'search_db_name',
 ];
 public $prg_convert_to_prod_details = [
  'name' => 'Convert DB from Demo to Production',
  'description' => 'Convert DB from Demo to Production',
 ];

 private function _set_exclusion_mode() {
  switch ($this->exclusion_mode) {
   case 'ONLY_SETUP' :
    $this->exclude_tables_final = $this->exclude_tables_only_setup;
    break;

   case 'LIMITED_SETUP' :
    $this->exclude_tables_final = array_merge($this->exclude_tables_only_setup, $this->exclude_tables_limited_setup_mode);
    break;

   case 'ALL_SETUP' :
    $this->exclude_tables_final = array_merge($this->exclude_tables_all_setup_mode, $this->exclude_tables_limited_setup_mode, $this->exclude_tables_only_setup);
    break;

   default :
    $this->exclude_tables_final = array_merge($this->exclude_tables_all_setup_mode, $this->exclude_tables_limited_setup_mode, $this->exclude_tables_only_setup);
    break;
  }
 }

 public function prg_convert_to_prod($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message .= '<br> Staring Convert to Prod program ';

  if (!empty($parameters['convert_to_prod_mode'][0])) {
   $convert_to_prod_mode = $this->convert_to_prod_mode = $parameters['convert_to_prod_mode'][0];
   $this->message .= '<br> Entered convert_to_prod_mode is : ' . $convert_to_prod_mode;
  } else {
   $convert_to_prod_mode = 'TEST';
   $this->message .= '<br> No convert_to_prod_mode found. Running the program in TEST mode ' . __LINE__;
  }


  if (!empty($parameters['exclusion_mode'][0])) {
   $this->exclusion_mode = $parameters['exclusion_mode'][0];
   $this->message .= '<br> Entered exclusion_mode is : ' . $this->exclusion_mode;
  } else {
   $this->exclusion_mode = 'LIMITED';
   $this->message .= '<br> No exclusion_mode found. Running the program in LIMITED mode ' . __LINE__;
  }


  try {
   $this->convert_to_prod($convert_to_prod_mode);
   $this->message .= "<br>Convert to Prod program is sucessfully completed";
  } catch (Exception $e) {
   $this->message .= "<br>Convert to Prod program failed!" . $e->getMessage();
  }

  return $this->message;
 }

 public function convert_to_prod($mode = 'TEST') {
  global $dbc;
  $table_sql = "   select table_name
from information_schema.tables
WHERE TABLE_SCHEMA= '" . DB_NAME . "'
AND table_type = 'BASE TABLE'
 ";

  $prepare = $dbc->connection->prepare($table_sql);
  try {
   $prepare->execute();
   $result_fetchAll = $prepare->fetchAll(PDO::FETCH_COLUMN);
  } catch (Exception $e) {
//    echo "<br>Error @dbObject @@ Line " . __LINE__ . $sql;
   return false;
  }

  $this->_set_exclusion_mode();
  if (empty($this->exclude_tables_final)) {
   $this->exclude_tables_final = $this->exclude_tables_limited_mode;
  }
  $this->message .= '<h2>Total no base tables in selected DB ' . DB_NAME . ' : </h2>' . count($result_fetchAll);
  $include_tables = array_diff($result_fetchAll, $this->exclude_tables_final);
  $include_tables = array_values($include_tables);
  $this->message .= '<h2>Total no tables updated : </h2>' . count($include_tables);

  if ($mode != 'FINAL') {
   return;
  }

  foreach ($include_tables as $key => $table_name) {
   $sql2 = " DELETE FROM  {$table_name}  ";
   $dbc->ddlexecute($sql2);
   $sql3 = "   ALTER TABLE {$table_name} auto_increment = 1 ";
   $dbc->ddlexecute($sql3);
   echo "<br> $table_name is updated";
  }
  $dbc->confirm();
 }

}

//end of path class
?>