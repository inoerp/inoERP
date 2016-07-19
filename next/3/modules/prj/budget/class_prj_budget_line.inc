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
 * prj_budget_line
 *
 */
class prj_budget_line extends dbObject {

 public static $table_name = "prj_budget_line";
 public static $primary_column = "prj_budget_line_id";
 public static $parent_primary_column = "prj_budget_header_id";
 public static $key_column = "prj_project_line_id";
 public static $module = "prj";
 public $field_a = [
  'prj_budget_line_id',
  'prj_budget_header_id',
//  'prj_project_header_id',
  'description',
  'prj_project_line_id',
  'prj_resource_line_id',
  'uom_id',
  'quantity',
  'raw_cost',
  'burden_cost',
  'revenue_quantity',
  'revenue_amount',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'resource_type',
 ];
 public $requiredField = [
  'prj_budget_header_id',
  'prj_project_line_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $fields_inForm_notInDataBase = [
  "employee_name",
  'task_number'
 ];
 public $pageTitle = " Budget Line"; //page Title
 public $prj_budget_line_id;
 public $prj_budget_header_id;
 public $prj_project_header_id;
 public $description;
 public $prj_project_line_id;
 public $prj_resource_line_id;
 public $uom_id;
 public $quantity;
 public $raw_cost;
 public $burden_cost;
 public $revenue_quantity;
 public $revenue_amount;
 public $average_rate;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $employee_name;
 public $task_number;

 Public static function validation_types() {
  $header = option_line::find_by_keyColumn('SYS_VALIDATION_TYPE');
  $option_line = new option_line();
  $lines = $option_line->findBy_parentId($header->option_line_id);
  return $lines;
 }

 public static function find_budget_by_ProjectHeaderIdBudgetType($prj_project_header_id, $budget_type) {
  $sql = " SELECT SUM(pbl.revenue_amount) as revenue_amount, SUM(pbl.quantity) as quantity, SUM(pbl.raw_cost) as raw_cost,
   SUM(pbl.burden_cost) as burden_cost, SUM(pbl.revenue_quantity) as revenue_quantity, pbh.prj_project_header_id
FROM prj_budget_line pbl,
prj_budget_header pbh
WHERE pbh.prj_project_header_id = '{$prj_project_header_id}'
AND pbh.budget_type = '{$budget_type}'
 AND pbh.baselined_cb = 1
AND pbh.prj_budget_header_id = pbl.prj_budget_header_id
GROUP BY pbh.prj_project_header_id
";
//echo $sql;
  $result = self::find_by_sql($sql);

  return !empty($result) ? array_pop($result) : false;
 }
 
  public static function find_revBudgetAmount_byProjectHeaderId($prj_project_header_id) {
  $result = self::find_budget_by_ProjectHeaderIdBudgetType($prj_project_header_id,'APPR_REV');
  return !empty($result) ? $result->revenue_amount : false;
 }

}

//end of path class
?>
