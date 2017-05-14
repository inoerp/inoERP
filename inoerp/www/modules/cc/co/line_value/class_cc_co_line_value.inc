<?php

class cc_co_line_value extends dbObject {

 public static $table_name = "cc_co_line_value";
 public static $primary_column = "cc_co_line_value_id";
 public static $parent_primary_column = "cc_co_line_id";
 public static $key_column = 'cc_co_line_id';
 public static $module = "cc";
 public $field_a = [
  'cc_co_line_value_id',
  'cc_co_line_id',
  'cc_co_template_line_id',
  'field_value',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  "cc_co_header_id"
 ];
 public $requiredField = [
  'cc_co_line_id',
  'cc_co_template_line_id',
  'field_value',
 ];
 public $fields_inFormr_notinDataBase = [
  "field_name",
  'item_number',
 ];
 public $cc_co_line_value_id;
 public $cc_co_line_id;
 public $cc_co_template_line_id;
 public $field_value;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;

 public static function find_by_lineId_templateLineId($cc_co_line_id, $cc_co_template_line_id) {
  $sql = " SELECT ccl.cc_co_line_id, ccl.cc_co_header_id, ccl.item_id_m, ccl.item_description,  
    ccl.new_revision, cclv.cc_co_template_line_id, cclv.field_value, cclv.cc_co_line_value_id

FROM 
cc_co_line ccl
LEFT JOIN cc_co_line_value cclv ON cclv.cc_co_line_id = ccl.cc_co_line_id 

WHERE cclv.cc_co_template_line_id = '{$cc_co_template_line_id}'
 AND cclv.cc_co_line_id = '{$cc_co_line_id}'
";
 
   switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $result = self::find_by_sql($sql);
// echo $sql;
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of inv_transaction class
?>