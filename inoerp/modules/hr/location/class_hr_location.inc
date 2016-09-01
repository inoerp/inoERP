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
 * hr_location
 * chart of account combinations defines valid accounting combinations available for transactions
 * Contains all the hr_location information, such as - coa_id, coa_structure_id , all fields
 * 
 */
class hr_location extends dbObject {

 public static $table_name = "hr_location";
 public static $primary_column = "hr_location_id";
 public static $key_column = "country";
 public static $module = "hr";
 public static $system_info = [
  'name' => 'Location',
  'number' => '3121',
  'description' => 'HR Location',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 4
 ];
 public $field_a = [
  'hr_location_id',
  'country',
  'state',
  'city',
  'combination',
  'description',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'country',
  'state',
  'city',
 ];
 public $requiredField = [
  'country',
  'city'
 ];
 public $pageTitle = " HR Location "; //page Title
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $hr_location_id;
 public $country;
 public $state;
 public $city;
 public $combination;
 public $description;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 
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

 public static function find_hr_location_by_coa_id($coa_id) {
  $sql = "SELECT * FROM "
   . self::$table_name
   . " where coa_id={$coa_id}";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_hr_location_by_hr_location($hr_location) {
  global $db;
  $sql = " SELECT combination FROM "
   . self::$table_name
   . " where combination LIKE '%{$hr_location}%' ";
   $sql = ino_perPageSql_i($sql, 1);
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

  $sql = ino_perPageSql_i($sql, $limit);

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

 $sql = ino_perPageSql_i($sql, $limit);
  $result = self::find_by_sql($sql);

  return !(empty($result)) ? $result : false;
 }

 public function findBy_exactCombination($combination) {
  global $db;
  $sql = " SELECT * FROM "
   . self::$table_name
   . " where  combination = :combination ";
  $sql = ino_perPageSql_i($sql, 1);
  $param_a = ['combination'];
  $value_a = ['combination' => $combination];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !(empty($result)) ? array_pop($result) : false;
 }

 public static function find_by_exactCombination($combination) {
  $sql = " SELECT * FROM "
   . self::$table_name
   . " where  combination = '{$combination}' ";
   $sql = ino_perPageSql_i($sql, 1);
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
     'hr_location_id' => $row->hr_location_id
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
     'hr_location_id' => $row->hr_location_id
    );
   }
  }
  return $data;
 }

 public function findIdBy_combination_coaId() {
  $result = $this->findBy_coaId_combination(1);
  return !(empty($result)) ? $result[0]->hr_location_id : false;
 }

 public static function validate_hr_location($coa_id, $hr_location) {
  global $db;
  $sql = "SELECT * FROM " .
   self::$table_name .
   " where coa_id='{$coa_id}' " .
   " AND combination='{$hr_location}' ";
   $sql = ino_perPageSql_i($sql, 1);
  $result_set = $db->find_by_sql($sql);
  return !(empty($result_set)) ? true : false;
 }

 public function prg_update_description($seralized_parameters) {
  $parameters = unserialize($seralized_parameters);
  $this->message = '<br> Starting description update program';

  if (!empty($parameters['hr_location_id'][0])) {
   $hr_location_id = $parameters['hr_location_id'][0];
   $this->message .= '<br> Entered hr_location_id  is : ' . $hr_location_id;
  } else {
   $this->message .= '<br> No hr_location_id provide. Updating all account code combination description ';
  }


  if (!empty($hr_location_id)) {
   $cc = new hr_location();
   $cc->hr_location_id = $hr_location_id;
//   $cc->$cc->description = $ret_a['desc'];
   $ret_a = self::find_description_from_ccId($hr_location_id);
   $cc->description = $ret_a['desc'];
   $cc->ac_type = $ret_a['ac_type'];
   $cc->save();
  } else {
   $cc_all = hr_location::find_all();
   foreach ($cc_all as $record) {
    $cc = new hr_location();
    $cc->hr_location_id = $record->hr_location_id;
    $ret_a = self::find_description_from_ccId($cc->hr_location_id);
    $cc->description = $ret_a['desc'];
    $cc->ac_type = $ret_a['ac_type'];
    echo '<br> des ' . $cc->description;
    $cc->save();
   }
  }
  return $this->message;
 }

 public function prg_all_combinations($seralized_parameters) {
  return hr_location::find_all();
 }

 public static function hr_location_description() {

  $sql = " 
  SELECT segment1.code, segment2.code, segment3.code, segment4.code,  segment5.code, segment6.code, 
  segment1.description, segment2.description,
  segment3.description, segment4.description, segment5.description, segment6.description
  FROM (
SELECT cc.hr_location_id, cc.field1, vgl.code, vgl.description
from hr_location cc,
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
AND cc.hr_location_id = 1
) segment1 ,

(
SELECT cc.hr_location_id, cc.field2,  vgl.code, vgl.description
from hr_location cc,
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
AND cc.hr_location_id = 1
) segment2 ,

(
SELECT cc.hr_location_id, cc.field3,  vgl.code, vgl.description
from hr_location cc,
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
AND cc.hr_location_id = 1
) segment3 ,

(
SELECT cc.hr_location_id, cc.field4,  vgl.code, vgl.description
from hr_location cc,
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
AND cc.hr_location_id = 1
) segment4,

(
SELECT cc.hr_location_id, cc.field5,  vgl.code, vgl.description
from hr_location cc,
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
AND cc.hr_location_id = 1
) segment5 ,

(
SELECT cc.hr_location_id, cc.field6,  vgl.code, vgl.description
from hr_location cc,
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
AND cc.hr_location_id = 1
) segment6 

";
 }

 public static function find_description_from_ccId($cc_id = '1') {

  $sql = " 
  SELECT segment1.description1,  segment2.description2,  segment3.description3, segment4.description4, 
  segment5.description5, segment6.description6, segment4.account_qualifier4
  
  FROM (
SELECT cc.hr_location_id, cc.field1, vgl.code, vgl.description as description1, vgl.account_qualifier as account_qualifier1
from hr_location cc,
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
AND cc.hr_location_id = '{$cc_id}'
) segment1 ,

(
SELECT cc.hr_location_id, cc.field2,  vgl.code, vgl.description as description2
from hr_location cc,
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
AND cc.hr_location_id = '{$cc_id}'
) segment2  LEFT JOIN

(
SELECT cc.hr_location_id, cc.field3,  vgl.code, vgl.description as description3
from hr_location cc,
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
AND cc.hr_location_id = '{$cc_id}'
) segment3 ON  segment3.hr_location_id = segment2.hr_location_id 
LEFT JOIN 

(
SELECT cc.hr_location_id, cc.field4,  vgl.code, vgl.description as description4, vgl.account_qualifier as account_qualifier4
from hr_location cc,
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
AND cc.hr_location_id = '{$cc_id}'
) segment4 ON  segment4.hr_location_id = segment3.hr_location_id 

LEFT JOIN 
(
SELECT cc.hr_location_id, cc.field5,  vgl.code, vgl.description as description5
from hr_location cc,
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
AND cc.hr_location_id = '{$cc_id}'
) segment5  ON  segment5.hr_location_id = segment4.hr_location_id 
  LEFT JOIN 
(
SELECT cc.hr_location_id, cc.field6,  vgl.code, vgl.description as description6
from hr_location cc,
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
AND cc.hr_location_id = '{$cc_id}'
) segment6 ON  segment6.hr_location_id = segment5.hr_location_id 

LEFT JOIN 
(
SELECT cc.hr_location_id, cc.field7,  vgl.code, vgl.description as description57
from hr_location cc,
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
AND cc.hr_location_id = '{$cc_id}'
) segment7  ON  segment7.hr_location_id = segment6.hr_location_id 
  LEFT JOIN 
(
SELECT cc.hr_location_id, cc.field8,  vgl.code, vgl.description as description8
from hr_location cc,
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
AND cc.hr_location_id = '{$cc_id}'
) segment8 ON  segment8.hr_location_id = segment7.hr_location_id 

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

}

//end of hr_location class
?>