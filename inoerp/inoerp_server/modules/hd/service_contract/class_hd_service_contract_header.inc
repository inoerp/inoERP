<?php

/**
 * inoERP 
 *
 * 
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * hd_service_contract_HEADER
 * Used for generating AR Invoice, Debit Memo, Credit Memo, Deposit, Guarantee
 * Contains all the AR Transaction header level information, such as - Customer, Document Type, Currency, Trnx Number
 * 
 */
class hd_service_contract_header extends dbObject {

 public static $table_name = "hd_service_contract_header";
 public static $dependent_classes = ['hd_service_contract_line', 'hd_service_contract_detail'];
 public static $primary_column = "hd_service_contract_header_id";
 public static $primary_column2 = "contract_number";
 public static $key_column = 'ar_customer_id';
 public static $module = "hd"; //same as gl_journal_source
 public static $gl_journal_category = "HD_CONTRACT";
// public static $js_fileName = 'modules/ar/transaction/hd_service_contract.js';
 public static $system_info = [
  'name' => 'Service COntracts',
  'number' => '5106',
  'description' => 'Create & Mainten Service Contracts',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hd_service_contract_line', 'hd_service_contract_detail'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 3
 ];
 public static $category_a = [
  'WARRANTY' => 'Warranty & Extended ',
  'SERVICE' => 'Service Agreement',
 ];
 public $action_a = [
  'CREATE_RECEIPT' => 'Create Receipt',
  'CREATE_ACCOUNT' => 'Create Accounting',
  'VIEW_JOURNAL' => 'View Journal',
  'CREDIT' => 'Credit Transaction',
  'CANCEL' => 'Cancel Transaction',
 ];

