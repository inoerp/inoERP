<?php

class bom_header extends dbObject {

 protected static $table_name = "bom_header";
 public static $primary_column = "bom_header_id";
 public static $dependent_classes = ['bom_line'];
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
		 "commonBom_item_description",
 ];
 public $requiredField = [
		 'item_id',
		 'org_id',
		 'bom_revision',
		 'effective_date'
 ];
 public $pageTitle = " BOM - Create & Update BOM "; //page Title
 public $search = [
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update',
		 '_show_view_path' => 1,
		 '_extra_path' => array('form.php?class_name=indented_bom&mode=9' => 'Indented BOM')
 ];
 public $prg_varify_circular_bom_parameters = [
		 'Organization' => 'search_org_name',
		 'Item Number From' => 'search_item_number_from',
		 'Item Number To' => 'search_item_number_to',
		 'Item Id From' => 'search_item_id_from',
		 'Item Id To' => 'search_item_id_to'
 ];
 public $prg_varify_circular_bom_details = [
		 'name' => 'Verify Circular BOM',
		 'description' => 'Verify if cicular BOM exists',
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
 public $component_item_number;
 public $component_description;
 public $component_uom;

 public function __set($name, $value) {
	$this->$name = $value;
 }

 public function _before_showing() {
	if (!empty($this->common_bom_item_id)) {
	 $item = item::find_by_id($this->common_bom_item_id);
	 $this->commonBom_item_number = $item->item_number;
	 $this->commonBom_item_description = $item->item_description;
	} else {
	 $this->commonBom_item_number = null;
	 $this->commonBom_item_description = null;
	}
 }

 public function _before_submit() {
	
 }

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
	return !empty($result_array) ? array_pop($result_array) : false;
 }

 public function findBy_itemId() {
	$sql = "SELECT * FROM " .
					self::$table_name .
					" where item_id= :item_id LIMIT 1 ";
	$param_a = ['item_id'];
	$value_a = ['item_id' => $this->item_id];
	$result_array = $this->findBy_sql($sql, $param_a, $value_a);
	return !empty($result_array) ? array_pop($result_array) : false;
 }

 private function _explosion($item_id, &$level_array, $level = 0) {
	$boh = new bom_header();
	$boh->item_id = $item_id;
	$boh_i = $boh->findBy_itemId();
	if (empty($boh_i)) {
	 return;
	}
	foreach ($boh->field_a as $key => $value) {
	 if (isset($boh_i->$value)) {
		$boh->$value = $boh_i->$value;
	 }
	}
	$bol = new bom_line();
	$bol_i = $bol->findBy_parentId($boh->bom_header_id);
	if (empty($bol_i)) {
	 return;
	}
	if (empty($level_array[$level])) {
	 $level_array[$level] = [];
	}
	foreach ($bol_i as $items) {
	 foreach ($level_array as &$existing_val_arr) {
		while (($pos = array_search($items->component_item_id, $existing_val_arr)) !== false) {
		 unset($existing_val_arr[$pos]);
		}
	 }
	 array_push($level_array[$level], $items->component_item_id);
	}
	$level++;
	foreach ($bol_i as $items) {
	 $boh->item_id = $items->component_item_id;
	 $boh_i = $boh->findBy_itemId();
	 if (!empty($boh_i)) {
		$this->_explosion($items->component_item_id, $level_array, $level);
	 }
	}
 }

 private function _indented_bom($item_id, &$level_array, $level = 0) {
	$boh = new bom_header();
	$boh->item_id = $item_id;
	$boh_i = $boh->findBy_itemId();
	if (empty($boh_i)) {
	 return;
	}
	foreach ($boh->field_a as $key => $value) {
	 if (isset($boh_i->$value)) {
		$boh->$value = $boh_i->$value;
	 }
	}
	$bol = new bom_line();
	$bol_i = $bol->findBy_parentId($boh->bom_header_id);
	if (empty($bol_i)) {
	 return;
	}
	if (empty($level_array[$level])) {
	 $level_array[$level] = [];
	}
	foreach ($bol_i as $items) {
	 array_push($level_array[$level], $items->component_item_id);
	}
	$level++;
	foreach ($bol_i as $items) {
	 $boh->item_id = $items->component_item_id;
	 $boh_i = $boh->findBy_itemId();
	 if (!empty($boh_i)) {
		$this->_indented_bom($items->component_item_id, $level_array, $level);
	 }
	}
 }

 //not accurate need to change the logic
 private function _varify_circular_bom($item_id, &$parent_ref_items) {
	array_push($parent_ref_items, $item_id);

	$boh = new bom_header();
	$boh->item_id = $item_id;
	$boh_i = $boh->findBy_itemId();
	if (empty($boh_i)) {
	 return;
	}
	$bol = new bom_line();
	$bol_i = $bol->findBy_parentId($boh_i->bom_header_id);
	if (empty($bol_i)) {
	 return;
	}

	foreach ($bol_i as $items) {
	 if (array_search($items->component_item_id, $parent_ref_items)) {
		return $item_id;
	 } else {
		$this->_varify_circular_bom($items->component_item_id, $parent_ref_items);
	 }
	}
 }

 public function prg_varify_circular_bom($seralized_parameters) {
	$parameters = unserialize($seralized_parameters);
  $parent_ref_items = [];
	if (!empty($parameters['org_id'][0])) {
	 $org_id = $parameters['org_id'][0];
	 $this->message .= '<br> Entered Org Id is : ' . $org_id;
	} else {
	 $this->message .= '<br> Error! : No org id found @ cst_item_cost_header ' . __LINE__;
	 return $this->message;
	}

	if (isset($parameters['from_item_id'][0])) {
	 $this->message .= "<br/>Using Item Id ";
	 $from_item_id = $parameters['from_item_id'][0];
	 if (!empty($parameters['to_item_id'][0])) {
		$to_item_id = $parameters['to_item_id'][0];
	 } else {
		$to_item_id = $from_item_id;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemIdRange($from_item_id, $to_item_id);
	 foreach ($item_range as $items) {
		try {
		 $item_id = $this->_varify_circular_bom($items->item_id, $parent_ref_items);
		 if ($item_id) {
			$this->message .= "<br/>$item_id has circular BOM";
		 } else {
			$this->message .= "<br/>No Circular BOM found";
		 }
		} catch (Exception $e) {
		 $this->message .= "<br/> Cicrular BOM Verification failed for Item id " . $items->item_id . $e->getMessage();
		}
	 }
	 return $this->message;
	}

	if (isset($parameters['from_item_number'][0])) {
	 $from_item_number = $parameters['from_item_number'][0];
	 if (!empty($parameters['to_item_number'][0])) {
		$to_item_number = $parameters['to_item_number'][0];
	 } else {
		$to_item_number = $from_item_number;
	 }
	 $item = new item();
	 $item_range = $item->findBy_itemNumberRange_OrgId($from_item_number, $to_item_number, $org_id);
	 foreach ($item_range as $items) {
		try {
		 $item_id = $this->_varify_circular_bom($items->item_id, $parent_ref_items);
		 if ($item_id) {
			$this->message .= "<br/>$item_id has circular BOM";
		 } else {
			$this->message .= "<br/>No Circular BOM found";
		 }
		} catch (Exception $e) {
		 $this->message .= "<br/> Cicrular BOM Verification failed for Item id " . $items->item_id . $e->getMessage();
		}
	 }
	 return $this->message;
	}
 }

 public function BOM_Explosion($item_id) {
	$level_array = [];
	$l = 0;
	$array_level = 'array_' . $l;
	$$array_level = [];
	array_push($$array_level, $item_id);
	array_push($level_array, $$array_level);
	$this->_explosion($item_id, $level_array, 1);
	return $level_array;
 }

 public function indented_BOM($item_id) {
	$level_array = [];
	$l = 0;
	$array_level = 'array_' . $l;
	$$array_level = [];
	array_push($$array_level, $item_id);
	array_push($level_array, $$array_level);
	$this->_indented_bom($item_id, $level_array, 1);
	return $level_array;
 }

}

//end of bom class
?>