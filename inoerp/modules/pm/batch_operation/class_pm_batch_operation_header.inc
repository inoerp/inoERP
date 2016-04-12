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
 * pm_process_operation_header CLass
 * Contains all the pm_process_operation_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class pm_batch_operation_header extends pm_process_operation_header {

 public static $dependent_classes = ['pm_batch_operation_line', 'pm_batch_operation_detail'];
 public static $module = "pm";
 public static $system_info = [
  'name' => 'Operation Batch',
  'number' => '5108',
  'description' => 'Create & Mainten Process Batch',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('pm_batch_operation_line', 'pm_batch_operation_detail'),
  'primary_entity_cb' => '',
  'module_name' => 'hd',
  'weight' => 1
 ];
  public $fields_inForm_notInDataBase = [
  "pm_batch_header_id",
 ];
  
 public $pm_batch_header_id;
 
 public $pageTitle = "Batch Header "; //page Title

 public function _before_save() {
  
 }

}

//end of pm_process_operation_header class
?>