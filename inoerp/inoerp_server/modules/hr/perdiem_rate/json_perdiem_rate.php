<?php 
require_once __DIR__.'/../../../includes/basics/wloader.inc';
include_once(__DIR__.'/../../../../inoerp_server/includes/basics/basics.inc');


if ((!empty($_GET['hr_location_id'])) && (!empty($_GET['find_perdiem_rate']))) {
 $emp_id = !empty($_GET['hr_employee_id']) ? ($_GET['hr_employee_id']) : null;
 $data = hr_perdiem_rate::find_by_hrLocationId_employeeId($_GET['hr_location_id'], $emp_id);
 if (count($data) == 0) {
  return false;
 } else {
  echo header('Content-Type: application/json');
  echo json_encode($data);
 }
}
?>