<?php

$column_list = [];
if (!empty($$class->report_columns)) {
 $column_list_i = json_decode($$class->report_columns);
 foreach($column_list_i as $k => $v){
  $column_list[$v] = $v;
 }
}

if (!empty($$class->path_id)) {
 $$class->parent_id = path::find_by_id($$class->path_id)->parent_id;
}
?>