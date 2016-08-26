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
 * sys_catalog_value
 *
 */
class sys_catalog_value extends dbObject {

 public static $table_name = "sys_catalog_value";
 public static $primary_column = "sys_catalog_value_id";
 public static $parent_primary_column = "sys_catalog_line_id";
 public static $key_column = "line_value";
 public static $module = "sys";
 public $field_a = [
  'sys_catalog_value_id',
  'sys_catalog_line_id',
  'sys_catalog_header_id',
  'line_value',
  'reference_table',
  'reference_id',
 ];
 public $initial_search = [
  'line_value'
 ];
 public $requiredField = [
  'sys_catalog_line_id',
  'line_value',
  'reference_table',
  'reference_id',
 ];
 public $fields_inForm_notInDataBase = [
  'sys_catalog_header_id',
  'line_name',
  'description',
 ];
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Catalog Values"; //page Title
 public $sys_catalog_value_id;
 public $sys_catalog_line_id;
 public $sys_catalog_header_id;
 public $line_value;
 public $reference_table;
 public $reference_id;
 public $msg;
 public $line_name;
 public $description;

 public static function find_by_referenceTable_and_referenceId_headerId($reference_table, $reference_id, $sys_catalog_header_id) {
  $sql = "SELECT scv.sys_catalog_value_id , scv.sys_catalog_line_id, 
               scv.line_value,  scv.reference_table,  scv.reference_id,
							 sci.line_name,  sci.description, sch.catalog, sch.description as catalog_description
       FROM 
       sys_catalog_value scv , sys_catalog_line sci, sys_catalog_header sch
       WHERE scv.reference_table = '{$reference_table}'
       AND scv.reference_id = '{$reference_id}'
        AND scv.sys_catalog_header_id = '{$sys_catalog_header_id}'
       AND scv.sys_catalog_line_id = sci.sys_catalog_line_id
        AND scv.sys_catalog_header_id = sch.sys_catalog_header_id ";
  $result = self::find_by_sql($sql);
//  echo $sql;
  return !empty($result) ? $result : false;
 }

 public function findBy_referenceTable_and_referenceId_headerId($sys_catalog_header_id) {
  $sql = "SELECT scv.sys_catalog_value_id , scv.sys_catalog_line_id, 
               scv.line_value,  scv.reference_table,  scv.reference_id,
							 sci.line_name,  sci.description, sch.catalog, sch.description as catalog_description
       FROM 
       sys_catalog_value scv , sys_catalog_line sci, sys_catalog_header sch
       WHERE scv.reference_table = :reference_table
       AND scv.reference_id = :reference_id
        AND scv.sys_catalog_header_id = :sys_catalog_header_id
       AND scv.sys_catalog_line_id = sci.sys_catalog_line_id
        AND scv.sys_catalog_header_id = sch.sys_catalog_header_id ";
  $value_a = ['reference_table' => $this->reference_table, 'reference_id' => $this->reference_id, 'sys_catalog_header_id' => $sys_catalog_header_id];

  $result = $this->findBySql($sql, $value_a);
//  echo $sql;
  return !empty($result) ? $result : false;
 }

 public function findValues_forDocument() {
  $ret_result = [];
  $dist_sql = " 
       SELECT DISTINCT(sys_catalog_header_id)
       FROM sys_catalog_value 
       WHERE reference_table = :reference_table
       AND reference_id = :reference_id ";
  $value_a = ['reference_table' => $this->reference_table, 'reference_id' => $this->reference_id];
  $sys_catalog_header_ids = $this->findBySql($dist_sql, $value_a);
  if ($sys_catalog_header_ids) {
   foreach ($sys_catalog_header_ids as $k => $v) {
    $data = $this->findBy_referenceTable_and_referenceId_headerId($v->sys_catalog_header_id);
    if ($data) {
     array_push($ret_result, $data);
    }
   }
  }

  return $ret_result;
 }

 public function catalog_stmt() {
  $all_data = $this->findValues_forDocument();
  $stmt = '';
  foreach ($all_data as $cat_val_a) {
   $stmt .= '<div class="panel panel-ino-light-grey catalog-list-element '.$cat_val_a[0]->catalog.' ">
       <div class="panel-heading"><h3 class="panel-title">' . $cat_val_a[0]->catalog . '</h3></div>
       <div class="panel-body">
        <ul class="column header_field catalog-ul">';
   foreach ($cat_val_a as $k => $obj) {
    $stmt .='<li><label>' . $obj->line_name . '</label> ' . $obj->line_value . '</li>';
   }
   $stmt .='</ul>
       </div>
      </div>';
  }
  return $stmt;
 }

 public static function find_by_referenceTable_referenceId_lineId($reference_table, $reference_id, $sys_catalog_line_id) {
  $sql = "SELECT scv.sys_catalog_value_id , scv.sys_catalog_line_id, 
               scv.line_value,  scv.reference_table,  scv.reference_id,
							 sci.line_name,  sci.description
       FROM 
       sys_catalog_value scv , sys_catalog_line sci
       WHERE scv.reference_table = '{$reference_table}'
       AND scv.reference_id = '{$reference_id}'
        AND scv.sys_catalog_line_id = '{$sys_catalog_line_id}'
       AND scv.sys_catalog_line_id = sci.sys_catalog_line_id ";
        $sql = ino_perPageSql_i($sql, 1);
  $result = self::find_by_sql($sql);
//  echo $sql;
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of path class
?>
