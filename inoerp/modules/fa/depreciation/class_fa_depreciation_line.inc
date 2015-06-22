<?php

class fa_depreciation_line extends dbObject {

 public static $table_name = "fa_depreciation_line";
 public static $primary_column = "fa_depreciation_line_id";
 public static $parent_primary_column = "fa_depreciation_header_id";
 public static $key_column = "asset_id";
 public static $module = "fa";
 public $field_a = [
  'fa_depreciation_line_id',
  'fa_depreciation_header_id',
  'asset_id',
  'depreciation_amount',
  'unschedule_amount',
  'total_depreciation_amount',
  'depreciation_account_id',
  'cost_before_depreciation',
  'nbv_before_depreciation',
  'salvage_value_bd',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 
  public $fields_inForm_notInDataBase = [
  'asset_number',
 ];
 
 public $initial_search = [
  'fa_depreciation_header_id',
 ];
 public $requiredField = [
  'fa_depreciation_header_id',
  'asset_id',
  'depreciation_amount',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "fa_depreciation_header_id"
 ];
 public $pageTitle = " Depreciation Line "; //page Title
 public $fa_depreciation_line_id;
 public $fa_depreciation_header_id;
 public $asset_id;
 public $depreciation_amount;
 public $unschedule_amount;
 public $total_depreciation_amount;
 public $depreciation_account_id;
 public $cost_before_depreciation;
 public $nbv_before_depreciation;
 public $salvage_value_bd;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $asset_number;

 public static function find_rateSum_by_depriciationMethod($fa_depreciation_header_id) {
  $sql = " 
	 SELECT SUM(rate) as RATE_SUM
		FROM fa_depreciation_line 
		WHERE  fa_depreciation_header_id = '{$fa_depreciation_header_id}'
";
  $result = self::find_by_sql($sql);
  return !empty($result[0]) ? $result[0]->RATE_SUM : false;
 }

 public function priceBy_headerId_orgId_ItemId($price_date) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_depreciation_header_id = '{$this->fa_depreciation_header_id}' ";
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