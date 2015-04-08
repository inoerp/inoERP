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
 * ec_confirm_order
 * 
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use ec_confirm_order rev only
class ec_confirm_order extends ec_user_cart {

 public $pageTitle = " Payment Confirmation "; //page Title
 private $_ar_customer_id;
 
 public function create_sales_order(){
  global $ino_user; $ino_user = new user();
  
  if(empty($ino_user->ar_customer_id)){
   //create a new customer
  }else{
   $this->_ar_customer_id = $ino_user->ar_customer_id;
  }

  $sd_so = new sd_so_header();
  $sd_so->order_source_type = 'ECOMMERCE';
  
  
  
  
 }
 
 private function _create_customer(){
  global $ino_user; $ino_user = new user();
  $cust = new ar_customer();
  $cust->customer_name = $ino_user->first_name . ' '. $ino_user->last_name. '-' .$ino_user->email ;
  $cust->customer_number = $ino_user->username.'-'.$ino_user->user_id;
  $cust->ship_to_id = $_SESSION['confirm_order']['ship_to_id'];
  $cust->bill_to_id = $_SESSION['confirm_order']['bill_to_id'];
  $cust->save();
  $this->_ar_customer_id = $cust->ar_customer_id;
 }

}

//end of ec_confirm_order class
?>