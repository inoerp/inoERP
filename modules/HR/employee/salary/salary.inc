<?php

 $mode = 2;
 $readonly = 1;
  if (empty($$class->employee_id) && !empty($_GET['employee_id'])) {
  if(hr_element_entry_header::find_by_employeeId($_GET['employee_id'])){
   $$class = hr_element_entry_header::find_by_employeeId($_GET['employee_id']);
  }
  $$class->employee_id = $_GET['employee_id'];
  if(!empty($$class->hr_element_entry_header_id)){
  $hr_element_entry_line_object = hr_element_entry_line::find_by_parent_id($$class->hr_element_entry_header_id);
  }
 }
 if (!empty($$class->employee_id)) {
  $emp_details = hr_employee::find_by_id($$class->employee_id);
  $$class->identification_id = $emp_details->identification_id;
  $$class->employee_name = $emp_details->first_name . ' ' . $emp_details->last_name;
 }
 
?>