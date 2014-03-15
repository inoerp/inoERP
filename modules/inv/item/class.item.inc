<?php

class item extends dbObject {

 protected static $table_name = "item";
 public static $primary_column = "item_id";
 public static $key_column = 'item_number';
 public static $module = "inv";
 public $account = [
		 "material_ac_id",
		 "material_oh_ac_id",
		 "overhead_ac_id",
		 "resource_ac_id",
		 "osp_ac_id",
		 "expense_ac_id",
		 "sales_ac_id",
		 "cogs_ac_id",
		 "deffered_cogs_ac_id"
 ];
 public $checkbox = [
		 "item_rev_enabled_cb",
		 "inventory_item_cb",
		 "stockable_cb",
		 "transactable_cb",
		 "reservable_cb",
		 "cycle_count_enabled_cb",
		 "equipment_cb",
		 "electronic_format_cb",
		 "rev_enabled_cb",
		 "customer_ordered_cb",
		 "internal_ordered_cb",
		 "shippable_cb",
		 "returnable_cb",
		 "purchased_cb",
		 "use_asl_cb",
		 "bom_enabled_cb",
		 "costing_enabled_cb",
		 "inventory_asset_cb",
		 "build_in_wip_cb",
		 "allow_negative_balance_cb"
 ];
 public $field_a = [
		 "item_id",
		 "org_id",
		 "item_number",
		 "item_description",
		 "locator_control",
		 "long_description",
		 "uom_id",
		 "item_type",
		 "item_status",
		 "bom_type",
		 "item_rev_number",
		 "default_cost_group",
		 "lot_uniqueness",
		 "lot_generation",
		 "lot_prefix",
		 "lot_starting_number",
		 "serial_generation",
		 "serial_prefix",
		 "serial_starting_number",
		 "serial_uniqueness",
		 "invoice_matching",
		 "default_buyer",
		 "list_price",
		 "un_number",
		 "hazard_classs",
		 "over_receipt_percentage",
		 "receipt_days_early",
		 "receipt_days_late",
		 "receipt_day_action",
		 "receipt_routing",
		 "weight_uom_id",
		 "weight",
		 "volume_uom_id",
		 "volume",
		 "dimension_uom_id",
		 "length",
		 "width",
		 "height",
		 "planning_method",
		 "planner",
		 "make_buy",
		 'wip_supply_subinventory',
		 'wip_supply_locator',
		 "fix_order_quantity",
		 "fix_days_supply",
		 "fix_lot_multiplier",
		 "minimum_order_quantity",
		 "maximum_order_quantity",
		 "forecast_method",
		 "forecast_control",
		 "demand_timefence",
		 "planning_timefence",
		 "release_timefence",
		 "pre_processing_lt",
		 "post_processing_lt",
		 "processing_lt",
		 "cumulative_mfg_lt",
		 "cumulative_total_lt",
		 "lt_lot_size",
		 "wip_supply_type",
		 "ef1",
		 "ef2",
		 "atp",
		 "picking_rule",
		 "sourcing_rule",
		 "ap_tax",
		 "sales_tax",
		 "ap_payment_term",
		 "ar_payment_term",
		 "ef_id",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date",
		 "material_ac_id",
		 "material_oh_ac_id",
		 "overhead_ac_id",
		 "resource_ac_id",
		 "osp_ac_id",
		 "expense_ac_id",
		 "sales_ac_id",
		 "cogs_ac_id",
		 "deffered_cogs_ac_id",
		 "item_rev_enabled_cb",
		 "inventory_item_cb",
		 "stockable_cb",
		 "transactable_cb",
		 "reservable_cb",
		 "cycle_count_enabled_cb",
		 "equipment_cb",
		 "electronic_format_cb",
		 "rev_enabled_cb",
		 "customer_ordered_cb",
		 "internal_ordered_cb",
		 "shippable_cb",
		 "returnable_cb",
		 "purchased_cb",
		 "use_asl_cb",
		 "bom_enabled_cb",
		 "costing_enabled_cb",
		 "inventory_asset_cb",
		 "build_in_wip_cb",
		 "allow_negative_balance_cb"
 ];
 public $initial_search = [
		 'item_id',
		  "org_id",
		 "item_number",
		 "item_type",
		 "uom_id",
		 "item_status"
 ];
 public $column = [
		 'item_id',
		 "org_id",
		 "item_number",
		 "item_description",
		 "item_type",
		 "uom_id",
		 "item_status"
 ];
 public $requiredField = [
		 "item_number",
		 "uom_id",
		 "org_id",
		 "item_description",
		 "item_type",
		 "make_buy"];
 
