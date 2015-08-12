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
 * prj_role
 * Contains all the prj_role information, such as - prj_role, prj_role_id, org_id,  type, etc.
 * 
 */
class prj_role extends dbObject {

 public static $table_name = "prj_role";
 public static $primary_column = "prj_role_id";
 public static $key_column = 'role_name';
 public static $module = "prj";
 public static $multi_select_template_path = 'modules/prj/expenditure_type/multi_action/prj_role_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Role',
  'number' => '6018',
  'description' => 'Project Role',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 17
 ];
 public $field_a = [
  'prj_role_id',
  'role_name',
  'description',
  'user_role',
  'effective_from',
  'effective_to',
  'labor_cost_cb',
  'contract_member_cb',
  'project_member_cb',
  'task_member_cb',
  'scheduling_cb',
  'min_job_level',
  'max_job_level',
  'hr_job_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'role_name',
  'description',
 ];
 public $checkbox = [
  'labor_cost_cb',
  'contract_member_cb',
  'project_member_cb',
  'task_member_cb',
  'scheduling_cb',
 ];
 public $requiredField = [
  "role_name",
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project Role "; //page Title
 public static $header_tabs = [
  'basic_info' => 'Basic Info',
  'notes' => 'Notes',
  'attachments' => 'Attachments',
 ];
 public static $basic_info = [
  'prj_role_id' => 'l_text_field_dr_withSearch',
  'role_name' => 'l_text_field_d',
  'description' => 'l_text_field_d',
  'user_role' => 'l_text_field_d',
  'min_job_level' => 'l_text_field_d',
  'max_job_level' => 'l_text_field_d',
  'hr_job_id' => array('l_select_field_from_object', 'hr_job::find_all()', 'hr_job_id', 'hr_job_id', 'job_name', '$$class->hr_job_id'),
  'effective_from' => array('l_date_fieldAnyDay', 'effective_from', '$$class->effective_from'),
  'effective_to' => array('l_date_fieldAnyDay', 'effective_from', '$$class->effective_from'),
 ];
 public static $line_tabs = [
  'control_options' => 'Control Options',
 ];
 public static $control_options = [
  'labor_cost_cb' => 'l_checkBox_field_d',
  'contract_member_cb' => 'l_checkBox_field_d',
  'project_member_cb' => 'l_checkBox_field_d',
  'task_member_cb' => 'l_checkBox_field_d',
  'scheduling_cb' => 'l_checkBox_field_d',
 ];
 public $prj_role_id;
 public $role_name;
 public $description;
 public $user_role;
 public $effective_from;
 public $effective_to;
 public $labor_cost_cb;
 public $contract_member_cb;
 public $project_member_cb;
 public $task_member_cb;
 public $scheduling_cb;
 public $min_job_level;
 public $max_job_level;
 public $hr_job_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 Public static function prj_work_utilization_type() {
  $option_header = option_header::find_by_exact_name('PRJ_WORK_UTILIZATION_TYPE');
  $ol = option_line::find_by_option_id($option_header->option_header_id);
  return $ol;
 }

 public function multi_select_hidden_fields() {
  $multi_select_hidden = [
   'mode',
   'show_block'
  ];

  return $multi_select_hidden;
 }

}

//end of prj_role class
?>