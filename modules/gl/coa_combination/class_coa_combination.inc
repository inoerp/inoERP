<?php

class coa_combination extends dbObject {

 protected static $table_name = "coa_combination";
 public static $dependent_classes = ['coa'];
 public static $primary_column = "coa_combination_id";
 public static $key_column = "combination";
 public static $module = "gl";
 public $field_a = [];
 public $initial_search = [
		 'field1',
		 'combination',
		 'coa_combination_id',
		 'coa_id',
		 'coa_structure_id'
 ];
 public $column = [
		 'field1',
		 'combination',
		 'coa_combination_id',
		 'coa_id',
		 'coa_structure_id'
 ];
 public $account = [
		 'combination'
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
		 'coa_structure_id',
		 'field1',
		 'field2',
		 'field3',
		 'field4'
 ];
 public $pageTitle = " GL COA Combinatioins "; //page Title
 public $search = [
		 '_update_path' => 'modules/gl/coa_combination/coa_combination',
		 '_show_update_path' => 1,
//		 '_view_path' => 'modules/gl/coa/ledger_view',
//		 '_show_view_path' => 1,
 ];

 function __construct() {
	if (!empty(static::$table_name)) {
	 $this->field_a = get_dbColumns(static::$table_name);
	 foreach ($this->field_a as $key => $value) {
		$this->$value = '';
	 }
	}
 }

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
					. " where combination LIKE '%{$coa_combination}%' LIMIT 0, 30";
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
	global $db;
	$sql = " SELECT * FROM "
					. self::$table_name
					. " where coa_id = :coa_id AND combination LIKE :combination LIMIT 0, $limit";
	$param_a = ['coa_id', 'combination'];
	$combination = '%' . $this->combination . '%';
	$value_a = [ 'coa_id' => $this->coa_id, 'combination' => $combination];
	$result = $db->findBy_sql($sql, $param_a, $value_a);
	return !(empty($result)) ? $result : false;
 }

 public function searchBy_coaId_combination() {
	$result = $this->findBy_coaId_combination();
	$data = array();
	if (!empty($result)) {
	 foreach ($result as $obj) {
		$data[] = array(
				'label' => $obj->combination,
				'value' => $obj->combination
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
					" AND combination='{$coa_combination}' " .
					"LIMIT 1";
	$result_set = $db->find_by_sql($sql);
	return !(empty($result_set)) ? true : false;
 }

// public static function find_combination_id_from_combination($coa_id, $coa_combination) {
//	global $dbc;
//	$sql = "SELECT coa_combination_id FROM " .
//					self::$table_name .
//					" where coa_id= :coa_id" .
//					" AND combination= :coa_combination " .
//					" LIMIT 1";
//	$stmt = $dbc->connection->prepare(" $sql ");
//	$stmt->bindParam(':coa_id', $coa_id);
//	$stmt->bindParam(':coa_combination', $coa_combination);
//	try {
//	 $stmt->execute();
//	 $result = $stmt->fetchObject();
//	 return !(empty($result)) ? ($result->coa_combination_id) : false;
//	} catch (PDOException $e) {
//	 $ie->page_exception = ['dbObject findBy id Error : ' => $e->getMessage()];
//	 echo "Record couldnt be saved!!: " . $e->getMessage();
//	}
// }

 public static function coa_combination_page() {
	echo '<table class="normal">
                <thead> 
                    <tr>
                    <th>COA Segment Value Id/th>
                    <th>Segment Code </th>
                    <th>Description</th>
                    <th>Created By</th>
                    <th>Creation Date</th>
                    <th>Last Update By</th>
                    <th>Last Update Date</th>
                    <th>Action</th>
                    </tr>
                </thead>
                <tbody>';

	$coa_combination = coa_combination::find_all();
	foreach ($coa_combination as $record) {
	 echo '<tr><td>' . $record->coa_combination_id . '</td>';
	 echo '<td>' . $record->segment_code . '</td> ';
	 echo '<td>' . $record->description . '</td>';
	 echo '<td>' . $record->created_by . '</td>';
	 echo '<td>' . $record->creation_date . '</td> ';
	 echo '<td>' . $record->last_update_by . '</td>';
	 echo '<td>' . $record->last_update_date . '</td>';
	 echo '<td><a href="coa_combination.php?coa_combination_id=' . $record->coa_combination_id . '">Update</a></td></tr>';
	}

	echo ' </tbody> </table>';
 }

}

//end of coa_combination class
?>