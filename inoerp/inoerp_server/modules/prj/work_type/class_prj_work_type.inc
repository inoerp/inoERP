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
 * prj_work_type
 * Contains all the prj_work_type information, such as - prj_work_type, prj_work_type_id, org_id,  type, etc.
 * 
 */
class prj_work_type extends dbObject {

 public static $table_name = "prj_work_type";
 public static $primary_column = "prj_work_type_id";
 public static $key_column = 'work_type';
 public static $module = "prj";
 public static $multi_select_template_path = 'modules/prj/expenditure_type/multi_action/prj_work_type_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Work Type',
  'number' => '6020',
  'description' => 'Project Work Type',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 17
 ];
 public static $tp_amount_type_a = [
  'REVENUE' => 'Revenue',
  'COST' => 'Actual Cost',
  'COST_PLUS' => 'Cost Plus Markup'
 ];
 public $field_a = [
  'prj_work_type_id',
  'work_type',
  'description',
  'billable_cb',
  'effective_from',
  'effective_to',
  'capitalizable_cb',
  'tp_amount_type',
  'training_cb',
  'shadow_resource_cb',
  'utilization_type',
  'utilization_percentage',
  'unassigned_cb',
  'non_worked_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'work_type',
  'description',
 ];
 public $checkbox = [
  'billable_cb',
  'effective_to',
  'capitalizable_cb',
  'training_cb',
  'shadow_resource_cb',
  'unassigned_cb',
  'non_worked_cb',
 ];
 public $requiredField = [
  "work_type",
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Work Type"; //page Title
 public $prj_work_type_id;
 public $work_type;
 public $description;
 public $billable_cb;
 public $effective_from;
 public $effective_to;
 public $capitalizable_cb;
 public $tp_amount_type;
 public $training_cb;
 public $shadow_resource_cb;
 public $utilization_type;
 public $utilization_percentage;
 public $unassigned_cb;
 public $non_worked_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

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

//end of prj_work_type class
?>