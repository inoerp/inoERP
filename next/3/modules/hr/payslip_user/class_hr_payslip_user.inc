<?php

 class hr_payslip_user extends hr_payslip_header {
 public static $system_info = [
  'name' => 'User HR Payslip',
  'number' => '3305',
  'description' => 'User Payslip',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'dependent_class' => array('hr_payslip_line'),
  'primary_entity_cb' => '',
  'module_name' => 'hr',
  'weight' => 17
 ];

 }

//end of hr_leave_balance class
?>