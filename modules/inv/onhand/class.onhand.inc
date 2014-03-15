<?php

class onhand {

 protected static $table_name = "onhand";
 protected static $view_name = "onhand_v";
//  data base variables as stored database column name
 public static $field_array = ["onhand_id",
		 "item_id",
		 "org_id",
		 "subinventory_id",
		 "locator_id",
		 "lot_id",
		 "serial_id",
		 "item_number",
		 "item_description",
		 "org_name",
		 "subinventory",
		 "locator",
		 "onhand",
		 "reservable_onhand",
		 "transactable_onhand",
		 "lot_status",
		 "serial_status",
		 "uom_id",
		 "secondary_uom_id",
		 "onhand_status",
		 "ef_id",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//variables used for showing data
 public static $column_array = [
		 "item_number",
		 "item_description",
		 "org_name",
		 "subinventory",
		 "locator",
		 "uom",
		 "onhand",
		 "sum_onhand",
		 "onhand_id",
		 "item_id",
 ];
// public static $checkbox_array =["rev_enabled"                                 
//                                 ];

 public static $group_by = ["locator", "subInventory", "inventory"];
 public $sum_onhand;
 public $onhand_id;
 public $item_id;
 public $org_id;
 public $subinventory_id;
 public $locator_id;
 public $lot_id;
 public $item_number;
 public $item_description;
 public $org_name;
 public $subinventory;
 public $locator;
 public $uom_id;
 public $serial_id;
 public $onhand;
 public $reservable_onhand;
 public $transactable_onhand;
 public $lot_status;
 public $serial_status;
 public $uom;
 public $secondary_uom_id;
 public $onhand_status;
 public $ef_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public static $view_table_line_tr = <<<'VAR'
              <thead> 
               <tr>
                <th>Action</th>
                <th>Inventory</th>
                <th>SubInventory</th>
                <th>Structure</th>
                <th>Locator Id</th>
                <th>Locator </th>
                <th>Alias</th>
                <th>EF Id</th>
                <th>Status</th>
                <th>Rev Enabled</th>
                <th>Rev Number</th>
               </tr>
              </thead>
VAR;

//Public static function onhand_structure() {
//    $option_header = option_header::find_by_name('LOCATOR_STRUCTURE');
//    $onhand_class = option_line::find_by_option_id($option_header->option_id);
//    return $onhand_class;
//  }

 public static function find_by_sql($sql = "") {
	global $db;
	$result_set = $db->query($sql);
	$object_array = array();
	while ($row = $db->fetch_array($result_set)) {
	 $object_array[] = self::instantiate($row);
	}//end of while Loop
	return $object_array;
 }

 public static function find_all() {
	$sql = " SELECT * FROM " . self::$table_name;
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_all_v() {
	$sql = " SELECT * FROM " . self::$view_name;
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function count_all() {
	global $db;
	$sql = "SELECT COUNT(*) FROM " . self::$table_name;
	$result_set = $db->query($sql);
	$row = $db->fetch_array($result_set);
	return array_shift($row);
 }

 public static function count_all_by_sql($sql) {
	global $db;
	$result_set = $db->query($sql);
	$row = $db->fetch_array($result_set);
	return array_shift($row);
 }

 public static function find_by_id($onhand_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where onhand_id={$onhand_id} LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 private static function instantiate($record) {
	$object = new self;
	foreach ($record as $attribute => $value) {
	 if ($object->has_attribute($attribute)) {
		$object->$attribute = $value;
	 }
	}
	return $object;
 }

 Private function has_attribute($attribute) {
	$object_vars = get_object_vars($this);
	return array_key_exists($attribute, $object_vars);
 }

 public static function install() {
	global $db;
	$sql = "
		 ";
	$result = $db->query($sql);
	return !empty($result) ? $result : false;
 }

 public function save() {
	if (empty($this->onhand_id)) {
	 $this->create();
	} else {
	 $this->update($this->onhand_id);
	}
	return $this->msg;
 }

 private function create_onhand_v() {
	$sql = "CREATE OR REPLACE VIEW onhand_v
(onhand_id, item_number, item_description, org_name, subinventory, locator,
uom_id,onhand, item_id, org_id, subinventory_id, 
locator_id, lot_id, serial_id, reservable_onhand, 
transactable_onhand, lot_status, serial_status,  
secondary_uom_id, onhand_status, ef_id, created_by, 
creation_date, last_update_by, last_update_date)
AS
SELECT onhand.onhand_id, 
item.item_number, item.description, org.org, subinventory.subinventory, locator.locator,
onhand.uom_id,onhand.onhand,
onhand.item_id, onhand.org_id, onhand.subinventory_id, 
onhand.locator_id, onhand.lot_id, onhand.serial_id, onhand.reservable_onhand, 
onhand.transactable_onhand, onhand.lot_status, onhand.serial_status,  
onhand.secondary_uom_id, onhand.onhand_status, onhand.ef_id, onhand.created_by, 
onhand.creation_date, onhand.last_update_by, onhand.last_update_date

FROM onhand 
LEFT JOIN item ON onhand.item_id = item.item_id
LEFT JOIN org ON onhand.org_id = org.org_id
LEFT JOIN subinventory ON onhand.subinventory_id = subinventory.subinventory_id
LEFT JOIN locator ON onhand.locator_id = locator.locator_id
";
 }

 public function create() {
	global $db;
	$field_arry_colums = array();
	$field_arry_values = array();
	foreach (self::$field_array as $key => $value) {
	 $field_arry_colums[] = sprintf("`%s`", $value);
	}
	$field_colums = implode(',', $field_arry_colums);

	foreach (self::$field_array as $key => $value) {
	 if (!empty($this->$value)) {
		$field_arry_values[] = sprintf("'%s'", $this->$value);
	 } else {
		$field_arry_values[] = 'NULL';
	 }
	}
	$field_values = implode(',', $field_arry_values);

	$sql = " INSERT INTO ";
	$sql.= self::$table_name;
	$sql.= ' ( ';
	$sql.= $field_colums;
	$sql.= ' ) ';
	$sql.= 'VALUES';
	$sql.= ' ( ';
	$sql.= $field_values;
	$sql.= ' ) ';


	if ($db->query($sql)) {
	 $this->onhand_id = $db->insert_id();
	 $this->msg = 1;
	} else {
	 $this->msg = 0;
	}
	return $this->msg;
 }

//end of create onhand

 public function update($onhand_id) {
	global $db;
	$field_arry_values = array();

	foreach (self::$field_array as $key => $value) {
	 if (isset($this->$value)) {
		$field_arry_values[] = sprintf("`%s` = '%s'", $value, $this->$value);
	 }
	}
	$field_values = implode(',', $field_arry_values);

	$time = time();
	$last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
	$last_update_by = $_SESSION['user_name'];

	$sql = " UPDATE ";
	$sql.= self::$table_name;
	$sql .= " SET ";
	$sql.= $field_values;
//    $sql.= "`last_update_date` = '{$last_update_date}'," ;
//    $sql.= "`last_update_by` = '{$last_update_by }'" ;
	$sql.= " WHERE `onhand_id` = '{$onhand_id}' ";

//    echo "<br/>$sql is <br/>" . $sql;

	if ($db->query($sql)) {
	 $this->msg = 1;
	} else {
	 $this->msg = 0;
	}
	return $this->msg;
 }

 public static function update_onhand($item_id, $org_id, $uom_id, $quantity, $from_org_id, $from_subinventory_id, $from_locator_id, $to_org_id, $to_subinventory_id, $to_locator_id, $lot_number, $serial_number) {
	global $db;
	$return_array = array();
	$field_arry_values = array();

	if ((!empty($from_org_id))) {
	 $from_onhand_sql = " SELECT onhand_id, onhand  FROM onhand";
	 $from_onhand_sql .= " WHERE item_id = '{$item_id}' ";
	 $from_onhand_sql .= " AND  	org_id = '{$from_org_id}' ";

	 if (!empty($from_subinventory_id)) {
		$from_onhand_sql .= " AND  	subinventory_id = '{$from_subinventory_id}' ";
	 }
	 if (!empty($from_locator_id)) {
		$from_onhand_sql .= " AND  	locator_id = '{$from_locator_id}' ";
	 }
	 $from_onhand_sql .= " LIMIT 1 ";

	 $from_onhand_result = $db->query($from_onhand_sql);
	 $from_intial_onhand = 0;
	 if ($from_onhand_result && mysql_num_rows($from_onhand_result)) {
		while ($row = $db->fetch_array($from_onhand_result)) {
		 $from_intial_onhand = $row['onhand'];
		 $onhand_id = $row['onhand_id'];
		 $return_array['from_intial_onhand'] = $from_intial_onhand;
		}
		$from_final_onhand = $from_intial_onhand - $quantity;
		$return_array['from_final_onhand'] = $from_final_onhand;

		$update_onhand_sql = " update onhand SET onhand = '{$from_final_onhand}' WHERE onhand_id='{$onhand_id}' ";
		$onhand_update_result = $db->query($update_onhand_sql);
		if ($onhand_update_result) {
		 $return_array['from_update_staus'] = 1;
		} else {
		 $return_array['from_update_staus'] = 0;
		}
	 } else {
		//insert THE NEW ONHAND RECORDS
		$onhand = $from_intial_onhand - $quantity;
		$transactable_onhand = $onhand;
		$subinventory_id = $from_subinventory_id;
		$locator_id = $from_locator_id;
		$time = time();
		$creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
		$last_update_date = $creation_date;
		$created_by = $_SESSION['user_name'];
		$last_update_by = $created_by;
		$return_array['to_final_onhand'] = $onhand;

		$all_columns = array();
		$all_columns_sql = " SHOW COLUMNS FROM  " . self::$table_name;
		$all_columns_result = $db->query($all_columns_sql);
		if ($all_columns_result && mysql_num_rows($all_columns_result)) {
		 while ($row = $db->fetch_array($all_columns_result)) {
			array_push($all_columns, $row['Field']);
		 }
		}

		foreach ($all_columns as $key => $value) {
		 $field_arry_colums[] = sprintf("`%s`", $value);
		}
		$field_colums = implode(',', $field_arry_colums);

		foreach ($all_columns as $key => $value) {
		 if (!empty($$value)) {
			$field_arry_values[] = sprintf("'%s'", $$value);
		 } else {
			$field_arry_values[] = 'NULL';
		 }
		}
		$field_values = implode(',', $field_arry_values);

		$sql = " INSERT INTO ";
		$sql.= self::$table_name;
		$sql.= ' ( ';
		$sql.= $field_colums;
		$sql.= ' ) ';
		$sql.= 'VALUES';
		$sql.= ' ( ';
		$sql.= $field_values;
		$sql.= ' ) ';

		$onhand_update_result = $db->query($sql);
		if ($onhand_update_result) {
		 $return_array['to_update_staus'] = 1;
		} else {
		 $return_array['to_update_staus'] = 0;
		}
	 }
	}
//end of from org_id
//begining of to_org_id  
	if ((!empty($to_org_id))) {

//	 echo '<br/> in to_org_id 1 </br>';
	 $to_onhand_sql = " SELECT onhand_id, onhand  FROM onhand";
	 $to_onhand_sql .= " WHERE item_id = '{$item_id}' ";
	 $to_onhand_sql .= " AND  	org_id = '{$to_org_id}' ";

	 if (!empty($to_subinventory_id)) {
		$to_onhand_sql .= " AND  	subinventory_id = '{$to_subinventory_id}' ";
	 }
	 if (!empty($to_locator_id)) {
		$to_onhand_sql .= " AND  	locator_id = '{$to_locator_id}' ";
	 }
	 $to_onhand_sql .= " LIMIT 1 ";



	 $to_onhand_result = $db->query($to_onhand_sql);
//	 echo '<br/> in to_org_id 2.1 </br>';
	 $to_intial_onahand = 0;
	 if ($to_onhand_result && mysql_num_rows($to_onhand_result)) {
//		echo '<br/> in to_org_id 2.2 </br>';
		while ($row = $db->fetch_array($to_onhand_result)) {
		 $to_intial_onahand = $row['onhand'];
		 $onhand_id = $row['onhand_id'];
		 $return_array['to_intial_onahnd'] = $to_intial_onahand;
		}
		$to_final_onhand = $to_intial_onahand + $quantity;
		$return_array['to_final_onhand'] = $to_final_onhand;

		$update_onhand_sql = " update onhand SET onhand = '{$to_final_onhand}' " .
						" WHERE onhand_id='{$onhand_id}' ";

		$onhand_update_result = $db->query($update_onhand_sql);
		if ($onhand_update_result) {
		 $return_array['to_update_staus'] = 1;
		} else {
		 $return_array['to_update_staus'] = 0;
		}
	 } else {
		//insert THE NEW ONHAND RECORDS
//		echo '<br/> in to_org_id 3 </br>'. $to_onhand_sql;
		$onhand = $to_intial_onahand + $quantity;
		$reservable_onhand = $onhand;
		$transactable_onhand = $onhand;
		$subinventory_id = $to_subinventory_id;
		$locator_id = $to_locator_id;
		$time = time();
		$creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
		$last_update_date = $creation_date;
		$created_by = $_SESSION['user_name'];
		$last_update_by = $created_by;

		$return_array['to_final_onhand'] = $onhand;

		$all_columns = array();
		$all_columns_sql = " SHOW COLUMNS FROM  " . self::$table_name;
		$all_columns_result = $db->query($all_columns_sql);
		if ($all_columns_result && mysql_num_rows($all_columns_result)) {
		 while ($row = $db->fetch_array($all_columns_result)) {
			array_push($all_columns, $row['Field']);
		 }
		}

		foreach ($all_columns as $key => $value) {
		 $field_arry_colums[] = sprintf("`%s`", $value);
		}
		$field_colums = implode(',', $field_arry_colums);

		foreach ($all_columns as $key => $value) {
		 if (!empty($$value)) {
			$field_arry_values[] = sprintf("'%s'", $$value);
		 } else {
			$field_arry_values[] = 'NULL';
		 }
		}
		$field_values = implode(',', $field_arry_values);

		$sql = " INSERT INTO ";
		$sql.= self::$table_name;
		$sql.= ' ( ';
		$sql.= $field_colums;
		$sql.= ' ) ';
		$sql.= 'VALUES';
		$sql.= ' ( ';
		$sql.= $field_values;
		$sql.= ' ) ';

//		echo '<br/> in to_org_id 4 </br>'. $sql;

		$onhand_update_result = $db->query($sql);
		if ($onhand_update_result) {
		 $return_array['to_update_staus'] = 1;
		} else {
		 $return_array['to_update_staus'] = 0;
		}
	 }
	}
//end of to_org_id

	if ((!empty($org_id)) && (empty($from_org_id)) && (empty($to_org_id))) {
	 if (!empty($from_subinventory_id)) {
		$from_onhand_sql = " SELECT onhand_id, onhand  FROM onhand";
		$from_onhand_sql .= " WHERE item_id = '{$item_id}' ";
		$from_onhand_sql .= " AND  	org_id = '{$org_id}' ";
		$from_onhand_sql .= " AND  	subinventory_id = '{$from_subinventory_id}' ";

		if (!empty($from_locator_id)) {
		 $from_onhand_sql .= " AND  	locator_id = '{$from_locator_id}' ";
		}

		$from_onhand_sql .= " LIMIT 1 ";
		$from_intial_onhand = 0;

		$from_onhand_result = $db->query($from_onhand_sql);
		if ($from_onhand_result && mysql_num_rows($from_onhand_result) > 0) {
		 while ($row = $db->fetch_array($from_onhand_result)) {
			$from_intial_onhand = $row['onhand'];
			$onhand_id = $row['onhand_id'];
			$return_array['from_intial_onhand'] = $from_intial_onhand;
		 }
		 $from_final_onhand = $from_intial_onhand - $quantity;
		 $return_array['from_final_onhand'] = $from_final_onhand;

		 $update_onhand_sql = "update onhand SET onhand = '{$from_final_onhand}' WHERE onhand_id='{$onhand_id}'  ";

		 $onhand_update_result = $db->query($update_onhand_sql);
		 if ($onhand_update_result) {
			$return_array['from_update_staus'] = 1;
		 } else {
			$return_array['from_update_staus'] = 0;
		 }
		}else {
		 //insert THE NEW ONHAND RECORDS
		 $onhand = 0 - $quantity;
		 $reservable_onhand = $onhand;
		 $transactable_onhand = $onhand;
		 $subinventory_id = $from_subinventory_id;
		 $locator_id = $from_locator_id;
		 $time = time();
		 $creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
		 $last_update_date = $creation_date;
		 $created_by = $_SESSION['user_name'];
		 $last_update_by = $created_by;

		 $return_array['from_final_onhand'] = $onhand;

		 $all_columns = array();
		 $all_columns_sql = " SHOW COLUMNS FROM  " . self::$table_name;
		 $all_columns_result = $db->query($all_columns_sql);
		 if ($all_columns_result && mysql_num_rows($all_columns_result)) {
			while ($row = $db->fetch_array($all_columns_result)) {
			 array_push($all_columns, $row['Field']);
			}
		 }

		 foreach ($all_columns as $key => $value) {
			$field_arry_colums[] = sprintf("`%s`", $value);
		 }
		 $field_colums = implode(',', $field_arry_colums);

		 foreach ($all_columns as $key => $value) {
			if (!empty($$value)) {
			 $field_arry_values[] = sprintf("'%s'", $$value);
			} else {
			 $field_arry_values[] = 'NULL';
			}
		 }
		 $field_values = implode(',', $field_arry_values);

		 $sql = " INSERT INTO ";
		 $sql.= self::$table_name;
		 $sql.= ' ( ';
		 $sql.= $field_colums;
		 $sql.= ' ) ';
		 $sql.= 'VALUES';
		 $sql.= ' ( ';
		 $sql.= $field_values;
		 $sql.= ' ) ';

//		echo "<br/> sql is $sql";

		 $onhand_update_result = $db->query($sql);
		 if ($onhand_update_result) {
			$return_array['from_update_staus'] = 1;
		 } else {
			$return_array['from_update_staus'] = 0;
		 }
		}
	 }//complete of from sub inventory

	 if (!empty($to_subinventory_id)) {
		$to_onhand_sql = " SELECT onhand_id, onhand  FROM onhand";
		$to_onhand_sql .= " WHERE item_id = '{$item_id}' ";
		$to_onhand_sql .= " AND  	org_id = '{$org_id}' ";
		$to_onhand_sql .= " AND  	subinventory_id = '{$to_subinventory_id}' ";

		if (!empty($to_locator_id)) {
		 $to_onhand_sql .= " AND  	locator_id = '{$to_locator_id}' ";
		}

		$to_onhand_sql .= " LIMIT 1 ";
		$to_intial_onahand = 0;
		
		echo '<br><br>in onhand1';
		$to_onhand_result = $db->query($to_onhand_sql);
		if ($to_onhand_result && mysql_num_rows($to_onhand_result) > 0) {
		 echo '<br><br>in onhand2';
		 while ($row = $db->fetch_array($to_onhand_result)) {
			$to_intial_onahand = $row['onhand'];
			$onhand_id = $row['onhand_id'];
			$return_array['to_intial_onahnd'] = $to_intial_onahand;
		 }
		 $to_final_onhand = $to_intial_onahand + $quantity;
		 $return_array['to_final_onhand'] = $to_final_onhand;
		 $update_onhand_sql = "update onhand SET onhand = '{$to_final_onhand}' WHERE onhand_id='{$onhand_id}'  ";

		 $onhand_update_result = $db->query($update_onhand_sql);
		 if ($onhand_update_result) {
			$return_array['to_update_staus'] = 1;
		 } else {
			$return_array['to_update_staus'] = 0;
		 }
		} else {
		 echo '<br><br>in onhand3';
		 //insert THE NEW ONHAND RECORDS
		 $onhand = $to_intial_onahand + $quantity;
		 $reservable_onhand = $onhand;
		 $transactable_onhand = $onhand;
		 $subinventory_id = $to_subinventory_id;
		 $locator_id = $to_locator_id;
		 $time = time();
		 $creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
		 $last_update_date = $creation_date;
		 $created_by = $_SESSION['user_name'];
		 $last_update_by = $created_by;

		 $return_array['to_final_onhand'] = $onhand;

		 $all_columns = array();
		 $all_columns_sql = " SHOW COLUMNS FROM  " . self::$table_name;
		 $all_columns_result = $db->query($all_columns_sql);
		 if ($all_columns_result && mysql_num_rows($all_columns_result)) {
			while ($row = $db->fetch_array($all_columns_result)) {
			 array_push($all_columns, $row['Field']);
			}
		 }

		 foreach ($all_columns as $key => $value) {
			$field_arry_colums[] = sprintf("`%s`", $value);
		 }
		 $field_colums = implode(',', $field_arry_colums);

		 foreach ($all_columns as $key => $value) {
			if (!empty($$value)) {
			 $field_arry_values[] = sprintf("'%s'", $$value);
			} else {
			 $field_arry_values[] = 'NULL';
			}
		 }
		 $field_values = implode(',', $field_arry_values);

		 $sql = " INSERT INTO ";
		 $sql.= self::$table_name;
		 $sql.= ' ( ';
		 $sql.= $field_colums;
		 $sql.= ' ) ';
		 $sql.= 'VALUES';
		 $sql.= ' ( ';
		 $sql.= $field_values;
		 $sql.= ' ) ';

//		echo "<br/> sql is $sql";

		 $onhand_update_result = $db->query($sql);
		 if ($onhand_update_result) {
			$return_array['to_update_staus'] = 1;
		 } else {
			$return_array['to_update_staus'] = 0;
		 }
		}
	 }
	}

	return $return_array;
 }

 public static function onhand_page() {
	echo '<table class="normal"><thead><tr>';
	foreach (self::$field_array as $key => $value) {
	 echo '<th>' . $value . '</th>';
	}
	echo '</tr></thead><tbody>';

	$onhand = self::find_all();
//    echo '<pre>';
//    print_r($onhand);
//    echo '<pre>';
	foreach ($onhand as $record) {
	 echo '<tr>';
	 foreach (self::$field_array as $key => $value) {
		echo '<td>' . $record->$value . '</td>';
	 }
	 echo '</tr>';
	}
	echo ' </tbody> </table>';
 }

}

//end of onhand class
?>