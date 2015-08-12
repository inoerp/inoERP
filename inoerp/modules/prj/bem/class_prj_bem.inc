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
 * prj_bem
 * Contains all the prj_bem information, such as - prj_bem, prj_bem_id, org_id,  type, etc.
 * 
 */
class prj_bem extends dbObject {

 public static $table_name = "prj_bem";
 public static $primary_column = "prj_bem_id";
 public static $key_column = 'bem';
 public static $module = "prj";
// public static $multi_select_template_path = 'modules/prj/bem/multi_action/prj_bem_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'prj_bem',
  'number' => '6002',
  'description' => 'Budget Entry Method',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 17
 ];
 public static $budget_entry_level_a = [
  'PROJECT' => 'Project',
  'TOP_TASK' => 'Top Task',
  'LOWEST_TASK' => 'Lowest Task',
  'TOP_LOWEST_TASK' => 'Top & Lowest Task',
 ];
 public static $time_phased_by_a = [
  'NONE' => 'None',
  'GL_PERIOD' => 'GL Period',
  'DATE_RANGE' => 'Date Range',
 ];
 public $field_a = [
  'prj_bem_id',
  'bem',
  'description',
  'budget_entry_level',
  'effective_from',
  'effective_to',
  'quantity_cost_cb',
  'raw_cost_cb',
  'burdened_cost_cb',
  'revenue_cb',
  'quantity_revenue_cb',
  'time_phased_by',
  'categorized_by_resource_cb',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'bem',
  'description'
 ];
 public $checkbox = [
  'quantity_cost_cb',
  'raw_cost_cb',
  'burdened_cost_cb',
  'revenue_cb',
  'quantity_revenue_cb',
  'categorized_by_resource_cb',
 ];
 public $requiredField = [
  'bem',
  'budget_entry_level',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Budget Entry Method"; //page Title
 public $prj_bem_id;
 public $bem;
 public $description;
 public $budget_entry_level;
 public $effective_from;
 public $effective_to;
 public $quantity_cost_cb;
 public $raw_cost_cb;
 public $burdened_cost_cb;
 public $revenue_cb;
 public $quantity_revenue_cb;
 public $time_phased_by;
 public $categorized_by_resource_cb;
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

//end of prj_bem class
?>