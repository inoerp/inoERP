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



if (property_exists($class_first, 'allow_search')) {
 $allow_search = $class_first::$allow_search;
} else {
 $allow_search = 1;
}

require_once 'default_template.php'
?>