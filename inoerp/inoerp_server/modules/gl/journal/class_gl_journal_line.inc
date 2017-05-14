<?php

class gl_journal_line extends dbObject {

 public static $table_name = "gl_journal_line";
 public static $primary_column = "gl_journal_line_id";
 public static $parent_primary_column = "gl_journal_header_id";
 public static $query_order_by_field = "line_num";
 public static $query_order_by_value = "ASC";
 public static $key_column = 'code_combination_id';
 public static $module = "gl";
 public $checkbox = [
  "rev_enabled_cb"
 ];
 public $field_a = [
  'gl_journal_line_id',
  'gl_journal_header_id',
  'line_num',
  'status',
  'line_type',
  'description',
  'code_combination_id',
  'total_dr',
  'total_cr',
  'total_ac_dr',
  'total_ac_cr',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'ef_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'gl_journal_line_id',
  'gl_journal_header_id',
  'line_type',
  'description',
  'period_id',
  'code_combination_id',
 ];
 public $column = [
  'gl_journal_line_id',
  'gl_journal_header_id',
  'line_type',
  'description',
  'period_id',
  'code_combination_id'
 ];
 public $account = [
  'code_combination_id'
 ];
 public $numberField = [
  'total_cr',
  'total_dr',
  'total_ac_dr',
  'total_ac_cr',
 ];
 public $requiredField = [
  'gl_journal_header_id',
  'line_num',
  'code_combination_id'
 ];
 public $fields_inForm_notInDataBase = [
  'ledger_id'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "gl_journal_header_id"
 ];
 public $gl_journal_line_id;
 public $gl_journal_header_id;
 public $line_num;
 public $status;
 public $line_type;
 public $description;
 public $code_combination_id;
 public $total_cr;
 public $total_dr;
 public $total_ac_dr;
 public $total_ac_cr;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $ledger_id;

 public function _before_massupload($record, $columns) {
  foreach ($columns as $k => $v) {
   if ($v == 'code_combination_id') {
    $comb = $record[$k];
    $coa_data = coa_combination::find_by_exactCombination($comb);
    if ($coa_data) {
     $record[$k] = $coa_data->coa_combination_id;
    } else {
     $record[$k] = null;
    }
   }
  }
//  pa($record);
  return $record;
 }

 public function _before_save() {
  if (empty($this->status)) {
   $this->status = 'U';
  }
  if ((isset($this->status)) && ($this->status == 'P')) {
   echo " You can't modify this Journal Line as its already posted. <br>"
   . " You can only reverse the Journal Header. ";
   return -99;
  } elseif (!empty($this->gl_journal_line_id)) { //required if user click post twice
   $gjl_id = $this->gl_journal_line_id;
   $gjl = new gl_journal_line;
   $gjl_inDb = $gjl->findBy_id($gjl_id);
   if ($gjl_inDb->status == 'P') {
    return -90;
   }
  }
 }

 public function _after_save() {
  
 }

 public function post_all_lines() {
  $journal_headerid = $this->gl_journal_header_id;
  $gjh = new gl_journal_header();
  $gjh_i = $gjh->findBy_id($journal_headerid);
  $jls = $this->findBy_parentId($journal_headerid);
  foreach ($jls as $journal_lines) {
   $gjl = new gl_journal_line();
   foreach ($journal_lines as $jl_key => $jl_value) {
    $gjl->$jl_key = $jl_value;
   }
   $gjl->status = 'P';

   //update the balance
   $gb = new gl_balance();
   $gb->period_id = $gjh_i->period_id;
   $gb->ledger_id = $gjh_i->ledger_id;
   $gb->balance_type = $gjh_i->balance_type;
   $gb->coa_combination_id = $gjl->code_combination_id;
   $gb->total_ac_dr = $gjl->total_ac_dr;
   $gb->total_ac_cr = $gjl->total_ac_cr;
   try {
    $gb->_before_save();
    $gb->save();
    try {
     $gjl->save();
    } catch (Exception $e) {
     $this->rollback = true;
     echo " GL Journa line status change failed!" . $e->getMessage();
    }
   } catch (Exception $e) {
    $this->rollback = true;
    echo " GL Balance Update Failed!" . $e->getMessage();
   }
  }
 }

 public function reverse_journal_lines($new_journal_header_id) {
  $old_journal_header_id = $this->gl_journal_header_id;
  $old_gjl_i = $this->findBy_parentId($old_journal_header_id);

  foreach ($old_gjl_i as $old_lines) {
   $new_gjl = new gl_journal_line();
   $new_gjl->gl_journal_header_id = $new_journal_header_id;
   $new_gjl->line_num = $old_lines->line_num;
   $new_gjl->status = 'U';
   $new_gjl->code_combination_id = $old_lines->code_combination_id;
   $new_gjl->total_cr = $old_lines->total_dr;
   $new_gjl->total_dr = $old_lines->total_cr;
   $new_gjl->total_ac_cr = $old_lines->total_ac_dr;
   $new_gjl->total_ac_dr = $old_lines->total_ac_cr;
   $new_gjl->description = 'Reversal of line num ' . $old_lines->line_num;
   $new_gjl->reference_key_value = $old_journal_header_id . '_' . $old_lines->gl_journal_line_id;
   try {
    $new_gjl->save();
   } catch (Exception $e) {
    echo " Failed in reversing journal lines " . $e->getMessage();
   }
  }
 }

 Public static function gl_journal_line_types() {
  $option_header = option_header::find_by_name('GL_JOURNAL_LINE_TYPE');
  $lines = option_line::find_by_option_id($option_header->option_header_id);
  return $lines;
 }

 public function findBy_headerId_lineNum() {
  global $db;
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE gl_journal_header_id= :gl_journal_header_id AND  line_num = :line_num";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $param_a = ['gl_journal_header_id', 'line_num'];
  $value_a = ['gl_journal_header_id' => $this->gl_journal_header_id,
   'line_num' => $this->line_num];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_reference_keyName_keyValue() {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE reference_key_name= :reference_key_name AND  reference_key_value = :reference_key_value";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $value_a = ['reference_key_name' => $this->reference_key_name,
   'reference_key_value' => $this->reference_key_value];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of gl_journal_line class
?>