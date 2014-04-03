<?php include_once("../../../include/basics/header.inc"); ?>
<script src="receipt.js"></script>

<div id="json_save_header"> <?php json_save('inventory', 'receipt_header', 'org_id', 'receipt_header_id','receipt_number'); ?></div>
<div id="json_save_line">
 <?php
 if (!empty($_POST['lineData'])) {
	$postArray = get_postArray_From_jqSearializedArray($_POST['lineData']);
	$postArray['submit_receipt_line'] = '1';
		
 	if(!empty($_POST['detailData'])){
	$_posted_detail_line = $_POST['detailData'];
	}
	
	$_POST = $postArray;
//		 echo '<div class="message"><pre>';
//	 print_r($_POST);
//	 echo '<pre></div>';
	
	$receipt_line = Pre_Loading_Function('inventory', 'receipt_line', 'po_detail_id', 'receipt_line_id');
		
		if (!empty($receipt_line)) {
	 echo '<div class="message">Line is sucessfully saved! </div>';
	 echo '<div class="po_lineId">' . $receipt_line->receipt_line_id . '</div>';
	} else {
	 echo " Error code: ! ";
	 echo '<pre>';
	 print_r($receipt_line);
	 echo '<pre>';
	}

//	echo '<br/detail_line> is . '.print_r($_posted_detail_line);
	if (!empty($_posted_detail_line)) {
	 $postDetailArray = get_postArray_From_jqSearializedArray($_posted_detail_line);
	 
	 $postDetailArray['submit_receipt_detail'] = '1';
	 echo "<br/>po_line_id is $po_line->po_line_id";
	 $po_lineID_array = [];
	 array_push($po_lineID_array, $po_line->po_line_id);
	 $postDetailArray['po_line_id'] = $po_lineID_array ;

	 $_POST = $postDetailArray;
	 
//	 echo "<br/> PO Line Details <pre>";
//	 print_r($_POST);
	 $po_detail = Pre_Loading_Function('po', 'po_detail', 'shipment_number', 'po_detail_id');
	
	 	if ((count($po_detail)) > 0 ) {
		 echo '<div class="message">Detail line is sucessfully saved! </div>';
	 echo '<div class="option_detailId">' . $po_detail->po_detail_id . '</div>';
	}else{
	  
	 	 echo " Error code: ! ";
	 echo '<pre>';
	 print_r($po_detail);
	 echo '<pre>';
	}
	}


 }
 ?>
</div>

<?php include_template('footer.inc') ?>