<?php

class enterprise extends org {

 protected static $table_name = "enterprise";
 public static $field_array = [
		 "enterprise_id",
		 "org_id",
		 "designation_option_header_id",
		 "type_option_header_id",
		 "efid",
		 "status",
		 "rev_enabled",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
 public static $initial_search_array = [
		 "enterprise_id",
		 "org_id",
		 "org",
		 "description"
 ];
 public static $checkbox_array = [
 ];
 public static $column_array = [
		 "enterprise_id",
		 "org_id",
		 "org",
		 "description"
 ];
 public static $base_encoded_array = [];
 public static $requiredField_array = [
		 "org_id",
 ];
 public static $primary_column = "enterprise_id";
 public $enterprise_id;
 public $org_id;
 public $designation_option_header_id;
 public $type_option_header_id;
 public $description;
 public $address_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;

// public static function find_by_sql($sql = "") {
//	global $db;
//	$result_set = $db->query($sql);
//	$object_array = array();
//	while ($row = $db->fetch_array($result_set)) {
//	 $object_array[] = self::instantiate($row);
//	}//end of while Loop
//	return $object_array;
// }
//
// public static function find_all() {
//	$sql = " SELECT * FROM " . self::$table_name;
//	$result = self::find_by_sql($sql);
//	return $result;
// }
//
// public static function find_by_id($enterprise_id) {
//	$sql = "SELECT * FROM " . self::$table_name . " where enterprise_id={$enterprise_id} LIMIT 1";
//	$result_array = self::find_by_sql($sql);
//	return !empty($result_array) ? array_shift($result_array) : false;
// }
//
// private static function instantiate($record) {
//	$object = new self;
//	foreach ($record as $attribute => $value) {
//	 if ($object->has_attribute($attribute)) {
//		$object->$attribute = $value;
//	 }
//	}
//	return $object;
// }
//
// Private function has_attribute($attribute) {
//	$object_vars = get_object_vars($this);
//	return array_key_exists($attribute, $object_vars);
// }
//
// public static function install() {
//	global $db;
//	$sql = "
//		 ";
//	$result = $db->query($sql);
//	return !empty($result) ? $result : false;
// }
//
// public function save() {
//	if (empty($this->enterprise_id)) {
//	 $this->create();
//	} else {
//	 $this->update($this->enterprise_id);
//	}
//	return $this->msg;
// }
//
// public function create() {
//	global $db;
//	$sql = "INSERT INTO enterprise (
//					  `enterprise_id`, 
//					  `created_by`, 
//					  `creation_date`, 
//					  `last_update_by`, 
//					  `last_update_date`) 
//  VALUES( NULL , '{$this->created_by}', '{$this->creation_date}', '{$this->created_by}', 
//		 '{$this->creation_date}' )";
//
//	if ($db->query($sql)) {
//	 $this->enterprise_id = $db->insert_id();
//	 $this->msg = 1;
//	} else {
//	 $this->msg = 0;
//	}
//	return $this->msg;
// }
//
////end of create enterprise
//
// public function update($enterprise_id) {
//	global $db;
//	$enterprise_id = $db->escape_value($this->enterprise_id);
//	$name = $db->escape_value($this->name);
//	$description = $db->escape_value($this->description);
//	$time = time();
//	$last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
//	$last_update_by = $_SESSION['user_name'];
//
//	$sql = " UPDATE `enterprise` SET 
//			`name` = '{$name}', 
//			`description` = '{$description}', 
//            `last_update_by`= '{$last_update_by}', 
//			`last_update_date`= '{$last_update_date}'
//			 WHERE `enterprise_id` = '{$enterprise_id}' ";
//
//	if ($db->query($sql)) {
//	 $this->msg = 1;
//	} else {
//	 $this->msg = 0;
//	}
//	return $this->msg;
// }
//
// public static function enterprise_page() {
//	echo '<table class="normal">
//                <thead> 
//                    <tr>
//                    <th>Enterprise Id</th>
//                    <th>Name</th>
//                    <th>Description</th>
//                    <th>Address Id</th>
//                    <th>Created By</th>
//                    <th>Creation Date</th>
//                    <th>Last Update By</th>
//                    <th>Last Update Date</th>
//                    <th>Action</th>
//                    </tr>
//                </thead>
//                <tbody>';
//
//	$enterprise = enterprise::find_all();
//	foreach ($enterprise as $record) {
//	 echo '<tr><td>' . $record->enterprise_id . '</td>';
//	 echo '<td>' . $record->name . '</td> ';
//	 echo '<td>' . $record->description . '</td>';
//	 echo '<td>' . $record->$address_id . '</td> ';
//	 echo '<td>' . $record->created_by . '</td>';
//	 echo '<td>' . $record->creation_date . '</td> ';
//	 echo '<td>' . $record->last_update_by . '</td>';
//	 echo '<td>' . $record->last_update_date . '</td>';
//	 echo '<td><a href="enterprise.php?enterprise_id=' . $record->enterprise_id . '">Update</a></td></tr>';
//	}
//
//	echo ' </tbody> </table>';
// }

}

//end of enterprise class
?>
