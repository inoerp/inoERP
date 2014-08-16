<?php

class hr_payroll_schedule extends dbObject {

 public static $table_name = "hr_payroll_schedule";
 public static $primary_column = "hr_payroll_schedule_id";
 public static $parent_primary_column = "hr_payroll_id";
 public static $key_column = "line_type";
 public static $module = "mdm";
 public static $line_type_a = [
  'ITEM' => 'Item',
  'DEFAULT' => 'Default',
  'CATEGORY' => 'Catefory'];
 public $field_a = [
		 'hr_payroll_schedule_id',
		 'hr_payroll_id',
		 'line_type',
		 'org_id',
		 'item_id_m',
		 'uom_id',
		 'unit_price',
		 'formula',
		 'effective_start_date',
		 'effective_end_date',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $checkbox = [
//		 "parent_cb",
 ];
 public $initial_search = [
		 'hr_payroll_schedule_id',
		 'hr_payroll_id',
		 'line_type',
		 'item_id_m',
 ];
 public $column = [
		 'hr_payroll_schedule_id',
		 'hr_payroll_id',
		 'line_type',
		 'item_id_m',
 ];
 public $requiredField = [
		 'hr_payroll_id',
		 'line_type',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 "hr_payroll_id"
 ];
 public $fields_inForm_notInDataBase = [
		 "item_number",
		 'item_description',
 ];
 public $pageTitle = " Price List Line "; //page Title
 public $hr_payroll_schedule_id;
 public $hr_payroll_id;
 public $line_type;
 public $org_id;
 public $item_id_m;
 public $uom_id;
 public $unit_price;
 public $formula;
 public $effective_start_date;
 public $effective_end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $item_number;
 public $item_description;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public static function find_all_lines() {
	$sql = " SELECT * FROM " . self::$table_name;
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_by_header_id($id) {
	$vgl = new hr_payroll_schedule();
	return $vgl->findBy_parentId($id);
 }

 public static function find_by_optionId_lineCode($header_id, $code) {
	$sql = "SELECT * FROM " . self::$table_name .
					" where code={$code} AND hr_payroll_id={$header_id} LIMIT 1 ";
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_push($result) : $result;
 }

 public function _before_save() {
	if (!(empty($this->item_number)) && empty($this->item_id_m)) {
	 $item_s = item::find_by_itemNumber_fromMasterOrg($this->item_number);
	 $this->item_id_m = $item_s->item_id_m;
	}
 }

 public static function priceBy_headerId_ItemId($item_id_m, $price_date, $hr_payroll_id = '1') {
	$sql = " 
	 SELECT *
		FROM hr_payroll_schedule 
		WHERE  hr_payroll_id = '{$hr_payroll_id}'
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
	$sql .= " WHERE hr_payroll_id = '{$this->hr_payroll_id}' ";
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