<?php

class pos_transaction_line extends dbObject {

 public static $table_name = "pos_transaction_line";
 public static $primary_column = "pos_transaction_line_id";
 public static $parent_primary_column = "pos_transaction_header_id";
 public static $key_column = "item_number";
 public static $module = "pos";
 public static $status_a = [
  'E' => 'Entered',
  'F' => 'Sync Failed',
  'S' => 'Sync Completed'
 ];
 public $field_a = [
  'pos_transaction_line_id',
  'pos_transaction_header_id',
  'item_number',
  'unit_price',
  'quantity',
  'line_amount',
  'amount_after_discount',
  'discount_percentage',
  'discount_amount',
  'discount_code',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'item_number'
 ];
 public $requiredField = [
  'item_number',
  'pos_transaction_header_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "pos_transaction_header_id"
 ];
 public $pageTitle = " POS Transaction Line "; //page Title
 public $pos_transaction_line_id;
 public $pos_transaction_header_id;
 public $item_number;
 public $unit_price;
 public $line_amount;
 public $discount_percentage;
 public $discount_amount;
 public $discount_code;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $quantity;
 public $amount_after_discount;

 public static function priceBy_headerId_ItemId($item_id_m, $price_date, $pos_transaction_header_id = '1') {
  $sql = " 
	 SELECT *
		FROM pos_transaction_line 
		WHERE  pos_transaction_header_id = '{$pos_transaction_header_id}'
		AND item_id_m = '{$item_id_m}'
		AND effective_start_date < '{$price_date}'
		AND(effective_end_date IS NULL OR effective_end_date > '{$price_date}')
";
    $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function priceBy_headerId_orgId_ItemId($price_date) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE pos_transaction_header_id = '{$this->pos_transaction_header_id}' ";
  $sql .= " AND item_id_m = '{$this->item_id_m}' ";
  $sql .= " AND org_id = '{$this->org_id}' ";
  $sql .= " AND $this->effective_start_date < '{$price_date}' ";
  $sql .= " AND $this->effective_end_date > '{$price_date}' ";
  $sql .= " OR $this->effective_end_date IS NULL ";

  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function getPrice($price_date) {
  if (!empty($this->org_id)) {
   $result = $this->priceBy_headerId_orgId_ItemId($price_date);
  }
 }

}

//end of path class
?>