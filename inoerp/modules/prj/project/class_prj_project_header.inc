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
 * Contains all the prj_project_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class prj_project_header extends dbObject {

 public static $table_name = "prj_project_header";
 public static $dependent_classes = ['prj_project_line', 'prj_project_member', 'prj_project_control'];
 public static $primary_column = "prj_project_header_id";
 public static $primary_column2 = "project_number";
 public static $key_column = 'prj_project_type_id';
 public static $module = "prj";
 public static $system_info = [
  'name' => 'Project',
  'number' => '6014',
  'description' => 'Create & Mainten Project',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('prj_project_line'),
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 1
 ];
 public $action_a = [
  'APPROVE' => 'Approve',
  'PRINT' => 'Print Estimates',
  'CANCEL' => 'Cancel',
  'CLOSE' => 'Close',
  'CREATE_WO' => 'Create Work Order',
  'COPY_ESTIMATES' => 'Copy Estimates to Actuals',
  'COPY_WO' => 'Copy WO Charges to Actuals',
  'PROCESS_LOGISTICS' => 'Process Logistics',
  'PROCESS_ACTUALS' => 'Process Actuals',
 ];
 public static $approval_status_a = [
  'ENTERED' => 'Entered',
  'APPROVED' => 'Approved',
  'REQ_APPROVAL' => 'Requires Re-Aproval',
  'REJECTED' => 'Rejected',
 ];
 public static $status_a = [
  'ENTERED' => 'Entered',
  'ACTIVE' => 'Active',
  'HOLD' => 'On Hold',
  'INVOICE_HOLD' => 'On Invoice Hold',
  'REVENUE_HOLD' => 'On Revenue Hold',
  'PENDING_CLOSURE' => 'Pending Closure',
  'CLOSED' => 'Closed',
 ];
 public $billing_method_a = [
  'CC' => 'Cost-Cost',
  'CW' => 'Cost-Work',
  'CE' => 'Cost-Event',
  'EE' => 'Event-Event',
  'EW' => 'Event-Work',
  'WW' => 'Work-Work',
  'WE' => 'Work-Event'
 ];
 public $field_a = [
  'prj_project_header_id',
  'bu_org_id',
  'prj_project_type_id',
  'project_number',
  'ar_customer_id',
  'ar_customer_site_id',
  'pm_employee_id',
  'description',
  'manager_user_id',
  'start_date',
  'completion_date',
  'header_amount',
  'project_class',
  'category',
  'finance_structure_cb',
  'operation_structure_cb',
  'life_cycle',
  'current_phase',
  'role_list_id',
  'prj_work_type',
  'probability',
  'opportunity_value',
  'currency',
  'doc_currency',
  'exchange_rate_type',
  'exchange_rate',
  'expected_approval_date',
  'billing_method',
  'billing_cycle',
  'prj_burden_list_header_id',
  'account_burdened_cost_cb',
  'labor_billing_type',
  'nlr_billing_type',
  'employee_schedule_id',
  'job_schedule_id',
  'l_revenue_burden_id',
  'l_invoice_burdern_id',
  'nlr_schedule_id',
  'nrl_revenue_burden_id',
  'nlr_invoice_burdern_id',
  'source',
  'name',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'direct_labor_cb',
  'is_template_cb',
  'project_status',
  'approval_status',
  'accounting_group',
  'rev_enabled_cb',
  'rev_number',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'prj_project_type_id',
  'project_number',
  'approval_status'
 ];
 public $requiredField = [
  'doc_currency',
  'bu_org_id',
  'prj_project_type_id',
  'prj_work_type',
  'accounting_group'
 ];
 public $addressField = [
  'ship_to_id',
  'bill_to_id'
 ];
 public $fields_inForm_notInDataBase = [
  'action',
  "customer_name",
  "customer_number",
  "customer_site_name",
  'pm_employee_name'
 ];
 public static $json_label_fields = [
  'bu_org_id',
  'project_number',
  'description',
  'manager_user_id',
  'start_date',
 ];
 public $profile_default = [
  'exchange_rate_type' => 'gl_currency_conversion_type',
  'bu_org_id' => 'org_bu_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//  '_extra_path' => array('form.php?class_name=ar_transaction_header&mode=9' => 'Invoice',
//   'form.php?class_name=sd_delivery_header&mode=9' => 'Ship')
 ];
 public $pageTitle = " Project "; //page Title
 public $prj_project_header_id;
 public $bu_org_id;
 public $prj_project_type_id;
 public $project_number;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $pm_employee_id;
 public $description;
 public $manager_user_id;
 public $start_date;
 public $completion_date;
 public $header_amount;
 public $project_class;
 public $category;
 public $finance_structure_cb;
 public $operation_structure_cb;
 public $life_cycle;
 public $currency;
 public $doc_currency;
 public $current_phase;
 public $exchange_rate_type;
 public $exchange_rate;
 public $role_list_id;
 public $prj_work_type;
 public $probability;
 public $opportunity_value;
 public $expected_approval_date;
 public $billing_method;
// public $invoice_accrual_method;
 public $billing_cycle;
 public $prj_burden_list_header_id;
 public $account_burdened_cost_cb;
 public $labor_billing_type;
 public $nlr_billing_type;
 public $employee_schedule_id;
 public $job_schedule_id;
 public $l_revenue_burden_id;
 public $l_invoice_burdern_id;
 public $nlr_schedule_id;
 public $nrl_revenue_burden_id;
 public $nlr_invoice_burdern_id;
 public $source;
 public $name;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $direct_labor_cb;
 public $is_template_cb;
 public $project_status;
 public $approval_status;
 public $accounting_group;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $customer_name;
 public $customer_number;
 public $customer_site_name;
 public $pm_employee_name;
 public $billing_cycle_id;

 public function _before_showing() {
  $address = new address();
  if (!empty($this->ship_to_id)) {
   $address_ship_to = $address->findBy_id($this->ship_to_id);
   $this->ship_to_address_name = $address_ship_to->address_name;
   $this->ship_to_address = $address_ship_to->address;
   $this->ship_to_country = $address_ship_to->country;
   $this->ship_to_postal_code = $address_ship_to->postal_code;
   $this->ship_to_phone = $address_ship_to->phone;
  }
  if (!empty($this->bill_to_id)) {
   $address_bill_to = $address->findBy_id($this->bill_to_id);
   $this->bill_to_address_name = $address_bill_to->address_name;
   $this->bill_to_address = $address_bill_to->address;
   $this->bill_to_country = $address_bill_to->country;
   $this->bill_to_postal_code = $address_bill_to->postal_code;
   $this->bill_to_phone = $address_bill_to->phone;
  }
 }

 private function _do_action() {

  switch ($this->action) {
   case 'APPROVE':
    $this->approval_status = 'APPROVED';
    break;

   default :
    echo $this->action;
    break;
  }
 }

 public function _before_save() {
  if (!empty($this->action)) {
   $this->_do_action();
  }

  if (empty($this->approval_status)) {
   $this->approval_status = 'ENTERED';
  }
 }

 public function _after_save() {
  if ((!empty($this->prj_project_header_id)) && empty($this->project_number)) {
   $prj_project_header_id = $this->prj_project_header_id;
   $bu_org_id = $this->bu_org_id;
   $prj_number = $bu_org_id . '-' . $prj_project_header_id;
   $this->project_number = $prj_number;
   echo '<br/> New Project number is ' . $prj_number;
   $this->update_svoNumber();
  }
 }

 private function update_svoNumber() {
  $sql = " UPDATE " . self::$table_name;
  $sql .= " SET project_number = '{$this->project_number}'  ";
  $sql .= " WHERE prj_project_header_id = '{$this->prj_project_header_id}'  ";
  try {
   $this->runSQL($sql);
  } catch (Exception $e) {
   echo "<br>SO Number update failed!" . $e->getMessage();
  }
 }

 public static function find_financial_details_from_projectHeaderId($prj_project_header_id) {
  $sql = " 
         SELECT org.org_id, org.legal_org_id, legal.ledger_id,
            gl.ledger, gl.description as ledger_description, gl.coa_id, gl.calendar_option_line_code, gl.currency_code, legal.balancing_segments,
            org.org, org.code,org.type, org.description as org_description, pph.prj_project_header_id, pph.project_number
            FROM org,
            legal,
            gl_ledger gl,
            prj_project_header pph
            WHERE org.legal_org_id = legal.org_id 
            AND gl.gl_ledger_id = legal.ledger_id
            AND org.org_id = pph.bu_org_id
            AND pph.prj_project_header_id = '{$prj_project_header_id}'
 "
  ;
$sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);

  return !empty($result) ? array_pop($result) : false;
 }

}

//end of prj_project_header class
?>