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
 * prj_expenditure_line
 *
 */
class prj_expenditure_line extends dbObject {

 public static $table_name = "prj_expenditure_line";
 public static $primary_column = "prj_expenditure_line_id";
 public static $parent_primary_column = "prj_expenditure_header_id";
 public static $key_column = "prj_exepnditure_type_header_id";
 public static $module = "prj";
 public $field_a = [
  'prj_expenditure_line_id',
  'prj_expenditure_header_id',
  'org_id',
  'hr_employee_id',
  'description',
  'job_id',
  'expenditure_date',
  'prj_project_header_id',
  'prj_project_line_id',
  'prj_nlr_header_id',
  'prj_exepnditure_type_header_id',
  'uom_id',
  'quantity',
  'rate',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'description',
 ];
 public $requiredField = [
  'prj_expenditure_header_id',
  'prj_exepnditure_type_header_id',
  'quantity',
 ];
 public $fields_inForm_notInDataBase = [
  "employee_name",
  'project_number',
  "task_number",
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Expenditure Lines"; //page Title
 public $prj_expenditure_line_id;
 public $prj_expenditure_header_id;
 public $org_id;
 public $hr_employee_id;
 public $description;
 public $job_id;
 public $expenditure_date;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $prj_nlr_header_id;
 public $prj_exepnditure_type_header_id;
 public $uom_id;
 public $quantity;
 public $rate;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $project_number;
 public $employee_name;
 public $task_number;
 

}

//end of path class
?>
