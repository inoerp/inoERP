<?php

class inv_abc_valuation extends dbObject {

 public static $table_name = "inv_abc_valuation";
 public static $primary_column = "inv_abc_valuation_id";
 public static $key_column = 'valuation_name';
 public static $module = "inv";
 public static $template_type = [
		 'header_tab' => 1,
		 'line_tab' => 2,
		 'nooffields_header_tab1' => 5,
		 'nooffields_line_tab1' => 6,
		 'nooffields_line_tab2' => 6,
 ];
 public $field_a = [
		 'inv_abc_valuation_id',
		 'valuation_name',
		 'scope_org_id',
		 'scope_sub_inventory_id',
		 'scope_org_hirearchy_id',
		 'description',
		 'scope_product_line',
		 'criteria',
		 'cost_type',
		 'fp_forecast_header_id',
		 'fp_mrp_header_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'inv_abc_valuation_id',
		 'valuation_name',
		 'scope_org_id',
 ];
 public $column = [
		 'inv_abc_valuation_id',
		 'valuation_name',
		 'scope_org_id',
		 'scope_sub_inventory_id',
		 'scope_org_hirearchy_id',
		 'description',
 ];
 public $fields_inForm_notInDataBase = [
		 'org',
		 'subinventory',
 ];
 public $requiredField = [
		 'valuation_name',
		 'criteria',
 ];
 public $inv_abc_valuation_id;
 public $valuation_name;
 public $scope_org_id;
 public $scope_sub_inventory_id;
 public $scope_org_hirearchy_id;
 public $description;
 public $scope_product_line;
 public $criteria;
 public $cost_type;
 public $fp_forecast_header_id;
 public $fp_mrp_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " ABC Valuation ";

 Public static function abc_criteria() {
	$option_header = option_header::find_by_name('INV_ABC_CRITERIA');
	$ol = option_line::find_by_option_id($option_header->option_header_id);
	return $ol;
 }

 public static function find_by_buOrgId($bu_org_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE bu_org_id = '{$bu_org_id}' AND status='active'";
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

 public function findBy_buOrgId($bu_org_id = '') {
	$bu_org_id = empty($bu_org_id) ? $this->bu_org_id : $bu_org_id;
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE bu_org_id = '{$bu_org_id}' AND status='active'";
	$result = $this->findBySql($sql);
	return !empty($result) ? $result : false;
 }

}

//end of inv_abc_valuation class
?>