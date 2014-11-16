<?php

class file extends dbObject {

 public static $table_name = "file";
//  data base variables as stored database column name
 public $field_a = [
		 "file_id",
		 "file_path",
		 "file_name",
		 "file_size",
		 "file_type",
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//variables used for showing data

 public $checkbox = [];
 public $column = [];
 public $requiredField = ["file_name"];
 private $_allowedExts = [
		 "pdf",
		 "doc",
		 "docx",
		 "jpg",
		 "png",
		 "gif",
		 "ppt",
		 "pptx",
		 "xls",
		 "txt",
		 "mpg",
		 "xlsx",
		 "csv"
 ];
 private $_allowedMimeTypes = [
		 'application/msword',
		 'application/pdf',
		 'image/gif',
		 'image/jpeg',
		 'image/png',
		 'application/mspowerpoint',
		 'application/excel',
		 'text/plain',
		 'audio/mpeg',
		 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet',
		 'application/vnd.openxmlformats-officedocument.presentationml.presentation',
		 'application/vnd.ms-excel'
 ];
 public static $primary_column = "file_id";
 private $_upload_types = ['only_server', 'data_base'];
 private $_class_name;
 private $_file_dir;
 private $_upload_type;
 private $_max_size = '2097152';

 const MAX_SIZE = '2097152';

 public $file_id;
 public $file_path;
 public $file_name;
 public $file_size;
 public $file_type;
 public $description;
 public $reference_table;
 public $file_reference_id;
 public $reference_id;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $time;
 public $msg;

 public function setProperty($property, $value) {
	if (property_exists($this, $property)) {
	 switch ($property) {
		case '_max_size':
		 $this->$property = !empty($value) ? (int) $value : '2097152';
		 break;

		case '_upload_type':
		 $this->$property = !empty($value) ? $value : 'data_base';
		 break;

		case '_file_dir':
		 if (!empty($value)) {
			$value = ltrim($value, '/');
			$this->$property = HOME_DIR . "/files/$value";
			$this->file_path = "files/$value/";
		 } else {
			$this->$property = HOME_DIR . "/files/temp";
			$this->file_path = 'files/temp/';
		 }
		 break;

		default:
		 $this->$property = $value;
		 break;
	 }
	}
 }

 private function check_extension($extension) {
	if (!( in_array($extension, $this->_allowedExts) )) {
	 $error = "<div class='message'>File extension ccc $extension is not allowed.</div>";
	 throw new Exception($error);
	}
	return true;
 }

 private function check_mimetypes($mimetype) {
	if (!(in_array($mimetype, $this->_allowedMimeTypes))) {
	 $error = "<div class='message'>File type $mimetype is not allowed.</div>";
	 throw new Exception($error);
	}
	return true;
 }

 private function check_file_size($file_size) {
	if ($file_size > $this->_max_size) {
	 $error = "<div class='message'>File size must be less than 2 MB</div>";
	 throw new Exception($error);
	}
	return true;
 }

 private function mass_upload($data_array, $class_name) {
	$mu = new massupload();
	$mu->setProperty('_class_name', $class_name);
	if (!$mu->mass_upload($data_array)) {
	 $error = "<div class='message'> Mass upload failed </div>";
	 throw new Exception($error);
	}
 }

 public function upload_file($FILES) {
	$errors = [];
	$uploaded_file_ids = [];
	foreach ($FILES as $new_files) {
	 $extension_t = explode(".", $new_files["name"]);
	 $extension = end($extension_t);
	 try {
		$this->check_extension($extension);
	 } catch (Exception $e) {
		echo 'Message: ' . $e->getMessage();
	 }
	 try {
		$this->check_mimetypes($new_files["type"]);
	 } catch (Exception $e) {
		echo 'Message: ' . $e->getMessage();
	 }

	 $date = new DateTime();
	 $uploaded_file_name_asis = trim($new_files['name']);
	 $uploaded_file_name = preg_replace('/\s+/', '_', $uploaded_file_name_asis);
	 $this->file_name = $date->getTimestamp() . '_' . $uploaded_file_name;
	 $this->file_size = $new_files['size'];
	 $file_tmp = $new_files['tmp_name'];
	 $this->file_type = $new_files['type'];

	 try {
		$this->check_file_size($this->file_size);
	 } catch (Exception $e) {
		echo 'Message: ' . $e->getMessage();
	 }

	 if (!empty($errors)) {
		pa($errors);
		return;
	 }
	  if (!is_dir($this->_file_dir)) {
		mkdir("$this->_file_dir", 0777, true); // Create directory if it does not exist
	 }
	 if (is_dir("$this->_file_dir/" . $this->file_name) == false) {
		$upload_status = move_uploaded_file($file_tmp, "$this->_file_dir/" . $this->file_name);
	 } else { //rename the file if another one exist
		$new_dir = "$this->_file_dir/" . $this->file_name . time();
		rename($file_tmp, $new_dir);
	 }
//save to data base if in db mode

	 if (($upload_status) && ($this->_upload_type == 'only_server')) {
		$fh = fopen("$this->_file_dir/$this->file_name", 'r');
		$data_array = [];
		while (($data = fgetcsv($fh, 1000, ",")) !== FALSE) {
		 array_push($data_array, $data);
		}
		$this->mass_upload($data_array, $this->_class_name);
		fclose($fh);
	 }

	 if (($upload_status) && ($this->_upload_type == 'data_base')) {
		$this->audit_trial();
		$new_entry = $this->save();
		if ($new_entry == 1) {
		 $msg = "File is sucessfully uploaded!";
		 array_push($uploaded_file_ids, $this->file_id);
		} else {
		 $msg = "File is sucessfully uploaded but record cldnt saved in database";
		}
	 }
	}//complete of for loop
	if ((empty($errors)) && (($this->_upload_type == 'data_base'))) {
	 if (!empty($uploaded_file_ids)) {
		echo '<div id="uploaded_files_list">';
		foreach ($uploaded_file_ids as $keys => $values) {
		 $file = file::find_by_id($values);
		 echo '<ul class="inRow asperWidth">';
		 echo '<li><button name="remove_file" class="remove_file" >Remove</button></li>';
		 echo '<li><input type="hidden" name=file_id_values[] class="hidden" value="' . $values . '"></li>';
		 echo '<li><a href=' . HOME_URL . "$this->file_path" . $file->file_name . '>' . $file->file_name . '</a></li>';
		 echo '</ul>';
		}
		echo '</div>';
	 }
	}
 }

 public static function find_by_reference_table_and_id($reference_table, $reference_id) {
	global $db;

	$sql = "SELECT file.file_id as file_id, 
               file.file_path as file_path, 
               file.file_name as file_name, 
               file.description as description,
							 file_reference.file_reference_id as file_reference_id,
							 file_reference.status as status
       FROM 
       file , file_reference
       WHERE file_reference.reference_table = '{$reference_table}'
       AND file_reference.reference_id = '{$reference_id}'
       AND file.file_id = file_reference.file_id";
	$result = self::find_by_sql($sql);
	return $result;
 }
 
  public static function find_by_fieldName_referenceTable_and_id($field_name, $reference_table, $reference_id) {
	global $db;
    $table_name = 'extra_field_'.$field_name;
    $value_colum = $table_name.'_value';
    $id_colum = $table_name.'_id';
	$sql = "SELECT file.file_id as file_id, 
               file.file_path as file_path, 
               file.file_name as file_name, 
               file.description as description,
               fr.$id_colum as file_reference_id 
       FROM 
       file , $table_name fr
       WHERE fr.reference_key_name = '{$reference_table}'
       AND fr.reference_key_value = '{$reference_id}'
       AND file.file_id = fr.$value_colum";
   $result = self::find_by_sql($sql);
	return $result;
 }

 public static function attachment_statement(&$file) {

	$attachment_statement = "<div id=\"existing_attachment_list\"><ul class='first_level'>";

	if (!empty($file) && count($file) > 0) {
	 $attachment_statement .= '<li><ul  class="second_level header"><li>Hide</li><li>Delete</li><li>File</li><li></li></ul></li>';
	 foreach ($file as $records) {
		$attachment_statement .= '<li><ul class="second_level">';
		$attachment_statement .= '<li><input type="checkbox" class="hide_file" name="hide_file[]" value="' . $records->file_reference_id . '"></li>';
		$attachment_statement .= '<li><input type="checkbox" class="delete_file" name="delete_file[]" value="' . $records->file_reference_id . '"></li>';
		$attachment_statement .= '<li><a href=' . HOME_URL . $records->file_path . $records->file_name . '>' . $records->file_name . '</a></li>';
//		$attachment_statement .= '<li class="remove_row_img"><img src="' . HOME_URL . 'themes/images/remove.png" alt="remove this file" /> </li>';
		$attachment_statement .= '</ul></li>';
	 }
	}
	$attachment_statement .= "</ul></div>";
	return $attachment_statement;
 }

 public static function show_attachment_button() {
	return '<input type="button" class="button" value="Attachements" id="attachment_button" name="">';
 }

 public static function show_file_list(&$file) {

	$attachment_statement = "<div id=\"attachment_list\">";

	if (isset($file) && count($file) > 0) {
	 $attachment_statement .= '<ul  class="attachment_list">';
	 foreach ($file as $records) {
		$attachment_statement .= '<li><a href=' . HOME_URL . $records->file_path . $records->file_name . '>' . $records->file_name . '</a></li>';
	 }
	 $attachment_statement .= '</ul>';
	}
	$attachment_statement .= "</div>";
	return $attachment_statement;
 }

}

//end of file class
?>