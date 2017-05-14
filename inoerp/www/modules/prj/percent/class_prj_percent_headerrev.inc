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
 * prj_percent_header
 * A sigle transaction document(invoice, etc) can be created against multiple purchase orders
 * Transaction header contains all the header level informations such as supplier site, document_type, currency, header amount,  paying entity
 * Transaction line contains invoices details
 *
 */
class prj_percent_headerrev extends dbObject {

 public static $table_name = "prj_percent_headerrev";
 public static $primary_column = "prj_percent_headerrev_id";
 public static $key_column = 'prj_project_header_id';
 public static $module = "prj"; //same as gl_journal_source
 public static $system_info = [
  'name' => 'Project Percent Revision',
  'number' => '6031',
  'description' => 'Create & Mainten Project Status Percent ',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('prj_percent_line'),
  'primary_entity_cb' => '',
  'module_name' => 'prj',
  'weight' => 3
 ];
 public $field_a = [
  'prj_percent_headerrev_id',
  'prj_percent_header_id',
  'prj_project_header_id',
  'percent',
  'description',
  'as_of_date',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'prj_project_header_id',
 ];
 public $requiredField = [
  'prj_project_header_id',
  'percent',
  'as_of_date',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project Completion Revision  "; //page Title
 public $prj_percent_headerrev_id;
 public $prj_percent_header_id;
 public $prj_project_header_id;
 public $percent;
 public $description;
 public $as_of_date;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_projectHeaderId($project_header_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE prj_project_header_id= '{$project_header_id}'  ORDER BY prj_percent_headerrev_id DESC ";
// echo $sql;
  $result = self::find_by_sql($sql);

  return !empty($result) ? ($result) : [new prj_percent_headerrev()];
 }

}

//end of prj_percent_header class
?>