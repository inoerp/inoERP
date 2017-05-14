<?php

 define('NO_OF_FIELDS_IN_TAB', 7);
 define('NO_OF_SEEDED_FIELDS', 6);

 if (empty($$class->template_id) && (!empty($_GET['template_id']))) {
  $$class->template_id = $_GET['template_id'];
 }

 if (!empty($$class->template_id)) {
  $template_lines = cc_co_template_line::find_by_parent_id($$class->template_id);
  $no_of_fields = 4 + count($template_lines);
 } else {
  $no_of_fields = 4;
  $template_lines = [];
 }
 $no_of_tabs = ceil($no_of_fields / 7);


 if (!empty($$class->template_id)) {
  foreach ($cc_co_line_object as &$co_line) {
   if (!empty($co_line->item_id_m)) {
    $item = item::find_by_id($co_line->item_id_m);
    $co_line->item_number = $item->item_number;
   } else {
    $co_line->item_number = null;
   }
  }
 }

 if (empty($$class->status)) {
  $$class->status = 'INCOMPLETE';
 }

 if (!empty($$class->process_flow_header_id)) {
  $process_flow_line_obj = sys_process_flow_line::find_by_parent_id($$class->process_flow_header_id,'line_number','ASC');
 }else{
  $process_flow_line_obj = array(new sys_process_flow_line());
 }
?>