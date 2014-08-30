<?php

 class hr_leave_transaction_user extends hr_leave_transaction {
  public function search_pre_populate() {
   $employee_details = hr_employee::find_by_userId($_SESSION['user_id']);
   return array('employee_id' => $employee_details->hr_employee_id);
  }
 }

//end of hr_leave_transaction class
?>