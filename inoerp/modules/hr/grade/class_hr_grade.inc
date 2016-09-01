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
 * hr_grade
 * Contains all the hr_grade information, such as - hr_grade, hr_grade_id, org_id,  type, etc.
 * 
 */
class hr_grade extends dbObject {

 public static $table_name = "hr_grade";
 public static $primary_column = "hr_grade_id";
 public static $key_column = 'grade';
 public static $module = "hr";
 public static $multi_select_template_path = 'modules/hr/grade/multi_action/hr_grade_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'HR Grade',
  'number' => '3127',
  'description' => 'hr_grade',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 17
 ];
 public $field_a = [
  'hr_grade_id',
  'grade',
  'hr_element_entry_tpl_header_id',
  'description',
  'rank',
  'inactive_date',
  'alt_name',
  'alt_description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'grade',
  'description',
 ];
 public $requiredField = [
  "grade",
  'hr_element_entry_tpl_header_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "HR Grade"; //page Title
 public $hr_grade_id;
 public $grade;
 public $hr_element_entry_tpl_header_id;
 public $description;
 public $rank;
 public $inactive_date;
 public $alt_name;
 public $alt_description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of hr_grade class
?>