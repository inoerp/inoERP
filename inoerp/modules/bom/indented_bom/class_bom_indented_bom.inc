<?php

/**
 * inoERP 
 *
 * Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * indented_bom
 * Used for showing all the items in each level of a make item
 * Routing specifies the flow of matrial in the production line
 * 
 */
class bom_indented_bom extends bom_header {

 public static $system_info = [
  'name' => 'Indented BOM',
  'number' => '2429',
  'description' => 'Define and mainten bill of materials',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'bom',
  'weight' => '9'
 ];

}

//end of po_detail class
?>