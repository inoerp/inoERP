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
 * hd_subscription_header CLass
 * Contains all the hd_subscription_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class hd_subscription_user extends hd_subscription_header {

 public static $system_info = [
  'name' => 'Subscription User',
  'number' => '5110',
  'description' => 'Create & Mainten Subscription User',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hd_subscription_line'),
  'primary_entity_cb' => '',
  'module_name' => 'sd',
  'weight' => 1
 ];

 public function search_pre_populate() {
  $employee_details = hr_employee::find_by_userId($_SESSION['user_id']);
  return array('employee_id' => $employee_details->hr_employee_id);
 }

}

//end of hd_subscription_header class
?>