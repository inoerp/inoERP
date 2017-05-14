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
 * pos_transaction_header
 * Contains all the pos_transaction_header information, such as - price_list, module_name, description,  currency_code, etc.
 * 
 */
class pos_transaction_header extends dbObject {

 public static $table_name = "pos_transaction_header";
 public static $primary_column = "pos_transaction_header_id";
 public static $dependent_classes = ['pos_transaction_line'];
 public static $key_column = "terminal_name";
 public static $module = "pos";
 public static $dont_show_save_msg = true;
 public static $system_info = [
  'name' => 'POS Transaction',
  'number' => '2724',
  'description' => 'Point Of Sale Transaction',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'dependent_class' => array('pos_transaction_line'),
  'primary_entity_cb' => '',
  'module_name' => 'pos',
  'weight' => 2
 ];
 public $field_a = [
  'pos_transaction_header_id',
  'terminal_name',
  'currency_code',
  'header_amount',
  'tax_amount',
  'discount_amount',
  'total_amount',
  'description',
  'ar_customer_id',
  'ar_customer_site_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $checkbox = [
  'allow_mutli_currency_cb'
 ];
 public $initial_search = [
  'pos_transaction_header_id',
 ];
 public $requiredField = [
  'terminal_name'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Point Of Sales "; //page Title
 public $pos_transaction_header_id;
 public $terminal_name;
 public $currency_code;
 public $header_amount;
 public $tax_amount;
 public $discount_amount;
 public $total_amount;
 public $description;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 private $_stores_for_sync;
 private $_sync_cash_amount;
 private $_sync_org_id;
 private $_sync_tax_amount = 0;
 private $_total_amount = 0;
 private $_sync_cash_ac_id;
 private $_sync_revenue_ac_id;
 private $_sync_tax_ac_id;
 public $message;
 public $prg_sync_pos_with_inv_parameters = [
  'Organization' => 'search_org_name',
  'Store' => 'search_sd_store',
 ];
 public $prg_sync_pos_with_inv_details = [
  'name' => 'Sync POS with Inventory',
  'description' => 'Sync POS transaction with Inventory',
 ];

 public static function profile_pos_transaction_org() {
  $line_data_array = [];
  $line_data_array['line_key'] = 'org_id';
  $line_data_array['line_desc'] = 'org';
  $line_data_array['line_values'] = org::find_all_inventory();
  return $line_data_array;
 }

 public static function find_POSPrice_by_ItemIdM_orgId($Item_id_m, $org_id) {
  $sql = "SELECT plh.mdm_price_list_header_id, pll.mdm_price_list_line_id, pll.org_id, pll.item_id_m, pll.unit_price
FROM mdm_price_list_header plh,
mdm_price_list_line pll,
inventory inv

WHERE pll.mdm_price_list_header_id = plh.mdm_price_list_header_id
AND inv.pos_price_list_header_id = plh.mdm_price_list_header_id
AND inv.org_id = '{$org_id}'
AND pll.item_id_m = '{$Item_id_m}'
AND pll.effective_start_date <= NOW()
AND ( pll.effective_end_date >= NOW() OR  pll.effective_end_date IS NULL)
";
$sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : '';
 }

 private function _sync_pos_by_terminalId($terminal_id) {
  global $dbc;
  //find all transaction lines need to be synchronized
  $sql = " SELECT ptl.pos_transaction_line_id, ptl.pos_transaction_header_id,  ptl.item_number, pth.currency_code,  
   item.item_id_m, ptl.unit_price,  ptl.quantity,  ptl.line_amount,  ptl.amount_after_discount,
 ptl.discount_percentage,  ptl.discount_amount,  ptl.discount_code,  ptl.status, ss.org_id,
 item.item_id_m, pic.transaction_subinventory_id,pth.tax_amount, pth.total_amount,
pic.transaction_locator_id, item.uom_id, 
IFNULL(ss.cogs_ac_id, pic.cogs_ac_id) as cogs_ac_id ,
 ss.revenue_ac_id, ss.cash_ac_id, ss.sd_store_id, ss.tax_ac_id
 
FROM pos_transaction_line ptl,
pos_transaction_header pth,
pos_terminal pt,
sd_store ss,
pos_inv_control pic,
item

WHERE  pth.pos_transaction_header_id = ptl.pos_transaction_header_id
AND ( ptl.status IS NULL || ptl.status != 'S' )
AND pt.terminal_name = pth.terminal_name
AND ss.sd_store_id = pt.sd_store_id
AND pic.org_id = ss.org_id
AND item.org_id = ss.org_id
AND item.item_number  = ptl.item_number
AND pt.pos_terminal_id = '{$terminal_id}'
";

  $transaction_lines = self::find_by_sql($sql);
//  pa($transaction_lines);
  if (empty($transaction_lines)) {
   return;
  }
  $pos_transaction_header_id = null;
  foreach ($transaction_lines as $tl_record) {

   $store_subinventories = sd_store_subinventory::find_by_parent_id($tl_record->sd_store_id);
   $from_subinventory_id = null;
   $from_locator_id = null;
   foreach ($store_subinventories as $subinv) {
    $onhandv = onhand_v::find_by_itemIdM_orgId_subInventoryId($tl_record->item_id_m, $tl_record->org_id, $subinv->subinventory_id);
    if (empty($onhandv)) {
     continue;
    } else {
//     pa($onhandv);
     $from_subinventory_id = $onhandv[0]->subinventory_id;
     $from_locator_id = $onhandv[0]->locator_id;
     break;
    }
   }
   if (empty($from_subinventory_id)) {
    $this->msg .= "No onhand found for " . $tl_record->item_id_m;
    continue;
   }
   $invt = new inv_transaction();
   $invt->transaction_type_id = 22;
   $invt->org_id = $tl_record->org_id;
   $invt->from_subinventory_id = $from_subinventory_id;
   $invt->from_locator_id = $from_locator_id;
   $invt->item_id_m = $tl_record->item_id_m;
   $invt->uom_id = $tl_record->uom_id;
   $invt->setProperty('_dr_ac_id', $tl_record->cogs_ac_id);
   $invt->org_id = $tl_record->org_id;
   $invt->quantity = $tl_record->quantity;
   $invt->reference_type = 'table';
   $invt->reference_key_name = 'pos_transaction_header';
   $invt->reference_key_value = $tl_record->pos_transaction_header_id;
   $invt->reason = 'PSO Transaction';
   $invt->sd_so_line_id = $tl_record->pos_transaction_line_id;
   try {
    $invt->_before_save();
    $invt->save();
    $invt->_after_save();
//    pa($invt);
    $this->msg .= "<br>Inventory Transaction is Successfully Created for POS transaction id " . $tl_record->pos_transaction_header_id;
   } catch (Exception $e) {
    $this->msg .= "<br>Failed to Complete the inventory transaction. Error @ pos transaction_header @@ " . __LINE__ . $e->getMessage();
    $dbc->rollback = true;
   }


   $pos_tnx_line = new pos_transaction_line();
   $pos_tnx_line->findBy_id($tl_record->pos_transaction_line_id);
   try {
    $pos_tnx_line->status = 'S';
    $pos_tnx_line->save();
   } catch (Exception $e) {
    $this->msg .= "<br>Failed to update POS transaction line status. Error @ pos transaction_header @@ " . __LINE__ . $e->getMessage();
    $dbc->rollback = true;
   }

   //create journal for cash, revenue & tax amount
   if (empty($pos_transaction_header_id) || $pos_transaction_header_id !== $tl_record->pos_transaction_header_id) {
    pa($tl_record);
    $pos_transaction_header_id = $tl_record->pos_transaction_header_id;
    $this->_sync_tax_amount = $tl_record->tax_amount;
    $this->_total_amount = $tl_record->total_amount;
    $this->_sync_cash_ac_id = $tl_record->cash_ac_id;
    $this->_sync_tax_ac_id = $tl_record->tax_ac_id;
    $this->_sync_revenue_ac_id = $tl_record->revenue_ac_id;
    $this->_save_journal($tl_record);
   }
  }
 }

 public function prg_sync_pos_with_inv($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message .= '<br> Staring synchronization of POS & Inventory';
  if (!empty($parameters['org_id'][0])) {
   $this->_sync_org_id = $parameters['org_id'][0];
   $this->message .= '<br> Entered Org Id is : ' . $this->_sync_org_id;
   $all_stores = sd_store::find_by_orgId($this->_sync_org_id);
   if (empty($all_stores)) {
    $this->message .= '<br> Error! : No stores found for the above org_id. Error @ pos_transaction_header ' . __LINE__;
    return $this->message;
   } else {
    $this->_stores_for_sync = $all_stores;
   }
  }

  if (!empty($parameters['sd_store_id'][0])) {
   $sd_store_id = $parameters['sd_store_id'][0];
   $this->_stores_for_sync = array(sd_store::find_by_id($sd_store_id));
   $this->_sync_org_id = $this->_stores_for_sync[0]->org_id;
   $this->message .= '<br> Entered store Id is : ' . $this->_stores_for_sync;
  }

//create inventory transaction for all pos_transaction_lines and update the line status as synchronized

  if (!empty($this->_stores_for_sync)) {

   if (is_array($this->_stores_for_sync)) {
    foreach ($this->_stores_for_sync as $store_record) {
     $this->_sync_tax_amount = 0;
     $this->_line_amount_after_discount = 0;
     $terminals_for_sync = pos_terminal::find_by_storeId($store_record->sd_store_id);
     foreach ($terminals_for_sync as $terminals) {
      try {
       $this->_sync_pos_by_terminalId($terminals->pos_terminal_id);
       $this->message .= "<br/>Sync is Successfullycompleted for termianl id " . $terminals->pos_terminal_id;
      } catch (Exception $e) {
       $this->message .= "<br/>Sync failed fialed for termianl id " . $terminals->pos_terminal_id . $e->getMessage();
      }
     }
    }
   }
   return $this->message;
  }
 }

 private function _save_journal($tl_record) {
  global $dbc;
  $gjh = new gl_journal_header;
  $org_details = org::find_financial_details_from_orgId($this->_sync_org_id);

  $gjh->ledger_id = $org_details->ledger_id;
  $gjh->status = 'ENTERED';
  $gjh->currency = $org_details->currency_code;

  $gp = new gl_period();
  if (empty($org_details->period_id)) {
   $open_period = $gp->current_open_period($org_details->ledger_id, 'OPEN');
   $gjh->period_id = $open_period->gl_period_id;
  }

  $gjh->journal_source = self::$module;
  $gjh->journal_category = 'POS_TRANSACTION';
  $gjh->reference_type = 'table';
  $gjh->reference_key_name = self::$table_name;
  $gjh->reference_key_value = $tl_record->pos_transaction_header_id;
  $gjh->journal_name = $gjh->journal_category . '-' . $gjh->reference_key_value;
  $gjh->description = $gjh->journal_name . '-' . current_time();
  $gjh->balance_type = 'A';
  try {
   $gjh->save();
   $this->gl_journal_header_id = $gjh->gl_journal_header_id;
   $this->msg .= "<br> Jounral Header Id #" . $this->gl_journal_header_id . ' is created';
  } catch (Exception $e) {
   $dbc->rollback = true;
   $this->msg .= "<br> Failed Saving Jounral Header" . $e->getMessage();
   return;
  }

  $j_line_num = 1;
  //Revenue & Tax
  $new_gjl = new gl_journal_line();
  $new_gjl->gl_journal_header_id = $gjh->gl_journal_header_id;
  $new_gjl->reference_key_name = self::$table_name;
//  $new_gjl->reference_key_value = $deatils->ar_transaction_detail_id;
  $new_gjl->gl_journal_line_id = null;
  $new_gjl->line_num = $j_line_num;
  $j_line_num++;
  $new_gjl->status = 'U';
  $new_gjl->code_combination_id = $this->_sync_revenue_ac_id;
  $new_gjl->total_cr = $this->_total_amount;
  $new_gjl->total_ac_cr = $this->_total_amount;
  $new_gjl->description = 'POS Sync';
  $new_gjl->reference_type = '';
  $new_gjl->save();

  $new_gjl->total_cr = $new_gjl->total_ac_cr = 0;
  if (!empty($this->_sync_tax_amount)) {
   $new_gjl->gl_journal_line_id = null;
   $new_gjl->line_num = $j_line_num;
   $j_line_num++;
   $new_gjl->code_combination_id = $this->_sync_tax_ac_id;
   $new_gjl->total_cr = $this->_sync_tax_amount;
   $new_gjl->total_ac_cr = $this->_sync_tax_amount;
   $new_gjl->description = 'POS Sync';
   $new_gjl->save();
  }


//	save the Cash Account
  $new_gjl->gl_journal_line_id = null;
  $new_gjl->line_num = $j_line_num;
  $j_line_num++;
  $new_gjl->code_combination_id = $this->_sync_cash_ac_id;
  $new_gjl->total_dr = $this->_total_amount - $this->_sync_tax_amount;
  $new_gjl->total_ac_dr = $this->_total_amount - $this->_sync_tax_amount;
  $new_gjl->description = 'POS Sync';
  $new_gjl->save();
  pa($new_gjl);
 }

}

//end of path class
?>
