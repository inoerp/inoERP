<?php

class hr_team_header extends dbObject {

 public static $table_name = "hr_team_header";
 public static $primary_column = "hr_team_header_id";
 public static $dependent_classes = ['hr_team_line'];
 public static $key_column = 'team_name';
 public static $module = "hr";
// public static $js_fileName = 'modules/hr/element_entry/js/multi_select.js';
 public static $type_a = [
  'SALES' => 'Sales',
  'PROJECT' => 'Project',
  'CONTRACT' => 'Contract',
  'OTHER' => 'Others'
 ];
 public $field_a = [
  'hr_team_header_id',
  'team_name',
  'team_lead_employee_id',
  'type',
  'region',
  'objective',
  'email',
  'status',
  'start_date',
  'end_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 //variables used for showing data

 public $initial_search = [
  'team_name',
  'team_lead_employee_id',
 ];
 public $requiredField = [
  'team_name',
 ];
 public $fields_inForm_notInDataBase = [
  "lead_employee_name",
 ];
 
   public $numberField = [
 'hr_team_header_id',
  'team_lead_employee_id',
 ];
   
 public $pageTitle = " HR Team "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $hr_team_header_id;
 public $team_name;
 public $team_lead_employee_id;
 public $type;
 public $region;
 public $objective;
 public $email;
 public $status;
 public $start_date;
 public $end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $lead_employee_name;

 public static function find_by_employeeId($employee_id) {
  $sql = " SELECT * 
       FROM hr_team_header eeh 
       WHERE eeh.hr_employee_id = '{$employee_id}'   
        LIMIT 1
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function findBy_employeeId($employee_id) {
  $sql = " SELECT * 
       FROM hr_team_header eeh 
       WHERE eeh.hr_employee_id = '{$employee_id}'   
        LIMIT 1
";
  $result = $this->findBySql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 Public static function team_region() {
  $option_header = option_header::find_by_name('HR_TEAM_REGION');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function hr_role() {
  $option_header = option_header::find_by_name('HR_ROLE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function find_all_sales_team() {
  $sql = " SELECT * 
       FROM hr_team_header eeh 
       WHERE eeh.type = 'SALES'   
";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

}

//end of bom class
?>