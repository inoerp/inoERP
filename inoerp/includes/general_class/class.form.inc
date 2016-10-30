<?php

class form {

 public static $table_name = "form";
 //  data base variables as stored database column name
 public static $field_array = [
		 "form_id",
		 "form",
		 "description",
		 "submit_button",
		 "action_link",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//variables used for showing data

 public static $checkbox_array = [
 ];
 public static $column_array = [
		 "form_id",
		 "form",
		 "description"
 ];
 public static $base_encoded_array = [
 ];
 public static $requiredField_array = [
		 "form",
		 "description"
 ];
 public static $primary_column = "form_id";
 public $form_id;
 public $form;
 public $description;
 public $coa_id;
 public $submit_button;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $current_page_path = "";

// public static $form_button_ul =<<<EOD
//			 <ul class="form_top">
//        <li><input type="button" class="button" id="refresh_button" value="*Refresh" name="refresh"/> </li>
//				<li><a class="button" id="new_object_button" href="$current_page_path">New *Object</a> </li> 
//				<li><input type="button" class="button add_row_img new_line" value="*New Line" name="new_line"/> </li>
//				<li><input type="button" class="button save" name="save" id="save" value="*Save"></li>
//				<li><input type="button" class="button delete" id="delete_button" name="delete_row" id="delete_row" value="*Delete"></li>
//        <li><input type="button" class="button remove_row" name="remove_row" id="remove_row_button" value="Re*move"></li>
//        <li><input type="reset" class="button reset" id="reset_button" name="reset" Value="Rese*t"></li>
//        <li><script>document.write('<a class="button go_back" id="go_back_button" href="' + document.referrer + '">Go *Back</a>');</script></li>
//			 </ul>
//EOD;
 public function __set($name, $value) {
	$this->$name = $value;
 }

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

 public static function find_by_id($form_id) {
	$sql = "SELECT * FROM " . self::$table_name . " where form_id={$form_id} ";
  $sql = ino_perPageSql_i($sql, 1);
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
	if (empty($this->form_id)) {
	 $this->create();
	} else {
	 $this->update($this->form_id);
	}
	return $this->msg;
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
	 $this->form_id = $db->insert_id();
	 $this->msg = 1;
	} else {
	 $this->msg = 0;
	}
	return $this->msg;
 }

 public function update($form_id) {
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
	$sql.= " WHERE `form_id` = '{$form_id}' ";

//    echo "<br/>$sql is <br/>" . $sql;

	if ($db->query($sql)) {
	 $this->msg = 2;
	} else {
	 $this->msg = 0;
	}
	return $this->msg;
 }

 public static function form_button($current_page_path = "") {
	echo <<<EOD
			 <ul class="form_top">
        <li><input type="button" class="button" id="refresh_button" value="*Refresh" name="refresh"/> </li>
				<li><a class="button" id="new_object_button" href="$current_page_path">New *Object</a> </li> 
				<li><input type="button" class="button add_row_img new_line" id="new_line" value="*New Line" name="new_line"/> </li>
				<li><input type="button" class="button save" name="save" id="save" value="*Save"></li>
				<li><input type="button" class="button delete" id="delete_button" name="delete_row" id="delete_row" value="*Delete"></li>
        <li><input type="button" class="button remove_row" name="remove_row" id="remove_row_button" value="Re*move"></li>
        <li><input type="reset" class="button reset" id="reset_button" name="reset" Value="Rese*t"></li>
        <li><script>document.write('<a class="button go_back" id="go_back_button" href="' + document.referrer + '">Go *Back</a>');</script></li>
        <li class="show_loading_small"></li>			 
</ul>
EOD;
 }

 public static function form_button_withImage($current_page_path = "", $homeUrl = '') {
	$home_url_wos = rtrim(HOME_URL, '/');
	$homeUrl = empty($homeUrl) ? $home_url_wos : $homeUrl;
	if (empty($current_page_path)) {
	 $current_page_path = thisPage_url();
	}
	echo <<<EOD
			 <ul id="form_top_image" class="draggable">
        <li class="show_loading_small"><img src="$homeUrl/themes/images/form/small_loading_bar.gif"></li>	
        <li><input type="button" class="button_image"  name="refresh"/>
				 <img src="$homeUrl/themes/images/form/refresh.png" id="refresh_button" alt="Refresh" Title="Refresh" class="showPointer"></li>
				<li><a id="new_object_button" href="$current_page_path">
				 <img src="$homeUrl/themes/images/form/new_object.png" alt="New Object" Title="New Object" class="showPointer"></a> </li> 
				<li><a id="new_page_button" href="$current_page_path">
				 <img src="$homeUrl/themes/images/form/new_line.png" alt="New Page" Title="New Page" class="showPointer"></a> </li> 
				<li><input type="button" class="button_image save" name="save" id="save_button">
				 <img src="$homeUrl/themes/images/form/save.png" id="save" alt="Save" Title="Save" class="showPointer"></li>
				<li><input type="button" class="button_image delete"  name="delete_row" id="delete_row">
				 <img src="$homeUrl/themes/images/form/delete.png" id="delete_button" alt="Delete" Title="Delete" class="showPointer"></li>
        <li><input type="button" class="button_image remove_row" name="remove_row" >
				 <img src="$homeUrl/themes/images/form/remove.png" id="remove_row_button" alt="Remove" Title="Remove" class="showPointer"></li>
        <li><input type="reset" class="button_image reset"  name="reset" Value="Rese*t">
				 <img src="$homeUrl/themes/images/form/reset.png" id="reset_button" alt="Reset" Title="Reset" class="showPointer"></li>
					<li><script>document.write('<a class="button_image go_back"  href="' + document.referrer + '"><img src="$homeUrl/themes/images/form/go_back.png"/ id="go_back_button" alt="Go Back" Title="Go Back" class="showPointer"></a>');</script></li>
</ul>
EOD;
 }

