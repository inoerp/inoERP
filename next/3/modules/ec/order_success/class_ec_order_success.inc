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
 * ec_order_success
 * 
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use ec_order_success rev only

class ec_order_success extends ec_paid_order {

public static $system_info = [
  'name' => 'EC Order Sucess',
  'number' => '4205',
  'description' => 'EC Order Sucess',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ec',
  'weight' => 1
 ];

}

//end of ec_order_success class
?>