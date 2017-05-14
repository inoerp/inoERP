<?php

set_time_limit(120);
include_once ('../../../includes/basics/basics.inc');

function start_next_program() {
 global $dbc;
 $prg_schedule = new sys_program_schedule();
 $all_prg_schedule = $prg_schedule->findAll();
 /*
  * Foreach schedule check the schedule frequency
  * Check if any program is submitted with in the schduled ferquency, If yes, continue. Else create a new program
  */
 $curr_time = new DateTime();

 foreach ($all_prg_schedule as $prg_schedule) {
  $intvl = 'P365D';
  switch ($prg_schedule->frequency_uom) {
   case 'MINUTELY' :
    $intvl_i = $prg_schedule->frequency_value;
    $intvl = 'PT' . $intvl_i . 'M';
    break;

   case 'HOURLY' :
    $intvl_i = $prg_schedule->frequency_value;
    $intvl = 'PT' . $intvl_i . 'H';
    break;

   case 'DAILY' :
    $intvl_i = $prg_schedule->frequency_value;
    $intvl = 'P' . $intvl_i . 'D';
    break;

   case 'WEEKLY' :
    $intvl_i = $prg_schedule->frequency_value * 7;
    $intvl = 'P' . $intvl_i . 'D';
    break;

   case 'MONTHLY' :
    $intvl_i = $prg_schedule->frequency_value;
    $intvl = 'P' . $intvl_i . 'M';
    break;
  }

  $date_time_int = new DateInterval($intvl);
  $curr_time->sub($date_time_int);

  $sys_prg = new sys_program();
  $sys_prg->class = $prg_schedule->program_class_name;
  $sys_prg->program_name = $prg_schedule->program_name;
  $sys_prg->program_source = 'SCHEDULER';
  $sys_prg->request_type = $prg_schedule->request_type;
  $sys_prg->report_query = $prg_schedule->report_query;
  $sys_prg->op_email_address = $prg_schedule->op_email_address;
  $sys_prg->op_email_format = $prg_schedule->op_email_format;
  $sys_prg->creation_date = $curr_time->format('Y-m-d');

  $existing_schl = $sys_prg->findBy_schdule_details();

  if ($existing_schl) {
   continue;
  } else {
   //submit a request
   $all_parameters = unserialize($prg_schedule->parameter);
   if ($prg_schedule->increase_date_parameter_cb) {
    $format_param = 'Y-m-d';
    foreach ($all_parameters as $param_k => &$param_v) {
     $d = DateTime::createFromFormat($format_param, $param_v[0]);
     if ($d && $d->format($format_param) == $param_v[0]) {
      $scheduled_date_time = new DateTime($prg_schedule->creation_date);
      $param_date_time = new DateTime($param_v[0]);
      $param_date_time->diff($scheduled_date_time, true);
      $diff = $param_date_time->diff($scheduled_date_time);
      $param_d = new DateTime();
      if ($diff->invert) {
       //negative - use add
       $param_d->add(new DateInterval('P' . $diff->days . 'D'));
      } else {
       //positive - use sub
       $param_d->sub(new DateInterval('P' . $diff->days . 'D'));
      }
      $param_v[0] = $param_d->format($format_param);
     }
    }
   }
   $sys_prg->parameters = serialize($all_parameters);
   $sys_prg->description = 'Auto schdule program @' . $curr_time->format('Y-m-d');
   $sys_prg->status = 'Initiated';
   $sys_prg->save();
  }
 }
 $dbc->confirm();
 sleep(15);
 execution_time();
}

do {
 start_next_program();
} while (execution_time(true) < 55);
?>