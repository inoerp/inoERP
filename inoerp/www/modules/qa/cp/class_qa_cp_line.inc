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
 * qa_cp_line
 *
 */
class qa_cp_line extends dbObject {

 public static $table_name = "qa_cp_line";
 public static $primary_column = "qa_cp_line_id";
 public static $parent_primary_column = "qa_cp_header_id";
 public static $key_column = "qa_ce_header_id";
 public static $module = "qa";
 public $field_a = [
  'qa_cp_line_id',
  'qa_cp_header_id',
  'qa_ce_header_id',
  'description',
  'sequence',
  'prompt',
  'mandatory_cb',
  'enabled_cb',
  'readonly_cb',
  'displayed_cb',
  'information_cb',
  'dafault_value',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'qa_ce_header_id',
  'description',
 ];
 public $requiredField = [
  'qa_cp_header_id',
  'qa_ce_header_id',
  'sequence',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Collection Plan Line"; //page Title
 public $qa_cp_line_id;
 public $qa_cp_header_id;
 public $qa_ce_header_id;
 public $description;
 public $sequence;
 public $prompt;
 public $mandatory_cb;
 public $enabled_cb;
 public $readonly_cb;
 public $displayed_cb;
 public $information_cb;
 public $dafault_value;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_parent_id($qa_cp_header_id , $order_by_field ='', $order_by_seq='') {
  $sql = "  SELECT qcl.qa_cp_line_id , qcl.qa_cp_header_id , qcl.qa_ce_header_id,
qceh.element_name, qceh.sys_element_name, qceh.data_type, qceh.data_length, qceh.display_type, qceh.element_type,
qceh.element_label, qceh.option_header_id
FROM  qa_cp_line qcl,
qa_ce_header qceh
WHERE qceh.qa_ce_header_id = qcl.qa_ce_header_id
AND qcl.qa_cp_header_id = '{$qa_cp_header_id}' ";

 $result = self::find_by_sql($sql);
 
 return !empty($result) ? $result : false;
 
 }

}

//end of path class
?>
