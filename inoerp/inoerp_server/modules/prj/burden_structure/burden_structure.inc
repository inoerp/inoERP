<?php 
if (empty($prj_burden_struct_exptype_object) && !empty($$class->prj_burden_structure_header_id)) {
 $prj_burden_struct_exptype_object = prj_burden_struct_exptype::find_by_parent_id($$class->prj_burden_structure_header_id);
}
if (empty($prj_burden_struct_exptype_object)) {
 $prj_burden_struct_exptype_object = array(new prj_burden_struct_exptype());
}
?>