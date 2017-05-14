<?php 
if (empty($prj_project_type_billing_object) && !empty($$class->prj_project_type_header_id)) {
 $prj_project_type_billing_object = prj_project_type_billing::find_by_parent_id($$class->prj_project_type_header_id);
}
if (empty($prj_project_type_billing_object)) {
 $prj_project_type_billing_object = array(new prj_project_type_billing());
}
?>