 public static function convert_id($id = "") {
	if (!empty($id)) {
	 $idvalue = 'id="' . $id . '"';
	} else {
	 $idvalue = "";
	}
	return $idvalue;
 }

 public static function hidden_field($name, $value) {
	$bracketName = $name . '[]';
	$value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	$element_hidden_field = "<input type=\"hidden\" name=\"$bracketName\" value=\"$value\" class=\"hidden $name\" >";
	return $element_hidden_field;
 }

 public static function hidden_field_withId($name, $value) {
	$bracketName = $name . '[]';
	$value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	$element_hidden_field = "<input type=\"hidden\" id=\"hidden_$name \" name=\"$bracketName\" value=\"$value\" class=\"hidden $name\" >";
	return $element_hidden_field;
 }

 public static function text_field($name, $value, $size = "15", $maxlength = "256", $required = "", $place_holder = "", $id = "", $readonly = "", $class_name = "", $title = "") {
	$bracketName = $name . '[]';
	$value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	if ($readonly == 1) {
	 $readonly = 'readonly';
	} else {
	 $readonly = '';
	}
	if ($required == 1) {
	 $required = 'required';
	} else {
	 $required = '';
	}
	if (!empty($id)) {
	 $idvalue = 'id="' . $id . '"';
	} else {
	 $idvalue = "";
	}
	$element_text_field = "<input type=\"text\" name=\"$bracketName\" value=\"$value\" 
	 maxlength=\"$maxlength\" size=\"$size\" class=\"textfield $class_name $name\" "
					. "placeholder=\"$place_holder\"  $required $idvalue $readonly title=\"$title\" >";
	return $element_text_field;
 }

 public static function text_field_ap($array) {
	$name = array_key_exists('name', $array) ? $array['name'] : null;
	$value = array_key_exists('value', $array) ? $array['value'] : null;
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	$size = array_key_exists('size', $array) ? $array['size'] : null;
	$maxlength = array_key_exists('maxlength', $array) ? $array['maxlength'] : null;
	$required = array_key_exists('required', $array) ? $array['required'] : null;
	$place_holder = array_key_exists('place_holder', $array) ? $array['place_holder'] : null;
	$id = array_key_exists('id', $array) ? $array['id'] : null;
	$readonly = array_key_exists('readonly', $array) ? $array['readonly'] : null;
	$class_name = array_key_exists('class_name', $array) ? $array['class_name'] : null;
	$title = array_key_exists('title', $array) ? $array['title'] : null;

	$bracketName = $name . '[]';
	if ($readonly == 1) {
	 $readonly = 'readonly';
	} else {
	 $readonly = '';
	}
	if ($required == 1) {
	 $required = 'required';
	} else {
	 $required = '';
	}
	if (!empty($id)) {
	 $idvalue = 'id="' . $id . '"';
	} else {
	 $idvalue = "";
	}
	$element_text_field = "<input type=\"text\" name=\"$bracketName\" value=\"$value\" 
	 maxlength=\"$maxlength\" size=\"$size\" class=\"textfield $class_name $name\" "
					. "placeholder=\"$place_holder\"  $required $idvalue $readonly title=\"$title\" >";
	return $element_text_field;
 }

 public static function number_field($name, $value, $size = "15", $min = "", $max = "", $required = "", $place_holder = "", $id = "", $readonly = "", $divClass = "") {
	$bracketName = $name . '[]';
	$valueAfterDecimal = ino_showDecimal(htmlentities($value));
//	echo "$value : $valueAfterDecimal";
  $valueAfterDecimal = htmlentities($valueAfterDecimal, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  

	if ($readonly == 1) {
	 $readonly = 'readonly';
	} else {
	 $readonly = '';
	}
	if ($required == 1) {
	 $required = 'required';
	} else {
	 $required = '';
	}
	if (!empty($id)) {
	 $idvalue = 'id="' . $id . '"';
	} else {
	 $idvalue = "";
	}
	$element_text_field = "<input type=\"text\" name=\"$bracketName\" value=\"$valueAfterDecimal\"  size=\"$size\"
	 class=\"number $divClass $name\" placeholder=\"$place_holder\" "
					. "pattern=\"[0-9]+([\.][0-9]+)?\"  $required $idvalue $readonly>";
	return $element_text_field;
 }

//d - default , r- readonly, s- small size, m - mandatory
 public static function text_field_d($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '20', '', '', '', $field_name, $readonly);
 }

