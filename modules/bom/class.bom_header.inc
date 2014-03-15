<?php

class bom_header extends dbObject {

 protected static $table_name = "bom_header";
 public static $primary_column = "bom_header_id";
 public static $key_column = 'item_id';
 public static $module = "bom";
 public $field_a = [
		 'bom_header_id',
		 'item_id',
		 'org_id',
		 'alternate_bom',
		 'bom_revision',
		 'effective_date',
		 'common_bom_item_id',
		 "ef_id",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 //variables used for showing data

 public $initial_search = [
		 'bom_header_id',
		 'item_id',
		 'org_id',
		 'alternate_bom'
 ];
 public $column = [
		 'bom_header_id',
		 'item_id',
		 'org_id',
		 'alternate_bom',
 ];
 public $fields_inForm_notInDataBase = [
		 "item_number",
		 "item_description",
		 "uom",
		 "commonBom_item_number",
		 "commonBom_item_description"
 ];
 public $requiredField = [
		 'item_id',
		 'org_id',
		 'bom_revision',
		 'effective_date'
 ];
 public $search = [
		 '_update_path' => 'modules/bom/bom',
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update BOM',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
		 '_extra_path' => [ 'modules/bom/indented_bom' => 'Indented BOM'],
 ];
 public $pageTitle = " Option - Find All Options "; //page Title
 public $option_list = [
//		 'calendar_option_line_code' => 'GL_CALENDAR_NAME',
 ];
 public $bom_header_id;
 public $item_id;
 public $org_id;
 public $alternate_bom;
 public $bom_revision;
 public $effective_date;
 public $common_bom_item_id;
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
 public $commonBom_item_number;
 public $commonBom_item_description;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public function _before_showing() {
	if (!empty($this->common_bom_item_id)) {
	 $item = item::find_by_id($this->common_bom_item_id);
	 $this->commonBom_item_number = $item->item_number;
	 $this->commonBom_item_description = $item->item_description;
	}else{
	 $this->commonBom_item_number = null;
	 $this->commonBom_item_description = null;
	}
 }

 public function _before_submit() {
//	if (!(empty($this->transaction_type_id))) {
//	 switch ($this->transaction_type_id) {
//		case 1 :
//		 array_push(self::$requiredField_array, 'to_account_id');
//		 array_push(self::$requiredField_array, 'from_subinventory_id');
//		 $this->from_account_id = "";
//		 $this->to_account_id = $this->account_id;
//		 break;
//
//		case 2 :
//		 array_push(self::$requiredField_array, 'from_account_id');
//		 array_push(self::$requiredField_array, 'to_subinventory_id');
//		 $this->from_account_id = $this->account_id;
//		 $this->to_account_id = "";
//		 break;
//
//		case 3 :
//		 array_push(self::$requiredField_array, 'to_subinventory_id');
//		 array_push(self::$requiredField_array, 'from_subinventory_id');
//		 break;
//
//		default:
//		 break;
//	 }
//	}
 }

// private function update_bomNumber($bom_header_id, $bom_number) {
//	global $db;
//
//	$sql = " UPDATE " . self::$table_name;
//	$sql .= " SET bom_number = '{$bom_number}'  ";
//	$sql .= " WHERE bom_header_id = $bom_header_id  ";
//
////	    echo "<br/>$sql is <br/>" . $sql;
//	if ($db->query($sql)) {
//	 $this->msg = 1;
//	 $this->bom_number = $bom_number;
//	} else {
//	 $this->msg = 0;
//	}
//
//	return $this->msg;
// }
// public function _after_save() {
//	global $db;
//	if ((!empty($this->bom_header_id)) && empty($this->bom_number)) {
//	 $bom_header_id = $this->bom_header_id;
//	 $org_id = $this->org_id;
//	 $bom_number = $org_id . '-' . $bom_header_id;
//	 $this->msg = $this->update_bomNumber($bom_header_id, $bom_number);
//	}
//
//	return $this->msg;
// }

 Public static function wip_supply_type() {
	$option_header = option_header::find_by_name('WIP_SUPPLY_TYPE');
	$wip_supply_type = option_line::find_by_option_id($option_header->option_header_id);
	return $wip_supply_type;
 }

 Public static function bom_charge_basis() {
	$option_header = option_header::find_by_name('BOM_CHARGE_BASIS');
	$bom_charge_basis = option_line::find_by_option_id($option_header->option_header_id);
	return $bom_charge_basis;
 }

 Public static function bom_overhead_type() {
	$option_header = option_header::find_by_name('BOM_OVERHEAD_TYPE');
	$bom_overhead_type = option_line::find_by_option_id($option_header->option_header_id);
	return $bom_overhead_type;
 }

 Public static function bom_department_type() {
	$option_header = option_header::find_by_exact_name('BOM_DEPARTMENT_TYPE');
	$resource_type = option_line::find_by_option_id($option_header->option_header_id);
	return $resource_type;
 }

 Public static function bom_schedule_option() {
	$option_header = option_header::find_by_exact_name('BOM_SCHEDULE_OPTION');
	$bom_schedule_option = option_line::find_by_option_id($option_header->option_header_id);
	return $bom_schedule_option;
 }

 public static function find_by_itemId($item_id) {
	global $db;
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where item_id= '{$item_id}' LIMIT 1 ";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

}

//end of bom class
?>