<?php

class prj_project_all_lowesttask_v extends dbObject {

 public static $form_class_name = "hd_ro_header";
 public static $table_name = "prj_project_all_lowesttask_v";
 public static $primary_column = "prj_project_line_id";
 public $field_a = [
  'org',
  'project_number',
  'description',
  'task_number',
  'task_name',
  'task_description',
  'project_status',
  'approval_status',
  'prj_project_line_id',
  'prj_project_header_id',
  'task_level_weight',
  'parent_prj_task_num',
  'task_start_date',
  'task_end_date',
  'task_manager_user_id',
  'org_id',
  'service_type',
  'work_type',
  'allow_charges_cb',
  'capitalizable_cb',
  'bu_org_id',
  'prj_project_type_id',
  'ar_customer_id',
  'ar_customer_site_id',
  'pm_employee_id',
  'manager_user_id',
  'start_date',
  'completion_date',
  'header_amount',
 ];
 public $initial_search = [
  'prj_project_header_id',
  'project_number',
  'prj_project_line_id',
  'approval_status',
 ];
 public static $json_label_fields = [
  'org',
  'project_number',
  'description',
  'task_number',
  'task_name',
  'task_description',
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=prj_project_header',
  '_show_update_path' => 1,
  '_view_path' => 'form.php?class_name=prj_project_header',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project All "; //page Title
 public $task_description;
 public $project_status;
 public $approval_status;
 public $prj_project_line_id;
 public $prj_project_header_id;
 public $task_level_weight;
 public $parent_prj_task_num;
 public $task_start_date;
 public $task_end_date;
 public $task_manager_user_id;
 public $org_id;
 public $service_type;
 public $work_type;
 public $allow_charges_cb;
 public $capitalizable_cb;
 public $bu_org_id;
 public $prj_project_type_id;
 public $ar_customer_id;
 public $ar_customer_site_id;
 public $pm_employee_id;
 public $manager_user_id;
 public $start_date;
 public $completion_date;
 public $header_amount;

 private function create_prj_project_all_lowesttask_v() {
  $sql = "
CREATE OR REPLACE VIEW prj_project_all_lowesttask_v
(
org, project_number,description, task_number, task_name,  task_description, project_status, approval_status, 
prj_project_line_id, prj_project_header_id, task_level_weight,
parent_prj_task_num, task_start_date, task_end_date, task_manager_user_id, org_id,
service_type, work_type, allow_charges_cb, capitalizable_cb, bu_org_id, prj_project_type_id,
ar_customer_id, ar_customer_site_id, pm_employee_id, 
manager_user_id, start_date,  completion_date, header_amount
)
AS
SELECT
org.org, prh.project_number,prh.description, prl.task_number, prl.task_name,  prl.description as task_description, prh.project_status, approval_status, 
prl.prj_project_line_id, prl.prj_project_header_id, prl.task_level_weight,
prl.parent_prj_task_num, prl.start_date, prl.end_date, prl.manager_user_id, prl.org_id,
prl.service_type, prl.work_type, prl.allow_charges_cb, prl.capitalizable_cb, prh.bu_org_id, prh.prj_project_type_id,
 prh.ar_customer_id, prh.ar_customer_site_id, prh.pm_employee_id, 
prh.manager_user_id, prh.start_date,  prh.completion_date, prh.header_amount

FROM prj_project_header prh,
prj_project_line prl,
org

WHERE  prl.prj_project_header_id = prh.prj_project_header_id
AND prh.bu_org_id = org.org_id
AND  prl.task_number NOT IN(
SELECT prl.parent_prj_task_num
FROM prj_project_line prl
WHERE    prl.parent_prj_task_num IS NOT NULL
)


CREATE OR REPLACE VIEW prj_project_all_lowesttask_v
(
task_number, task_name,  description as task_description, prj_project_line_id, 
prj_project_header_id, parent_prj_task_num
)
AS
SELECT prl.task_number, prl.task_name,  prl.description as task_description, prl.prj_project_line_id, 
prl.prj_project_header_id, prl.parent_prj_task_num
FROM prj_project_line prl
WHERE    prl.task_number NOT IN(
SELECT prl.parent_prj_task_num
FROM prj_project_line prl
WHERE    prl.parent_prj_task_num IS NOT NULL
)


";
 }

 public function findBY_soLineId($line_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE hd_ro_line_id = :hd_ro_line_id ";
  $sql = ino_perPageSql_i($sql, 1);
  $value_a = ['hd_ro_line_id' => $line_id];
  $result = $this->findBySql($sql, $value_a);
  return !empty($result) ? array_pop($result) : false;
 }

}

//end of so_detail class
?>