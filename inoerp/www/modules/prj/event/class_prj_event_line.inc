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
 * prj_event_line
 *
 */
class prj_event_line extends dbObject {

 public static $table_name = "prj_event_line";
 public static $primary_column = "prj_event_line_id";
 public static $parent_primary_column = "prj_event_header_id";
 public static $key_column = "event_number";
 public static $module = "prj";
 public $field_a = [
  'prj_event_line_id',
  'prj_event_header_id',
  'event_type_id',
  'event_date',
  'org_id',
  'event_number',
  'prj_project_line_id',
  'description',
  'currency',
  'billing_amount',
  'revenue_amount',
  'billed_cb',
  'revenue_distributed_cb',
  'reference_key_name',
  'reference_key_value',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'resource_type',
 ];
 public $requiredField = [
  'prj_event_header_id',
  'event_type_id',
  'event_number',
  'prj_project_line_id',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $fields_inForm_notInDataBase = [
  'task_number'
 ];
 public $pageTitle = " Event Line"; //page Title
 public $prj_event_line_id;
 public $prj_event_header_id;
 public $event_type_id;
 public $event_date;
 public $org_id;
 public $event_number;
 public $prj_project_line_id;
 public $description;
 public $currency;
 public $billing_amount;
 public $revenue_amount;
 public $billed_cb;
 public $revenue_distributed_cb;
 public $reference_key_name;
 public $reference_key_value;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $task_number;

 Public static function validation_types() {
  $header = option_line::find_by_keyColumn('SYS_VALIDATION_TYPE');
  $option_line = new option_line();
  $lines = $option_line->findBy_parentId($header->option_line_id);
  return $lines;
 }

 public static function find_allNonInvoicedLines_byProjectHeaderId($prj_project_header_id) {
  $sql = " SELECT pel.prj_event_line_id, pel.prj_event_header_id, pel.event_type_id, pel.event_date,
pel.org_id, pel.event_number,  pel.prj_project_line_id,  pel.description, pel.currency,
pel.billing_amount, pel.revenue_amount, 
peh.event_name, peh.description, peh.prj_project_header_id, peh.billing_amount,
peh.revenue_amount, peh.event_number 

FROM prj_event_line pel,
prj_event_header peh

WHERE peh.prj_event_header_id = pel.prj_event_header_id
AND peh.prj_project_header_id = '{$prj_project_header_id}'
 AND pel.billed_cb = NULL
";
$sql = ino_perPageSql_i($sql, 1);

  $result = self::find_by_sql($sql);

  return !empty($result) ? array_pop($result) : false;
 }

  public static function find_allNonRevenueLines_byProjectHeaderId($prj_project_header_id) {
  $sql = " SELECT pel.prj_event_line_id, pel.prj_event_header_id, pel.event_type_id, pel.event_date,
pel.org_id, pel.event_number,  pel.prj_project_line_id,  pel.description, pel.currency,
pel.billing_amount, pel.revenue_amount, 
peh.event_name, peh.description, peh.prj_project_header_id, peh.billing_amount,
peh.revenue_amount, peh.event_number 

FROM prj_event_line pel,
prj_event_header peh

WHERE peh.prj_event_header_id = pel.prj_event_header_id
AND peh.prj_project_header_id = '{$prj_project_header_id}'
 AND pel.revenue_distributed_cb = NULL
";
$sql = ino_perPageSql_i($sql, 1);

  $result = self::find_by_sql($sql);

  return !empty($result) ? array_pop($result) : false;
 }
}

//end of path class
?>
