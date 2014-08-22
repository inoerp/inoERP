<?php

 class hr_approval_limit_assignment extends dbObject {

  public static $table_name = "hr_approval_limit_assignment";
  public static $primary_column = "hr_approval_limit_assignment_id";
  public static $key_column = 'hr_approval_limit_header_id';
  public static $module = "hr";
  public $field_a = [
   'hr_approval_limit_assignment_id',
   'hr_approval_limit_header_id',
   'bu_org_id',
   'job_id',
   'position_id',
   'document_type',
   'start_date',
   'end_date',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'hr_approval_limit_header_id',
   'bu_org_id',
   'job_id',
  ];
  public $requiredField = [
   'hr_approval_limit_header_id',
   'document_type',
  ];
  public $hr_approval_limit_assignment_id;
  public $hr_approval_limit_header_id;
  public $bu_org_id;
  public $job_id;
  public $position_id;
  public $document_type;
  public $start_date;
  public $end_date;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " HR Approval Limit Assignments  "; //page Title

  public static function find_all_header_levels() {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE level = 'HEADER' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

  public static function find_all_line_levels() {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE level = 'LINE' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

 }

//end of hr_approval_limit_assignment class
?>