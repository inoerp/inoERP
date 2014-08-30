<?php include_once("../../includes/basics/basics.inc"); ?>
<?php

if (isset($_FILES)) {
  $file = new file();
 if (!empty($_POST['upload_type']) && ($_POST['upload_type'] != 'undefined')) {
	$file->setProperty('_upload_type', $_POST['upload_type']);
 } else {
	$file->setProperty('_upload_type', 'data_base');
 }
 if (!empty($_POST['file_dir'])) {
	$file->setProperty('_file_dir', $_POST['file_dir']);
 } else {
	$file->setProperty('_file_dir', 'temp');
 }

 if (!empty($_POST['class_name'])) {
	$file->setProperty('_class_name', $_POST['class_name']);
 }
 echo '<div id="uploaded_files">';
 $file->upload_file($_FILES);
 echo '</div>';
}


//echo 'POsted data <pre>';
//print_r($_FILES);
//if (isset($_FILES)) {
// $errors = array();
// $allowedExts = file::$allowedExts;
// $allowedMimeTypes = file::$allowedMimeTypes;
// $file_dir = HOME_DIR . "/files";
// $file_path = "files";
// $uploaded_file_ids = array();
//
// foreach ($_FILES as $new_files) {
//
//	$extension_t = explode(".", $new_files["name"]);
//	$extension = end($extension_t);
//	if (!( in_array($extension, $allowedExts) )) {
//	 die('File extension is not allowed.');
//	}
//	if (!(in_array($new_files["type"], $allowedMimeTypes))) {
//	 die('File type is not allowed.');
//	}
//
//	$date = new DateTime();
//	$file = new file();
//
//	$uploaded_file_name = trim($new_files['name']);
//	$uploaded_file_name = preg_replace('/\s+/', '_', $uploaded_file_name);
//	$file_name = $date->getTimestamp() . '_' . $uploaded_file_name;
//	$file_size = $new_files['size'];
//	$file_tmp = $new_files['tmp_name'];
//	$file_type = $new_files['type'];
//	if ($file_size > $file::MAX_SIZE) {
//	 $errors[] = 'File size must be less than 2 MB';
//	}
//
////        $query="INSERT into upload_data 
////         (`USER_ID`,`FILE_NAME`,`FILE_SIZE`,`FILE_TYPE`) 
////         VALUES('$user_id','$file_name','$file_size','$file_type'); ";
//
//	if (empty($errors) == true) {
//	 if (is_dir($file_dir) == false) {
//		mkdir("$file_dir", 0700); // Create directory if it does not exist
//	 }
//	 if (is_dir("$file_dir/" . $file_name) == false) {
//		if (move_uploaded_file($file_tmp, "$file_dir/" . $file_name)) {
//
//		 $file->file_path = "files/";
//		 $file->file_name = $file_name;
//		 $file->file_size = $file_size;
//		 $file->file_type = $file_type;
//
//		 $time = time();
//		 $file->creation_date = strftime("%d-%m-%Y %H:%M:%S", $time);
//		 $file->created_by = $_SESSION['username'];
//		 $file->last_update_date = $file->creation_date;
//		 $file->last_update_by = $file->created_by;
//		 $new_entry = $file->save();
//
//		 if ($new_entry == 1) {
//			$msg = "File is sucessfully uploaded!";
//			array_push($uploaded_file_ids, $file->file_id);
//		 } else {
//			$msg = "File is sucessfully uploaded but record cldnt saved in database";
//		 }
//		}
//	 } else {		 //rename the file if another one exist
//		$new_dir = "$file_dir/" . $file_name . time();
//		rename($file_tmp, $new_dir);
//	 }
////            mysql_query($query);			
//	} else {
//	 print_r($errors);
//	}
// }
// if (empty($errors)) {
//	if (!empty($uploaded_file_ids)) {
//	 echo '<div id="uploadde_files">';
//	 foreach ($uploaded_file_ids as $keys => $values) {
//		$file = file::find_by_id($values);
//		echo '<ul class="inRow asperWidth">';
//		echo '<li><button name="remove_file" class="remove_file" >Remove</button></li>';
//		echo '<li><input type="hidden" name=file_id_values[] class="hidden" value="' . $values . '"></li>';
//		echo '<li><a href=' . HOME_URL . "$file_path/" . $file->file_name . '>' . $file->file_name . '</a></li>';
//		echo '</ul>';
//	 }
//	 echo '</div>';
//	}
// }
//}
//// } else {
////  echo '<br/> No Post';
//// }
?>

<?php 
 $dbc->confirm();
 ?>