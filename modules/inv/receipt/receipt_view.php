<?php require_once('receipt.inc') ?>
<?php  $readonly = 1 ; ?>
<?php 
if (!empty($_GET["receipt_header_id"])) {
 $receipt_header_id = htmlentities($_GET["receipt_header_id"]);
 $receipt_line_object = [];
 $all_receipt_lines = all_receipt_v::find_all_by_receiptHeaderId($receipt_header_id);
 if (!empty($all_receipt_lines)) {
 //assign the item number to the object
 foreach ($all_receipt_lines as $array) {
	$receipt_line = $array;
	array_push($receipt_line_object, $array);
 }
}

} elseif (!empty($_POST["receipt_header_id"][0])) {
 $receipt_header_id = $_POST["receipt_header_id"][0];
} else {
 $receipt_line = new receipt_line();
 $receipt_line_object = array();
 array_push($receipt_line_object, $receipt_line);
//	$field_array = receipt_line::$field_array;
}
?>
<?php require_once('receipt_template.php') ?>