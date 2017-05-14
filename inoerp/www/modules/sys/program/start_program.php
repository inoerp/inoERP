<?php

set_time_limit(120);
include_once ('../../../includes/basics/basics.inc');

function start_next_program() {
 global $dbc, $si;
 $p = new sys_program();
 $p_toStart = $p->findBy_status('Initiated');
 if (!empty($p_toStart)) {
  foreach ($p->field_a as $key => $value) {
   $p->$value = $p_toStart->$value;
  }
  if (DB_TYPE == 'ORACLE') {
   $p->parameters = stream_get_contents($p->parameters);
  }
  //update the status to inprogress
  $p->status = 'inprogress';
  $p->save();
  $dbc->confirm();

  $class = $p->class;
  $$class = new $class;

  if ($p_toStart->request_type == 'REPORT') {
   $search_class_obj_all = $$class->findBySql(base64_decode($p_toStart->report_query));
   $search_class_array_all = json_decode(json_encode($search_class_obj_all), true);

   if (!empty($p_toStart->op_email_address)) {
    //send email
    $im = new inomail();
    $im->FromName = $si->site_name;
    $email_a = explode(',', $p_toStart->op_email_address);
    foreach ($email_a as $em_k => $email_v) {
     $im->addAddress($email_v);
    }
    $im->addReplyTo($si->email, 'Search Output');
    $im->Subject = 'Search Result';
    $im->Body = 'Please find attached the search result';

    switch ($p_toStart->op_email_format) {
     case 'text_format' :
      $report_op = array2text($search_class_array_all);
      $file_name = date("Y-m-d") . '_' . $class . '_report_output.txt';
      break;

     case 'pdf_format' :
      $report_op = array2pdf($search_class_array_all);
      $file_name = date("Y-m-d") . '_' . $class . '_report_output.pdf';
      break;

     case 'xml_format' :
      $report_op = array2xml($search_class_array_all);
      $file_name = date("Y-m-d") . '_' . $class . '_report_output.txt';
      break;

     case 'worddoc_format' :
      $report_op = array2worddoc($search_class_array_all);
      $file_name = date("Y-m-d") . '_' . $class . '_report_output.doc';
      break;

     default :
      $report_op = array2csv($search_class_array_all);
      $file_name = date("Y-m-d") . '_' . $class . '_report_output.csv';
      break;
    }

    $im->addStringAttachment($report_op, $file_name);
    try {
     $im->ino_sendMail();
     $p->message = "Program $p->program_name is Successfullycompleted <br>" . execution_time();
     $p->status = 'Completed';
    } catch (Exception $e) {
     $p->status = 'Error';
    }
    $p->save();
   }
  } else {
   try {

    $result = call_user_func(array($$class, $p->program_name), $p->parameters);
    $result_message = is_array($result) ? $result[0] : $result;
    $result_output = is_array($result) ? $result[1] : null;
    $p->message = "Program $p->program_name is Successfullycompleted <br>" . $result_message . '<br>' . execution_time();
    $p->status = 'Completed';
    try {
     if (!empty($result_output)) {
      $op_file_name = $p->program_name . '_' . time() . '.xls';
      $module_name = $class::$module;
      $file_path = HOME_DIR . "/files/outputs/modules/$module_name/$p->program_name/$op_file_name";
      $file = fopen($file_path, 'w');
      $headerData = [];
      foreach ($result_output[0] as $key => $value) {
       array_push($headerData, $key);
      }
      fputcsv($file, $headerData);

      foreach ($result_output as $obj) {
       $rowData = [];
       foreach ($obj as $key => $value) {
        array_push($rowData, $value);
       }
       fputcsv($file, $rowData);
      }
      fclose($file);
      $p->output_path = "/files/outputs/modules/$module_name/$p->program_name/$op_file_name";
     }
    } catch (Exception $e) {
     $p->output_path = null;
    }
    $p->save();
   } catch (Exception $e) {
    $p->status = 'Failed';
    $p->message = "<br> Program failed @ start_program " . __LINE__ . '<br>' . $e->getMessage();
    $p->save();
   }
  }
  $dbc->confirm();
 } else {
  sleep(5);
 }

 execution_time();
 unset($p_toStart);
 unset($p);
}

do {
 start_next_program();
} while (execution_time(true) < 5);
?>