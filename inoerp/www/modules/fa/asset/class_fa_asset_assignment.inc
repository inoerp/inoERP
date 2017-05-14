<?php

class fa_asset_assignment extends dbObject {

 public static $table_name = "fa_asset_assignment";
 public static $primary_column = "fa_asset_assignment_id";
 public static $parent_primary_column = "fa_asset_id";
 public static $key_column = "units";
 public static $module = "fa";
 public $field_a = [
  'fa_asset_assignment_id',
  'fa_asset_id',
  'units',
  'hr_employee_id',
  'address_id',
  'expense_ac_id',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'fa_asset_id',
 ];
 public $requiredField = [
  'fa_asset_id',
  'units',
  'hr_employee_id',
//  'address_id',
  'expense_ac_id',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "fa_asset_id"
 ];
 
  public $fields_inForm_notInDataBase = [
  "employee_name",
  'identification_id',
   'address_name'
 ];
  
 public $pageTitle = " Asset Assignment "; //page Title
 public $fa_asset_assignment_id;
 public $fa_asset_id;
 public $units;
 public $hr_employee_id;
 public $address_id;
 public $expense_ac_id;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $member_employee_name;
 public $address_name;

 public function priceBy_headerId_orgId_ItemId($price_date) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE fa_asset_id = '{$this->fa_asset_id}' ";
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