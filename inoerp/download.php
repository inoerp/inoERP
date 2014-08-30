<?php

require_once 'includes/functions/functions.inc';
$str_var = $_POST["data"];
$download_format = !empty($_POST['download_format']) ? $_POST['download_format'] : 'text_format';

switch ($download_format) {
 case 'excel_format':
  $format_extn = '.csv';
  break;

 case 'xml_format':
  $format_extn = '.txt';
  break;

 case 'worddoc_format':
  $format_extn = '.doc';
  break;

 case 'pdf_format':
  $format_extn = '.pdf';
  break;

 case 'text_format':
 case 'default' :
  $format_extn = 'txt';
  break;
}
$array_var = unserialize(base64_decode($str_var));

download_send_headers("data_export_" . date("Y-m-d") . "$format_extn", $download_format);
//download_send_headers("data_export_" . date("Y-m-d") . ".html");

switch ($download_format) {
 case 'excel_format':
  echo array2csv($array_var);
  break;

 case 'xml_format':
  echo array2xml($array_var);
  break;

 case 'worddoc_format':
  echo array2worddoc($array_var);
  break;

 case 'pdf_format':
  echo array2pdf($array_var);
  break;

 case 'text_format':
 case 'default' :
  echo array2text($array_var);
  break;
}

die();
?>