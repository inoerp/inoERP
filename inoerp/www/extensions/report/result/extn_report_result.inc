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

if (!empty($$class->extn_report_id) && !empty($$class->chart_type)) {
 $svgimg = new getsvgimage();
 $$class->pageno = !empty($_GET['pageno']) ? ($_GET['pageno']) : 1;
 $$class->per_page = !empty($_GET['per_page']) ? ($_GET['per_page']) : 20;
 $result = $result1 = dbObject::find_by_sql(base64_decode($$class->query_v));

//getSvgData($result, $legend_name, $chart_label, $chart_value, $legend, $labels, $data);
 $svgimg->setProperty('_chart_name', $$class->report_name);
 $svgimg->setProperty('_chart_width', $$class->chart_width);
 $svgimg->setProperty('_chart_height', $$class->chart_height);
 $svgimg->setProperty('_chart_type', $$class->chart_type);
 $svgimg->result = $result;
 $svgimg->legend_name = str_replace('.', '__', $$class->chart_legend);
 $svgimg->legend_name2 = str_replace('.', '__', $$class->chart_legend2);
 $svgimg->chart_label = str_replace('.', '__', $$class->chart_label);
 $svgimg->chart_value = str_replace('.', '__', $$class->chart_value);
 $svg_chart = $svgimg->getSvgChart_forView();
}

$column_list = [];
if (!empty($$class->report_columns)) {
 $column_list_i = json_decode($$class->report_columns);
 foreach ($column_list_i as $k => $v) {
  $column_list[$v] = $v;
 }
}
?>