<?php
$mode = 2; $readonly = 1;

if (!empty($$class->prj_project_header_id)) {
 $$class->project_number = prj_project_header::find_by_id($$class->prj_project_header_id)->project_number;
}

?>