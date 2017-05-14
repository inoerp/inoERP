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
 * coa
 * coa is used for mapping different  business segments that needs financial account mapping
 * Contains all the gl_calendar information, such as - name, description , balancing, natural_account, etc
 * coa_structure_id is the option header id
 * 
 */
class coa extends dbObject {

 public static $table_name = "coa";
 public static $primary_column = "coa_id";
 public static $key_column = "coa_structure_id"; //same as option_header_id
 public static $module = "gl";
 public static $system_info = [
  'name' => 'COA',
  'number' => '1103',
  'description' => 'Chart Of Account',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('coa_segment_values'),
  'primary_entity_cb' => '',
  'module_name' => 'gl',
  'weight' => 3
 ];
 public $field_a = ['coa_id',
  'coa_structure_id',
  'coa_name',
  'description',
  'balancing',
  'cost_center',
  'natural_account',
  'inter_company',
  'field1',
  'field2',
  'field3',
  'field4',
  'field5',
  'field6',
  'field7',
  'field8',
  'status',
  'rev_enabled_cb',
  'rev_number',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'coa_structure_id',
  'description',
  'coa_sequence'
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public $checkbox = [
  'rev_enabled_cb',
 ];
 public $requiredField = [
  'coa_structure_id',
  'description',
  'balancing',
  'cost_center',
  'natural_account',
  'inter_company'
 ];
// public $dateFields;
//varibles required for search
 public $search = [
  '_show_update_path' => 1,
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Chart Of Account "; //page Title
 public $coa_id;
 public $coa_structure_id;
 public $coa_name;
 public $description;
 public $balancing;
 public $cost_center;
 public $natural_account;
 public $inter_company;
 public $field1;
 public $field2;
 public $field3;
 public $field4;
 public $field5;
 public $field6;
 public $field7;
 public $field8;
 public $coa_sequence_value;
 public $coa_sequence_field;
 public $ef_id;
 public $status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $only_parent;
 public $account_qualifier;
 public $field4_low;
 public $field4_high;

// public function _before_save() {
//  if (empty($this->coa_sequence)) {
//   
//  }
// }

 public static function find_all_accounts_from_coaId($coa_id = '1', $only_parent = false, $account_qualifier = '') {
  $sql = "
  SELECT coa.coa_id, coa.coa_structure_id, coa.natural_account, ol.value_group_id, vgl.code, vgl.description, 
  vgl.account_qualifier, vgl.parent_cb
from 
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND coa.natural_account = ol.option_line_code 
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND coa.coa_id = '{$coa_id}'
";

  if ($only_parent) {
   $sql .= " AND vgl.parent_cb = 1";
  }

  if (!empty($account_qualifier)) {
   $sql .= " AND vgl.account_qualifier = '{$account_qualifier}'";
  }

  $sql .= " ORDER BY vgl.code asc";


  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public function findAll_accounts_from_coaId() {
  $this->coa_id = empty($this->coa_id) ? '1' : $this->coa_id;
  $sql = "
  SELECT coa.coa_id, coa.coa_structure_id, coa.natural_account, ol.value_group_id, vgl.code, vgl.description, 
  vgl.account_qualifier, vgl.parent_cb
from 
coa,
option_header oh,
option_line ol,
sys_value_group_header vgh,
sys_value_group_line vgl
WHERE oh.option_header_id = coa.coa_structure_id
AND oh.option_header_id = ol.option_header_id
AND coa.natural_account = ol.option_line_code 
AND vgh.sys_value_group_header_id = ol.value_group_id
AND vgh.sys_value_group_header_id = vgl.sys_value_group_header_id
AND coa.coa_id = :coa_id
";

  if (!empty($this->field4_low)) {
   $sql .= " AND vgl.code >= '{$this->field4_low}' ";
  }

  if (!empty($this->field4_high)) {
   $sql .= " AND vgl.code <= '{$this->field4_high}' ";
  }

  $param_a['coa_id'] = $this->coa_id;

  if (!empty($this->only_parent)) {
   $sql .= " AND vgl.parent_cb = 1 ";
  }

  if (!empty($this->account_qualifier)) {
   $sql .= " AND vgl.account_qualifier = :account_qualifier ";
   $param_a['account_qualifier'] = $this->account_qualifier;
  }

  $sql .= " ORDER BY vgl.code asc";


  $result = $this->findBySql($sql, $param_a);

  return !empty($result) ? $result : false;
 }

 Public static function coa_account_types() {
  $option_header = option_header::find_by_name('COA_ACCOUNT_TYPE');
  $ol = new option_line();
  $coa_account_types = $ol->findBy_parentId($option_header->option_header_id);
  return $coa_account_types;
 }

 Public static function find_by_structure($coa_structure_id = '') {
  global $db;
  $sql = " SELECT * FROM  " . self::$table_name;
  $sql .= " WHERE coa_structure_id = '{$coa_structure_id}' ";
  $result = $db->find_by_sql($sql);
  return !empty($result) ? array_shift($result) : false;
 }

 Public function findBy_structureId() {
  global $db;
  $sql = " SELECT * FROM  " . self::$table_name;
  $sql .= " WHERE coa_structure_id = :coa_structure_id ";
  $param_a = ['coa_structure_id'];
  $value_a = [ 'coa_structure_id' => $this->coa_structure_id];
  $result = $db->findBy_sql($sql, $param_a, $value_a);
  return !empty($result) ? array_shift($result) : false;
 }

 Public static function coa_structures() {
  $sql = " SELECT * FROM option_header WHERE option_assignments = 'GL_COA' ";
  $result = self::find_by_sql($sql);
  return $result;
 }

 Public static function coa_display_by_coaId($coaId = '') {
  global $db;
  $sql = " SELECT  field1, field2, field3, field4, field5, 
	 field6, field7, field8 FROM  " . self::$table_name;
  $sql .= " WHERE coa_id = '{$coaId}' ";
  $result = $db->find_by_sql($sql);
  return !empty($result) ? array_shift($result) : false;
 }

 Public static function coa_segments($option_type) {
  $coa_structure_id = option_header::find_by_name($option_type);
  if (!empty($coa_structure_id)) {
   $segments = option_line::find_by_option_id($coa_structure_id->option_header_id);
  }
  return !empty($segments) ? $segments : false;
 }

 Public static function coa_segments_by_optionHeaderId($option_headerId) {
  $segments = option_line::find_by_parent_id($option_headerId);
  return !empty($segments) ? $segments : false;
 }

 public static function find_coa_fields_option($coa_id) {
  $sql = "SELECT balancing, cost_center, 	natural_account, inter_company,
      segment1, segment2, segment3, segment4 FROM "
   . self::$table_name . " where coa_id={$coa_id} ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_coa_fields_by_id($coa_id) {
  $sql = "SELECT balancing, cost_center, 	natural_account, inter_company,
      segment1, segment2, segment3, segment4 FROM "
   . self::$table_name . " where coa_id={$coa_id} ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_array = self::find_by_sql($sql);
  return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_coa_fields_by_id_array($coa_id) {
  global $db;
  $sql = "SELECT balancing, cost_center, 	natural_account, inter_company,
      segment1, segment2, segment3, segment4 FROM "
   . self::$table_name . " where coa_id={$coa_id} ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_set = $db->query($sql);
  $row = mysql_fetch_row($result_set);
  return $row;
 }

 public static function find_coa_from_orgId($coa_id) {
  global $db;
  $sql = "SELECT balancing, cost_center, 	natural_account, inter_company,
      segment1, segment2, segment3, segment4 FROM "
   . self::$table_name . " where coa_id={$coa_id} ";
  switch (DB_TYPE) {
   case 'ORACLE' :
    $sql .= ' AND ' . ino_perPageSql(1);
    break;

   default:
    $sql .= ino_perPageSql(1);
    break;
  }
  $result_set = $db->query($sql);
  $row = mysql_fetch_row($result_set);
  return $row;
 }

 public static function find_account_qualifers_byCoaId($coa_id) {
  $coa_details = self::find_by_id($coa_id);
  $ret_arr = [];

  for ($i = 1; $i <= 8; $i++) {
   $field = 'field' . $i;
   if ($coa_details->$field == $coa_details->balancing) {
    $ret_arr['balancing'] = $field;
   } else if ($coa_details->$field == $coa_details->cost_center) {
    $ret_arr['cost_center'] = $field;
   } else if ($coa_details->$field == $coa_details->natural_account) {
    $ret_arr['natural_account'] = $field;
   } else if ($coa_details->$field == $coa_details->inter_company) {
    $ret_arr['inter_company'] = $field;
   }
  }
  return $ret_arr;
 }

}

$coa = new coa;
//end of coa class
?>
