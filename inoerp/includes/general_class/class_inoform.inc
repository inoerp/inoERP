<?php

/*
 * textfields
 * numberfields
 * accounfields
 * textarea
 */

class inoform {

// protected static $table_name = "inoform";
 public static $primary_column = "inoform_id";
 public static $key_column = 'form_name';
 public static $module = "sys";
 //  data base variables as stored database column name
 public static $field_a = [
  "inoform_id",
  "form_name",
  "description",
  "class_name",
  "created_by",
  "creation_date",
  "last_update_by",
  "last_update_date"
 ];
 public $initial_search = [
  "inoform_id",
  "form_name",
  "description",
  "class_name",
 ];
 public $column = [
  "inoform_id",
  "form_name",
  "description",
  "class_name",
 ];
 public $numberField = [
 ];
 public $requiredField = [
  "form_name",
  "description",
  "class_name",
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=inoform',
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " inoFrom - All Forms "; //page Title
 public $option_lists = [
//		 'supplier_type' => 'SUPPLIER_TYPE',
 ];
 public $inoform_id;
 public $_form_name;
 public $_description;
 public $_class_name;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;
 public $current_page_path = "";
 public $readonly;
 public $readonly1;
 public $readonly2;
 public $readonly3;
 public $readonly4;
 public $ac_field_length = 28;
 public $no_of_columns_per_tab = 9;
 public $data_arrOfObjs;
 public $action_message = 'Comments';
 public $column_array_s;

 public static function form_button_withImage($current_page_path = "", $homeUrl = '') {
  $home_url_wos = rtrim(HOME_URL, '/');
  $homeUrl = empty($homeUrl) ? $home_url_wos : $homeUrl;
  if (empty($current_page_path)) {
   $current_page_path = thisPage_url();
  }
  echo <<<EOD
			 <ul id="form_top_image" class="draggable">
        <li class='fa fa-refresh clickable' id='refresh_button' title='Refresh'></li>
        <li><a class='fa fa-file-text-o clickable' Title="New Document" id="new_page_button" href="$current_page_path"></a></li>
    		<li class='fa fa-save clickable' id='save' title='Save'></li>
        <li><a class='fa fa-eraser clickable' Title="Clear All, Quick Entry" id="new_object_button" href="$current_page_path"></a></li>
        <li class='fa fa-trash-o clickable' id='delete_button' title='Delete'></li>
        <li class='fa fa-remove clickable' id='remove_row_button' title='Remove'></li>
        <li class='fa fa-print clickable print' id='print_searchResult' title='Print'></li>
</ul>
EOD;
 }

 public static function form_button_withImage_xx($current_page_path = "", $homeUrl = '') {
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
				 <img src="$homeUrl/themes/images/form/new_object.png" alt="Quick Entry" Title="Quick Entry" class="showPointer"></a> </li> 
				<li><a id="new_page_button" href="$current_page_path">
				 <img src="$homeUrl/themes/images/form/new_line.png" alt="New Entry" Title="New Entry" class="showPointer"></a> </li> 
				<li><input type="button" class="button_image save" name="save" id="save_button">
				 <img src="$homeUrl/themes/images/form/save.png" id="save" alt="Save" Title="Save" class="showPointer"></li>
				<li><input type="button" class="button_image delete"  name="delete_row" id="delete_row">
				 <img src="$homeUrl/themes/images/form/delete.png" id="delete_button" alt="Delete" Title="Delete" class="showPointer"></li>
        <li><input type="button" class="button_image remove_row" name="remove_row" >
				 <img src="$homeUrl/themes/images/form/remove.png" id="remove_row_button" alt="Remove" Title="Remove" class="showPointer"></li>
        <li><input type="reset" class="button_image reset"  name="reset" Value="Rese*t">
				 <img src="$homeUrl/themes/images/form/reset.png" id="reset_button" alt="Reset" Title="Reset" class="showPointer"></li>
             <li><input type="button" class="button_image print clickable showPointer"  name="print"/>
				 <img src="$homeUrl/files/images/print.png" id="refresh_button" alt="print" Title="Print" class="print showPointer" id='print_searchResult'></li>
</ul>
EOD;
 }

 private function _convert_id($id = "") {
  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  return $idvalue;
 }

 public function hidden_field($name, $value) {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
  $element_hidden_field = "<input type=\"hidden\" name=\"$bracketName\" value=\"$value\" class=\"hidden $name\" >";
  return $element_hidden_field;
 }

 public function hidden_field_withId($name, $value) {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
  $element_hidden_field = "<input type=\"hidden\" id=\"$name\" name=\"$bracketName\" value=\"$value\" class=\"hidden $name\" >";
  return $element_hidden_field;
 }

 public function hidden_field_withCLass($name, $value, $class) {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
  $element_hidden_field = "<input type=\"hidden\" name=\"$bracketName\" value=\"$value\" class=\"hidden $class $name\" >";
  return $element_hidden_field;
 }

 public function hidden_field_withIdClass($name, $value, $class) {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
  $element_hidden_field = "<input type=\"hidden\" id=\"$name\" name=\"$bracketName\" value=\"$value\" class=\"hidden $name $class\" >";
  return $element_hidden_field;
 }

 public function text_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $maxlength = "256") {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
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
	 maxlength=\"$maxlength\" size=\"$size\" class=\"textfield $div_class $name\" "
   . "placeholder=\"$place_holder\"  $required $idvalue $readonly title=\"$title\" >";
  return $element_text_field;
 }

