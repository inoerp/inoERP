<?php set_time_limit(120);
include_once("../../includes/basics/basics.inc"); ?>
<?php

if (isset($_FILES)) {
 if (!empty($_POST['display_type']) && ($_POST['display_type'] == 'extn_image')) {
	$file = new extn_image();
	$temp_dir = 'temp_images';
 } else {
	$file = new extn_file();
	$temp_dir = 'temp';
 }

 if (!empty($_POST['upload_type']) && ($_POST['upload_type'] != 'undefined')) {
	$file->setProperty('_upload_type', $_POST['upload_type']);
 } else {
	$file->setProperty('_upload_type', 'only_server');
 }
 if (!empty($_POST['file_dir'])) {
	$file->setProperty('_file_dir', $_POST['file_dir']);
 } else {
	$file->setProperty('_file_dir', $temp_dir);
 }

 if (!empty($_POST['class_name'])) {
	$file->setProperty('_class_name', $_POST['class_name']);
 }

 if (!empty($_POST['display_type'])) {
	$file->display_type = $_POST['display_type'];
 }

 if (!empty($_POST['description'])) {
	$file->description = $_POST['description'];
 }

 if (!empty($_POST['extn_folder_id']) && $_POST['extn_folder_id'] != 'undefined') {
	$file->extn_folder_id = $_POST['extn_folder_id'];
 }else{
	$file->extn_folder_id = null;
 }


 echo '<div id="uploaded_files">';
 $file->upload_file($_FILES);
 echo '</div>';
}
?>

<?php

$dbc->confirm();
?>