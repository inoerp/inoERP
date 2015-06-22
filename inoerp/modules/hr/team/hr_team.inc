<?php

if(!empty($_SESSION['hr_team_type'])){
 $$class->type = $_SESSION['hr_team_type'];
 $type_r = 1;
} else if(!empty($_GET['type']) && !is_array($_GET['type'])){
 $$class->type = $_GET['type']; 
 $type_r = 1;
 $_SESSION['hr_team_type'] = $_GET['type'];
}else{
  $type_r = null;
}

if (!empty($$class->team_lead_employee_id)) {
 $emp_details = hr_employee::find_by_id($$class->team_lead_employee_id);
 $$class->lead_employee_name = $emp_details->first_name . ' ' . $emp_details->last_name;
}

if (!empty($$class->region)) {
 $team_reg_vg_id = option_line::find_by_optionType_lineCode('HR_TEAM_REGION', $$class->region)->value_group_id;
} else {
 $team_reg_vg_id = null;
}
?>