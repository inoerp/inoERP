<?php

class hr_employee_education_ss extends hr_employee_education {

 public static $system_info = [
  'name' => 'SS - Employe Education ',
  'number' => '3115',
  'description' => 'Self Service Employee Education',
  'version' => '0.1.1',
  'db_version' => '1001',
  'mod_version' => '1.1.1',
  'primary_entity_cb' => '',
  'module_name' => 'sys',
  'weight' => 7
 ];

// public function search_pre_populate() {
//  return array('to_user_id' => $_SESSION['user_id']);
// }

}

//end of hr_employee_education class
?>