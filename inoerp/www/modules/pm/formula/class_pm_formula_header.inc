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
 * Contains all the pm_formula_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class pm_formula_header extends dbObject {

 public static $table_name = "pm_formula_header";
 public static $dependent_classes = ['pm_formula_line', 'pm_formula_ingredient', 'pm_formula_byproduct'];
 public static $primary_column = "pm_formula_header_id";
 public static $key_column = 'formula_name';
 public static $module = "pm";
 public static $system_info = [
  'name' => 'Formula',
  'number' => '2804',
  'description' => 'Create & Mainten Formula',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('pm_formula_line', 'pm_formula_ingredient', 'pm_formula_byproduct'),
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
  'pm_formula_header_id',
  'org_id',
  'formula_name',
  'type',
  'revision',
  'comment',
  'status',
  'description',
  'owner_employee_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'formula_name',
  'type',
 ];
 public $requiredField = [
  'org_id',
  'formula_name',
 ];
 public $fields_inForm_notInDataBase = [
  'action',
  'pm_employee_name'
 ];
 public static $json_label_fields = [
  'formula_name',
  'description',
  'status',
  'type',
  'org_id',
 ];
 public $profile_default = [
  'org_id' => 'org_inv_name_default',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Formula "; //page Title
 public $pm_formula_header_id;
 public $org_id;
 public $formula_name;
 public $type;
 public $revision;
 public $comment;
 public $status;
 public $description;
 public $owner_employee_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $pm_employee_name;
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

 public static function find_financial_details_from_projectHeaderId($pm_formula_header_id) {
  $sql = " 
         SELECT org.org_id, org.legal_org_id, legal.ledger_id,
            gl.ledger, gl.description as ledger_description, gl.coa_id, gl.calendar_option_line_code, gl.currency_code, legal.balancing_segments,
            org.org, org.code,org.type, org.description as org_description, pph.pm_formula_header_id, pph.project_number
            FROM org,
            legal,
            gl_ledger gl,
            pm_formula_header pph
            WHERE org.legal_org_id = legal.org_id 
            AND gl.gl_ledger_id = legal.ledger_id
            AND org.org_id = pph.bu_org_id
            AND pph.pm_formula_header_id = '{$pm_formula_header_id}'
 " ;
            $sql = ino_perPageSql_i($sql, 1);

  $result = self::find_by_sql($sql);

  return !empty($result) ? array_pop($result) : false;
 }

}

//end of pm_formula_header class
?>