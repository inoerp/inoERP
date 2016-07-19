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
 
public static $system_info = [
  'name' => 'EC Confirm Order',
  'number' => '4203',
  'description' => 'EC Confirm Order',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ec',
  'weight' => 1
 ];

}

//end of ec_confirm_order class
?>