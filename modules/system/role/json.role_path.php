<?php include_once("../../../include/basics/header.inc"); ?>
<script src="option.js"></script>

<div id="new_search_criteria">
  <?php
  if (!empty($_GET["new_search_criteria"])) {
    $new_search_criteria = $_GET["new_search_criteria"];
     
  ?>
 
  <li><label><?php echo $new_search_criteria ;?> : </label>
    <input type="search" name="<?php echo $new_search_criteria ;?>" id="<?php echo $new_search_criteria ;?>" 
           value="" 
           maxlength="50" >
  </li>
  <?php } ?>
</div>


<div id="coa_json">
 <?php
 if (!empty($_GET["option_id"])) {
	$option_id_l = $_GET["option_id_l"];
	$option_line_object = option_line::find_by_option_id($option_id_l);
	if (count($option_line_object) == 0) {
	 return false;
	} else {
	 foreach ($option_line_object as $key => $value) {
		echo '<option value="' . $value->option_line_code . '"';
		echo '>' . $value->option_line_code . '</option>';
	 }
	}
 }
 ?>
</div>

<div id="json_delete_line">
 <?php
 if (!empty($_GET['delete']) && $_GET['delete'] == 1) {
	$line_id = $_GET['line_id'];

	$result = role_path::delete($line_id);

	if ($result == 1) {
	 echo 'Option line is deleted!';
	} else {
	 echo " Error code: $result ! ";
	}
 }
 ?>
</div>


<div id="json_save_option_line">
 <?php
 if (($_POST['save_line'] == 1) && (!empty($_POST['lineData']))) {
	$role_id = $_POST['role_id'];
	$option_header_idArray = [];

	$postArray = get_postArray_From_jqSearializedArray($_POST['lineData']);
	foreach ($postArray['path_id'] as $path_id) {
	 array_push($option_header_idArray, $role_id);
	}
	$postArray['submit_role_path'] = '1';
	$postArray['role_id'] = $option_header_idArray;

	$_POST = $postArray;

	$object_line = Pre_Loading_Function('role', 'role_path', 'path_id', 'role_path_id');
	$role_path_id = $object_line->role_path_id;
	
		if (!empty($object_line->role_path_id)) {
	 echo '<div class="message">Line is sucessfully saved! </div>';
	 echo '<div class="option_lineId">' . $object_line->role_path_id . '</div>';
	} else {
	 echo " Error code: ! ";
	 echo '<pre>';
	 print_r($object_line);
	 echo '<pre>';
	}

//	echo '<br/detail_line> is . '.print_r($_posted_detail_line);
	 }
 ?>
</div>

<?php include_template('footer.inc') ?>