 public $field_a = [
  'hd_service_contract_header_id',
  'bu_org_id',
  'category',
  'contract_number',
  'version',
  'start_date',
  'end_date',
  'duration_uom_id',
  'duration',
  'ar_customer_id',
  'ar_customer_site_id',
  'document_owner',
  'description',
  'ship_to_id',
  'bill_to_id',
  'header_amount',
  'tax_amount',
  'receipt_amount',
  'currency',
  'doc_currency',
  'payment_term_id',
  'exchange_rate_type',
  'exchange_rate',
  'negotiation_status',
  'status',
  'document_date',
  'document_number',
  'ledger_id',
  'period_id',
  'payment_term_date',
  'ar_transaction_type_id',
  'billing_cb',
  'invoicing_rule',
  'accounting_rule',
  'renewal_process',
  'renew_upto_date',
  'rewnew_pricing_method',
  'rewnew_price_list_id',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'approval_status',
  'sales_person_employee_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 
  public $profile_default = [
  'exchange_rate_type' => 'gl_currency_conversion_type',
  'bu_org_id' => 'org_bu_name_default',
  'ship_to_id' => 'ship_to_address_default',
  'bill_to_id' => 'bill_to_address_default'
 ];
  
   public $fields_inForm_notInDataBase = [
  "supplier_name",
  "supplier_number",
  "supplier_site_name",
  "ship_to_address",
  "bill_to_address",
  'multi_action_class_pc',
  'multi_action_class_pc_value',
  'action',
  'ship_to_phone',
  'ship_to_email',
  'ship_to_address',
  'ship_to_country',
  'ship_to_postal_code',
  'bill_to_phone',
  'bill_to_email',
  'bill_to_address',
  'bill_to_country',
  'bill_to_postal_code',
 ];
   
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Service Contracts "; //page Title
 public $hd_service_contract_header_id;
 public $bu_org_id;
 public $category;
 public $contract_number;
 public $version;
 public $start_date;
 public $end_date;
 public $duration_uom_id;
 public $duration;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $document_owner;
 public $description;
 public $ship_to_id;
 public $bill_to_id;
 public $header_amount;
 public $tax_amount;
 public $receipt_amount;
 public $currency;
 public $doc_currency;
 public $receivable_ac_id;
 public $payment_term_id;
 public $exchange_rate_type;
 public $exchange_rate;
 public $negotiation_status;
 public $status;
 public $document_date;
 public $document_number;
 public $ledger_id;
 public $period_id;
 public $payment_term_date;
 public $ar_transaction_type_id;
 public $billing_cb;
 public $invoicing_rule;
 public $accounting_rule;
 public $renewal_process;
 public $renew_upto_date;
 public $rewnew_pricing_method;
 public $rewnew_price_list_id;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $approval_status;
 public $sales_person_employee_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $customer_name;
 public $customer_number;
 public $sd_so_number;
 public $multi_action_class_pc;
 public $multi_action_class_pc_value;
 public $action;
 public $transaction_action;
 
 public $ship_to_address;
 public $bill_to_address_name;
 public $ship_to_phone;
 public $ship_to_address_name;
 public $ship_to_country;
 public $ship_to_postal_code;
 public $bill_to_phone;
 public $bill_to_address;
 public $bill_to_country;
 public $bill_to_postal_code;
 private $_max_line_num;


 public function _before_showing() {
  $address = new address();
  if (!empty($this->ship_to_id)) {
   $address_ship_to = $address->findBy_id($this->ship_to_id);
   $this->ship_to_address_name = $address_ship_to->address_name;
   $this->ship_to_address = $address_ship_to->address;
   $this->ship_to_country = $address_ship_to->country;
   $this->ship_to_postal_code = $address_ship_to->postal_code;
   $this->ship_to_phone = $address_ship_to->phone;
  }
  if (!empty($this->bill_to_id)) {
   $address_bill_to = $address->findBy_id($this->bill_to_id);
   $this->bill_to_address_name = $address_bill_to->address_name;
   $this->bill_to_address = $address_bill_to->address;
   $this->bill_to_country = $address_bill_to->country;
   $this->bill_to_postal_code = $address_bill_to->postal_code;
   $this->bill_to_phone = $address_bill_to->phone;
  }
 }

 public function _before_save() {

//  if ((!empty($this->hd_service_contract_header_id)) && ($this->action === 'create_accounting')) {
//   //if journal header id excists then save journal lines only else first header & then lines
//   $this->findBy_id($this->hd_service_contract_header_id);
//   if (empty($this->gl_journal_header_id)) {
//    try {
//     $this->_save_journal_header();
//    } catch (Exception $e) {
//     echo "Create accounting failed" . $e->getMessage();
//    }
//   }
//   if (!empty($this->gl_journal_header_id)) {
//    //check the status is not updated and then save/update journal lines
//    $gjh = new gl_journal_header();
//    $gjh->findBy_id($this->gl_journal_header_id);
//    $max_line_num = $gjh->highest_line_num()->max_line_num;
//    $this->_max_line_num = !empty($max_line_num) ? $max_line_num + 1 : 1;
//    if ($gjh->status == 'ENTERED') {
//     $this->_save_journal_lines();
//    } else {
//     echo "<br> The Journal Header \" $gjh->journal_name \" (id : $this->gl_journal_header_id ) is not in Entered Status."
//     . "<br>From Subledger, You can only update Jouranls in Entered Status";
//     return;
//    }
//   }
//
//   return 10;
//  }
//
//  if ((!empty($this->hd_service_contract_header_id)) && ($this->transaction_action == 'CANCEL')) {
//   $this->_cancel_transaction();
//   return 10;
//  }
 }

 public function _after_save() {
  if (!$this->contract_number) {
   echo '<br/> No contract number is entered';
  }
  if ((!empty($this->hd_service_contract_header_id)) && empty($this->contract_number)) {
   $hd_service_contract_header_id = $this->hd_service_contract_header_id;
   $bu_org_id = $this->bu_org_id;
   $this->contract_number = $bu_org_id . '-' . $hd_service_contract_header_id;
   echo '<br/> System created contract number is ' . $this->contract_number;
   $this->save();
  }
 }

 private function _save_journal_header() {
  $gjh = new gl_journal_header;
  $gjh->ledger_id = $this->ledger_id;
  $gjh->status = 'ENTERED';
  $gjh->currency = $this->doc_currency;
  $gjh->period_id = $this->period_id;
  $gjh->journal_source = self::$module;
  $gjh->journal_category = 'AR_' . $this->transaction_class;
  $gjh->reference_type = 'table';
  $gjh->reference_key_name = self::$table_name;
  $gjh->reference_key_value = $this->hd_service_contract_header_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = 'A';
  $gjh->audit_trial();
  try {
   $gjh->save();
   $this->gl_journal_header_id = $gjh->gl_journal_header_id;
   echo "<br> Jounral Header Id #" . $this->gl_journal_header_id . ' is created';
   //need to create a new insatnce of hd_service_contract_header as the gl_journal_header_id is not allowed to updated from webform
   $ar_th = new hd_service_contract_header();
   $ar_th->findBy_id($this->hd_service_contract_header_id);
   $ar_th->gl_journal_header_id = $gjh->gl_journal_header_id;
   $ar_th->audit_trial();
   $ar_th->save();
  } catch (Exception $e) {
   echo "<br> Failed Saving Jounral Header" . $e->getMessage();
  }
 }

 private function _save_journal_lines() {
  $artl = new hd_service_contract_line();
  $all_lines = $artl->findBy_parentId($this->hd_service_contract_header_id);
  foreach ($all_lines as $lines) {
   $artd = new hd_service_contract_detail();
   $all_details = $artd->findBy_parentId($lines->hd_service_contract_line_id);
   foreach ($all_details as $deatils) {
    $new_gjl = new gl_journal_line();
    $artd->findBy_id($deatils->hd_service_contract_detail_id);
    $new_gjl->gl_journal_header_id = $this->gl_journal_header_id;
    $new_gjl->reference_key_name = 'hd_service_contract_detail';
    $new_gjl->reference_key_value = $deatils->hd_service_contract_detail_id;
    //check if line lready exists
    $jl_exists = $new_gjl->findBy_reference_keyName_keyValue();
    if ($jl_exists) {
     $new_gjl->gl_journal_line_id = $jl_exists->gl_journal_line_id;
     $new_gjl->line_num = $jl_exists->line_num;
     $new_gjl->status = $jl_exists->status;
    } else {
     $new_gjl->gl_journal_line_id = null;
     $new_gjl->line_num = $this->_max_line_num;
     $new_gjl->status = 'U';
     $this->_max_line_num++;
    }
    $new_gjl->code_combination_id = $deatils->detail_ac_id;
    if ($this->transaction_type == 'CREDIT_MEMO') {
     $new_gjl->total_dr = $deatils->amount;
     $new_gjl->total_ac_dr = $deatils->amount;
    } else {
     $new_gjl->total_cr = $deatils->amount;
     $new_gjl->total_ac_cr = $deatils->amount;
    }
    $new_gjl->description = 'AR Trnx detail #' . $deatils->detail_number . ' of trxn# ' . $this->transaction_number;
    $new_gjl->reference_type = 'table';
    $new_gjl->audit_trial();
    $new_gjl->save();
    $artd->journal_created_cb = 1;
    $artd->audit_trial();
    $artd->save();
   }
  }

//	save the Receviable Account
  $receviable_gjl = new gl_journal_line();
  $receviable_gjl->gl_journal_header_id = $this->gl_journal_header_id;
  $receviable_gjl->reference_key_name = 'hd_service_contract_header';
  $receviable_gjl->reference_key_value = $this->hd_service_contract_header_id;
  //check if line lready exists
  $jl_exists_receviable = $receviable_gjl->findBy_reference_keyName_keyValue();
  if ($jl_exists_receviable) {
   $receviable_gjl->gl_journal_line_id = $jl_exists_receviable->gl_journal_line_id;
   $receviable_gjl->line_num = $jl_exists_receviable->line_num;
  } else {
   $receviable_gjl->gl_journal_line_id = null;
   $receviable_gjl->line_num = $this->_max_line_num;
   $this->_max_line_num++;
  }
  $receviable_gjl->status = 'U';
  $receviable_gjl->code_combination_id = $this->receivable_ac_id;
  if ($this->transaction_type == 'CREDIT_MEMO') {
   $receviable_gjl->total_cr = $this->header_amount + $this->tax_amount;
   $receviable_gjl->total_ac_cr = $this->header_amount + $this->tax_amount;
  } else {
   $receviable_gjl->total_dr = $this->header_amount + $this->tax_amount;
   $receviable_gjl->total_ac_dr = $this->header_amount + $this->tax_amount;
  }
  $receviable_gjl->description = 'AR Trnx Receviable of ' . $this->transaction_number;
  $receviable_gjl->reference_type = 'table';

  $receviable_gjl->audit_trial();
  $receviable_gjl->save();
 }

 public function _post_gl_process($hd_service_contract_id) {
  try {
   $this->findBy_id($hd_service_contract_id);
   $this->transaction_status = 'CLOSED';
   $this->audit_trial();
   $this->save();
   return 1;
  } catch (Exception $e) {
   echo "<br>Updating transaction status failed.Error @ hd_service_contract_header @@ " . __LINE__ . $e->getMessage();
   return -99;
  }
 }

 public static function instantiate_extra_fields(&$array_of_objects) {
  if (count($array_of_objects) > 0) {
   foreach ($array_of_objects as &$this_object) {
    $customer_details = customer::find_by_id($this_object->ar_customer_id);
    $this_object->customer_name = $customer_details->customer_name;
    $this_object->customer_number = $customer_details->customer_number;
    $customer_site_details = customer_site::find_by_id($this_object->ar_customer_site_id);
    $this_object->customer_site_name = $customer_site_details->customer_site_name;
   }
  }
  return $array_of_objects;
 }

 Public static function transaction_class() {
  $option_header = option_header::find_by_name('hd_service_contract_CLASS');
  $transaction_types = option_line::find_by_option_id($option_header->option_header_id);
  return $transaction_types;
 }

 Public static function transaction_action() {
  $option_header = option_header::find_by_name('hd_service_contract_ACTION');
  $transaction_types = option_line::find_by_option_id($option_header->option_header_id);
  return $transaction_types;
 }

 Public static function ar_approval_status() {
  $option_header = option_header::find_by_name('APPROVAL_STATUS');
  $ar_approval_status = option_line::find_by_option_id($option_header->option_header_id);
  return $ar_approval_status;
 }

 public function copy($hd_service_contract_header_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM hd_service_contract_header WHERE `hd_service_contract_header_id` = '{$hd_service_contract_header_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `hd_service_contract_header_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `hd_service_contract_header_id` = '{$hd_service_contract_header_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `hd_service_contract_header` SELECT * FROM tmptable WHERE `hd_service_contract_header_id` = '' ";
    if ($db->query($sql3)) {
     $this->hd_service_contract_header_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

 public function save() {
//  $primary_column = static::$primary_column;
//  if (empty($this->$primary_column)) {
//   $this->ar_approval_status = 'ENTER';
//   $this->create();
//  } else {
//   $this->update($this->$primary_column);
//  }
//  return $this->msg;
 }

 /* 1. Reverse the journal header
  * 2. Update the PO lines
  * 3. Update the transaction header & line 
  */

 private function _cancel_transaction() {
  if (empty($this->hd_service_contract_header_id)) {
   echo "<br>Cancellation failed!. No transaction header id found.";
  }
  if (!empty($this->gl_journal_header_id)) {
   $gjh = new gl_journal_header();
   $gjh_i = $gjh->findBy_id($this->gl_journal_header_id);
   foreach ($gjh_i as $key => $value) {
    $gjh->$key = $value;
   }
   $gjh->status = 'REVERSED';
   try {
    $gjh->_before_save();
   } catch (Exception $e) {
    echo "Journal Reversal Failed!. Error @ class_hd_service_contract_header _cancel_transaction" . $e->getMessage();
    return;
   }
  }

  //update PO & invoice
  try {
   $this->_update_so_lines();
   try {
    $this->_cancel_transaction_header();
   } catch (Exception $e) {
    echo "PO Header Update Failed!. Error @ class_hd_service_contract_header _cancel_transaction" . $e->getMessage();
    return;
   }
  } catch (Exception $e) {
   echo "PO Detail Update Failed!. Error @ class_hd_service_contract_header _cancel_transaction" . $e->getMessage();
   return;
  }
 }

 private function _cancel_transaction_header() {
  $new_arth = new hd_service_contract_header();
  $new_arth_i = $new_arth->findBy_id($this->hd_service_contract_header_id);
  $new_arth->arproval_status = 'CANCELLED';
  $new_arth->header_amount = '0.0';
  $new_arth->hd_service_contract_header_id = $new_arth_i->hd_service_contract_header_id;
  $new_arth->audit_trial();
  try {
   $new_arth->save();
  } catch (Exception $e) {
   echo "AR Transaction Lines Update Failed!. Error @ class_hd_service_contract_header _transaction_cancell_poInv_lines " . $e->getMessage();
   return;
  }
 }

 //needs to be updated after SD SO
 private function _update_so_lines() {
  global $dbc;
  $aptl = new hd_service_contract_line();
  $all_lines = $aptl->findBy_parentId($this->hd_service_contract_header_id);
  foreach ($all_lines as $lines) {
   if (!empty($lines->sd_so_line_id)) {
    $ss_line = new sd_so_line();
    $ss_line->findBy_id($lines->sd_so_line_id);
    $ss_line->invoiced_quantity -= $lines->invoiced_quantity;
    try {
     $ss_line->save();
    } catch (Exception $e) {
     $dbc->rollback = true;
     echo "SO Line Update Failed!. Error @ class_hd_service_contract_header _update_so_lines @ line" . __LINE__ . $e->getMessage();
     return;
    }
   }
//update the invlice details
   $aptd = new hd_service_contract_detail();
   $all_details = $aptd->findBy_parentId($lines->hd_service_contract_line_id);
   foreach ($all_details as $details) {
    $new_aptd = new hd_service_contract_detail();
    $new_aptd_i = $new_aptd->findBy_id($details->hd_service_contract_detail_id);
    $new_aptd->status = 'Cancelled';
    $new_aptd->amount = '0.0';
    $new_aptd->hd_service_contract_detail_id = $new_aptd_i->hd_service_contract_detail_id;
    $new_aptd->audit_trial();
    try {
     $new_aptd->save();
    } catch (Exception $e) {
     echo "AP Transaction Details Update Failed!. Error @ class_hd_service_contract_header _transaction_cancell_poInv_lines " . $e->getMessage();
     return;
    }
   }

   //update the invoice lines
   $new_aptl = new hd_service_contract_line();
   $new_aptl_i = $new_aptl->findBy_id($lines->hd_service_contract_line_id);
   $new_aptl->status = 'Cancelled';
   $new_aptl->inv_line_quantity = '0.0';
   $new_aptl->inv_line_price = '0.0';
   $new_aptl->hd_service_contract_line_id = $new_aptl_i->hd_service_contract_line_id;
   $new_aptl->audit_trial();
   try {
    $new_aptl->save();
   } catch (Exception $e) {
    echo "AP Transaction Lines Update Failed!. Error @ class_hd_service_contract_header _transaction_cancell_poInv_lines " . $e->getMessage();
    return;
   }
  }
 }

 public function get_details_from_om_so_header() {
  if (empty($this->sd_so_header_id)) {
   return false;
  }
  $po = new om_so_header();
  $om_so_i = $po->findBy_id($this->sd_so_header_id);
  $this->bu_org_id = $om_so_i->bu_org_id;
  $this->transaction_type = 'INVOICE';
  $this->om_so_number = $om_so_i->om_so_number;
  $this->ar_customer_id = $om_so_i->ar_customer_id;
  $this->ar_customer_site_id = $om_so_i->ar_customer_site_id;
  $this->doc_currency = $om_so_i->currency;
  $this->payment_term_id = $om_so_i->payment_term_id;
 }

 public function multi_select_input_fields() {
  $multi_select_input = [
  ];
  return $multi_select_input;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'action_class_name',
   'mode',
   'action',
   'show_block',
  ];

  return $multi_select_hidden;
 }

}

//end of hd_service_contract_header class
?>