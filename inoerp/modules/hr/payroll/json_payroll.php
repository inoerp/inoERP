<?php include_once("../../../includes/basics/basics.inc"); ?>
<?php
if ((!empty($_GET['hr_payroll_id']))) {
$data = hr_payroll_schedule::find_open_schedules_by_headerId($_GET['hr_payroll_id']);
 if (count($data) == 0) {
  return false;
 } else {
  echo header('Content-Type: application/json');
  echo json_encode($data);
 }
}
?>