<?php

class coa extends dbObject {

 public static $table_name = "coa";
 public static $primary_column = "coa_id";
 public static $key_column = "coa_structure_id"; //same as option_header_id
 public static $module = "gl";
 public $initial_search = [
		 'coa_structure_id',
		 'name',
		 'description',
		 'coa_sequence'
 ];
 public $fields_inForm_notInDataBase = [
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public $field_a = [];
 public $checkbox = [
		 'rev_enabled_cb',
 ];
 public $column = [
		 'coa_id',
		 'coa_structure_id',
		 'name',
		 'description',
		 'coa_sequence'
 ];
// public $base_encoded = [];
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
		 '_update_path' => 'modules/gl/coa/coa',
		 '_show_update_path' => 1,
		 '_update_action_meassge' => 'Update COA',
		 '_view_path' => 'modules/gl/ledger/coa_view',
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " COA - Find All COAs "; //page Title
 public $coa_structure_id;

 public $coa_id;
 public $segments;
 public $name;
 public $description;
 public $balancing;
 public $cost_center;
 public $natural_account;
 public $inter_company;
 public $segment1;
 public $segment2;
 public $segment3;
 public $segment4;
 public $coa_sequence;
 public $field1;
 public $field2;
 public $field3;
 public $field4;
 public $field5;
 public $field6;
 public $field7;
 public $field8;
 public $ef_id;
 public $status;
 public $rev_enabled;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
// function __construct() {
//	if (!empty(static::$table_name)) {
//	 $this->field_a = get_dbColumns(static::$table_name);
//	 foreach ($this->field_a as $key => $value) {
//		$this->$value = '';
//	 }
//	}
// }

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
	$value_a = [ 'coa_structure_id' => $this->coa_structure_id ];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
	return !empty($result) ? array_shift($result) : false;
 }

 Public static function coa_structures() {
	global $db;
	$sql = " SELECT * FROM option_header ";
	$sql .= " WHERE option_assignments IS NOT NULL ";
	$result = $db->find_by_sql($sql);
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
	$coa_structure_id = option_header::find_by_name('{$option_type}');
	if (!empty($coa_structure_id)) {
	 $segments = option_line::find_by_option_id($coa_structure_id->option_header_id);
	}
	return !empty($segments) ? $segments : false;
 }

 Public static function coa_segments_by_optionHeaderId($option_headerId) {
	$coa_structure_id = option_header::find_by_id($option_headerId);
	if (!empty($coa_structure_id)) {
	 $segments = option_line::find_by_option_id($coa_structure_id->option_header_id);
	}
	return !empty($segments) ? $segments : false;
 }

 public static function find_coa_fields_option($coa_id) {
	$sql = "SELECT balancing, cost_center, 	natural_account, inter_company,
      segment1, segment2, segment3, segment4 FROM "
					. self::$table_name . " where coa_id={$coa_id} LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_coa_fields_by_id($coa_id) {
	$sql = "SELECT balancing, cost_center, 	natural_account, inter_company,
      segment1, segment2, segment3, segment4 FROM "
					. self::$table_name . " where coa_id={$coa_id} LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_coa_fields_by_id_array($coa_id) {
	global $db;
	$sql = "SELECT balancing, cost_center, 	natural_account, inter_company,
      segment1, segment2, segment3, segment4 FROM "
					. self::$table_name . " where coa_id={$coa_id} LIMIT 1";
	$result_set = $db->query($sql);
	$row = mysql_fetch_row($result_set);
	return $row;
 }

 public static function coa_page() {
	echo '<table class="normal">
                <thead> 
                    <tr>
                    <th>COA Id/th>
                    <th>Name</th>
                    <th>Description</th>
                    <th>Structure</th>
					<th>Balancing</th>
					<th>Cost Center</th>
					<th>Account</th>
					<th>I/C</th>
                    <th>Segemnt1</th>
                    <th>Segemnt2</th>
                    <th>Segemnt3</th>
                    <th>Segemnt4</th>
                    <th>Sequence</th>
                    <th>Created By</th>
                    <th>Creation Date</th>
                    <th>Last Update By</th>
                    <th>Last Update Date</th>
                    <th>Action</th>
                    </tr>
                </thead>
                <tbody>';

	$coa = coa::find_all();
	foreach ($coa as $record) {
	 echo '<tr><td>' . $record->coa_id . '</td>';
	 echo '<td>' . $record->name . '</td> ';
	 echo '<td>' . $record->description . '</td>';
	 echo '<td>' . $record->coa_structure_id . '</td>';
	 echo '<td>' . $record->balancing . '</td>';
	 echo '<td>' . $record->cost_center . '</td>';
	 echo '<td>' . $record->natural_account . '</td>';
	 echo '<td>' . $record->inter_company . '</td>';
	 echo '<td>' . $record->segment1 . '</td>';
	 echo '<td>' . $record->segment2 . '</td>';
	 echo '<td>' . $record->segment3 . '</td>';
	 echo '<td>' . $record->segment4 . '</td>';
	 echo '<td>' . $record->coa_sequence . '</td>';
	 echo '<td>' . $record->created_by . '</td>';
	 echo '<td>' . $record->creation_date . '</td> ';
	 echo '<td>' . $record->last_update_by . '</td>';
	 echo '<td>' . $record->last_update_date . '</td>';
	 echo '<td><a href="coa.php?coa_id=' . $record->coa_id . '">Update</a></td></tr>';
	}

	echo ' </tbody> </table>';
 }

}

$coa = new coa;
//end of coa class
?>
