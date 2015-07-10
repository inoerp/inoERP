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
 * prj_expenditure_header
 * Contains all the prj_expenditure_header information, such as - prj_expenditure_header, prj_expenditure_header_id, org_id,  type, etc.
 * 
 */
class prj_expenditure_header extends dbObject {

 public static $table_name = "prj_expenditure_header";
 public static $primary_column = "prj_expenditure_header_id";
 public static $key_column = 'expenditure_class';
 public static $dependent_classes = ['prj_expenditure_line'];
 public static $module = "prj";
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Project Expenditure',
  'number' => '2117',
  'description' => 'prj_expenditure_header',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 17
 ];
 public $action_a = [
  'RELEASE' => 'Release',
  'REVERSE' => 'Reverse'
 ];
 public static $status_a = [
  'WORKING' => 'Working',
  'RELEASED' => 'Released',
  'COSTED' => 'Costed',
  'REVERSED' => 'Reversed',
 ];
 public static $expenditure_class_a = [
  'TIMESHEET' => 'Time Sheet',
  'EXPENSE_REPORT' => 'Expense Report',
  'INV' => 'Inventory',
  'WIP' => 'WIP',
  'INVOICE' => 'Supplier Invoice',
  'BURDEN' => 'Burden',
  'USAGE' => 'Usage',
  'MISC' => 'Miscellaneous',
  'BURDEN' => 'Burden',
 ];
 public $field_a = [
  'prj_expenditure_header_id',
  'bu_org_id',
  'batch_name',
  'description',
  'expenditure_class',
  'effective_to',
  'status',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'submitted_by_user_id',
  'submitted_on',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'batch_name',
  'description',
 ];
 public $requiredField = [
  'bu_org_id',
  'expenditure_class',
 ];
 
  public $fields_inForm_notInDataBase = [
  'action',
 ];
  
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $search_functions = [
  'Organization' => 'search_org_name'
 ];
 public $profile_default = [
  'bu_org_id' => 'org_bu_name_default',
 ];
 public $pageTitle = " Expenditure Type"; //page Title
 public $prj_expenditure_header_id;
 public $bu_org_id;
 public $batch_name;
 public $description;
 public $expenditure_class;
 public $effective_to;
 public $status;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $submitted_by_user_id;
 public $submitted_on;
 public $misc_transaction_cb;
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
 public $action;

 public function _before_save() {
  if (!empty($this->status) && $this->status != 'WORKING') {
   if ($this->_verify_status() < 0) {
    return -90;
   }
  }
  if (!empty($this->action)) {
   $this->_do_action();
  }

  if (empty($this->status)) {
   $this->status = 'WORKING';
  }
 }

 private function _do_action() {
  switch ($this->action) {
   case 'RELEASE' :
    $this->status = 'RELEASED';
    break;

   default:
    break;
  }
  
 }

 private function _verify_status() {
  $return = 1;
  switch ($this->status) {
   case 'RELEASED' :
    if ($this->action_a != 'REVERSE') {
     echo "<br>You can only reverse a released expenditure";
     $return = -1;
    }
    break;

   case 'REVERSED' :
   case 'COSTED':
    echo "<br>You can't modify any expenditure in" . $this->status . " status";
    $return = -1;
    break;

   default:
    break;
  }
  return $return;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of prj_expenditure_header class
?>