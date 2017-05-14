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
 * prj_burden_expenditure
 * Contains all the prj_burden_expenditure information, such as - prj_burden_expenditure, prj_burden_expenditure_id, org_id,  type, etc.
 * 
 */
class prj_burden_expenditure extends dbObject {

 public static $table_name = "prj_burden_expenditure";
 public static $primary_column = "prj_burden_expenditure_id";
 public static $key_column = 'expenditure';
 public static $module = "prj";
//  data base variables as stored database column name
 public static $system_info = [
  'name' => 'Burden Expenditure',
  'number' => '6026',
  'description' => 'prj_burden_expenditure',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 17
 ];
 public $field_a = [
  'prj_burden_expenditure_id',
  'prj_expenditure_line_id',
  'prj_burden_cost_base_id',
  'prj_expenditure_type_header_id',
  'description',
  'prj_burden_list_header_id',
  'expenditure_date',
  'prj_project_header_id',
  'prj_project_line_id',
  'prj_burden_structure_header_id',
  'prj_burden_costcode_id',
  'multiplier',
  'burden_value',
  'burden_amount',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date'
 ];
//variables used for showing data
 public $initial_search = [
  'expenditure',
  'description',
  'prj_expenditure_line_id'
 ];
 public $requiredField = [
  "prj_expenditure_line_id",
  'final_amount'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Burdden Expenditure "; //page Title
 public $prj_burden_expenditure_id;
 public $prj_expenditure_line_id;
 public $prj_burden_cost_base_id;
 public $prj_expenditure_type_header_id;
 public $description;
 public $prj_burden_list_header_id;
 public $expenditure_date;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $prj_burden_structure_header_id;
 public $prj_burden_costcode_id;
 public $multiplier;
 public $burden_value;
 public $burden_amount;
 public $final_amount;
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

//end of prj_burden_expenditure class
?>