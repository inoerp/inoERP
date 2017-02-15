<?php

class hr_student_v extends dbObject {

 public static $form_class_name = "hr_student_v";
 public static $table_name = "hr_student_v";
 public static $primary_column = "hr_student_id";
 public $field_a = [
  'user_id',
  'username',
  'first_name',
  'last_name',
  'email',
  'hr_employee_id',
  'status',
  'identification_id',
  'emp_start_date',
  'citizen_number',
  'emp_first_name',
  'emp_last_name',
  'phone',
  'emp_email',
  'gender',
  'person_type',
  'org_id',
  'currency_code',
  'employee_name'
 ];
 public $initial_search = [
  'username',
  'first_name',
  'last_name',
 ];
 public $multi_select_column = [
  'user_id',
  'username',
  'first_name',
  'last_name',
  'email',
  'hr_employee_id',
  'status',
  'identification_id',
  'emp_start_date',
  'citizen_number',
  'emp_first_name',
  'emp_last_name',
  'phone',
  'emp_email',
  'gender',
  'person_type',
  'org_id',
  'job_id',
  'position_id',
  'expense_ac_id',
  'position_name',
  'emp_org_id',
  'hr_approval_limit_header_id',
  'document_type',
  'limit_start_date',
  'limit_type',
  'limit_range_low',
  'limit_range_high',
  'amount_limit',
  'limit_object',
  'bu_org_id',
  'currency_code',
 ];
 
  public static $json_label_fields = [
   'username',
   'person_type',
  'identification_id',
   'employee_name'
 ];
 public $dateField = [
  'limit_start_date',
 ];
 public $search = [
//   '_update_path' => 'form.php?class_name=sd_so_header',
//   '_show_update_path' => 1,
//   '_view_path' => 'form.php?class_name=sd_so_header',
//   '_show_view_path' => 1,
////		 '_view_action_meassge' => 'View',
//   '_extra_path' => array('form.php?class_name=ar_transaction_header&mode=9' => 'Invoice',
//    'form.php?class_name=sd_delivery_header&mode=9' => 'Ship')
 ];
 public $pageTitle = " Employee Details "; //page Title
 public $user_id;
 public $username;
 public $first_name;
 public $last_name;
 public $email;
 public $hr_employee_id;
 public $status;
 public $identification_id;
 public $emp_start_date;
 public $citizen_number;
 public $emp_first_name;
 public $emp_last_name;
 public $phone;
 public $emp_email;
 public $gender;
 public $person_type;
 public $org_id;
 public $job_id;
 public $position_id;
 public $expense_ac_id;
 public $supervisor_employee_id;
 public $position_name;
 public $emp_org_id;
 public $hr_approval_limit_header_id;
 public $document_type;
 public $limit_start_date;
 public $limit_type;
 public $limit_range_low;
 public $limit_range_high;
 public $amount_limit;
 public $limit_object;
 public $bu_org_id;
 public $currency_code;
 public $employee_name;

 private function create_lms_student_v() {
  $sql = "
CREATE OR REPLACE VIEW lms_student_v
(
lms_student_id, identification_id,  start_date, identification_type, citizen_number, first_name,
last_name, phone, email, language, title, gender, lms_program_id, date_of_birth, city_of_birth,
country_of_birth, nationality, disability_code, marital_status, degree, highest_education,
education_details, no_of_children, home_address_id, home_address, permanent_address, permanent_address_id,
mobile_number, home_phone_number, other_email, date_first_joined, org_id, location_id, 
CONCAT(last_name, ', ' , first_name) as student_name, org_v.currency_code, org_v.org
)
AS
SELECT 
ls.lms_student_id, ls.identification_id,  ls.start_date, ls.identification_type, ls.citizen_number, ls.first_name,
ls.last_name, ls.phone, ls.email, ls.language, ls.title, ls.gender, ls.lms_program_id, ls.date_of_birth, ls.city_of_birth,
ls.country_of_birth, ls.nationality, ls.disability_code, ls.marital_status, ls.degree, ls.highest_education,
ls.education_details, ls.no_of_children, ls.home_address_id, ls.home_address, ls.permanent_address, ls.permanent_address_id,
ls.mobile_number, ls.home_phone_number, ls.other_email, ls.date_first_joined, ls.org_id, ls.location_id, 
CONCAT(ls.last_name, ', ' , ls.first_name) as student_name, org_v.currency_code, org_v.org

FROM lms_student ls
LEFT JOIN ino_user user ON ls.lms_student_id = user.ino_user_id
LEFT JOIN org_v ON org_v.org_id =  ls.org_id


";
 }

 public static function find_by_userId_docType($user_id, $document_type) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE user_id = '{$user_id}' AND document_type = '{$document_type}' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? ($result) : false;
 }

 
  public static function find_by_ColumnNameVal($columnName, $columnVal, $dependent_fields = '', $hidden_fields = '') {
  $sql = " SELECT   user_id,   username,   first_name,   last_name,   email,
  hr_employee_id,     identification_id,   emp_start_date,   citizen_number,
  emp_first_name,   emp_last_name,    emp_email,   gender,   person_type,  employee_name  ";

  $sql .= " FROM " . static::$table_name . " where " . $columnName . " LIKE  '%{$columnVal}%'  ";

//  if(!empty($_GET['hidden_fields']['receving_org_id'])){
//   $rec_org_id = $_GET['hidden_fields']['receving_org_id'];
//   $sql .= " AND receving_org_id = '{$rec_org_id}' ";
//  }
  if (!empty($dependent_fields)) {
   foreach ($dependent_fields as $k => $v) {
    if (!empty($k) && !empty($v)) {
     $sql .= " AND $k = '{$v}' ";
    }
   }
  }
  $result_array = static::find_by_sql($sql);
  return !empty($result_array) ? ($result_array) : false;
 }
 
}

//end of so_detail class
?>