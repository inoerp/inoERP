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
 * prj_agreement_line
 *
 */
class prj_agreement_line extends dbObject {

 public static $table_name = "prj_agreement_line";
 public static $primary_column = "prj_agreement_line_id";
 public static $parent_primary_column = "prj_agreement_header_id";
 public static $key_column = "prj_project_header_id";
 public static $module = "prj";
 public $field_a = [
  'prj_agreement_line_id',
  'prj_agreement_header_id',
  'prj_project_header_id',
  'prj_project_line_id',
  'allocation_date',
  'allocation_amount',
  'classification',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'description',
 ];
 public $requiredField = [
  'prj_agreement_header_id',
  'prj_project_header_id'
 ];
 
  public $fields_inForm_notInDataBase = [
  "project_number",
  "task_number",
 ];
  
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Project Agreements"; //page Title
 public $prj_agreement_line_id;
 public $prj_agreement_header_id;
 public $prj_project_header_id;
 public $prj_project_line_id;
 public $allocation_date;
 public $allocation_amount;
 public $classification;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $project_number;
 public $task_number;


}

//end of path class
?>
