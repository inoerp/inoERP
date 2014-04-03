<?php $show_submit_button = 1; ?>
<?php require_once('receipt.inc') ?>
<?php

$receipt_line_object = [];
$search_form = search::search_form('all_po_v', 'receipt', 'search_expected_receipts');
if (!empty($search_result)) {
//	 $search_result = po_header::instantiate_extra_fields($search_result);
//	 echo "<pre>";
//	 print_r($search_result);
 $search_result_statement = search::search_result('po_receipt', $column_array, $search_result, $primary_column, $view_path, 'Y', 'Receive');
//		 $return_value['search_result'] = $search_result;
}

if (!empty($pagination)) {
 $pagination_statement = $pagination->show_pagination($pagination, 'receipt', $pageno, $query_string);
}

if (!empty($search_result)) {
 //assign the item number to the object
 foreach ($search_result as $array) {
	$receipt_line = $array;
	array_push($receipt_line_object, $array);
 }
}

if(!empty($receipt_line_object[0]->ship_to_id)){
$$class->org_id = $receipt_line_object[0]->ship_to_id;
$$class->transaction_type_id = 4;
}

//echo "<pre>";
//print_r($receipt_line_object);

?>
<?php require_once('receipt_template.php'); ?>
