<?php

class lms_exam_header extends dbObject {

 public static $table_name = "lms_exam_header";
 public static $primary_column = "lms_exam_header_id";
 public static $dependent_classes = ['lms_exam_line'];
 public static $key_column = 'exam_name';
 public static $module = "lms";
 public static $system_info = [
		 'name' => 'Examination',
		 'number' => '8305',
		 'description' => 'LMS Exam',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 //'dependent_class' => array('lms_dept_res_assignment'),
		 'primary_entity_cb' => '',
		 'module_name' => 'lms',
		 'weight' => 2
 ];
 public $field_a = [
		 'lms_exam_header_id',
		 'exam_name',
		 'exam_month',
		 'exam_year',
		 'lms_group_header_id',
		 'lms_academic_year_id',
		 'lms_term_id',
		 'exam_code',
		 'description',
		 'details',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
		 'struct_name',
 ];
 public $requiredField = [
		 'struct_name',
 ];
 public $pageTitle = " Grade Structure "; //page Title
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $lms_exam_header_id;
 public $exam_name;
 public $exam_month;
 public $exam_year;
 public $lms_group_header_id;
 public $lms_term_id;
 public $exam_code;
 public $description;
 public $details;
 public $status;
 public $lms_academic_year_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public function _before_showing() {
	
 }

 Public static function find_all_tpl_lines_by_category($lms_exam_header_id, $category = 'E_REGULAR') {
	if (empty($lms_exam_header_id)) {
	 return null;
	}
	$sql = " SELECT * 
       FROM lms_exam_header eeh, 
       lms_exam_line eel,
       hr_compensation_element hce
       WHERE eel.lms_exam_header_id = eeh.lms_exam_header_id
       AND eeh.lms_exam_header_id = '{$lms_exam_header_id}'
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

 Public static function find_all_regular_tpl_lines($lms_exam_header_id) {
	return self::find_all_tpl_lines_by_category($lms_exam_header_id, 'E_REGULAR');
 }

 Public static function find_all_basic_tpl_lines($lms_exam_header_id) {
	return self::find_all_tpl_lines_by_category($lms_exam_header_id, 'E_BASIC');
 }

 Public static function find_all_basic_regular_tpl_lines($lms_exam_header_id) {
	return self::find_all_tpl_lines_by_category($lms_exam_header_id, array('E_BASIC', 'E_REGULAR'));
 }

 public static function find_by_employeeId($employee_id) {
	$sql = " SELECT * 
       FROM lms_exam_header eeh 
       WHERE eeh.hr_employee_id = '{$employee_id}'   
";
	$sql = ino_perPageSql_i($sql, 1);
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_pop($result) : false;
 }

}

//end of bom class
?>