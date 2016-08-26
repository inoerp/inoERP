<?php

class prj_burden_list_line extends dbObject {

 public static $table_name = "prj_burden_list_line";
 public static $primary_column = "prj_burden_list_line_id";
 public static $parent_primary_column = "prj_burden_list_header_id";
 public static $key_column = "prj_burden_costcode_id";
 public static $module = "prj";
 public $field_a = [
  'prj_burden_list_line_id',
  'prj_burden_list_header_id',
  'prj_burden_costcode_id',
  'bu_org_id',
  'multiplier',
  'burden_value',
  'formula',
  'effective_start_date',
  'effective_end_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'prj_burden_list_line_id',
  'prj_burden_list_header_id',
  'line_type',
  'item_id_m',
 ];
 public $requiredField = [
  'prj_burden_list_header_id',
  'prj_burden_costcode_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "prj_burden_list_header_id"
 ];
 public $fields_inForm_notInDataBase = [
  "item_number",
  'item_description',
 ];
 public $pageTitle = " Burden List "; //page Title
 public $prj_burden_list_line_id;
 public $prj_burden_list_header_id;
 public $prj_burden_costcode_id;
 public $bu_org_id;
 public $multiplier;
 public $burden_value;
 public $formula;
 public $effective_start_date;
 public $effective_end_date;
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
  $vgl = new prj_burden_list_line();
  return $vgl->findBy_parentId($id);
 }

 public static function find_by_optionId_lineCode($header_id, $code) {
  $sql = "SELECT * FROM " . self::$table_name .
   " where code={$code} AND prj_burden_list_header_id={$header_id} LIMIT 1 ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_push($result) : $result;
 }

 public function _before_save() {
  if (!(empty($this->item_number)) && empty($this->item_id_m)) {
   $item_s = item::find_by_itemNumber_fromMasterOrg($this->item_number);
   $this->item_id_m = $item_s->item_id_m;
  }
 }

 public static function priceBy_headerId_ItemId($item_id_m, $price_date, $prj_burden_list_header_id = '1') {
  $sql = " 
	 SELECT *
		FROM prj_burden_list_line 
		WHERE  prj_burden_list_header_id = '{$prj_burden_list_header_id}'
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
  $sql .= " WHERE prj_burden_list_header_id = '{$this->prj_burden_list_header_id}' ";
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