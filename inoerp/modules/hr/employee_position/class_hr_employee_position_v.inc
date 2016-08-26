<?php

 class hr_employee_position_v extends dbObject {
public static $form_class_name = "hr_employee";
  public static $table_name = "hr_employee_position_v";
  public static $primary_column = "hr_employee_id";
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
   'job_id',
   'position_id',
   'expense_ac_id',
   'supervisor_employee_id',
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
  public $pageTitle = " Employee Position Details "; //page Title

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

  private function create_hr_employee_position_v() {
   $sql = "
CREATE OR REPLACE VIEW hr_employee_position_v
(
user_id, username, first_name,last_name,email,hr_employee_id,status,
identification_id,emp_start_date,citizen_number,emp_first_name,emp_last_name,phone, 
emp_email,gender,person_type, org_id, job_id, position_id, expense_ac_id,supervisor_employee_id,
position_name, emp_org_id, hr_approval_limit_header_id, document_type, limit_start_date,
limit_type, limit_range_low, limit_range_high, amount_limit,limit_object, bu_org_id, currency_code
)
AS
 SELECT 
user.ino_user_id, user.username, user.first_name,user.last_name,user.email,user.hr_employee_id,user.status,
he.identification_id,he.start_date,he.citizen_number,he.first_name as emp_first_name,he.last_name as emp_last_name,he.phone, 
he.email,he.gender,he.person_type, he.org_id, he.job_id, he.position_id, he.expense_ac_id,he.supervisor_employee_id,
hp.position_name, he.org_id, hala.hr_approval_limit_header_id, hala.document_type, hala.start_date,
hall.limit_type, hall.limit_range_low, hall.limit_range_high, hall.amount_limit,hall.limit_object, halh.bu_org_id, org_v.currency_code
FROM ino_user user
LEFT JOIN hr_employee he ON he.hr_employee_id = user.hr_employee_id
LEFT JOIN hr_position hp ON hp.hr_position_id = he.position_id
LEFT JOIN hr_approval_limit_assign hala ON he.position_id = hala.position_id
LEFT JOIN hr_approval_limit_line hall ON  hala.hr_approval_limit_header_id =  hall.hr_approval_limit_header_id
LEFT JOIN hr_approval_object hao ON  hao.hr_approval_object_id =  hall.limit_object
LEFT JOIN hr_approval_limit_header halh ON hall.hr_approval_limit_header_id = halh.hr_approval_limit_header_id
LEFT JOIN org_v ON org_v.org_id =  halh.bu_org_id


";
  }

  public static function find_by_userId_docType($user_id, $document_type) {
   $sql = " SELECT * FROM ";
   $sql .= self::$table_name;
   $sql .= " WHERE user_id = '{$user_id}' AND document_type = '{$document_type}' ";
   $result =self::find_by_sql($sql);
   return !empty($result) ? ($result) : false;
  }

 }

//end of so_detail class
?>