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
 * hr_position
 * Employee positions.
 * Contains all the conversion information, such as - position_name, job_id , org_id, etc
 * 
 */
 
 class hr_position extends dbObject {

  public static $table_name = "hr_position";
  public static $primary_column = "hr_position_id";
  public static $key_column = 'position_name';
  public static $module = "hr";
   public static $system_info = [
  'name' => 'Approval Limit',
  'number' => '3111',
  'description' => 'HR Approval Limit',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 20
 ];
 public $field_a = [
   'hr_position_id',
   'position_name',
   'job_id',
   'org_id',
   'location_id',
   'description',
   'start_date',
   'end_date',
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
  public $end_date;
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