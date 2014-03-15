<?php 
require_once 'includes/functions/functions.inc';
$str_var = $_POST["data"];
$array_var = unserialize(base64_decode($str_var));
download_send_headers("data_export_" . date("Y-m-d") . ".csv");
//download_send_headers("data_export_" . date("Y-m-d") . ".html");
echo array2csv($array_var);
die();

?>