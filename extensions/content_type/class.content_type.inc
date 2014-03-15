<?php

class content_type extends dbObject {

 protected static $table_name = "content_type";
 public static $primary_column = "content_type_id";
 public static $key_column = "content_type";
 public static $module = "extension";
 public $field_a = [
		 "content_type_id",
		 "allow_file_cb",
		 'allow_comment_cb',
		 "content_type",
		 "description",
		 "has_subject_cb",
		 "subject_label",
		 "has_content_cb",
		 "content_label",
		 'summary_display_type',
		 "rev_enabled_cb",
		 "rev_number",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//variables used for showing data

 public static $newField_array = [
		 "field_label",
		 "field_position",
		 "field_name",
		 "field_num",
		 "field_type",
		 "field_enum",
		 "option_type"
 ];
 
 public $initial_search = [
		 "content_type_id",
		 "content_type",
		 "description",
		 'summary_display_type'
 ];
 public $column = [
		 "content_type_id",
		 "allow_file_cb",
		 "content_type",
		 "description",
		 "subject_label",
		 "content_label",
		 'summary_display_type',
 ];
 public $checkbox = [
		 "allow_file_cb",
		 'allow_comment_cb',
		 "has_subject_cb",
		 "has_content_cb",
		 "rev_enabled_cb"
 ];
 public $fields_inForm_notInDataBase = [
   'field_num',
   'field_enum'
 ];
 public $fields_inHeader_needsToBeInserted_inPOST = [
 ];
 public $base_encoded_array = [];
 public $requiredField = [
		 "content_type",
		 "description"
 ];
 
 public $search = [
		 '_update_path' => 'extensions/content_type/content_type',
		 '_show_update_path' => 1,
		 '_show_view_path' => 1,
//		 '_view_action_meassge' => 'View',
//		 '_extra_path' => '',
 ];
 public $pageTitle = " Content Types - Find All Content Types "; //page Title
// public $option_list = [
//		 'calendar_option_line_code' => 'GL_CALENDAR_NAME',
//		 'currency_code' => 'CURRENCY'
// ];

 public $category_id;
 public $content_type_id;
 public $content_type;
 public $allow_comment_cb;
 public $allow_file_cb;
 public $description;
 public $has_subject_cb;
 public $has_content_cb;
 public $subject_label;
 public $content_label;
 public $summary_display_type;
 public $rev_enabled_cb;
 public $rev_number;
 public $content_type_id_l;
 public $field_label;
 public $field_position;
 public $field_name;
 public $field_num;
 public $field_enum;
 public $field_type;
 public $option_type;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 
  public function __set($name, $value) {
	$this->$name = $value;
 }

 Public static function summary_display_type() {
	$option_header = option_header::find_by_name('EXT_SUMMARY_DISPLAY_TYPE');
	$result = option_line::find_by_option_id($option_header->option_header_id);
	return $result;
 }

 Public static function content_field_type() {
	$option_header = option_header::find_by_name('EXT_CONTENT_FIELD_TYPE');
	$option_line = new option_line();
	$result = $option_line->findBy_parentId($option_header->option_header_id);
	return $result;
 }

 public function _after_save() {
	global $db;
	if ((!empty($_POST['field_name'])) && (count($_POST['field_name']) > 0)) {
	 for ($i = 0; $i < count($_POST['field_name']); $i++) {
//		print_r($_POST['field_num']);
		//create or update the new content type /table
		$content_type_id = $this->content_type_id;
		$field_record = new new_content_type;
		foreach (content_type::$newField_array as $key => $values) {
		 if (!empty($_POST[$values][$i])) {
			$field_record->$values = trim(mysql_prep($_POST[$values][$i]));
		 } else {
			$field_record->$values = "";
		 }
		}
		$enum_array = explode(",", $this->field_enum);
		$field_record->content_type = trim(mysql_prep($_POST['content_type'][0]));
//		echo "<div class='message>'<br>going for save table field $i </div>";
		$new_fild_entry = $field_record->save_table_field($enum_array);
//		echo "<div class='message>'<br>coming out of field $i </div>";
		if ($new_fild_entry) {
		 $newMsg = 'Record is sucessfully saved';
		}

		//create or update the field_reference_table
		$content_type_reference_record = new content_type_reference;
		foreach ($content_type_reference_record->field_a as $key => $values) {
		 if (!empty($_POST[$values][$i])) {
			$content_type_reference_record->$values = trim(mysql_prep($_POST[$values][$i]));
		 } else {
			$content_type_reference_record->$values = "";
		 }
		}
		
		if(!empty( $_POST['required_cb'])){
		if(in_array($content_type_reference_record->field_name, $_POST['required_cb'])){
		 $content_type_reference_record->required_cb = 1;
		}else{
		 $content_type_reference_record->required_cb = 0;
		}
		}
		$content_type_reference_record->content_type_id = $content_type_id;
		$content_type_reference_record->save();
//		echo "<div class='message>'<br>coming out after reference $i </div>";
	 }
	}
//	echo "<div class='message>'<br>going out of after save </div>";
 }

//
// public static function find_all() {
//	$sql = " SELECT * FROM " . self::$table_name;
//	$result = self::find_by_sql($sql);
//	return $result;
// }
//
// public static function count_all() {
//	global $db;
//	$sql = "SELECT COUNT(*) FROM " . self::$table_name;
//	$result_set = $db->query($sql);
//	$row = $db->fetch_array($result_set);
//	return array_shift($row);
// }
//
// public static function count_all_by_sql($sql) {
//	global $db;
//	$result_set = $db->query($sql);
//	$row = $db->fetch_array($result_set);
//	return array_shift($row);
// }
//
// public static function find_by_id($content_type_id) {
//	$sql = "SELECT * FROM " . self::$table_name . " where content_type_id={$content_type_id} LIMIT 1";
//	$result_array = self::find_by_sql($sql);
//	return !empty($result_array) ? array_shift($result_array) : false;
// }

 public static function find_by_content_type($content_type) {
	$sql = "SELECT * FROM " . self::$table_name . " where content_type='{$content_type}' LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

 public static function find_summary_by_id($content_type_id) {
	$selectFields = ' SUBSTRING(content,1,2000) AS content_summary , ' .
					implode(", ", self::$field_array);
	$sql = "SELECT " . $selectFields . " FROM "
					. self::$table_name . " 
            where content_type_id={$content_type_id} LIMIT 1";
	$result_array = self::find_by_sql($sql);
	return !empty($result_array) ? array_shift($result_array) : false;
 }

//
// public function save() {
//	if (empty($this->content_type_id)) {
//	 $this->create();
//	} else {
//	 $this->update($this->content_type_id);
//	}
//	return $this->msg;
// }
//
// public function create() {
//	global $db;
//
//	$field_arry_colums = array();
//	$field_arry_values = array();
//	foreach (self::$field_array as $key => $value) {
//	 $field_arry_colums[] = sprintf("`%s`", $value);
//	}
//	$field_colums = implode(',', $field_arry_colums);
//
//	foreach (self::$field_array as $key => $value) {
//	 if (!empty($this->$value)) {
//		$field_arry_values[] = sprintf("'%s'", $this->$value);
//	 } else {
//		$field_arry_values[] = 'NULL';
//	 }
//	}
//	$field_values = implode(',', $field_arry_values);
//
//	$sql = " INSERT INTO ";
//	$sql.= self::$table_name;
//	$sql.= ' ( ';
//	$sql.= $field_colums;
//	$sql.= ' ) ';
//	$sql.= 'VALUES';
//	$sql.= ' ( ';
//	$sql.= $field_values;
//	$sql.= ' ) ';
//
//	if ($db->query($sql)) {
//	 $this->content_type_id = $db->insert_id();
//	 $this->msg = 1;
//	} else {
//	 $this->msg = 0;
//	}
//	return $this->msg;
// }
//
// public function update($content_type_id) {
//	global $db;
//	$field_arry_values = array();
//
//	foreach (self::$field_array as $key => $value) {
//	 if (isset($this->$value)) {
//		$field_arry_values[] = sprintf("`%s` = '%s'", $value, $this->$value);
//	 }
//	}
//	$field_values = implode(',', $field_arry_values);
//
//	$time = time();
//	$last_update_date = strftime("%d-%m-%y %H:%M:%S", $time);
//	$last_update_by = $_SESSION['user_name'];
//
//	$sql = " UPDATE ";
//	$sql.= self::$table_name;
//	$sql .= " SET ";
//	$sql.= $field_values;
////    $sql.= "`last_update_date` = '{$last_update_date}'," ;
////    $sql.= "`last_update_by` = '{$last_update_by }'" ;
//	$sql.= " WHERE `content_type_id` = '{$content_type_id}' ";
//
//	if ($db->query($sql)) {
//	 $this->msg = 2;
//	} else {
//	 $this->msg = 0;
//	}
//	return $this->msg;
// }
//
// public static function delete($content_type_id) {
//	global $db;
//	$content_type_id = $db->escape_value($content_type_id);
//	$sql = "DELETE FROM " . self::$table_name . " WHERE `content_type_id` = '{$content_type_id}' ";
//
//	if ($db->query($sql)) {
//	 $msg = 1;
//	} else {
//	 $msg = 0;
//	}
//	return $msg;
// }

 public static function drop_column($content_name, $field_name) {
	global $dbc;
	$table_name = 'c_' . $content_name;
	$sql = "ALTER TABLE $table_name";
	$sql .=" DROP COLUMN $field_name";

	if ($dbc->ddlexecute($sql)) {
	 $msg = 1;
	} else {
	 $msg = 0;
	}
	return $msg;
 }

 public static function drop_table($content_name) {
	global $dbc;
	$table_name = 'c_' . $content_name;
	$sql = " DROP TABLE IF EXISTS $table_name";
	if ($dbc->ddlexecute($sql)) {
	 $msg = 1;
	} else {
	 $msg = 0;
	}

	if ($msg == 1) {
	 $content_type = self::find_by_content_type($content_name);
	 $result = self::delete($content_type->content_type_id);
	 if ($result == 1) {
		$msg = 11;
	 } else {
		$msg = 10;
	 }
	}


	if ($msg == 11) {
	 $ctype_path = new path();
	 $path = $ctype_path->find_by_namefind_by_name($content_name);
	 $result = $ctype_path->delete($path->path_id);
	 if ($result == 1) {
		$msg = 111;
	 } else {
		$msg = 110;
	 }
	}


	return $msg;
 }

 public static function content_type_content_type() {
	echo '<table class="normal"><thead><tr>';
	foreach (self::$field_array as $key => $value) {
	 echo '<th>' . $value . '</th>';
	}
	echo '</tr></thead><tbody>';

	$content_type = self::find_all();
//    echo '<pre>';
//    print_r($content_type);
//    echo '<pre>';
	foreach ($content_type as $record) {
	 echo '<tr>';
	 foreach (self::$field_array as $key => $value) {
		echo '<td>' . $record->$value . '</td>';
	 }
	 echo '</tr>';
	}
	echo ' </tbody> </table>';
 }

}

//end of content_type class
?>



