<?php

if (!empty($_GET['obj_class_name'])) {
 $obj_class_name_h = $_GET['obj_class_name'];
 $custom_template_file_name = $obj_class_name_h.'_template.php';
} else {
 $custom_template_file_name = $obj_class_name_h = '';
}
$file_name_fp = $file_content_fp = '';

static $get_file_content = true;
if (!empty($obj_class_name_h) && class_exists($obj_class_name_h) && $get_file_content) {
 $get_file_content = false;
 $reflector_fp = new ReflectionClass($obj_class_name_h);
 $fnname_fp = $reflector_fp->getFileName();
 $fdir_fp = dirname($fnname_fp);

 $include_file_names_fp = glob($fdir_fp . DS . "*_template.php");
 $file_name_fp = $include_file_names_fp[0];

}
?>