 public function l_text_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $maxlength = "256") {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->text_field($name, $value, $size, $id, $div_class, $required, $readonly, $place_holder, $title, $maxlength);
 }

 public function seq_field($value) {
  $this->text_field('seq_number', $value, '6', '', 'seq_number', '', 1);
 }

 public function seq_field_d($value) {
  echo $this->text_field('seq_number', $value, '6', '', 'seq_number', '', 1);
 }

 public function seq_field_detail_d($value) {
  echo $this->text_field('detail_seq_number', $value, '6', '', '', '', 1);
 }

 public function text_field_ap($array) {
  $name = array_key_exists('name', $array) ? $array['name'] : null;
  $value = array_key_exists('value', $array) ? $array['value'] : null;
  $size = array_key_exists('size', $array) ? $array['size'] : "15";
  $maxlength = array_key_exists('maxlength', $array) ? $array['maxlength'] : null;
  $required = array_key_exists('required', $array) ? $array['required'] : null;
  $place_holder = array_key_exists('place_holder', $array) ? $array['place_holder'] : null;
  $id = array_key_exists('id', $array) ? $array['id'] : null;
  $readonly = array_key_exists('readonly', $array) ? $array['readonly'] : null;
  $div_class = array_key_exists('class_name', $array) ? $array['class_name'] : null;
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
	 maxlength=\"$maxlength\" size=\"$size\" class=\"textfield $div_class $name\" "
   . "placeholder=\"$place_holder\"  $required $idvalue $readonly title=\"$title\" >";
  return $element_text_field;
 }

 public function number_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $min = "", $max = "") {
  $bracketName = $name . '[]';
  $valueAfterDecimal = ino_showDecimal($value);
//	echo "$value : $valueAfterDecimal";

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
	 min=\"$min\" max=\"$max\" class=\"number $div_class $name\" placeholder=\"$place_holder\" "
   . "pattern=\"[0-9]+([\.][0-9]+)?\" step='any' $required $idvalue $readonly title=\"$title\" >";
  return $element_text_field;
 }

 public function l_number_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $min = "", $max = "") {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->number_field($name, $value, $size, $id, $div_class, $required, $readonly, $place_holder, $title, $min, $max);
 }

 public function l_number_field_d($field_name, $div_class = "") {
  global  $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
   echo $this->number_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function address_field($field_name, $div_class = "") {
  global $class, $$class;
  $text_field = $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
  $text_field .= '<img src="' . HOME_URL . 'themes/images/serach.png" class="address_id select_popup">';
  return $text_field;
 }

 public function address_field_d($field_name, $div_class = "") {
  global $class, $$class;
  $ttl = $field_val = null;
  if (!empty($$class->$field_name)) {
   $addr = address::find_by_id($$class->$field_name);
   if ($addr) {
    $field_val = $addr->address_name;
    $ttl = $addr->address . ' ' . $addr->country . ' ' . $addr->postal_code;
   }
  }
  $text_field = $this->hidden_field_withId($field_name, $$class->$field_name);
  $text_field .= $this->text_field('address_name', $field_val, '', 'address_name', '', '', 1, '', $ttl);
  $text_field .= '<img src="' . HOME_URL . 'themes/images/serach.png" class="address_id select_popup">';
  echo $text_field;
 }
 
  public function address_field_wid($field_name, $div_class = "") {
  global $class, $$class;
  $ttl = $field_val = null;
  if (!empty($$class->$field_name)) {
   $addr = address::find_by_id($$class->$field_name);
   if ($addr) {
    $field_val = $addr->address_name;
    $ttl = $addr->address . ' ' . $addr->country . ' ' . $addr->postal_code;
   }
  }
    $text_field = $this->hidden_field_withCLass($field_name, $$class->$field_name, $field_name);
  $text_field .= $this->text_field('address_name', $field_val, '', '', 'address_name', '', 1, '', $ttl);
  $text_field .= '<img src="' . HOME_URL . 'themes/images/serach.png" class="address_id select_popup">';
  echo $text_field;
 }
 
  public function l_address_field_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->address_field_d($field_name, $div_class);
 }
 
   public function l_address_field_wid($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->address_field_wid($field_name, $div_class);
 }

