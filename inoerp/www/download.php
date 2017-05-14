<?php

set_time_limit(0);
include_once(__DIR__ . '/../inoerp_server/includes/basics/basics.inc');
if (!empty($_POST) && !empty($_POST['program_name'])) {
 if ((!empty($_POST['class_name'])) && (!empty($_POST['program_name']))) {
  $class = $_POST['class_name'];
  $program_name = $_POST['program_name'][0];
  if (!empty($_POST['download_as_text'])) {
   $download_as_text = 1;
  } else {
   $download_as_text = 0;
  }

  $$class = new $class;
  $result = call_user_func(array($$class, $program_name), $_POST);
  $array_var = json_decode(json_encode($result), true);
  $download_format = !empty($_POST['download_format'][0]) ? $_POST['download_format'][0] : 'text_format';
 }
} else {
 $str_var = $_POST["data"];

 if (!empty($_POST['data_type']) && $_POST['data_type'] == 'sql_query') {
  $sql = unserialize(base64_decode($str_var));
  $array_var = json_decode(json_encode(dbObject::find_by_sql($sql)), true);
 } else {
  $array_var = unserialize(base64_decode($str_var));
 }

 if (!empty($_POST['download_format'])) {
  $download_format = is_array($_POST['download_format']) ? $_POST['download_format'][0] : 'text_format';
 } else {
  $download_format = 'text_format';
 }
}



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
 case 'pdf_format_list':
  $format_extn = '.pdf';
  break;

 case 'text_format':
 default :
  $format_extn = '.txt';
  break;
}

//pa($array_var);

download_send_headers("data_export_" . date("Y-m-d") . "$format_extn", $download_format);
//download_send_headers("data_export_" . date("Y-m-d") . ".html");

switch ($download_format) {
 case 'excel_format':
  if (is_array($array_var)) {
   echo array2csv($array_var);
  }
  break;

 case 'xml_format':
  if (is_array($array_var)) {
   echo array2xml($array_var);
  }
  break;

 case 'worddoc_format':
  if (is_array($array_var)) {
   echo array2worddoc($array_var);
  }
  break;

 case 'pdf_format':
  if (is_array($array_var)) {
   echo array2pdf($array_var);
  }
  break;

 case 'pdf_format_list':
  if (is_array($array_var)) {
   echo array2pdf_list($array_var);
  }
  break;

 case 'text_format':
 case 'default' :
  if (is_array($array_var)) {
   echo array2text($array_var);
  }
  break;
}

die();
?>