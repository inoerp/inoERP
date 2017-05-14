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
 * 
 *
 */
class extn_file extends dbObject {

 public static $table_name = "extn_file";
 public static $system_info = [
		 'name' => 'File',
		 'number' => '10042',
		 'description' => 'File System',
		 'version' => '0.1.1',
		 'db_version' => '1001',
		 'mod_version' => '1.1.1',
		 'primary_entity_cb' => '',
		 'module_name' => 'extn',
		 'weight' => 16
 ];
//  data base variables as stored database column name
 public $field_a = [
		 "extn_file_id",
		 "file_path",
		 "file_name",
		 "file_size",
		 "file_type",
		 'extn_folder_id',
		 'display_type',
		 'description',
		 "created_by",
		 "creation_date",
		 "last_update_by",
		 "last_update_date"
 ];
//variables used for showing data

 public $checkbox = [];
 public $column = [];
 public $requiredField = ["file_name"];
 protected $_allowedExts = [
		 "pdf",
		 "doc",
		 "docx",
		 "jpg",
		 'JPG',
		 'PNG',
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
 protected $_allowedMimeTypes = [
		 'application/msword',
		 'application/pdf',
		 'image/gif',
		 'image/jpeg',
		 'image/png',
		 'application/mspowerpoint',
		 'application/excel',
		 'text/plain',
		 'audio/mpeg',
		 'text/csv',
		 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet',
		 'application/vnd.openxmlformats-officedocument.presentationml.presentation',
		 'application/vnd.ms-excel'
 ];
 public static $primary_column = "extn_file_id";
 protected $_upload_types = ['only_server', 'data_base'];
 protected $_class_name;
 protected $_file_dir;
 protected $_upload_type;
 protected $_max_size = '9097152';

 const MAX_SIZE = '2097152';

 public $extn_file_id;
 public $file_path;
 public $file_name = 'attachments';
 public $file_size;
 public $file_type;
 public $extn_folder_id;
 public $display_type;
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

 public function show_attachement($file, $label = 'Select Image') {
	$stmt = '<div class="existing-image">' . $this->show_existing_files($file) . '</div>';
	$stmt .= '<div  class="show_attachment">';
	$stmt .= '<div id="file_upload_form" class="form-group">
							<ul class="inRow asperWidth"><li><label for="exampleInputFile">' . gettext($label) . '</label></li>
							 <li><input type="file" id="attachments" class="attachments" name="' . $this->file_name . '[]" multiple/></li>
                <li><input type="hidden" class="hidden" name="display_type[]" value="' . $this->display_type . '"/></li>
							 <li><button  form="file_upload" name="attach_submit" id="attach_submit" class="submit button">Attach</button></li>';
	$stmt .= '<li class="show_loading_small"><img alt="Loading..." src="' . HOME_URL . 'themes/images/small_loading.gif"/></li>
							</ul>
							<div class="uploaded_file_details"></div>
						 </div>';
	$stmt .= '</div>';

	return $stmt;
 }

 public function show_existing_files(&$file) {
	$attachment_statement = "<div id=\"existing_attachment_list\"><ul class='first_level'>";

	if (!empty($file) && count($file) > 0) {
	 if ($this->display_type == 'file') {
		$attachment_statement .= '<li><ul  class="second_level header"><li>Hide</li><li>Delete</li><li>File</li><li></li></ul></li>';
	 }
	 foreach ($file as $records) {
		switch ($records->display_type) {
		 case 'image':
			$attachment_statement .= '<li><img src="' . $records->file_path . $records->file_name . '"/></li>';
			break;

		 case 'file' :
			$attachment_statement .= '<li><ul class="second_level">';
			$attachment_statement .= '<li><input type="checkbox" class="hide_file" name="hide_file[]" value="' . $records->file_reference_id . '"></li>';
			$attachment_statement .= '<li><input type="checkbox" class="delete_file" name="delete_file[]" value="' . $records->file_reference_id . '"></li>';
			$attachment_statement .= '<li><a href=' . HOME_URL . $records->file_path . $records->file_name . '>' . $records->file_name . '</a></li>';

//		$attachment_statement .= '<li class="remove_row_img"><img src="' . HOME_URL . 'themes/images/remove.png" alt="remove this file" /> </li>';
			$attachment_statement .= '</ul></li>';
			break;

		 default:
			break;
		}
	 }
	}

	$attachment_statement .= "</ul></div>";
	return $attachment_statement;
 }

 protected function check_extension($extension) {
	if (!( in_array(strtolower($extension), $this->_allowedExts) )) {
	 $error = '<div class="message">File extension ' . strtolower($extension) . ' is not allowed.</div>';
	 throw new Exception($error);
	}
	return true;
 }

 protected function check_mimetypes($mimetype) {
	if (!(in_array($mimetype, $this->_allowedMimeTypes))) {
	 $error = "<div class='message'>File type $mimetype is not allowed.</div>";
	 throw new Exception($error);
	}
	return true;
 }

 protected function check_file_size($file_size) {
	if ($file_size > $this->_max_size) {
	 $error = "<div class='message'>File size must be less than 2 MB</div>";
	 throw new Exception($error);
	}
	return true;
 }

 protected function mass_upload($data_array, $class_name) {
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
	 if ($new_files['error'] > 0) {
		echo '<div class="message"> Upload error ' . ino_upload_error_msg($new_files['error']) . '</div>';
		continue;
	 }

	 $extension_t = explode(".", $new_files["name"]);
	 $extension = end($extension_t);
	 try {
		$this->check_extension($extension);
	 } catch (Exception $e) {
		echo 'Message: ' . $e->getMessage();
		return false;
	 }
	 try {
		$this->check_mimetypes($new_files["type"]);
	 } catch (Exception $e) {
		echo 'Message: ' . $e->getMessage();
		return false;
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
	 if (($upload_status) && ($this->_upload_type == 'data_base')) {
		$fh = fopen("$this->_file_dir/$this->file_name", 'r');
		$data_array = [];
		while (($data = fgetcsv($fh, 3000, ",")) !== FALSE) {
		 array_push($data_array, $data);
		}
		$this->mass_upload($data_array, $this->_class_name);
		fclose($fh);
	 }

	 if (($upload_status) && ($this->_upload_type == 'only_server')) {
		$new_entry = $this->save();
		if ($new_entry == 1) {
		 $msg = "File is Successfully uploaded!";
		 array_push($uploaded_file_ids, $this->extn_file_id);
		 $this->extn_file_id = null;
		} else {
		 $msg = "File is Successfully uploaded but record cldnt saved in database";
		}
	 }
	}//complete of for loop
	if ((empty($errors)) && (($this->_upload_type == 'only_server'))) {
	 if (!empty($uploaded_file_ids)) {
		echo '<div id="uploaded_files_list">';
		foreach ($uploaded_file_ids as $keys => $values) {
		 $file = extn_file::find_by_id($values);
		 echo '<ul class="inRow asperWidth">';
		 echo '<li><button name="remove_file" class="remove_file" >Remove</button></li>';
		 if (!empty($this->display_type) && ($this->display_type == 'extn_image')) {
			echo '<li><input type="hidden" name=extn_image_id_values[] class="hidden file_id_values" value="' . $values . '"></li>';
		 } else {
			echo '<li><input type="hidden" name=file_id_values[] class="hidden file_id_values" value="' . $values . '"></li>';
		 }
		 echo '<li><a href=' . HOME_URL . "$this->file_path" . $file->file_name . '>' . $file->file_name . '</a></li>';
		 if ($this->display_type == 'image') {
			echo '<li><img src="' . $file->file_path . $file->file_name . '"/ class="img img-medium"></li>';
		 }
		 echo '</ul>';
		}
		echo '</div>';
	 }
	}
 }

 public static function find_by_reference_table_and_id($reference_table, $reference_id) {
	global $db;

	$sql = "SELECT extn_file.extn_file_id as extn_file_id, 
               extn_file.file_path as file_path, 
               extn_file.file_name as file_name, extn_file.extn_folder_id as extn_folder_id, 
               extn_file.description as description,extn_file.display_type as display_type,
							 file_reference.file_reference_id as file_reference_id,
							 file_reference.status as status
       FROM 
       extn_file, file_reference
       WHERE file_reference.reference_table = '{$reference_table}'
       AND file_reference.reference_id = '{$reference_id}'
       AND extn_file.extn_file_id = file_reference.file_id";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function find_by_fieldName_referenceTable_and_id($field_name, $reference_table, $reference_id) {
	global $db;
	$table_name = 'ef_' . $field_name;
	$value_colum = $table_name . '_value';
	$id_colum = $table_name . '_id';
	$sql = "SELECT extn_file.extn_file_id as extn_file_id, 
               extn_file.file_path as file_path, 
               extn_file.file_name as file_name, 
               extn_file.description as description,
               fr.$id_colum as file_reference_id 
       FROM 
       extn_file , $table_name fr
       WHERE fr.reference_key_name = '{$reference_table}'
       AND fr.reference_key_value = '{$reference_id}'
       AND extn_file.extn_file_id = fr.$value_colum";
	$result = self::find_by_sql($sql);
	return $result;
 }

 public static function attachment_statement(&$file) {

	$attachment_statement = "<div id=\"existing_attachment_list\" class='col-md-12'><table class='table table-striped'>";

	if (!empty($file) && count($file) > 0) {
	 $attachment_statement .= '<thead><tr><th class="col-md-1 text-center">Hide File</th><th class="col-md-1 text-center">Delete File</th><th class="col-md-2">File Name</th><th class="col-md-2">Folder</th><th class="col-md-4">File Description</th></tr></thead><tbody>';
	 foreach ($file as $records) {
		$folder_val = !empty($records->extn_folder_id) ? org::find_by_id(extn_folder::find_by_id($records->extn_folder_id)->org_id)->org : '' ;
		$attachment_statement .= '<tr>';
		$attachment_statement .= '<td><input type="checkbox" class="hide_file checkbox pull-left" name="hide_file[]" value="' . $records->file_reference_id . '"></td>';
		$attachment_statement .= '<td><input type="checkbox" class="delete_file checkbox pull-left" name="delete_file[]" value="' . $records->file_reference_id . '"></td>';
		$attachment_statement .= '<td><a href=' . HOME_URL . $records->file_path . $records->file_name . '>' . $records->file_name . '</a></td>';
		$attachment_statement .= '<td>' . $folder_val . '</a></td>';
		$attachment_statement .= '<td>' . $records->description . '</td>';
//		$attachment_statement .= '<li class="remove_row_img"><img src="' . HOME_URL . 'themes/images/remove.png" alt="remove this file" /> </li>';
		$attachment_statement .= '</tr>';
	 }
	 $attachment_statement .= "</tbody>";
	}
	$attachment_statement .= "</table></div>";
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

$file_z = new extn_file();
//end of file class
?>