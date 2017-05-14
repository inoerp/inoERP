<?php

class prj_expenditure_line_v extends dbObject {

 public static $table_name = "prj_expenditure_line_v";
 public static $form_class_name = "prj_expenditure_line";
 public static $primary_column = "prj_expenditure_line_id";
 public $field_a = [
  'prj_expenditure_line_id',
  'prj_expenditure_header_id',
  'status',
  'project_number',
  'bu_org_id',
  'task_number',
  'debit_ac_id',
  'credit_ac_id',
  'burden_amount',
  'gl_journal_header_id',
  'gl_journal_interface_cb',
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
 ];
 public $initial_search = [
  'project_number',
   'task_number',
  'prj_expenditure_line_id',
  'gl_journal_interface_cb',
  'status',
 ];
 public $search = [
  '_view_path' => 'form.php?class_name=prj_expenditure_line',
  '_show_view_path' => 1,
 ];
   public $search_functions = [
  'Business Org' => 'search_business_org',
 ];
 public $pageTitle = " Burden Expenditure "; //page Title
 public $prj_expenditure_line_id;
 public $prj_expenditure_header_id;
 public $org_id;
 public $hr_employee_id;
 public $description;
 public $job_id;
 public $expenditure_date;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $prj_nlr_header_id;
 public $prj_expenditure_type_header_id;
 public $uom_id;
 public $quantity;
 public $rate;
 public $debit_ac_id;
 public $credit_ac_id;
 public $burden_amount;
 public $gl_journal_header_id;
 public $gl_journal_interface_cb;
 public $status;
 public $project_number;
 public $bu_org_id;
 public $task_number;

 private function create_prj_expenditure_line_v() {
  $sql = "
CREATE OR REPLACE VIEW prj_expenditure_line_v
(
prj_expenditure_line_id, prj_expenditure_header_id,  org_id,
hr_employee_id, description, job_id, expenditure_date,
prj_project_header_id, prj_project_line_id, prj_nlr_header_id,
prj_expenditure_type_header_id, uom_id, quantity, rate,
debit_ac_id, credit_ac_id, burden_amount, gl_journal_header_id, gl_journal_interface_cb,
status, project_number, bu_org_id, task_number
)
AS
SELECT
pel.prj_expenditure_line_id, pel.prj_expenditure_header_id,  pel.org_id,
pel.hr_employee_id, pel.description, pel.job_id, pel.expenditure_date,
pel.prj_project_header_id, pel.prj_project_line_id, pel.prj_nlr_header_id,
pel.prj_expenditure_type_header_id, pel.uom_id, pel.quantity, pel.rate,
pel.debit_ac_id, pel.credit_ac_id, pel.burden_amount, pel.gl_journal_header_id, pel.gl_journal_interface_cb,
pel.status, pph.project_number, pph.bu_org_id, ppl.task_number

FROM prj_expenditure_line pel,
prj_project_line ppl,
prj_project_header pph

WHERE pel.prj_project_header_id = pph.prj_project_header_id
AND pel.prj_project_line_id = ppl.prj_project_line_id

";
 }

 public function findBY_soLineId($line_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE hd_ro_line_id = :hd_ro_line_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $value_a = ['hd_ro_line_id' => $line_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of so_detail class
?>