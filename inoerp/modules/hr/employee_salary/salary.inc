<?php

$mode = 2;
$readonly = 1;

$user_details = ino_user::find_by_id($_SESSION['user_id']);
$emp_details = hr_employee::find_by_id($user_details->hr_employee_id);
$$class->hr_employee_id = $emp_details->hr_employee_id;
$$class->identification_id = $emp_details->identification_id;
$$class->employee_name = $emp_details->first_name . ' ' . $emp_details->last_name;
$hr_element_entry_line_object = $$class->findBy_employeeId($$class->hr_employee_id);
?>