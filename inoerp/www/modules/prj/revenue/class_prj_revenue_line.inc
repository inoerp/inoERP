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
 * prj_revenue_line
 *
 */
class prj_revenue_line extends dbObject {

 public static $table_name = "prj_revenue_line";
 public static $primary_column = "prj_revenue_line_id";
 public static $parent_primary_column = "prj_revenue_header_id";
 public static $key_column = "prj_revenue_type_header_id";
 public static $module = "prj";
 public static $gl_journal_category = "prj_revenue";
 public static $status_a = [
    'ENTERED' => 'Entered',
    'DISTRIBUTED' => 'Distributed',
 ];
 public $field_a = [
    'prj_revenue_line_id',
    'prj_revenue_header_id',
    'prj_project_line_id',
    'revenue_category',
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
    'gl_journal_interface_cb',
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
    'prj_revenue_header_id',
    'amount',
    'revenue_category',
    'revenue_source',
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
 public $pageTitle = "Revenue Lines"; //page Title
 public $prj_revenue_line_id;
 public $prj_revenue_header_id;
 public $prj_project_line_id;
 public $revenue_category;
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
 public $gl_journal_interface_cb;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $project_number;
 public $employee_name;
 public $task_number;
 public $status_f;
 public $action;

 public function _before_save() {
  if (empty($this->prj_project_line_id) || empty($this->status)) {
   $this->status = 'ENTERED';
  }
  if (empty($this->line_amount)) {
   $this->line_amount = empty($this->rate) ? $this->quantity : $this->quantity * $this->rate;
  }
  if ($this->action == 'create_accounting') {
//   pa($this);
   $this->_insert_gl_interface();
   return 10;
  }
 }

 public $doc_currency;
 public $exchange_type;
 public $exchange_rate;

 public static function find_totalRevenue_projectHeaderId($project_header_id) {
  $sql = " SELECT SUM(amount) as revenue_amount
FROM prj_revenue_line prl,
prj_revenue_header prh
WHERE prh.prj_project_header_id = '{$project_header_id}'
AND prh.prj_revenue_header_id = prl.prj_revenue_header_id
";

  global $db;
  $value_a = ['option_line_code' => $option_line_code];
  $result = $db->findBySql($sql, $value_a);

  return !empty($result) ? $result[0]->revenue_amount : false;
 }

 public static function find_highest_line_num($prj_revenue_header_id) {
  $sql = " SELECT MAX(prl.line_number) as max_line_num 
FROM  prj_revenue_line prl,
prj_revenue_header prh
WHERE prh.prj_revenue_header_id = prl.prj_revenue_header_id
AND prh.prj_revenue_header_id  = :prj_revenue_header_id ";

  global $db;
  $value_a = ['prj_revenue_header_id' => $prj_revenue_header_id];
  $result = $db->findBySql($sql, $value_a);

  return !empty($result) ? $result[0]->max_line_num : 0;
 }


}

//end of path class
?>
