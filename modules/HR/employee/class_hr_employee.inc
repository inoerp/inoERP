<?php
 class hr_empoyee extends dbObject {

  public static $table_name = "hr_empoyee";
  public static $primary_column = "hr_empoyee_id";
  public static $key_column = 'transaction_source';
  public static $module = "hr"; 
  public static $template_type = [
   'header_tab' => 1,
   'line_tab' => 2,
   'nooffields_header_tab1' => 5,
   'nooffields_line_tab1' => 6,
   'nooffields_line_tab2' => 6,
  ];
  public static $source_type_a = [
   'MANUAL' => 'Manual',
   'IMPORT' => 'Import'
  ];
  public $field_a = [
   'hr_employee_id',
   'identification_id',
   'identification_type',
   'citizen_number',
   'first_name',
   'last_name',
   'phone',
   'email',
   'language',
   'title',
   'gender',
   'person_type',
   'date_of_birth',
   'city_of_birth',
   'country_of_birth',
   'nationality',
   'disability_code',
   'marital_status',
   'degree',
   'highest_education',
   'no_of_children',
   'home_address_id',
   'home_address',
   'permanent_address',
   'permanent_address_id',
   'mobile_number',
   'home_phone_number',
   'other_email',
   'date_first_hired',
   'org_id',
   'job_id',
   'position_id',
   'grade_id',
   'location_id',
   'job_type',
   'supervisor_employee_id',
   'probation_period_uom',
   'probation_period',
   'notice_period_uom',
   'notice_period',
   'revision_enabled',
   'status',
   'revision_number',
   'work_policy_id',
   'expense_ac_id',
   'performance_id',
   'vechile_number',
   'asset_numbers',
   'contract_id',
   'bank_account_id',
   'tax_reg_number',
   'passport_number',
   'ledger_id',
   'created_by',
   'creation_date',
   'last_update_by',
   'last_update_date',
  ];
  public $initial_search = [
   'identification_id',
   'citizen_number',
   'first_name',
   'last_name',
  ];
  public $column = [
   'identification_id',
   'identification_type',
   'citizen_number',
   'first_name',
   'last_name',
  ];
  public $requiredField = [
   'hr_employee_id',
   'identification_id',
   'identification_type',
   'first_name',
   'last_name',
   'phone',
   'email',
   'person_type',
  ];
  public $hr_employee_id;
  public $identification_id;
  public $identification_type;
  public $citizen_number;
  public $first_name;
  public $last_name;
  public $phone;
  public $email;
  public $language;
  public $title;
  public $gender;
  public $person_type;
  public $date_of_birth;
  public $city_of_birth;
  public $country_of_birth;
  public $nationality;
  public $disability_code;
  public $marital_status;
  public $degree;
  public $highest_education;
  public $no_of_children;
  public $home_address_id;
  public $home_address;
  public $permanent_address;
  public $permanent_address_id;
  public $mobile_number;
  public $home_phone_number;
  public $other_email;
  public $date_first_hired;
  public $org_id;
  public $job_id;
  public $position_id;
  public $grade_id;
  public $location_id;
  public $job_type;
  public $supervisor_employee_id;
  public $probation_period_uom;
  public $probation_period;
  public $notice_period_uom;
  public $notice_period;
  public $revision_enabled;
  public $status;
  public $revision_number;
  public $work_policy_id;
  public $expense_ac_id;
  public $performance_id;
  public $vechile_number;
  public $asset_numbers;
  public $contract_id;
  public $bank_account_id;
  public $tax_reg_number;
  public $passport_number;
  public $ledger_id;
  public $created_by;
  public $creation_date;
  public $last_update_by;
  public $last_update_date;
  public $search = [
   '_show_update_path' => 1,
   '_update_action_meassge' => 'Update',
   '_show_view_path' => 1,
  ];
  public $pageTitle = " HR Employee  "; //page Title

  
   Public static function marital_status() {
	$option_header = option_header::find_by_name('HR_MARITAL_STATUS');
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

  public static function find_all_line_levels() {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE level = 'LINE' ";
   $result = self::find_by_sql($sql);
   return !empty($result) ? $result : false;
  }

  public static function find_by_transactionClass($class) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE type_class = '{$class}' AND status='active'";
   $result = self::find_by_sql($sql);
   return $result;
  }

 }

//end of hr_empoyee class
?>