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
 * gl_journal_header
 * Journals tracks all the financial transactions
 * Contains all the conversion information, such as - ledger_id, currency , document_date, journal_source, journal_name etc
 * 
 */
class gl_journal_header extends dbObject {

 public static $table_name = "gl_journal_header";
 public static $dependent_classes = ['gl_journal_line'];
 public static $primary_column = "gl_journal_header_id";
 public static $multi_search_primary_column = "gl_journal_header_id";
 public static $key_column = 'ledger_id';
 public static $module = "gl";
 public static $system_info = [
  'name' => 'Journal',
  'number' => '1106',
  'description' => 'General Ledger Journal',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('gl_journal_line'),
  'primary_entity_cb' => '',
  'module_name' => 'gl',
  'weight' => 6
 ];
 public $checkbox = [
  "rev_enabled_cb"
 ];
 public $status_a = [
  'ENTERED' => 'Entered',
  'POSTED' => 'Posted',
  'REVERSED' => 'Reversed',
 ];
 public $field_a = [
  'gl_journal_header_id',
  'ledger_id',
  'currency',
  'doc_currency',
  'document_date',
  'period_id',
  'journal_source',
  'journal_category',
  'journal_name',
  'description',
  'balance_type',
  'post_date',
  'header_amount',
  'exchange_type',
  'exchange_date',
  'exchange_rate',
  'control_total',
  'running_total_dr',
  'running_total_cr',
  'running_toatl_ac_dr',
  'running_toatl_ac_cr',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'status',
  'rev_enabled_cb',
  'rev_number',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'gl_journal_header_id',
  'ledger_id',
  'currency',
  'period_id',
  'journal_name',
  'description',
 ];
 public $requiredField = [
  'ledger_id',
  'currency',
  'period_id',
  'journal_source',
  'journal_category',
  'journal_name',
 ];
 public $numberField = [
  'header_amount',
  'exchange_rate',
  'control_total',
  'running_total_dr',
  'running_total_cr',
  'running_toatl_ac_dr',
  'running_toatl_ac_cr',
 ];
 public $fields_inForm_notInDataBase = [
  'multi_action_class',
  'action'
 ];
 public $profile_default = [
  'ledger_id' => 'gl_ledger_id_default',
 ];
 public $search = [
//		 '_update_path' => 'modules/po/po',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $search_functions = [
  'Ledger' => 'search_ledger',
 ];
 public $pageTitle = " GL Journal Entry "; //page Title
 public $option_lists = [
  'journal_category' => 'GL_JOURNAL_CATEGORY',
  'status' => 'GL_JOURNAL_STATUS',
  'balance_type' => 'GL_BALANCE_TYPE',
 ];
 public $module_defaults = [
  'journal_category' => 'GL_MISCELLANEOUS',
  'journal_source' => 'man',
  'balance_type' => 'A',
 ];
 public $gl_journal_header_id;
 public $ledger_id;
 public $currency;
 public $doc_currency;
 public $period_id;
 public $document_date;
 public $journal_source;
 public $journal_category;
 public $journal_name;
 public $description;
 public $balance_type;
 public $post_date;
 public $header_amount;
 public $exchange_type;
 public $exchange_date;
 public $exchange_rate;
 public $control_total;
 public $running_total_dr;
 public $running_total_cr;
 public $running_toatl_ac_dr;
 public $running_toatl_ac_cr;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $ef_id;
 public $status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $coa_id;
 public $coa_structure_id;
 public $action;
 public $multi_action_class;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 private $_update_ledger_id = false;

 private function _period_status($period_id) {
  $period = new gl_period();
  $period_i = $period->findBy_id($period_id);
  return $period_i->status;
 }

