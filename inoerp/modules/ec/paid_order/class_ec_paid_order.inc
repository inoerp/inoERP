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
  'name' => 'eComm Payment Method',
  'number' => '1401',
  'description' => 'eCommerce Payment Methods',
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

 public function findBy_ec_paid_order_id_m($ec_paid_order_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ec_paid_order_id = ec_paid_order_id_m ";
  $sql .= " AND ec_paid_order_id = '{$ec_paid_order_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
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

 

}

//end of ec_paid_order class
?>