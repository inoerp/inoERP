<?php

class pos_barcode_list_line extends dbObject {

 public static $table_name = "pos_barcode_list_line";
 public static $primary_column = "pos_barcode_list_line_id";
 public static $parent_primary_column = "pos_barcode_list_header_id";
 public static $key_column = "item_number";
 public static $module = "pos";
 public $field_a = [
  'pos_barcode_list_line_id',
  'pos_barcode_list_header_id',
  'item_number',
  'unit_price',
  'quantity',
  'line_amount',
  'discount_percentage',
  'discount_amount',
  'discount_code',
  'amount_after_discount',
  'no_of_labels',
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
  'pos_barcode_list_header_id',
  'item_number',
  'unit_price',
  'quantity',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "pos_barcode_list_header_id"
 ];
 public $pageTitle = " Barcode List Line "; //page Title
 public $pos_barcode_list_line_id;
 public $pos_barcode_list_header_id;
 public $item_number;
 public $unit_price;
 public $quantity;
 public $line_amount;
 public $discount_percentage;
 public $discount_amount;
 public $discount_code;
 public $amount_after_discount;
 public $no_of_labels;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_all_lines() {
  $sql = " SELECT * FROM " . self::$table_name;
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_header_id($id) {
  $vgl = new pos_barcode_list_line();
  return $vgl->findBy_parentId($id);
 }

 public static function find_by_optionId_lineCode($header_id, $code) {
  $sql = "SELECT * FROM " . self::$table_name .
   " where code={$code} AND pos_barcode_list_header_id={$header_id} ";
   $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_push($result) : $result;
 }


 public static function priceBy_headerId_ItemId($item_id_m, $price_date, $pos_barcode_list_header_id = '1') {
  $sql = " 
	 SELECT *
		FROM pos_barcode_list_line 
		WHERE  pos_barcode_list_header_id = '{$pos_barcode_list_header_id}'
		AND item_id_m = '{$item_id_m}'
		AND effective_start_date < '{$price_date}'
		AND(effective_end_date IS NULL OR effective_end_date > '{$price_date}')
";
    $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
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