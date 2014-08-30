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

<div id="json_delete_option_detail">
 <?php
 if (!empty($_GET['delete']) && $_GET['delete'] == 1) {
	$option_detail_id = $_GET['option_detail_id'];

	$result = option_detail::delete($option_detail_id);

	if ($result == 1) {
	 echo 'Option detail is deleted!';
	} else {
	 echo " Error code: $result ! ";
	}
 }
 ?>
</div>

<div id="json_delete_option_line">
 <?php
 if (!empty($_GET['delete']) && $_GET['delete'] == 1) {
	$option_line_id = $_GET['option_line_id'];

	$result = option_line::delete($option_line_id);

	if ($result == 1) {
	 echo 'Option line is deleted!';
	} else {
	 echo " Error code: $result ! ";
	}
 }
 ?>
</div>

<div id="json_save_header"> <?php json_save('option', 'option_header', 'option_type', 'option_header_id'); ?></div>

<div id="json_save_line">
 <?php
 if (!empty($_POST['lineData'])) {
	
	$postArray = get_postArray_From_jqSearializedArray($_POST['lineData']);
	$postArray['submit_option_line'] = '1';
			
 	if(!empty($_POST['detailData'])){
	$_posted_detail_line = $_POST['detailData'];
	}
	
	$_POST = $postArray;

	$option_line = Pre_Loading_Function('option', 'option_line', 'option_line_code', 'option_line_id');
	$option_line_id = $option_line->option_line_id;
	
		if (!empty($option_line->option_line_id)) {
	 echo '<div class="message">Option line is sucessfully saved! </div>';
	 echo '<div class="option_lineId">' . $option_line->option_line_id . '</div>';
	} else {
	 echo " Error code: ! ";
	 echo '<pre>';
	 print_r($option_line);
	 echo '<pre>';
	}

//	echo '<br/detail_line> is . '.print_r($_posted_detail_line);
	if (!empty($_posted_detail_line)) {
	 $postDetailArray = get_postArray_From_jqSearializedArray($_posted_detail_line);
//	 	 	 echo '<pre>';
//	 print_r($postDetailArray);
//	 echo '<pre>';
	 
	 $postDetailArray['submit_option_detail'] = '1';
	 echo "<br/>option_line_id is $option_line->option_line_id";
	 $option_lineID_array = [];
	 array_push($option_lineID_array, $option_line->option_line_id);
	 $postDetailArray['option_line_id'] = $option_lineID_array ;

	 $_POST = $postDetailArray;
//
//	 	 	 	 echo '<pre>';
//	 print_r($_POST);
//	 echo '<pre>';
//	 
	 $option_detail = Pre_Loading_Function('option', 'option_detail', 'option_detail_value', 'option_detail_id');
	 
	 	if ((count($option_detail)) > 0 ) {
		 echo '<div class="message">Detail line is sucessfully saved! </div>';
	 echo '<div class="option_detailId">' . $option_detail->option_detail_id . '</div>';
	}else{
	  
	 	 echo " Error code: ! ";
	 echo '<pre>';
	 print_r($option_detail);
	 echo '<pre>';
	}
	}


 }
 ?>
</div>

<div id="json_save_option_header">
 <?php
 if (!empty($_POST['option_header'])) {
	$postArray = get_postArray_From_jqSearializedArray($_POST['option_header']);
	$postArray['submit_option_header'] = '1';
	$_POST = $postArray;

	$option_header = Pre_Loading_Function('option', 'option_header', 'option_type', 'option_header_id');
	if (!empty($option_header->option_header_id)) {
	 echo '<div class="message">Option header is sucessfully saved! </div>';
	 echo '<div id="option_headerId">' . $option_header->option_header_id . '</div>';
	} else {
	 echo " Error code:  ! ";
	 echo '<pre>';
	 print_r($option_header);
	 echo '<pre>';
	}
 }
 ?>
</div>

<div id="json_save_option_line">
 <?php
 if (!empty($_POST['option_line'])) {
	$option_header_id = $_POST['option_header_id'];
	if(!empty($_POST['detail_line'])){
	$_posted_detail_line = $_POST['detail_line'];
	}
	$option_header_idArray = [];

	$postArray = get_postArray_From_jqSearializedArray($_POST['option_line']);
	foreach ($postArray['option_line_code'] as $option_line_code) {
	 array_push($option_header_idArray, $option_header_id);
	}
	$postArray['submit_option_line'] = '1';
	$postArray['option_header_id'] = $option_header_idArray;

	$_POST = $postArray;

	$option_line = Pre_Loading_Function('option', 'option_line', 'option_line_code', 'option_line_id');
	$option_line_id = $option_line->option_line_id;
	
		if (!empty($option_line->option_line_id)) {
	 echo '<div class="message">Option line is sucessfully saved! </div>';
	 echo '<div class="option_lineId">' . $option_line->option_line_id . '</div>';
	} else {
	 echo " Error code: ! ";
	 echo '<pre>';
	 print_r($option_line);
	 echo '<pre>';
	}

//	echo '<br/detail_line> is . '.print_r($_posted_detail_line);
	if (!empty($_posted_detail_line)) {
	 $option_line_idArray = [];
	 $option_header_idArray_detail = [];
	 $postDetailArray = get_postArray_From_jqSearializedArray($_posted_detail_line);
	 foreach ($postDetailArray['option_detail_value'] as $option_detail_value) {
		array_push($option_line_idArray, $option_line_id);
		array_push($option_header_idArray_detail, $option_header_id);
	 }
	 $postDetailArray['submit_option_detail'] = '1';
	 $postDetailArray['option_header_id'] = $option_header_idArray_detail;
	 $postDetailArray['option_line_id'] = $option_line_idArray;

	 $_POST = $postDetailArray;

	 $option_detail = Pre_Loading_Function('option', 'option_detail', 'option_detail_value', 'option_detail_id');
	 
	 	if ((count($option_detail)) > 0 ) {
		 	 		 	 echo '<pre>';
	 print_r($option_detail);
	 echo '<pre>';

//		 foreach ($option_detail as $each_option_detail)
//	 echo '<div class="message">Option detail is sucessfully saved! </div>';
//	 echo '<div class="option_detailId">' . $each_option_detail->option_detail_id . '</div>';
	}else{
	 	 echo " Error code: ! ";
	 echo '<pre>';
	 print_r($option_detail);
	 echo '<pre>';
	}
	}


 }
 ?>
</div>

<?php include_template('footer.inc') ?>