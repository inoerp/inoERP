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
 * sys_document_sequence
 *
 */
class sys_document_sequence extends dbObject {

 public static $table_name = "sys_document_sequence";
 public static $primary_column = "sys_document_sequence_id";
 public static $key_column = 'document_type';
 public static $module = "sys";
 public static $system_info = [
  'name' => 'Document Sequence',
  'number' => '9101',
  'description' => 'Create & Mainten Document Sequence',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 1
 ];
 public static $entry_type_a = [
  'AUTO_SEQUENCE' => 'Auto Sequence',
  'MANUAL' => 'Manual',
  'BU_HEADER_ID' => 'Org/Header Id',
 ];
 public $field_a = [
  'sys_document_sequence_id',
  'bu_org_id',
  'entry_type',
  'pre_fix',
  'seq_separator',
  'next_number',
  'document_type',
  'start_date',
  'end_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'sys_document_sequence_id',
  'bu_org_id'
 ];
 public $requiredField = [
  'bu_org_id',
  'entry_type',
  'document_type',
 ];
 public $sys_document_sequence_id;
 public $bu_org_id;
 public $entry_type;
 public $pre_fix;
 public $seq_separator;
 public $next_number;
 public $document_type;
 public $start_date;
 public $end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Document Sequence  "; //page Title

 public static function xx_find_all_header_levels() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'HEADER' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

}

//end of sys_document_sequence class
?>