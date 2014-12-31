<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php
if ((!empty($_GET['open_next_gl_period'])) && (!empty($_GET['new_gl_calendar_id'])) && (!empty($_GET['ledger_id']))) {
 $gl_p = new gl_period();
 $gl_p->ledger_id = $_GET['ledger_id'];
 $gl_p->gl_calendar_id = $_GET['new_gl_calendar_id'];
 $gl_p->status = 'OPEN';
 $gl_p->period_name = gl_calendar::find_by_id($gl_p->gl_calendar_id)->name;
 try{
  $gl_p->save();
  $dbc->confirm();
  return "<br>Period ".  $gl_p->period_name . "is sucessfully opened";
 }catch(Exception $e){
  return "<br>Failed to open the period <br>". $e->getMessage();
 }
}
?>