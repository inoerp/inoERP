<?php include_once("../../include/basics/header.inc"); ?>
<script src="bom.js"></script>

<div id="json_save_header"><div class="json_message"> 
 <?php json_save('bom', 'bom_header', 'org_id', 'bom_header_id'); ?>
 </div>
</div>
<div id="json_save_line">
 <?php
 json_saveLineData('bom', 'bom_line', 'component_item_id', 'bom_line_id');
// if (!empty($_POST['lineData'])) {
//	$postArray = get_postArray_From_jqSearializedArray($_POST['lineData']);
//	$postArray['submit_bom_line'] = '1';
//	
//	$_POST = $postArray;
//	
//	$bom_line = Pre_Loading_Function('bom', 'bom_line', 'component_item_id', 'bom_line_id');
//		
//		if (!empty($bom_line)) {
//	 echo '<div class="message">Line is sucessfully saved! </div>';
//	 echo '<div class="po_lineId">' . $bom_line->bom_line_id . '</div>';
//	} else {
//	 echo " Error code: ! ";
//	 echo '<pre>';
//	 print_r($bom_line);
//	 echo '<pre>';
//	}
// }
 ?>
</div>

<?php include_template('footer.inc') ?>