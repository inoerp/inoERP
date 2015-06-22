<?php

class fp_mds_line extends dbObject {

 public static $table_name = "fp_mds_line";
 public static $primary_column = "fp_mds_line_id";
 public static $parent_primary_column = "fp_mds_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "po";
 public $field_a = [
		 'fp_mds_line_id',
		 'fp_mds_header_id',
		 'item_id_m',
		 'demand_date',
		 'quantity',
		 'source_type',
		 'source_header_id',
		 'source_line_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 //variables used for showing data

 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "fp_mds_header_id"
 ];
 public $requiredField = [
		 'fp_mds_header_id',
		 'item_id_m',
		 'demand_date',
		 'quantity',
		 'source_type',
		 'source_header_id',
		 'source_line_id'
 ];
 public  $fp_mds_line_id;
 public $fp_mds_header_id;
 public $item_id_m;
 public $demand_date;
 public $quantity;
 public $source_type;
 public $source_header_id;
 public $source_line_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function findBy_ItemId_headerId() {
	$sql = " SELECT * FROM  ";
	$sql .= self::$table_name;
	$sql .= " WHERE fp_mds_header_id =:fp_mds_header_id AND item_id_m = :item_id_m ";
	$value_a = ['fp_mds_header_id' => $this->fp_mds_header_id, 'item_id_m' => $this->item_id_m];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? $result : false;
 }

 public function findAll_distinctItems_ofHeader() {
	$sql = "SELECT DISTINCT(item_id_m) FROM " .
					self::$table_name;
	$sql .= " WHERE fp_mds_header_id =:fp_mds_header_id ";
	$param_a = ['fp_mds_header_id'];
	$value_a = ['fp_mds_header_id' => $this->fp_mds_header_id];
	$result_array = $this->findBy_sql($sql, $param_a, $value_a);
	return !empty($result_array) ? $result_array : false;
 }

}

//end of inv_transaction class
?>