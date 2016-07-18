<?php

class prj_percent_line_v extends dbObject {

 public static $form_class_name = "prj_percent_header";
 public static $table_name = "prj_percent_line_v";
 public static $primary_column = "prj_percent_header_id";
 public static $parent_primary_column = "prj_percent_header_id";
 public static $key_column = 'prj_project_line_id';
 public $field_a = [
  'prj_percent_line_id',
  'prj_percent_header_id',
  'percent',
  'comment',
  'as_of_date',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
  'prj_project_line_id',
  'prj_project_header_id',
  'task_number',
  'task_name',
  'task_level_weight',
  'parent_prj_task_num',
  'description'
 ];
 public $initial_search = [
  'project_number',
  'prj_percent_header_id',
  'prj_project_header_id',
 ];
 public static $json_label_fields = [
  'project_number',
  'project_description',
 ];
 public $search = [
  '_update_path' => 'form.php?class_name=prj_percent_header',
  '_show_update_path' => 1,
  '_view_path' => 'form.php?class_name=prj_percent_header',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " Project Completion Status  "; //page Title
 public $prj_percent_line_id;
 public $prj_percent_header_id;
 public $percent;
 public $comment;
 public $as_of_date;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $prj_project_line_id;
 public $prj_project_header_id;
 public $task_number;
 public $task_name;
 public $task_level_weight;
 public $parent_prj_task_num;
 public $description;

 private function create_prj_percent_line_v() {

  $sql = "
CREATE OR REPLACE VIEW prj_percent_line_v
(
prj_percent_line_id, prj_percent_header_id,
percent, comment, as_of_date, created_by, 
creation_date, last_update_by, last_update_date,
prj_project_line_id, prj_project_header_id, task_number, task_name, task_level_weight,
parent_prj_task_num, description
)
AS   

SELECT
ppl.prj_percent_line_id, ppl.prj_percent_header_id,
ppl.percent, ppl.comment, ppl.as_of_date, ppl.created_by, 
ppl.creation_date, ppl.last_update_by, ppl.last_update_date,
projl.prj_project_line_id, projl.prj_project_header_id, projl.task_number, projl.task_name, projl.task_level_weight,
projl.parent_prj_task_num, projl.description

FROM prj_percent_line ppl,
prj_project_line projl 
WHERE projl.prj_project_header_id = ppl.prj_project_header_id
AND projl.prj_project_line_id = ppl.prj_project_line_id

UNION

SELECT
NULL as prj_percent_line_id, NULL as prj_percent_line_id, 
NULL as percent, NULL as comment, NULL as as_of_date, NULL as created_by, 
NULL as creation_date, NULL as last_update_by, NULL as last_update_date,
projl.prj_project_line_id, projl.prj_project_header_id, projl.task_number, projl.task_name, projl.task_level_weight,
projl.parent_prj_task_num, projl.description

FROM prj_project_line projl
WHERE prj_project_line_id NOT IN (
SELECT DISTINCT(prj_project_line_id) FROM prj_percent_line
)
  ";
 }

 public function findBy_parentId($project_header_id,$order_by_field = '', $order_by_seq = '') {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE prj_project_header_id= '{$_GET['prj_project_header_id']}'  ORDER BY task_number ASC ";
// echo $sql;
  $result = self::find_by_sql($sql);

  return !empty($result) ? ($result) : [new prj_percent_line_v()];
 }
 
  public static function find_by_projectHeaderId($project_header_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE prj_project_header_id= '{$project_header_id}'  ORDER BY task_number ASC ";
// echo $sql;
  $result = self::find_by_sql($sql);

  return !empty($result) ? ($result) :  [new prj_percent_line_v()];
 }

}

//end of so_detail class
?>