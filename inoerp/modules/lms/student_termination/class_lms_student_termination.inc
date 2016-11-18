<?php

class lms_student_termination extends dbObject {

 public static $table_name = "lms_student_termination";
 public static $primary_column = "lms_student_termination_id";
 public static $key_column = 'employee_id';
 public static $module = "hr";
 public static $status_a = [
		 'APPLIED' => 'Applied',
		 'PENDING_APPROVAL' => 'Pending Approval',
		 'PENDING_CLEARANCE' => 'Pending Clearance',
		 'ACCEPTED' => 'Accepted',
		 'REJECTED' => 'Rejected',
		 'COMPLETED' => 'Completed'
 ];
 public $field_a = [
		 'lms_student_termination_id',
		 'lms_student_id',
		 'new_employer',
		 'reason',
		 'status',
		 'date_of_notification',
		 'projected_last_date',
		 'actual_last_date',
		 'accpeted_date',
		 'accpeted_by_employee_id',
		 'new_university',
		 'new_contact_email',
		 'new_contact_number',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'lms_student_termination_id',
		 'employee_id',
 ];
 public $requiredField = [
		 'employee_id',
 ];
 public $fields_inForm_notInDataBase = [
		 "employee_name",
		 "identification_id"
 ];

 
 public $lms_student_termination_id;
public $lms_student_id;
public $new_employer;
public $reason;
public $status;
public $date_of_notification;
public $projected_last_date;
public $actual_last_date;
public $accpeted_date;
public $accpeted_by_employee_id;
public $new_university;
public $new_contact_email;
public $new_contact_number;
public $created_by;
public $creation_date;
public $last_update_by;
public $last_update_date;


 public $employee_name;
 public $identification_id;
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

 public function _after_save() {
	if ($this->status == 'COMPLETED' && !empty($this->employee_id)) {
	 $hr_em = new lms_student();
	 $hr_em->lms_student_id = $this->employee_id;
	 $hr_em->status = 'INACTIVE';
	 $hr_em->person_type = 'EMPLOYEE_EX';
	 try {
		$hr_em->save();
	 } catch (Exception $e) {
		
	 }
	}
 }

}

//end of lms_student_termination class
?>