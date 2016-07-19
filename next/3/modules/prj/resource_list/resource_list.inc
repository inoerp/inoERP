<?php

foreach ($prj_resource_list_line_object as &$prj_resource_list_line) {
 switch ($prj_resource_list_line->resource_type) {
  case 'HR_EMPLOYEE' :
   $emp_details = hr_employee::find_by_id($prj_resource_list_line->hr_employee_id);
   $prj_resource_list_line->employee_name = $emp_details->first_name . ' ' . $emp_details->last_name;
   break;

  default:
  $prj_resource_list_line->employee_name = null;
   break;
 }
}


?>