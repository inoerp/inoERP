<br>
<span role="button" class="btn btn-success">
 <?php echo gettext('Click on any module link to enable /disable features of that module'); ?>
</span>
<br>
<?php

$all_modules = option_header::modules();
$search_result_statement = "";
$search_result_statement .= "<table class=\"normal\"><thead><tr>";
$search_result_statement .= '<th> Module Name </th>';
$search_result_statement .= '<th> Code </th>';
$search_result_statement .= '<th> Description </th>';
$search_result_statement .= '<th> Link </th>';
$search_result_statement .='</tr></thead>';
If (!empty($all_modules)) {
 $search_result_statement .= '<tbody>';
 foreach ($all_modules as $record) {
	$dir_path = 'modules'.DS. $record->option_line_code;
	$link = HOME_URL.'form.php?class_name=engine&mode=9&dir_path='.$dir_path;
	$search_result_statement .='<tr>';
	$search_result_statement .='<td>' . $record->option_line_value . '</td>';
	$search_result_statement .='<td>' . $record->option_line_code . '</td>';
	$search_result_statement .='<td>' . $record->description . '</td>';
	$search_result_statement .='<td><a role="button" class="ajax-link btn btn-default" href="' . $link . '">' . $record->option_line_value . '</a></td>';
	$search_result_statement .='</tr>';
 }
 $search_result_statement .='</tbody>';
}

echo $search_result_statement;
?>