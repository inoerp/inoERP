<?php

/**
 * inoERP - Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * lms_student
 * All employee information
 * Contains all the hr_approval_limit_assign information, such as - lms_student_id, identification_id , last_name, etc
 * 
 */
class lms_student extends dbObject {

 public static $table_name = "lms_student";
 public static $primary_column = "lms_student_id";
 public static $key_column = 'last_name';
 public static $dependent_classes = ['lms_student_education', 'lms_student_experience'];
// public static $dependent_classes = ['lms_student_education', 'lms_student_experience', 'lms_student_termination'];
 public static $module = "lms";
 public static $system_info = [
		 'name' => 'Student',
		 'number' => '8308',
		 'description' => 'LMS Student',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
//  'dependent_class' => array('hr_approval_limit_line'),
		 'primary_entity_cb' => '',
		 'module_name' => 'hr',
		 'weight' => 7
 ];
 public static $source_type_a = [
		 'MANUAL' => 'Manual',
		 'IMPORT' => 'Import'
 ];
 public static $student_type_a = [
		 'APPLICANT' => 'Applicant',
		 'STUDENT' => 'Student',
		 'ALLUMNI' => 'Alumni'
 ];
 public $field_a = [
		 'lms_student_id',
		 'identification_id',
		 'start_date',
		 'identification_type',
		 'citizen_number',
		 'first_name',
		 'last_name',
		 'phone',
		 'email',
		 'language',
		 'title',
		 'gender',
		 'lms_program_id',
		 'date_of_birth',
		 'city_of_birth',
		 'country_of_birth',
		 'nationality',
		 'disability_code',
		 'marital_status',
		 'degree',
		 'highest_education',
		 'education_details',
		 'no_of_children',
		 'home_address_id',
		 'home_address',
		 'permanent_address',
		 'permanent_address_id',
		 'mobile_number',
		 'home_phone_number',
		 'other_email',
		 'date_first_joined',
		 'org_id',
		 'location_id',
		 'supervisor_employee_id',
		 'revision_enabled',
		 'status',
		 'revision_number',
		 'expense_ac_id',
		 'vehicle_number',
		 'asset_numbers',
		 'contract_id',
		 'bank_account_id',
		 'tax_reg_number',
		 'social_ac_no',
		 'social_ac_no2',
		 'passport_number',
		 'ledger_id',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'lms_student_id',
		 'identification_id',
		 'citizen_number',
		 'first_name',
		 'last_name',
 ];
 public $fields_inForm_notInDataBase = [
		 "supervisor_employee_name"
 ];
 public $requiredField = [
		 'identification_id',
		 'identification_type',
		 'first_name',
		 'last_name',
//		 'person_type',
 ];
 public $lms_student_id;
 public $identification_id;
 public $start_date;
 public $identification_type;
 public $citizen_number;
 public $first_name;
 public $last_name;
 public $phone;
 public $email;
 public $language;
 public $title;
 public $gender;
 public $lms_program_id;
 public $date_of_birth;
 public $city_of_birth;
 public $country_of_birth;
 public $nationality;
 public $disability_code;
 public $marital_status;
 public $degree;
 public $highest_education;
 public $education_details;
 public $no_of_children;
 public $home_address_id;
 public $home_address;
 public $permanent_address;
 public $permanent_address_id;
 public $mobile_number;
 public $home_phone_number;
 public $other_email;
 public $date_first_joined;
 public $org_id;
 public $location_id;
 public $supervisor_employee_id;
 public $revision_enabled;
 public $status;
 public $revision_number;
 public $expense_ac_id;
 public $vehicle_number;
 public $asset_numbers;
 public $contract_id;
 public $bank_account_id;
 public $tax_reg_number;
 public $social_ac_no;
 public $social_ac_no2;
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
 public $pageTitle = " LMS Student  "; //page Title

 Public static function marital_status() {
	$option_header = option_header::find_by_name('HR_MARITAL_STATUS');
	$ol = new option_line();
	$option_lines = $ol->findBy_parentId($option_header->option_header_id);
	return $option_lines;
 }

 Public static function person_type() {
	$option_header = option_header::find_by_name('HR_PERSON_TYPE');
	$ol = new option_line();
	$option_lines = $ol->findBy_parentId($option_header->option_header_id);
	return $option_lines;
 }

 Public static function identification_type() {
	$option_header = option_header::find_by_name('HR_IDENTIFICATION_TYPE');
	$ol = new option_line();
	$option_lines = $ol->findBy_parentId($option_header->option_header_id);
	return $option_lines;
 }

 Public static function gender() {
	$option_header = option_header::find_by_name('HR_GENDER');
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

 public static function find_by_payrollId($payroll_id) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE payroll_id = '{$payroll_id}' AND status='active'";
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

 public static function find_by_userId($user_id) {
	$sql = " SELECT * 
            FROM lms_student hre, 
                 ino_user as user 
            WHERE user.lms_student_id = hre.lms_student_id
            AND user.ino_user_id = '{$user_id}' ";
	$sql = ino_perPageSql_i($sql, 1);
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_pop($result) : false;
 }

 public static function find_by_orgId($org_id) {
	$sql = " SELECT * 
            FROM lms_student
            WHERE org_id = '{$org_id}' ";
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

 public function _before_showing() {
	if (!empty($this->supervisor_employee_id)) {
	 $emp_details = lms_student::find_by_id($this->supervisor_employee_id);
	 $this->supervisor_employee_name = $emp_details->first_name . ' ' . $emp_details->last_name;
	}
 }

 public function _after_save() {
//   pa($this);
//   pa($_POST);
	if (!empty($this->lms_student_id) && !empty($_POST['degree_name']) && !empty($_POST['degree_name'])) {
	 
	 try {
		$this->_save_education();
		echo "<br>Education details are sucessfully saved.";
	 } Catch (Exception $e) {
		echo "<br>Failed to save education details. Error @ " . __FILE__ . ' @@ ' . __LINE__ . '<br>' . $e->getMessage();
	 }
	}

	if (!empty($this->lms_student_id) && !empty($_POST['organization_name']) && !empty($_POST['work_start_date'])) {
	 try {
		$this->_save_workEx();
		echo "<br>Work Ex details are sucessfully saved.";
	 } Catch (Exception $e) {
		echo "<br>Failed to save Work Ex details. Error @ " . __FILE__ . ' @@ ' . __LINE__ . '<br>' . $e->getMessage();
	 }
	}
 }

 private function _save_education() {
	$eedu = new lms_student_education();
	foreach ($_POST['education_line_id_cb'] as $key => $val) {
	 if (empty($val)) {
		continue;
	 }
	 foreach ($eedu->field_a as $field_k => $field_v) {
		$eedu->$field_v = isset($_POST[$field_v][$key]) ? $_POST[$field_v][$key] : null;
	 }
	 $eedu->lms_student_id = $this->lms_student_id;
	 $eedu->save();
	}
 }

 private function _save_workEx() {
	$emp_exp = new lms_student_experience();
	foreach ($_POST['experience_line_id_cb'] as $key => $val) {
	 if (empty($val)) {
		continue;
	 }
	 foreach ($emp_exp->field_a as $field_k => $field_v) {
		$emp_exp->$field_v = isset($_POST[$field_v][$key]) ? $_POST[$field_v][$key] : null;
	 }
	 $emp_exp->employee_id = $this->lms_student_id;
	 $emp_exp->save();
	}
 }

}

//end of lms_student class
?>