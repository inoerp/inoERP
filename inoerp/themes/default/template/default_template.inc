<?php

$class_first;
if (property_exists($class_first, 'header_tab_1')) {
 $tab1 = $class_first::$header_tab_1;
} else {
 $tab1 = null;
}



$no_ofline_tabs = property_exists($class_first, 'no_ofline_tabs') ? $class_first::$no_ofline_tabs : 1;
$line_tab_1 = property_exists($class_first, 'line_tab_1') ? $class_first::$line_tab_1 : null;
$line_tab_2 = property_exists($class_first, 'line_tab_2') ? $class_first::$line_tab_2 : null;
$line_tab_3 = property_exists($class_first, 'line_tab_3') ? $class_first::$line_tab_3 : null;
$line_tab_4 = property_exists($class_first, 'line_tab_4') ? $class_first::$line_tab_4 : null;
$line_tab_5 = property_exists($class_first, 'line_tab_5') ? $class_first::$line_tab_5 : null;
$line_tab_6 = property_exists($class_first, 'line_tab_6') ? $class_first::$line_tab_6 : null;
$line_tab_7 = property_exists($class_first, 'line_tab_7') ? $class_first::$line_tab_7 : null;
$line_tab_8 = property_exists($class_first, 'line_tab_8') ? $class_first::$line_tab_8 : null;

function ino_showField_from_details_a($arr) {
 global $f, $class, $$class;
 $f = new inoform();
 $ret_stmt = '';
 switch ($arr['field_function']) {
  case 'l_text_field_d':
   $ret_stmt = $f->l_text_field_d($arr['name']);
   break;

  case 'hidden_field_d':
   $val_f = isset($arr['function_parameters'][0]) ? $arr['function_parameters'][0] : null;
   $ret_stmt = $f->hidden_field_d($arr['name'], $val_f);
   break;

  case 'l_checkBox_field_d':
   $ret_stmt = $f->l_checkBox_field_d($arr['name']);
   break;

  case 'text_area':
   echo $f->l_text_area_d($arr['name']);
   break;

  case 'l_val_field_d':
   $val_field_n = isset($arr['function_parameters'][0]) ? $arr['function_parameters'][0] : null;
   $val_field_v = isset($arr['function_parameters'][1]) ? $arr['function_parameters'][1] : null;
   $val_field_value = isset($arr['function_parameters'][2]) ? $arr['function_parameters'][2] : null;
   $dependent_field = isset($arr['function_parameters'][3]) ? $arr['function_parameters'][3] : null;
   $div_class = isset($arr['function_parameters'][4]) ? $arr['function_parameters'][4] : null;
   $ret_stmt = $f->l_val_field_d($val_field_n, $val_field_v, $val_field_value, '', $div_class);
   $ret_stmt = '<i class="generic select_popup clickable fa fa-search" data-class_name="' . $val_field_v . '"></i>';
   break;

  default:
   $ret_stmt = $f->l_text_field_d($arr['name']);
   break;
 }


 echo $ret_stmt;
}

if(property_exists($class_first, 'allow_search')){
 $allow_search = $class_first::$allow_search;
}else{
 $allow_search = 1;
}

require_once 'default_template.php'
?>