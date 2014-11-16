<?php

class gl_balance_v extends dbObject {

 public static $table_name = "gl_balance_v";
 public static $primary_column = "gl_journal_header_id";
 public $field_a = [
 ];
 public $initial_search = [
		 'period_name',
		 "coa_combination_id",
		 "combination",
		 "description",
		 "balance_type"
 ];
 public $column = [
		 'period_name',
		 "coa_combination_id",
		 "combination",
		 "period_net_dr",
		 "period_net_cr",
		 "begin_balance_dr",
		 "begin_balance_cr",
 ];
 public $dateField = [
 ];
 public $search = [
 ];
 public $pageTitle = " Balalnce - Find Account Balances "; //page Title
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

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public  function create_gl_balance_v() {
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
 balance_type, post_date,gl_period_id
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
	
	
		$sql = "
CREATE OR REPLACE VIEW gl_balance_v
(
period_name, gl_period_id, combination,description, 
gl_balance_id,ledger_id,coa_combination_id,
period_id, balance_type, period_net_dr,period_net_cr,
begin_balance_dr,begin_balance_cr, last_update_by, last_update_date,
field1, field2, field3,field4, field5, field6, field7, field8
)
AS
SELECT
gp.period_name, gp.gl_period_id, 
cc.combination,cc.description,
gb.gl_balance_id,gb.ledger_id,gb.coa_combination_id,
gb.period_id, gb.balance_type, gb.period_net_dr,gb.period_net_cr,
gb.begin_balance_dr,gb.begin_balance_cr, gb.last_update_by, gb.last_update_date,
cc.field1, cc.field2, cc.field3,
cc.field4, cc.field5, cc.field6, cc.field7, cc.field8

FROM gl_balance gb 
LEFT JOIN gl_period gp ON gp.gl_period_id = gb.period_id
LEFT JOIN coa_combination cc ON cc.coa_combination_id = gb.coa_combination_id
ORDER BY gp.gl_period_id DESC
";
 }

}

//end of po_detail class
?>