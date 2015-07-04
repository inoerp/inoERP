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
  'number' => '2301',
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
  'revenue_accrual_method',
  'invoice_accrual_method',
  'billing_cycle',
  'cost_burden_schedule_id',
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
 ];
 public $requiredField = [
  'doc_currency',
  'bu_org_id',
  'prj_project_type_id',
  'prj_work_type',
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
 public $revenue_accrual_method;
 public $invoice_accrual_method;
 public $billing_cycle;
 public $cost_burden_schedule_id;
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
   case 'COPY_ESTIMATES':
    $this->copy_estimates();
    break;

   case 'PROCESS_ACTUALS':
    $this->copy_estimates();
    break;

   case 'PROCESS_LOGISTICS':
    $this->_process_logistics();
    break;

   default :
    break;
  }
 }

 public function _before_save() {
  if (!empty($this->action)) {
   $this->_do_action();
  }

  if (empty($this->so_status)) {
   $this->so_status = 'ENTERED';
  }
 }

 public function copy_estimates() {
  /* 1. Find all lines not copied - status PENDING_IMPORT.
   * 2. Copy all estimates to actuals
   * 3. Change all the estimate line status to IMPORTED.
   */
  if (empty($this->prj_project_header_id)) {
   return -1;
  }
  $all_estimates_lines = prj_project_estimates::find_by_headerId_and_status($this->prj_project_header_id);
  if ($all_estimates_lines) {
   foreach ($all_estimates_lines as $k => $estimates_line) {
    $new_actuals = new prj_project_actuals();
    foreach ($new_actuals->field_a as $k_a => $v_a) {
     if ((property_exists($estimates_line, $v_a)) && !empty($estimates_line->$v_a)) {
      $new_actuals->$v_a = $estimates_line->$v_a;
     }
    }
    $new_actuals->created_by = $new_actuals->creation_date = null;
    $new_actuals->source = 'ESTIMATES';
    $new_actuals->line_status = 'PENDING_IMPORT';
    try {
     $new_actuals->save();
     $estimate = new prj_project_estimates();
     $estimate->findBy_id($estimates_line->prj_project_estimates_id);
     $estimate->line_status = 'IMPORTED';
     $estimate->save();
    } catch (Exception $e) {
     echo "<br>Unable to import estimates to actuals. Error @ line " . __LINE__ . ' of file ' . __FILE__ . '<br>' . $e->getMessage();
    }
   }
  }
 }

 private function _process_logistics() {
  /* 1. Check if primary_Sd_so_header exists ? if not create a new sales order header
   * 2. Find all lines not imported - status PENDING_IMPORT & empty sd_so_line.
   * 2. Add all the lines to the sales order header
   * 3. Update the line status, sd_so_header_id and sd_so_line_id status 
   */

  $all_logistics_lines = prj_project_line::find_by_headerId_and_status($this->prj_project_header_id);
  if ($all_logistics_lines) {
   $ser_act_lines = hd_service_activity_line::find_by_headerId_and_buOrgId($all_logistics_lines[0]->service_activity_header_id, $this->bu_org_id);
   if ($ser_act_lines) {
    $this->_so_header_document_type = $ser_act_lines->header_type_id;
   }
  }

  if (empty($this->primary_sd_so_header_id) && !empty($this->_so_header_document_type)) {
   $this->_create_so_header();
  }
  if (empty($this->primary_sd_so_header_id)) {
   return false;
  }
  if ($all_logistics_lines) {
   $so_line_num = 0;
   foreach ($all_logistics_lines as $k => $logistics_line) {
    $so_line_num++;
    if (!empty($logistics_line->sd_so_line_id)) {
     continue;
    }
    $ser_act_line = hd_service_activity_line::find_by_headerId_and_buOrgId($logistics_line->service_activity_header_id, $this->bu_org_id);
    $so_line = new sd_so_line();
    foreach ($so_line->field_a as $k_a => $v_a) {
     if ((property_exists($logistics_line, $v_a)) && !empty($logistics_line->$v_a)) {
      $so_line->$v_a = $logistics_line->$v_a;
     }
    }
    $so_line->sd_so_header_id = $this->primary_sd_so_header_id;
    $so_line->line_status = 'ENTERED';
    $so_line->line_type = $ser_act_line->line_type_id;
    $so_line->shipping_org_id = $logistics_line->inv_org_id;
    $so_line->item_description = item::find_by_item_id_m($so_line->item_id_m)->item_description;
    try {
     if (method_exists($so_line, '_before_save')) {
      $so_line->_before_save();
     }
     $so_line->save();
     if (method_exists($so_line, '_after_save')) {
      $so_line->_after_save();
     }
     $sv_line = new prj_project_line();
     $sv_line->findBy_id($logistics_line->prj_project_line_id);
     $sv_line->sd_so_header_id = $so_line->sd_so_header_id;
     $sv_line->sd_so_line_id = $so_line->sd_so_line_id;
     $sv_line->line_status = 'IMPORTED';
     $sv_line->save();
//     pa($so_line);
//     pa($sv_line);
    } catch (Exception $e) {
     echo "<br>Unable to import estimates to logistic lines. Error @ line " . __LINE__ . ' of file ' . __FILE__ . '<br>' . $e->getMessage();
    }
   }
  }
 }

 public function _after_save() {
  if ((!empty($this->prj_project_header_id)) && empty($this->order_number)) {
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

 private function _create_so_header() {
  global $dbc;
  $sd_so_h = new sd_so_header();
  $sd_so_h->bu_org_id = $this->bu_org_id;
  $sd_so_h->order_source_type = 'SERVICE';
  $sd_so_h->document_type = $this->_so_header_document_type;
  $sd_so_h->doc_currency = $this->doc_currency;
  $sd_so_h->currency = $this->currency;
  $sd_so_h->exchange_rate_type = $this->exchange_rate_type;
  $sd_so_h->exchange_rate = $this->exchange_rate;
  $sd_so_h->ar_customer_id = $this->ar_customer_id;
  $sd_so_h->bill_to_id = $this->bill_to_id;
  $sd_so_h->ship_to_id = $this->ship_to_id;
  $sd_so_h->ar_customer_site_id = $this->ar_customer_site_id;
  $sd_so_h->payment_term_id = $this->payment_term_id;
  $sd_so_h->payment_term_date = $this->payment_term_date;
  $sd_so_h->order_reference_table = 'hd_sv_header';
  $sd_so_h->order_reference_id = $this->prj_project_header_id;
  try {
   if (method_exists($sd_so_h, '_before_save')) {
    $sd_so_h->_before_save();
   }
   $sd_so_h->save();
   if (method_exists($sd_so_h, '_after_save')) {
    $sd_so_h->_after_save();
   }
   $this->primary_sd_so_header_id = $sd_so_h->sd_so_header_id;
   $this->save();
  } catch (Exception $e) {
   echo "<br>Unable to create SO Header. Error @ line " . __LINE__ . " in file " . __FILE__ . '<br>' . $e->getMessage();
   $dbc->rollback = true;
  }
 }

 private function _pick_sales_order() {
  
 }

// public function save() {
//	$primary_column = static::$primary_column;
//	if (empty($this->$primary_column)) {
//	 $this->approval_status = 'Entered';
//	 $this->create();
//	} else {
//	 $this->update($this->$primary_column);
//	}
//	return $this->msg;
// }
}

//end of prj_project_header class
?>