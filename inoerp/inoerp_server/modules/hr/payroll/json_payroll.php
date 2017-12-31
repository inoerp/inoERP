<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


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