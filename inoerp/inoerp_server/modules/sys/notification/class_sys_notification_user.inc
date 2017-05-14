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
 * sys_notification_user
 *
 */


 class sys_notification_user extends sys_notification {
  public static $system_info = [
  'name' => 'User Notification',
  'number' => '9107',
  'description' => 'User Notifications',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 7
 ];
  public function search_pre_populate() {
   return array('to_user_id' => $_SESSION['user_id']);
  }

 }

//end of sys_notification class
?>