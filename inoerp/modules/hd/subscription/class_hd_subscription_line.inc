<?php

class hd_subscription_line extends dbObject {

 public static $table_name = "hd_subscription_line";
 public static $primary_column = "hd_subscription_line_id";
 public static $parent_primary_column = "hd_subscription_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "hd";
 public $line_status_a = [
  'ENTERED' => 'Entered',
  'AWAITING_PICKING' => 'Awaiting Picking',
  'PICKED' => 'Picked',
  'PARTIAL_PICKED' => 'Partially Picked',
  'SHIPPED' => 'Shipped',
  'PARTIAL_SHIPPED' => 'Partial Shipped',
  'AWAITING_INVOICING' => 'Awaiting Invoicing',
  'AWAITING_CLOSING' => 'Awaiting Closing',
  'CLOSED' => 'Closed',
 ];
 public $field_a = [
  'hd_subscription_line_id',
  'hd_subscription_header_id',
  'line_number',
  'shipping_org_id',
  'item_id_m',
  'item_description',
  'line_quantity',
  'invoiced_quantity',
  'price_list_header_id',
  'price_date',
  'unit_price',
  'line_price',
  'tax_amount',
  'gl_line_price',
  'gl_tax_amount',
  'tax_code_id',
  'line_status',
  'line_type',
  'uom_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  "hd_subscription_header_id",
  "so_number",
  "item_id_m",
  "item_number",
  "item_description",
  'shipping_org_id'
 ];
 public $requiredField = [
  'hd_subscription_header_id',
  'line_number',
  'item_description'
 ];
 public $numberField = [
  'exchange_rate',
  'line_quantity',
  'unit_price',
  'line_price',
  'gl_line_price',
  'gl_tax_amount'
 ];
 public $fields_inForm_notInDataBase = [
  "so_number",
  "item_number",
  'tax_code_value',
  'ar_transaction_number',
  'line_action'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "hd_subscription_header_id"
 ];
 public $notUpdatedFromWebForm = [
  'actual_ship_date',
 ];
 public $hd_subscription_line_id;
 public $hd_subscription_header_id;
 public $line_number;
 public $shipping_org_id;
 public $item_id_m;
 public $item_description;
 public $line_quantity;
 public $invoiced_quantity;
 public $price_list_header_id;
 public $price_date;
 public $unit_price;
 public $line_price;
 public $tax_amount;
 public $gl_line_price;
 public $gl_tax_amount;
 public $tax_code_id;
 public $line_status;
 public $line_type;
 public $uom_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $tax_code_value;
 public $item_number ;

 private function _validate_before_save() {
  $ret = 1;
  if ($this->line_status == 'SHIPPED') {
   $ret = -90;
   echo "<br> You cant modify any shipped sales order line ";
  }
  return $ret;
 }

 public function _before_save() {
  if ($this->_validate_before_save() < 0) {
   return -90;
  }
 }

 public function _after_save() {

 }

 public static function pf_invoice_only($obj) {
  $sd_so_l = new hd_subscription_line();
  $sd_so_l->findBy_id($obj->hd_subscription_line_id);
  $sd_so_l->line_status = 'AWAITING_INVOICING';
  try {
   $sd_so_l->save();
   return 1;
  } catch (Exception $e) {
   echo "<br>Not able to update line status.Error @ line " . __LINE__ . ' of file ' . __FILE__ . '<br>' . $e->getMessage();
   return -1;
  }
 }

 public function findAll_ByOrgId($org_id, $status = '') {
  $sql = " SELECT * FROM " .
   self::$table_name .
   " WHERE shipping_org_id= :shipping_org_id  ";
  if (!empty($status)) {
   $sql .= " AND line_status = :line_status ";
   $value_a = ['shipping_org_id' => $org_id, 'line_status' => $status];
  } else {
   $value_a = ['shipping_org_id' => $org_id];
  }
  $result_array = $this->findBySql($sql, $value_a);
  return !empty($result_array) ? $result_array : false;
 }

 Public static function hd_subscription_line_types() {
  $option_header = option_header::find_by_name('PO_LINE_TYPE');
  $po_types = option_line::find_by_option_id($option_header->option_header_id);
  return $po_types;
 }

 public static function find_by_hd_subscription_headerId($hd_subscription_header_id) {
  $sql = "SELECT * FROM " . self::$table_name . " where hd_subscription_header_id = '{$hd_subscription_header_id}'";
  $result_array = self::find_by_sql($sql);
  return $result_array;
 }

 public static function find_by_orgId_itemId_ssd($org_id, $item_id_m = '', $ssd = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE shipping_org_id = '{$org_id}'";
  $sql .= " AND schedule_ship_date IS NOT NULL ";
  if (!empty($item_id_m)) {
   $sql .= " AND item_id_m = '{$item_id_m}'";
  }
  if (!empty($ssd)) {
   $sql .= " AND schedule_ship_date >= '{$ssd}'";
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? $result_array : false;
 }

 public function copy($hd_subscription_line_id) {
  global $db;
  $sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM hd_subscription_line WHERE `hd_subscription_line_id` = '{$hd_subscription_line_id}' ";
  if ($db->query($sql1)) {
   $sql2 = "  UPDATE tmptable SET `hd_subscription_line_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `hd_subscription_line_id` = '{$hd_subscription_line_id}' ";
   if ($db->query($sql2)) {
    $sql3 = " INSERT INTO `hd_subscription_line` SELECT * FROM tmptable WHERE `hd_subscription_line_id` = '' ";
    if ($db->query($sql3)) {
     $this->hd_subscription_line_id = $db->insert_id();
     $this->msg = 1;
    } else {
     $this->msg = 0;
    }
   }
  }
  return $this->msg;
 }

}

//end of hd_subscription_line class
?>