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
class pos_tt_header extends pos_transaction_header {

  public static $system_info = [
  'name' => 'POS Transaction Header',
  'number' => '2725',
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
}

//end of path class
?>
