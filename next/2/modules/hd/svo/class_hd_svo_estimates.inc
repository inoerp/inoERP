<?php

class hd_svo_estimates extends dbObject {

 public static $table_name = "hd_svo_estimates";
 public static $primary_column = "hd_svo_estimates_id";
 public static $parent_primary_column = "hd_svo_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "hd";
 public static $billing_source_a = [
  'MANUAL' => 'Manual',
  'SYSTEM' => 'System',
 ];
 public static $line_status_a = [
  'PENDING_IMPORT' => 'Pending Import',
  'IMPORTED' => 'Imported',
 ];
//  data base variables as stored database column name
 public $field_a = [
  'hd_svo_estimates_id',
  'hd_svo_header_id',
  'item_id_m',
  'billing_source',
  'billing_type',
  'price_list_header_id',
  'quantity',
  'uom_id',
  'price_date',
  'unit_price',
  'line_price',
  'line_status',
  'sd_so_line_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $fields_inForm_notInDataBase = [
  "billing_item_number",
  "billing_description",
  "billing_uom"
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'hd_svo_header_id'
 ];
 public $requiredField = [
  'hd_svo_header_id',
  'item_id_m',
  'billing_source',
  'billing_type',
  'quantity',
 ];
 public $hd_svo_estimates_id;
 public $hd_svo_header_id;
 public $line_number;
 public $item_id_m;
 public $billing_source;
 public $billing_type;
 public $price_list_header_id;
 public $quantity;
 public $uom_id;
 public $action_type_id;
 public $price_date;
 public $unit_price;
 public $line_price;
 public $line_status;
 public $sd_so_line_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $msg;
 public $billing_item_number;
 public $billing_description;
 public $billing_uom;
 public $open_quantity;
 public $lot_number;
 public $serial_number;
 public $inv_serial_number_id;
 public $serial_number_id;
 public $serial_generation;
 public $lot_generation;
 private $_serial_type;

 public function _before_save() {
  if ((empty($this->line_status)) && (empty($this->sd_so_line_id))) {
   $this->line_status = 'PENDING_IMPORT';
   echo "<div class='alert alert-danger'>Line status is updated to <strong> " . $this->line_status . ".</strong></div> ";
  }else   if (!(empty($this->line_status)) && ($this->line_status='IMPORTED')) {
    echo "<div class='alert alert-danger'>You can't update lines with <strong> " . $this->line_status . ".</strong> status</div> ";
    return -90;
  }
 }

 public static function find_by_headerId_and_status($hd_svo_header_id, $line_status = 'PENDING_IMPORT') {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where hd_svo_header_id= '{$hd_svo_header_id}' AND line_status= '{$line_status}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_wipWoHeaderId_and_routingSequence($wip_wo_header_id, $routing_sequence) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where wip_wo_header_id= '{$wip_wo_header_id}' 
					 AND routing_sequence= '{$routing_sequence}' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public function findBy_woHeaderId_routingSeq() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE wip_wo_header_id = :wip_wo_header_id ";
  $sql .= " AND routing_sequence = :routing_sequence ";

  $param_a = ['wip_wo_header_id', 'routing_sequence'];
  $value_a = ['wip_wo_header_id' => $this->wip_wo_header_id, 'routing_sequence' => $this->routing_sequence];
  $result = $this->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? $result : false;
 }

}

//end of hd_svo_estimates class
?>