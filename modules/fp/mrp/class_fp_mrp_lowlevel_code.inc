<?php

class fp_mrp_lowlevel_code extends dbObject {

 public static $table_name = "fp_mrp_lowlevel_code";
 public static $primary_column = "fp_mrp_lowlevel_code_id";
 public static $key_column = 'item_id_m';
 public static $module = "fp";
 public $field_a = [
		 'fp_mrp_lowlevel_code_id',
		 'org_id',
		 'item_id_m',
		 'level',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'fp_mrp_lowlevel_code_id',
		 'item_id_m',
		 'level',
 ];
 public $column = [
		 'fp_mrp_lowlevel_code_id',
		 'org_id',
		 'item_id_m',
		 'level',
 ];
 public $requiredField = [
		 'org_id',
		 'item_id_m',
		 'level',
 ];
 public $search = [
 ];
 public $pageTitle = " MRP Item Low Level Code "; //page Title
 public $fp_mrp_lowlevel_code_id;
 public $org_id;
 public $item_id_m;
 public $level;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function findBy_itemId($item_id_m) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE item_id_m = :item_id_m LIMIT 1";
	$value_a = ['item_id_m' => $item_id_m];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? array_pop($result) : false;
 }

 public function findAll_levels($org_id) {
	$sql = " SELECT DISTINCT(level) FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE org_id = :org_id ";
	$sql .= " ORDER BY LEVEL ASC";
	$value_a = ['org_id' => $org_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? ($result) : false;
 }

 public function findAll_orderByLevel($org_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE org_id = :org_id ";
	$sql .= " ORDER BY LEVEL ASC";
	$value_a = ['org_id' => $org_id];
	$result = $this->findBySql($sql, $value_a);
	return !empty($result) ? ($result) : false;
 }

 private function _search_item_inLowLevelCode($item_id_m, &$existing_level, $lowLevelCode_a) {
	foreach ($lowLevelCode_a as $level_key => $level_value_a) {
	 if (array_search($item_id_m, $level_value_a) !== false) {
		$existing_level = $level_key;
		return array_search($item_id_m, $level_value_a);
	 }
	}
	return false;
 }

 public function find_lowlevel_code($org_id) {
	$boh = new bom_header();
	$all_boms = $boh->findBy_orgId($org_id);
	$lowLevel_code = [];

	foreach ($all_boms as $bom) {
	 $exploded_bom = $boh->BOM_Explosion($bom->item_id_m);
	 	 if (empty($lowLevel_code)) {
		$lowLevel_code = $exploded_bom;
	 } else {
		foreach ($exploded_bom as $new_level => $item_a) {
		 foreach ($item_a as $key => $item_id_m) {
			$existing_level = 0;
			$verify_item_key = $this->_search_item_inLowLevelCode($item_id_m, $existing_level, $lowLevel_code);
			if ($verify_item_key !== false) {
			 if ($new_level > $existing_level) {
				unset($lowLevel_code[$existing_level][$verify_item_key]);
				if (array_key_exists($new_level, $lowLevel_code)) {
				 array_push($lowLevel_code[$new_level], $item_id_m);
				} else {
				 $lowLevel_code[$new_level] = array($item_id_m);
				}
			 }
			} else {
			 if (array_key_exists($new_level, $lowLevel_code)) {
				array_push($lowLevel_code[$new_level], $item_id_m);
			 } else {
				$lowLevel_code[$new_level] = array($item_id_m);
			 }
			}
		 }
		}
	 }
	}

	return $lowLevel_code;
 }

 public function create_lowlevel_code($org_id) {
	$low_level_code_a = $this->find_lowlevel_code($org_id);
	$mrp_llc = new fp_mrp_lowlevel_code();
	foreach ($low_level_code_a as $level => $level_item_a) {
	 $level++;
	 foreach ($level_item_a as $key => $item_id_m) {
		$mrp_llc_i = $mrp_llc->findBy_itemId($item_id_m);
		$mrp_llc->fp_mrp_lowlevel_code_id = ($mrp_llc_i) ? $mrp_llc_i->fp_mrp_lowlevel_code_id : null;
		$mrp_llc->org_id = $org_id;
		$mrp_llc->item_id_m = $item_id_m;
		$mrp_llc->level = $level;
		$mrp_llc->audit_trial();
		$mrp_llc->save();
	 }
	}
 }

}

?>