 public $otherField = [
		 "org.org"
 ];
 
 public $item_id;
 public $org_id;
 public $org;
 public $item_number;
 public $item_description;
 public $locator_control;
 public $allow_negative_balance_cb;
 public $long_description;
 public $uom_id;
 public $item_rev_enabled_cb;
 public $item_rev_number;
 public $item_type;
 public $item_status;
 public $inventory_item_cb;
 public $stockable_cb;
 public $transactable_cb;
 public $reservable_cb;
 public $cycle_count_enabled_cb;
 public $bom_enabled_cb;
 public $bom_type;
 public $costing_enabled_cb;
 public $inventory_asset_cb;
 public $default_cost_group;
// public $material_ac;
 public $material_oh_ac;
 public $overhead_ac;
 public $resource_ac;
 public $expense_ac;
 public $osp_ac;
 public $material_ac_id;
 public $material_oh_ac_id;
 public $overhead_ac_id;
 public $resource_ac_id;
 public $expense_ac_id;
 public $osp_ac_id;
 public $lot_uniqueness;
 public $lot_generation;
 public $lot_prefix;
 public $lot_starting_number;
 public $serial_generation;
 public $serial_prefix;
 public $serial_starting_number;
 public $serial_uniqueness;
 public $purchased_cb;
 public $use_asl_cb;
 public $invoice_matching;
 public $default_buyer;
 public $list_price;
 public $un_number;
 public $hazard_classs;
 public $receipt_sub_inventory;
 public $over_receipt_percentage;
 public $over_receipt_action;
 public $receipt_days_early;
 public $receipt_days_late;
 public $receipt_day_action;
 public $receipt_routing;
 public $weight_uom_id;
 public $weight;
 public $volume_uom_id;
 public $volume;
 public $dimension_uom_id;
 public $length;
 public $width;
 public $height;
 public $equipment_cb;
 public $electronic_format_cb;
 public $planning_method;
 public $planner;
 public $make_buy;
 public $wip_supply_locator;
 public $wip_supply_subinventory;
 public $fix_order_quantity;
 public $fix_days_supply;
 public $fix_lot_multiplier;
 public $minimum_order_quantity;
 public $maximum_order_quantity;
 public $forecast_method;
 public $forecast_control;
 public $demand_timefence;
 public $planning_timefence;
 public $release_timefence;
 public $pre_processing_lt;
 public $post_processing_lt;
 public $processing_lt;
 public $cumulative_mfg_lt;
 public $cumulative_total_lt;
 public $lt_lot_size;
 public $build_in_wip_cb;
 public $wip_supply_type;
 public $customer_ordered_cb;
 public $internal_ordered_cb;
 public $shippable_cb;
 public $returnable_cb;
 public $invoiceable;
 public $ap_tax;
 public $sales_tax;
 public $ap_payment_term;
 public $ar_payment_term;
 public $ef1;
 public $ef2;
 public $atp;
 public $picking_rule;
 public $sourcing_rule;
 public $sales_ac;
 public $cogs_ac;
 public $deffered_cogs_ac;
 public $sales_ac_id;
 public $cogs_ac_id;
 public $deffered_cogs_ac_id;
 public $ef_id;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;

 Public static function item_types() {
	$option_header = option_header::find_by_name('ITEM_TYPE');
	$coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
	return $coa_account_types;
 }

 Public static function item_status() {
	$option_header = option_header::find_by_name('ITEM_STATUS');
	$coa_account_types = option_line::find_by_option_id($option_header->option_header_id);
	return $coa_account_types;
 }

