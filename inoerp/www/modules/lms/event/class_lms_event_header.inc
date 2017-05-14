<?php

/**
 * inoERP
 *
 * @copyright   2015 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * mail_form
 * Contains all the mail_form information, such as - mail_form_id, type, description,  mail_form_name, etc.
 * 
 */

class lms_event_header extends dbObject {

 public static $key_column = 'title';
 public static $table_name = 'lms_event_header';
 public static $primary_column = "lms_event_header_id";
 public static $dependent_classes = ['lms_event_line'];
 public static $module = "lms";
 public static $system_info = [
		 'name' => 'LMS Event',
		 'number' => '3119',
		 'description' => 'LMS Event',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'lms',
		 'weight' => 17
 ];
 public static $frequencey_umo_a = [
		 'DAILY' => 'Daily',
		 'WEEKLY' => 'Weekly',
		 'MONTHLY' => 'Monthly',
		 'YEARLY' => 'Yearly',
 ];
 public $field_a = [
		 'lms_event_header_id',
		 'user_id',
		 'start_date',
		 'start_time',
		 'end_date',
		 'end_time',
		 'title',
		 'location',
		 'url',
		 'event_details',
		 'privacy',
		 'event_color',
		 'frequency_uom',
		 'frequncy_val',
		 'description',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $fields_inForm_notInDataBase = [
		 "employee_name",
		 'username',
		 'first_name',
		 'last_name',
 ];
 public $requiredField = [
		 'start_date',
		 'end_date',
		 'title'
 ];
 public $initial_search = [
		 'title',
		 'description',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Event "; //page Title
 public $lms_event_header_id;
 public $user_id;
 public $start_date;
 public $start_time;
 public $end_date;
 public $end_time;
 public $title;
 public $location;
 public $url;
 public $event_details;
 public $privacy;
 public $event_color;
 public $description;
 public $frequency_uom;
 public $frequncy_val;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $username;
 public $first_name;
 public $last_name;

 public static function find_by_year_user($year = '', $user = '') {
	$year = empty($year) ? date("Y") : $year;
	$user = empty($user) ? $_SESSION['user_id'] : $user;
	$first_date = $year . '-01-01';
	$last_date = $year . '-12-31';

	$sql = " SELECT * from ";
	$sql .= self::$table_name;
	$sql .= " WHERE start_date >= '$first_date' ";
	$sql .= " AND end_date <= '$last_date' ";
	$sql .= " AND user_id = '$user' ";
	$sql .= " ORDER BY start_date, start_time ASC ";
	$result = self::find_by_sql($sql);
	return !empty($result) ? $result : false;
 }

}

?>