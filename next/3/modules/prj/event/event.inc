<?php
$action_readonly = false;

if(!empty($$class->prj_project_header_id)){
$project_i = prj_project_header::find_by_id($$class->prj_project_header_id);
$$class->project_number = $project_i->project_number;
}


?>