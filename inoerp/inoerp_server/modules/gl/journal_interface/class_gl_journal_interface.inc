<?php

class gl_journal_interface extends dbObject {

 public static $table_name = "gl_journal_interface";
 public static $primary_column = "gl_journal_interface_id";
 public static $multi_search_primary_column = "gl_journal_line_id"; //this value is used in multi search hidden value
 public static $key_column = 'gl_journal_line_id';
 public static $system_info = [
  'name' => 'Journal Interface',
  'number' => '110',
  'description' => 'GL Journal Interface',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'gl',
  'weight' => 6
 ];
 public static $line_status_a = [
  'N' => 'New not imported',
  'E' => 'Error',
  'S' => 'Sucessfully Imported',
 ];
 public $field_a = [
  'gl_journal_interface_id',
  'gl_journal_header_id',
  'gl_journal_line_id',
  'ledger_id',
  'currency',
  'document_date',
  'period_id',
  'journal_source',
  'journal_category',
  'journal_name',
  'description',
  'balance_type',
  'post_date',
  'header_amount',
  'doc_currency',
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
//  'status',
  'line_num',
  'line_status',
  'line_type',
  'line_description',
  'code_combination_id',
  'total_dr',
  'total_cr',
  'total_ac_dr',
  'total_ac_cr',
  'line_reference_type',
  'line_reference_key_name',
  'line_reference_key_value',
  'rev_enabled_cb',
  'rev_number',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'gl_journal_interface_id',
  'gl_journal_header_id',
  'gl_journal_line_id',
 ];
 public $dateField = [
  'document_date'
 ];
 public $requiredField = [
  'ledger_id',
  'journal_source',
  'journal_category',
  'period_id',
  'balance_type',
  'currency',
  'doc_currency',
  'exchange_type',
  'exchange_rate',
  'code_combination_id',
 ];
 public $fields_inForm_notInDataBase = [
  'action',
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
 public $search = [
  '_update_path' => 'form.php?class_name=gl_journal_interface',
  '_show_update_path' => 1,
  '_view_path' => 'form.php?class_name=gl_journal_interface',
  '_show_view_path' => 1
 ];
 public $search_functions = [
  'Ledger' => 'search_ledger',
 ];
 public $prg_import_gl_journal_parameters = [
  'Ledger' => 'search_ledger',
  'Source' => 'search_journal_source',
  'Category' => 'search_journal_category',
  'Period' => 'search_gl_period_name',
 ];
 public $prg_import_gl_journal_details = [
  'name' => 'Import GL Journal ',
  'description' => 'Import GL Journal from Interface ',
 ];
 
  public $prg_delete_gl_journal_parameters = [
  'Ledger' => 'search_ledger',
  'Source' => 'search_journal_source',
  'Category' => 'search_journal_category',
  'Period' => 'search_gl_period_name',
 ];
 public $prg_delete_gl_journal_details = [
  'name' => 'Delete Journal Interface Lines',
  'description' => 'Delete Journal Interface Lines',
 ];
 
 public $pageTitle = " Import GL Journals "; //page Title
 public $gl_journal_interface_id;
 public $gl_journal_header_id;
 public $gl_journal_line_id;
 public $ledger_id;
 public $currency;
 public $document_date;
 public $period_id;
 public $journal_source;
 public $journal_category;
 public $journal_name;
 public $description;
 public $balance_type;
 public $post_date;
 public $header_amount;
 public $doc_currency;
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
 public $status;
 public $line_num;
 public $line_status;
 public $line_type;
 public $line_description;
 public $code_combination_id;
 public $total_dr;
 public $total_cr;
 public $total_ac_dr;
 public $total_ac_cr;
 public $line_reference_type;
 public $line_reference_key_name;
 public $line_reference_key_value;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $action;
 public $action_class_name;
 public $mode;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 private $_gl_journal_header_id;
 public $message;

 /*
  * Elements need to be same for journal lines to be in same journal header are
  * 1. Ledger Id
  * 2. Currency and Doc Currency
  * 3. Period
  * 4. Balance Type
  * 5. Journal Source
  * 6. Journal Category
  * 7. Exchange Type & Exchange Rate
  */

 private function _distinct_lines() {
  $sql = " SELECT DISTINCT  CONCAT(ledger_id, '|' ,currency, '|' ,doc_currency, '|' , period_id, '|' ,balance_type, '|' ,journal_source, '|' ,
journal_category,'|' , '|' ,exchange_type, '|' , exchange_rate) as line_combination

FROM gl_journal_interface ";

  $sql .= " WHERE (line_status IN ( 'N' , 'E' ) || line_status IS NULL) ";

  if (!empty($this->ledegr_id)) {
   $sql .= " AND ledegr_id = '{$this->ledegr_id}' ";
  }
  
    if (!empty($this->journal_source)) {
   $sql .= " AND journal_source = '{$this->journal_source}' ";
  }


  if (!empty($this->journal_category)) {
   $sql .= " AND journal_category = '{$this->journal_category}' ";
  }

  if (!empty($this->period_id)) {
   $sql .= " AND period_id = '{$this->period_id}' ";
  }

  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 
  private function _lines_for_delete() {
  $sql = " SELECT *
          FROM gl_journal_interface 
          WHERE line_status = 'S' ";

  if (!empty($this->ledegr_id)) {
   $sql .= " AND ledegr_id = '{$this->ledegr_id}' ";
  }
  
    if (!empty($this->journal_source)) {
   $sql .= " AND journal_source = '{$this->journal_source}' ";
  }


  if (!empty($this->journal_category)) {
   $sql .= " AND journal_category = '{$this->journal_category}' ";
  }

  if (!empty($this->period_id)) {
   $sql .= " AND period_id = '{$this->period_id}' ";
  }

  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }
 
 private function _create_journal($iline) {
  $sql = " SELECT * 
FROM gl_journal_interface 
WHERE CONCAT(ledger_id, '|' ,currency, '|' ,doc_currency, '|' , period_id, '|' ,balance_type, '|' ,journal_source, '|' ,
journal_category,'|' , '|' ,exchange_type, '|' , exchange_rate) = '{$iline->line_combination}' ";

  $all_lines = $this->find_by_sql($sql);
  if ($all_lines) {
   $gl_journal_header_id = $this->_create_journal_header($all_lines[0]);

   if ($gl_journal_header_id) {
    $this->_max_line_num = 1;
    $header_amount = 0;
    foreach ($all_lines as $journal_line) {
     $journal_line_id = $this->_create_journal_line($journal_line, $gl_journal_header_id);
     $this->_max_line_num++;
     $header_amount += $journal_line->total_dr;
     $gl_ji = new gl_journal_interface();
     $gl_ji->findBy_id($journal_line->gl_journal_interface_id);
     if ($journal_line_id) {
      $gl_ji->line_status = 'S';
     }else{
      $gl_ji->line_status = 'E';
     }
     $gl_ji->save();
    }
    $gjh_i = new gl_journal_header;
    $gjh_i->findBy_id($gl_journal_header_id);
    $gjh_i->header_amount = $header_amount;
    $gjh_i->save();
   }
  }
 }

 private function _create_journal_header($one_line) {
  global $dbc;
  $gjh = new gl_journal_header;
  $gjh->ledger_id = $one_line->ledger_id;
  $gjh->status = 'ENTERED';
  $gjh->currency = $one_line->currency;
  $gjh->doc_currency = $one_line->doc_currency;
  $gjh->exchange_type = $one_line->exchange_type;
  $gjh->exchange_rate = $one_line->exchange_rate;
  $gjh->period_id = $one_line->period_id;
  $gjh->journal_source = $one_line->journal_source;
  $gjh->journal_category = $one_line->journal_category;
  $gjh->reference_type = 'table';
  $gjh->reference_key_name = self::$table_name;
  $gjh->reference_key_value = $one_line->gl_journal_interface_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = $one_line->balance_type;
  try {
   $gjh->save();
   $this->_gl_journal_header_id = $gjh->gl_journal_header_id;
   $this->message .= '<br> ' . $this->gl_journal_header_id . ' is created';
  } catch (Exception $e) {
   $dbc->rollback = true;
   $gjh->gl_journal_header_id = null;
   echo "<br> Failed Saving Jounral Header" . $e->getMessage();
  }
  return $gjh->gl_journal_header_id;
 }

 private $_max_line_num;

 private function _create_journal_line($journal_line_o, $gl_journal_header_id) {
  global $dbc;
  $new_gjl = new gl_journal_line();
  $new_gjl->gl_journal_header_id = $gl_journal_header_id;
  $new_gjl->reference_type = $journal_line_o->line_reference_type;
  $new_gjl->reference_key_name = $journal_line_o->line_reference_key_name;
  $new_gjl->reference_key_value = $journal_line_o->line_reference_key_value;
  $new_gjl->gl_journal_line_id = null;
  $new_gjl->line_num = $this->_max_line_num;
  $new_gjl->status = 'U';
  $new_gjl->code_combination_id = $journal_line_o->code_combination_id;
  $new_gjl->total_dr = $journal_line_o->total_dr;
  $new_gjl->total_ac_dr = $journal_line_o->total_ac_dr;
  $new_gjl->total_cr = $journal_line_o->total_cr;
  $new_gjl->total_ac_cr = $journal_line_o->total_ac_cr;
  $new_gjl->description = $journal_line_o->line_description;
  try {
   $new_gjl->save();
   $this->message .= '<br> ' . $this->gl_journal_line_id . ' is created';
  } catch (Exception $e) {
   $new_gjl->gl_journal_line_id = null;
   $this->message .= '<br> Failed to create journal line for gl_kournal_interface_id ' . $journal_line_o->gl_kournal_interface_id;
  }

  return $new_gjl->gl_journal_line_id;
 }

 public function _before_save() {
  return -90;
 }

 public function prg_import_gl_journal($seralized_parameters) {
  /*
   *  1. First Import all lines with the same customer site id
   */

  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting to Import GL Journals....<br>';
  if (!empty($parameters['ledger_id'][0])) {
   $this->ledger_id = $parameters['ledger_id'][0];
   $this->message .= '<br> Entered Ledger Id is : ' . $this->ledger_id;
  } 

  if (!empty($parameters['journal_category'][0])) {
   $this->journal_category = $parameters['journal_category'][0];
   $this->message .= '<br> Entered journal_category is : ' . $this->journal_category;
  }

  if (!empty($parameters['journal_source'][0])) {
   $this->journal_source = $parameters['journal_source'][0];
   $this->message .= '<br> Entered journal_source is : ' . $this->journal_source;
  }

  if (!empty($parameters['period_id'][0])) {
   $this->period_id = $parameters['period_id'][0];
   $this->message .= '<br> Entered period_id is : ' . $this->period_id;
  }

  $all_distinct_lines = $this->_distinct_lines();
  if ($all_distinct_lines) {
   foreach ($all_distinct_lines as $iline) {
    $this->_create_journal($iline);
   }
  } else {
   $this->message .= '<br> No elligible lines found for import. Check entered parameters for the program';
  }

  return $this->message;
 }
 
 public function prg_delete_gl_journal($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting to Delete GL Journal Interface Lines....<br>';
  if (!empty($parameters['ledger_id'][0])) {
   $this->ledger_id = $parameters['ledger_id'][0];
   $this->message .= '<br> Entered Ledger Id is : ' . $this->ledger_id;
  } 

  if (!empty($parameters['journal_category'][0])) {
   $this->journal_category = $parameters['journal_category'][0];
   $this->message .= '<br> Entered journal_category is : ' . $this->journal_category;
  }

  if (!empty($parameters['journal_source'][0])) {
   $this->journal_source = $parameters['journal_source'][0];
   $this->message .= '<br> Entered journal_source is : ' . $this->journal_source;
  }

  if (!empty($parameters['period_id'][0])) {
   $this->period_id = $parameters['period_id'][0];
   $this->message .= '<br> Entered period_id is : ' . $this->period_id;
  }

  $all_lines = $this->_lines_for_delete();
  if ($all_lines) {
   $lines_deleted = 0;
   foreach ($all_lines as $iline) {
    $gl_int = new gl_journal_interface();
    $gl_int->gl_journal_interface_id = $iline->gl_journal_interface_id;
    $gl_int->delete();
    $lines_deleted++;
   }
   $this->message .= "<br> $lines_deleted lines are sucessfully deleted";
  } else {
   $this->message .= '<br> No elligible lines found for deletion. Check entered parameters for the program';
  }

  return $this->message;
 }

}

//end of po_requisition_detail class
?>