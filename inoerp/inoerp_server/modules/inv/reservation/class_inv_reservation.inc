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
 * inv_reservation
 * Contains all the inv_reservation information, such as - inv_reservation, inv_reservation_id, org_id,  type, etc.
 * 
 */
class inv_reservation extends dbObject {

 public static $table_name = "inv_reservation";
 public static $primary_column = "inv_reservation_id";
 public static $key_column = 'demand_quantity';
 public static $module = "inv";
 public static $multi_select_template_path = 'modules/inv/reservation/multi_action/inv_reservation_template_ma.php';
// public static $js_fileName = 'modules/inv/reservation/multi_action/ma_reservation.js';
 public static $system_info = [
  'name' => 'Inventory Reservation',
  'number' => '2121',
  'description' => 'inv_reservation',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 17
 ];
 public static $demand_type_a = [
  'SALES_ORDER' => 'Sales Order',
  'DELIVERY_LINE' => 'Delivery Line',
  'MISC' => 'Miscellaneous',
 ];
 public static $supply_type_a = [
  'ONHAND' => 'Onhand Quantity'
 ];
 public $field_a = [
  'inv_reservation_id',
  'item_id_m',
  'org_id',
  'status',
  'demand_type',
  'sd_so_header_id',
  'sd_so_line_id',
  'd_reference_key_name',
  'd_reference_key_value',
  'demand_comment',
  'need_by_date',
  'uom_id',
  'demand_quantity',
  'supply_type',
  'subinventory_id',
  'locator_id',
  's_reference_key_name',
  's_reference_key_value',
  'supply_comment',
  'inv_serial_number_id',
  'inv_lot_number_id',
  'reason',
  'onhand_id',
  'reservation_type',
  'reference_key_name',
  'reference_key_value',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'item_id_m',
  'description',
  'sd_so_line_id'
 ];
 public $search_functions = [
  'Item From' => 'search_item_number_from',
  'Item To' => 'search_item_number_to',
  'Organization' => 'search_org_name',
 ];
 public $requiredField = [
  'item_id_m',
  'org_id',
  'demand_type',
  'd_reference_key_name',
  'd_reference_key_value',
  'need_by_date',
  'uom_id',
  'demand_quantity',
  'supply_type',
  's_reference_key_name',
  's_reference_key_value',
 ];
 public $fields_inForm_notInDataBase = [
  "item_number",
  "item_description",
  'so_number',
  'so_line_number',
  'serial_number',
  'lot_number',
  'onhand',
  'reservable_onhand'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Reservation"; //page Title
 public $inv_reservation_id;
 public $item_id_m;
 public $org_id;
 public $status;
 public $demand_type;
 public $sd_so_header_id;
 public $sd_so_line_id;
 public $d_reference_key_name;
 public $d_reference_key_value;
 public $demand_comment;
 public $need_by_date;
 public $uom_id;
 public $demand_quantity;
 public $supply_type;
 public $subinventory_id;
 public $locator_id;
 public $s_reference_key_name;
 public $s_reference_key_value;
 public $supply_comment;
 public $inv_serial_number_id;
 public $inv_lot_number_id;
 public $reason;
 public $reservation_type;
 public $reference_key_name;
 public $reference_key_value;
 public $onhand_id;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $item_number;
 public $item_description;
 public $so_number;
 public $so_line_number;
 public $serial_number;
 public $lot_number;
 public $onhand;
 public $reservable_onhand;

 public function _before_save() {
  if (empty($this->reservable_onhand) || $this->reservable_onhand < $this->demand_quantity) {
   echo "<div class='alert alert-danger'>Error - Reservable Onhand is less than demand onhand </div>";
   return -90;
  }

  if (empty($this->inv_reservation_id)) {
   $this->_set_defult_values();
  }
 }

 private function _set_defult_values() {
  if (!empty($this->sd_so_line_id)) {
   $this->d_reference_key_name = 'sd_so_line';
   $this->d_reference_key_value = $this->sd_so_line_id;
  } else if ($this->demand_type == 'MISC') {
   $this->d_reference_key_name = 'MISC';
   $this->d_reference_key_value = '-1';
  }

  if (!empty($this->onhand_id)) {
   $this->s_reference_key_name = 'onhand';
   $this->s_reference_key_value = $this->onhand_id;
  }

  if (!empty($this->inv_serial_number_id)) {
   $this->demand_quantity = 1;
  }
 }

 public function remove_reservation(array $reservationid_qty_a) {
  foreach ($reservationid_qty_a as $res_id => $qty) {
   $res = new inv_reservation();
   $res->findBy_id($res_id);

   if ($qty >= $res->demand_quantity) {
    $res->delete();
   } else {
    $res->demand_quantity = $res->demand_quantity - $qty;
    $res->save();
   }
  }
 }

 public static function find_by_demandReference($d_reference_key_n, $d_reference_key_v) {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE d_reference_key_name = '{$d_reference_key_n}' ";
  $sql .= " AND d_reference_key_value = '{$d_reference_key_v}' ";

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_serialNumberId($inv_serial_number_id) {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE inv_serial_number_id = '{$inv_serial_number_id}' ";
  $sql = ino_perPageSql_i($sql, 1);


  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_lotNumberId($inv_lot_number_id) {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE inv_lot_number_id = '{$inv_lot_number_id}' ";


  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_demandReference_onhandReference($d_reference_key_n, $d_reference_key_v, $onhand_id) {
  $sql = " SELECT * FROM  ";
  $sql .= self::$table_name;
  $sql .= " WHERE d_reference_key_name = '{$d_reference_key_n}' ";
  $sql .= " AND d_reference_key_value = '{$d_reference_key_v}' ";
  $sql .= " AND s_reference_key_name = 'onhand' ";
  $sql .= " AND s_reference_key_value = '{$onhand_id}' ";
//  echo $sql;

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of inv_reservation class
?>