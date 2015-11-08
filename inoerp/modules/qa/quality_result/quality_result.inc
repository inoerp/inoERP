<?php

if (!empty($_GET['qa_cp_header_id'])) {
 $qa_cp_element_obj = qa_cp_line::find_by_parent_id($_GET['qa_cp_header_id'], 'sequence');
 $$class->qa_cp_header_id = $_GET['qa_cp_header_id'];
}

if (empty($qa_cp_element_obj)) {
 $qa_cp_element_obj = [new qa_cp_line()];
}
?>