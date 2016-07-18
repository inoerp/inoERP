<?php include_once("../../includes/basics/header.inc"); ?>

<div id="file_attachement_upload_json">
  <div id="add_attachments">
    
    <div id="file_output">
    </div>
    <script src="<?php echo HOME_URL . 'extensions/file/' ?>file.js"></script>

    <form action="<?php echo HOME_URL . 'extensions/file/upload.php'; ?>"  method="post" id="file_upload"  name="file_upload" ENCTYPE="multipart/form-data">
      <ul>
        <li><input type="file" id="attachments" class="attachments" name="attachments[]" multiple/></li>
        <li> <input type="button" value="Attach" form="file_upload" name="attach_submit" id="attach_submit" class="submit button"></li>
        <li class="show_loading_small"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/small_loading.gif"/></li>
      </ul>
    </form>
		<div id="uploaded_file_details"></div>
  </div>

  
</div>

<div id="json_delete_file" ><div class="json_message">
	<?php
	if (!empty($_GET['delete']) && $_GET['delete'] == 1) {
	 $file_reference_id = $_GET['file_reference_id'];
	 	 $result = file_reference::delete($file_reference_id);
	 if ($result == 1) {
		echo '<div class="message">File is deleted! </div>';
	 } else {
		echo "<div class='message'> Error code: $result ! <div>";
	 }
	}
	?>
 </div></div>
<?php include_template('footer.inc') ?>