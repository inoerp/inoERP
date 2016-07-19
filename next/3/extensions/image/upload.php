<?php include_once("../../includes/basics/basics.inc"); ?>
<?php

if (isset($_imageS)) {
  $image = new image();
 if (!empty($_POST['upload_type']) && ($_POST['upload_type'] != 'undefined')) {
	$image->setProperty('_upload_type', $_POST['upload_type']);
 } else {
	$image->setProperty('_upload_type', 'data_base');
 }
 if (!empty($_POST['image_dir'])) {
	$image->setProperty('_image_dir', $_POST['image_dir']);
 } else {
	$image->setProperty('_image_dir', 'temp');
 }

 if (!empty($_POST['class_name'])) {
	$image->setProperty('_class_name', $_POST['class_name']);
 }
 echo '<div id="uploaded_images">';
 $image->upload_image($_imageS);
 echo '</div>';
}

?>