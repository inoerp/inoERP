<?php
$hideContextMenu = true;
require_once __DIR__.'/includes/basics/wloader.inc';
global $s;
if ((!empty($_GET['class_name'])) && (!empty($_GET['report_name']))) {
 $class_names = $_GET['class_name'];
 $report_name = $_GET['report_name'];
// $label = $_GET['label'];
 $_GET['mode'] = 2;
} else {
 $class_names[] = 'path';
 
include_once(__DIR__.'/../inoerp_server/includes/functions/loader.inc');
 $path = new path();
 $all_search_paths = $path->findAll_searchPaths();
 $search_result_statement = "";
 $search_result_statement .= "<table class=\"first_table normal\"><thead><tr>";
 $search_result_statement .= '<th> Module </th>';
 $search_result_statement .= '<th> Search Details </th>';
 $search_result_statement .='</tr></thead>';
 If (!empty($all_search_paths)) {
  $search_result_statement .= '<tbody>';
  foreach ($all_search_paths as $key => $module_group) {
   $search_result_statement .= ' <tr class="major_row"><td>' . $key . '</td><td><table class="second">';
   foreach ($module_group as $paths) {
    $search_result_statement .='<tr class="minor_row">';
    $search_result_statement .='<td>' . $paths->name . '</td>';
    $search_result_statement .='<td>' . $paths->description . '</td>';
    $search_result_statement .='<td><a href="' . HOME_URL . $paths->path_link . '">' . HOME_URL . $paths->path_link . '</a></td>';
    $search_result_statement .='</tr>';
   }
   $search_result_statement .='</table></td></tr>';
  }
  $search_result_statement .='</tbody>';
 }
 $search_result_statement .='</table>';
 require_once(INC_BASICS . DS . "search_page.inc");
 return;
}

if ((!empty($class_names)) && (!empty($report_name))) {
include_once(__DIR__.'/../inoerp_server/includes/functions/loader.inc');
 $hidden_field_a = ['report_name' => $report_name];
 $report_parameters = $report_name . '_parameters';
 $s->setProperty('_searching_class', $class);
 $s->setProperty('_form_name', 'program_header');
 $search->setProperty('_hidden_fields', $hidden_field_a);
 $s->setProperty('_initial_search_array', $$class->initial_search);

 if (property_exists($$class, $report_parameters)) {
  $s->setProperty('_search_functions', $$class->$report_parameters);
 }
// $search_form = $s->search_form($$class);

 $$class = new $class;
 $legend = [];
 $chart_a = [];
 $reports = call_user_func(array($$class, $report_name), $p->parameters);
 $detail_name = $report_name . '_settings';
 $chart_settings = $$class->$detail_name;
 $count = 0;
 foreach ($reports as $key => $report_data) {
  $key_name_setting = $key . '_settings';
  $svgimage = new getsvgimage();
  $svgimage->setProperty('_settings', $chart_settings);
  if (property_exists($class, $key_name_setting)) {
   $this_chart_settings = $$class->$key_name_setting;
   $svgimage->setProperty('_settings', $this_chart_settings);
  }

  $svgimage->setProperty('_data', $report_data);
  $chart = $svgimage->draw_chart();
  array_push($chart_a, $chart);
  $count++;
 }
   if ($continue) {
  include_once(THEME_DIR . '/header.inc');
 } else {
  $continue = false;
  echo "<h2>Could n't call the header</h2>";
  return;
 }
 require_once(INC_BASICS . DS . "report_template.inc");
}
?>
<script type="text/javascript">
 $(document).ready(function () {
   $.getScript("includes/js/erp.js");
  $("head").append("<link id='getsvgimage' href='http://localhost/inoerp/css/getsvgimage.css' type='text/css' rel='stylesheet' />");
 });
</script>
