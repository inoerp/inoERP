<?php include_once("../../../include/basics/header.inc"); ?>
<script src="option.js"></script>

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
<div id="json_delete_detail"> <?php  json_delete('option_detail','option_detail_id'); ?> </div>
<div id="json_delete_line"> <?php  json_delete('option_line','option_line_id'); ?> </div>
<div id="json_save_header"> <?php json_save('option', 'option_header', 'option_type', 'option_header_id'); ?></div>

<div id="json_save_line"><div class="json_message">
 <?php
 json_saveLineDetail('option', 'option_line', 'option_line_code', 'option_line_id', 'option_detail', 'option_detail_value', 'option_detail_id');
 
// if (!empty($_POST['lineData'])) {
//	
//	$postArray = get_postArray_From_jqSearializedArray($_POST['lineData']);
//	$postArray['submit_option_line'] = '1';
//			
// 	if(!empty($_POST['detailData'])){
//	$_posted_detail_line = $_POST['detailData'];
//	}
//	
//	$_POST = $postArray;
//
//	$option_line = Pre_Loading_Function('option', 'option_line', 'option_line_code', 'option_line_id');
////	$module_info = [
////		array(
////				"module" => 'option',
////				"class" => 'option_line',
////				"key_field" => 'option_line_code',
////				"primary_column" => 'option_line_id'
////		)
////];
////require_once '../../../include/function/module_functions.inc' ;
//	$option_line_id = $option_line->option_line_id;
//	
//		if (!empty($option_line->option_line_id)) {
//	 echo '<div class="message">Option line is sucessfully saved! </div>';
//	 echo '<div class="option_lineId">' . $option_line->option_line_id . '</div>';
//	} else {
//	 echo " Error code: ! ";
//	 echo '<pre>';
//	 print_r($option_line);
//	 echo '<pre>';
//	}
//
////	echo '<br/detail_line> is . '.print_r($_posted_detail_line);
//	if (!empty($_posted_detail_line)) {
//	 $postDetailArray = get_postArray_From_jqSearializedArray($_posted_detail_line);
////	 	 	 echo '<pre>';
////	 print_r($postDetailArray);
////	 echo '<pre>';
//	 
//	 $postDetailArray['submit_option_detail'] = '1';
//	 echo "<br/>option_line_id is $option_line->option_line_id";
//	 $option_lineID_array = [];
//	 array_push($option_lineID_array, $option_line->option_line_id);
//	 $postDetailArray['option_line_id'] = $option_lineID_array ;
//
//	 $_POST = $postDetailArray;
////
////	 	 	 	 echo '<pre>';
////	 print_r($_POST);
////	 echo '<pre>';
////	 
//	 $option_detail = Pre_Loading_Function('option', 'option_detail', 'option_detail_value', 'option_detail_id');
////	 	$module_info = [
////		array(
////				"module" => 'option',
////				"class" => 'option_detail',
////				"key_field" => 'option_detail_value',
////				"primary_column" => 'option_detail_id'
////		)
////];
////	require_once '../../../include/function/module_functions.inc' ;
//	
//	 	if ((count($option_detail)) > 0 ) {
//		 echo '<div class="message">Detail line is sucessfully saved! </div>';
//	 echo '<div class="option_detailId">' . $option_detail->option_detail_id . '</div>';
//	}else{
//	  
//	 	 echo " Error code: ! ";
//	 echo '<pre>';
//	 print_r($option_detail);
//	 echo '<pre>';
//	}
//	}
//
//
// }
 ?>
 </div>
</div>

<?php include_template('footer.inc') ?>