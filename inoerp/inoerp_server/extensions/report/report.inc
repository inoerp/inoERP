<?php
if (DB_TYPE == 'ORACLE') {
 $$class->query_v = stream_get_contents($$class->query_v);
 $$class->logical_settings = stream_get_contents($$class->logical_settings);
 $$class->report_columns = stream_get_contents($$class->report_columns);
 $$class->page_header = stream_get_contents($$class->page_header);
 $$class->page_footer = stream_get_contents($$class->page_footer);
 $$class->header_text = stream_get_contents($$class->header_text);
 $$class->footer_text = stream_get_contents($$class->footer_text);
}

$column_list = [];
if (!empty($$class->report_columns)) {
 $column_list_i = json_decode($$class->report_columns);
 foreach ($column_list_i as $k => $v) {
  $column_list[$v] = $v;
 }
}

if (!empty($$class->path_id)) {
 $$class->parent_id = path::find_by_id($$class->path_id)->parent_id;
}


?>