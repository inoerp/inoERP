<?php

/**
 * inoERP - Version 0.1.1
 *
 * @copyright 2014 Nishit R. Das
 * @license   https://www.mozilla.org/MPL/2.0/
 * @link       http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 */

/**
 * coa_combination
 * chart of account combinations defines valid accounting combinations available for transactions
 * Contains all the coa_combination information, such as - coa_id, coa_structure_id , all fields
 * 
 */
class coa_combination extends dbObject {

 public static $table_name = "coa_combination";
 public static $dependent_classes = ['coa'];
 public static $primary_column = "coa_combination_id";
 public static $key_column = "combination";
 public static $module = "gl";
 public static $system_info = [
  'name' => 'Combination',
  'number' => '1104',
  'description' => 'Chart Of Account Combinations',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'gl',
  'weight' => 4
 ];
 public $field_a = [
  'coa_combination_id',
  'coa_id',
  'field1',
  'field2',
  'field3',
  'field4',
  'field5',
  'field6',
  'field7',
  'field8',
  'combination',
  'description',
  'ac_type',
  'ef_id',
  'status',
  'rev_enabled_cb',
  'rev_number',
  'effective_start_date',
  'effective_end_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'ac_type',
  'field1',
  'combination',
 ];
 public $checkbox = [
  'rev_enabled_cb',
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
  'coa_id'
 ];
 public $requiredField = [
  'coa_id',
  'field1',
  'field2',
  'field3',
  'field4',
  'ac_type'
 ];
 public $pageTitle = " GL COA Combinatioins "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $coa_combination_id;
 public $coa_id;
 public $coa_structure_id;
 public $field1;
 public $field2;
 public $field3;
 public $field4;
 public $field5;
 public $field6;
 public $field7;
 public $field8;
 public $combination;
 public $ac_type;
 public $description;
 public $ef_id;
 public $status;
 public $rev_enabled_cb;
 public $rev_number;
 public $effective_start_date;
 public $effective_end_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $prg_update_description_parameters = [
//  'Depreciation Id' => 'search_depreciation_id',
//  'Asset Book' => 'search_asset_book',
//  'Period' => 'search_depreciation_period'
 ];
 public $prg_update_description_details = [
  'name' => 'Update Account Combination Description',
  'description' => 'Run update Description program',
 ];
 public $prg_all_combinations_details = [
  'name' => 'All Account Combinations',
  'description' => 'All Account Combinations',
 ];

 public static function find_all_from_coa($coa_id) {
  $sql = " SELECT * FROM " . self::$table_name;
  $sql .= " WHERE coa_id='{$coa_id}'";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_coa_combination_by_coa_id($coa_id) {
  $sql = "SELECT * FROM "
   . self::$table_name
   . " where coa_id={$coa_id}";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_coa_combination_by_coa_combination($coa_combination) {
  global $db;
  $sql = " SELECT combination FROM "
   . self::$table_name
   . " where combination LIKE '%{$coa_combination}%' ";

  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(30);
    break;

   default:
    $sql .= ino_perPageSql(30);
    break;
  }

  $result = $db->find_by_sql($sql);
  $data = array();
  foreach ($result as $obj) {
   $data[] = array(
    'label' => $obj->combination,
    'value' => $obj->combination
   );
  }
  return $data;
 }

 public function findBy_coaId_combination($limit = 30) {
  global $dbc;
  $sql = " SELECT * FROM "
   . self::$table_name
   . " where coa_id = :coa_id AND combination LIKE :combination ";

  if (!empty($this->ac_type)) {
   $ac_type = trim($this->ac_type);
   if (strpos($ac_type, ',') !== false) {
    $text_a = explode(',', $ac_type);
    foreach ($text_a as $k => $v) {
     $text_a[$k] = $dbc->connection->quote($v);
    }
    $text1 = join(',', $text_a);
    $sql .= " AND ac_type IN ( {$text1}  ) ";
   } else {
    $sql .= " AND ac_type = '{$ac_type}'  ";
   }
  }

  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql($limit);
    break;

   default:
    $sql .= ino_perPageSql($limit);
    break;
  }


  $combination = '%' . $this->combination . '%';
  $value_a = [ 'coa_id' => $this->coa_id, 'combination' => $combination];
  $result = $this->findBySql($sql, $value_a);

  return !(empty($result)) ? $result : false;
 }

