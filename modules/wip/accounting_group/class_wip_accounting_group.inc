<?php

class wip_accounting_group extends org {

 public static $table_name = "wip_accounting_group";
 public static $primary_column = "wip_accounting_group_id";
 public static $key_column = 'wip_accounting_group';
 public static $module = "wip";
 public $field_a = [
		 'wip_accounting_group_id',
		 'org_id',
		 'wo_type',
		 'wip_accounting_group',
		 'description',
		 'ef_id',
		 'rev_enabled',
		 'rev_number',
		 'status',
		 'material_ac_id',
		 'material_oh_ac_id',
		 'overhead_ac_id',
		 'resource_ac_id',
		 'osp_ac_id',
		 'var_material_ac_id',
		 'var_material_oh_ac_id',
		 'var_overhead_ac_id',
		 'var_resource_ac_id',
		 'var_osp_ac_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'wip_accounting_group_id',
		 'wip_accounting_group',
 ];
 public $account = [
		 'material_ac_id',
		 'material_oh_ac_id',
		 'overhead_ac_id',
		 'resource_ac_id',
		 'osp_ac_id',
		 'var_material_ac_id',
		 'var_material_oh_ac_id',
		 'var_overhead_ac_id',
		 'var_resource_ac_id',
		 'var_osp_ac_id',
 ];
 public $column = [
		 'wip_accounting_group_id',
		 'org_id',
		 'wo_type',
		 'wip_accounting_group',
		 'description',
 ];
 public $requiredField = [
		 'org_id',
		 'wo_type',
		 'wip_accounting_group',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $option_lists = [
		 'wo_type' => 'WIP_WO_TYPE',
 ];
 public $search_functions = [
		 'Organization' => 'search_org_name',
 ];
 public $pageTitle = " WIP - Accounting Group "; //page Title
 public $wip_accounting_group_id;
 public $org_id;
 public $wo_type;
 public $wip_accounting_group;
 public $description;
 public $ef_id;
 public $rev_enabled;
 public $rev_number;
 public $status;
 public $material_ac_id;
 public $material_oh_ac_id;
 public $overhead_ac_id;
 public $resource_ac_id;
 public $osp_ac_id;
 public $var_material_ac_id;
 public $var_material_oh_ac_id;
 public $var_overhead_ac_id;
 public $var_resource_ac_id;
 public $var_osp_ac_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_orgId($org_id) {
	global $db;
	if (!empty($org_id)) {
	 $sql = " SELECT * FROM ";
	 $sql .= self::$table_name;
	 $sql .= " WHERE org_id = '{$org_id}' ";
	 $result = $db::find_by_sql($sql);
	} else {
	 $result = null_instantitae('subinventory');
	}
	return $result;
 }

 public function findBy_orgId() {
	global $db;
	$sql = " SELECT * FROM " . self::$table_name;
	$sql .= " WHERE org_id= :org_id ";
	$param_a = ['org_id'];
	$value_a = ['org_id' => $this->org_id];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? $result : false;
 }

}

//end of business class
?>
