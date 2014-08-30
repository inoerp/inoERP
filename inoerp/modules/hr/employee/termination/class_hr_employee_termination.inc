<?php

 class hr_employee_termination extends dbObject {

  public static $table_name = "hr_employee_termination";
  public static $primary_column = "hr_employee_termination_id";
  public static $key_column = 'employee_id';
  public static $module = "hr";
  public $field_a = [
   'hr_employee_termination_id',
   'employee_id',
   'new_employer',
   'reason',
   'date_of_notification',
   'projected_last_date',
   'actual_last_date',
   'accpeted_date',
   'accpeted_by_employee_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'hr_employee_termination_id',
   'employee_id',
  ];
  public $requiredField = [
   'employee_id',
  ];
  public $fields_inForm_notInDataBase = [
   "employee_name",
   "employee_number"
  ];
    
  public $hr_employee_termination_id;
  public $employee_id;
  public $new_employer;
  public $reason;
  public $date_of_notification;
  public $projected_last_date;
  public $actual_last_date;
  public $accpeted_date;
  public $accpeted_by_employee_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $employee_name;
  public $employee_number;
  
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " HR Employee termination  "; //page Title

  Public static function find_by_employeeId($employee_id) {
   $sql = " SELECT * FROM " . self::$table_name . " WHERE employee_id = '{$employee_id}' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : null;
  }

 }

//end of hr_employee_termination class
?>