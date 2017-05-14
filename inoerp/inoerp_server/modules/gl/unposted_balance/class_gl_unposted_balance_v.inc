<?php

class gl_unposted_balance_v extends dbObject {

 public static $form_class_name = "fp_mrp_header";
 public static $table_name = "gl_unposted_balance_v";
 public static $primary_column = "gl_journal_header_id";
 public $field_a = [
  'combination',
  'code_combination_id',
  'period_name',
  'coa_id',
  'total_cr',
  'total_dr',
  'total_ac_dr',
  'total_ac_cr',
  'ledger_id',
  'description',
  'gl_journal_line_id',
  'gl_journal_header_id',
  'line_num',
  'line_type',
  'line_description',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'coa_structure_id',
  'field1',
  'field2',
  'field3',
  'field4',
  'field5',
  'field6',
  'field7',
  'field8',
  'balance_type',
  'post_date',
  'gl_period_id',
 ];
 public $initial_search = [
  'combination',
  'code_combination_id',
  'period_name',
  'coa_id',
 ];
 public $column = [
  'combination',
  'code_combination_id',
  'period_name',
  'coa_id',
  'total_cr',
  'total_dr',
  'total_ac_dr',
  'total_ac_cr',
  'ledger_id',
  'description',
 ];
 public $dateField = [
 ];
 public $search = [
 ];
 public $pageTitle = " Unposted Balances "; //page Title
 public $option_lists = [
//		 'po_type' => 'PO_TYPE',
//		 'po_status' => 'PO_STATUS',
 ];

 function __construct() {
  if (!empty(static::$table_name)) {
   $this->field_a = get_dbColumns(static::$table_name);
   foreach ($this->field_a as $key => $value) {
    $this->$value = '';
   }
  }
 }

 public function create_gl_unposted_balance_v() {
  $sql = "
CREATE OR REPLACE VIEW gl_unposted_balance_v
(
combination, code_combination_id, period_name,
coa_id, total_cr, total_dr,
total_ac_dr, total_ac_cr ,ledger_id,
description, gl_journal_line_id,
gl_journal_header_id, line_num, line_type, line_description,
reference_type, reference_key_name, reference_key_value , 
coa_structure_id, field1, field2, field3,
field4, field5, field6, field7, field8,
balance_type, post_date, gl_period_id
)
AS
SELECT  cc.combination, gjl.code_combination_id, gp.period_name,
cc.coa_id, sum(gjl.total_cr), sum(gjl.total_dr),
sum(gjl.total_ac_dr), sum(gjl.total_ac_cr) ,gjh.ledger_id,
cc.description, gjl.gl_journal_line_id,
gjl.gl_journal_header_id, gjl.line_num, gjl.line_type, gjl.description,
gjl.reference_type, gjl.reference_key_name, gjl.reference_key_value , 
cc.coa_structure_id, cc.field1, cc.field2, cc.field3,
cc.field4, cc.field5, cc.field6, cc.field7, cc.field8,
gjh.balance_type, gjh.post_date, gp.gl_period_id

FROM gl_journal_line gjl 
LEFT JOIN gl_journal_header gjh ON gjl.gl_journal_header_id = gjh.gl_journal_header_id
LEFT JOIN gl_period gp ON gp.gl_period_id = gjh.period_id
LEFT JOIN coa_combination cc ON gjl.code_combination_id=cc.coa_combination_id
WHERE gjl.status = 'U'
GROUP BY  gjl.code_combination_id

";
 }

}

//end of po_detail class
?>