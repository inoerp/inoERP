<?php

 class hr_employee_education extends dbObject {

  public static $table_name = "hr_employee_education";
  public static $primary_column = "hr_employee_education_id";
  public static $key_column = 'degree_name';
  public static $module = "hr";
    public static $system_info = [
  'name' => 'Employee Education',
  'number' => '3113',
  'description' => 'HR Employee Education',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => '',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 7
 ];
    
  public $field_a = [
   'hr_employee_education_id',
   'employee_id',
   'degree_name',
   'university',
   'university_address',
   'specialization',
   'edu_start_date',
   'edu_end_date',
   'mode_of_education',
   'grade',
   'marks_percentage',
   'comments',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'hr_employee_education_id',
   'employee_id',
   'degree_name',
   'university',
  ];
  public $requiredField = [
   'employee_id',
   'degree_name',
   'university',
   'edu_end_date',
  ];
  public $hr_employee_education_id;
  public $employee_id;
  public $degree_name;
  public $university;
  public $university_address;
  public $specialization;
  public $edu_start_date;
  public $edu_end_date;
  public $mode_of_education;
  public $grade;
  public $marks_percentage;
  public $comments;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " HR Employee Education  "; //page Title

  Public static function education_mode() {
   $option_header = option_header::find_by_name('HR_EDUCATION_MODE');
   $ol = new option_line();
   $option_lines = $ol->findBy_parentId($option_header->option_header_id);
   return $option_lines;
  }

    Public static function find_by_employeeId($employee_id) {
     $sql=  " SELECT * FROM ". self::$table_name . " WHERE employee_id = '{$employee_id}' "  ;
     $result = self::find_by_sql($sql);
     return !empty($result) ? $result : null;
   }
  

 }

//end of hr_employee_education class
?>