<?php include_once("../../includes/basics/basics.inc"); ?>
<div id="json_drop_column" ><div class="json_message">
	<?php
	if (!empty($_GET['delete']) && $_GET['delete'] == 1) {
	 $content_name = $_GET['content_name'];
	 $field_name = $_GET['field_name'];

	 $result = content_type::drop_column($content_name, $field_name);

	 if ($result == 1) {
		echo 'Column is deleted!';
	 } else {
		return false;
	 }
	}
	?>
 </div>
</div>

<div id="json_drop_table" >
 <div class="json_message">
	<?php
	if (!empty($_GET['delete']) && $_GET['delete'] == 2) {
	 $content_name = $_GET['content_name'];
	 $ct = new content_type();
	 $result = $ct->drop_table($content_name);
	 if ($result == 111) {
		echo 'Content type is dropped!';
	 } else {
		echo " Error code: $result ! ";
	 }
	}
	?>
 </div>
</div>

<?php include_template('footer.inc') ?>