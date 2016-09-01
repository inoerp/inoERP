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
 * sys_rfid_interface
 * Contains all the sys_rfid_interface information, such as - sys_rfid_interface, sys_rfid_interface_id, org_id,  type, etc.
 * 
 */
class sys_rfid_interface extends dbObject {

 public static $table_name = "sys_rfid_interface";
 public static $primary_column = "sys_rfid_interface_id";
 public static $key_column = 'epc';
 public static $module = "sys";
 public static $multi_select_template_path = 'modules/prj/burden_costcode/multi_action/sys_rfid_interface_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'RFID Interface',
  'number' => '9113',
  'description' => 'RFID Interface',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 17
 ];
 public $field_a = [
  'sys_rfid_interface_id',
  'epc',
  'tag_number',
  'antena_number',
  'time_stamp',
  'description',
  'readcount',
  'org_id',
  'item_id_m',
  'from_subinventory_id',
  'from_subinventory',
  'transaction_type_id',
  'transaction_type',
  'quantity',
  'item_description',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'epc',
  'tag_number',
 ];
 public $requiredField = [
  'epc',
  'status',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " RFID Interface "; //page Title
 public $sys_rfid_interface_id;
 public $epc;
 public $tag_number;
 public $antena_number;
 public $time_stamp;
 public $description;
 public $readcount;
 public $org_id;
 public $item_id_m;
 public $from_subinventory_id;
 public $from_subinventory;
 public $transaction_type_id;
 public $transaction_type;
 public $quantity;
 public $item_description;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of sys_rfid_interface class
?>