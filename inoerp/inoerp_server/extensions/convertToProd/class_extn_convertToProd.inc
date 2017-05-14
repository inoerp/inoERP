<?php

//set $allow_conversion to true when before conversion
class extn_convertToProd extends dbObject {

 public static $allow_conversion = true;
 public static $table_name = "extn_convertToProd";
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
  'extn_menu_header',
  'extn_menu_line',
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
  'ino_user',
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
  'sd_document_type',
  'adm_task_status',
  'adm_task_template_header',
  'adm_task_template_line',
  'adm_task_type',
  'fa_asset_source',
  'hd_service_type_header',
  'hd_service_type_line',
  'hd_task_type',
  'prj_bem',
  'prj_burden_cost_base',
  'prj_burden_costcode',
  'prj_burden_struct_costcode',
  'prj_burden_struct_exptype',
  'prj_burden_structure_header',
  'prj_category_header',
  'prj_category_line',
  'prj_category_value',
  'prj_event_header',
  'prj_event_line',
  'prj_event_type',
  'prj_status_header',
  'prj_status_line',
  'prj_status_next',
  'prj_work_type',
  'qa_specification_header',
  'qa_specification_line',
  'extn_report'
 ];
 public $exclude_tables_limited_setup_mode = [
  'ap_payment_terms',
  'ar_receipt_source',
  'ar_transaction_source',
  'ar_transaction_type',
  'ar_revenue_rule_header',
  'ar_revenue_rule_line',
  'bom_department',
  'bom_dept_res_assignment',
  'bom_overhead',
  'bom_oh_rate_assignment',
  'bom_oh_res_assignment',
  'bom_resource',
  'bom_resource_cost',
  'business',
  'hr_approval_limit_assign',
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
  'hr_pos_hierarchy_header',
  'hr_pos_hierarchy_line',
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
  'ino_user',
  'user_role',
  'user_favourite',
  'user_password_reset',
  'user_supplier',
  'wip_control',
  'fp_planning_control',
  'sd_document_type',
  'am_meter',
  'am_ms_calendar_date',
  'am_ms_date_rule',
  'am_ms_meter_rule',
  'ar_sales_region',
  'extn_social_login',
  'prj_burden_list_header',
  'prj_burden_list_line',
  'prj_expenditure_type_header',
  'prj_expenditure_type_line',
  'prj_nlr_header',
  'prj_nlr_line',
  'prj_role',
  'sys_catalog_header',
  'sys_catalog_line',
  'sys_catalog_value',
  'sys_pd_header',
  'sys_pd_process_flow_action',
  'sys_process_flow_action',
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
  'bom_stnd_op_res_assignment',
  'c_article',
  'c_collections',
  'c_content',
  'c_dataentity',
  'c_documentation',
  'c_forum',
  'c_issue',
  'coa_combination',
  'coa_segment_values',
  'comment',
  'common_bom_line',
  'content',
  'extn_emessage_line',
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
  'fa_book_category_assoc',
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
  'sys_secondary_field_inst',
  'ino_user',
  'user_role',
  'user_favourite',
  'user_password_reset',
  'user_supplier',
  'user_dashboard_config',
  'user_group',
  'user_group_access',
  'wip_accounting_group',
  'address_reference',
  'am_maintenance_schedule',
  'am_ms_activity_reference',
  'am_planned_wo',
  'am_wo_bom',
  'am_wo_header',
  'am_wo_routing_detail',
  'am_wo_routing_line',
  'ap_payable_control',
  'ap_payment_all_v',
  'ap_payment_header',
  'ap_payment_interface',
  'ap_payment_line',
  'ap_payment_process',
  'ap_payment_trnx_v',
  'ap_po_matching_v',
  'ap_transaction_all_v',
  'ap_transaction_detail',
  'ap_transaction_header',
  'ap_transaction_line',
  'ar_customer_relation',
  'ar_customer_v',
  'ar_payment_process',
  'ar_receipt_header',
  'ar_receipt_interface',
  'ar_receipt_line',
  'ar_transaction_all_v',
  'ar_transaction_detail',
  'ar_transaction_header',
  'ar_transaction_interface',
  'ar_transaction_line',
  'ar_unpaid_transaction_v',
  'bc_label_request',
  'block_cache',
  'bom_all_v',
  'bom_line_v',
  'bom_overhead_v',
  'bom_routing_line_v',
  'bom_routing_v',
  'cc_co_header',
  'cc_co_line',
  'cc_co_line_value',
  'cc_co_process_flow_action',
  'cc_co_process_flow_action_value',
  'cst_item_cost_sum_v',
  'cst_item_cost_v',
  'ec_cart',
  'ec_control',
  'ec_paid_order',
  'ec_payment_method',
  'ec_product',
  'extn_image',
  'extn_image_reference',
  'extn_rating_control',
  'extn_rating_values',
  'ef_calculated_power',
  'ef_grade',
  'ef_length',
  'ef_per_master_file',
  'ef_power_cable',
  'ef_serial_status',
  'fa_asset_component',
  'fa_asset_retirement',
  'fa_asset_trasaction',
  'fa_depreciation_header',
  'fa_depreciation_line',
  'fp_forecast_consumption',
  'fp_forecast_line',
  'fp_forecast_line_date',
  'fp_forecast_line_date_v',
  'fp_forecast_over_consumption_v',
  'fp_kanban_demand',
  'fp_kanban_demand_v',
  'fp_kanban_header',
  'fp_kanban_line',
  'fp_kanban_line_v',
  'fp_kanban_planner_header',
  'fp_kanban_suggestion_v',
  'fp_mds_line',
  'fp_minmax_demand',
  'fp_minmax_demand_v',
  'fp_minmax_header',
  'fp_minmax_line',
  'fp_minmax_suggestion_v',
  'fp_mrp_demand',
  'fp_mrp_demand_v',
  'fp_mrp_exception',
  'fp_mrp_existing_supply_v',
  'fp_mrp_lowlevel_code',
  'fp_mrp_planned_order',
  'fp_mrp_supply',
  'fp_mrp_v',
  'fp_source_list_header',
  'fp_source_list_line',
  'fp_urgent_card',
  'gl_balance_v',
  'gl_journal_header',
  'gl_journal_line',
  'gl_journal_line_v',
  'gl_ledger_balancing_values',
  'gl_unposted_balance_v',
  'gl_unposted_journal_lines_v',
  'hd_change_request',
  'hd_repair_type_line',
  'hd_sbp_header',
  'hd_sbp_line',
  'hd_service_activity_header',
  'hd_service_activity_line',
  'hd_service_contract_detail',
  'hd_service_contract_header',
  'hd_service_contract_line',
  'hd_service_contract_sched',
  'hd_service_request',
  'hd_support_request',
  'hd_svo_actuals',
  'hd_svo_estimates',
  'hd_svo_header',
  'hd_svo_line',
  'hr_employee_position_v',
  'hr_employee_v',
  'hr_payroll_process',
  'inv_count_abc_ref',
  'inv_count_entries',
  'inv_count_entries_v',
  'inv_count_header',
  'inv_count_schedule',
  'inv_interorg_receipt_header',
  'inv_intorg_transfer_header',
  'inv_intorg_transfer_line',
  'inv_interorg_transfer_v',
  'inv_item_relation',
  'inv_lot_number',
  'inv_lot_onhand',
  'inv_lot_transaction',
  'inv_lot_transaction_v',
  'inv_moveorder_header',
  'inv_moveorder_line',
  'inv_receipt_header',
  'inv_receipt_line',
  'inv_serial_number',
  'inv_serial_transaction',
  'inv_serial_transaction_v',
  'inv_transaction',
  'item_select_v',
  'locator_v',
  'mdm_bank_account_v',
  'mdm_bank_v',
  'onhand',
  'onhand_summary_v',
  'onhand_v',
  'org_v',
  'page',
  'po_all_v',
  'po_blanket_v',
  'po_convert_requisition_v',
  'po_detail',
  'po_document_v',
  'po_header',
  'po_line',
  'po_quote_detail',
  'po_quote_header',
  'po_quote_line',
  'po_requisition_all_v',
  'po_requisition_detail',
  'po_requisition_header',
  'po_requisition_interface',
  'po_requisition_line',
  'po_rfq_detail',
  'po_rfq_header',
  'po_rfq_line',
  'pos_transaction_header',
  'pos_transaction_line',
  'prj_agreement_header',
  'prj_agreement_line',
  'prj_budget_detail',
  'prj_budget_header',
  'prj_budget_line',
  'prj_expenditure_header',
  'prj_expenditure_line',
  'prj_project_all_lowesttask_v',
  'prj_project_all_v',
  'prj_project_control',
  'prj_project_header',
  'prj_project_line',
  'prj_project_member',
  'prj_project_type_billing',
  'prj_project_type_header',
  'prj_project_type_line',
  'prj_rate_schedule_header',
  'prj_rate_schedule_line',
  'prj_resource_list_header',
  'prj_resource_list_line',
  'sd_delivery_all_v',
  'sd_delivery_header',
  'sd_delivery_line',
  'sd_lead',
  'sd_opportunity',
  'sd_pick_list_v',
  'sd_quote_header',
  'sd_quote_line',
  'sd_sales_documents_v',
  'sd_so_all_v',
  'sd_so_header',
  'sd_so_line',
  'session',
  'sf_item_file1',
  'sf_item_image1',
  'sf_item_image2',
  'sf_item_inv_category',
  'sf_item_pur_category',
  'supplier_all_v',
  'sys_notification',
  'sys_pd_pflow_action_val',
  'sys_pflow_action_val',
  'sys_program',
  'sys_program_schedule',
  'sys_program_status',
  'sys_rfid_interface',
  'sys_spd_header',
  'sys_spd_process_flow_action',
  'wip_move_transaction',
  'wip_resource_transaction',
  'wip_wo_bom',
  'wip_wo_header',
  'wip_wo_routing_detail',
  'wip_wo_routing_line',
  'wip_wo_routing_v',
  'wip_wol_transaction',
  'pm_batch_header',
  'pm_process_operation_header',
  'pm_process_operation_detail',
  'pm_formula_byproduct',
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
   $this->message .= "<br>Convert to Prod program is Successfully completed";
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