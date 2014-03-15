<?php include_once("../../../include/basics/header.inc"); ?> 
<script type='text/javascript' src="bom_routing.js" ></script>

<div id="json_save_header"> <?php json_save('bom', 'bom_routing_header', 'item_id', 'bom_routing_header_id', ''); ?></div>
<div id="json_save_line"><div class="json_message">
	<?php
	json_saveLineDetail('bom', 'bom_routing_line', 'routing_sequence', 'bom_routing_line_id','bom_routing_detail', 'resource_sequence', 'bom_routing_detail_id');
//	if (!empty($_POST['lineData'])) {
//
//	 $postArray = get_postArray_From_jqSearializedArray($_POST['lineData']);
//	 $postArray['submit_bom_routing_line'] = '1';
//
//	 if (!empty($_POST['detailData'])) {
//		$_posted_detail_line = $_POST['detailData'];
//	 }
//
//	 $_POST = $postArray;
//
//	 $bom_routing_line = Pre_Loading_Function('bom', 'bom_routing_line', 'routing_sequence', 'bom_routing_line_id');
//	 $bom_routing_line_id = $bom_routing_line->bom_routing_line_id;
//
//	 if (!empty($bom_routing_line->bom_routing_line_id)) {
//		echo '<div class="message">Line is sucessfully saved! </div>';
//		echo '<div class="bom_routing_lineId">' . $bom_routing_line->bom_routing_line_id . '</div>';
//	 } else {
//		echo " Error code: ! ";
//		echo '<pre>';
//		print_r($bom_routing_line);
//		echo '<pre>';
//	 }
//
////	echo '<br/detail_line> is . '.print_r($_bomsted_detail_line);
//	 if (!empty($_posted_detail_line)) {
//		$postDetailArray = get_postArray_From_jqSearializedArray($_posted_detail_line);
//
//		$postDetailArray['submit_bom_routing_detail'] = '1';
////		echo "<br/>bom_routing_line_id is $bom_routing_line->bom_routing_line_id";
//		$bom_routing_lineID_array = [];
//		array_push($bom_routing_lineID_array, $bom_routing_line->bom_routing_line_id);
//		$postDetailArray['bom_routing_line_id'] = $bom_routing_lineID_array;
//
//		$_POST = $postDetailArray;
//
////	 print_r($_POST);
//		$jsonSave_bom_routing_detail = Pre_Loading_Function('bom', 'bom_routing_detail', 'resource_sequence', 'bom_routing_detail_id');
//		if ((count($jsonSave_bom_routing_detail)) > 0) {
//		 echo '<div class="message">Detail line is sucessfully saved! </div>';
////		 echo '<pre>'; 
////		 print_r($jsonSave_bom_routing_detail);
//		 foreach ($jsonSave_bom_routing_detail as $key=>$details){
//			if($key != 'bom_routing_detail'){
//		 echo '<div class="option_detailId">' . $details->bom_routing_detail_id . '</div>';
//			}
//		 }
//		} else {
//		 echo " Error code: ! ";
//		 echo '<pre>';
//		 print_r($jsonSave_bom_routing_detail);
//		 echo '<pre>';
//		}
//	 }
//	}
	?>
 </div>
</div>
<div id="json_delete_line"> <?php json_delete('bom_routing_line'); ?> </div>

<?php include_template('footer.inc') ?>