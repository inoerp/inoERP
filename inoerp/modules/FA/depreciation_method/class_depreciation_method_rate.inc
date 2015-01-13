<?php

class fa_depreciation_method_rate extends dbObject {

 public static $table_name = "fa_depreciation_method_rate";
 public static $primary_column = "fa_depreciation_method_rate_id";
 public static $parent_primary_column = "fa_depreciation_method_id";
 public static $key_column = "rate";
 public static $module = "fa";
 public $field_a = [
  'fa_depreciation_method_rate_id',
  'fa_depreciation_method_id',
  'year',
  'period',
  'rate',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'fa_depreciation_method_id',
 ];
 public $requiredField = [
  'fa_depreciation_method_id',
  'rate',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "fa_depreciation_method_id"
 ];
 public $pageTitle = " Depreciation Method "; //page Title
 public $fa_depreciation_method_rate_id;
 public $fa_depreciation_method_id;
 public $year;
 public $period;
 public $rate;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_save() {
  if (!(empty($this->item_number)) && empty($this->item_id_m)) {
   $item_s = item::find_by_itemNumber_fromMasterOrg($this->item_number);
   $this->item_id_m = $item_s->item_id_m;
  }
 }

 public static function priceBy_headerId_ItemId($item_id_m, $price_date, $fa_depreciation_method_id = '1') {
  $sql = " 
	 SELECT *
		FROM fa_depreciation_method_rate 
		WHERE  fa_depreciation_method_id = '{$fa_depreciation_method_id}'
		AND item_id_m = '{$item_id_m}'
		AND effective_start_date < '{$price_date}'
		AND(effective_end_date IS NULL OR effective_end_date > '{$price_date}')
		 LIMIT 1
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function priceBy_headerId_orgId_ItemId($price_date) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_depreciation_method_id = '{$this->fa_depreciation_method_id}' ";
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