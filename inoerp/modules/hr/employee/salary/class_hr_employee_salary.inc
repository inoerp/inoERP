<?php

 class hr_employee_salary extends hr_element_entry_header {

 public function findBy_employeeId($employee_id) {
  $data = parent::findBy_employeeId($employee_id);
  if($data){
      return hr_element_entry_line::find_by_parent_id($data->hr_element_entry_header_id);
  }else{
   return array(new hr_element_entry_line());
  }
 }

 }

//end of bom class
?>