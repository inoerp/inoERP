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
 * ec_payment_method
 * 
 * 
 */
// public $rev_enabled_cb;  needs to be dropped - use ec_payment_method rev only

class ec_payment_method extends dbObject {

 public static $table_name = "ec_payment_method";
 public static $primary_column = "ec_payment_method_id";
 public static $key_column = 'payment_method_name';
 public static $module = "ec";
// public static $js_fileName = 'modules/inv/ec_payment_method/js/multi_select.js';
 public static $system_info = [
  'name' => 'eComm Payment Method',
  'number' => '4207',
  'description' => 'eCommerce Payment Methods',
  'version' => '0.1.4',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'ec',
  'weight' => 1
 ];
 public $field_a = [
  'ec_payment_method_id',
  'payment_method_name',
  'display_name',
  'user_message',
  'submit_button_name',
  'type',
  'mode',
  'username',
  'password',
  'signature',
  'doc_currency',
  'return_url',
  'cancel_url',
  'confirm_url',
  'image_file_id',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'payment_method_name',
 ];
 public $requiredField = [
  'payment_method_name',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " eComm Payment Method "; //page Title
 public $payment_method_name;
 public $display_name;
 public $submit_button_name;
 public $user_message;
 public $image_file_id;
 public $ec_payment_method_id;
 public $type;
 public $mode;
 public $username;
 public $password;
 public $signature;
 public $doc_currency;
 public $return_url;
 public $cancel_url;
 public $confirm_url;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function findBy_ec_payment_method_id_m($ec_payment_method_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE ec_payment_method_id = ec_payment_method_id_m ";
  $sql .= " AND ec_payment_method_id = '{$ec_payment_method_id}' ";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_all_assigned_orgs($ec_payment_method_number) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where ec_payment_method_number= '{$ec_payment_method_number}' ";
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

 public static function show_payment_methods($total_amount, $curr, $ship_to_id, $bill_to_id, $btn_div_clas = "btn-warning") {
  global $f;
  $all_payment_methods = self::find_all_active_methods();
  $stmt = '';
  foreach ($all_payment_methods as $k => $pm) {
   $method_div_id = 'payment_method' . $k;
   $stmt .= '<button class="btn ' . $btn_div_clas . '" type="button" data-toggle="collapse" 
    data-target="#' . $method_div_id . '" aria-expanded="false" aria-controls="' . $method_div_id . '">' . $pm->display_name .
    '</button>
     <div class="collapse" id="' . $method_div_id . '">';
   $stmt .= '<div class="well">';
   $action_linl = HOME_URL . $pm->confirm_url;
   $stmt .= '<form action="' . $action_linl . '"  method="post" id="payment_confirmation"  name="payment_confirmation">';
   $stmt .= $f->hidden_field('ec_payment_method_id', $pm->ec_payment_method_id);
   $stmt .= $f->hidden_field('ship_to_id', $ship_to_id);
   $stmt .= $f->hidden_field('bill_to_id', $bill_to_id);
   $stmt .= $f->hidden_field('total_amount', $total_amount);
   $stmt .= $f->hidden_field('doc_currency', $curr);
   
   if (!empty($pm->user_message)) {
    $stmt .= '<p>'.$pm->user_message .'</p>';
   }
   if (!empty($pm->image_file_id)) {
    $img_file = extn_file::find_by_id($pm->image_file_id);
    $stmt .= '<input type="image" class="img-height-120" name="submit" src="' . HOME_URL . $img_file->file_path . $img_file->file_name . '" border="0" alt="Submit" />';
   } else {
    $stmt .= '<input class="btn btn-warning ino-btn" type="submit" value="' . $pm->submit_button_name . '" name="submit" role="button">';
   }
   $stmt .= '</form>';
   $stmt .= '</div>';
   $stmt .= '</div>';
  }
  return $stmt;
 }

}

//end of ec_payment_method class
?>