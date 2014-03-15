<?php 
require_once 'include/function/functions.inc';

$str_var = $_POST["data"];
$array_var = unserialize(base64_decode($str_var));

//echo is_array($array_var) ? "yes array" : "no not array";
download_send_headers("data_export_" . date("Y-m-d") . ".csv");
echo array2csv($array_var);
die();

?>