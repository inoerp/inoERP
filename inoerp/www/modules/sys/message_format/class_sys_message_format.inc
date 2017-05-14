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
 * sys_message_format
 * 
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use sys_message_format rev only

class sys_message_format extends dbObject {

 public static $table_name = "sys_message_format";
 public static $primary_column = "sys_message_format_id";
 public static $key_column = 'format_name';
 public static $module = "ec";
// public static $js_fileName = 'modules/inv/sys_message_format/js/multi_select.js';
 public static $system_info = [
  'name' => 'Message Format',
  'number' => '8101',
  'description' => 'Message Format',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 1
 ];
 
 public static $content_type_a = [
  'TEXT' => 'Text',
  'HTML' => 'HTML'
 ];
 public $field_a = [
  'sys_message_format_id',
  'format_name',
  'description',
  'message_subject',
  'message_body',
  'content_type',
  'cc_email',
  'from_name',
  'from_email',
  'reply_to',
  'use_smtp_cb',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'format_name',
 ];
 public $requiredField = [
  'format_name',
  'message_subject',
  'message_body',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Message Format "; //page Title
 public $sys_message_format_id;
 public $format_name;
 public $description;
 public $message_subject;
 public $message_body;
 public $content_type;
 public $cc_email;
 public $from_name;
 public $from_email;
 public $reply_to;
 public $use_smtp_cb;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public static $form_template_name = 'f_single_form1_template.php';
 public static $header_tab = [
  'basic_info' => [
   'ec_payment_method_id' => 'search_text_field'
  ]
 ];
 
 public static $header_tab1 = [
  ['name' => 'ec_payment_method_id' , 'type' => 'l_text_field_dr_withSearch'],
  ['name' => 'payment_method_name' , 'type' => 'l_text_field_dm'],
  ['name' => 'payment_method_name' , 'type' => 'l_text_field_dm'],
  ['name' => 'payment_method_name' , 'type' => 'l_text_field_d'],
  ['name' => 'payment_method_name' , 'type' => 'l_text_field_d'],
  ['name' => 'payment_method_name' , 'type' => 'l_text_field_d'],
 ];

 public function findBy_sys_message_format_id_m($sys_message_format_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE sys_message_format_id = sys_message_format_id_m ";
  $sql .= " AND sys_message_format_id = '{$sys_message_format_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_assigned_orgs($sys_message_format_number) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where sys_message_format_number= '{$sys_message_format_number}' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }

 public static function find_all_active_methods() {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where status= 'ACTIVE' ";
  $result = $db->find_by_sql($sql);
  return $result;
 }

}

//end of sys_message_format class
?>