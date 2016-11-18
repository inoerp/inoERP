<?php

class lms_student_experience extends dbObject {

 public static $system_info = [
		 'name' => 'Student Experience',
		 'number' => '8311',
		 'description' => 'LMS Student Experience',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'dependent_class' => '',
		 'primary_entity_cb' => '',
		 'module_name' => 'hr',
		 'weight' => 7
 ];
 public static $table_name = "lms_student_experience";
 public static $primary_column = "lms_student_experience_id";
 public static $key_column = 'organization_name';
 public static $module = "lms";
 public $field_a = [
		 'lms_student_experience_id',
		 'lms_student_id',
		 'organization_name',
		 'designation',
		 'employee_number',
		 'department',
		 'work_start_date',
		 'work_end_date',
		 'last_manager',
		 'last_drawn_salary',
		 'communication_details',
		 'project_details',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'lms_student_experience_id',
		 'lms_student_id',
		 'organization_name',
		 'designation',
		 'employee_number',
		 'department',
 ];
 public $requiredField = [
		 'lms_student_id',
		 'designation',
 ];
 public $lms_student_experience_id;
 public $lms_student_id;
 public $organization_name;
 public $designation;
 public $employee_number;
 public $department;
 public $work_start_date;
 public $work_end_date;
 public $last_manager;
 public $last_drawn_salary;
 public $communication_details;
 public $project_details;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Student Experience  "; //page Title

 Public static function find_by_employeeId($employee_id) {
	$sql = " SELECT * FROM " . self::$table_name . " WHERE employee_id = '{$employee_id}' ";
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : null;
 }
 
 public static function find_by_studentId($student_id){
	
	$sql = " SELECT * FROM " . self::$table_name . " WHERE lms_student_id = :lms_student_id " ;
	$value_a = ['lms_student_id' => $student_id ];
	$result = self::find_by_sql_i($sql, $value_a);
	
	return !empty($result) ? $result : null;
 }

}

//end of lms_student_experience class
?>