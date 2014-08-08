<?php

class bom_routing_header extends dbObject {

 public static $table_name = "bom_routing_header";
 public static $dependent_classes = ['bom_routing_line', 'bom_routing_detail'];
 public static $primary_column = "bom_routing_header_id";
 public static $key_column = 'item_id_m';
 public static $module = "bom"; //same as gl_journal_source
 public static $system_info = [
		 'name' => 'Routing',
		 'number' => '2407',
		 'description' => 'Product Routings',
		 'version' => '1.1.1.3',
		 'db_version' => '1001',
		 'mod_version' => '1.1.x-1.1',
		 'dependent_class' => array('bom_routing_line','bom_routing_detail'),
		 'primary_entity_cb' => '',
		 'module_name' => 'bom',
		 'weight' => 7
 ];
 public $field_a = [
		 'bom_routing_header_id',
		 'item_id_m',
		 'alternate_routing',
		 'org_id',
		 'routing_revision',
		 'effective_date',
		 'common_routing_item_id_m',
		 'description',
		 'completion_subinventory',
		 'completion_locator',
		 'ef_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date'
 ];
 public $initial_search = [
		 'bom_routing_header_id',
		 'item_id_m',
		 'alternate_routing',
		 'org_id'
 ];
 public $column = [
		 'bom_routing_header_id',
		 'item_id_m',
		 'alternate_routing',
		 'org_id'
 ];
 public $fields_inForm_notInDataBase = [
		 "item_number",
		 "item_description",
		 "uom",
		 "commonRouting_item_number",
		 "commonRouting_item_description"
 ];
 public $requiredField = [
		 'item_id_m',
		 'org_id'
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1
 ];
 public $pageTitle = " Routing - Resource & Usages @ Each Operation "; //page Title
 public $option_lists = [
//		 'po_type' => 'PO_TYPE',
//		 'po_status' => 'PO_STATUS',
 ];
 public $bom_routing_header_id;
 public $item_id_m;
 public $alternate_routing;
 public $org_id;
 public $routing_revision;
 public $effective_date;
 public $common_routing_item_id_m;
 public $description;
 public $completion_subinventory;
 public $completion_locator;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $uom;
 public $item_number;
 public $item_description;
 public $commonRouting_item_number;
 public $commonRouting_item_description;

 public function __set($name, $value) {
	$this->$name = $value;
 }


 public static function find_by_itemId($itemId) {
	$sql = "SELECT * FROM " . self::$table_name . " where item_id_m = '{$itemId}'";
	$result_array = self::find_by_sql($sql);
	return $result_array;
 }

 public function findBy_itemId() {
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where item_id_m= :item_id_m LIMIT 1 ";
	$param_a = ['item_id_m'];
	$value_a = ['item_id_m' => $this->item_id_m];
	$result_array = $this->findBy_sql($sql, $param_a, $value_a);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 Public static function wip_move_step() {
	$option_header = option_header::find_by_name('WIP_MOVE_STEP');
	$wip_move_step = option_line::find_by_option_id($option_header->option_header_id);
	return $wip_move_step;
 }

}

//end of bom_routing_header class
?>