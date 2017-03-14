<?php

/**
 * inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * mdm_discount_value
 *
 */
class mdm_discount_value extends dbObject {

 public static $table_name = "mdm_discount_value";
 public static $module = "inv";
 public static $primary_column = "mdm_discount_value_id";
 public static $key_column = "relation_type";
 public static $system_info = [
		 'name' => 'Discount Value',
		 'number' => '2119',
		 'description' => 'Define and Mainten Discount Value',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'primary_entity_cb' => '',
		 'module_name' => 'inv',
		 'weight' => 4
 ];
 public static $status_a = [
		 'active' => 'Active',
		 'inactive' => 'Inactive'
 ];
 public $field_a = [
		 'mdm_discount_value_id',
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'mdm_discount_line_id',
		 'discount_percentage',
		 'discount_amount',
		 'discount_formula',
		 'manual_cb',
		 'close_bracket',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'reference_type',
		 'reference_key_name',
 ];
 public $requiredField = [
		 'reference_type',
		 'reference_key_name',
		 'reference_key_value',
		 'mdm_discount_line_id',
 ];
 public $fields_inForm_notInDataBase = [
		 'from_item_number',
		 'to_item_number',
		 'from_item_description',
		 'to_item_description',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
		 'relation_type'
 ];
 public $search = [
		 '_update_path' => 'form.php?class_name=mdm_discount_value&mode=9',
		 '_show_update_path' => 1,
		 '_view_path' => 'form.php?class_name=mdm_discount_value&mode=2',
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Discount Value "; //page Title
 public $option_list = [
		 'relation_type' => 'mdm_discount_value',
 ]; //list of search fields wh
 public $mdm_discount_value_id;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $mdm_discount_line_id;
 public $discount_percentage;
 public $discount_amount;
 public $discount_formula;
 public $manual_cb;
 public $close_bracket;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_save() {
	if (!empty($this->from_item_number)) {
	 $item_i = item::find_by_itemNumber_fromMasterOrg($this->from_item_number);
	 if ($item_i) {
		$this->from_item_id_m = $item_i->item_id_m;
	 } else {
		echo "<br>Wrong item number. Error @ " . __FILE__ . ' @ line num ' . __LINE__;
	 }
	}

	if (!empty($this->to_item_number)) {
	 $item_j = item::find_by_itemNumber_fromMasterOrg($this->to_item_number);
	 if ($item_j) {
		$this->to_item_id_m = $item_j->item_id_m;
	 } else {
		echo "<br>Wrong item number. Error @ " . __FILE__ . ' @ line num ' . __LINE__;
	 }
	}
 }

 Public static function item_relation() {
	$option_header = option_header::find_by_name('mdm_discount_value');
	$ol = new option_line();
	$option_lines = $ol->findBy_parentId($option_header->option_header_id);
	return $option_lines;
 }

 public function find_all_ofyear($year) {
	global $db;
	$sql = " SELECT * FROM " . self::$table_name;
	$sql .= " WHERE year= :year ";
	$param_a = ['year'];
	$value_a = ['year' => $year];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
	return $result;
 }

 public static function find_all_by_relationType($relation_type) {
	$sql = " 
	 SELECT *
	 FROM mdm_discount_value
	 WHERE relation_type = '{$relation_type}'
	";
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

 public static function find_all_by_fromItemIdM($from_item_id_m) {
	$sql = " 
	 SELECT *
	 FROM mdm_discount_value
	 WHERE from_item_id_m = '{$from_item_id_m}'
	";
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

}

//end of mdm_discount_value class
?>