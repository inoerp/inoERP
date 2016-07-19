<?php 
if (empty($qa_collection_element_action_object) && !empty($$class->qa_collection_element_header_id)) {
 $qa_collection_element_action_object = qa_collection_element_action::find_by_parent_id($$class->qa_collection_element_header_id);
}
if (empty($qa_collection_element_action_object)) {
 $qa_collection_element_action_object = array(new qa_collection_element_action());
}
?>