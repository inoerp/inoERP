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
 * ec_product
 * 
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use ec_product rev only
class ec_product_view extends ec_product {

 public static $system_info = [
  'name' => 'eComm Product',
  'number' => '4209',
  'description' => 'eCommerce Products',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'am',
  'weight' => 1
 ];

}

//end of ec_product class
?>