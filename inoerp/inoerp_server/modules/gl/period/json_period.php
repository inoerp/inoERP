<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


if ((!empty($_GET['open_next_gl_period'])) && (!empty($_GET['new_gl_calendar_id'])) && (!empty($_GET['ledger_id']))) {
 $gl_p = new gl_period();
 $gl_p->ledger_id = $_GET['ledger_id'];
 $gl_p->gl_calendar_id = $_GET['new_gl_calendar_id'];
 $gl_p->status = 'OPEN';
 $gl_p->period_name = gl_calendar::find_by_id($gl_p->gl_calendar_id)->name;
 try {
  $gl_p->save();
  $dbc->confirm();
  echo '<div class="message">' . $gl_p->period_name . gettext(' is is Successfully Opened') . ' ' . ' </div>';
 } catch (Exception $e) {
  echo "<br>Failed to open the period <br>" . $e->getMessage();
 }
}
?>

<?php

if ((!empty($_GET['gl_ledger_id'])) && (!empty($_GET['find_open_periods']))) {
 $data = [];
 $gp = new gl_period();
 $ledger_id = $_GET['gl_ledger_id'];
 $all_open_periods = $gp->find_all_periods($ledger_id, 'OPEN');
 $period_id = $gp->current_open_period($ledger_id, 'OPEN')->gl_period_id;
 $data['period_name_stmt'] = $f->select_field_from_object('gl_period_id', $all_open_periods, 'gl_period_id', 'period_name', $period_id, 'gl_period_id', '', 1);
 if (count($data) > 0) {
  echo header('Content-Type: application/json');
  echo json_encode($data);
 }
}
?>