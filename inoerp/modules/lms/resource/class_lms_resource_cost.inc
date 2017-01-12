<?php

class lms_resource_cost extends dbObject {

 public static $table_name = "lms_resource_cost";
 public static $primary_column = "lms_resource_cost_id";
 public static $parent_primary_column = "lms_resource_id";
 public static $key_column = 'lms_cost_type';
 public static $module = "lms";
//  data base variables as stored database column name
 public $field_a = [
		 'lms_resource_cost_id',
		 'lms_resource_id',
		 'lms_cost_type',
		 'resource_rate',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
		 'lms_resource_cost_id',
		 'resource',
		 'description',
		 'org_id',
		 'status',
		 'resource_type'
 ];
 public $fields_inForm_notInDataBase = [
		 "lms_cost_type_description",
 ];
 public $requiredField = [
		 'lms_resource_id',
		 'lms_cost_type',
		 'resource_rate',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Resource COST "; //page Title
 public $search_functions = [
		 'Cost Type' => 'search_bom_cost_type',
 ];
 public $lms_resource_id;
 public $resource;
 public $description;
 public $org_id;
 public $status;
 public $resource_type;
 public $charge_type;
 public $uom;
 public $basis;
 public $costed_cb;
 public $standard_rate_cb;
 public $absorption_ac_id;
 public $variance_ac_id;
 public $overheads;
 public $rate_reference_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $lms_cost_type_description;

 public function findBy_resourceId_bomCostType() {
	$sql = " SELECT * FROM  ";
	$sql .= self::$table_name;
	$sql .= " WHERE lms_cost_type =:lms_cost_type AND lms_resource_id = :lms_resource_id ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}

	$param_a = ['lms_cost_type', 'lms_resource_id'];
	$value_a = ['lms_cost_type' => $this->lms_cost_type, 'lms_resource_id' => $this->lms_resource_id];
	$result = $this->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_resourceId_bomCostType($resource_id, $lms_cost_type = 'FROZEN') {
	$sql = " SELECT * FROM  ";
	$sql .= self::$table_name;
	$sql .= " WHERE lms_cost_type = '{$lms_cost_type}' AND lms_resource_id = '{$resource_id}' ";
	switch (DB_TYPE) {
	 case 'ORACLE' :
		$sql .= ' AND ' . ino_perPageSql(1);
		break;

	 default:
		$sql .= ino_perPageSql(1);
		break;
	}

	$result = self::find_by_sql($sql);
	return !empty($result) ? array_pop($result) : false;
 }

}

//end of lms_resource_cost class
?>