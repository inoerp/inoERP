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
 * prj_invoice_line
 *
 */
class prj_invoice_line extends dbObject {

 public static $table_name = "prj_invoice_line";
 public static $primary_column = "prj_invoice_line_id";
 public static $parent_primary_column = "prj_invoice_header_id";
 public static $key_column = "prj_invoice_type_header_id";
 public static $module = "prj";
 public static $gl_journal_category = "prj_invoice";
 public static $status_a = [
  'ENTERED' => 'Entered',
  'DISTRIBUTED' => 'Distributed',
 ];
 public $field_a = [
  'prj_invoice_line_id',
  'prj_invoice_header_id',
  'prj_project_line_id',
  'revenue_category',
  'expenditure_category',
  'revenue_source',
  'line_number',
  'description',
  'amount',
  'release_date',
  'rejection_reason',
  'transfer_date',
  'document_number',
  'reference_type',
  'reference_key_name',
  'reference_key_value',
  'gl_journal_header_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'line_number',
  'description',
 ];
 public $requiredField = [
  'prj_invoice_header_id',
  'prj_project_line_id',
  'revenue_category',
  'invoice_source',
  'line_number',
 ];
 public $fields_inForm_notInDataBase = [
  'project_number',
  "task_number",
  'action'
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = "Invoice Lines"; //page Title
 public $prj_invoice_line_id;
 public $prj_invoice_header_id;
 public $prj_project_line_id;
 public $revenue_category;
 public $expenditure_category;
 public $revenue_source;
 public $line_number;
 public $description;
 public $amount;
 public $release_date;
 public $rejection_reason;
 public $transfer_date;
 public $document_number;
 public $reference_type;
 public $reference_key_name;
 public $reference_key_value;
 public $gl_journal_header_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $project_number;
 public $employee_name;
 public $task_number;
 public $status_f;
 public $action;

 public static function find_totalinvoice_projectHeaderId($project_header_id) {
  $sql = " SELECT SUM(amount) as invoice_amount
FROM prj_invoice_line prl,
prj_invoice_header prh
WHERE prh.prj_project_header_id = '{$project_header_id}'
AND prh.prj_invoice_header_id = prl.prj_invoice_header_id
";

  $result = self::find_by_sql($sql);

  return !empty($result) ? $result[0]->invoice_amount : false;
 }

 public static function find_highest_line_num($prj_invoice_header_id) {
  $sql = " SELECT MAX(prl.line_number) as max_line_num 
FROM  prj_invoice_line prl,
prj_invoice_header prh
WHERE prh.prj_invoice_header_id = prl.prj_invoice_header_id
AND prh.prj_invoice_header_id  = '{$prj_invoice_header_id}' ";

  $result = self::find_by_sql($sql);
  return !empty($result) ? $result[0]->max_line_num : 0;
 }
}

//end of path class
?>
