<?php

 class hr_leave_type extends dbObject {

  public static $table_name = "hr_leave_type";
  public static $primary_column = "hr_leave_type_id";
  public static $key_column = 'leave_type';
  public static $module = "hr";
  public $field_a = [
   'hr_leave_type_id',
   'leave_type',
   'leave_category',
   'description',
   'allow_carry_forward_cb',
   'carry_forward_per_year',
   'maximum_accumulation',
   'auto_convert_salary_cb',
   'allow_advance_cb',
   'lwp_cb',
   'default_reason',
   'status',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'hr_leave_type_id',
   'leave_type',
   'description',
  ];
  public $requiredField = [
   'leave_type',
   'leave_category',
  ];
  public $checkbox = [
   'allow_carry_forward_cb',
   'auto_convert_salary_cb',
   'allow_advance_cb',
   'lwp_cb',
  ];
  public $hr_leave_type_id;
  public $leave_type;
  public $leave_category;
  public $description;
  public $allow_carry_forward_cb;
  public $carry_forward_per_year;
  public $maximum_accumulation;
  public $auto_convert_salary_cb;
  public $allow_advance_cb;
  public $lwp_cb;
  public $default_reason;
  public $status;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $search = [
   '_show_update_path' => 1,
   '_show_view_path' => 1,
  ];
  public $pageTitle = " HR Leave Types  "; //page Title
  
  
  public function _before_Save(){
//   pa($_POST);
//   pa($this);
  }

  Public static function leave_category() {
   $option_header = option_header::find_by_name('HR_LEAVE_CATEGORY');
   $ol = new option_line();
   $option_lines = $ol->findBy_parentId($option_header->option_header_id);
   return $option_lines;
  }

  public static function find_all_header_levels() {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE level = 'HEADER' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

 }

//end of hr_leave_type class
?>