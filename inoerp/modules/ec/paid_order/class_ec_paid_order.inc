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
 * ec_paid_order
 * 
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use ec_paid_order rev only


interface i_ec_create_paid_order {

 public function create_paid_order();
}

class ec_paid_order extends dbObject {

 public static $table_name = "ec_paid_order";
 public static $primary_column = "ec_paid_order_id";
 public static $key_column = 'paid_order_name';
 public static $module = "ec";
// public static $js_fileName = 'modules/inv/ec_paid_order/js/multi_select.js';
 public static $system_info = [
  'name' => 'eComm Paid Order',
  'number' => '4206',
  'description' => 'eCommerce Paid Orders',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ec',
  'weight' => 1
 ];
 public static $status_a = [
  'ENTERED' => 'Entered',
  'ERROR' => 'Errored',
  'CONVERTED' => 'Converted to SO',
 ];
 public $field_a = [
  'ec_paid_order_id',
  'payment_method_id',
  'total_amount',
  'doc_currency',
  'service_provider',
  'sp_transaction_id',
  'user_id',
  'email',
  'confirm_order_details',
  'sp_return_data',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'user_id',
  'email',
 ];
 public $column = [
  'ec_paid_order_id',
  'payment_method_id',
  'total_amount',
  'doc_currency',
  'service_provider',
  'sp_transaction_id',
  'user_id',
  'email',
  'status',
 ];
 public $requiredField = [
  'email',
  'confirm_order_details',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " eComm Paid Orders "; //page Title
 public $ec_paid_order_id;
 public $payment_method_id;
 public $total_amount;
 public $doc_currency;
 public $service_provider;
 public $sp_transaction_id;
 public $user_id;
 public $email;
 public $confirm_order_details;
 public $sp_return_data;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $message;
 public $prg_create_so_parameters = [
  'Cut Off Date' => 'search_cut_off_date',
 ];
 public $prg_create_so_details = [
  'name' => 'Generate Sales Orders',
  'description' => 'Generate Sales Orders From Paid eCommerce Orders',
 ];

 private function _findOrders_forSOImport($cut_off_date = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE status != 'CONVERTED' ";
  if (!empty($cut_off_date)) {
   $sql .= " AND ec_paid_order_id <='{$cut_off_date}' ";
  }
  $result = $this->findBySql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_all_assigned_orgs($ec_paid_order_number) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where ec_paid_order_number= '{$ec_paid_order_number}' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }

 public static function find_all_active_methods() {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where status= 'ACTIVE' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }

 private $_cut_off_date;

 public function prg_create_so($seralized_parameters) {
  global $dbc;
  $parameters = unserialize($seralized_parameters);

  if (!empty($parameters['cut_off_date'][0])) {
   $this->_cut_off_date = $parameters['cut_off_date'][0];
  }

  //ecommerce Control details
  $ec_con = new ec_control();
  $ec_con_details = $ec_con->findAll_singleRecord_db();

  //find all elligible orders & create SO
  $all_orders = $this->_findOrders_forSOImport($this->_cut_off_date);

  if (!empty($all_orders)) {
   foreach ($all_orders as $odkey => $ecp_order) {
    $this->message .= '<br> Trying to cerate SO for ec_paid_order_id : ' . $ecp_order->ec_paid_order_id;
    try {
     $so_header_id = $this->_create_sales_order($ecp_order, $ec_con_details);
     $this->message .= '<br> SO is Successfully Created. so_header_id is : ' . $so_header_id;
     //update ec_paid_order status
     $ec_paid_order_su = new ec_paid_order();
     $ec_paid_order_su->ec_paid_order_id = $ecp_order->ec_paid_order_id;
     $ec_paid_order_su->status = 'CONVERTED';
     $ec_paid_order_su->save();
    } catch (Exception $e) {
     $dbc->rollback = true;
     $this->message .= '<br> Failed to create sales order. Error @ ec_paid_order @@ line ' . __LINE__ . ' ' . $e->getMessage();
    }
   }
  } else {
   $this->message .= '<br> No elligible paid orders found for SO creation ';
  }

  return $this->message;
 }

 public function _create_sales_order($ecp_order, $ec_con_details) {
  global $dbc;
  $order_user = new ino_user();
  $order_user->findBy_id($ecp_order->user_id);

  $confirm_order_details = json_decode($ecp_order->confirm_order_details);
//  pa($confirm_order_details);
  $sp_return_data = $ecp_order->sp_return_data;

  if (empty($order_user->ar_customer_id)) {
   //create a new customer
   try {
    $ar_customer_id = $this->_create_customer($order_user);
   } catch (Exception $e) {
    $this->message .= '<br> Failed to create sales order. line Error @ ec_paid_order @@ line ' . __LINE__ . ' ' . $e->getMessage();
    $dbc->rollback = true;
    return false;
   }
  } else {
   $ar_customer_id = $order_user->ar_customer_id;
  }

  $sd_so = new sd_so_header();
  $sd_so->order_source_type = $ec_con_details->order_source_type;
  $sd_so->document_type = $ec_con_details->sales_document_type;
  $sd_so->ar_customer_id = $ar_customer_id;
  $sd_so->doc_currency = $confirm_order_details->sp_currency_code;
  $sd_so->bill_to_id = $confirm_order_details->bill_to_id;
  $sd_so->ship_to_id = $confirm_order_details->ship_to_id;
  $sd_so->header_amount = $confirm_order_details->total_amount[0];
  $sd_so->tax_amount = $confirm_order_details->tax_amount[0];
  $sd_so->prepaid_amount = $confirm_order_details->tax_amount[0];
//  $sd_so->prepaid_status = $sp_return_data->tax_amount[0];
  $sd_so->so_status = 'ENTERED';
  $sd_so->bu_org_id = $ec_con_details->bu_org_id;
  $org_i = org::find_financial_details_from_orgId($sd_so->bu_org_id);
  if (!empty($org_i) && !empty($org_i->currency_code)) {
   $sd_so->currency = $org_i->currency_code;
  } else {
   throw new Exception('No default currency found for the org id ' . $org_i->currency_code);
  }
  $sd_so->payment_term_id = $ec_con_details->payment_term_id;
  $sd_so->payment_term_date = current_time(true);
  $sd_so->exchange_rate_type = $ec_con_details->exchange_rate_type;
  $sd_so->order_reference_table = 'ec_confirm_order';
  $sd_so->order_reference_id = $ecp_order->ec_paid_order_id;
  try {
   $sd_so->save();
   $sd_so->_after_save();
  } catch (Exception $e) {
   $this->message .= '<br> Failed to create sales order. line Error @ ec_paid_order @@ line ' . __LINE__ . ' ' . $e->getMessage();
   $dbc->rollback = true;
   return false;
  }

  $ec_product_ids = $confirm_order_details->ec_product_id;
  foreach ($ec_product_ids as $k => $ec_product_id) {
   $sd_so_line = new sd_so_line();
   $sd_so_line->sd_so_header_id = $sd_so->sd_so_header_id;
   $product_details = ec_product::find_by_id($ec_product_id);
   $item_details = item::find_by_id($product_details->item_id_m);
   $sd_so_line->item_id_m = $product_details->item_id_m;
   $sd_so_line->shipping_org_id = $ec_con_details->shipping_org_id;
   $sd_so_line->sd_so_header_id = $sd_so->sd_so_header_id;
   $sd_so_line->item_description = $item_details->item_description;
   $sd_so_line->uom_id = $item_details->uom_id;
   $sd_so_line->line_number = ($k + 1);
   $sd_so_line->line_type = $ec_con_details->line_type;
   $sd_so_line->line_status = 'ENTERED';
   $sd_so_line->line_quantity = $confirm_order_details->quantity[$k];
   $sd_so_line->line_description = 'product_name : ' . $confirm_order_details->quantity[$k];
   $sd_so_line->line_price = $confirm_order_details->sales_price[$k];
   $sd_so_line->unit_price = $sd_so_line->line_price / $sd_so_line->line_quantity;
   $sd_so_line->tax_code_id = $confirm_order_details->tax_code[$k];
   $sd_so_line->supply_source = 'INV';
   try {
    $sd_so_line->save();
   } catch (Exception $e) {
    $this->message .= '<br> Failed to create sales order. line Error @ ec_paid_order @@ line ' . __LINE__ . ' ' . $e->getMessage();
    $dbc->rollback = true;
    return false;
   }
  }
  return $sd_so->sd_so_header_id;
 }

 private function _create_customer($order_user) {
  $cust = new ar_customer();
  $cust->customer_name = $order_user->first_name . ' ' . $order_user->last_name . '-' . $order_user->email;
  $cust->customer_number = $order_user->username . '-' . $order_user->user_id;
  $cust->ship_to_id = $_SESSION['confirm_order']['ship_to_id'];
  $cust->bill_to_id = $_SESSION['confirm_order']['bill_to_id'];
  $cust->save();

  $user = new ino_user();
  $user->ino_user_id = $order_user->user_id;
  $user->ar_customer_id = $cust->ar_customer_id;
  $user->save();

  return $cust->ar_customer_id;
 }

}

//end of ec_paid_order class
?>