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
 * prj_burden_cost_base
 * Contains all the prj_burden_cost_base information, such as - prj_burden_cost_base, prj_burden_cost_base_id, org_id,  type, etc.
 * 
 */
class prj_burden_cost_base extends dbObject {

 public static $table_name = "prj_burden_cost_base";
 public static $primary_column = "prj_burden_cost_base_id";
 public static $key_column = 'cost_base';
 public static $module = "prj";
 public static $multi_select_template_path = 'modules/prj/burden_cost/multi_action/prj_burden_cost_template_ma.php';
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Expenditure Type',
  'number' => '6004',
  'description' => 'prj_burden_cost_base',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'inv',
  'weight' => 17
 ];
 public $field_a = [
  'prj_burden_cost_base_id',
  'cost_base',
  'description',
  'cost_base_type',
  'effective_from',
  'effective_to',
  'priority',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
//variables used for showing data
 public $initial_search = [
  'cost_base',
  'description',
 ];
 public $requiredField = [
  "cost_base",
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Burdden Cost Base"; //page Title
 public $prj_burden_cost_base_id;
 public $cost_base;
 public $description;
 public $cost_base_type;
 public $effective_from;
 public $effective_to;
 public $priority;
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

//end of prj_burden_cost_base class
?>