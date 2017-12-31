<?php

$action_readonly = false;

if (empty($$class->prj_budget_header_id)) {
 $$class->version_name = 'Current Original';
 $$class->version_number = 1;
 $$class->current_cb = $$class->original_cb = 1;
 $$class->budget_type = 'APPR_COST';
}

if (!empty($$class->prj_project_header_id)) {
 $$class->project_number = prj_project_header::find_by_id($$class->prj_project_header_id)->project_number;
}

?>