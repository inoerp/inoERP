<?php 
// if(($class == 'option_header') && $$class->access_level == 'SYSTEM'){
//$readonly = true; $mode = 2;
// }
 
 
 if (!empty($_GET['option_header_id']) && empty($option_line_object)) {
 $option_line_object = option_line::find_by_parent_id($_GET['option_header_id']);
} 

if(empty($option_line_object)){
 $option_line_object = [new option_line()];
}

$pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
$per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
$total_count = count($option_line_object);
$pagination = new pagination($pageno, $per_page, $total_count);
$pagination->setProperty('_path', 'form');
$position = ($pageno - 1) * $per_page;

 ?>