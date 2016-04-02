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
 * Contains all the pm_batch_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class pm_batch_header extends dbObject {

 public static $table_name = "pm_batch_header";
 public static $dependent_classes = ['pm_batch_line', 'pm_batch_ingredient', 'pm_batch_byproduct'];
 public static $primary_column = "pm_batch_header_id";
 public static $key_column = 'batch_name';
 public static $module = "pm";
 public static $system_info = [
  'name' => 'batch',
  'number' => '6214',
  'description' => 'Create & Mainten Process Batch',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('pm_batch_line', 'pm_batch_ingredient', 'pm_batch_byproduct'),
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
  'pm_batch_header_id',
  'batch_name',
  'org_id',
  'pm_recipe_header_id',
  'cost_batch_id',
  'recipe_version',
  'comment',
  'status',
  'description',
  'terminate_reason',
  'planned_start_date',
  'planned_completion_date',
  'required_completion_date',
  'actual_completion_date',
  'actual_start_date',
  'update_invnetory_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'batch_name',
  'description',
 ];
 public $requiredField = [
  'batch_name',
  'org_id',
  'pm_recipe_header_id',
 ];
 public static $json_label_fields = [
  'batch_name',
  'description',
  'status',
  'org_id',
 ];
 public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Production Batch "; //page Title
public $pm_batch_header_id;
public $org_id;
public $batch_name;
public $pm_recipe_header_id;
public $cost_batch_id;
public $recipe_version;
public $comment;
public $status;
public $description;
public $terminate_reason;
public $planned_start_date;
public $planned_completion_date;
public $required_completion_date;
public $actual_completion_date;
public $actual_start_date;
public $update_invnetory_cb;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;

 public $action;

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

 public static function find_financial_details_from_projectHeaderId($pm_batch_header_id) {
  $sql = " 
         SELECT org.org_id, org.legal_org_id, legal.ledger_id,
            gl.ledger, gl.description as ledger_description, gl.coa_id, gl.calendar_option_line_code, gl.currency_code, legal.balancing_segments,
            org.org, org.code,org.type, org.description as org_description, pph.pm_batch_header_id, pph.project_number
            FROM org,
            legal,
            gl_ledger gl,
            pm_batch_header pph
            WHERE org.legal_org_id = legal.org_id 
            AND gl.gl_ledger_id = legal.ledger_id
            AND org.org_id = pph.bu_org_id
            AND pph.pm_batch_header_id = '{$pm_batch_header_id}'
           LIMIT 1
 "
  ;

  $result = self::find_by_sql($sql);

  return !empty($result) ? array_pop($result) : false;
 }

}

//end of pm_batch_header class
?>