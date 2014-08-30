<?php
//namespace modules\hr\position;
 
 class hr_position extends dbObject {

  public static $table_name = "hr_position";
  public static $primary_column = "hr_position_id";
  public static $key_column = 'position_name';
  public static $module = "hr";
  public $field_a = [
   'hr_position_id',
   'position_name',
   'job_id',
   'org_id',
   'location_id',
   'description',
   'start_date',
   'end_Date',
   'headcount',
   'grade_id',
   'payroll_id',
   'salary_basis',
   'working_hours',
   'wh_frequency',
   'position_details',
   'position_status',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'hr_position_id',
   'position_name',
   'job_id',
  ];
  public $column = [
   'hr_position_id',
   'position_name',
   'job_id',
   'org_id',
   'location_id',
   'description',
  ];
  public $requiredField = [
   'position_name',
   'job_id',
   'org_id',
  ];
  public $hr_position_id;
  public $position_name;
  public $job_id;
  public $org_id;
  public $location_id;
  public $description;
  public $start_date;
  public $end_Date;
  public $headcount;
  public $grade_id;
  public $payroll_id;
  public $salary_basis;
  public $working_hours;
  public $wh_frequency;
  public $position_details;
  public $position_status;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " HR positions  "; //page Title

  Public static function position_position_type() {
   $option_header = option_header::find_by_name('HR_position_POSITION_TYPE');
   $ol = new option_line();
   $option_lines = $ol->findBy_parentId($option_header->option_header_id);
   return $option_lines;
  }

 }

//end of hr_position class
?>