 public static function find_by_coaId_description($coa_id, $description, $ac_type = '', $limit = 30) {
  global $dbc;
  $sql = " SELECT * FROM "
   . self::$table_name
   . " where coa_id = '{$coa_id}'  ";
  $sql .= " AND description LIKE " . "'%" . $description . "%'";

  if (!empty($ac_type)) {
   $ac_type = trim($ac_type);
   if (strpos($ac_type, ',') !== false) {
    $text_a = explode(',', $ac_type);
    foreach ($text_a as $k => $v) {
     $text_a[$k] = $dbc->connection->quote($v);
    }
    $text1 = join(',', $text_a);
    $sql .= " AND ac_type IN ( {$text1} ) ";
   } else {
    $sql .= " AND ac_type = '{$ac_type}'  ";
   }
  }

  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql($limit);
    break;

   default:
    $sql .= ino_perPageSql($limit);
    break;
  }


//  echo $sql;
  $result = self::find_by_sql($sql);

  return !(empty($result)) ? $result : false;
 }

 public function findBy_exactCombination($combination) {
  global $db;
  $sql = " SELECT * FROM "
   . self::$table_name
   . " where  combination = :combination ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $param_a = ['combination'];
  $value_a = ['combination' => $combination];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !(empty($result)) ? array_pop($result) : false;
 }

 public static function find_by_exactCombination($combination) {
  $sql = " SELECT * FROM "
   . self::$table_name
   . " where  combination = '{$combination}' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $result = self::find_by_sql($sql);
  return !(empty($result)) ? array_pop($result) : false;
 }

 public function searchBy_coaId_combination() {
  $result = $this->findBy_coaId_combination();
  $data = array();
  if (!empty($result)) {
   foreach ($result as $row) {
    $desc = $row->combination . ' | ' . $row->description;
    $data[] = array(
     'label' => $desc,
     'value' => $row->combination,
     'coa_combination_id' => $row->coa_combination_id
    );
   }
  }
  return $data;
 }

 public function searchBy_coaId_description() {
  $result = self::find_by_coaId_description(1, $this->description, $this->ac_type);
  $data = array();
  if (!empty($result)) {
   foreach ($result as $row) {
    $desc = $row->combination . ' | ' . $row->description;
    $data[] = array(
     'label' => $desc,
     'value' => $row->combination,
     'coa_combination_id' => $row->coa_combination_id
    );
   }
  }
  return $data;
 }

 public function findIdBy_combination_coaId() {
  $result = $this->findBy_coaId_combination(1);
  return !(empty($result)) ? $result[0]->coa_combination_id : false;
 }

 public static function validate_coa_combination($coa_id, $coa_combination) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where coa_id='{$coa_id}' " .
   " AND combination='{$coa_combination}' ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }

  $result_set = $db->find_by_sql($sql);
  return !(empty($result_set)) ? true : false;
 }

 public function prg_update_description($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting description update program';

  if (!empty($parameters['coa_combination_id'][0])) {
   $coa_combination_id = $parameters['coa_combination_id'][0];
   $this->message .= '<br> Entered coa_combination_id  is : ' . $coa_combination_id;
  } else {
   $this->message .= '<br> No coa_combination_id provide. Updating all account code combination description ';
  }


  if (!empty($coa_combination_id)) {
   $cc = new coa_combination();
   $cc->coa_combination_id = $coa_combination_id;
//   $cc->$cc->description = $ret_a['desc'];
   $ret_a = self::find_description_from_ccId($coa_combination_id);
   $cc->description = $ret_a['desc'];
   $cc->ac_type = $ret_a['ac_type'];
   $cc->save();
  } else {
   $cc_all = coa_combination::find_all();
   foreach ($cc_all as $record) {
    $cc = new coa_combination();
    $cc->coa_combination_id = $record->coa_combination_id;
    $ret_a = self::find_description_from_ccId($cc->coa_combination_id);
    $cc->description = $ret_a['desc'];
    $cc->ac_type = $ret_a['ac_type'];
    echo '<br> des ' . $cc->description;
    $cc->save();
   }
  }
  return $this->message;
 }

 public function prg_all_combinations($seralized_parameters) {
  return coa_combination::find_all();
 }

 public static function coa_combination_description() {

  $sql = " 
  SELECT segment1.code, segment2.code, segment3.code, segment4.code,  segment5.code, segment6.code, 
  segment1.description, segment2.description,
  segment3.description, segment4.description, segment5.description, segment6.description
  FROM (
SELECT cc.coa_combination_id, cc.field1, vgl.code, vgl.description
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field1 AND coa.field1 = ol.option_line_code 
AND cc.coa_combination_id = 1
) segment1 ,

(
SELECT cc.coa_combination_id, cc.field2,  vgl.code, vgl.description
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field2 AND coa.field2 = ol.option_line_code 
AND cc.coa_combination_id = 1
) segment2 ,

(
SELECT cc.coa_combination_id, cc.field3,  vgl.code, vgl.description
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field3 AND coa.field3 = ol.option_line_code 
AND cc.coa_combination_id = 1
) segment3 ,

(
SELECT cc.coa_combination_id, cc.field4,  vgl.code, vgl.description
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field4 AND coa.field4 = ol.option_line_code 
AND cc.coa_combination_id = 1
) segment4,

(
SELECT cc.coa_combination_id, cc.field5,  vgl.code, vgl.description
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field5 AND coa.field5 = ol.option_line_code 
AND cc.coa_combination_id = 1
) segment5 ,

(
SELECT cc.coa_combination_id, cc.field6,  vgl.code, vgl.description
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field6 AND coa.field6 = ol.option_line_code 
AND cc.coa_combination_id = 1
) segment6 

";
 }

 public static function find_description_from_ccId($cc_id = '1') {

  $sql = " 
  SELECT segment1.description1,  segment2.description2,  segment3.description3, segment4.description4, 
  segment5.description5, segment6.description6, segment4.account_qualifier4
  
  FROM (
SELECT cc.coa_combination_id, cc.field1, vgl.code, vgl.description as description1, vgl.account_qualifier as account_qualifier1
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field1 AND coa.field1 = ol.option_line_code 
AND cc.coa_combination_id = '{$cc_id}'
) segment1 ,

(
SELECT cc.coa_combination_id, cc.field2,  vgl.code, vgl.description as description2
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field2 AND coa.field2 = ol.option_line_code 
AND cc.coa_combination_id = '{$cc_id}'
) segment2  LEFT JOIN

(
SELECT cc.coa_combination_id, cc.field3,  vgl.code, vgl.description as description3
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field3 AND coa.field3 = ol.option_line_code 
AND cc.coa_combination_id = '{$cc_id}'
) segment3 ON  segment3.coa_combination_id = segment2.coa_combination_id 
LEFT JOIN 

(
SELECT cc.coa_combination_id, cc.field4,  vgl.code, vgl.description as description4, vgl.account_qualifier as account_qualifier4
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field4 AND coa.field4 = ol.option_line_code 
AND cc.coa_combination_id = '{$cc_id}'
) segment4 ON  segment4.coa_combination_id = segment3.coa_combination_id 

LEFT JOIN 
(
SELECT cc.coa_combination_id, cc.field5,  vgl.code, vgl.description as description5
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field5 AND coa.field5 = ol.option_line_code 
AND cc.coa_combination_id = '{$cc_id}'
) segment5  ON  segment5.coa_combination_id = segment4.coa_combination_id 
  LEFT JOIN 
(
SELECT cc.coa_combination_id, cc.field6,  vgl.code, vgl.description as description6
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field6 AND coa.field6 = ol.option_line_code 
AND cc.coa_combination_id = '{$cc_id}'
) segment6 ON  segment6.coa_combination_id = segment5.coa_combination_id 

LEFT JOIN 
(
SELECT cc.coa_combination_id, cc.field7,  vgl.code, vgl.description as description57
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field7 AND coa.field7 = ol.option_line_code 
AND cc.coa_combination_id = '{$cc_id}'
) segment7  ON  segment7.coa_combination_id = segment6.coa_combination_id 
  LEFT JOIN 
(
SELECT cc.coa_combination_id, cc.field8,  vgl.code, vgl.description as description8
from coa_combination cc,
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE coa.coa_id = cc.coa_id
AND oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND vgl.code = cc.field8 AND coa.field8 = ol.option_line_code 
AND cc.coa_combination_id = '{$cc_id}'
) segment8 ON  segment8.coa_combination_id = segment7.coa_combination_id 

";

  $result = self::find_by_sql($sql);
  $ret_a = [];

  if (empty($result[0]->account_qualifier4)) {
   echo $sql;
   return;
  }

  $ret_a['ac_type'] = $result[0]->account_qualifier4;

  $desc = '';
  foreach ($result[0] as $k => $v) {
   $desc .=!empty($v) ? "-$v" : '';
  }
  $ret_a['desc'] = ltrim($desc, '-');

  return $ret_a;
 }

 public static function find_new_combination($combination_id, $segment_vals) {
  /* $segment_vals parameter examples ['cost_center' => '123', 'natural_account' => '465']
   */

  $cc_details = self::find_by_id($combination_id);
  $field_mapping_a = coa::find_account_qualifers_byCoaId($cc_details->coa_id);
  $field_name = $field_val = "";
//  pa($segment_vals);
//  pa($field_mapping_a);
  foreach ($segment_vals as $k => $v) {
   $field_name = $field_mapping_a[$k];
   $field_val = $v;
  }
//  echo "<br>field_name is $field_name and field_val is $field_val ";
  $sql = " SELECT comb2.coa_combination_id, comb2.combination, comb2.description, comb2.ac_type ,
   comb2.effective_start_date, comb2.effective_end_date  
   FROM  
   coa_combination comb1,
   coa_combination comb2
   WHERE comb1.coa_combination_id = '{$combination_id}'
   AND comb1.coa_id = comb2.coa_id
   ";

  if ($field_name == 'field1') {
   $sql .= " AND comb2.field1 = '{$field_val}' ";
  } else {
   $sql .= " AND (comb1.field1 = comb2.field1 || comb1.field1 IS NULL) ";
  }


  if ($field_name == 'field2') {
   $sql .= " AND comb2.field2 = '{$field_val}' ";
  } else {
   $sql .= " AND (comb1.field2 = comb2.field2 || comb1.field2 IS NULL) ";
  }


  if ($field_name == 'field3') {
   $sql .= " AND comb2.field3 = '{$field_val}' ";
  } else {
   $sql .= " AND (comb1.field3 = comb2.field3 || comb1.field3 IS NULL) ";
  }


  if ($field_name == 'field4') {
   $sql .= " AND comb2.field4 = '{$field_val}' ";
  } else {
   $sql .= " AND (comb1.field4 = comb2.field4 || comb1.field4 IS NULL) ";
  }

  if ($field_name == 'field5') {
   $sql .= " AND comb2.field5 = '{$field_val}' ";
  } else {
   $sql .= " AND (comb1.field5 = comb2.field5 || comb1.field5 IS NULL) ";
  }

  if ($field_name == 'field6') {
   $sql .= " AND comb2.field6 = '{$field_val}' ";
  } else {
   $sql .= " AND (comb1.field6 = comb2.field6 || comb1.field6 IS NULL) ";
  }

  if ($field_name == 'field7') {
   $sql .= " AND comb2.field7 = '{$field_val}' ";
  } else {
   $sql .= " AND (comb1.field7 = comb2.field7 || comb1.field7 IS NULL) ";
  }

  if ($field_name == 'field8') {
   $sql .= " AND comb2.field8 = '{$field_val}' ";
  } else {
   $sql .= " AND (comb1.field8 = comb2.field8 || comb1.field8 IS NULL) ";
  }

//  echo $sql;
  $result = self::find_by_sql($sql);

  return !empty($result) ? array_pop($result) : null;
 }

}

//end of coa_combination class
?>