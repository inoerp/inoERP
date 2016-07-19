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
 * inv_interorg_transfer_header
 * Contains all the inv_interorg_transfer_header information, such as - item_id_m, order_number,  from_org_id, to_org_id, etc.
 * 
 */
class inv_interorg_transfer_header extends dbObject {

 public static $table_name = "inv_interorg_transfer_header";
 public static $dependent_classes = ['inv_interorg_transfer_line'];
 public static $primary_column = "inv_interorg_transfer_header_id";
 public static $primary_column2 = "order_number";
 public static $key_column = 'from_org_id';
 public static $module = "inv"; //same as gl_journal_source
 public static $gl_journal_category = "INV_RECEIVING";
 public static $system_info = [
  'name' => 'InterOrg Transfer',
  'number' => '2134',
  'description' => 'Inventory InterOrg Transfer',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('inv_interorg_transfer_line'),
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 6
 ];
 public static $transaction_type_id_a = [
  '18' => 'Direct Inter-Org',
  '19' => 'In-transit Inter-Org',
 ];

  public $action_a = [
  'SHIP' => 'Ship Lines',
  'GENERATE_DOC' => 'Generate Shipping Documents',
 ];
  
 public $field_a = [
  'inv_interorg_transfer_header_id',
  'order_number',
  'comment',
  'from_org_id',
  'transaction_type_id',
  'to_org_id',
  'status',
  'transfer_to_gl',
  'transaction_date',
  'carrier',
  'vehicle_number',
  'waybill',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data

 public $initial_search = [
  'inv_interorg_transfer_header_id',
  'order_number',
  'comment',
 ];
 public $column = [
  'inv_interorg_transfer_header_id',
  'order_number',
  'comment',
  'from_org_id',
  'transaction_type_id',
  'to_org_id',
  'status',
  'transfer_to_gl',
  'transaction_date',
  'carrier',
  'vehicle_number',
  'waybill',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fields_inForm_notInDataBase = [
  "from_org",
  'to_org',
 ];
 public $requiredField = [
  'from_org_id',
  'transaction_type_id',
  'to_org_id',
 ];
 public $search = [
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Inter Org Transfer "; //page Title
 public $option_lists = [
  'inv_transaction_class' => 'TRANSACTION_TYPE_CLASS'
 ];
 public $inv_interorg_transfer_header_id;
 public $order_number;
 public $comment;
 public $from_org_id;
 public $transaction_type_id;
 public $to_org_id;
 public $status;
 public $transfer_to_gl;
 public $transaction_date;
 public $carrier;
 public $vehicle_number;
 public $waybill;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $action;

//  public function _before_save() {
//   if (($this->action == 'multi_interorg_transfer')) {
//    echo "<br> Starting interorg_transfer.";
//    pa($_POST);
//    return 10;
//   }
//  }

 public function _after_save() {
  if ((!empty($this->inv_interorg_transfer_header_id)) && empty($this->order_number)) {
   $this->order_number = $this->from_org_id . '-' . $this->inv_interorg_transfer_header_id;
   echo '<br/> System created order number is ' . $this->order_number;
   $this->save();
  }
 }

}

?>