 Public static function manufacturing_item_types() {
	$option_header = option_header::find_by_name('MANUFACTURING_ITEM_TYPE');
	$mfg_item_types = option_line::find_by_option_id($option_header->option_header_id);
	return $mfg_item_types;
 }

 public static function find_item_number_by_item_number($item_number) {
	global $db;
	$sql = "SELECT * FROM "
					. self::$table_name
					. " where item_number LIKE '%{$item_number}%' LIMIT 0, 30";
	$result = $db->query($sql);
	$data = array();
	if ($result && mysql_num_rows($result)) {
	 while ($row = $db->fetch_array($result)) {
		$data[] = array(
				'label' => $row['item_number'],
				'item_number' => $row['item_number'],
				'item_id' => $row['item_id'],
				'description' => $row['item_description'],
				'uom_id' => $row['uom_id']
		);
	 }
	}

	return $data;
 }

 public static function find_item_id_from_itemNumber_OrgId($item_number, $org_id) {
	global $db;
	$sql = "SELECT item_id FROM " . self::$table_name;
	$sql .= " where item_number= '{$item_number}' ";
	$sql .= " AND org_id= '{$org_id}' ";
	$sql .= " LIMIT 1 ";

	$result = $db->query($sql);
	if ($result && mysql_num_rows($result)) {
	 while ($row = $db->fetch_array($result)) {
		$item_id = $row['item_id'];
	 }//end of while Loop
	 return $item_id;
	} else {
	 return false;
	}
 }

 public static function find_item_number_by_itemNumber_OrgId($item_number, $org_id="") {
	global $db;
	$sql = "SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " where item_number LIKE '%{$item_number}%' ";
	if(!empty($org_id)){
	$sql .= " AND org_id  = '{$org_id}' ";
	}
	$result = $db->find_by_sql($sql);
	$data = array();
	$return_array = array();
	foreach ($result as $row) {
	 $data[] = array(
			 'label' => $row->item_number,
			 'item_number' => $row->item_number,
			 'item_id' => $row->item_id,
			 'item_description' => $row->item_description,
			 'uom_id' => $row->uom_id
	 );
	}
//	$return_array['jsonvalue'] = $data;

	return $data;
 }

 public static function find_by_itemNumber_OrgId($item_number, $org_id) {
	$item_id = self::find_item_id_from_itemNumber_OrgId($item_number, $org_id);
	$result = self::find_by_id($item_id);
	return $result;
 }

 public static function find_all_assigned_orgs($item_number) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where item_number= '{$item_number}' ";
	$result = $db->result_array_assoc($sql);
	return $result;
 }

 public static function find_all_assigned_org_ids($item_number) {
	global $db;
	$sql = "SELECT org_id FROM " .
					self::$table_name .
					" where item_number= '{$item_number}' ";
	$result = $db->result_array_assoc($sql);
	$assigned_inventory_orgs_array = [];

	foreach ($result as $orgs) {
	 $assigned_inventory_orgs_array[] = $orgs['org_id'];
	}

	return $assigned_inventory_orgs_array;
 }

 public function save() {
	if (empty($this->item_id)) {
//before creating item, check if the entered org is a master org or not;
//if the entered org is a master org then create the item else show error message that
//items can be created only in master org

	 $all_master_orgs = org::find_all_item_master_orgIds_array();
	 if (in_array($this->org_id, $all_master_orgs[0])) {
		$this->create();
	 } else {
		$this->msg = " Items can be created only in master org ";
	 }
	} else {
	 $entered_item = self::find_by_id($this->item_id);
	 if (($entered_item->org_id) == ($this->org_id)) {
		$this->update($this->item_id);
	 } else {
		$this->copy($this->item_id);
	 }
	}
	return $this->msg;
 }

 public function copy($item_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM item WHERE `item_id` = '{$item_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = "  UPDATE tmptable SET `item_id` = '' ,
           `org_id` = '{$this->org_id}' 
          WHERE `item_id` = '{$item_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `item` SELECT * FROM tmptable WHERE `item_id` = '' ";
		if ($db->query($sql3)) {
		 $this->item_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

}

//end of item class
?>