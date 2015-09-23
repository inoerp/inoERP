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
 * ec_cart
 * 
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use ec_cart rev only
class ec_user_cart extends ec_cart {
public static $system_info = [
  'name' => 'User Cart',
  'number' => '4202',
  'description' => 'User Product Cart',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ec',
  'weight' => 1
 ];

}

//end of ec_cart class
?>