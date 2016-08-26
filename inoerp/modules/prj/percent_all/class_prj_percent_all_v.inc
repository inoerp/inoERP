<?php

class prj_percent_all_v extends dbObject {

 public static $form_class_name = "prj_percent_header";
 public static $table_name = "prj_percent_all_v";
 public static $primary_column = "prj_project_header_id";
 public static $primary_column2 = "project_number";
 public $field_a = [
  'prj_percent_header_id',
  'project_number',
  'project_description',
  'prj_project_header_id',
  'percent',
  'description',
  'as_of_date',
  'status',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
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
 public $prj_percent_header_id;
 public $prj_project_header_id;
 public $percent;
 public $description;
 public $as_of_date;
 public $status;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $project_number;
 public $project_description;

 private function create_prj_percent_all_v() {
  $sql = "
CREATE OR REPLACE VIEW prj_percent_all_v
(
prj_percent_header_id, percent,
description, as_of_date, status, created_by,  creation_date,
last_update_by, last_update_date,
project_number, project_description, prj_project_header_id
)
AS

SELECT 
pp.prj_percent_header_id,  pp.percent,
pp.description, pp.as_of_date, pp.status, pp.created_by,  pp.creation_date,
pp.last_update_by, pp.last_update_date,
projh.project_number, projh.description as project_description, projh.prj_project_header_id

FROM prj_percent_header pp,
prj_project_header projh

WHERE projh.prj_project_header_id = pp.prj_project_header_id


UNION

SELECT 
NULL as prj_percent_header_id, NULL as percent,
NULL as description, NULL as as_of_date,NULL as status, 
NULL as created_by,  NULL as creation_date, NULL as last_update_by, NULL as last_update_date,
projh.project_number, projh.description as project_description, projh.prj_project_header_id

FROM 
prj_project_header projh

WHERE projh.prj_project_header_id NOT IN (
SELECT DISTINCT(prj_project_header_id) FROM prj_percent_header
)

";
 }

 
 public static function find_by_projectHeaderId($project_header_id){
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE prj_project_header_id= '{$project_header_id}' ";
  $sql = ino_perPageSql_i($sql, 1);
  
  $result = self::find_by_sql($sql);
  
  return !empty($result) ?  array_pop($result) : new prj_percent_all_v();
  
 }
 
}

//end of so_detail class
?>