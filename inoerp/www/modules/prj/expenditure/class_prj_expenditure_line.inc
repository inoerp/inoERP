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
 * prj_expenditure_line
 *
 */
class prj_expenditure_line extends dbObject {

 public static $table_name = "prj_expenditure_line";
 public static $primary_column = "prj_expenditure_line_id";
 public static $parent_primary_column = "prj_expenditure_header_id";
 public static $key_column = "prj_expenditure_type_header_id";
 public static $module = "prj";
 public static $gl_journal_category = "PRJ_EXPENDITURE";
 public static $status_a = [
  'ENTERED' => 'Entered',
  'DISTRIBUTED' => 'Distributed',
 ];
 public $field_a = [
  'prj_expenditure_line_id',
  'prj_expenditure_header_id',
  'org_id',
  'hr_employee_id',
  'description',
  'job_id',
  'expenditure_date',
  'prj_project_header_id',
  'prj_project_line_id',
  'prj_nlr_header_id',
  'prj_expenditure_type_header_id',
  'uom_id',
  'quantity',
  'rate',
  'line_amount',
  'debit_ac_id',
  'credit_ac_id',
  'burden_amount',
  'gl_journal_header_id',
  'gl_journal_interface_cb',
  'invoiced_cb',
  'revene_calculated_cb',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'description',
  'gl_journal_header_id',
  'status'
 ];
 public $requiredField = [
  'prj_expenditure_header_id',
  'prj_expenditure_type_header_id',
  'quantity',
 ];
 public $fields_inForm_notInDataBase = [
  "employee_name",
  'project_number',
  "task_number",
  'action'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Expenditure Lines"; //page Title
 public $prj_expenditure_line_id;
 public $prj_expenditure_header_id;
 public $org_id;
 public $hr_employee_id;
 public $description;
 public $job_id;
 public $expenditure_date;
 public $status;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $prj_nlr_header_id;
 public $prj_expenditure_type_header_id;
 public $uom_id;
 public $quantity;
 public $rate;
 public $debit_ac_id;
 public $credit_ac_id;
 public $gl_journal_header_id;
 public $gl_journal_interface_cb;
 public $line_amount;
 public $burden_amount;
 public $invoiced_cb;
 public $revene_calculated_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $project_number;
 public $employee_name;
 public $task_number;
 public $status_f;
 public $action;

 public function _before_save() {
  if (empty($this->prj_project_line_id) || empty($this->status)) {
   $this->status = 'ENTERED';
  }
  if (empty($this->line_amount)) {
   $this->line_amount = empty($this->rate) ? $this->quantity : $this->quantity * $this->rate;
  }
  if ($this->action == 'create_accounting') {
//   pa($this);
   $this->_insert_gl_interface();
   return 10;
  }
 }

 public $doc_currency;
 public $exchange_type;
 public $exchange_rate;

 private function _insert_gl_interface() {
  global $dbc;
  $fin_details = prj_project_header::find_financial_details_from_projectHeaderId($this->prj_project_header_id);
  if (!$fin_details) {
   echo "<br>Finance details not found";
   if (!empty($debug)) {
    echo "<br> Error @ " . __FILE__ . ' @@ line ' . __LINE__ . $e->getMessage();
   }
  }
  $gl_int = new gl_journal_interface();
  $gl_int->ledger_id = $fin_details->ledger_id;
  $gl_int->status = 'ENTERED';
  $gl_int->currency = $fin_details->currency_code;

  if (!empty($this->doc_currency)) {
   $gl_int->doc_currency = $this->doc_currency;
   $gl_int->exchange_type = $this->exchange_type;
   $gl_int->exchange_rate = $this->exchange_rate;
  } else {
   $gl_int->doc_currency = $fin_details->currency_code;
   $gl_int->exchange_type = 'NA';
   $gl_int->exchange_rate = 1;
  }
  $gp = new gl_period();
  $gl_int->period_id = $gp->current_open_period($fin_details->ledger_id, 'OPEN')->gl_period_id;
  $gl_int->journal_source = self::$module;
  $gl_int->journal_category = self::$gl_journal_category;
  $gl_int->reference_type = 'table';
  $gl_int->reference_key_name = self::$table_name;
  $gl_int->reference_key_value = '-1';
  $gl_int->journal_name = $gl_int->journal_category . '-' . $gl_int->reference_key_value;
  $gl_int->description = $gl_int->journal_name . '-' . current_time();
  $gl_int->balance_type = 'A';
  $gl_int->reference_type = 'table';
  $gl_int->reference_key_name = 'prj_expenditure_line';
  $gl_int->reference_key_value = $this->prj_expenditure_line_id;
  $gl_int->gl_journal_interface_id = null;
  $gl_int->code_combination_id = $this->debit_ac_id;
  $gl_int->total_dr = $gl_int->total_ac_dr = $this->burden_amount + $this->line_amount;
  $gl_int->line_reference_key_name = 'prj_expenditure_line';
  $gl_int->line_reference_key_value = $this->prj_expenditure_line_id;
  $gl_int->line_status = 'N';
  try {
   $gl_int->save();
   $gl_int->gl_journal_interface_id = null;
   $gl_int->code_combination_id = $this->credit_ac_id;
   $gl_int->total_cr = $gl_int->total_ac_cr = $this->burden_amount + $this->line_amount;
   $gl_int->total_dr = $gl_int->total_ac_dr = null;
   $gl_int->save();
   $pel = new prj_expenditure_line();
   $pel->findBy_id($this->prj_expenditure_line_id);
   $pel->gl_journal_interface_cb = true;
   $pel->save();
  } catch (Exception $e) {
   echo "<br>Unable to insert interface lines. Error @ " . __FILE__ . ' @@ line ' . __LINE__ . $e->getMessage();
   $dbc->rollback = true;
  }
 }

 public static function find_burdenDetails_fromExpenditureLine($prj_expenditure_line_id) {
  $sql = " SELECT pel.prj_expenditure_line_id,   pel.prj_expenditure_header_id,   pel.org_id,
pel.prj_project_header_id,   pel.prj_project_line_id,   pel.prj_nlr_header_id,
pel.prj_expenditure_type_header_id,   pel.uom_id,   pel.quantity ,
pbse.prj_burden_structure_header_id, pbse.burden_cost_base_id, pbsc.burden_cost_code_id, pbll.bu_org_id, pbll.multiplier, 
pbll.burden_value, pbll.prj_burden_list_header_id

FROM prj_expenditure_line pel,
prj_burden_struct_exptype pbse,
prj_burden_struct_costcode pbsc,
prj_burden_list_line pbll,
prj_project_header pph,
prj_burden_list_header bplh

WHERE pbse.prj_expenditure_type_id = pel.prj_expenditure_type_header_id
AND pbse.prj_burden_structure_header_id =  pbsc.prj_burden_structure_header_id
AND pbse.burden_cost_base_id = pbsc.burden_cost_base_id
AND pbll.prj_burden_costcode_id = pbsc.burden_cost_code_id
AND pph.prj_project_header_id = pel.prj_project_header_id
AND pph.bu_org_id = pbll.bu_org_id
AND pph.prj_burden_list_header_id = pbll.prj_burden_list_header_id
AND bplh.prj_burden_list_header_id = pbll.prj_burden_list_header_id
AND bplh.prj_burden_structure_header_id =  pbsc.prj_burden_structure_header_id
AND pel.prj_expenditure_line_id = '{$prj_expenditure_line_id}' ";

//echo "<br>$sql";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_accountDetails_fromExpenditureLine($prj_expenditure_line_id) {
  $sql = " 
        SELECT pel.prj_expenditure_line_id,   pel.prj_expenditure_header_id,   pel.org_id,
        pel.prj_project_header_id,   pel.prj_project_line_id,   pel.prj_nlr_header_id,
        pel.prj_expenditure_type_header_id,   pel.uom_id,   pel.quantity ,
        peh.expenditure_class, pph.accounting_group, pph.prj_project_type_id,
        pda.document_type, pda.ac_id

        FROM prj_expenditure_line pel,
        prj_expenditure_header peh,
        prj_project_header pph,
        prj_default_account pda

        WHERE pel.prj_expenditure_header_id = peh.prj_expenditure_header_id
        AND pph.prj_project_header_id = pel.prj_project_header_id
        AND pda.accounting_group = pph.accounting_group 
        AND pda.prj_project_type_header_id = pph.prj_project_type_id 
        AND (pda.document_type = 'DEFAULT_EXPEN_CLEAR' || pda.document_type = 'DEFAULT_EXPEN' )
        AND pel.prj_expenditure_line_id = '{$prj_expenditure_line_id}'

        UNION
        SELECT pel.prj_expenditure_line_id,   pel.prj_expenditure_header_id,   pel.org_id,
        pel.prj_project_header_id,   pel.prj_project_line_id,   pel.prj_nlr_header_id,
        pel.prj_expenditure_type_header_id,   pel.uom_id,   pel.quantity ,
        peh.expenditure_class, pph.accounting_group, pph.prj_project_type_id,
        pda.document_type, pda.ac_id

        FROM prj_expenditure_line pel,
        prj_expenditure_header peh,
        prj_project_header pph,
        prj_default_account pda,
        option_line ol

        WHERE pel.prj_expenditure_header_id = peh.prj_expenditure_header_id
        AND pph.prj_project_header_id = pel.prj_project_header_id
        AND pda.accounting_group = pph.accounting_group 
        AND pda.prj_project_type_header_id = pph.prj_project_type_id 
        AND pda.accounting_group = pph.accounting_group 
        AND pda.prj_project_type_header_id = pph.prj_project_type_id 
        AND pda.document_type = ol.option_line_code
        AND ol.mapper1 = peh.expenditure_class
        AND pel.prj_expenditure_line_id = '{$prj_expenditure_line_id}'
";

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_headerId_Status($project_header_id, $status = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE  prj_project_header_id = '{$project_header_id}' ";
  if (!empty($status)) {
   $sql .= " AND  status = '{$status}' ";
  } else {
   $sql .= " AND ( status IS NULL || status = 'ENTERED' ) ";
  }

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_lines_forRevenueGeneration($project_header_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE  prj_project_header_id = '{$project_header_id}' ";
  $sql .= " AND  status = 'DISTRIBUTED' ";
  $sql .= " AND  revene_calculated_cb IS NULL ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }
 
  public static function find_lines_forInvoiceGeneration($project_header_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE  prj_project_header_id = '{$project_header_id}' ";
  $sql .= " AND  status = 'DISTRIBUTED' ";
  $sql .= " AND  invoiced_cb IS NULL ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_totalExpenditure_by_projectHeaderId($project_header_id) {
  $sql = " SELECT SUM(line_amount) as line_amount, SUM(burden_amount) as burden_amount, prj_project_header_id FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE  prj_project_header_id = '{$project_header_id}' ";
  $sql .= " AND  status = 'DISTRIBUTED' ";
  $sql .= " GROUP BY prj_project_header_id ";

  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_billRates_fromLineIdSchedule($prj_expenditure_line_id, $emp_schedule_id, $job_schedule_id,$nlr_schedule_id) {
  $sql = " SELECT 
pel.prj_expenditure_line_id,pel.line_amount,pel.burden_amount, pel.quantity,
pel.line_amount,(IFNULL(pel.burden_amount,0) + pel.line_amount) as total_expn_amount,
(
    CASE 
    WHEN pel.hr_employee_id IS NOT NULL 
	THEN 	(SELECT rate
    FROM prj_rate_schedule_line prsl
    WHERE prsl.prj_rate_schedule_header_id = '{$emp_schedule_id}'
    AND reference_key_name = 'EMPLOYEE')
    
	WHEN pel.job_id IS NOT NULL &&  pel.hr_employee_id IS NULL 
    THEN 	(SELECT rate
    FROM prj_rate_schedule_line prsl
    WHERE prsl.prj_rate_schedule_header_id = '{$job_schedule_id}'
    AND reference_key_name = 'JOB')
	
    ELSE ( 
	SELECT rate
    FROM prj_rate_schedule_line prsl
    WHERE prsl.prj_rate_schedule_header_id = '{$nlr_schedule_id}'
    AND reference_key_name = 'NON_LABOR'
	)
    END
 ) as rate,
 (
    CASE 
    WHEN pel.hr_employee_id IS NOT NULL 
    THEN 	(SELECT mark_up_percentage
    FROM prj_rate_schedule_line prsl
    WHERE prsl.prj_rate_schedule_header_id = '{$emp_schedule_id}'
    AND reference_key_name = 'EMPLOYEE')
	
	WHEN pel.job_id IS NOT NULL &&  pel.hr_employee_id IS NULL 
    THEN 	(SELECT mark_up_percentage
    FROM prj_rate_schedule_line prsl
    WHERE prsl.prj_rate_schedule_header_id = '{$job_schedule_id}'
    AND reference_key_name = 'JOB')
	
    ELSE ( 
	SELECT mark_up_percentage
    FROM prj_rate_schedule_line prsl
    WHERE prsl.prj_rate_schedule_header_id = '{$nlr_schedule_id}'
    AND reference_key_name = 'NON_LABOR'
	)
    END
 ) as mark_up_percentage

FROM 
prj_expenditure_line pel
WHERE pel.prj_expenditure_line_id = '{$prj_expenditure_line_id}' 
";
$sql = ino_perPageSql_i($sql, 1);

  $result = self::find_by_sql($sql);

  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_distinctProject_byStatus($status = '') {
  $sql = " SELECT DISTINCT(prj_project_header_id) FROM ";
  $sql .= self::$table_name;
  if (!empty($status)) {
   $sql .= " WHERE  status = '{$status}' ";
  } else {
   $sql .= " WHERE ( status IS NULL || status = 'ENTERED' ) ";
  }

//  echo $sql;
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'action_class_name',
   'mode',
   'action',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of path class
?>