//d - default , r- readonly, s- small size, m - mandatory
//textfields
 public function text_field_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function l_text_field_d($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }
 
  public function l_text_field_ds($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  $div_class = $div_class . ' small';
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function l_text_field_dr($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function l_text_field_dm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, 1, $this->readonly);
 }

 public function l_text_field_d_withSearch($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . '<img src="' . HOME_URL . '/themes/images/serach.png" class="' . $field_name . ' select_popup clickable">';
  echo gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', $this->readonly);
 }

 public function l_text_field_dr_withSearch($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo '<label>' . '<img src="' . HOME_URL . '/themes/images/serach.png" class="' . $field_name . ' select_popup clickable">';
  echo gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function text_field_ds($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', $field_name, $div_class, '', $this->readonly);
 }

 public function text_field_dr($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function text_field_dm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, 1, $this->readonly);
 }

 public function text_field_dl($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '35', $field_name, $div_class, '', $this->readonly);
 }

 public function text_field_dlm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '35', $field_name, $div_class, 1, $this->readonly);
 }

 public function text_field_dlr($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '35', $field_name, $div_class, '', 1);
 }

 public function text_field_dsr($field_name, $div_class = "") {
  global $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', $field_name, $div_class, '', 1);
 }

 public function text_field_drm($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', $field_name, $div_class, 1, 1);
 }

 public function text_field_dsrm($field_name, $div_class = "") {
  global $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', $field_name, $div_class, 1, 1);
 }

 public function text_field_d2($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, '', $this->readonly2);
 }

 public function text_field_d2s($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', $field_name, $div_class, '', $this->readonly2);
 }

 public function text_field_d2sm($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', $field_name, $div_class, 1, $this->readonly2);
 }

 public function text_field_d2r($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function text_field_d2m($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, 1, $this->readonly2);
 }

 public function text_field_d2l($field_name, $div_class = "") {
  global $readonly, $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '40', $field_name, $div_class, '', $this->readonly2);
 }

 public function text_field_d2sr($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', $field_name, $div_class, '', 1);
 }

 public static function text_field_d2rm($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', $field_name, $div_class, 1, 1);
 }

 public function text_field_d2srm($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', $field_name, $div_class, 1, 1);
 }

 public function text_field_d3($field_name, $div_class = "") {
  global $readonly, $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', $field_name, $div_class, '', $this->readonly3);
 }

 public function text_field_d3s($field_name, $div_class = "") {
  global $readonly, $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', $field_name, $div_class, '', $this->readonly3);
 }

 public function text_field_d3r($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', $field_name, $div_class, '', 1);
 }

 public function text_field_d3m($field_name, $div_class = "") {
  global $readonly, $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', $field_name, $div_class, 1, $this->readonly3);
 }

 public function text_field_d3l($field_name, $div_class = "") {
  global $readonly, $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '40', $field_name, $div_class, '', $this->readonly3);
 }

 public function text_field_d3sr($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', $field_name, $div_class, '', 1);
 }

 public function text_field_d3rm($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', $field_name, $div_class, 1, 1);
 }

 public function text_field_d3srm($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', $field_name, $div_class, 1, 1);
 }

 public function text_field_wid($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', '', $div_class, '', $this->readonly);
 }

 public function text_field_widl($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '40', '', $div_class, '', $this->readonly);
 }

 public function text_field_widlr($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '40', '', $div_class, '', 1);
 }

 public function text_field_wids($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', '', $div_class, '', $this->readonly);
 }

 public function text_field_widm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', '', $div_class, 1, $this->readonly);
 }

 public function text_field_widr($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', '', $div_class, '', 1);
 }

 public function text_field_widrm($field_name, $div_class = "") {
  global $class, $$class;
  echo $this->text_field($field_name, $$class->$field_name, '20', '', $div_class, 1, 1);
 }

 public function text_field_widsm($field_name, $div_class = "") {
  global $readonly, $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', '', $div_class, 1, $this->readonly);
 }

 public function text_field_widsr($field_name, $div_class = "") {
  global $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', '', $div_class, '', 1);
 }

 public function text_field_widsrm($field_name, $div_class = "") {
  global $class, $$class;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class->$field_name, '8', '', $div_class, 1, 1);
 }

 public function text_field_wid2($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', '', $div_class, '', $this->readonly2);
 }

 public function text_field_wid2s($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', '', $div_class, '', $this->readonly2);
 }

 public function text_field_wid2l($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '40', '', $div_class, '', $this->readonly2);
 }

 public function text_field_wid2m($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', '', $div_class, 1, $this->readonly2);
 }

 public function text_field_wid2r($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', '', $div_class, '', 1);
 }

 public function text_field_wid2rm($field_name, $div_class = "") {
  global $class_second, $$class_second;
  echo $this->text_field($field_name, $$class_second->$field_name, '20', '', $div_class, 1, 1);
 }

 public function text_field_wid2sm($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', '', $div_class, 1, $this->readonly2);
 }

 public function text_field_wid2sr($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', '', $div_class, '', 1);
 }

 public function text_field_wid2srm($field_name, $div_class = "") {
  global $class_second, $$class_second;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_second->$field_name, '8', '', $div_class, 1, 1);
 }

 public function text_field_wid3($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', '', $div_class, '', $this->readonly3);
 }

 public function text_field_wid3s($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', '', $div_class, '', $this->readonly3);
 }

 public function text_field_wid3m($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', '', $div_class, 1, $this->readonly3);
 }

 public function text_field_wid3r($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', '', $div_class, '', 1);
 }

 public function text_field_wid3rm($field_name, $div_class = "") {
  global $class_third, $$class_third;
  echo $this->text_field($field_name, $$class_third->$field_name, '20', '', $div_class, 1, 1);
 }

 public function text_field_wid3sm($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', '', $div_class, 1, $this->readonly3);
 }

 public function text_field_wid3sr($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', '', $div_class, '', 1);
 }

 public function text_field_wid3srm($field_name, $div_class = "") {
  global $class_third, $$class_third;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_third->$field_name, '8', '', $div_class, 1, 1);
 }

 public function text_field_wid4($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  echo $this->text_field($field_name, $$class_fourth->$field_name, '20', '', $div_class, '', $this->readonly4);
 }

 public function text_field_wid4s($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_fourth->$field_name, '8', '', $div_class, '', $this->readonly4);
 }

 public function text_field_wid4m($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  echo $this->text_field($field_name, $$class_fourth->$field_name, '20', '', $div_class, 1, $this->readonly4);
 }

 public function text_field_wid4r($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  echo $this->text_field($field_name, $$class_fourth->$field_name, '20', '', $div_class, '', 1);
 }

 public function text_field_wid4rm($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  echo $this->text_field($field_name, $$class_fourth->$field_name, '20', '', $div_class, 1, 1);
 }

 public function text_field_wid4sm($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_fourth->$field_name, '8', '', $div_class, 1, $this->readonly4);
 }

 public function text_field_wid4sr($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_fourth->$field_name, '8', '', $div_class, '', 1);
 }

 public function text_field_wid4srm($field_name, $div_class = "") {
  global $class_fourth, $$class_fourth;
  $div_class = $div_class . ' small';
  echo $this->text_field($field_name, $$class_fourth->$field_name, '8', '', $div_class, 1, 1);
 }

 /* --------------------End of default text fields and begining of default number fields-------------
  * numberfields
  */


 /* --------------------End of default number fields and begining of accoun fields-------------
  * accounfields
  */

 public function account_field($name, $value, $size = "15", $id = "", $div_class = "", $required = "", $readonly = "", $ac_type = '', $place_holder = "", $title = "", $maxlength = "256") {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
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
  if (!empty($ac_type)) {
   $ac_type_i = " data-ac_type='{$ac_type}' ";
  } else {
   $ac_type_i = '';
  }
  $element_text_field = "<span class='acField_withSearchImage'>";
  $element_text_field .= "<input type=\"text\" name=\"$bracketName\" value=\"$value\" 
	 maxlength=\"$maxlength\" size=\"$size\" class=\"textfield $div_class $name\" "
   . "placeholder=\"$place_holder\"  $required $idvalue $readonly title=\"$title\"  $ac_type_i >";
  $element_text_field .= $this->accpup_stmt();
  $element_text_field .= "</span>";
  ;
  return $element_text_field;
 }

 public function accpup_stmt() {
  return "<img src=\"" . HOME_URL . "/themes/images/serach.png\" class=\"account_popup select_popup clickable\" >";
 }

 private function _get_account($ac_id = "") {
  $cc = new coa_combination();
  if (!empty($ac_id)) {
   $cc_i = $cc->findBy_id($ac_id);
   if ($cc_i) {
    return !empty($cc_i) ? $cc_i : $cc;
   } else {
    return $cc;
   }
  } else {
   return $cc;
  }
 }

 public function ac_field_d($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", '', $this->readonly, $ac_type, '', $ac_d->description);
 }

 public function l_ac_field_d($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo '<label>' . gettext(ucwords(str_replace(['_', '_id'], ' ', $field_name))) . '</label>';
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", '', $this->readonly, $ac_type, '', $ac_d->description);
 }

 public function l_ac_field_dm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo '<label>' . gettext(ucwords(str_replace(['_', '_id'], ' ', $field_name))) . '</label>';
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", 1, $this->readonly, $ac_type, '', $ac_d->description);
 }

 public function l_ac_field_dr($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo '<label>' . gettext(ucwords(str_replace(['_', '_id'], ' ', $field_name))) . '</label>';
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", '', 1, $ac_type, '', $ac_d->description);
 }

 public function l_ac_field_drm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo '<label>' . gettext(ucwords(str_replace(['_', '_id'], ' ', $field_name))) . '</label>';
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", 1, 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_dm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", 1, $this->readonly, $ac_type, '', $ac_d->description);
 }

 public function ac_field_dr($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", '', 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_drm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", 1, 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_d2($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  $ac_d = $this->_get_account($$class_second->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", '', $this->readonly2, $ac_type, '', $ac_d->description);
 }

 public function ac_field_d2m($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  $ac_d = $this->_get_account($$class_second->$field_name);
    echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", 1, $this->readonly2, $ac_type, '', $ac_d->description);
 }

 public function ac_field_d2r($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  $ac_d = $this->_get_account($$class_second->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", '', 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_d2rm($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  $ac_d = $this->_get_account($$class_second->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", 1, 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_d3($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  $ac_d = $this->_get_account($class_third->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", '', $this->readonly3, $ac_type, '', $ac_d->description);
 }

 public function ac_field_d3m($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  $ac_d = $this->_get_account($class_third->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", 1, $this->readonly3, $ac_type, '', $ac_d->description);
 }

 public function ac_field_d3r($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  $ac_d = $this->_get_account($class_third->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, $field_name, "$div_class select_account", '', 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_d3rm($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  $ac_d = $this->_get_account($class_third->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, "$div_class select_account", 'select_account', 1, 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_wid($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", '', $this->readonly, $ac_type, '', $ac_d->description);
 }

 public function ac_field_widm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", 1, $this->readonly, $ac_type, '', $ac_d->description);
 }

 public function ac_field_widr($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", '', 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_widrm($field_name, $div_class = '', $ac_type = '') {
  global $class, $$class;
  $ac_d = $this->_get_account($$class->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", 1, 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_wid2($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  $ac_d = $this->_get_account($$class_second->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", '', $this->readonly2, $ac_type, '', $ac_d->description);
 }

 public function ac_field_wid2m($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  $ac_d = $this->_get_account($$class_second->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", 1, $this->readonly2, $ac_type, '', $ac_d->description);
 }

 public function ac_field_wid2r($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  $ac_d = $this->_get_account($$class_second->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", '', 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_wid2rm($field_name, $div_class = '', $ac_type = '') {
  global $class_second, $$class_second;
  $ac_d = $this->_get_account($$class_second->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", 1, 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_wid3($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  $ac_d = $this->_get_account($$class_third->$field_name);
  $div_class = $div_class . ' select_account';
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", '', $this->readonly3, $ac_type, '', $ac_d->description);
 }

 public function ac_field_wid3m($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  $ac_d = $this->_get_account($$class_third->$field_name);
  $div_class = $div_class . ' select_account';
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", 1, $this->readonly3, $ac_type, '', $ac_d->description);
 }

 public function ac_field_wid3r($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  $ac_d = $this->_get_account($$class_third->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", '', 1, $ac_type, '', $ac_d->description);
 }

 public function ac_field_wid3rm($field_name, $div_class = '', $ac_type = '') {
  global $class_third, $$class_third;
  $ac_d = $this->_get_account($$class_third->$field_name);
  echo $this->account_field($field_name, $ac_d->combination, $this->ac_field_length, '', "$div_class select_account", 1, 1, $ac_type, '', $ac_d->description);
 }

 /* --------------------End of default accoun fields and begining of text area -----------------------------
  * textarea
  */

 public function text_area($name, $value, $rowsize = "1", $id = "", $div_class = "", $required = "", $readonly = "", $place_holder = "", $title = "", $columnsize = "16") {
  $bracketName = $name . '[]';
  $value = htmlentities($value);
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
	 cols=\"$columnsize\" rows=\"$rowsize\" class=\"textfield $name $div_class \" title=\"$title\" placeholder=\"$place_holder\" $required $idvalue $readonly>$value</textarea>";
  return $element_text_field;
 }

 public function text_area_ap($array) {
  $name = array_key_exists('name', $array) ? $array['name'] : null;
  $value = array_key_exists('value', $array) ? $array['value'] : null;
  $columnsize = array_key_exists('column_size', $array) ? $array['column_size'] : "15";
  $rowsize = array_key_exists('row_size', $array) ? $array['row_size'] : null;
  $required = array_key_exists('required', $array) ? $array['required'] : null;
  $place_holder = array_key_exists('place_holder', $array) ? $array['place_holder'] : null;
  $id = array_key_exists('id', $array) ? $array['id'] : null;
  $readonly = array_key_exists('readonly', $array) ? $array['readonly'] : null;
  $div_class = array_key_exists('div_class', $array) ? $array['div_class'] : null;
  $title = array_key_exists('title', $array) ? $array['title'] : null;


  $bracketName = $name . '[]';
  $value_html = htmlentities($value);
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
	 cols=\"$columnsize\" rows=\"$rowsize\" class=\"textfield $name $div_class \" title=\"$title\" placeholder=\"$place_holder\" $required $idvalue $readonly>$value_html</textarea>";
  return $element_text_field;
 }

 public function date_field($name, $value, $size = "20", $id = "", $div_class = "", $required = "", $readonly = "") {
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

  $bracketName = $name . '[]';
  $value = ino_date(htmlentities($value));
  if (!empty($id)) {
   $idvalue = 'id="' . $id . '"';
  } else {
   $idvalue = "";
  }
  $element_date_field = "<input type=\"text\" name=\"$bracketName\" value=\"$value\" 	size=\"$size\" "
   . "class=\"date $div_class $readonly $name\"  $required $readonly $idvalue>";
  return $element_date_field;
 }

 public function dateTime_field($name, $value) {
  return $this->date_field($name, $value, '20', '', 'dateTime');
 }

 public function date_fieldFromToday($name, $value, $divClass = '') {
  $divClass = "dateFromToday $divClass ";
  return $this->date_field($name, $value, '20', '', $divClass);
 }
 
  public function l_date_fieldFromToday($name, $value, $divClass = '') {
  $divClass = "dateFromToday $divClass ";
  echo '<label>' . __(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo  $this->date_field($name, $value, '20', '', $divClass);
 }

 public function date_field_MondayFromToday($name, $value) {
  return $this->date_field($name, $value, '20', '', 'MondayFromToday');
 }

 public function date_fieldFromToday_r($name, $value, $readonly) {
  return $this->date_field($name, $value, '20', '', 'dateFromToday', '', $readonly);
 }

 public function date_fieldFromToday_m($name, $value) {
  return $this->date_field($name, $value, '20', '', 'dateFromToday', 1);
 }

 public function date_fieldFromToday_mr($name, $value) {
  return $this->date_field($name, $value, '20', '', 'dateFromToday', 1, 1);
 }

 public function date_fieldFromToday_d($name, $value) {
  return $this->date_field($name, $value, '20', '', 'dateFromToday default_date');
 }

 public function date_fieldAnyDay($name, $value, $div_class = '') {
  $div_class = $div_class . ' anyDate';
  return $this->date_field($name, $value, '20', '', 'anyDate');
 }

  public function l_date_fieldAnyDay($name, $value, $div_class = '') {
  $div_class = $div_class . ' anyDate';
  echo '<label>' . __(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', '', 'anyDate');
 }
 
   public function l_date_fieldAnyDay_r($name, $value, $div_class = '') {
  $div_class = $div_class . ' anyDate';
  echo '<label>' . __(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->date_field($name, $value, '20', '', 'anyDate' , '', 1);
 }

 
 public function date_fieldAnyDay_r($name, $value, $readonly) {
  return $this->date_field($name, $value, '20', '', 'anyDate', '', $readonly);
 }

 public function date_fieldAnyDay_m($name, $value, $readonly) {
  return $this->date_field($name, $value, '20', '', 'anyDate', 1, $readonly);
 }

 public function select_field_from_array($name, $array, $value, $id = "", $class_name = "", $required = "", $readonly = "", $disabled = '', $convertToText = false) {
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }

  if ($disabled == 1) {
   $disabled = 'disabled';
  } else {
   $disabled = '';
  }

  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }

  $bracketName = $name . '[]';
  $idvalue = $this->_convert_id($id);
  $element_select_field = "<Select name=\"$bracketName\" class=\"from_array select $class_name $name\" $idvalue $required $readonly $disabled >";
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
  if ($convertToText == 1) {
   $element_select_field .= "<option value=\"newentry\"  class=\"bold blue\">New Entry</option>";
  }
  $element_select_field .= '</select>';

  return $element_select_field;
 }

 public function multi_select_field_from_array($name, $array, $value, $id = "", $class_name = "", $required = "", $readonly = "", $disabled = '', $convertToText = false) {
  if ($readonly == 1) {
   $readonly = 'readonly';
  } else {
   $readonly = '';
  }

  if ($disabled == 1) {
   $disabled = 'disabled';
  } else {
   $disabled = '';
  }

  if ($required == 1) {
   $required = 'required';
  } else {
   $required = '';
  }

  $bracketName = $name . '[]';
  $idvalue = $this->_convert_id($id);
  $element_select_field = "<Select multiple name=\"$bracketName\" class=\"from_array multi_select $class_name $name\" $idvalue $required $readonly $disabled >";
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
  if ($convertToText == 1) {
   $element_select_field .= "<option value=\"newentry\"  class=\"bold blue\">New Entry</option>";
  }
  $element_select_field .= '</select>';

  return $element_select_field;
 }

 public function select_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value = "", $id = "", $divClass = "", $required = "", $readonly = "", $convertToText = "", $nonArrayName = "", $disabled = "", $dataname = '') {
  if ($nonArrayName == 1) {
   $bracketName = $name;
  } else {
   $bracketName = $name . '[]';
  }
  $idvalue = $this->_convert_id($id);
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
    if (!empty($dataname)) {
     $element_select_field .= " data-$dataname='" . $record->$dataname . "' ";
    }
    $element_select_field .= '>';
    if (is_array($objectDescriptionKey)) {
     $newValue1 = '';
     foreach ($objectDescriptionKey as $keya => $valuea) {
      $newValue1 .= $record->$valuea . ' | ';
     }
     $newValue = rtrim($newValue1, ' | ');
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

 public function l_select_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value = "", $id = "", $divClass = "", $required = "", $readonly = "", $convertToText = "", $nonArrayName = "", $disabled = "", $dataname = '') {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->select_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value, $id, $divClass, $required, $readonly, $convertToText, $nonArrayName, $disabled, $dataname);
 }

 public function l_select_field_from_array($name, $array, $value, $id = "", $class_name = "", $required = "", $readonly = "", $disabled = '', $convertToText = false) {
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . '</label>';
  echo $this->select_field_from_array($name, $array, $value, $id, $class_name, $required, $readonly, $disabled, $convertToText);
 }

 public function multi_select_field_from_object($name, $object, $objectValueKey, $objectDescriptionKey, $value = "", $id = "", $divClass = "", $required = "", $readonly = "", $convertToText = "", $nonArrayName = "", $disabled = "") {
  if ($nonArrayName == 1) {
   $bracketName = $name;
  } else {
   $bracketName = $name . '[]';
  }
  $idvalue = $this->_convert_id($id);
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
  $element_select_field = "<Select multiple name=\"$bracketName\" class=\"multi_select $divClass $name\" $idvalue $readonly $required $disabled>";
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

 public function select_field_from_object_ap($array) {
  $name = array_key_exists('name', $array) ? $array['name'] : null;
  $ob = array_key_exists('ob', $array) ? $array['ob'] : null;
  $ob_value = array_key_exists('ob_value', $array) ? $array['ob_value'] : null;
  $ob_desc = array_key_exists('ob_desc', $array) ? $array['ob_desc'] : null;
  $value = array_key_exists('value', $array) ? $array['value'] : null;
  $id = array_key_exists('id', $array) ? $array['id'] : null;
  $readonly = array_key_exists('readonly', $array) ? $array['readonly'] : null;
  $div_class = array_key_exists('div_class', $array) ? $array['div_class'] : null;
  $convertToText = array_key_exists('convertToText', $array) ? $array['convertToText'] : null;
  $required = array_key_exists('required', $array) ? $array['required'] : null;
  $nonArrayName = array_key_exists('nonArrayName', $array) ? $array['nonArrayName'] : null;
  $disabled = array_key_exists('disabled', $array) ? $array['disabled'] : null;
  $dataname = array_key_exists('dataname', $array) ? $array['dataname'] : null;

  if ($nonArrayName == 1) {
   $bracketName = $name;
  } else {
   $bracketName = $name . '[]';
  }
  $idvalue = $this->co($id);
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

  $element_select_field = "<Select name=\"$bracketName\" class=\" select $div_class $name  \" $idvalue $readonly $required $disabled>";
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
    if (!empty($dataname)) {
     $element_select_field .= " data-$dataname='" . $record->$dataname . "' ";
    }
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
  $value = htmlentities($value);
  $element_extra_field = "<input type=\"text\" name=\"efid[]\" value=\"$value\" maxlength=\"200\" 
										size=\"$size\" class=\"efid\" $readonly \>";
  return $element_extra_field;
 }

 public function checkBox_field($name, $value, $id = "", $class_name = "", $readonly = "") {
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

  $element_extra_field = "<input type=\"checkbox\" name=\"$bracketName\"  class=\"checkBox $name $class_name \" id=\"$id\" 
	 value=\"1\"  $checked $readonly>";
  return $element_extra_field;
 }

 public function l_checkBox_field($name, $value, $id = "", $class_name = "", $readonly = "") {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $name))) . ' </label>';
  echo $this->checkBox_field($name, $value, $id, $class_name, $readonly);
 }

 public function l_checkBox_field_d($field_name) {
  global $class, $$class;
  echo '<label>' . gettext(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->checkBox_field($field_name, $$class->$field_name, $field_name, '', $this->readonly);
 }

 public function checkBox_field_d($field_name) {
  global $readonly, $class, $$class;
  echo $this->checkBox_field($field_name, $$class->$field_name, $field_name, '', $this->readonly);
 }

 public function checkBox_field_d2($field_name) {
  global $readonly, $class_second, $$class_second;
  echo $this->checkBox_field($field_name, $$class_second->$field_name, $field_name, '', $this->readonly);
 }

 public function checkBox_field_wid($field_name) {
  global $readonly, $class, $$class;
  echo $this->checkBox_field($field_name, $$class->$field_name, '', '', $this->readonly);
 }

 public function checkBox_field_wid2($field_name) {
  global $readonly, $class_second, $$class_second;
  echo $this->checkBox_field($field_name, $$class_second->$field_name, '', '', $this->readonly);
 }

 public function status_field($value, $readonly = "") {
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

  $value = htmlentities($value);
  $element_text_field = "<Select name=\"status[]\" class=\"status select\" $readonly >";
  $element_text_field .= "<option value=\"\" ></option>";
  $element_text_field .= "<option value=\"ACTIVE\" $active > Active </option>";
  $element_text_field .= "<option value=\"INACTIVE\" $inactive > Inactive </option>";
  $element_text_field .= "</select>";
  return $element_text_field;
 }

 public function status_field_d($field_name) {
  global $readonly, $class, $$class;
  echo $this->status_field($$class->$field_name, $this->readonly);
 }

  public function l_status_field_d($field_name) {
  global $readonly, $class, $$class;
  echo '<label>' . __(ucwords(str_replace('_', ' ', $field_name))) . '</label>';
  echo $this->status_field($$class->$field_name, $this->readonly);
 }
 
 public function status_field_d2($field_name) {
  global $readonly, $class_second, $$class_second;
  echo $this->status_field($$class_second->$field_name, $this->readonly);
 }

 public function show_arrayData_in_tabularTable() {
  $drop_down_icon = ino_search_dropDownSettings();
  if (empty($this->column_array_s)) {
   foreach ($this->data_arrOfObjs[0] as $k => $v) {
    $this->column_array_s[] = $k;
   }
  }


  $total_columns = count($this->column_array_s) + 1; //1 for action
  $no_of_tabs = ceil($total_columns / $this->no_of_columns_per_tab);

  $stmt_rtn = '';
  $stmt_rtn .= '<div id="tabsLine">
				 <ul class="tabMain">';
  for ($i = 0; $i < $no_of_tabs; $i++) {
   $stmt_rtn .= "<li><a href=\"#tabsLine-$i\">Tab No $i </a></li>";
  }
  $stmt_rtn .= ' </ul>
				 <div class="tabContainer"> ';

  for ($i = 0; $i < $no_of_tabs; $i++) {
   $stmt_rtn .= "<div id=\"tabsLine-$i\" class='tabContent'>";
   $stmt_rtn .= "<table class=\"normal\"><thead><tr>";
   $stmt_rtn .= "<th>Seq#</th>";
   if ($i == 0) {
    $stmt_rtn .= "<th>" . $this->action_message . "</th>";
   }
   $new_start = ($i * ($this->no_of_columns_per_tab - 1)) + $i;
   $new_end = $new_start + ($this->no_of_columns_per_tab - 1);
   for ($j = $new_start; $j <= $new_end; $j++) {
    if ($j > $total_columns - 2) {
     break;
    }
    $stmt_rtn .= '<th data-field_name="' . $this->column_array_s[$j] . '">' . $drop_down_icon . ucwords(str_replace('_', ' ', $this->column_array_s[$j])) . '</th>';
   }
   $stmt_rtn .='</tr></thead>';
   If (!empty($this->data_arrOfObjs)) {
    $stmt_rtn .= '<tbody class="form_data_line_tbody search_data_arrOfObjss" >';
    $count = 0;
    foreach ($this->data_arrOfObjs as $record) {
     $count++;
     $stmt_rtn .='<tr>';
     $stmt_rtn .= "<td>$count</td>";
     if ($i == 0) {
      $stmt_rtn .= '<td class="search_data_arrOfObjs action">';

      $stmt_rtn .= '</td>';
     }
     $new_start = ($i * ($this->no_of_columns_per_tab - 1)) + $i;
     $new_end = $new_start + ($this->no_of_columns_per_tab - 1);
     for ($k = $new_start; $k <= $new_end; $k++) {
      if ($k > $total_columns - 2) {
       break;
      }
      $col_val = $this->column_array_s[$k];
      if (isset($record->$col_val)) {
       $stmt_rtn .= '<td>' . ucwords(str_replace('_', ' ', $record->$col_val)) . '</td>';
      } else {
       $stmt_rtn .= '<td> </td>';
      }
     }
     $stmt_rtn .= '</tr>';
    }
    $stmt_rtn .= '</tbody>';
   } else {
    $stmt_rtn .= 'No Records Found!';
   }
   $stmt_rtn .= '</table> </div>';
  }
  $stmt_rtn .= '</div> </div>';
  return $stmt_rtn;
 }

}

$inoform = new inoform();
$f = & $inoform;
//end of form class
?>