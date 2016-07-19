<?php

if (!empty($_GET['qa_cp_header_id'])) {
 $qa_cp_element_obj = qa_cp_line::find_by_parent_id($_GET['qa_cp_header_id'], 'sequence');
 $$class->qa_cp_header_id = $_GET['qa_cp_header_id'];
}

if (empty($qa_cp_element_obj)) {
 $qa_cp_element_obj = [new qa_cp_line()];
}



if (isset($_GET['window_type']) && $_GET['window_type'] == 'popup') {
 $readonly2 = true;
 $always_readonly2 = ' always_readonly ';
 if (!empty($_GET['qa_cp_header_ids'])) {
  $qa_cp_header_obj = [];
  foreach ($_GET['qa_cp_header_ids'] as $k => $v) {
   $qa_cp_obj = qa_cp_header::find_by_id($v);
   array_push($qa_cp_header_obj, $qa_cp_obj);
  }
 } else {
  $qa_cp_header_obj = qa_cp_header::find_all();
 }
} else {
 $always_readonly2 = $readonly2 = false;
 $qa_cp_header_obj = qa_cp_header::find_all();
}

$ref_key_name = !empty($_GET['reference_key_name']) ? $_GET['reference_key_name'] : null;
$ref_key_value = !empty($_GET['reference_key_value']) ? $_GET['reference_key_value'] : null;
$reference_type = !empty($_GET['reference_type']) ? $_GET['reference_type'] : null;
$reference_entity = !empty($_GET['reference_entity']) ? $_GET['reference_entity'] : null;
?>