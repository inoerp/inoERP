<?php

class uom extends org {

 protected static $table_name = "uom";
 public static $field_array = ["uom_id",
		 "class",
		 "uom",
		 "description",
		 "primary",
		 "primary_uom",
		 "primary_relation",
		 "ef_id",
		 "status",
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $initial_search_array = [
		 "uom_id",
		 "class",
		 "uom",
		 "description",
		 "primary"
 ];
 public static $column_array = [
		 "uom_id",
		 "class",
		 "uom",
		 "description",
		 "primary",
		 "primary_uom",
		 "primary_relation",
		 "status"
 ];
 public static $checkbox_array = [
		 "rev_enabled_cb"
 ];
 public static $requiredField_array = [
		 "class",
		 "uom"
 ];
 public static $primary_column = "uom_id";
 public $uom_id;
 public $class;
 public $uom;
 public $description;
 public $primary;
 public $primary_uom;
 public $primary_relation;
 public $ef_id;
 public $status;
 public $rev_enabled_cb;
 public $rev_number;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public static $table_line_tr = <<<'VAR'
<thead> 
 				 <tr>
 					<th>Action</th>
 					<th>UOM Id</th>
 					<th>UOM</th>
 					<th>Class</th>
 					<th>Description</th>
 					<th>Primary</th>
 					<th>Primary UOM</th>
 					<th>Operator</th>
 					<th>Primary Relation</th>
 					<th>EF Id</th>
 					<th>Status</th>
 					<th>Rev Enabled</th>
 					<th>Rev#</th>
 				 </tr>
 				</thead>
VAR;

 Public static function uom_class() {
	$option_header = option_header::find_by_name('UOM_CLASS');
	$uom_class = option_line::find_by_option_id($option_header->option_header_id);
	return $uom_class;
 }

 public static function find_uom_by_uom($uom) {
	global $db;
	$sql = "SELECT uom, description FROM "
					. self::$table_name
					. " where uom LIKE '%{$uom}%' LIMIT 0, 30";
	$result = $db->query($sql);
	$data = array();
	if ($result && mysql_num_rows($result)) {
	 while ($row = $db->fetch_array($result)) {
		$data[] = array(
				'label' => $row['uom'] . ' , ' . $row['description'],
				'value' => $row['uom']
		);
	 }
	}

	return $data;
 }

 public function copy($uom_id) {
	global $db;
	$sql1 = " CREATE TEMPORARY TABLE tmptable SELECT * FROM uom WHERE `uom_id` = '{$uom_id}' ";
	if ($db->query($sql1)) {
	 $sql2 = " UPDATE tmptable SET `uom_id` = '',
                `inventory_id` = '{$this->inventory_id}'
                WHERE `uom_id` = '{$uom_id}' ";
	 if ($db->query($sql2)) {
		$sql3 = " INSERT INTO `uom` SELECT * FROM tmptable WHERE `uom_id` = '' ";
		if ($db->query($sql3)) {
		 $this->uom_id = $db->insert_id();
		 $this->msg = 1;
		} else {
		 $this->msg = 0;
		}
	 }
	}
	return $this->msg;
 }

 public static function uom_page() {
	echo '<table class="normal"><thead><tr>';
	foreach (self::$field_array as $key => $value) {
	 echo '<th>' . $value . '</th>';
	}
	echo '</tr></thead><tbody>';

	$uom = self::find_all();
//    echo '<pre>';
//    print_r($uom);
//    echo '<pre>';
	foreach ($uom as $record) {
	 echo '<tr>';
	 foreach (self::$field_array as $key => $value) {
		echo '<td>' . $record->$value . '</td>';
	 }
	 echo '</tr>';
	}
	echo ' </tbody> </table>';
 }

}

//end of uom class
?>