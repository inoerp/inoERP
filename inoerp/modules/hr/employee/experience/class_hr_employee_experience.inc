<?php

 class hr_employee_experience extends dbObject {
  public static $system_info = [
  'name' => 'Employee Experience',
  'number' => '3114',
  'description' => 'HR Employee Experience',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => '',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 7
 ];
  public static $table_name = "hr_employee_experience";
  public static $primary_column = "hr_employee_experience_id";
  public static $key_column = 'organization_name';
  public static $module = "hr";
  public $field_a = [
   'hr_employee_experience_id',
   'employee_id',
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
   'hr_employee_experience_id',
   'employee_id',
   'organization_name',
  ];
  public $requiredField = [
   'work_start_date',
   'employee_id',
   'organization_name',
  ];
  public $hr_employee_experience_id;
  public $employee_id;
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
  public $pageTitle = " HR Employee experience  "; //page Title


  Public static function find_by_employeeId($employee_id) {
   $sql = " SELECT * FROM " . self::$table_name . " WHERE employee_id = '{$employee_id}' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : null;
  }

 }

//end of hr_employee_experience class
?>