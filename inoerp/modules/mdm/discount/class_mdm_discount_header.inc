<?php

class mdm_discount_header extends dbObject {

 public static $table_name = "mdm_discount_header";
 public static $primary_column = "mdm_discount_header_id";
 public static $dependent_classes = ['mdm_discount_line'];
 public static $key_column = 'discount_code';
 public static $module = "mdm";
 public static $system_info = [
		 'name' => 'Discount',
		 'number' => '8305',
		 'description' => 'MDM Discounts',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'dependent_class' => array('mdm_discount_line'),
		 'primary_entity_cb' => '',
		 'module_name' => 'lms',
		 'weight' => 2
 ];
 public static $discount_type_a = [
		 'PER' => 'Percentage',
		 'FORMULA' => 'Formula'
 ];
 public $field_a = [
		 'mdm_discount_header_id',
		 'discount_name',
		 'discount_code',
		 'module_code',
		 'description',
		 'status',
		 'discount_type',
		 'discount_percentage',
		 'discount_formula',
		 'check_condition_cb',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
		 'discount_name',
		 'discount_code',
		 'module_code',
		 'description',
 ];
 public $requiredField = [
		 'discount_name',
		 'discount_code',
		 'module_code',
 ];
 public $pageTitle = " Discount "; //page Title
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $mdm_discount_header_id;
 public $discount_name;
 public $discount_code;
 public $module_code;
 public $description;
 public $status;
 public $discount_type;
 public $discount_percentage;
 public $discount_formula;
 public $check_condition_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_showing() {
	
 }

 Public static function find_all_tpl_lines_by_category($mdm_discount_header_id, $category = 'E_REGULAR') {
	if (empty($mdm_discount_header_id)) {
	 return null;
	}
	$sql = " SELECT * 
       FROM mdm_discount_header eeh, 
       mdm_discount_line eel,
       hr_compensation_element hce
       WHERE eel.mdm_discount_header_id = eeh.mdm_discount_header_id
       AND eeh.mdm_discount_header_id = '{$mdm_discount_header_id}'
        AND hce.hr_compensation_element_id = eel.element_id
        
";
	if (is_array($category)) {
	 $sql .= " AND hce.category IN " . "( '" . implode("','", $category) . "' )";
	} else {
	 $sql .= " AND hce.category = '{$category}' ";
	}
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

 Public static function find_all_regular_tpl_lines($mdm_discount_header_id) {
	return self::find_all_tpl_lines_by_category($mdm_discount_header_id, 'E_REGULAR');
 }

 Public static function find_all_basic_tpl_lines($mdm_discount_header_id) {
	return self::find_all_tpl_lines_by_category($mdm_discount_header_id, 'E_BASIC');
 }

 Public static function find_all_basic_regular_tpl_lines($mdm_discount_header_id) {
	return self::find_all_tpl_lines_by_category($mdm_discount_header_id, array('E_BASIC', 'E_REGULAR'));
 }

 public static function find_by_employeeId($employee_id) {
	$sql = " SELECT * 
       FROM mdm_discount_header eeh 
       WHERE eeh.hr_employee_id = '{$employee_id}'   
";
	$sql = ino_perPageSql_i($sql, 1);
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_pop($result) : false;
 }

}

//end of bom class
?>