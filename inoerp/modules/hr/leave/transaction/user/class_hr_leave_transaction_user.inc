<?php

 class hr_leave_transaction_user extends hr_leave_transaction {
  
    public $search = [
   '_show_update_path' => 1,
     '_update_path' => 'form.php?class_name=hr_leave_transaction&mode=9',
   '_show_view_path' => 1,
     '_view_path' => 'form.php?class_name=hr_leave_transaction&mode=2',
  ];
    
  public function search_pre_populate() {
   $employee_details = hr_employee::find_by_userId($_SESSION['user_id']);
   return array('employee_id' => $employee_details->hr_employee_id);
  }
 }

//end of hr_leave_transaction class
?>