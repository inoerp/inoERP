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
 * lms_attendance
 * Contains all the lms_attendance information, such as - lms_attendance, lms_attendance_id, org_id,  type, etc.
 * 
 */
class lms_attendance extends dbObject {

 public static $table_name = "lms_attendance";
 public static $primary_column = "lms_attendance_id";
 public static $key_column = 'hr_employee_id';
 public static $module = "hr";
 public static $multi_select_template_path = 'modules/hr/attendance/multi_action/lms_attendance_template_ma.php';
 public static $js_fileName = 'modules/hr/attendance/attendance.js';
//  data base variables as stored database column name
 public static $system_info = [
		 'name' => 'Student Attendance',
		 'number' => '3130',
		 'description' => 'Student Attendance',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'hr',
		 'weight' => 17
 ];
 public static $status_a = [
		 'ENTERED' => 'Entered',
		 'APPROVED' => 'Approved',
		 'CLOSED' => 'Closed'
 ];
 public $field_a = [
		 'lms_attendance_id',
		 'lms_student_id',
		 'date',
		 'punch_in',
		 'punch_in_note',
		 'punch_out',
		 'punch_out_note',
		 'description',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
		 'lms_student_id',
		 'date',
 ];
 public $fields_inForm_notInDataBase = [
		 "student_name",
 ];
 public $requiredField = [
		 'lms_student_id',
		 'date',
		 'punch_in',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = "Student Attendance"; //page Title
 public $lms_attendance_id;
 public $lms_student_id;
 public $date;
 public $punch_in;
 public $punch_in_note;
 public $punch_out;
 public $punch_out_note;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_fromDate($date) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE from_date = '{$date}'  ";
	$sql = ino_perPageSql_i($sql, 1);
	$result = self::find_by_sql($sql);
	return !empty($result) ? array_pop($result) : false;
 }

 public function multi_select_hidden_fields() {
	$multi_select_hidden = [
			'mode',
			'show_block'
	];

	return $multi_select_hidden;
 }

}

//end of lms_attendance class
?>