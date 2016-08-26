<?php 
if (empty($qa_ce_action_object) && !empty($$class->qa_ce_header_id)) {
 $qa_ce_action_object = qa_ce_action::find_by_parent_id($$class->qa_ce_header_id);
}
if (empty($qa_ce_action_object)) {
 $qa_ce_action_object = array(new qa_ce_action());
}
?>