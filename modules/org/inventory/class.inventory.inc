<?php

class inventory extends org {

 protected static $table_name = "inventory";
 public static $field_array = [
		 "inventory_id",
		 "org_id",
		 "type",
		 "code",
		 "item_master_cb",
		 "master_org",
		 "calendar",
		 "locator_control",
		 "allow_negative_balance_cb",
		 "costing_org",
		 "costing_method",
		 "transfer_to_gl_cb",
		 "default_cost_group",
		 "material_ac_id",
		 "material_oh_ac_id",
		 "overhead_ac_id",
		 "resource_ac_id",
		 "expense_ac_id",
		 "item_rev_enabled_cb",
		 "rev_start_number",
		 "lot_uniqueness",
		 "lot_generation",
		 "lot_prefix",
		 "lot_starting_number",
		 "serial_uniqueness",
		 "serial_generation",
		 "serial_prefix",
		 "serial_starting_number",
		 "atp",
		 "picking_rule",
		 "sourcing_rule",
		 "inter_org_ppv_ac_id",
		 "inter_org_receivable_ac_id",
		 "inter_org_payable_ac_id",
		 "inter_org_intransit_ac_id",
		 "inv_ap_accrual_ac_id",
		 "inv_ap_exp_accrual_ac_id",
		 "inv_ppv_ac_id",
		 "inv_ipv_ac_id",
		 "sales_ac_id",
		 "cogs_ac_id",
		 "deferred_cogs_ac_id",
		 "ef_id",
		 "status",
		 "rev_enabled",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $initial_search_array = [
		 "inventory_id",
		 "org_id",
		 "org",
		 "description",
		 "master_org"
 ];
 public static $checkbox_array = [
		 "item_master_cb",
		 "allow_negative_balance_cb",
		 "transfer_to_gl_cb",
		 "item_rev_enabled_cb"
 ];
 public static $column_array = [
		 "inventory_id",
		 "org_id",
		 "org",
		 "description",
		 "code",
		 "item_master_cb",
		 "master_org"
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 "org_id",
 ];
 public static $primary_column = "inventory_id";
 public $inventory_id;
 public $org_id;
 public $org;
 public $description;
 public $type;
 public $code;
 public $item_master_cb;
 public $master_org;
 public $calendar;
 public $locator_control;
 public $allow_negative_balance_cb;
 public $costing_org;
 public $costing_method;
 public $transfer_to_gl_cb;
 public $default_cost_group;
 public $material_ac_id;
 public $material_oh_ac_id;
 public $overhead_ac_id;
 public $resource_ac_id;
 public $expense_ac_id;
 public $item_rev_enabled_cb;
 public $rev_start_number;
 public $lot_uniqueness;
 public $lot_generation;
 public $lot_prefix;
 public $lot_starting_number;
 public $serial_uniqueness;
 public $serial_generation;
 public $serial_prefix;
 public $serial_starting_number;
 public $atp;
 public $picking_rule;
 public $sourcing_rule;
 public $inter_org_ppv_ac_id;
 public $inter_org_receivable_ac_id;
 public $inter_org_payable_ac_id;
 public $inter_org_intransit_ac_id;
 public $inv_ap_accrual_ac_id;
 public $inv_ap_exp_accrual_ac_id;
 public $inv_ppv_ac_id;
 public $inv_ipv_ac_id;
 public $sales_ac_id;
 public $cogs_ac_id;
 public $deferred_cogs_ac_id;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;

  Public static function inventory_org_types() {
	$org_header = option_header::find_by_name('INVENTORY_ORG_TYPE');
	$type = option_line::find_by_option_id($org_header->option_header_id);
	return $type;
 }
 
   Public static function costing_methods() {
	$org_header = option_header::find_by_name('COSTING_METHODS');
	$type = option_line::find_by_option_id($org_header->option_header_id);
	return $type;
 }
 
 public static function find_all_item_master() {
	$sql = " SELECT * FROM " .
					self::$table_name .
					" WHERE item_master=1 ";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public function findBy_org_id($org_id) {
	global $db;
	$sql = "SELECT * FROM inventory where org_id=:org_id LIMIT 1";
	$param_a = ['org_id'];
	$value_a = ['org_id'=>$org_id];
  $result = $db->findBy_sql($sql,$param_a,$value_a)	;
   pa($result);
	return !empty($result) ?array_pop($result) : false;
 }
 
 

}

//end of inventory_org class
?>
