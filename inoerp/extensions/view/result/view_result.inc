<?php

 if (!empty($$class->view_id) && !empty($$class->chart_type)) {
  $svgimg = new getsvgimage();
  $result = $result1 = dbObject::find_by_sql(base64_decode($$class->query_v));

//getSvgData($result, $legend_name, $chart_label, $chart_value, $legend, $labels, $data);
  $svgimg->setProperty('_chart_name', $$class->view_name);
  $svgimg->setProperty('_chart_width', $$class->chart_width);
  $svgimg->setProperty('_chart_height', $$class->chart_height);
  $svgimg->setProperty('_chart_type', $$class->chart_type);
  $svgimg->result = $result;
  $svgimg->legend_name = str_replace('.', '__', $$class->chart_legend);
  $svgimg->chart_label = str_replace('.', '__', $$class->chart_label);
  $svgimg->chart_value = str_replace('.', '__', $$class->chart_value);
  $svg_chart = $svgimg->getSvgChart_forView();
 }

 if (!empty($$class->view_id)) {
  $view_i = view::find_by_id($$class->view_id);
  $column_list = [];
  if (!empty($view_i->select_v)) {
   $select_v = explode(',', $$class->select_v);
   if (!empty($select_v)) {
    foreach ($select_v as $k2 => $v2) {
     if (strpos($v2, 'AS') !== false) {
      $v_a = explode('AS', $v2);
      $colmn_v = trim($v_a[1]);
      $column_list[$colmn_v] = $colmn_v;
     }
    }
   }
  }
 }
?>