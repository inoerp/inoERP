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
 * lms_chapter
 * All Job information
 * Contains all the lms_chapter information, such as - lms_chapter_id, job_code , job_name, etc
 * 
 */
class lms_chapter extends dbObject {

 public static $table_name = "lms_chapter";
 public static $primary_column = "lms_chapter_id";
 public static $key_column = 'chapter_name';
 public static $module = "lms";
 public static $system_info = [
		 'name' => 'Chapter',
		 'number' => '8301',
		 'description' => 'Chapter',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'lms',
		 'weight' => 8
 ];
 public $field_a = [
		 'lms_chapter_id',
		 'chapter_name',
		 'chapter_code',
		 'overview',
		 'topics',
		 'reference',
		 'description',
		 'status',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'chapter_name',
		 'chapter_code',
 ];
 public $column = [
	 'lms_chapter_id',
		 'chapter_name',
		 'chapter_code',
		 'description',
		 'status',
 ];
 public $requiredField = [
		 'chapter_name',
		 'chapter_code'
 ];
 public $lms_chapter_id;
 public $chapter_name;
 public $chapter_code;
 public $overview;
 public $topics;
 public $reference;
 public $description;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
 ];
 public $pageTitle = " Chapter  "; //page Title

 Public static function job_position_type() {
	$option_header = option_header::find_by_name('lms_chapter_POSITION_TYPE');
	$ol = new option_line();
	$option_lines = $ol->findBy_parentId($option_header->option_header_id);
	return $option_lines;
 }

 public static function find_by_transactionClass($class) {
	$sql = " SELECT * FROM ";
	$sql .= self::$table_name;
	$sql .= " WHERE type_class = '{$class}' AND status='active'";
	$result = self::find_by_sql($sql);
	return $result;
 }

}

//end of lms_chapter class
?>