 public static function text_field_dm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '20', '', 1, '', $field_name, $readonly);
 }

 public static function text_field_ds($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '8', '', '', '', $field_name, '');
 }

 public static function text_field_dl($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '40', '', '', '', $field_name, '');
 }

 public static function text_field_dsr($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '8', '', '', '', $field_name, 1);
 }

 public static function text_field_dsrm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '8', '', 1, '', $field_name, 1);
 }

 public static function text_field_dr($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '20', '', '', '', $field_name, 1);
 }

 public static function text_field_drm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '20', '', 1, '', $field_name, 1);
 }

 public static function text_field_d2($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '20', '', '', '', $field_name, $readonly);
 }

 public static function text_field_d2m($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '20', '', 1, '', $field_name, $readonly);
 }

 public static function text_field_d2r($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '20', '', '', '', $field_name, 1);
 }

 public static function text_field_d2rm($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '20', '', 1, '', $field_name, 1);
 }

 public static function text_field_d3($field_name) {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '20', '', '', '', $field_name, $readonly);
 }

 public static function text_field_d3r($field_name) {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '20', '', '', '', $field_name, 1);
 }

 public static function text_field_d3m($field_name) {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '20', '', 1, '', $field_name, $readonly);
 }

 public static function text_field_d4($field_name) {
	global $class_four, $$class_four, $readonly;
	echo self::text_field($field_name, $$class_four->$field_name, '20', '', '', '', $field_name, $readonly);
 }

 public static function text_field_d4r($field_name) {
	global $class_four, $$class_four, $readonly;
	echo self::text_field($field_name, $$class_four->$field_name, '20', '', '', '', $field_name, 1);
 }

 public static function text_field_d4m($field_name) {
	global $class_four, $$class_four, $readonly;
	echo self::text_field($field_name, $$class_four->$field_name, '20', '', 1, '', $field_name, $readonly);
 }

 public static function text_field_wid($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '20', '', '', '', '', $readonly);
 }

 public static function text_field_widm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '20', '', 1, '', '', $readonly);
 }

 public static function text_field_widr($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '20', '', '', '', '', 1);
 }

 public static function text_field_widrm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '20', '', 1, '', '', 1);
 }

 public static function text_field_wids($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '7', '', '', '', '', $readonly);
 }

 public static function text_field_widsm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '7', '', 1, '', '', $readonly);
 }

 public static function text_field_widsr($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '8', '', '', '', '', 1);
 }

 public static function text_field_widsrm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '8', '', 1, '', '', 1);
 }

 public static function text_field_wid2($field_name, $class_name="") {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '20', '255', '', '', '', $readonly, $class_name);
 }

 public static function text_field_wid2m($field_name, $class_name="") {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '20', '', 1, '', '', $readonly, $class_name);
 }

 public static function text_field_wid2r($field_name, $class_name="") {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '20', '', '', '', '', 1, $class_name);
 }

 public static function text_field_wid2s($field_name, $class_name="") {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '8', '255', '', '', '', $readonly, $class_name);
 }

 public static function text_field_wid2l($field_name, $class_name="") {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '40', '', '', '', '', $readonly, $class_name);
 }

 public static function text_field_wid2sm($field_name, $class_name="") {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '8', '', 1, '', '', $readonly, $class_name);
 }

 public static function text_field_wid2sr($field_name, $class_name="") {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '8', '', '', '', '', 1, $class_name);
 }

 public static function text_field_wid2lr($field_name, $class_name="") {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '40', '', '', '', '', 1, $class_name);
 }

 public static function text_field_wid3s($field_name, $class_name="") {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '8', '', '', '', '', $readonly, $class_name);
 }

 public static function text_field_wid3sm($field_name, $class_name="") {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '8', '', 1, '', '', $readonly, $class_name);
 }

 public static function text_field_wid3sr($field_name, $class_name="") {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '8', '', '', '', '', 1, $class_name);
 }

 public static function text_field_wid3($field_name, $class_name="") {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '20', '', '', '', '', $readonly, $class_name);
 }

 public static function text_field_wid3m($field_name, $class_name="") {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '20', '', 1, '', '', $readonly, $class_name);
 }

 public static function text_field_wid3r($field_name, $class_name="") {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '20', '', '', '', '', 1, $class_name);
 }

 public static function text_field_wid4s($field_name) {
	global $class_fourth, $$class_fourth, $readonly;
	echo self::text_field($field_name, $$class_fourth->$field_name, '8', '', '', '', '', $readonly);
 }

 public static function text_field_wid4sm($field_name) {
	global $class_fourth, $$class_fourth, $readonly;
	echo self::text_field($field_name, $$class_fourth->$field_name, '8', '', 1, '', '', $readonly);
 }

 public static function text_field_wid4sr($field_name) {
	global $class_fourth, $$class_fourth, $readonly;
	echo self::text_field($field_name, $$class_fourth->$field_name, '8', '', '', '', '', 1);
 }

 public static function text_field_wid4($field_name) {
	global $class_fourth, $$class_fourth, $readonly;
	echo self::text_field($field_name, $$class_fourth->$field_name, '20', '', '', '', '', $readonly);
 }

 public static function text_field_wid4m($field_name) {
	global $class_fourth, $$class_fourth, $readonly;
	echo self::text_field($field_name, $$class_fourth->$field_name, '20', '', 1, '', '', $readonly);
 }

 public static function text_field_wid4r($field_name) {
	global $class_fourth, $$class_fourth, $readonly;
	echo self::text_field($field_name, $$class_fourth->$field_name, '20', '', '', '', '', 1);
 }

 public static function number_field_d($field_name, $divClass = "") {
	global $readonly, $class, $$class;
	echo self::number_field($field_name, $$class->$field_name, '', '', '', '', '', $field_name, $readonly, $divClass);
 }

 public static function number_field_ds($field_name, $divClass = "") {
	global $readonly, $class, $$class;
	echo self::number_field($field_name, $$class->$field_name, '8', '', '', '', '', $field_name, $readonly, $divClass);
 }

 public static function number_field_dr($field_name, $divClass = "") {
	global $readonly, $class, $$class;
	echo self::number_field($field_name, $$class->$field_name, '', '', '', '', '', $field_name, 1, $divClass);
 }

 public static function number_field_drs($field_name, $divClass = "") {
	global $readonly, $class, $$class;
	echo self::number_field($field_name, $$class->$field_name, '8', '', '', '', '', $field_name, 1, $divClass);
 }

 public static function number_field_dm($field_name, $divClass = "") {
	global $readonly, $class, $$class;
	echo self::number_field($field_name, $$class->$field_name, '', '', '', 1, '', $field_name, $readonly, $divClass);
 }

 public static function number_field_drsm($field_name, $divClass = "") {
	global $readonly, $class, $$class;
	echo self::number_field($field_name, $$class->$field_name, '8', '', '', 1, '', $field_name, 1, $divClass);
 }

 public static function number_field_d2($field_name, $divClass = "") {
	global $class_second, $$class_second, $readonly;
	echo self::number_field($field_name, $$class_second->$field_name, '', '', '', '', '', '', $readonly, $divClass);
 }

 public static function number_field_d2m($field_name, $divClass = "") {
	global $class_second, $$class_second, $readonly;
	echo self::number_field($field_name, $$class_second->$field_name, '', '', '', 1, '', '', $readonly, $divClass);
 }

 public static function number_field_d2s($field_name, $divClass = "") {
	global $class_second, $$class_second, $readonly;
	echo self::number_field($field_name, $$class_second->$field_name, '8', '', '', '', '', '', $readonly, $divClass);
 }

 public static function number_field_d2sm($field_name, $divClass = "") {
	global $class_second, $$class_second, $readonly;
	echo self::number_field($field_name, $$class_second->$field_name, '8', '', '', 1, '', '', $readonly, $divClass);
 }

 public static function number_field_d2sr($field_name, $divClass = "") {
	global $class_second, $$class_second, $readonly;
	echo self::number_field($field_name, $$class_second->$field_name, '8', '', '', '', '', '', 1, $divClass);
 }

 public static function number_field_wid($field_name, $divClass = "") {
	global $readonly, $class, $$class;
	echo self::number_field($field_name, $$class->$field_name, '', '', '', '', '', '', $readonly, $divClass);
 }

 public static function number_field_wids($field_name, $divClass = "") {
	global $readonly, $class, $$class;
	echo self::number_field($field_name, $$class->$field_name, '8', '', '', '', '', '', $readonly, $divClass);
 }

 public static function number_field_widsm($field_name, $divClass = "") {
	global $readonly, $class, $$class;
	echo self::number_field($field_name, $$class->$field_name, '8', '', '', 1, '', '', $readonly, $divClass);
 }

 public static function number_field_widsr($field_name, $divClass = "") {
	global $readonly, $class, $$class;
	echo self::number_field($field_name, $$class->$field_name, '8', '', '', '', '', '', 1, $divClass);
 }

 public static function number_field_widsrm($field_name, $divClass = "") {
	global $readonly, $class, $$class;
	echo self::number_field($field_name, $$class->$field_name, '8', '', '', 1, '', '', 1, $divClass);
 }

 public static function number_field_wid2($field_name, $divClass = "") {
	global $class_second, $$class_second, $readonly;
	echo self::number_field($field_name, $$class_second->$field_name, '', '', '', '', '', '', $readonly, $divClass);
 }

 public static function number_field_wid2m($field_name, $divClass = "") {
	global $class_second, $$class_second, $readonly;
	echo self::number_field($field_name, $$class_second->$field_name, '', '', '', 1, '', '', $readonly, $divClass);
 }

 public static function number_field_wid2s($field_name, $divClass = "") {
	global $class_second, $$class_second, $readonly;
	echo self::number_field($field_name, $$class_second->$field_name, '8', '', '', '', '', '', $readonly, $divClass);
 }

 public static function number_field_wid2sm($field_name, $divClass = "") {
	global $class_second, $$class_second, $readonly;
	echo self::number_field($field_name, $$class_second->$field_name, '8', '', '', 1, '', '', $readonly, $divClass);
 }

 public static function number_field_wid2sr($field_name, $divClass = "") {
	global $class_second, $$class_second, $readonly;
	echo self::number_field($field_name, $$class_second->$field_name, '6', '', '', '', '', '', 1, $divClass);
 }

 public static function number_field_wid2srm($field_name, $divClass = "") {
	global $class_second, $$class_second, $readonly;
	echo self::number_field($field_name, $$class_second->$field_name, '8', '', '', 1, '', '', 1, $divClass);
 }

 public static function number_field_wid3($field_name, $divClass = "") {
	global $class_third, $$class_third, $readonly;
	echo self::number_field($field_name, $$class_third->$field_name, '', '', '', '', '', '', $readonly, $divClass);
 }

 public static function number_field_wid3s($field_name, $divClass = "") {
	global $class_third, $$class_third, $readonly;
	echo self::number_field($field_name, $$class_third->$field_name, '8', '', '', '', '', '', $readonly, $divClass);
 }

 public static function number_field_wid3sm($field_name, $divClass = "") {
	global $class_third, $$class_third, $readonly;
	echo self::number_field($field_name, $$class_third->$field_name, '8', '', '', 1, '', '', $readonly, $divClass);
 }

 public static function number_field_wid3sr($field_name, $divClass = "") {
	global $class_third, $$class_third, $readonly;
	echo self::number_field($field_name, $$class_third->$field_name, '8', '', '', '', '', '', 1, $divClass);
 }

 public static function number_field_wid4($field_name, $divClass = "") {
	global $class_fourth, $$class_fourth, $readonly;
	echo self::number_field($field_name, $$class_fourth->$field_name, '', '', '', '', '', '', $readonly, $divClass);
 }

 public static function number_field_wid4m($field_name, $divClass = "") {
	global $class_fourth, $$class_fourth, $readonly;
	echo self::number_field($field_name, $$class_fourth->$field_name, '', '', '', 1, '', '', $readonly, $divClass);
 }

 public static function number_field_wid4s($field_name, $divClass = "") {
	global $class_fourth, $$class_fourth, $readonly;
	echo self::number_field($field_name, $$class_fourth->$field_name, '8', '', '', '', '', '', $readonly, $divClass);
 }

 public static function number_field_wid4sm($field_name, $divClass = "") {
	global $class_fourth, $$class_fourth, $readonly;
	echo self::number_field($field_name, $$class_fourth->$field_name, '8', '', '', 1, '', '', $readonly, $divClass);
 }

 public static function number_field_wid4sr($field_name, $divClass = "") {
	global $class_fourth, $$class_fourth, $readonly;
	echo self::number_field($field_name, $$class_fourth->$field_name, '8', '', '', '', '', '', 1, $divClass);
 }

 //account fields
 public static function accpup_stmt() {
	return "<img src=\"" . HOME_URL . "/themes/images/serach.png\" class=\"account_popup\" >";
 }

 public static function ac_field_d($field_name) {
	global $readonly, $class, $$class;
	if(!empty($$class->$field_name)){
	 $value = coa_combination::find_by_id($$class->$field_name)->combination;
	}else{
	 $value = null;
	}
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	echo self::text_field($field_name, $value, '30', '', '', '', $field_name, $readonly, 'select_account');
	echo self::accpup_stmt();
 }

 public static function ac_field_dm($field_name) {
	global $readonly, $class, $$class;
		if(!empty($$class->$field_name)){
	 $value = coa_combination::find_by_id($$class->$field_name)->combination;
	}else{
	 $value = null;
	}
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	echo self::text_field($field_name, $value, '30', '', 1, '', $field_name, $readonly, 'select_account');
	echo self::accpup_stmt();
 }

  public static function ac_field_dr($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '30', '', '', '', $field_name, 1, 'select_account');
	echo self::accpup_stmt();
 }

 public static function ac_field_drm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '30', '', 1, '', $field_name, 1, 'select_account');
	echo self::accpup_stmt();
 }

 public static function ac_field_d2($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '30', '', '', '', $field_name, $readonly, 'select_account');
	echo self::accpup_stmt();
 }

 public static function ac_field_d2m($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '30', '', 1, '', $field_name, $readonly, 'select_account');
	echo self::accpup_stmt();
 }

 public static function ac_field_d2r($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '30', '', '', '', $field_name, 1, 'select_account');
	echo self::accpup_stmt();
 }

 public static function ac_field_d2rm($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '30', '', 1, '', $field_name, 1, 'select_account');
	echo self::accpup_stmt();
 }

 public static function ac_field_d3($field_name) {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '30', '', '', '', $field_name, $readonly, 'select_account');
	echo self::accpup_stmt();
 }

 public static function ac_field_d3r($field_name) {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '30', '', '', '', $field_name, 1, 'select_account');
	echo self::accpup_stmt();
 }

 public static function ac_field_d3m($field_name) {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '30', '', 1, '', $field_name, $readonly, 'select_account');
	echo self::accpup_stmt();
 }

 public static function ac_field_d4($field_name) {
	global $class_four, $$class_four, $readonly;
	echo self::text_field($field_name, $$class_four->$field_name, '30', '', '', '', $field_name, $readonly, 'select_account');
 }

 public static function ac_field_d4r($field_name) {
	global $class_four, $$class_four, $readonly;
	echo self::text_field($field_name, $$class_four->$field_name, '30', '', '', '', $field_name, 1, 'select_account');
 }

 public static function ac_field_d4m($field_name) {
	global $class_four, $$class_four, $readonly;
	echo self::text_field($field_name, $$class_four->$field_name, '30', '', 1, '', $field_name, $readonly, 'select_account');
 }

 public static function ac_field_wid($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '30', '', '', '', '', $readonly, 'select_account');
 }

 public static function ac_field_widm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '30', '', 1, '', '', $readonly, 'select_account');
 }

 public static function ac_field_widr($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '30', '', '', '', '', 1, 'select_account');
 }

 public static function ac_field_widrm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '30', '', 1, '', '', 1, 'select_account');
 }

 public static function ac_field_wids($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '7', '', '', '', '', $readonly, 'select_account');
 }

 public static function ac_field_widsm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '7', '', 1, '', '', $readonly, 'select_account');
 }

 public static function ac_field_widsr($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '8', '', '', '', '', 1, 'select_account');
 }

 public static function ac_field_widsrm($field_name) {
	global $readonly, $class, $$class;
	echo self::text_field($field_name, $$class->$field_name, '8', '', 1, '', '', 1, 'select_account');
 }

 public static function ac_field_wid2($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '30', '', '', '', '', $readonly, 'select_account');
 }

 public static function ac_field_wid2m($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '30', '', 1, '', '', $readonly, 'select_account');
 }

 public static function ac_field_wid2r($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '30', '', '', '', '', 1, 'select_account');
 }

 public static function ac_field_wid2s($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '8', '', '', '', '', $readonly, 'select_account');
 }

 public static function ac_field_wid2sm($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '8', '', 1, '', '', $readonly, 'select_account');
 }

 public static function ac_field_wid2sr($field_name) {
	global $class_second, $$class_second, $readonly;
	echo self::text_field($field_name, $$class_second->$field_name, '8', '', '', '', '', 1, 'select_account');
 }

 public static function ac_field_wid3s($field_name) {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '8', '', '', '', '', $readonly, 'select_account');
 }

 public static function ac_field_wid3sm($field_name) {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '8', '', 1, '', '', $readonly, 'select_account');
 }

 public static function ac_field_wid3sr($field_name) {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '8', '', '', '', '', 1, 'select_account');
 }

 public static function ac_field_wid3($field_name) {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '30', '', '', '', '', $readonly, 'select_account');
 }

 public static function ac_field_wid3m($field_name) {
	global $class_third, $$class_third, $readonly;
	$value = coa_combination::find_by_id($$class_third->$field_name)->combination;
	$title = "Enter atleast 3 numbers from coa for auto list or click on the find button to select";
	echo self::text_field($field_name, $value, '30', '', 1, '', '', $readonly, 'select_account', $title);
 }

 public static function ac_field_wid3r($field_name) {
	global $class_third, $$class_third, $readonly;
	echo self::text_field($field_name, $$class_third->$field_name, '30', '', '', '', '', 1, 'select_account');
 }

 //remove below account fields
 public static function account_field($account_name, $all_code_combinations = "") {
	if (empty($all_code_combinations)) {
	 $coa_id = 7;
	 $all_code_combinations = coa_combination::find_all_from_coa($coa_id);
	}
	global $class, $$class, $readonly;
	$divClass = 'account ' . $account_name;
	echo form::select_field_from_object($account_name, $all_code_combinations, 'coa_combination_id', 'combination', $$class->$account_name, '', $readonly, $divClass);
 }

 public static function account_field_m($account_name, $all_code_combinations = "") {
	if (empty($all_code_combinations)) {
	 $coa_id = 7;
	 $all_code_combinations = coa_combination::find_all_from_coa($coa_id);
	}
	global $class, $$class, $readonly;
	$divClass = 'account ' . $account_name;
	echo form::select_field_from_object($account_name, $all_code_combinations, 'coa_combination_id', 'combination', $$class->$account_name, '', $readonly, $divClass, '', 1);
 }

 public static function account_field2($account_name, $all_code_combinations = "") {
	if (empty($all_code_combinations)) {
	 $coa_id = 7;
	 $all_code_combinations = coa_combination::find_all_from_coa($coa_id);
	}
	global $class_second, $$class_second, $readonly;
	$divClass = 'account ' . $account_name;
	echo form::select_field_from_object($account_name, $all_code_combinations, 'coa_combination_id', 'combination', $$class_second->$account_name, '', $readonly, $divClass);
 }

 public static function account_field2_m($account_name, $all_code_combinations = "") {
	if (empty($all_code_combinations)) {
	 $coa_id = 7;
	 $all_code_combinations = coa_combination::find_all_from_coa($coa_id);
	}
	global $class_second, $$class_second, $readonly;
	$divClass = 'account ' . $account_name;
	echo form::select_field_from_object($account_name, $all_code_combinations, 'coa_combination_id', 'combination', $$class_second->$account_name, '', $readonly, $divClass, '', 1);
 }

 public static function account_field3($account_name, $all_code_combinations = "") {
	if (empty($all_code_combinations)) {
	 $coa_id = 7;
	 $all_code_combinations = coa_combination::find_all_from_coa($coa_id);
	}
	global $class_third, $$class_third, $readonly;
	$divClass = 'account ' . $account_name;
	echo form::select_field_from_object($account_name, $all_code_combinations, 'coa_combination_id', 'combination', $$class_third->$account_name, '', $readonly, $divClass);
 }

 public static function account_field3_m($account_name, $all_code_combinations = "") {
	if (empty($all_code_combinations)) {
	 $coa_id = 7;
	 $all_code_combinations = coa_combination::find_all_from_coa($coa_id);
	}
	global $class_third, $$class_third, $readonly;
	$divClass = 'account ' . $account_name;
	echo form::select_field_from_object($account_name, $all_code_combinations, 'coa_combination_id', 'combination', $$class_third->$account_name, '', $readonly, $divClass, '', 1);
 }

 public static function text_area($name, $value, $rowsize = "5", $columnsize = "20", $required = "", $place_holder = "", $id = "", $readonly = "") {
	$bracketName = $name . '[]';
//	$value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	if ($readonly == 1) {
	 $readonly = 'readonly';
	} else {
	 $readonly = '';
	}
	if ($required == 1) {
	 $required = 'required';
	} else {
	 $required = '';
	}
	if (!empty($id)) {
	 $idvalue = 'id="' . $id . '"';
	} else {
	 $idvalue = "";
	}
	$element_text_field = "<textarea name=\"$bracketName\" 
	 cols=\"$columnsize\" rows=\"$rowsize\" class=\"textfield $name\" placeholder=\"$place_holder\" $required $idvalue $readonly> ".  ($value)." </textarea>";
	return $element_text_field;
 }

 public static function date_field($name, $value, $required = "", $class = "", $id = "", $readonly = "") {
	if ($readonly == 1) {
	 $readonly = 'disabled';
	} else {
	 $readonly = '';
	}

	if ($required == 1) {
	 $required = 'required';
	} else {
	 $required = '';
	}

	$bracketName = $name . '[]';
	$value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	if (!empty($id)) {
	 $idvalue = 'id="' . $id . '"';
	} else {
	 $idvalue = "";
	}
	$element_date_field = "<input type=\"text\" name=\"$bracketName\" value=\"$value\" 	class=\"$class $name\"  $required $readonly $idvalue>";
	return $element_date_field;
 }

 public static function date_fieldFromToday($name, $value, $required = "", $class = "dateFromToday", $id = "", $readonly = "") {
	$element_date_field = self::date_field($name, $value, $required, $class, $id, $readonly);
	return $element_date_field;
 }

 public static function date_fieldFromToday_m($name, $value, $required = "", $class = "dateFromToday", $id = "", $readonly = "") {
	$element_date_field = self::date_field($name, $value, $required, $class, $id, $readonly);
	return $element_date_field;
 }

 public static function date_fieldAnyDay($name, $value, $required = "", $class = "anyDate", $id = "", $readonly = "") {
	$element_date_field = self::date_field($name, $value, $required, $class, $id, $readonly);
	return $element_date_field;
 }

 public static function date_fieldAnyDay_m($name, $value, $required = "", $class = "anyDate", $id = "", $readonly = "") {
	$element_date_field = self::date_field($name, $value, $required, $class, $id, $readonly);
	return $element_date_field;
 }

 public static function select_field_from_array($name, $array, $value, $id = "", $readonly = "") {
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	if ($readonly == 1) {
	 $readonly = 'disabled';
	} else {
	 $readonly = '';
	}

	$bracketName = $name . '[]';
	$idvalue = self::convert_id($id);
	$element_select_field = "<Select name=\"$bracketName\" class=\"from_array select\" $idvalue $readonly >";
	$element_select_field .= "<option value=\"\" ></option>";
	foreach ($array as $key => $arraValue) {
	 if ($key == $value) {
		$selected = 'selected';
	 } else {
		$selected = '';
	 }
	 $element_select_field .= '<option value="' . $key . '" ';
	 $element_select_field .= $selected;
	 $element_select_field .= '>' . $arraValue . '</option>';
	}
	$element_select_field .= '</select>';

	return $element_select_field;
 }

 public static function select_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value = "", $id = "", $readonly = "", $divClass = "", $convertToText = "", $required = "", $nonArrayName = "", $disabled = "") {
	$value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
  if ($nonArrayName == 1) {
	 $bracketName = $name;
	} else {
	 $bracketName = $name . '[]';
	}
	$idvalue = self::convert_id($id);
	if ($readonly == 1) {
	 $readonly = 'disabled';
	} else {
	 $readonly = '';
	}

	if ($required == 1) {
	 $required = 'required';
	} else {
	 $required = '';
	}

	if ($disabled == 1) {
	 $disabled = 'disbaled';
	} else {
	 $disabled = '';
	}
	$element_select_field = "<Select name=\"$bracketName\" class=\"select $divClass $name\" $idvalue $readonly $required $disabled>";
	$element_select_field .= "<option value=\"\" ></option>";
	if ((is_array($object)) && (count($object) > 0 )) {
	 foreach ($object as $record) {
		if ((!empty($value)) && ($record->$objectValueKey == $value)) {
		 $selected = 'selected';
		} else {
		 $selected = '';
		}
		$element_select_field .= '<option value="' . $record->$objectValueKey . '" ';
		$element_select_field .= $selected;
		$element_select_field .= '>';
		if (is_array($objectDescriptionKey)) {
		 $newValue1 = '';
		 foreach ($objectDescriptionKey as $keya => $valuea) {
			$newValue1 .= $record->$valuea . ' - ';
		 }
		 $newValue = rtrim($newValue1, ' - ');
		} else {
		 $newValue = $record->$objectDescriptionKey;
		}
		$element_select_field .= $newValue;
		$element_select_field .= '</option>';
	 }
	}

	if ($convertToText == 1) {
	 $element_select_field .= "<option value=\"newentry\"  class=\"bold blue\">New Entry</option>";
	}
	$element_select_field .= '</select>';

	return $element_select_field;
 }

 public static function select_field_from_object_ap($array) {
	$name = array_key_exists('name', $array) ? $array['name'] : null;
	$ob = array_key_exists('ob', $array) ? $array['ob'] : null;
	$ob_value = array_key_exists('ob_value', $array) ? $array['ob_value'] : null;
	$ob_desc = array_key_exists('ob_desc', $array) ? $array['ob_desc'] : null;
	$value = array_key_exists('value', $array) ? $array['value'] : null;
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	$id = array_key_exists('id', $array) ? $array['id'] : null;
	$readonly = array_key_exists('readonly', $array) ? $array['readonly'] : null;
	$divClass = array_key_exists('divClass', $array) ? $array['divClass'] : null;
	$convertToText = array_key_exists('convertToText', $array) ? $array['convertToText'] : null;
	$required = array_key_exists('required', $array) ? $array['required'] : null;
	$nonArrayName = array_key_exists('nonArrayName', $array) ? $array['nonArrayName'] : null;
	$disabled = array_key_exists('disabled', $array) ? $array['disabled'] : null;

	if ($nonArrayName == 1) {
	 $bracketName = $name;
	} else {
	 $bracketName = $name . '[]';
	}
	$idvalue = self::convert_id($id);
	if ($readonly == 1) {
	 $readonly = 'disabled';
	} else {
	 $readonly = '';
	}

	if ($required == 1) {
	 $required = 'required';
	} else {
	 $required = '';
	}

	if ($disabled == 1) {
	 $disabled = 'disabled';
	} else {
	 $disabled = null;
	}

	$element_select_field = "<Select name=\"$bracketName\" class=\" select $divClass $name  \" $idvalue $readonly $required $disabled>";
	$element_select_field .= "<option value=\"\" ></option>";
	if ((is_array($ob)) && (count($ob) > 0 )) {
	 foreach ($ob as $record) {
		if ((!empty($value)) && ($record->$ob_value == $value)) {
		 $selected = 'selected';
		} else {
		 $selected = '';
		}
		$element_select_field .= '<option value="' . $record->$ob_value . '" ';
		$element_select_field .= $selected;
		$element_select_field .= '>';
		if (is_array($ob_desc)) {
		 $newValue1 = '';
		 foreach ($ob_desc as $keya => $valuea) {
			$newValue1 .= $record->$valuea . ' - ';
		 }
		 $newValue = rtrim($newValue1, ' - ');
		} else {
		 $newValue = $record->$ob_desc;
		}
		$element_select_field .= $newValue;
		$element_select_field .= '</option>';
	 }
	}

	if ($convertToText == 1) {
	 $element_select_field .= "<option value=\"newentry\"  class=\"bold blue\">New Entry</option>";
	}
	$element_select_field .= '</select>';

	return $element_select_field;
 }

 public static function extra_field($value, $size = '6', $readonly = "") {
	if ($readonly == 1) {
	 $readonly = 'readonly';
	} else {
	 $readonly = '';
	}
	$value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	$element_extra_field = "<input type=\"text\" name=\"efid[]\" value=\"$value\" maxlength=\"200\" 
										size=\"$size\" class=\"efid\" $readonly \>";
	return $element_extra_field;
 }

 public static function checkBox_field($name, $value, $id = "", $readonly = "") {
  $value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	$bracketName = $name . '[]';
	if ($readonly == 1) {
	 $readonly = 'onclick="return false"';
	} else {
	 $readonly = '';
	}
	if ($value == 1) {
	 $checked = "checked";
	} else {
	 $checked = "";
	}
	if(!empty($id)){
	 $id_stmt = 'id="'.$id.'"';
	}else{
	 $id_stmt = null;
	}

	$element_extra_field = "<input type=\"checkbox\" name=\"$bracketName\"  class=\"checkBox $name\" $id_stmt 
	 value=\"1\"  $checked $readonly>";
	return $element_extra_field;
 }

 public static function checkBox_field_d($field_name) {
	global $readonly, $class, $$class;
	echo self::checkBox_field($field_name, $$class->$field_name, $field_name, $readonly);
 }

 public static function checkBox_field_d2($field_name) {
	global $readonly, $class_second, $$class_second;
	echo self::checkBox_field($field_name, $$class_second->$field_name, $field_name, $readonly);
 }

 public static function checkBox_field_wid($field_name) {
	global $readonly, $class, $$class;
	echo self::checkBox_field_d($field_name, $$class->$field_name, '', $readonly);
 }

 public static function checkBox_field_wid2($field_name) {
	global $readonly, $class_second, $$class_second;
	echo self::checkBox_field_d($field_name, $$class_second->$field_name, '', $readonly);
 }

 public static function status_field($value, $readonly = "") {
	$active = "";
	$inactive = "";
	if ($value == 'ACTIVE') {
	 $active = 'selected';
	} elseif ($value == 'INACTIVE') {
	 $inactive = 'selected';
	}
	if ($readonly == 1) {
	 $readonly = 'disabled';
	} else {
	 $readonly = '';
	}

	$value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	$element_text_field = "<Select name=\"status[]\" class=\"status select\" $readonly >";
	$element_text_field .= "<option value=\"\" ></option>";
	$element_text_field .= "<option value=\"ACTIVE\" $active > " . gettext('Active') . " </option>";
	$element_text_field .= "<option value=\"INACTIVE\" $inactive > " . gettext('Inactive') . " </option>";
	$element_text_field .= "</select>";
	return $element_text_field;
 }

 public static function status_field_d($field_name) {
	global $readonly, $class, $$class;
	echo self::status_field($$class->$field_name, $readonly);
 }

 public static function status_field_d2($field_name) {
	global $readonly, $class_second, $$class_second;
	echo self::status_field($$class_second->$field_name, $readonly);
 }

 public static function revision_enabled_field($value, $readonly = "") {
	$disabled = "";
	$enabled = "";
	if ($value == 'enabled') {
	 $enabled = 'selected';
	} elseif ($value == 'disabled') {
	 $disabled = 'selected';
	}
	if ($readonly == 1) {
	 $readonly = 'disabled';
	} else {
	 $readonly = '';
	}

	$value = htmlentities($value, ENT_QUOTES | ENT_HTML5, 'UTF-8');
	$element_text_field = "<Select name=\"rev_enabled[]\" class=\"rev_enabled select\" $readonly >";
	$element_text_field .= "<option value=\"\" ></option>";
	$element_text_field .= "<option value=\"enabled\" $enabled > Enabled </option>";
	$element_text_field .= "<option value=\"disabled\" $disabled > Disabled </option>";
	$element_text_field .= "</select>";
	return $element_text_field;
 }

 public static function revision_enabled_field_d($field_name) {
	global $readonly, $class, $$class;
	echo self::revision_enabled_field($$class->$field_name, $readonly);
 }

 public static function revision_enabled_field_d2($field_name) {
	global $readonly, $class_second, $$class_second;
	echo self::revision_enabled_field($$class_second->$field_name, $readonly);
 }

}

//end of form class
?>
