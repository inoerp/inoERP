<?php include_once("../../includes/basics/basics.inc"); ?>
<?php
if (isset($_FILES)) {
  $file = new file();
 if (!empty($_POST['upload_type']) && ($_POST['upload_type'] != 'undefined')) {
	$file->setProperty('_upload_type', $_POST['upload_type']);
 } else {
	$file->setProperty('_upload_type', 'only_server');
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
?>

<?php 
 $dbc->confirm();
 ?>