 public function _before_save() {
//   return -99;
  /* Check the existing status - If its POSTED then now other actiity is allowed except Reverse */
  if (($this->status == 'POSTED') && ( $this->action != 'REVERSED')) {
   echo " You cant save any records as the journal is POSTED. <br>"
   . " You can only reverse this Journal. ";
   return -99;
  } elseif (( $this->action != 'REVERSED') && (!empty($this->gl_journal_header_id))) { //required if user click post twice
   $gjh_id = $this->gl_journal_header_id;
   $gjh = new gl_journal_header;
   $gjh_inDb = $gjh->findBy_id($gjh_id);
   if ($gjh_inDb->status == 'POSTED') {
    echo " You cant save any records as the journal is POSTED. <br>"
    . " You can only reverse this Journal. ";
    return -99;
   }
  }


  /* Reversing and Posting acttivites */
  if ($this->action === 'REVERSED') {
   $reversing_journal_header_id = $this->gl_journal_header_id;
   if ($this->_reverse_journal_and_lines()) {
    echo "<br> Reveser Journal creation completed. New Journal name is " . $this->journal_name . ' & id is ' . $this->gl_journal_header_id;
    echo "<br> Starting to update this journal status ";
    $gjh = new gl_journal_header();
    $gjh_i = $gjh->findBy_id($reversing_journal_header_id);
    foreach ($gjh_i as $key_i => $value_i) {
     $gjh->$key_i = $value_i;
    }
    $gjh->status = 'REVERSED';
    $gjh->description = $gjh->description . '-Reversed on' . current_time();
    if ($gjh->save()) {
     echo "<br> Status update complete! ";
    }
   }
  } else if ($this->action === 'POSTED') {
   if ($this->_period_status($this->period_id) != 'OPEN') {
    echo " <br> Period is not open";
    return -99;
   }
   if (!empty($this->post_date)) {
    if (!empty($this->reference_key_name) && ($this->reference_key_value)) {
     if ($this->_update_referenced_class() < 0) {
      echo "<br>POST to GL process failed! in module. Error @ gl_journal_header @@ " . __LINE__ . '<br>' . $e->getMessage();
      $this->rollback = true;
      return -99;
     }
    }
    $gjl = new gl_journal_line();
    $gjl->gl_journal_header_id = $this->gl_journal_header_id;
    try {
     $gjl->post_all_lines();
    } catch (Exception $e) {
     echo "<br>POST to GL process failed! for journal line. Error @ gl_journal_header @@ " . __LINE__ . '<br>' . $e->getMessage();
     $this->rollback = true;
     return -99;
    }
    $this->post_date = current_time(1);
    $this->status = 'POSTED';
   }
  } else {
   $this->post_date = null;
  }

  /* Posting from other modules */
 }

 private function _reverse_journal_and_lines() {
  $gp = new gl_period();
  $current_open_period = $gp->current_open_period($this->ledger_id);
  $reversing_journal_header_id = $this->gl_journal_header_id;
  $this->gl_journal_header_id = null;
  $this->status = 'ENTERED';
  $this->document_date = current_time(1);
  $this->post_date = null;
  $this->period_id = $current_open_period->gl_period_id;
  $this->journal_name = 'Reversal of ' . $this->journal_name;
  $this->description = 'Reversal of ' . $this->description . ' on ' . current_time();
  $this->journal_category = 'GL_REVERSAL';
  $this->journal_source = 'System';
  $this->reference_type = 'table';
  $this->reference_key_name = 'gl_journal_header';
  $this->reference_key_value = $reversing_journal_header_id;
  $this->audit_trial();
  if ($this->save()) {
   $gjl = new gl_journal_line();
   $gjl->gl_journal_header_id = $reversing_journal_header_id;
   try {
    $gjl->reverse_journal_lines($this->gl_journal_header_id);
   } catch (Exception $e) {
    echo " Error in reversing " . $e->getMessage();
    return -90;
   }
   return 1;
  }
 }

 private function _update_referenced_class() {
  $class = $this->reference_key_name;
  $$class = new $class;
  if (method_exists($$class, '_post_gl_process')) {
   return call_user_func(array($$class, '_post_gl_process'), $this->reference_key_value);
  }
 }

 Public function gl_balance_type() {
  $option_header = option_header::find_by_name('GL_BALANCE_TYPE');
  $ol = new option_line();
  $lines = $ol->findBy_parentId($option_header->option_header_id);
  return $lines;
 }

 Public function gl_journal_status() {
  $option_header = option_header::find_by_name('GL_JOURNAL_STATUS');
  $ol = new option_line();
  $lines = $ol->findBy_parentId($option_header->option_header_id);
  return $lines;
 }

 Public function gl_journal_category() {
  $option_header = option_header::find_by_name('GL_JOURNAL_CATEGORY');
  $ol = new option_line();
  $lines = $ol->findBy_parentId($option_header->option_header_id);
  return $lines;
 }

 public function highest_line_num() {
  $sql = " SELECT MAX(gjl.line_num)	 as max_line_num "
   . " FROM  gl_journal_header gjh LEFT JOIN gl_journal_LINE gjl "
   . " ON gjh.gl_journal_header_id = gjl.gl_journal_header_id "
   . " AND gjh.gl_journal_header_id = :gl_journal_header_id  ";
  $value_a = ['gl_journal_header_id' => $this->gl_journal_header_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : 0;
 }

}

//end of gl_journal_header class
?>