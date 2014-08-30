<?php 
 if(!empty($$class->employee_id)){
  $emp_details = hr_employee::find_by_id($$class->employee_id);
  $$class->identification_id = $emp_details->identification_id;
  $$class->employee_name = $emp_details->first_name . ' ' . $emp_details->last_name ;
  }
 
 ?>