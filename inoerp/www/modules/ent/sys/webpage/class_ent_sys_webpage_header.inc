<?php

/**
 * inoERP
 *
 * @copyright   2017 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * ent_sys_webpage_header CLass
 * Contains all the ent_sys_webpage_header information, such as - document_type, so_number, ar_customer_id
 *
 */
class ent_sys_webpage_header extends dbObject {

 public static $table_name = "ent_sys_webpage_header";
 public static $dependent_classes = ['ent_sys_webpage_line'];
 public static $primary_column = "ent_sys_webpage_header_id";
 public static $key_column = 'service_type';
 public static $module = "hd";
 public static $system_info = [
		 'name' => 'Webpage',
		 'number' => '5107',
		 'description' => 'Create & Mainten Service Activity',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'dependent_class' => array('ent_sys_webpage_line'),
		 'primary_entity_cb' => '',
		 'module_name' => 'hd',
		 'weight' => 1,
		 'ent_cb' => 1
 ];
 public static $line_category_a = [
		 'ORDER' => 'Order',
		 'RETURN' => 'Return'
 ];
 public static $repair_mode_a = [
		 'WO' => 'Work Order',
		 'TASK' => 'Task',
		 'NO_TRACKING' => 'No Tracking',
 ];
 public $field_a = [
		 'ent_sys_webpage_header_id',
		 'page_type',
		 'parent_id',
		 'title',
		 'page_message',
		 'link_title',
		 'weightage',
		 'access_role',
		 'rev_number',
		 'show_in_fp_cb',
		 'comment_status',
		 'content_by',
		 'created_by',
		 'creation_date',
		 'last_update_by',
		 'last_update_date',
 ];
 public $initial_search = [
		 'activity_name',
		 'activity_description',
		 'line_category',
 ];
 public $requiredField = [
		 'service_type',
		 'primary_service_type'
 ];
 public $fields_inForm_notInDataBase = [
		 'action',
 ];
 public $search = [
		 '_show_update_path' => 1,
		 '_show_view_path' => 1
 ];
 public $pageTitle = " Webpage "; //page Title
 public $ent_sys_webpage_header_id;
 public $page_type;
 public $parent_id;
 public $title;
 public $page_message;
 public $link_title;
 public $weightage;
 public $access_role;
 public $rev_number;
 public $show_in_fp_cb;
 public $comment_status;
 public $content_by;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function primary_service_type() {
	$option_header = option_header::find_by_name('HD_PRI_SERVICE_TYPE');
	$ol = new option_line();
	$option_lines = $ol->findBy_parentId($option_header->option_header_id);
	return $option_lines;
 }

 Public static function billing_type() {
	$option_header = option_header::find_by_name('SYS_BILLING_TYPE');
	$ol = new option_line();
	$option_lines = $ol->findBy_parentId($option_header->option_header_id);
	return $option_lines;
 }

}

//end of ent_sys_webpage_header class
?>