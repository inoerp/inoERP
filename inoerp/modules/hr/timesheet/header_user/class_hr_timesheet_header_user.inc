<?php

class hr_timesheet_header_user extends hr_timesheet_header {

 public $search = [
  '_show_update_path' => 1,
  '_update_path' => 'form.php?class_name=hr_timesheet_header&mode=9',
  '_show_view_path' => 1,
  '_view_path' => 'form.php?class_name=hr_timesheet_header&mode=2',
 ];

 public function search_pre_populate() {
  $employee_details = hr_employee::find_by_userId($_SESSION['user_id']);
  return array('employee_id' => $employee_details->hr_employee_id);
 }

}

//end of hr_expense_header class
?>