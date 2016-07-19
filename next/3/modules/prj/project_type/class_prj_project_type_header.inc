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
 * hd_ro_header CLass
 * Contains all the prj_project_type_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class prj_project_type_header extends dbObject {

 public static $table_name = "prj_project_type_header";
 public static $dependent_classes = ['prj_project_type_line', 'prj_project_type_billing'];
 public static $primary_column = "prj_project_type_header_id";
 public static $key_column = 'project_type';
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Project Type',
  'number' => '6015',
  'description' => 'Create & Mainten Project Type',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('prj_project_type_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];
 public $action_a = [
  'APPROVE' => 'Approve',
  'PRINT' => 'Print billing',
  'CANCEL' => 'Cancel',
  'CLOSE' => 'Close',
  'CREATE_WO' => 'Create Work Order',
  'COPY_billing' => 'Copy billing to Actuals',
  'COPY_WO' => 'Copy WO Charges to Actuals',
  'PROCESS_LOGISTICS' => 'Process Logistics',
  'PROCESS_ACTUALS' => 'Process Actuals',
 ];
 public static $project_class_a = [
  'INDIRECT' => 'Indirect',
  'CAPITAL' => 'Capital',
  'CONTRACT' => 'Contract',
 ];
 public static $schedule_type_a = [
  'SCHEDULE' => 'Schedule Rate',
  'BURDEN' => 'Burden Rate',
 ];
 public $field_a = [
  'prj_project_type_header_id',
  'bu_org_id',
  'project_class',
  'project_type',
  'description',
  'effective_from',
  'effective_to',
  'service_type',
  'role_list_id',
  'prj_work_type_id',
  'sponsored_cb',
  'organization_planning_cb',
  'intercompany_billing_cb',
  'prj_burden_list_header_id',
  'cost_burdened_cb',
  'account_burdened_cost_cb',
  'cost_budget_method',
  'revenue_budget_method',
  'resource_list_id',
  'project_status',
  'cip_cost_type',
  'asset_cost_allocation_method',
  'event_processing_method',
  'grouping_method',
  'labor_billing_type',
  'nlr_billing_type',
  'employee_schedule_id',
  'job_schedule_id',
  'l_revenue_burden_id',
  'l_invoice_burdern_id',
  'nlr_schedule_id',
  'nrl_revenue_burden_id',
  'nlr_invoice_burdern_id',
  'billing_cycle_id',
  'cost_cost_cb',
  'cost_event_cb',
  'cost_work_cb',
  'event_event_cb',
  'event_work_cb',
  'work_event_cb',
  'work_work_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'project_class',
  'project_type',
  'description',
 ];
 public $requiredField = [
  'project_class',
  'project_type',
 ];
 public $fields_inForm_notInDataBase = [
  'action',
 ];
 public $profile_default = [
  'bu_org_id' => 'org_bu_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//  '_extra_path' => array('form.php?class_name=ar_transaction_header&mode=9' => 'Invoice',
//   'form.php?class_name=sd_delivery_header&mode=9' => 'Ship')
 ];
 public $pageTitle = " Project Type "; //page Title
 public $prj_project_type_header_id;
 public $bu_org_id;
 public $project_class;
 public $project_type;
 public $description;
 public $effective_from;
 public $effective_to;
 public $service_type;
 public $role_list_id;
 public $prj_work_type_id;
 public $sponsored_cb;
 public $organization_planning_cb;
 public $intercompany_billing_cb;
 public $prj_burden_list_header_id;
 public $cost_burdened_cb;
 public $account_burdened_cost_cb;
 public $cost_budget_method;
 public $revenue_budget_method;
 public $resource_list_id;
 public $project_status;
 public $cip_cost_type;
 public $asset_cost_allocation_method;
 public $event_processing_method;
 public $grouping_method;
 public $labor_billing_type;
 public $nlr_billing_type;
 public $employee_schedule_id;
 public $job_schedule_id;
 public $l_revenue_burden_id;
 public $l_invoice_burdern_id;
 public $nlr_schedule_id;
 public $nrl_revenue_burden_id;
 public $nlr_invoice_burdern_id;
 public $billing_cycle_id;
 public $cost_cost_cb;
 public $cost_event_cb;
 public $cost_work_cb;
 public $event_event_cb;
 public $event_work_cb;
 public $work_event_cb;
 public $work_work_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $item_number;
 public $item_description;
 public $serial_number;
 public $lot_number;
 public $add_to_order;

 Public static function so_types() {
  $option_header = option_header::find_by_name('SO_TYPE');
  $so_types = option_line::find_by_option_id($option_header->option_header_id);
  return $so_types;
 }

 
 
 
}

//end of prj_project_type_header class
?>