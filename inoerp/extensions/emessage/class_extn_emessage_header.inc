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
 * extn_emessage_header CLass
 * Contains all the extn_emessage_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class extn_emessage_header extends dbObject {

 public static $table_name = "extn_emessage_header";
 public static $dependent_classes = ['extn_emessage_line'];
 public static $primary_column = "extn_emessage_header_id";
 public static $key_column = 'user_id1';
 public static $module = "extn";
 public static $system_info = [
  'name' => 'E Message',
  'number' => '5107',
  'description' => 'Create & Mainten Message',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('extn_emessage_line'),
  'primary_entity_cb' => '',
  'module_name' => 'extn',
  'weight' => 1
 ];
 public $field_a = [
  'extn_emessage_header_id',
  'user_id1',
  'user_id2',
  'user_id_comb',
  'user1_deleted_cb',
  'user2_deleted_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'user_id1',
  'user_id2',
 ];
 public $requiredField = [
  'user_id1',
  'user_id2',
  'user_id_comb',
 ];
 public $fields_inForm_notInDataBase = [
  'action',
  'user_name1',
  'user_name2'
 ];
// public $search = [
//  '_show_update_path' => 1,
//  '_show_view_path' => 1
// ];
 public $pageTitle = " Message "; //page Title
 public $extn_emessage_header_id;
 public $user_id1;
 public $user_id2;
 public $user_id_comb;
 public $user1_deleted_cb;
 public $user2_deleted_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function primary_service_type() {
  $option_header = option_header::find_by_name('HD_PRI_SERVICE_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function billing_type() {
  $option_header = option_header::find_by_name('SYS_BILLING_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

}

//end of extn_emessage_header class
?>