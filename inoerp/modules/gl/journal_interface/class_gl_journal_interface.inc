<?php

class gl_journal_interface extends dbObject {

 public static $table_name = "gl_journal_interface";
 public static $primary_column = "gl_journal_interface_id";
 public static $multi_search_primary_column = "gl_journal_line_id"; //this value is used in multi search hidden value
 public static $key_column = 'gl_journal_line_id';
 public static $system_info = [
  'name' => 'Journal Interface',
  'number' => '1306',
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
  '_show_view_path' => 1,
  '_extra_path' => array('form.php?class_name=gl_journal_interface' => 'Import')
 ];
 public $search_functions = [
  'Ledger' => 'search_ledger',
 ];
 public $prg_import_gl_journal_parameters = [
  'Ledger' => 'search_ledger',
  'Source' => 'search_journal_source',
  'Ledger' => 'search_journal_category',
  'Period' => 'search_gl_period',
 ];
 public $prg_import_gl_journal_details = [
  'name' => 'Import GL Journal ',
  'description' => 'Import GL Journal from Interface ',
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
journal_category,'|' , '|' ,exchange_type, '|' , exchange_rate)

FROM gl_journal_interface ";
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 private function _create_journal_header() {
  $sd_so_header_id = $this->sd_so_header_id;
  $sd_so = new sd_so_header();
  $sd_so->findBy_id($sd_so_header_id);

  $ar_th = new gl_journal_header();
  $ar_th->bu_org_id = $this->bu_org_id;
  $ar_th->ledger_id = $this->ledger_id;
  $ledger = new gl_ledger();
  $ledger->findBy_id($ar_th->ledger_id);

  $ar_th->transaction_type = $this->transaction_type;
  $ar_th->ar_customer_id = $this->ar_customer_id;
  $ar_th->ar_customer_site_id = $this->ar_customer_site_id;
  $ar_th->ship_to_id = $sd_so->ship_to_id;
  $ar_th->bill_to_id = $sd_so->bill_to_id;
  $ar_th->doc_currency = $sd_so->doc_currency;
  $ar_th->currency = $ledger->currency_code;
  $ar_th->bill_to_id = $sd_so->bill_to_id;
  $gp = new gl_period();
  $ar_th->period_id = $gp->current_open_period($ar_th->ledger_id, 'OPEN')->gl_period_id;
  $ar_tt = new gl_journal_type();
  $ar_tt->findBy_id($ar_th->transaction_type);
  $ar_th->receivable_ac_id = $ar_tt->receivable_ac_id;
  $ar_th->transaction_class = $ar_tt->transaction_class;
  $ar_th->payment_term_id = $sd_so->payment_term_id;
  $ar_th->payment_term_date = $sd_so->payment_term_date;
  $ar_th->document_date = current_time(1);
  $ar_th->reference_type = 'table';
  $ar_th->reference_key_name = 'sd_so_header_id';
  $ar_th->reference_key_value = $ar_th->sd_so_header_id = $sd_so_header_id;
  $ar_th->sd_so_number = $sd_so->so_number;
  $ar_th->audit_trial();
  try {
   $ar_th->save();
  } catch (Exception $e) {

   echo "<br>Failed to create the transaction header. Error @gl_journal_interface "
   . "@@ Line" . __LINE__ . '<br>' . $e->getMessage();
   $this->rollback = true;
   return -99;
  }
  echo "<br> Transaction header is succefully created. Header Id/ Number - " . $ar_th->gl_journal_header_id;
  $ar_th->transaction_number = $ar_th->bu_org_id . '-' . $ar_th->gl_journal_header_id;
  $ar_th->save();
  $this->_gl_journal_header_id = $ar_th->gl_journal_header_id;
  return $ar_th->gl_journal_header_id;
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
  if (!empty($parameters['bu_org_id'][0])) {
   $bu_org_id = $parameters['bu_org_id'][0];
   $this->message .= '<br> Entered Bu org Id is : ' . $bu_org_id;
  } else {
   $this->message .= '<br> Error! : No BU org id found @ po_requisition_interface ' . __LINE__;
   return $this->message;
  }

//	1. Lines with same customer site id
  $all_customer_sites = $this->distinct_customer_sites();
  foreach ($all_customer_sites as $cst_site_id) {
   $all_lines = $this->findBy_customerSiteId_buOrgId($cst_site_id, $bu_org_id);
   if (empty($all_lines)) {
    return;
   }
   //create header on basis of first object
   $ar_ti_prg = new gl_journal_interface();
   foreach ($all_lines[0] as $key => $value) {
    if (property_exists($ar_ti_prg, $key)) {
     $ar_ti_prg->$key = $value;
    }
   }
   $ar_ti_prg->_create_transaction_header();
   $this->message .= "<br> Transaction header is succefully created. Header Id/ Number - " . $ar_ti_prg->_gl_journal_header_id;

   //create lines for each object
   $this->message .=$this->_create_transaction_line_prg($all_lines, $ar_ti_prg->_gl_journal_header_id);
  }

  return $this->message;
 }

}

//end of po_requisition_detail class
?>