<?php

class gl_journal_line_v extends dbObject {

 public static $table_name = "gl_journal_line_v";
 public $field_a = [
  'combination',
  'code_combination_id',
  'period_name',
  'total_cr',
  'total_dr',
  'total_ac_dr',
  'total_ac_cr',
  'coa_id',
  'ledger_id',
  'combination_description',
  'gl_journal_line_id',
  'status',
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
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
  'reference_key_value_h',
  'reference_key_name_h'
 ];
 public $initial_search = [
  'combination',
  "reference_key_name",
  'reference_key_value ',
 ];
 public $dateField = [
 ];
 public $search_functions = [
  'Period Name' => 'search_gl_period_name',
  'Legal Org' => 'search_legal_org_name'
 ];
 public $pageTitle = " GL Journals - Find All  Journal Lines "; //page Title
 public $option_lists = [
//		 'po_type' => 'PO_TYPE',
//		 'po_status' => 'PO_STATUS',
 ];
 public $combination;
 public $code_combination_id;
 public $period_name;
 public $total_cr;
 public $total_dr;
 public $total_ac_dr;
 public $total_ac_cr;
 public $coa_id;
 public $ledger_id;
 public $combination_description;
 public $gl_journal_line_id;
 public $status;
 public $gl_journal_header_id;
 public $line_num;
 public $line_type;
 public $line_description;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $coa_structure_id;
 public $field1;
 public $field2;
 public $field3;
 public $field4;
 public $field5;
 public $field6;
 public $field7;
 public $field8;
 public $balance_type;
 public $post_date;
 public $gl_period_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $reference_key_value_h;
 public $reference_key_name_h;

 public function create_gl_journal_line_v() {
  $SQL = "SELECT  cc.combination, gjl.code_combination_id,
cc.coa_id, sum(gjl.total_cr), sum(gjl.total_dr),
sum(gjl.total_ac_dr), sum(gjl.total_ac_cr) ,
cc.description, gjl.gl_journal_line_id,
gjl.gl_journal_header_id, gjl.line_num, gjl.line_type, gjl.description,
gjl.reference_type, gjl.reference_key_name, gjl.reference_key_value , 
cc.coa_structure_id, cc.field1, cc.field2, cc.field3,
cc.field4, cc.field5, cc.field6, cc.field7, cc.field8,
gjh.gl_journal_header_id, gjh.period_name, gjh.balance_type, gjh.post_date

FROM gl_journal_line gjl 
LEFT JOIN gl_journal_header gjh ON gjl.gl_journal_header_id = gjh.gl_journal_header_id
LEFT JOIN coa_combination cc ON gjl.code_combination_id=cc.coa_combination_id
group by gjl.code_combination_id";

  $sql = "
CREATE OR REPLACE VIEW gl_unposted_journal_lines_v
(
combination, code_combination_id, period_name,
coa_id, sum_total_cr, sum_total_dr,
sum_total_ac_dr, sum_total_ac_cr , ledger_id,
combination_description, gl_journal_line_id, status,
gl_journal_header_id, line_num, line_type, line_description,
reference_type, reference_key_name, reference_key_value , 
coa_structure_id, field1, field2, field3,
field4, field5, field6, field7, field8,
 balance_type, post_date,gl_period_id, 
 created_by, creation_date, last_update_by, last_update_date,
 reference_key_name_h, reference_key_value_h
)
AS
SELECT  cc.combination, gjl.code_combination_id, gp.period_name,
cc.coa_id, sum(gjl.total_cr), sum(gjl.total_dr),
sum(gjl.total_ac_dr), sum(gjl.total_ac_cr) ,gjh.ledger_id,
cc.description, gjl.gl_journal_line_id, gjl.status,
gjl.gl_journal_header_id, gjl.line_num, gjl.line_type, gjl.description,
gjl.reference_type, gjl.reference_key_name, gjl.reference_key_value , 
cc.coa_structure_id, cc.field1, cc.field2, cc.field3,
cc.field4, cc.field5, cc.field6, cc.field7, cc.field8,
gjh.balance_type, gjh.post_date, gp.gl_period_id,
gjl.created_by, gjl.creation_date, gjl.last_update_by, gjl.last_update_date,
gjh.reference_key_name as reference_key_name_h, gjh.reference_key_value as reference_key_value_h

FROM gl_journal_line gjl 
LEFT JOIN gl_journal_header gjh ON gjl.gl_journal_header_id = gjh.gl_journal_header_id
LEFT JOIN gl_period gp ON gp.gl_period_id = gjh.period_id
LEFT JOIN coa_combination cc ON gjl.code_combination_id=cc.coa_combination_id
GROUP BY  gjl.code_combination_id
";


  $sql = "
CREATE OR REPLACE VIEW gl_journal_line_v
(
combination, code_combination_id, period_name, total_cr, total_dr, total_ac_dr, total_ac_cr,
coa_id, ledger_id, combination_description, gl_journal_line_id, status,
gl_journal_header_id, line_num, line_type, line_description,
reference_type, reference_key_name, reference_key_value , 
coa_structure_id, field1, field2, field3,
field4, field5, field6, field7, field8,
 balance_type, post_date,gl_period_id,
 created_by, creation_date, last_update_by, last_update_date,
 reference_key_name_h, reference_key_value_h
)
AS
SELECT  cc.combination, gjl.code_combination_id, gp.period_name,
gjl.total_cr, gjl.total_dr, gjl.total_ac_dr, gjl.total_ac_cr,
cc.coa_id, gjh.ledger_id, cc.description, gjl.gl_journal_line_id, gjl.status,
gjl.gl_journal_header_id, gjl.line_num, gjl.line_type, gjl.description,
gjl.reference_type, gjl.reference_key_name, gjl.reference_key_value , 
cc.coa_structure_id, cc.field1, cc.field2, cc.field3,
cc.field4, cc.field5, cc.field6, cc.field7, cc.field8,
gjh.balance_type, gjh.post_date, gp.gl_period_id,
gjl.created_by, gjl.creation_date, gjl.last_update_by, gjl.last_update_date,
gjh.reference_key_name as reference_key_name_h, gjh.reference_key_value as reference_key_value_h

FROM gl_journal_line gjl 
LEFT JOIN gl_journal_header gjh ON gjl.gl_journal_header_id = gjh.gl_journal_header_id
LEFT JOIN gl_period gp ON gp.gl_period_id = gjh.period_id
LEFT JOIN coa_combination cc ON gjl.code_combination_id=cc.coa_combination_id
ORDER BY gp.gl_period_id DESC, cc.combination DESC
";
 }

 public static function find_by_referenceDetails($ref_key_name, $ref_key_value, $account_type = 'all') {

  $sql = " SELECT * FROM gl_journal_line_v ";
  $sql .= " WHERE  reference_key_name_h = '{$ref_key_name}' AND reference_key_value_h = '{$ref_key_value}' ";
  if ($account_type == 'dr') {
   $sql .= " AND  total_ac_dr IS NOT NULL ";
  } else if ($account_type == 'cr') {
   $sql .= " AND  total_ac_cr IS NOT NULL ";
  }

  
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of po_detail class
?>